#include "avm.h"

char* system_functions[] = {"print", "input", "objectmemberkeys", "objecttotalmembers", "objectcopy", 
	"totalarguments", "argument", "typeof", "strtonum", "sqrt", "cos", "sin"};



char* number_tostring (avm_memcell m){
    char* str;
    str = calloc(sizeof(double), sizeof(double));

    sprintf(str, "%f", m->data.numVal);
    return str;
}
char* string_tostring (avm_memcell m){
    char* p = strdup(m->data.strVal);
    return p;
}
char* bool_tostring (avm_memcell m){
    if(m->data.boolVal == 1)
        return strdup("TRUE");
    return strdup("FALSE");
}
char* table_tostring (avm_memcell m){


    return strdup(" ");
}
char* userfunc_tostring (avm_memcell m){
    unsigned int l = strlen(table_get(&userfunc_array, m->data.funcVal).function->name);
    char* uf = strdup("user function ");
    char* p = malloc(strlen(uf) + l + 3 + sizeof(int));
    sprintf(p, "%s%s %d", uf, table_get(&userfunc_array, m->data.funcVal).function->name, table_get(&userfunc_array, m->data.funcVal).function->line);
    return p;
}
char* libfunc_tostring (avm_memcell m){
    unsigned int l = strlen(m->data.libfuncVal);
    char* lf = strdup("library function ");
    char* p = malloc(l + 2 + strlen(lf));
    sprintf(p, "%s%s", lf, m->data.libfuncVal);
    return p;
}
char* nil_tostring (avm_memcell m){
    return strdup("NIL");
}
char* undef_tostring (avm_memcell m){
    return NULL;
}


void avm_registerlibfunc(char* libname){
    table_type p;
    p.string = strdup(libname);
    printf(MAGENTA"REGISTERING :%s\n"RESET, libname);
    table_set(&supported_libfunctions, supported_libfunctions.size, p);
}


function avm_funcinfo(unsigned int l){
    int i;
    for (i = 0; i < userfunc_array.size; i++){
        function f = table_get(&userfunc_array, i).function;
        if(l == f->line){
            function p = calloc(sizeof(struct function), sizeof(struct function));
            p->local_size = f->local_size;
            p->line = f->line;
            p->name = strdup(f->name);
            return p;
        }
    }
    executionFinished = 1;
    return NULL;

}


library_func_t avm_getlibraryfunc (char* id){ /*typical hashing*/
    int i = 0;
    while(i < supported_libfunctions.size){
    
        if(strcmp(id, table_get(&supported_libfunctions, i).string) == 0){
            
            return execute_libfuncs[i];
        }
        i++;
    }
    return NULL;
}



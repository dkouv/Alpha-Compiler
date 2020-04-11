#include "avm.h"

char* vmopcode_types[] = 
{	
    /* EXOUME ANTIKATASTISEI TO UMINUS ME TO MUL */
    "ASSIGN", "ADD", "SUB",
    "MUL", "DIVISION", "MOD",
    "MUL", "AND", "OR",
    "NOT", "IF_EQ", "IF_NOTEQ",
    "IF_LESSEQ", "IF_GREATEREQ", "IF_LESS",
    "IF_GREATER", "CALLFUNC", "PUSHARG",
    "ENTERFUNC", "EXITFUNC","NEWTABLE",
    "TABLEGETELEM", "TABLESETELEM", "NOP",
    "JUMP", "RET"
};

int vmopcode_binary_types[] = 
{	
        
    0 ,1, 2, 
    3, 4, 5, 
    6, 7, 8, 
    9, 10, 11, 
    12, 13, 14, 
    15, 16, 17,
    18, 19, 20,
    21, 22, 23, 
    24, 25
};



char* vmarg_types[] =
{
	"label_a"	,	 
	"global_a"	 ,
	"formal_a"	 ,
	"local_a"	,	 
	"number_a"	 ,
	"string_a" 	 ,
	"bool_a"	,	 
	"nil_a" 	,	 
	"userfunc_a" ,  
	"libfunc_a" ,	 
	"retval_a"	 ,
	"int_a" 	,	 
	"double_a" 	 
};






int total_strings;
int total_numbers;
int total_libfuncs;
int total_userfuncs;
int code;
int local_size;
int instructions;
int total_globals;














void read_libfuncs(FILE* file){
    int i;
    /* READ LIBFUNCS */
    fread(&total_libfuncs, sizeof(int), 1, file);
    printf("total libfuncs: %d\n", total_libfuncs);
    for(i = 0; i < total_libfuncs;i++){
        int size;
        char* lib_name;
        /* diavazw values apo arxeio */
        fread(&size, sizeof(int), 1, file);
        printf("SIZE :%d\n", size);
        lib_name = malloc(size + 1);
        fread(lib_name, size, 1, file);
        
        table_type p;
        p.string= strdup(lib_name);;
        table_set(&libfunc_array, i, p);
    }
    
}
void read_userfuncs(FILE* file){
    int i;
    /* READ FUNCTIONS */
    fread(&total_userfuncs, sizeof(int), 1, file);
    printf("total userfunctions: %d\n", total_userfuncs);
    for(i = 0; i < total_userfuncs;i++){
        /* an einai int i double */
        table_type p;
        function f1 = calloc(sizeof(struct function), sizeof(struct function));
        /* diavazw values apo arxeio */
        fread(f1, sizeof(struct function) - sizeof(char*), 1, file);
        int f_name_size;
        fread(&f_name_size, sizeof(int), 1, file);
        f1->name = malloc(f_name_size + 1);
        fread(f1->name, f_name_size, 1, file);
        p.function = f1;
        table_set(&userfunc_array, i, p);
    }
}
void read_numbers(FILE* file){
    int i;
    /* READ INTEGERS */
    fread(&total_numbers, sizeof(int), 1, file);
    printf("total numbers: %d\n", total_numbers);
    for(i = 0; i < total_numbers;i++){
        /* an einai int i double */
        int num_size;
        table_type p;
        fread(&num_size, sizeof(int), 1, file);
        if(num_size == 4){
            int num;
            /* irthe integer */
            fread(&num, sizeof(int), 1, file);
           
            // n->i = num;
            p.d = num;    
        }else {
            /* irthe double */
            double d;
            fread(&d, sizeof(double), 1, file);
         
            p.d = d;
            //n->d = d;
        }

        table_set(&number_array, i, p);
    }
    
}

void read_strings(FILE* file){
    int i;
    /* READ TOTAL STRINGS */
    fread(&total_strings, sizeof(int), 1, file);
    printf("total strings: %d\n", total_strings);
    for(i = 0; i < total_strings;i++){
        int str_size;
        fread(&str_size, sizeof(int), 1, file);
        printf("SiZE :%d\n", str_size);
        char* p = malloc(str_size + 1);
        fread(p, str_size, 1, file);
        table_type p1;
        p1.string = strdup(p);
        printf("A :%s\n", p);
        table_set(&string_array, i, p1);
    }
}


void parse_vmarg(int opcode, vmarg arg, FILE* f){
    switch(opcode){
        case label_a:{
            fread(&arg->val, sizeof(int), 1, f);
            //arg->type = number_a;
            //printf("%d ", arg->val);
            break;
        }
        case global_a:{
            fread(&arg->val, sizeof(int), 1, f);
            //printf(" %d:", arg->val);
            int size;
            fread(&size, sizeof(int), 1, f);
            
            arg->name = malloc(size + 1);
            fread(arg->name, size, 1, f);
            //printf("%s ", arg->name);
            
            break;
        }
        case formal_a:{
            fread(&arg->val, sizeof(int), 1, f);
            //printf(" %d:", arg->val);

            int size;
            fread(&size, sizeof(int), 1, f);
            arg->name = malloc(size + 1);
            fread(arg->name, size, 1, f);
            //printf("%s ", arg->name);

            break;
        }
        case local_a:{
            fread(&arg->val, sizeof(int), 1, f);
            //printf(" %d:", arg->val);

            int size;
            fread(&size, sizeof(int), 1, f);
      
            arg->name = malloc(size + 1);
            fread(arg->name, size, 1, f);
            //printf("%s ", arg->name);
            break;
        }
        case int_a:{
            fread(&arg->val, sizeof(int), 1, f);
            //printf("%f ", table_get(&number_array, arg->val).d);
            
            break;
        }
        case double_a:{
            fread(&arg->val, sizeof(int), 1, f);
            //printf("%f ", table_get(&number_array, arg->val).d);

            break;
        }
        case string_a:{
            fread(&arg->val, sizeof(int), 1, f);
            //printf("\"%s\" ", table_get(&string_array, arg->val).string);

            break;
        }
        case bool_a:{
            fread(&arg->val, sizeof(int), 1, f);
            //printf("%d ", arg->val);
            break;
        }
        case nil_a:{
            //printf("nill ");
            break;
        }
        case userfunc_a:{
            //printf(RED"userfunc_a :%d\n"RESET, userfunc_a);
            fread(&arg->val, sizeof(int), 1, f);
            //printf("%s ", table_get(&userfunc_array, arg->val).function->name);
            break;
        }
        case libfunc_a:{

            fread(&arg->val, sizeof(int), 1, f);
            //printf("%s ", table_get(&libfunc_array, arg->val).string);

            break;
        }
        case retval_a:{
            //printf("retval ");
            break;
        }
        case 13:{
            int unused;
            fread(&unused, sizeof(int), 1, f);
            //printf("unused ");
            break;
        }
    }
    
}

void print_instructions_table(){
    int i;
    while(i < instructions_table.size){
        instruction instr = table_get(&instructions_table, i).instr;
        printf(YELLOW"#%d "RESET, i);
        printf("%s ",vmopcode_types[instr->opcode]);
        vmarg_print(instr->result);
        vmarg_print(instr->arg1);
        vmarg_print(instr->arg2);
      
        printf("Line %d ", instr->srcLine);
        printf("\n");
        i++;

    }

}



void read_binary_file(char* fname){
    FILE *file = fopen(fname, "rb"); // "r" for read
    int magicnumber;
    int i;
    if(file == NULL){
        printf(MAGENTA"Error, file does not exist, exiting\n"RESET);
        exit(1);
    }
    fread(&magicnumber, sizeof(int), 1, file);

    if(magicnumber != 340){
        printf(MAGENTA"ERROR, invalid magic number\n"RESET);
        exit(1);
    }
    printf("Magicnumber: %d\n", magicnumber);
    fread(&total_globals, sizeof(int), 1, file);
    printf("GLOBALS :%d\n", total_globals);
    read_strings(file);       

    read_numbers(file);
    read_userfuncs(file);
    read_libfuncs(file);
    fread(&code, sizeof(int), 1, file);
    fread(&local_size, sizeof(int), 1, file);
    fread(&instructions, sizeof(int), 1, file);
    printf("CODE :%d\n", code);
    printf("LOCAL SIZE :%d\n", local_size);
    printf("INSTUCTIONS :%d\n", instructions);
    codeSize = instructions;

    table_init(&instructions_table);

    for(i = 0; i < instructions; i++){
        //printf("#%d \t", i);

        int opcode;
        fread(&opcode, sizeof(int), 1, file);
        //printf("%s ", vmopcode_types[opcode]);
        instruction t = calloc(sizeof(struct instruction), sizeof(struct instruction));
        vmarg vmarg1 = calloc(sizeof(struct vmarg), sizeof(struct vmarg));
        vmarg vmarg2 = calloc(sizeof(struct vmarg), sizeof(struct vmarg));
        vmarg result  = calloc(sizeof(struct vmarg), sizeof(struct vmarg));
        t->opcode = opcode;
        fread(&opcode, sizeof(int), 1, file);
        result->type = opcode;
        parse_vmarg(opcode, result, file);
        fread(&opcode, sizeof(int), 1, file);
        vmarg1->type = opcode;
        parse_vmarg(opcode, vmarg1, file);
        fread(&opcode, sizeof(int), 1, file);
        vmarg2->type = opcode;
        parse_vmarg(opcode, vmarg2, file);

        fread(&t->srcLine, sizeof(int), 1, file);
        //printf("LINE :%d\n", t->srcLine);
        t->arg1 = vmarg1;
        t->arg2 = vmarg2;
        t->result = result;
        table_type p;
        p.instr = t;
        table_set(&instructions_table, i, p);
    }
    print_instructions_table();
    fclose(file);
}
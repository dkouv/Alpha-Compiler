#include "avm.h"
typedef void (*library_func_t)(void);

void libfunc_print(void) {
    unsigned i;
    unsigned n = avm_totalactuals();
    for (i = 0; i < n; ++i) {
        char* s = avm_tostring(avm_getactual(i));
        if(s[0] == '\\' ){
            if(s[1] == 'n'){
                printf("\n");
                free(s);
            }
        }else{
            printf("%s",s);
            free(s);        
        }
    }
    
}

library_func_t execute_libfuncs[] = {
	libfunc_print, 
    libfunc_input, 
    libfunc_objectmemberkeys,
    libfunc_objecttotalmembers, 
	libfunc_objectcopy, 
    libfunc_totalarguments, 
    libfunc_argument,
	libfunc_typeof, 
    libfunc_strtonum,
    libfunc_sqrt, 
    libfunc_cos, 
    libfunc_sin
};

char* read_string(){
    size_t size = 80;
    char *str = malloc(sizeof(char) * size);
    int c;
    size_t len = 0;

    while (EOF != (c = getchar()) && c != '\r' && c != '\n') {
        str[len++] = c;
        if(len == size) str = realloc(str, sizeof(char) * (size *= 2));
    }
    str[len++]='\0';
    return realloc(str, sizeof(char) * len);
}

void libfunc_input(){
    printf(MAGENTA"Give an input\n"RESET);
    char* in = read_string();
    double f;
    avm_memcellclear(&retval);
    if(strcmp(in, "true") == 0 ){
       retval.type = bool_m;
       retval.data.boolVal = 1;
    }else if (strcmp(in, "false") == 0){
        retval.type = bool_m;
        retval.data.boolVal = 0;
        
    }else if (sscanf(in, "%lf", &f) != 0){

        retval.type = 0;
        retval.data.numVal = f;
    
    }else if(strcmp(in, "nil") == 0){
        retval.type = nil_m;
        retval.data.strVal = strdup("nil");

    }else { 
        /* string */
        retval.type = string_m;
        retval.data.strVal = strdup(in);
    }

}
void libfunc_objectmemberkeys(){
   
}
void libfunc_objectcopy(void){
    unsigned n = avm_totalactuals();
    if(n != 1){
        avm_error("Function objectcopy takes only 1 arguments");
    }

    avm_memcellclear(&retval);
    avm_memcell m = avm_getactual(0);
    if(m->type != table_m){
        avm_error("Argument is not type of table");
    }else{
        retval.type = table_m;
        retval.data.tableVal = m->data.tableVal;
    
    }
}

void libfunc_objecttotalmembers(void){
    unsigned n = avm_totalactuals();
    if(n != 1){
        avm_error("Function objecttotalmembers takes only 1 arguments");
    }
    avm_memcellclear(&retval);
    avm_memcell m = avm_getactual(0);
    if(m->type != table_m){
        avm_error("Argument is not type of table");
    }else{
        retval.type = number_m;
        retval.data.numVal = m->data.tableVal->total;
   
    }

}


void libfunc_totalarguments (void) {
	unsigned p_topsp = avm_get_envvalue(topsp + AVM_SAVEDTOPSP_OFFSET);
	avm_memcellclear(&retval);

	if (!p_topsp) {
		avm_error("'totalarguments' called outside a function!");
		retval.type = nil_m;
	}
	else {
		retval.type = number_m;
		retval.data.numVal = avm_get_envvalue(p_topsp + AVM_NUMACTUALS_OFFSET);
	}
}


void libfunc_argument(){
    unsigned n = avm_totalactuals();
    if(n != 1){
        avm_error("Function argument takes only 1 arguments");
    }
        /* get saved topsp */
    unsigned p_topsp = avm_get_envvalue(topsp + AVM_SAVEDTOPSP_OFFSET);

    //printf("STACK ! :%d\n", p_topsp + AVM_SAVEDTOPSP_OFFSET +3);
    //printf("STACK +1 :%d\n", table_get(&stack, p_topsp + AVM_SAVEDTOPSP_OFFSET+3 + 1).avmmemcell->type);
    
    //printf("STACK +1 :%d\n", table_get(&stack, p_topsp + AVM_SAVEDTOPSP_OFFSET+3 + 3).avmmemcell->type);

    if (!p_topsp) {
		avm_error("'libfunc_argument' called outside a function!");
        return;
		retval.type = nil_m;
	}
    /* formal args size */
    unsigned arg_size = avm_get_envvalue(p_topsp + AVM_SAVEDTOPSP_OFFSET+3);
    avm_memcellclear(&retval);
    avm_memcell arg = avm_getactual(0);
    if(arg->type != number_m){
        avm_error("Argument is not type of number");
        return ;
    }
    if( arg->data.numVal > arg_size){
        avm_error("Current function has %d arguments", arg_size);
        return;
    }

    avm_memcell m = table_get(&stack, p_topsp + AVM_SAVEDTOPSP_OFFSET + 3 + arg->data.numVal).avmmemcell;




    memcpy(&retval, m, sizeof(struct avm_memcell));
}

void libfunc_typeof (void) {

	unsigned n = avm_totalactuals();

	if (n != 1)
		avm_error("one argument (not %d) expected in 'typeof'!", n);
	else {

		avm_memcellclear(&retval);
		retval.type = string_m;
		retval.data.strVal = strdup(typeStrings[avm_getactual(0) -> type]);
	}
}

void libfunc_strtonum(){
   
    unsigned n = avm_totalactuals();
    printf("N IS :%d\n", n);
    if(n != 1){
        avm_error("Function strtonum takes only 1 arguments");
    }
    avm_memcellclear(&retval);
    avm_memcell m = avm_getactual(0);
    if(m->type != string_m){
        avm_error("Argument is not type of string");
    }

    
   
    double f = strtod(m->data.strVal, NULL);
    retval.type = number_m;
    retval.data.numVal = f;

}
void libfunc_sqrt(){

    unsigned n = avm_totalactuals();
    if(n != 1){
        avm_error("one argument (not %d) expected in 'sqrt  '!", n);
    }
    avm_memcellclear(&retval);
    avm_memcell m = avm_getactual(0);
    if(m->type != number_m){
        avm_error("Argument is not type of number");
    }
    if(m->data.numVal < 0){
        avm_error("Argument cannot be a negative number");
    }

    retval.type = number_m;
    retval.data.numVal = sqrt(m->data.numVal);
}
void libfunc_cos(){
  
    unsigned n = avm_totalactuals();
    if(n != 1){
        avm_error("one argument (not %d) expected in 'cos'!", n);
    }
    avm_memcellclear(&retval);
    avm_memcell m = avm_getactual(0);
    if(m->type != number_m){
        avm_error("Argument is not type of number");
    }
    if(m->data.numVal < 0){
        avm_error("Argument cannot be a negative number");
    }
    double val = PI / 180;
    double ret = cos(m->data.numVal * val);
    retval.type = number_m;
    retval.data.numVal = ret;
}
void libfunc_sin(){
    unsigned n = avm_totalactuals();
    if(n != 1){
        avm_error("one argument (not %d) expected in 'sin'!", n);
    }
    avm_memcellclear(&retval);
    avm_memcell m = avm_getactual(0);
    if(m->type != number_m){
        avm_error("Argument is not type of number");
    }
    if(m->data.numVal < 0){
        avm_error("Argument cannot be a negative number");
    }
    double val = PI / 180;
    double ret = sin(m->data.numVal * val);
    retval.type = number_m;
    retval.data.numVal = ret;

}




#include "avm.h"

memclear_func_t memclearFuncs [] = {
	0, /*number*/
	memclear_string, 
	0, /*bool*/
	memclear_table,
	0, /*userfunc*/
	0, /*libfunc*/
	0, /*nil*/
	0 /*undef*/
};

unsigned top, topsp;
unsigned totalActuals = 0;
typedef unsigned char (*tobool_func_t) (avm_memcell);

tostring_func_t tostringFuncs[] = {
	number_tostring,
	string_tostring,
	bool_tostring,
	table_tostring,
	userfunc_tostring,
	libfunc_tostring,
	nil_tostring,
	undef_tostring
};

tobool_func_t toboolFuncs [] = {
	number_tobool,
	string_tobool,
	bool_tobool,
	table_tobool,
	userfunc_tobool,
	libfunc_tobool,
	nil_tobool,
	undef_tobool
};


char* typeStrings[] = {
	"number",
	"string",
	"bool",
	"userfunc",
	"libfunc",
	"undef"
};

void avm_warning (char* str, ...){
   va_list args;
   printf(YELLOW);
   va_start(args, str);
   vprintf(str, args);
   printf(RESET);
   va_end(args);
   printf("\n");
}
void avm_error(char* str, ...){
   va_list args;
   printf(RED);
   va_start(args, str);
   vprintf(str, args);
   printf(RESET);
   va_end(args);
//    printf("\n");
   executionFinished = 1;
   printf("\tLINE %d\n", pc);
}
double consts_getnumber (unsigned index){
	double n = table_get(&number_array, index).d;
	return n;

}
char* consts_getstring (unsigned index){
	return (table_get(&string_array, index).string);
}
char* libfuncs_getused (unsigned index){
	return (table_get(&libfunc_array, index).string);
}


avm_memcell avm_translate_operand(vmarg arg, avm_memcell reg) {
	//reg = calloc(sizeof(struct avm_memcell), sizeof(struct avm_memcell));
	switch (arg->type) {

		/* Variables*/

		case global_a: return table_get(&stack, AVM_STACKSIZE-1-arg->val).avmmemcell;//&stack[];
		case local_a:  return table_get(&stack, topsp-arg->val).avmmemcell;
		case formal_a: return table_get(&stack, topsp+AVM_STACKENV_SIZE+1+arg->val).avmmemcell;

		case retval_a: return &retval;

		case number_a: {
			reg->type = number_m;
			reg->data.numVal = consts_getnumber(arg->val);
			return reg;
		}

		case int_a: {
			
			reg->type = number_m;
			
			reg->data.numVal = consts_getnumber(arg->val);
			return reg;
		}
		
		case double_a: {
			reg->type = number_m;
			reg->data.numVal = consts_getnumber(arg->val);
			return reg;
		}

		case string_a: {
			reg->type = string_m;
			reg->data.strVal = strdup(consts_getstring(arg->val));
			return reg;
		}

		case bool_a: {
			reg->type = bool_m;
			reg->data.boolVal = arg->val;
			return reg;
		}


		case nil_a: reg->type = nil_m; return reg;

		case userfunc_a: {
		
			reg->type = userfunc_m;
			reg->data.funcVal = arg->val;
			return reg;
		}

		case libfunc_a: {
			reg->type = libfunc_m;
			reg->data.libfuncVal = libfuncs_getused(arg->val);
			return reg;
		}

		default: assert(0);
	}
}



void avm_memcellclear (avm_memcell m) {
	if(m->type !=undef_m) {
		memclear_func_t f = memclearFuncs[m->type];
		if(f)
			(*f)(m);
		m->type = undef_m;
	}
}


void memclear_string (avm_memcell m) {
	// assert(m->data.strVal);
	 free(m->data.strVal);
}

void memclear_table (avm_memcell m) {
	assert(m->data.tableVal);
	avm_tabledecrefcounter(m->data.tableVal);
}



unsigned avm_get_envvalue (unsigned i) {
	//assert(stack[i]->type = number_m);
	unsigned val = (unsigned) table_get(&stack, i).avmmemcell->data.numVal;//.data.numVal;
	//assert(stack[i].data.numVal == ((double) val));

	return val;
}
typedef void (*library_func_t)(void);

void avm_calllibfunc(char* id) {
	library_func_t f = avm_getlibraryfunc(id);
	if(!f) {
		avm_error("Unsupported lib func '%s' called!", id);
		executionFinished = 1;
	}
	else {
		topsp = top;
		totalActuals = 0;

		(*f)(); 	/*  TO DO  call library function*/
		if(!executionFinished) /*an error may naturally occur inside.*/
			execute_funcexit((instruction) 0); /*return sequence*/
	}

}

void avm_dec_top (void) {
	if(!top) { /*stack overflow*/

		avm_error("Stack Overflow!");
		executionFinished = 1;
	}
	else
		--top;
}


char* avm_tostring (avm_memcell m) {
	assert(m->type >= 0 && m->type <= undef_m);
	return (*tostringFuncs[m->type]) (m);
}



unsigned avm_totalactuals (void) {
	return avm_get_envvalue(topsp + AVM_NUMACTUALS_OFFSET);
}

avm_memcell avm_getactual(unsigned i) {
	//assert(i < avm_totalactuals());

	return table_get(&stack, topsp + AVM_STACKENV_SIZE + 1 + i).avmmemcell;
}

 
void avm_push_envvalue (unsigned val) {
	avm_memcell s = table_get(&stack, top).avmmemcell;
	s->type = number_m;
	s->data.numVal = val;

	avm_dec_top();
}

void avm_callsaveenviroment (void) {
	avm_push_envvalue(totalActuals);
	avm_push_envvalue(pc+1);
	avm_push_envvalue(top + totalActuals + 2);
	avm_push_envvalue(topsp);
}


void avm_assign (avm_memcell lv, avm_memcell rv) {

	if(lv == rv) /*same calls? DONT ASSIGN!*/
	{

		return;
	}
	if(lv->type == table_m &&	/*same tables? no need to assign*/
	   rv->type == table_m &&
	 
	   lv->data.tableVal == rv->data.tableVal)
	   return;

	   

	if(rv->type == undef_m) /*from undefined r-value? warning!*/
		avm_warning("assigning from 'undef' content!");

	avm_memcellclear(lv); /*clear old cell contents*/
	memcpy(lv, rv, sizeof(struct avm_memcell));
	if(lv->type == string_m)
		lv->data.strVal = strdup(rv->data.strVal);
	else
	if (lv->type == table_m){
	
		avm_tableincrefcounter(lv->data.tableVal);
	}
}


unsigned char number_tobool (avm_memcell m) { return m->data.numVal != 0 ; }
unsigned char string_tobool (avm_memcell m) { return m->data.strVal[0] != 0; }
unsigned char bool_tobool (avm_memcell m) { return m->data.boolVal; }
unsigned char table_tobool (avm_memcell m) { return 1; }
unsigned char userfunc_tobool (avm_memcell m) { return 1; }
unsigned char libfunc_tobool (avm_memcell m) { return 1; }
unsigned char nil_tobool (avm_memcell m) { return 0; }
unsigned char undef_tobool (avm_memcell m) { assert(0); return 0; }

unsigned char avm_tobool (avm_memcell m) {
	assert(m->type >= 0 && m->type < undef_m);
	return (*toboolFuncs[m->type]) (m);
}

void avm_initstack(){
	int i;
	// initialize size and capacity
	stack.size = AVM_STACKSIZE;
	stack.capacity = AVM_STACKSIZE;

	// allocate memory for vector->data
	stack.data = calloc(sizeof(union table_type) * stack.capacity, sizeof(union table_type) * stack.capacity);
	for( i = 0; i < AVM_STACKSIZE; i++){
		table_type p;
		p.avmmemcell = new_memcell();
		p.avmmemcell->type = undef_m;
		table_set(&stack, i, p);	
	}
	
}


void avm_initialize (void) {

	avm_initstack();

	avm_registerlibfunc("print");											
	avm_registerlibfunc("input");
	avm_registerlibfunc("objectmemberkeys");
	avm_registerlibfunc("objecttotalmembers");
	avm_registerlibfunc("objectcopy");
	avm_registerlibfunc("totalarguments");
	avm_registerlibfunc("argument");
	avm_registerlibfunc("typeof");
	avm_registerlibfunc("strtonum");
	avm_registerlibfunc("sqrt");
	avm_registerlibfunc("cos");
	avm_registerlibfunc("sin");
 
}


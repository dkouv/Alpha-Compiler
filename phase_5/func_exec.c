#include "avm.h"

void execute_call (instruction instr) {
	avm_memcell func = avm_translate_operand(instr->result, &ax);
	
	avm_callsaveenviroment();

	switch (func->type) {

		case userfunc_m: {
		
			
			pc = table_get(&userfunc_array, func->data.funcVal).function->line;
		//	assert(pc < AVM_ENDING_PC);
		/*	assert(code[pc].opcode == funcenter_v); */
			break;
		}
		
		case string_m: avm_calllibfunc(func->data.strVal); break;
		case libfunc_m: avm_calllibfunc(func->data.libfuncVal); break;

		default: {
			char* s = avm_tostring(func);
			avm_error("call: cannot bind  to function!");
			free(s);
			executionFinished = 1;
		}
	}
	
}


void execute_pusharg (instruction instr) {

	avm_memcell arg = avm_translate_operand(instr->result, &ax);
	assert(arg);

	avm_assign(table_get(&stack, top).avmmemcell, arg);
	++totalActuals;
	avm_dec_top();
}

void execute_funcenter(instruction instr) {
	avm_memcell func = avm_translate_operand(instr->result, &ax);
	assert(func);
	assert(pc ==  table_get(&userfunc_array, func->data.funcVal).function->line);


	totalActuals = 0;
	function funcInfo = calloc(sizeof(struct function), sizeof(struct function));
	funcInfo = avm_funcinfo(pc);
	topsp = top;
	top = top - funcInfo->local_size;
 
}

void execute_funcexit (instruction unused) {
	unsigned oldTop = top;
	top 	= avm_get_envvalue(topsp + AVM_SAVEDTOP_OFFSET);
	pc 		= avm_get_envvalue(topsp + AVM_SAVEDPC_OFFSET);
	topsp 	= avm_get_envvalue(topsp + AVM_SAVEDTOPSP_OFFSET);

	while (++oldTop <= top) 
		avm_memcellclear(table_get(&stack, oldTop).avmmemcell);  /*katharismos tou activation record / garbage collector*/	
}
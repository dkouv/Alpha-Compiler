#include "avm.h"
typedef double (*arithmetic_func_t) (double x, double y);



int N;

double add_impl (double x, double y) { return x+y; }
double sub_impl (double x, double y) { return x-y; }
double mul_impl (double x, double y) { return x*y; }
double div_impl (double x, double y) { return x/y; }
double mod_impl (double x, double y) { 
	return ((unsigned) x) % ((unsigned) y);
}
arithmetic_func_t arithmeticFuncs[] = {
	add_impl,
	sub_impl,
	mul_impl,
	div_impl,
	mod_impl
};
avm_memcell new_memcell(){
	avm_memcell p = calloc(sizeof(struct avm_memcell), sizeof(struct avm_memcell));
	if(p == NULL){
		avm_error("CALLOC FAILED");
		exit(1);
	}
	return p;
}

void execute_arithmetic (instruction instr) {
	// printf("RESULT TYPE :%d, arg->val :%d\n", instr->result->type, instr->result->val);

	avm_memcell lv = avm_translate_operand(instr->result, (avm_memcell) 0 );

	avm_memcell rv1 = avm_translate_operand(instr->arg1, &ax);
		
	avm_memcell rv2 = avm_translate_operand(instr->arg2, &bx);

	//assert(lv && (&stack[N-1] >= lv && lv > &stack[top] || lv == &retval));
	//assert(rv1 && rv2);

	if (rv1->type != number_m || rv2->type != number_m) {
		avm_error("Not a number in arithmetic!");
		executionFinished = 1;
	}
	else {
		arithmetic_func_t op = arithmeticFuncs[instr->opcode - add_v];
		
		avm_memcellclear(lv);
		lv->type 		= number_m;
		
		lv->data.numVal = (*op) (rv1->data.numVal, rv2->data.numVal);
		//printf("lv ptr:%p  ,lv->type :%d\n", lv, lv->type);
		//avm_print(lv);
	}
	//printf("DONE\n");
} 

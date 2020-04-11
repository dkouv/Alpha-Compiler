#include "avm.h"

void execute_jeq (instruction instr) {

	/*assert(instr->result->type == label_a); */

	avm_memcell rv1 = avm_translate_operand(instr->result, &ax);
	avm_memcell rv2 = avm_translate_operand(instr->arg1, &bx);

	unsigned char result = 0;

	if(rv1->type == undef_m || rv2->type == undef_m)
		avm_error("'undef' involved in equality!");
	else
	if(rv1->type == nil_m || rv2->type == nil_m)
		result = rv1->type == nil_m && rv2->type == nil_m;
	else
	if(rv1->type == bool_m || rv2->type == bool_m)
		result = (avm_tobool(rv1) == avm_tobool(rv2));
	else
	if(rv1->type != rv2->type)
		avm_error(
			"%s == %s is illegal!",
			typeStrings[rv1->type],
			typeStrings[rv2->type]
		);
	else {
		/*equality check with dispaching*/
		if (rv1->type == number_m ) {

			if (rv1->data.numVal == rv2->data.numVal)
				result = 1;
			else
				result = 0;
		}else if (rv1->type == table_m) {

			result = !memcmp(rv1->data.tableVal->strIndexed,rv2->data.tableVal->strIndexed,AVM_TABLE_HASHSIZE*sizeof(struct avm_table_bucket)) &&
			!memcmp(rv1->data.tableVal->numIndexed, rv2->data.tableVal->numIndexed,AVM_TABLE_HASHSIZE*sizeof(struct avm_table_bucket));

		}else if (rv1->type == userfunc_m) {
			if (rv1->data.funcVal == rv2->data.funcVal)
				result = 1;
			else
				result = 0;
		}else if (rv1->type == libfunc_m) {

			result = !strcmp(rv1->data.libfuncVal,rv2->data.libfuncVal);
		
		}else
			result = !strcmp(rv1->data.strVal,rv2->data.strVal);

	}

	if(!executionFinished && result)
		pc = instr->arg2->val;		
}


void execute_jne(instruction instr) {

	/*assert(instr->result->type == label_a); */

	avm_memcell rv1 = avm_translate_operand(instr->result, &ax);
	avm_memcell rv2 = avm_translate_operand(instr->arg1, &bx);

	unsigned char result = 0;

	if(rv1->type == undef_m || rv2->type == undef_m)
		avm_error("'undef' involved in equality!");
	else
	if(rv1->type == nil_m || rv2->type == nil_m)
		result = rv1->type == nil_m && rv2->type == nil_m;
	else
	if(rv1->type == bool_m || rv2->type == bool_m)
		result = (avm_tobool(rv1) == avm_tobool(rv2));
	else
	if(rv1->type != rv2->type)
		avm_error(
			"%s == %s is illegal!",
			typeStrings[rv1->type],
			typeStrings[rv2->type]
		);
	else {
		/*equality check with dispaching*/
		if (rv1->type == number_m ) {
			if (rv1->data.numVal == rv2->data.numVal)
				result = 1;
			else
				result = 0;
		}else if (rv1->type == table_m) {

			result = !memcmp(rv1->data.tableVal->strIndexed,rv2->data.tableVal->strIndexed,AVM_TABLE_HASHSIZE*sizeof(struct avm_table_bucket)) &&
			!memcmp(rv1->data.tableVal->numIndexed,rv2->data.tableVal->numIndexed,AVM_TABLE_HASHSIZE*sizeof(struct avm_table_bucket));

		}else if (rv1->type == userfunc_m) {
			if (rv1->data.funcVal == rv2->data.funcVal)
				result = 1;
			else
				result = 0;
		}else if (rv1->type == libfunc_m) {

			result = !strcmp(rv1->data.libfuncVal,rv2->data.libfuncVal);
		
		}else
			result = !strcmp(rv1->data.strVal,rv2->data.strVal);

	}

	if(!executionFinished && !result)
		pc = instr->arg2->val;

}

int cmp_jle(double d, double dd) { 

	return d <= dd;
}

int cmp_jge(double d, double dd) { 	
	return d >= dd; 
}

int cmp_jlt(double d, double dd) { 
	return d < dd;
}

int cmp_jgt(double d, double dd) { 
	return d > dd; 
}	

void execute_jle(instruction instr) {


	unsigned result;
	avm_memcell rv1 = avm_translate_operand(instr->result, &ax);
	avm_memcell rv2 = avm_translate_operand(instr->arg1, &bx);
	
	if ((rv1->type != number_m || rv2->type != number_m)){
		avm_error("Argument's are not type of numbers");
		return ;
	}
	result = cmp_jle(rv1->data.numVal ,rv2->data.numVal);

	if(!executionFinished && result)
		pc = instr->arg2->val;
}

void execute_jge(instruction instr) {

	unsigned result;
	
	avm_memcell rv1 = avm_translate_operand(instr->result, &ax);
	avm_memcell rv2 = avm_translate_operand(instr->arg1, &bx);

	printf("TIPOS :%d\n", rv1->type);
	printf("TIPOS :%d\n", rv2->type);
	
	if ((rv1->type != number_m || rv2->type != number_m)){
		avm_error("Argument's are not type of numbers");
		return ;
	}
	result = cmp_jge(rv1->data.numVal, rv2->data.numVal);

	if(!executionFinished && result)
		pc = instr->arg2->val;
}

void execute_jlt(instruction instr) {
 
	unsigned result;
	
	avm_memcell rv1 = avm_translate_operand(instr->result, &ax);
	avm_memcell rv2 = avm_translate_operand(instr->arg1, &bx);
	
	if ((rv1->type != number_m || rv2->type != number_m)){
		avm_error("Argument's are not type of numbers");
		return ;
	}
	result = cmp_jlt(rv1->data.numVal ,rv2->data.numVal);


	if(!executionFinished && result)
		pc = instr->arg2->val;
}

void execute_jgt(instruction instr) {

	unsigned result;
	avm_memcell rv1 = avm_translate_operand(instr->result, &ax);
	avm_memcell rv2 = avm_translate_operand(instr->arg1, &bx);
	
	if ((rv1->type != number_m || rv2->type != number_m)){
		avm_error("Argument's are not type of numbers");
		return ;
	}
	result = cmp_jgt(rv1->data.numVal ,rv2->data.numVal);

	if(!executionFinished && result)
		pc = instr->arg2->val;
}

void execute_jump(instruction instr) {
	if(!executionFinished)
		pc = instr->result->val;
}

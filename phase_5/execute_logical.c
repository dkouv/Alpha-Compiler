#include "avm.h"

void execute_uminus(instruction instr){
	printf("UMINUS");
}

void execute_or(instruction instr){
	avm_memcell lv = avm_translate_operand(instr->result, (avm_memcell) 0 );
    avm_memcell rv1 = avm_translate_operand(instr->arg1, &ax);
	avm_memcell rv2 = avm_translate_operand(instr->arg2, &bx);


	if(rv1->type == undef_m && rv2->type == undef_m)
		avm_error("'undef' involved in equality!");
	
	avm_memcellclear(lv);
	lv->type = bool_m;
    lv->data.boolVal = (avm_tobool(rv1) || avm_tobool(rv2));



}
void execute_and(instruction instr){

	avm_memcell lv = avm_translate_operand(instr->result, (avm_memcell) 0 );
    avm_memcell rv1 = avm_translate_operand(instr->arg1, &ax);
	avm_memcell rv2 = avm_translate_operand(instr->arg2, &bx);


	if(rv1->type == undef_m && rv2->type == undef_m)
		avm_error("'undef' involved in equality!");
	
	avm_memcellclear(lv);
	lv->type = bool_m;
    lv->data.boolVal = (avm_tobool(rv1) && avm_tobool(rv2));



}
void execute_not(instruction instr){
	avm_memcell lv = avm_translate_operand(instr->result, (avm_memcell) 0 );
    avm_memcell rv1 = avm_translate_operand(instr->arg1, &ax);
	if(rv1->type == undef_m )
		avm_error("'undef' involved in equality!");
	avm_memcellclear(lv);
	lv->type = bool_m;
    lv->data.boolVal = !avm_tobool(rv1);
}
void execute_nop(instruction instr){
    printf(RED"PROGRAM FINISHED\n"RESET);
}
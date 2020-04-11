#include "avm.h"
void execute_tablegetelem (instruction instr) {

	avm_memcell lv = avm_translate_operand(instr->result, (avm_memcell) 0);
	avm_memcell t = avm_translate_operand(instr->arg1, (avm_memcell) 0);
	avm_memcell i = avm_translate_operand(instr->arg2, &ax);

	// assert(lv && &stack[N-1] >= lv && lv > &stack[top] || lv == &retval);
	// assert(t && &stack[N-1] >= t && t > &stack[top] );
	// assert(i);

	avm_memcellclear(lv);
	lv->type = nil_m;

	if (t->type != table_m) 
		avm_error("illegal use of type %s as table!", typeStrings[t->type]);
	else {

		avm_memcell content = avm_tablegetelem(t->data.tableVal, i);
		if(content) 
			avm_assign(lv,  content);
		else {
			printf(RED"ERROR variables not found\n"RESET);
			char* ts = avm_tostring(t);
			char* is = avm_tostring(i);
			avm_warning("%s[%s] not found!", ts, is);
			free(ts);
			free(is);
		}
	}

}

void execute_tablesetelem(instruction instr) {

	avm_memcell t = avm_translate_operand(instr->arg1, (avm_memcell) 0);
	avm_memcell i = avm_translate_operand(instr->arg2, &ax);
	avm_memcell c = avm_translate_operand(instr->result, &bx);

	// assert(t && &stack[N-1] >= t && t > &stack[top] );
	// assert(i && c);
	
	if(t->type != table_m)
		avm_error("illegal use of type %s as table!", typeStrings[t->type]);
	else{
		avm_tablesetelem(t->data.tableVal, i, c);	

	}
		
}


void execute_newtable(instruction instr){
	avm_memcell lv = avm_translate_operand(instr->result, (avm_memcell)0);
	//assert(lv && (table_get(&stack, N - 1)))
	avm_memcellclear(lv);
	lv->type = table_m;
	lv->data.tableVal = avm_tablenew();
	lv->data.tableVal->table_name = strdup(instr->result->name);
	avm_tableincrefcounter(lv->data.tableVal);

}
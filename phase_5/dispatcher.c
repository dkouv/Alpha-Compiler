#include "avm.h"


unsigned int executionFinished = 0;
unsigned pc = 0;
unsigned currLine = 0;
unsigned codeSize = 0;
instruction code = (instruction) 0;

typedef void (*execute_func_t) (instruction);

/*-----------------------Dispatcher-----------------------*/
execute_func_t executeFuncs[] = {
	execute_assign,
	execute_add,
	execute_sub,
	execute_mul,
	execute_div,
	execute_mod,
	execute_mul, /* uminus*/
	execute_and,
	execute_or,
	execute_not,
	execute_jeq,
	execute_jne,
	execute_jle,
	execute_jge,
	execute_jlt,
	execute_jgt,
	execute_call,
	execute_pusharg,
	execute_funcenter,
	execute_funcexit,
	execute_newtable,
	execute_tablegetelem,
	execute_tablesetelem,
	execute_nop,
	execute_jump
	
};


void execute_cycle(void) {
	if (executionFinished)
		return;
	else
	if(pc == AVM_ENDING_PC) {
		executionFinished = 1;
		return;
	}
	else {

		//assert(pc < AVM_ENDING_PC);
		
		instruction instr = table_get(&instructions_table, pc).instr;//code + pc;
		// assert (
		// 	instr->opcode >=0 && 
		// 	instr->opcode <= AVM_MAX_INSTRUCTIONS
		// );
		//printf("EXECUTING %d :%s\n", pc, vmopcode_types[instr->opcode]);
		if (instr->srcLine)
			currLine = instr->srcLine;
		unsigned oldPC = pc;
		(*executeFuncs[instr->opcode]) (instr);
		if (pc == oldPC)
			++pc;
	}
}

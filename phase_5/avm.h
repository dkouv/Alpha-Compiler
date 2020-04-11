#ifndef AVM_H
#define AVM_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdarg.h>
#include <math.h>

#include "type_vector.h"
#define PI 3.14159265
#define AVM_STACKSIZE 4096
#define AVM_STACKENV_SIZE 4
#define AVM_NUMACTUALS_OFFSET 4
#define AVM_SAVEDPC_OFFSET 3
#define AVM_SAVEDTOP_OFFSET 2
#define AVM_SAVEDTOPSP_OFFSET 1
extern unsigned  codeSize;
#define AVM_ENDING_PC codeSize
#define AVM_MAX_INSTRUCTIONS (unsigned) nop_v
#define AVM_TABLE_HASHSIZE 211

/**********
 * Colors * 
 *********/
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

typedef enum vmarg_t{
	label_a		= 0,
	global_a	= 1,
	formal_a	= 2,
	local_a		= 3,
	number_a	= 4,
	string_a 	= 5,
	bool_a		= 6,
	nil_a 		= 7,
	userfunc_a  = 8,
	libfunc_a 	= 9,
	retval_a	= 10,
	int_a 		= 11,
	double_a 	= 12,
	err_a		= 13
}vmarg_t;

struct vmarg{
	int type;
	//int scope;
	char* name;
	int val;
	

};
typedef struct vmarg* vmarg;

struct instruction{
	vmopcode opcode; 
	struct vmarg* result;
	struct vmarg* arg1;
	struct vmarg* arg2;
	int srcLine;
	int taddress;

};

typedef struct instruction* instruction;

struct function{

    int local_size;
    int line;
	char* name;
};

extern int vmopcode_binary_types[26]; 
extern char* vmopcode_types[26];
extern char* typeStrings[8];
extern char* system_functions[13];
extern unsigned int executionFinished;
extern unsigned top, topsp;
extern int N;
extern unsigned pc, currLine;
extern unsigned totalActuals;
extern int total_globals;

// extern memclear_func_t memclearFuncs[8];

typedef struct function* function;
Dynamic_Table string_array;
Dynamic_Table number_array;
Dynamic_Table userfunc_array;
Dynamic_Table libfunc_array;
Dynamic_Table stack;
Dynamic_Table instructions_table;
Dynamic_Table supported_libfunctions;

void read_binary_file(char* fname);
void print_array(Dynamic_Table* vector, int type);

typedef void (*library_func_t)(void);

library_func_t execute_libfuncs[12];

library_func_t avm_getlibraryfunc (char* id); /*typical hashing*/

typedef enum avm_memcell_t {
	number_m	= 0,
	string_m	= 1,
	bool_m		= 2,
	table_m		= 3,
	userfunc_m	= 4,
	libfunc_m	= 5,
	nil_m 		= 6,
	undef_m 	= 7,

}avm_memcell_t;

struct avm_memcell {
	avm_memcell_t type;
	union {
		double numVal;
		char* strVal;
		unsigned char boolVal;
		struct avm_table* tableVal;
		unsigned funcVal;
		char* libfuncVal;
	}data;
};


typedef union data_type{
		double numVal;
		char* strVal;
		unsigned char boolVal;
		struct avm_table* tableVal;
		unsigned funcVal;
		char* libfuncVal;
}data_type;


struct avm_table_bucket {
	struct avm_memcell key;
	struct avm_memcell value;
	struct avm_table_bucket* next;
};

typedef struct avm_table_bucket* avm_table_bucket;

struct avm_table{
	unsigned refCounter;
	struct avm_table_bucket* strIndexed[AVM_TABLE_HASHSIZE];
	struct avm_table_bucket* numIndexed[AVM_TABLE_HASHSIZE];
	char* table_name;
	unsigned total;
	
};

typedef struct avm_table* avm_table;
typedef struct avm_memcell* avm_memcell;
typedef void (*memclear_func_t) (struct avm_memcell*);

void execute_cycle(void);

extern void execute_assign(struct instruction*);
extern void execute_uminus(struct instruction*);
extern void execute_and(struct instruction*);
extern void execute_or(struct instruction*);
extern void execute_not(struct instruction*);
extern void execute_jeq(struct instruction*);
extern void execute_jne (struct instruction*);
extern void execute_jle (struct instruction*);
extern void execute_jge (struct instruction*);
extern void execute_jlt (struct instruction*);
extern void execute_jgt (struct instruction*);
extern void execute_jump (struct instruction*);
extern void execute_call (struct instruction*);
extern void execute_pusharg (struct instruction*);
extern void execute_funcenter (struct instruction*);
extern void execute_funcexit (struct instruction*);
extern void execute_newtable (struct instruction*);
extern void execute_tablegetelem (struct instruction*);
extern void execute_tablesetelem (struct instruction*);
extern void execute_nop (struct instruction*);
extern void execute_call (struct instruction* instr);
extern void execute_jeq (struct instruction* instr);
void execute_arithmetic (struct instruction* instr);
void avm_dec_top (void);
void avm_push_envvalue (unsigned val);
void avm_callsaveenviroment (void);
void avm_assign (struct avm_memcell* lv, struct avm_memcell* rv);
void avm_warning (char* s, ...);
void avm_error(char* s, ...);
void avm_calllibfunc(char* id);
struct avm_memcell* avm_translate_operand (struct vmarg* arg, struct avm_memcell* reg);

void memclear_table (struct avm_memcell* m);
void avm_memcellclear(struct avm_memcell* m);

void memclear_string (struct avm_memcell* m);
void memclear_nothing(struct avm_memcell* m);

void avm_registerlibfunc(char* libname);

typedef char* (*tostring_func_t) (struct avm_memcell*);

unsigned char number_tobool (struct avm_memcell* m);
unsigned char string_tobool (struct avm_memcell* m) ;
unsigned char bool_tobool (struct avm_memcell* m);
unsigned char table_tobool (struct avm_memcell* m);
unsigned char userfunc_tobool (struct avm_memcell* m);
unsigned char libfunc_tobool (struct avm_memcell* m);
unsigned char nil_tobool (struct avm_memcell* m);
unsigned char undef_tobool (struct avm_memcell* m);
unsigned avm_totalactuals (void);
struct avm_memcell* avm_getactual(unsigned i);
char* avm_tostring(struct avm_memcell* m);

char* number_tostring (struct avm_memcell*);
char* string_tostring (struct avm_memcell*);
char* bool_tostring (struct avm_memcell*);
char* table_tostring (struct avm_memcell*);
char* userfunc_tostring (struct avm_memcell*);
char* libfunc_tostring (struct avm_memcell*);
char* nil_tostring (struct avm_memcell*);
char* undef_tostring (struct avm_memcell*);
struct function* avm_funcinfo(unsigned int l);
double consts_getnumber (unsigned index);
char* consts_getstring (unsigned index);
char* libfuncs_getused (unsigned index);
unsigned avm_get_envvalue(unsigned i);
unsigned char avm_tobool(avm_memcell m);
struct avm_memcell ax, bx, cx;
struct avm_memcell retval;
void avm_tabledecrefcounter (struct avm_table* t);
void avm_tableincrefcounter(struct avm_table* t);
void avm_tabledestroy(struct avm_table* t);
void avm_tablesetelem(struct avm_table* t1 , struct avm_memcell* t, struct avm_memcell* c);
struct avm_table* avm_tablenew(void);
struct avm_memcell* avm_tablegetelem(struct avm_table* key, struct avm_memcell* value);
void vmarg_print(struct vmarg* arg);
void avm_initialize (void);
void execute_cycle(void);
void avm_print(struct avm_memcell *m);
struct avm_memcell* new_memcell();
#define execute_add execute_arithmetic
#define execute_sub execute_arithmetic
#define execute_mul execute_arithmetic
#define execute_div execute_arithmetic
#define execute_mod execute_arithmetic




#define AVM_WIPEOUT(m) memset(&(m),0,sizeof(struct avm_table_bucket))





void libfunc_print(void);
void libfunc_input();
void libfunc_objectmemberkeys();
void libfunc_objecttotalmembers();
void libfunc_objectcopy();
void libfunc_totalarguments();
void libfunc_argument();
void libfunc_typeof();
void libfunc_strtonum();
void libfunc_sqrt();
void libfunc_cos();
void libfunc_sin();





int cmp_jle(double, double);
int cmp_jge(double, double);
int cmp_jlt(double, double);
int cmp_jgt(double, double);





#endif

#include "avm.h"
#define TABLE_INITIAL_CAPACITY 4096

struct number_type{
	int type;
	int i;
	double d;
};
typedef struct number_type* number_type;

typedef union table_type{
	struct function* function;

	char* string;
	int i;
	double d;
	struct instruction* instr;
	struct avm_memcell* avmmemcell;
	
}table_type;
typedef enum vmopcode{
	assign_v,			add_v,			sub_v,
	mul_v,				div_v,			mod_v,
	uminus_v,			and_v,			or_v,
	not_v,				jeq_v,			jne_v,
	jle_v,				jge_v,			jlt_v,
	jgt_v,				call_v,			pusharg_v,
	funcenter_v,		funcexit_v,		newtable_v,
	tablegetelem_v,		tablesetelem_v, nop_v,
	jump_v,				ret_v			, getretval_v	
}vmopcode;
// Define a vector type
typedef struct {
  int size;      // slots used so far
  int capacity;  // total available slots
  table_type *data;     // array of integers we're storing
} Dynamic_Table;

void
table_init(Dynamic_Table *vector);

void
table_append(Dynamic_Table *vector, table_type value);

table_type
table_get(Dynamic_Table *vector, int index);

void
table_set(Dynamic_Table *vector, int index, table_type value);

void
table_double_capacity_if_full(Dynamic_Table *vector);

void
table_free(Dynamic_Table *vector);


int
table_find_element(Dynamic_Table* vector, table_type value, int type);

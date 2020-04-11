#include "library.h"
#define TABLE_INITIAL_CAPACITY 4096

#include <stdlib.h>
#include <stdio.h>

struct number_type{
	int type;
	int i;
	double d;
};
typedef struct number_type* number_type;

typedef union table_type{
	struct number_type* num_type;
	int i;
	double d;
	char c;
	char* string;
	char* libfunc;
	struct SymbolTableEntry *entry;
	struct Function *function;
	struct instruction *instr;
	struct incomplete_jump* jumps;
	struct rikas* rikas_1;
	struct cuck* cuck_1;
	struct expr* ex;
}table_type;

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

#ifndef LIBRARY_H
#define LIBRARY_H
#include "type_vector.h"

/***********
 * Defines *
 ***********/

/*
 * Concatenate preprocessor tokens A and B without expanding macro definitions
 * (however, if invoked from a macro, macro arguments are expanded).
 */


#define MAX_SIZE 1024
#define ENUMERATED 205
#define LEX_INTEGER 206
#define P_CHARACTER 207
#define LEX_OPERATOR 208
#define LEX_REAL 209
#define LEX_PUNCTUATION 210
#define COMMENT_SINGLE 211
#define COMMENT_MULTI 212
#define StartBucket 509
#define SYSTEM_FUNCTION_SIZE 12
#define true 1
#define false 0 
#define QUAD_INITIAL_CAPACITY 1024
#define VECTOR_INITIAL_CAPACITY 100
#define EXPAND_SIZE 1024
#define CURR_SIZE (total*sizeof(quad))
#define NEW_SIZE (EXPAND_SIZE*sizeof(quad)+CURR_SIZE)
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


/************
 * Includes *
 ************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "symtable.h"
#include <unistd.h>
#include <assert.h>

/*IOPCODE*/
 typedef enum iopcode {
	assign, add, sub,
	null,mul, division, mod,
	uminus, and, or,
	not, if_eq, if_noteq,
	if_lesseq, if_greatereq, if_less,
	if_greater, call, param,
	ret, getretval, funcstart,
	funcend, tablecreate,
	tablegetelem, tablesetelem, jump,
	if_eq_op, tablesetelemindex, tablecreate1,
	tablesetelem1, tablesetelemindex1
}iopcode;

/***************
 * Enumerators *
 ***************/
typedef enum key{LEX_IF, LEX_ELSE, LEX_WHILE, LEX_FOR, LEX_FUNCTION, LEX_RETURN, LEX_BREAK, LEX_CONTINUE, LEX_AND,
 									LEX_NOT, LEX_OR, LEX_LOCAL, LEX_TRUE, LEX_FALSE, LEX_NIL}enumerated;

typedef enum ops{LEX_EQUAL=15, LEX_PLUS, LEX_MINUS, LEX_STAR, LEX_SLASH, LEX_PERCENTAGE, LEX_DOUBLE_EQUAL, LEX_NOT_EQUAL, LEX_DOUBLE_PLUS,
 									LEX_GREATER, LEX_SMALLER, LEX_GREATER_EQUAL, LEX_SMALLER_EQUAL}operator;

typedef enum SymbolTableType {
	GLOBAL_T, LOCAL_T, FORMAL_T, USERFUNC_T, LIBFUNC_T
}symbol_table_type_enum;

 typedef enum expr_t {
	var_e,			// 0
	tableitem_e,	// 1

	programfunc_e,	// 2
	libraryfunc_e,	// 3

	arithexpr_e,	// 4
	boolexpr_e,		// 5
	assignexpr_e,	// 6
	newtable_e,		// 7
	constint_e,		// 8		
	constdouble_e,	// 9
	constbool_e,	// 10
	conststring_e,	// 11
	nil_e			// 12

	
}expr_t;


enum scopespace_t {
	programVal, functionLocal, formalArg
};



struct scope_space_list{
	int scope_space_type;
	int offset;
	struct scope_space_list* next;
};
typedef struct scope_space_list* scope_space_list;
scope_space_list scope_head;

/********
 * Structs *
 ***********/
typedef struct alpha_token_t{
   int  line_number;
   int  token_number;
   char*  data;
   char*  keyword;
   int category;
   int int_type;
   double double_type;
   char*  punctuation;
   char*  p_char_type;
   enumerated enumerated_type;
   struct alpha_token_t* next;
}alpha_token_t;



typedef struct Variable {

	char* name;			//Dynamic string

	unsigned int scope; //Scope Value
	
	unsigned int line; //Source line of decleration
}Variable;

typedef struct Function {
	char* name;
	/*list of arguments*/
	int total_arguments;
	unsigned int scope;
	unsigned int line;
}Function;

struct SymbolTableEntry {
	int taddress;
	int isActive;
	int assign_counter;
	int scope_space;
	int scope_offset;
	union {
		Variable* varVal;
		Function* funcVal;
	}value;
	symbol_table_type_enum type;
	struct SymbolTableEntry* next;
	struct SymbolTableEntry* next_same_scope;
};

struct Scope_List{
	int scope;
	struct Scope_List* next_scope;
	struct SymbolTableEntry* next_same_scope;
};



/* apothikeuei ta arguments tis listas arguments */
struct argument_mias_sinartisis{
    char * name;
    struct argument_mias_sinartisis* next;
};

  struct expr {
	expr_t type;
	struct SymbolTableEntry* sym;
	struct expr* index;
	int const_int;
	double const_double;
	char* strConst;
	int boolConst;
	/* to xrisimopoiume gia to if, while,for */
	/* gia na kanoume to katallilo quad sto ifstmt*/
	/* den exoume access sto quad */
	iopcode op;
	struct expr* next;
	int srcline;
};

/*QUADS*/
 struct quad {
	iopcode op;
	struct expr* result;
	struct expr* arg1;
	struct expr* arg2;
	int label;
	unsigned line;
	int taddress;
	/* dika m data */
	short written;
	int extra_data;
	int extra_data_for;
};

#define VECTOR_INITIAL_CAPACITY 100

// Define a vector type
typedef struct {
  int size;      // slots used so far
  int is_operation;
  int capacity;  // total available slots
  char **data;     // array of integers we're storing
} Vector;

void vector_init(Vector *vector);

void vector_append(Vector *vector, char *value);

char* vector_get(Vector *vector, int index);

void vector_set(Vector *vector, int index, char *value);

void vector_double_capacity_if_full(Vector *vector);

void vector_print(int label);

void vector_free(Vector *vector);

struct argument_mias_sinartisis* argument_list_head;


/*********************************************** PHASE 3 ***********************************************************/
extern Vector tableelem;
extern int is_assign;
extern int is_objectdef;
extern int label_objectdef;
extern int label_objectdef;
extern int label;
extern FILE *f;
extern int only_term;
extern int quad_offset;
typedef struct  quad* quad;
typedef struct  expr* expr;
extern char* expression_types[13];
extern char* opcode_types[32];
extern char* system_functions[13];
extern char* scope_space_str[3];
extern int stop_writing_quad_loop;
extern int stop_writing_if_quad;
extern int runtime_error;
extern int scope_offset, space_scope;
extern int global_var_counter;
quad last_quad_created;
quad for_quad, while_quad;
extern int while_counter;
extern int break_counter;
struct methodcall{
	char* m_name;
	struct expr* m_expr;
	int m_method;
};

struct indexed_struct{
	struct expr *index;
	struct expr *value;
	struct indexed_struct *next;
};


typedef struct indexed_struct* indexed_struct;
typedef struct methodcall* method_call;
extern int index1,index2, index3, index4, index5, index6, index7, index8, index9, index10, break7, break8,
		index11, index12;
		extern int for_counter ;
typedef struct
{
  int size;      // slots used so fark
  int capacity;  // total available slots
  int patched;
  quad *data; 
} Quad;


struct functions_created{
	struct SymbolTableEntry* func;
	struct functions_created *next;

};
typedef struct functions_created* functions_created;
functions_created functions_created_list;
extern int quad_counter;
Quad quad_table, backpatching_table_if, backpatching_index_if, backpatching_table_while, backpatching_index_while,
backpatching_index_while_start, backpatching_table_while_end, backpatching_table_for, backpatching_index_for,
backpatching_index_for_start, backpatching_table_for_end, backpatching_break_start_while, backpatching_break_end_while,
backpatching_index_for_elist, backpatching_table_for_elist, backpatching_break_start_for, backpatching_break_end_for,
backpatching_continue_start_for, backpatching_continue_end_for, backpatching_continue_start_while, backpatching_continue_end_while
,sinolika_loops, backpatching_index_else, backpatching_table_else, scope_space_stack; //dhmioyrgia pointer

/*
unsigned total = 0;
unsigned int currQuad = 0;
quad* quads = (quad*) 0; 
*/
/*********************************************** END PHASE 3 *******************************************************/

/*********************************************** PHASE 4 & 5 **********************************************************/
#define AVM_STACKSIZE 4096
#define AVM_WIPEOUT(m)	memset(&(m), 0, sizeof(m))
#define AVM_TABLE_HASHSIZE 211



extern void generate_ADD (struct quad*);
extern void generate_SUB (struct quad*);
extern void generate_MUL (struct quad*);
extern void generate_DIV (struct quad*);
extern void generate_MOD (struct quad*);
extern void generate_NEWTABLE (struct quad*);
extern void generate_TABLEGETELEM (struct quad*);
extern void generate_TABLESETELEM (struct quad*);
extern void generate_ASSIGN (struct quad*);
extern void generate_NOP (struct quad*);
extern void generate_JUMP (struct quad*);
extern void generate_IF_EQ (struct quad*);
extern void generate_IF_NOTEQ (struct quad*);
extern void generate_IF_GREATER (struct quad*);
extern void generate_IF_GREATEREQ (struct quad*);
extern void generate_IF_LESS (struct quad*);
extern void generate_IF_LESSEQ (struct quad*);
extern void generate_NOT (struct quad*);
extern void generate_OR (struct quad*);
extern void generate_AND (struct quad*);
extern void generate_PARAM (struct quad*);
extern void generate_CALL (struct quad*);
extern void generate_GETRETVAL (struct quad*);
extern void generate_FUNCSTART (struct quad*);
extern void generate_RETURN	(struct quad*);
extern void generate_FUNCEND (struct quad*);
extern void generate_UMIN (struct quad*);
extern void generate_NULL(struct quad*);
typedef enum avm_memcell_t{
	number_m	= 0,
	string_m	= 1,
	bool_m		= 2,
	table_m 	= 3,
	userfunc_m	= 4,
	libfunc_m	= 5,
	nil_m		= 6,
	undef_m		= 7
}avm_memcell_t;

struct avm_table;
struct avm_memcell{
	avm_memcell_t type;
	union{
		double					numVal;
		char*					strVal;
		unsigned char			boolVar;
		struct avm_table*		tableVal;
	    unsigned int 			funcVal;
		char*					libfuncVal;
	};
};
typedef struct avm_memcell* avm_memcell;
avm_memcell stack[AVM_STACKSIZE];
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

struct userfunc{
	int 	address;
	int 	localSize;
	char* 			id;
};
typedef struct userfunc* userfunc;

struct vmarg{
	vmarg_t type;
	int val;
	struct SymbolTableEntry* v_sym;
};
typedef struct vmarg* vmarg;

struct instruction{
	vmopcode opcode; 
	struct vmarg* result;
	struct vmarg* arg1;
	struct vmarg* arg2;
	int srcLine;
	int taddress;
	short patched;

};
typedef struct instruction* instruction;

double*			numConsts;
unsigned int 	totalNumConsts;
char**			stringConsts;
unsigned int 	totalStringConsts;
char**			namedLibFuncs;
unsigned int 	totalNamedLibFuncs;
userfunc*		userFuncs;
unsigned int 	totalUserFuncs;


struct avm_table_bucket{
	avm_memcell					key;
	avm_memcell					value;
	struct avm_table_bucket*	next;
};
typedef struct avm_table_bucket* avm_table_bucket;
struct avm_table{
	unsigned int 		refCounter;
	struct avm_table_bucket* 	strIndexed[AVM_TABLE_HASHSIZE];
	struct avm_table_bucket* 	numIndexed[AVM_TABLE_HASHSIZE];
	unsigned int 				total;
};
typedef struct amv_table* amv_table;

struct incomplete_jump {
	int 			instrNo;
	int 			iaddress;
	int 			patched;
	struct incomplete_jump* next;
};
typedef struct incomplete_jump* incomplete_jump;

struct incomplete_jump* ij_head;/// = (struct incomplete_jump*) 0;
unsigned int 			ij_total ;


typedef void(*generator_func_t)(struct quad*);



/* FUNCTIONS DECLARATIONS */
static void avm_initstack(void);
void avm_tabledestroy(struct avm_table* t);
avm_memcell* avm_tablegetelem(avm_memcell* key);
void avm_tablesetelem(avm_memcell* key, avm_memcell* value);
void avm_tableincrefcounter(struct avm_table* t);
void avm_tabledecrefcount(struct avm_table* t);
void avm_tablebucketsinit(struct avm_table_bucket** p);
struct avm_table* avm_tablenew(void);
void avm_memcellclear(struct avm_memcell* m);
void avm_tablebucketdestroy(struct avm_table_bucket** p);
void avm_tabledestroy(struct avm_table* t);
void generate(int opcode, struct quad* q);
void add_incomplete_jump(unsigned int instrNo, unsigned int iaddress);
void make_operand(struct expr* ex, struct vmarg* arg);
void make_booloperand(struct vmarg* v, int i);
void make_retvaloperand(struct vmarg* v);
unsigned consts_newstring(char* s);
unsigned consts_newnumber(double n);
unsigned libfuncs_newused(char* s);
unsigned consts_newnumber_int(int n);
unsigned userfuncs_newfunc(struct SymbolTableEntry* sym);
unsigned int instructionlabel();
void generate_output();
void patch_incomplete_jumps();
void print_instructions();
/* dikes mas metavlites */
extern unsigned int instruction_counter;
/* oi 4 dinamikes domes dedomenwn */
Dynamic_Table string_array;
Dynamic_Table num_array;
Dynamic_Table userfunc_array;
Dynamic_Table libfunc_array;
Dynamic_Table instruction_array;
Dynamic_Table incomplete_jumps_target_array;
Dynamic_Table return_incomplete_jumps_array;
Dynamic_Table incomplete_jumps_functions;
Dynamic_Table patch_jump_functions;
extern char* vmopcode_types[26];
extern int vmopcode_binary_types[26];

/* dikes mas sinartiseis */
void get_item_entry(struct vmarg* arg);
void emit(struct instruction* i);
void reset_operand(struct vmarg* v);
instruction instruct_init(int opcode,vmarg_t arg1, vmarg_t arg2  );
void create_instruction_output();
void create_binary_output();
void write_vmarg_output(vmarg arg, FILE* f);
void write_vmarg_output_binary(vmarg arg, FILE* f);
void create_binary_file(FILE* f);
void create_binary_file_bin(FILE* f);
struct instruction * create_new_instruction();
extern int dont_increase_locals;
extern int global_size;
extern int local_size;
struct rikas{
	struct instruction* instr;
	int f_id;
	char* f_name;
};

struct cuck{
	int pos;
	int flag;
	int f_id;
	char* f_name;
};
typedef struct rikas* rikas;
typedef struct cuck* cuck;


/*********************************************** END PHASE 4 & 5*******************************************************/



/*************
 * Variables *
 *************/
extern int yylineno; 
extern char* yytext;
extern FILE* yyin;
extern int yylex();
extern int file;
extern int lineno;
extern int token_count;
extern char* yytext;
extern FILE *yyin;
extern FILE *yyout;
extern alpha_token_t *head;

extern char* variable_types[6];
extern struct SymbolTableEntry* collision_list[StartBucket];
extern char* current_function_name;
extern int eimai_se_function;
extern int scope;
extern size_t hidden_tmp_var_counter;
extern int assign_counter;
extern expr true_expression;
extern expr false_expression;
extern expr last_expr_created;
extern expr dimitris;
extern int is_if;
struct Scope_List* Scope_List_Head;
typedef struct SymTable *SymTable_T;
typedef struct SymbolTableEntry* entry;
entry last_function_created;
quad get_last_quad;

SymTable_T Symbol_Table;




/*************
 * Functions *
 *************/
int
alpha_yylex(void* ylval);

void
add_alpha_token(alpha_token_t *head, int line_number, int token_number, char* data,
                char* keyword, char* type, int typename);

char*
category_print(alpha_token_t *head);

char*
type_print(alpha_token_t *head);

void
print_tail_token(alpha_token_t *head);

void
print_tail_token_to_file(alpha_token_t *head);

entry
look_up(char* pv_value, int scope);

void
print_scope(int scope);

void
print_hash_table(SymTable_T oSymTable);

void
print_all_scopes();

void
hide_variables_of_current_scope(int scope);

entry
Scope_List_Contains_Symbol(char *pv_value, int scope);

struct argument_mias_sinartisis*
insert_new_argument(struct argument_mias_sinartisis* head, char* arg_name);


void
print_all_arguments(struct argument_mias_sinartisis* head);

int
conflict_with_system_function(char* name);

entry
Scope_List_Contains_Symbol(char *pv_value, int scope);

void
print_hash_table(SymTable_T oSymTable);

void
print_entry_node_information(entry node);

entry
get_function_entry(char* func_name, int scope);

int
symbol_get_value_type(int type);

int
search_scope(char *pv_value, int scope);

int
function_arguments_valid(char* str, int scope);

/*SymbolTable struct that contains the length of SymbolTable 
and the hash table for all the bindings */
struct Scope_List* Scope_List_Head;
typedef struct SymTable *SymTable_T;
typedef struct SymbolTableEntry* entry;
SymTable_T Symbol_Table;
/* allocates memory for the SymTable and returns the pointer of 
the SymTable or returns NULL if it fails */
SymTable_T   symtable_new(int size);
/* frees the memory of the hash table and then frees the Symtable 
if oSymTable is NULL , do nothing */
void         SymTable_free(SymTable_T oSymTable);
/*Returns the number of bindings of oSymTable.
It has check runtime error if oSymTable is NULL */
unsigned int SymTable_getLength(SymTable_T oSymTable);
/*Returns 1 if there is no binding with pc_key in oSymtable and it assigns it else it returns 0
It has check runtime error if oSymTable is NULL */
int          SymTable_put(SymTable_T oSymTable,  char *pv_value, int line, int scope, int assign_counter, int symbol_table_type);
/*Returns 1 if a binding witeh pc_key exists in oSymTable,
it removes it and reduces the bindings of oSymTable ,else it returns 0
It has check runtime error if oSymTable is NULL */
int   SymTable_remove(SymTable_T oSymTable,  char *pc_key);
/*Returns 1 if a binding with pc_key exists in oSymtable or 0 
It has check runtime error if oSymTable is NULL */
struct SymbolTableEntry* SymTable_contains(SymTable_T oSymTable,  char *pv_value);
/*Returns the value of pc_key(pvValue) in oSymTable if it exists or rettmns NULL
It has check runtime error if oSymTable is NULL */ 
struct SymbolTableEntry* SymTable_get(SymTable_T oSymTable,  char *pc_key);

struct Scope_List* Search_Scope_Node(int scope);                    
/*custom function for printing all bindings of the oSymTable */
void Print(SymTable_T oSymTable);



/*********************************************** PHASE 3 ***********************************************************/
char*
create_name_with_num(char* name_prefix, size_t number_counter);


void
write_quad_to_file(char* op, char* _tmp, expr arg1, expr arg2, FILE* f);

void 
write_if_eq_op_quad_to_file(quad q, FILE* f);

expr
create_quad(int op, expr arg1, expr arg2, expr result);


void
expression_get_type(expr my_expression);


expr
calculate_expr(int op, expr arg1, expr arg2);



int
is_expression_true(expr my_expr);




void quad_struct_init(Quad *quad_struct);

void quad_struct_append(Quad *quad_struct, quad value);

quad quad_struct_get(Quad *quad_struct, int q_index);

void quad_struct_set(Quad *quad_struct, int q_index, quad value);

void quad_struct_double_capacity_if_full(Quad *quad_struct);

void quad_struct_free(Quad *quad_struct);
quad quad_struct_remove(Quad *quad_struct, int index);


expr backpatch_if_quad(Quad *quad_struct, int label, int write);
void backpatch_while_quad(Quad *quad_struct);
void backpatch_for_quad(Quad *quad_struct);
void write_quad_general(quad q);
void write_tablecreate_quad(char* op, char* func_name,int i);
void write_tablesetelem_quad(char* op, char* func_name,int i,expr e);
void write_tablesetelem_index_quad(char* op, char* func_name,expr c, expr e);
void write_tablegetelem_quad(char* op, char* func_name, expr c, expr e);

expr create_new_temp_var();

void print_quad_op(int op);

void insert_last_jump_if();
void insert_last_index_if( );


void insert_last_jump_while();
void insert_last_index_while();


void insert_last_index_while_start();
void insert_last_jump_while_end();

void insert_last_jump_for();
void insert_last_index_for();

void insert_last_jump_else();
void insert_last_index_else();


void insert_last_index_for_start();
void insert_last_jump_for_end();

void insert_last_index_for_elist();
void insert_last_jump_for_elist();


void backpatch_for_counter_quad();
void backpatch_for_elist_quad();
void insert_break_index_while();
void insert_break_jump_while();

void insert_break_index_for();
void insert_break_jump_for();


void insert_continue_index_for();
void insert_continue_jump_for();


void backpatch_while_start_end();


void remove_last_entry_for_break_for();
void remove_last_entry_for_break_while();

void backpatch_break_quad_while();
void backpatch_break_quad_for();

void insert_continue_index_while();
void insert_continue_jump_while();

void insert_continue_index_for();
void insert_continue_jump_for();

void remove_last_entry_for_continue_for();
void remove_last_entry_for_continue_while();

void backpatch_continue_quad_while();
void backpatch_continue_quad_for();

void backpatch_break_quad_while();
void backpatch_break_quad_for();


void insert_loop(int loop);
void remove_last_loop(int loop);
quad get_last_loop();

void function_list_insert(entry func);
void function_list_remove_last();

void enter_scope_space(int type);
void remove_last_scope_space();

void print_expression_info(expr arg);

expr newexpr(expr_t t);
expr newexpr_conststring(char* s);
expr newexpr_constnum(double d);
expr emit_iftableitem(expr e);
expr calculate_expr2(int op, expr arg1, expr arg2);
expr member_item(expr e,char* name);
entry new_temp(expr result, int scope);
expr newexpr_constint(int d);
void
write_tablecreate_quad1(char* op, char* func_name,int i);

void
write_tablesetelem_quad1(char* op, expr func_name,expr c, expr e);

void
write_tablesetelem_index_quad1(char* op, char* func_name,expr c, expr e);




expr make_call(expr lvalue, expr elist);
#endif

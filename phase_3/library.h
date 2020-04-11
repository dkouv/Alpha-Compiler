
#ifndef LIBRARY_H
#define LIBRARY_H


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
#define SYSTEM_FUNCTION_SIZE 11
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
	struct argument_mias_sinartisis* args;
	unsigned int scope;
	unsigned int line;
}Function;

struct SymbolTableEntry {
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
};

/*QUADS*/
 struct quad {
	iopcode op;
	struct expr* result;
	struct expr* arg1;
	struct expr* arg2;
	unsigned label;
	unsigned line;

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
extern char* system_functions[12];
extern char* scope_space_str[3];
extern int stop_writing_quad_loop;
extern int stop_writing_if_quad;
extern int runtime_error;
extern int scope_offset, space_scope;
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
extern char* system_functions[12];
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

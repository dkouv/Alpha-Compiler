%{
	#include "library.h"
	FILE *f;
	alpha_token_t* ylval;
	int yyerror (char* yaccProvideMessage);	
	int start_counter = 0;
	/* metraei posa arguments exei function */
	int formal_argument_count = 0;
	struct SymbolTableEntry* collision_list[StartBucket];
	char* current_function_name;
	int eimai_se_loop = 0;
	int eimai_se_function = 0;
	int tipwsa_error_gia_var = 0;

	int counter = 0;

	Vector tableelem;
	int k =0;
	int table_i_counter = 0;
	int type = 0;
	int scope;
	int functions_without_id = 0;
	int only_term = 0;
	/* anaferetai stis stoives tou if gia backpatching */
	int index1 = 0;
	int index2 = 0;
	/* anaferetai stis stoives tou while gia backpatching */
	int index3 = 0;
	int index4 = 0;
	/* anaferontai sta while start kai end */
	int index5 = 0;
	int index6 = 0;
	int ftiaxnw_jump_apo_logical = 0;

	int index7 = 0;
	int index8 = 0;
	int index9 = 0;
	int index10 = 0;
	/* anaferontai sto last expr tis for */
	int index11 = 0;
	int index12 = 0;
	/* anaferontai sta break */
	int break7 = 0;
	int break8 = 0;
	int while_counter = 0;
	int break_counter = 0;
	int continue_counter = 0;
	int for_counter = 0;

	int scope_offset = 0;
	int space_scope = 0;

	int is_assign = 0;
	int is_objectdef = 0;
	int label_objectdef = 0;
	int open_anon_functions = 0;

	/* gia na auksanw kata 4 to value ths IF EQ*/

	/* an eimaai se while i an eimai se for (1) */
	int se_ti_loop_eimai = 0;

	/* xreiazetai gia backpatching stin if */
	int current_quad_for_if = 0;
	int irthe_else_quad = 0;
	/* metavliti pou krataei ton arithmo twn hidden var gia ta       */
	/* exprs se kathe scope, prepei na ginetai reset meta apo hide() */
	/* _tmp1 _tmp2 ktl												 */
	size_t hidden_tmp_var_counter = 0;

	/*  metavliti pou krataei ton arithmo twn assignment poy exoyn ginei
	 *	mesa se ena scope
	 */
	int assign_counter = 0;
	int is_if = 0;
	/*struct pou krataei to teleutaio identifier gia call function pou dimiourgithike   */
	/* epeidi de boroume na peiraksoume ton tipo tou idlist giati tha gamisei olo ton   */
	/* palio kwdika, kratame ena struct pou tha deiktei tin arxikopoiisei tou ekastote  */
	/* pediou, px int, double ktl 														*/
	expr last_param_created;
	/* stores the last tmp expr created */
	expr last_expr_created;


	expr true_expression;
	expr false_expression;
	expr dimitris;
	expr dimitris1;
	/* arguments current sinartisi */
	struct argument_mias_sinartisis* argument_list_head;
	/*************************************************/
	/* lista me ola ta argument olwn twn sinartisewn */
	/************************************************/
	struct function_argument_lists* list;
	/****************************************************/
	/* apothikeuoume ton tipo tou lvalue p erxetai      */
	/* gia na eleksoume an einai variable gia prakaseis */
	/****************************************************/
	entry expr_node;
	extern int quad_counter;
	char* system_functions[] = {"print", "input", "objectmemberkeys", "objectcopy", 
	"totalarguments", "argument", "typeof", "strtonum", "sqrt", "cos", "sin"};


	char* expression_types[] = {"VAR_E", "TABLEITEM_E", "PROGRAMFUNC_E", "LIBRARYFUNC_E",
		"ARITHEXPR_E", "BOOLEXPR_E", "ASSIGNEXPR_E", "NEWTABLE_E",
		"CONSTINT_E", "CONSTDOUBLE_E", "CONSTBOOL_E", "CONSTSTRING_E", "NIL_E"};

	char* scope_space_str[] = {"PROGRAMVAL", "FUNCTIONLOCAL", "FORMALARG"};
	char* opcode_types[] = 
	{
		"ASSIGN", "ADD", "SUB",
		"NULL", "MUL", "DIVISION", "MOD",
		"UMINUS", "AND", "OR",
		"NOT", "IF_EQ", "IF_NOTEQ",
		"IF_LESSEQ", "IF_GREATEREQ", "IF_LESS",
		"IF_GREATER", "CALL", "PARAM",
		"RET", "GETRETVAL", "FUNCSTART",
		"FUNCEND", "TABLECREATE",
		"TABLEGETELEM", "TABLESETELEM", "JUMP","IF_EQ_OP", "TABLESETELEMINDEX",
		"TABLECREATE1","TABLESETELEM1", "TABLESETELEMINDEX1"
	};
	char* variable_types[] = {"GLOBAL", "LOCAL", "FORMAL", "USERFUNC", "LIBFUNC", "FUNCLOCAL"};
%}

%union{
    int int_val;
    double real_val;
    char* str;
	int boolean;
	char* nil;
	expr my_expr;
	method_call method;
	struct SymbolTableEntry* my_entry;
	indexed_struct indexed_struct;
}

%start	program
%expect	1

/**************
 * PRIORITIES *
 **************/
%right		EQUAL
%left 		OR
%left 		AND
%nonassoc	EQUAL_EQUAL	NOT_EQUAL
%nonassoc	GREATER	GREATER_EQUAL SMALLER SMALLER_EQUAL
%left		PLUS MINUS
%left		MULTIPLICATION DIVISION PERCENTAGE
%right		NOT PLUS_PLUS MINUS_MINUS UMINUS
%left		DOT DOT_DOT		
%left		RIGHT_BRACKET LEFT_BRACKET
%left		RIGHT_PARENTHESES LEFT_PARENTHESES


/********************
 * TERMINAL SYMBOLS *
 ********************/

/************
 * KEYWORDS *
 ************/
%token <str> IF
%token <str> ELSE
%token <str> WHILE
%token <str> FOR
%token <str> FUNCTION
%token <str> RETURN
%token <str> AND
%token <str> NOT
%token <str> OR
%token <str> LOCAL
%token <str> TRUE
%token <str> FALSE
%token <str> NIL
%token <str> BREAK
%token <str> CONTINUE

/************
 * OPERATOR *
 ************/
%token <str> EQUAL
%token <str> PLUS
%token <str> MINUS
%token <str> MULTIPLICATION
%token <str> DIVISION
%token <str> PERCENTAGE
%token <str> EQUAL_EQUAL 
%token <str> NOT_EQUAL
%token <str> PLUS_PLUS
%token <str> MINUS_MINUS
%token <str> GREATER
%token <str> SMALLER
%token <str> GREATER_EQUAL
%token <str> SMALLER_EQUAL
%token <str> RIGHT_CURLY
%token <str> LEFT_CURLY
%token <str> RIGHT_BRACKET
%token <str> LEFT_BRACKET
%token <str> RIGHT_PARENTHESES
%token <str> LEFT_PARENTHESES
%token <str> SEMI_COLON
%token <str> COMMA
%token <str> COLON
%token <str> COLON_COLON
%token <str> DOT
%token <str> DOT_DOT
%token <str> IDENTIFIER

/***********
 * VALUES  *
 ***********/
%token <str> STRING
%token <real_val> REAL
%token <int_val> INTEGER



/************************
 * NON-TERMINAL SYMBOLS *
 ************************/
%type <str>		stmt
%type <my_expr> 	expr
%type <my_expr> 	ifstmt
%type <int_val> ifprefix
%type <int_val> elseprefix
%type <str> 	whilestmt
%type <str> 	whilestmt_continue 
%type <str> 	forstmt
%type <str>		forstmt_continue
%type <str> 	returnstmt 
%type <str> 	block
%type <my_entry> 	funcdefstmt
%type <my_expr>		assignexpr
%type <my_expr>		term 
%type <my_expr>		primary
%type <my_expr>		call
%type <my_expr>		objectdef
%type <my_expr>		const
%type <my_expr>		member
%type <my_expr>		elist
%type <method>		callsuffix
%type <method>		normcall
%type <method>		methodcall
%type <indexed_struct>		indexedelem	
%type <str>		idlist
%type <indexed_struct>	 	indexed
%type <my_expr>		lvalue
%type <indexed_struct>		multi_indexedelem
%type <str>		multi_stmt

%%
program		:{
				if(start_counter == 0){
					printf(GREEN "********START********\n" RESET);
					start_counter++;
				}	
			} 
			stmt 
     	 	{
				only_term = 0;
				printf("\n");
				
  		 	}
			program
			|{printf("start\n");}
			;	

stmt		:expr SEMI_COLON			    {printf(GREEN "expr ;\n" RESET);}	
			|ifstmt		
			    {	
					int i ;
					if(stop_writing_if_quad == 0)
				    for(i = 0; i <= quad_counter - 1 ; i++){
						quad q = quad_struct_get(&quad_table, i);  
						if(q->written == 0)		
							write_quad_general(q);
					}
					printf(GREEN "ifstmt\n" RESET);			
				
				}
			|whilestmt 
				{
					backpatch_while_quad(&quad_table);
					
					printf(GREEN "while\n"RESET);
				}
			|forstmt 
				{
						backpatch_for_quad(&quad_table); 

					printf(GREEN "forstmt\n"RESET);
				}
			|returnstmt						
			{
				if (eimai_se_function == 0){
					printf(RED "Not in a loop\n"RESET);
					runtime_error = 1;
			}
				printf(GREEN "returnstmt ;\n"RESET);
			}
			|BREAK  SEMI_COLON				
			{
				if (eimai_se_loop == 0){
					printf(RED "Not in a loop\n"RESET);
					runtime_error = 1;
					
				}else{
					break_counter++;
					create_quad(jump, true_expression, true_expression, true_expression);
					if(get_last_loop() == while_quad)
						insert_break_jump_while();
					else if(get_last_loop() == for_quad)
						insert_break_jump_for();
				}
				printf(GREEN "break ;\n"RESET);
			}
			|CONTINUE SEMI_COLON			
			{
				if (eimai_se_loop == 0){
					printf(RED "Not in a loop\n"RESET);
					runtime_error = 1;
				}else{
					continue_counter++;
					printf(RED"Eskase continue se loop ctr :%d\n"RESET, se_ti_loop_eimai);
					if(get_last_loop() == while_quad){
						create_quad(jump, true_expression, true_expression, true_expression);
						insert_continue_jump_while();
						backpatch_continue_quad_while();	
			
					}else if(get_last_loop() == for_quad){
						create_quad(jump, true_expression, true_expression, true_expression);
						insert_continue_jump_for();
						backpatch_continue_quad_for();	
			
					}
				}
				printf(GREEN "continue ;\n"RESET);
			}
			|block							{printf(GREEN "block\n"RESET);}
			|funcdefstmt					{function_list_remove_last();
												remove_last_scope_space();
												printf(GREEN "funcdefstmt\n"RESET);
												
											}
			|SEMI_COLON						{printf(GREEN ";\n" RESET);}   
			;

expr		:assignexpr							{printf(BLUE "assignexpr\n" RESET);}
			|expr PLUS expr 					{printf(BLUE "expr + expr\n" RESET); printf("TIPOS :%s\n", expression_types[$1->type]);$$ = calculate_expr(add, $1, $3);}
			|expr MINUS expr					{printf(BLUE "expr - expr\n" RESET); $$ = calculate_expr(sub, $1, $3);}
			|expr MULTIPLICATION expr 			{printf(BLUE "expr * expr\n" RESET); $$ = calculate_expr(mul, $1, $3);}
			|expr DIVISION expr 				{printf(BLUE "expr / expr\n" RESET); $$ = calculate_expr(division, $1, $3);}
			|expr PERCENTAGE expr 				{printf(BLUE "expr %% expr\n" RESET); $$ = calculate_expr(mod, $1, $3); }
			|expr GREATER expr 					{
				printf(BLUE "expr > expr\n" RESET);
				$$ = calculate_expr(if_greater, $1, $3);
			 	
				create_quad(assign, $$, false_expression, false_expression);
				create_quad(jump, true_expression, true_expression, true_expression);
				
				create_quad(assign, $$, true_expression, false_expression);
				

				}
			|expr SMALLER expr 					
			{
				printf(BLUE "expr < expr\n" RESET); 
				$$ = calculate_expr(if_less, $1, $3); 
				
				create_quad(assign, $$, false_expression, false_expression);
				create_quad(jump, true_expression, true_expression, true_expression);
				
				create_quad(assign, $$, true_expression, false_expression);
				
			}
			|expr GREATER_EQUAL expr 			
			{
				printf(BLUE "expr >= expr\n" RESET); 
				$$ = calculate_expr(if_greatereq, $1, $3);
				create_quad(assign, $$, false_expression, false_expression);
				create_quad(jump, true_expression, true_expression, true_expression);
				
				create_quad(assign, $$, true_expression, false_expression);
				

			  }
			|expr SMALLER_EQUAL expr 			
			{
				printf(BLUE "expr <= expr\n" RESET); 
				$$ = calculate_expr(if_lesseq, $1, $3);
				create_quad(assign, $$, false_expression, false_expression);
				create_quad(jump, true_expression, true_expression, true_expression);
				
				create_quad(assign, $$, true_expression, false_expression);
			}
			|expr EQUAL_EQUAL expr 				
			{
				printf(BLUE "expr == expr\n" RESET); 
				printf(RED" %d\n"RESET, is_if);
				$$ = calculate_expr(if_eq_op, $1, $3); 
				create_quad(assign, $$, false_expression, false_expression);
				create_quad(jump, true_expression, true_expression, true_expression);
				create_quad(assign, $$, true_expression, false_expression);	
				
			}
			|expr NOT_EQUAL expr 				
			{
				printf(BLUE "expr != expr\n" RESET); 
				$$ = calculate_expr(if_noteq, $1, $3);
				create_quad(assign, $$, false_expression, false_expression);
				create_quad(jump, true_expression, true_expression, true_expression);
				create_quad(assign, $$, true_expression, false_expression);		
			}
			|expr AND expr 						{printf(BLUE "expr and expr\n" RESET);printf("str :%s %s\n", $1->strConst , $3->strConst); $$ = calculate_expr(and, $1, $3); printf("ENd of and\n");}
			|expr OR expr 						{printf(BLUE "expr or expr\n" RESET); $$ = calculate_expr(or, $1, $3);}
			|term 								
			{
				only_term ++;
				printf(BLUE "term\n" RESET);
				/* arxikopoiw to last_param_created afou sigoura tha proerxetai apo term */
				//memcpy(last_param_created, $$, sizeof(struct expr));
					
			} 	
			;
/*printf("Values :%d *%d\n", $1->const_int, $3->const_int);$$->const_int = $1->const_int * $3->const_int;}*/
 
 

term 		:LEFT_PARENTHESES expr RIGHT_PARENTHESES		
			{
				
				$$ = $2;
				printf(BLUE "( expr ) -> " RESET);
			}
			|MINUS expr	%prec UMINUS								
			{
				
				$$ = (expr) calloc(sizeof(struct expr), sizeof(struct expr));
				$$ = $2;
				$$ = calculate_expr(uminus, $2, $2);
				printf("- expr -> " RESET);
			}
			|NOT expr										
			{
				$$ = (expr) calloc(sizeof(struct expr), sizeof(struct expr));

				$$->type = constbool_e;

				$$ = calculate_expr(not, $2, $2);
				printf(BLUE "!  expr -> " RESET);
			}
			|PLUS_PLUS lvalue
				{
					/******************************************************/
					/* checking  gia apofigi praksis me function variable */
					/******************************************************/
					if(expr_node ){					
						if(symbol_get_value_type(expr_node->type) == 1 ){
							printf(RED "Cannot ++function at line :%d\n"RESET, yylineno);
							 
						} 
					}
					expr_node = NULL;

					expr ena;
					ena = calloc(sizeof(struct expr), sizeof(struct expr));
					
					ena->const_int = 1; 
					ena->type = constint_e;

					$$ = create_quad(add, ena, $2, $2);

					printf(BLUE "++lvalue ->" RESET);
				
				
				
				}	
			|lvalue PLUS_PLUS								
				{
					/******************************************************/
					/* checking  gia apofigi praksis me function variable */
					/******************************************************/
					if(expr_node){					
						if(symbol_get_value_type(expr_node->type) == 1){
							printf(RED "Cannot function++ at line :%d\n"RESET, yylineno);
					 
						} 
					}
					expr_node = NULL;
					expr ena;
					ena = calloc(sizeof(struct expr), sizeof(struct expr));
					
					ena->const_int = 1; 
					ena->type = constint_e;

					$$ = create_quad(add, $lvalue, ena, $lvalue);
					
					printf(BLUE "lvalue++ ->" RESET);
				}
			|MINUS_MINUS lvalue								
				{
					/******************************************************/
					/* checking  gia apofigi praksis me function variable */
					/******************************************************/
					if(expr_node){					
						if(symbol_get_value_type(expr_node->type) == 1){
							printf(RED "Cannot --function at line :%d\n"RESET, yylineno);
 
						} 
					}
					expr_node = NULL;

					expr ena;
					ena = calloc(sizeof(struct expr), sizeof(struct expr));
					
					ena->const_int = 1; 
					ena->type = constint_e;

					$$ = create_quad(sub, $lvalue, ena, $lvalue);

					printf(BLUE "--lvalue -> " RESET);
				}
			|lvalue MINUS_MINUS								
				{
					/******************************************************/
					/* checking  gia apofigi praksis me function variable */
					/******************************************************/
					if(expr_node){					
						if(symbol_get_value_type(expr_node->type) == 1){
							printf(RED "Cannot function-- at line :%d\n"RESET, yylineno);
							 
						} 
					} 
					expr_node = NULL;
					expr ena;
					ena = calloc(sizeof(struct expr), sizeof(struct expr));
					
					ena->const_int = 1; 
					ena->type = constint_e;

					$$ = create_quad(sub, $lvalue, ena, $lvalue);
					printf(BLUE "lvalue-- -> " RESET);
				}
			|primary                        				{only_term ++;printf(BLUE "primary -> " RESET);}
			;			

assignexpr 	:lvalue EQUAL expr								
				{	
					/******************************************************/
					/* checking  gia apofigi praksis me function variable */
					/******************************************************/
					if(expr_node){
						//printf("To expr_node einai :%d\n", expr_node->type);
						if(symbol_get_value_type(expr_node->type) == 1 && strcmp($1->strConst, expr_node->value.funcVal->name) == 0){
							printf(RED "Cannot perform assignment with function at line :%d\n"RESET, yylineno); 
						} 
					}else {
						entry e = look_up($1->strConst, scope);
						if(e && symbol_get_value_type(e->type) == 0 && eimai_se_function != 0 && e->value.varVal->scope != 0 && e->value.varVal->scope != scope && !eimai_se_loop){
								if(tipwsa_error_gia_var == 0)
									printf(RED"Cannot access :%s inside of function\n"RESET, $1->strConst);
							
						}
					}
					expr_node = NULL;
					tipwsa_error_gia_var = 0;
					printf(BLUE "lvalue = expression -> " RESET);
					if ($expr->type == newtable_e) {
						is_objectdef = 0;
						vector_print(label);

						vector_free(&tableelem);
						vector_init(&tableelem);
						$$ = create_quad(assign, $3, $1, true_expression);


					}else if($lvalue->type == tableitem_e) {
		
						create_quad(tablesetelem,$lvalue,$lvalue->index,$expr);

						$assignexpr = emit_iftableitem($lvalue);
						$assignexpr->type = assignexpr_e; 
						
						
					}else {						
						create_quad(assign, $1, $expr, true_expression);

						$assignexpr = newexpr(assignexpr_e);
						$assignexpr->type = assignexpr_e;
						$assignexpr->sym = Scope_List_Contains_Symbol($assignexpr->strConst, scope);
						$assignexpr = create_new_temp_var();
						create_quad(assign,$assignexpr,$lvalue,true_expression);

					}
					
				}
primary 	:lvalue											
			{
				printf(BLUE "lvalue -> " RESET);
				$primary = (expr )emit_iftableitem($lvalue);
				//printf(RED "%s\n" RESET, $primary->strConst);
			}
			|call											
			{/* edw tha kanw to neo quad gia to function , px F(a, b) */
				
			
				//create_quad(call, $$, true_expression, true_expression);
				//$$ = calculate_expr(getretval, true_expression, true_expression);
				
				printf(BLUE "call -> " RESET);
			}
			|objectdef										{printf(BLUE "objectdef -> " RESET);}
			|LEFT_PARENTHESES funcdefstmt RIGHT_PARENTHESES	
			{
				$$->type = programfunc_e;
				$$->sym = $2;
				
				printf(BLUE "( funcdefstmt ) -> " RESET);
			}
			|const											
			{
				only_term ++;
				$$ = $1;
				
				printf(BLUE "const -> " RESET);
			}
			;

lvalue		:IDENTIFIER						
				{
						/************************************************************************/
						/* diavasa ena simvolo,  poy borei na anaferetai se function i variable */
						/* an einai omws function de borw na kanw prakseis me to lvalue opote   */
						/* to apothikeuw kai to elegxw ksexwrista se kathe periptwsi tou lvalue */
						/* to expr_node einai pedio tou yylval union                            */
						/************************************************************************/
				printf("%s -> ", $1);
				$$ = calloc(sizeof(struct expr), sizeof(struct expr));
				$$->strConst = strdup($1);
				$$->type = var_e;
				only_term++;
				
				entry e = NULL;
				e = look_up($1, scope);
			
				
				/********************************************/
				/* elegxw an iparxei sto stoixeio $1 sto    */
				/* scope list, an oxi to eisagw me to scope */
				/********************************************/
				if (conflict_with_system_function($1) == 0){


					entry iparxei_func = get_function_entry($1, scope);

					if (!e){
						if (scope == 0) 
							SymTable_put(Symbol_Table, $1, yylineno, scope, assign_counter, 0);
						else 
							SymTable_put(Symbol_Table, $1, yylineno, scope, assign_counter, 1);
						expr_node = Scope_List_Contains_Symbol($1, scope);

					}else{
						
						if(symbol_get_value_type(e->type) == 0 && eimai_se_function != 0 && e->value.varVal->scope != 0 && e->value.varVal->scope != scope && !eimai_se_loop){
							if(iparxei_func == NULL){

								printf(RED"Cannot access :%s inside of function\n"RESET, $1);
								tipwsa_error_gia_var = 1;
							}
						}else if ( e->isActive ) {
							printf("Symbol :%s is already defined and active, den kanw put\n", $1);
							print_entry_node_information(e);
							expr_node = e;
						}
						else if(!e->isActive) {
							if (scope)
								SymTable_put(Symbol_Table, $1, yylineno, scope, assign_counter, 1);
							else
								SymTable_put(Symbol_Table, $1, yylineno, scope, assign_counter, 0);
							expr_node = Scope_List_Contains_Symbol($1, scope);

						}


					}
				}else {
					printf("Referring to LIBFUNC:%s\n", $1);


				}	
				
			}
								

			
			|LOCAL IDENTIFIER		
			{
				$$ = calloc(sizeof(struct expr), sizeof(struct expr));
				$$->strConst = strdup($2);
				only_term++;
				printf(BLUE "local %s -> " RESET, $2);
				/******************************************/
				/* an to scope einai global ,borw na kanw */
				/* local system_function xwris provlima   */
				/******************************************/
				/* an den iparxei sto local scope  */
				if (Scope_List_Contains_Symbol($2, scope) == NULL){
					/* vrikame oti kanei conflict me to name mia system sinartisis */
					if(conflict_with_system_function($2) == 1){
						if(scope == 0){
							printf("%s, referring to function in scope 0\n", $2);
						}else {
							printf(RED"Error: symbol: %s trying to shadow system function at line: %d\n" RESET, $2, yylineno);
						}	

					}else if (scope == 0) 
						SymTable_put(Symbol_Table, $2, yylineno, scope, assign_counter, 0);
					else	
						SymTable_put(Symbol_Table, $2, yylineno, scope, assign_counter, 1);
				}else {
					/* iparxei sto current scope */
					printf("Referring to local scope symbol:%s\n", $2);


				}



			}

			|COLON_COLON IDENTIFIER	
			{
				$$ = calloc(sizeof(struct expr), sizeof(struct expr));
				$$->strConst = strdup($2);
				only_term++;
				printf(BLUE ":: %s -> " RESET, $2);

				if(conflict_with_system_function($2) == 1){
					printf("Error: symbol: %s trying to shadow system function at line: %d\n", $2, yylineno);
				}
				else if (look_up($2,0) == NULL) //psaxnw mono sto Global scope kai an den iparxei error;
				{
					printf(RED"Error: symbol :%s does not exist in global scope\n"RESET, $2);
					
				}else 
					printf("Symbol :%s exists in global scope\n", $2);
				
			}

			|member	
				{ 
					printf(MAGENTA"K=%d"RESET,k++);
					$lvalue = $member;
					printf(YELLOW "\t2 : %s -@@@@@@@@@@- %d\n" RESET, $lvalue->strConst, $lvalue->type);
					printf(BLUE "member -> " RESET);
				}
			;

member		:lvalue DOT IDENTIFIER { 
				printf(BLUE "lvalue. %s  -> " RESET, $3);
				
				printf("TYPE :%d\n", $1->type);	

				$member  =  member_item($1,$3);
			
			}

			|lvalue LEFT_BRACKET expr RIGHT_BRACKET { 
				counter++;
				printf(RED "%d\n" RESET, counter);
				printf(BLUE "lvalue [ expr ] -> " RESET);
				$lvalue = emit_iftableitem($lvalue);
				printf(RED "------------%s----------" RESET,$lvalue->strConst);
				printf("$expr->CONSTINT------------>%d\n",$expr->const_int);
				$member = newexpr(tableitem_e);
				$member->sym = $lvalue->sym;
				$member->strConst = strdup($1->strConst);
				$member->index = $expr;
				
				// printf("member--------------->%d\n",$member->index->const_int);
				// printf("expr--------------->%d\n",$expr->const_int);
			}
			|call {expr_node = NULL;} DOT IDENTIFIER					{printf(BLUE "lvalue . %s -> " RESET, $1->strConst);}
			|call {expr_node = NULL;} LEFT_BRACKET expr RIGHT_BRACKET   {printf(BLUE "call [ expr ] -> " RESET);}
			;

call 		:call LEFT_PARENTHESES elist RIGHT_PARENTHESES 
			{
				
				$$ = make_call($1, $elist);

				printf(BLUE "call ( elist ) -> " RESET);
			}
			|lvalue
			{	
				entry iparxei_func = get_function_entry($1->strConst, scope);
				if(iparxei_func){
					printf("Referring to :%s at line %d\n", $1->strConst, iparxei_func->value.funcVal->line);
				}	
			}
			callsuffix 
			{
				 if($callsuffix->m_method == 1){
					 printf(RED"HERE\n"RESET);
					 expr self = $lvalue;
					 $lvalue = emit_iftableitem(member_item(self, $callsuffix->m_name));
					 
					 expr tmp = $callsuffix->m_expr;
					 while(tmp->next){
						 tmp = tmp->next;
					 }
					 tmp->next = self;
					 $callsuffix->m_expr = self;
				 }
				 $call = make_call($lvalue, $callsuffix->m_expr);
				 printf(BLUE "lvalue callsuffix -> " RESET);
			}   
			|LEFT_PARENTHESES funcdefstmt RIGHT_PARENTHESES LEFT_PARENTHESES elist RIGHT_PARENTHESES
				{
					expr f = newexpr(programfunc_e);
					f->sym = $2;
					printf("$2 is %s\n", $2->value.funcVal->name);
					printf("tipwnw pointer elist %p\n", $elist);
					printf("VALUE1 :%s\n", f->sym->value.funcVal->name);
					$call = make_call(f, $elist);

			 		printf(BLUE "( funcdefstmt ) ( elist )  -> " RESET);

					
			 	}
				
			;

callsuffix  :normcall	{
					printf("HERE\n");
					if($1 !=NULL && $1->m_expr){
						expr tmp = $1->m_expr;
						
						while(tmp){
							tmp = tmp->next;
						}
						$$ = $1;
					}
					printf("DONE2121\n");
				;printf(BLUE "normcall -> " RESET);}
			|methodcall {$$ = $1;printf(BLUE "methodcall -> " RESET);}
			;

normcall	:LEFT_PARENTHESES elist RIGHT_PARENTHESES 
				{	
					
						if($$ != NULL){
							printf("PRIN\n");
							$$->m_expr = $2;
					
							$$->m_method = 0;
							$$->m_name = strdup("nil");
							
				}
					printf(BLUE "( elist ) -> " RESET);
				};
 
methodcall	:DOT_DOT IDENTIFIER LEFT_PARENTHESES elist RIGHT_PARENTHESES
			 {
				
				$$->m_expr = $elist;
				$$->m_name = strdup($2);
				$$->m_method = 1; 
							
							printf(BLUE ".. %s ( elist ) -> " RESET, $2);
			};

elist 		:expr 				
			{
				
				/* edw tha kanw to neo quad gia to parameter , px f(a, b) */
				//if(se_ti_loop_eimai == 0)
				//	create_quad(param, $1, true_expression, true_expression);
				$$ = $1;
				$$->next = NULL;
				printf(BLUE "expr -> " RESET);
			}
			|elist COMMA expr	
			{
				/* edw tha kanw to neo quad gia to parameter , px f(a, b) */
				//if(se_ti_loop_eimai == 0)
				//	create_quad(param, $3, true_expression, true_expression);
				expr tmp = $1;
				while(tmp->next != NULL){
					tmp = tmp->next;
				}

				tmp->next = $3;
				$$ = $1;

				printf(BLUE "elist , expr -> " RESET);
			}
			|					
				{
					
					$$ = NULL;
					
					printf(RED "Empty elist\n" RESET);
				}
			;
objectdef	:LEFT_BRACKET elist RIGHT_BRACKET 
				{	
					$$ = create_new_temp_var();
					
					create_quad(tablecreate, $$, true_expression, true_expression);
					printf(RED" table :%s\n"RESET, $$->strConst);
					expr tmp = $2;
					int i = 0;
					while(tmp != NULL){

							create_quad(tablesetelem1, $$, newexpr_constint (i++), tmp);
						 
					
						tmp = tmp->next;
					}
							
					
				}
			|LEFT_BRACKET indexed RIGHT_BRACKET
		    	{
		     		$$ = create_new_temp_var();
		     		create_quad(tablecreate, $$, true_expression, true_expression);

		     		indexed_struct tmp = $indexed;
		     		while(tmp != NULL){

		     			create_quad(tablesetelem1, $$, tmp->index, tmp->value);
		     			tmp = tmp->next;
		     		}

		    		printf("[ indexed ] -> ");
				}
			;

indexed		:indexedelem 
				{ 
			 		$$ = $indexedelem;
			 		printf(BLUE "indexelem -> " RESET );
		    	}
			|indexedelem COMMA multi_indexedelem  
				{ 
					indexed_struct tmp = $indexedelem;
					while(tmp->next != NULL){
						tmp = tmp->next;
					}

					tmp->next = $multi_indexedelem;
					$$ = $indexedelem;

					printf(BLUE "indexelem , indexelem -> " RESET);
				}
			;

multi_indexedelem:indexed 
				 ;

indexedelem	:LEFT_CURLY expr COLON expr RIGHT_CURLY 
				{
					$$ = calloc(sizeof(struct indexed_struct), sizeof(struct indexed_struct));
					$$->index =  $2;
					$$->value =  $4;

					printf(BLUE "{ expr : expr } -> " RESET);
				}

			;

block 		:LEFT_CURLY {scope++;} multi_stmt  RIGHT_CURLY		{hide_variables_of_current_scope(scope);scope--;printf(BLUE "{ stmt } -> " RESET);};

multi_stmt	:multi_stmt stmt	{printf(BLUE "multi_stmt -> " RESET);}
			|					{printf(BLUE "Block\n" RESET);}
			;
funcdefstmt	:FUNCTION  IDENTIFIER 
		{
			se_ti_loop_eimai = 1;
			/* allazw scope_offset */
			enter_scope_space(functionLocal);



			/* telos allagis */
			entry node;
			
			/* elegxw an iparxei to node sto scope */

			node = Scope_List_Contains_Symbol($2, scope);

			/* vrike to idio node sto scope , error */
			if(node){
				printf(RED "Error, symbol :%s already Exists\n"RESET, $2);
				
			}else{
				/**********************************************/
				/* de vrethike to node sto scope              */
				/* elegxw an exei onoma sinartisis sistimatos */
				/**********************************************/

				if(conflict_with_system_function($2) == 1){
					printf(RED"Error: symbol: %s Collision with system function at line:%d\n"RESET, $2, yylineno);
		
				}else {
					/* efoson den petakse kapoio minima den exoun idio identifier */
					SymTable_put(Symbol_Table, $2, yylineno, scope, assign_counter, 3);
					current_function_name = strdup($2);
				}
			}
			/* memory allocation for function expression gia na to steiloume gia quad             */
			/* arkei na allaksoume mono to pedio strConst kai ton tipo afou to name tis func_expr */
			/* tha einai panta string! 															  */

			expr func_expr = calloc(sizeof(struct expr), sizeof(struct expr));
			func_expr->type = conststring_e;
			func_expr->strConst = strdup($2);
			create_quad(funcstart, func_expr, true_expression, true_expression);

		}	
		LEFT_PARENTHESES {enter_scope_space(2);}idlist {remove_last_scope_space();}RIGHT_PARENTHESES {eimai_se_function++;} block {eimai_se_function--;} 
			{
				printf("PARAMETROI\n");
				/************************************************************/
				/* kanw null ti lista etsi oste ta arguments tis sinartisis */
				/* na min ta paroun oi epomenes sinartiseis					*/
				/************************************************************/
			


				expr func_expr = calloc(sizeof(struct expr), sizeof(struct expr));
				func_expr->type = conststring_e;
				func_expr->strConst = strdup(last_function_created->value.funcVal->name);
				create_quad(funcend, func_expr, true_expression, true_expression);
				printf(BLUE "%s  ( idlist ) block -> " RESET, $1);
				argument_list_head = NULL;
				formal_argument_count = 0;
				se_ti_loop_eimai = 0;

				$funcdefstmt = get_function_entry($IDENTIFIER, scope);
				
			}
		|FUNCTION  LEFT_PARENTHESES 
			{
				open_anon_functions++;
				enter_scope_space(functionLocal);
				se_ti_loop_eimai = 1;

				/* Create name for the new function */
				printf(BLUE "Function without identifier :_func%d\n" RESET, functions_without_id);			
					
				/* Create name for the new function */
				char* name = malloc(strlen("_func") + 4);
				strcpy(name, "_func");
				sprintf(&name[5], "%d", functions_without_id);
				current_function_name = strdup(name);
				SymTable_put(Symbol_Table, name , yylineno, scope, assign_counter, 3);	
				functions_without_id++;

					
				expr func_expr = calloc(sizeof(struct expr), sizeof(struct expr));
				func_expr->type = conststring_e;
				func_expr->strConst = strdup(name);
				create_quad(funcstart, func_expr, true_expression, true_expression);

			}
		{enter_scope_space(2);}idlist {remove_last_scope_space();}RIGHT_PARENTHESES {eimai_se_function++;} block {eimai_se_function--;} 
				{
					int current_name = functions_without_id - open_anon_functions;
					char* name = malloc(strlen("_func") + 4);
					strcpy(name, "_func");
					sprintf(&name[5], "%d", current_name);
					current_function_name = strdup(name);
					$funcdefstmt = get_function_entry(current_function_name, scope);

					
					open_anon_functions--;
					/* kanw null ti lista etsi oste ta arguments tis sinartisis
					na min ta paroun oi epomenes sinartiseis*/
					argument_list_head = NULL;
					formal_argument_count = 0;

					expr func_expr = calloc(sizeof(struct expr), sizeof(struct expr));
					func_expr->type = conststring_e;
					func_expr->strConst = strdup(last_function_created->value.funcVal->name);
					create_quad(funcend, func_expr, true_expression, true_expression);
						
					se_ti_loop_eimai = 0;
				}
			;



const 		:INTEGER	
			{
				only_term ++;
				$$ = (expr) calloc(sizeof(struct expr), sizeof(struct expr));
				$$->type = constint_e;
				$$->const_int = $1;
				printf(BLUE "%d -> " RESET, $1);
			}
			|REAL					
			{only_term ++;
				$$ = (expr) calloc(sizeof(struct expr), sizeof(struct expr));
				$$->type = constdouble_e;
				$$->const_double = $1;
				printf(BLUE "%f -> " RESET, $1);
			}
			|STRING					
			{only_term ++;
				$$ = (expr) calloc(sizeof(struct expr), sizeof(struct expr));
				$$->type = conststring_e;
				$$->strConst = strdup($1);
				printf(BLUE "%s -> " RESET, $1);
			}
			|NIL					
			{only_term ++;
				$$ = (expr) calloc(sizeof(struct expr), sizeof(struct expr));
				$$->type = nil_e;
				printf(BLUE "NIL -> " RESET);
			}
			|TRUE					
			{	only_term ++;
				$$ = (expr) calloc(sizeof(struct expr), sizeof(struct expr));
				$$->type = constbool_e;
				$$->boolConst = 1;
				
				printf(BLUE "TRUE -> " RESET);
			}
			|FALSE					
			{only_term ++;
				$$ = (expr) calloc(sizeof(struct expr), sizeof(struct expr));
				$$->type = constbool_e;
				$$->boolConst = 0;
				printf(BLUE "FALSE -> " RESET);
			}
			;

idlist		:IDENTIFIER						
			{
				$$ = $1;
				argument_list_head = insert_new_argument(argument_list_head, $1);
				/* prepei na diasxisw oli ti lista me ta arguments kai na eleksw an einai valid */
				entry scope_node;
				if(current_function_name != NULL && function_arguments_valid($1, scope + 1) == 1){
					//function_arguments_valid(scope_node, scope);
					/* *********************************************************************/
					/* vriskw to function node p molis dimiourgisa gia na tou			   */
					/* valw ti lista me ta arguments pou vrika apo to idlist, to insertion */
					/* sti lista ginetai ston kanona tou idlist							   */
					/***********************************************************************/
					scope_node = Scope_List_Contains_Symbol(current_function_name, scope);
					if(scope_node != NULL){
						/**************************************************************/
						/* i lista twn argument vrisketai sto struct function,	      */
						/* kserw sigoura pws to node m einai function opote apla kanw */
						/* access kai vazw ti lista 								  */
						/**************************************************************/
						scope_node->value.funcVal->args = argument_list_head;
						SymTable_put(Symbol_Table, $1, yylineno, scope + 1, assign_counter, 2);

					
					formal_argument_count++;
					}	
				}
					/* dimiourgw ta params gia tin function !! */
					/* edw tha kanw to neo quad gia to parameter , px f(a, b) */
				if(se_ti_loop_eimai == 0){
					last_param_created->type = param;
					last_param_created->strConst = strdup($1);
					create_quad(param, last_param_created, true_expression, true_expression);
				}
				
				printf("%s \n", $1);
				} 
			|idlist COMMA IDENTIFIER		
				{

					argument_list_head = insert_new_argument(argument_list_head, $3);
					/* prepei na diasxisw oli ti lista me ta arguments kai na eleksw an einai valid */
					entry scope_node;

				if(current_function_name != NULL && function_arguments_valid($3, scope + 1) == 1){
					//function_arguments_valid(scope_node, scope);
					/* *********************************************************************/
					/* vriskw to function node p molis dimiourgisa gia na tou			   */
					/* valw ti lista me ta arguments pou vrika apo to idlist, to insertion */
					/* sti lista ginetai ston kanona tou idlist							   */
					/***********************************************************************/
					scope_node = Scope_List_Contains_Symbol(current_function_name, scope);
					if(scope_node != NULL){
						/**************************************************************/
						/* i lista twn argument vrisketai sto struct function,	      */
						/* kserw sigoura pws to node m einai function opote apla kanw */
						/* access kai vazw ti lista 								  */
						/**************************************************************/
						scope_node->value.funcVal->args = argument_list_head;
						SymTable_put(Symbol_Table, $3, yylineno, scope + 1, assign_counter, 2);

					
					formal_argument_count++;
					}	
				}	

					/* dimiourgw ta params gia tin function !! */
					/* edw tha kanw to neo quad gia to parameter , px f(a, b) */
					if(se_ti_loop_eimai == 0)
					{
						last_param_created->type = param;
						last_param_created->strConst = strdup($3);
						create_quad(param, last_param_created, true_expression, true_expression);
					}
					printf("%s \n", $3);
				} 
			|								{printf(BLUE "Empty idlist\n" RESET);}
			;


ifprefix:		IF LEFT_PARENTHESES {stop_writing_if_quad++;}expr RIGHT_PARENTHESES
				{
					
					create_quad(if_eq, $expr, true_expression, true_expression);
					$ifprefix = quad_counter;
					create_quad(jump, true_expression, true_expression, true_expression);
				};

elseprefix:		ELSE
				{
					
					$elseprefix = quad_counter;
					create_quad(jump, true_expression, true_expression, true_expression);
				};



ifstmt:			ifprefix stmt
{
				quad_struct_get(&quad_table, $ifprefix)->label = quad_counter;
				stop_writing_if_quad--;
}






				| ifprefix stmt elseprefix stmt{
					printf(RED" LALALAL :%d\n"RESET, $ifprefix);
					quad_struct_get(&quad_table, $ifprefix)->label = $elseprefix + 1;
					quad_struct_get(&quad_table, $elseprefix)->label = quad_counter;

					 {stop_writing_if_quad--;}
				}

whilestmt	:WHILE LEFT_PARENTHESES
				{
					insert_loop(0);
					
					stop_writing_if_quad++;
					insert_last_index_while_start();


					/* patching gia continue */
					while_counter++;
					insert_continue_index_while();
				}
			whilestmt_continue;


whilestmt_continue: expr
						{
							create_quad(if_eq, $1, true_expression, true_expression);
							create_quad(jump, true_expression, true_expression, true_expression);
							insert_last_jump_while();	
							
						}
				    RIGHT_PARENTHESES {eimai_se_loop++;} stmt {eimai_se_loop--;}
						{
							
							create_quad(jump, true_expression, true_expression, true_expression);
							insert_last_jump_while_end();
					
							insert_last_index_while();
							stop_writing_if_quad--;
							printf(BLUE "while ( expr ) stmt -> " RESET);
							insert_break_index_while();
							backpatch_break_quad_while();
					
							remove_last_entry_for_break_while();
							remove_last_entry_for_continue_while();
							
							while_counter--;
							//backpatch_while_start_end();
							remove_last_loop(0);
						}
				;

forstmt		:FOR LEFT_PARENTHESES { se_ti_loop_eimai = 1;}elist SEMI_COLON
					{
					

						insert_loop(1);
						for_counter++;
						insert_last_index_for_start();
						
						stop_writing_if_quad++;
						
					}
			forstmt_continue;

forstmt_continue: expr 
					{
						create_quad(if_eq, $1, true_expression, true_expression);
						quad_struct_get(&quad_table, quad_table.size - 1)->label += 2;
						create_quad(jump, true_expression, true_expression, true_expression);
						
						insert_last_jump_for();
					}
				SEMI_COLON 
				{
					insert_last_index_for_elist();
					insert_continue_index_for();
				}	
					elist 
					{
						
						create_quad(jump, true_expression, true_expression, true_expression);
						insert_last_jump_for_end();
	
						
					}
				RIGHT_PARENTHESES{eimai_se_loop++;} stmt {eimai_se_loop--;}
					{
						
						

						//create_quad(jump, true_expression, true_expression, true_expression);
						create_quad(jump, true_expression, true_expression, true_expression);
						insert_last_jump_for_elist();
						
						insert_last_index_for();
						stop_writing_if_quad--;
						backpatch_for_elist_quad();
						printf(BLUE "for ( elist ; expr ; elist ) stmt -> " RESET);

						insert_break_index_for();
						backpatch_break_quad_for();
						remove_last_entry_for_break_for();
						remove_last_entry_for_continue_for();
						for_counter--;
						se_ti_loop_eimai = 0;
						remove_last_loop(1);

					}	
			;

returnstmt 	:RETURN SEMI_COLON			
			{
				expr p = calloc(sizeof(struct expr), sizeof(struct expr));
				p->strConst = strdup(";");
				p->type = conststring_e;
				calculate_expr(ret, p, true_expression);
				printf(BLUE "return ; \n" RESET);
				

			}
			|RETURN expr SEMI_COLON		
			{

				calculate_expr(ret, $2, true_expression);
				printf(BLUE "return expr ; \n" RESET);
			}
			;					


%%

int yyerror (char* yaccProvideedMessage) 
{
	 
	fprintf(stderr, RED "%s: at line %d, before token: %s\n" RESET, yaccProvideedMessage, yylineno, yytext);
	fprintf(stderr, RED "Input Not Valid\n" RESET); 
	exit(0); 
	return -1;

}
int yywrap(){
	return 1;
}
 
int main(int argc, char** argv) {


	f = fopen("quad.txt", "a");
    vector_init(&tableelem);

	/* init quad array gia ta if */
	quad_struct_init(&quad_table);
	 
	/*backpatching stack */
	quad_struct_init(&backpatching_table_if); 
	quad_struct_init(&backpatching_index_if);

	quad_struct_init(&backpatching_table_while); 
	quad_struct_init(&backpatching_index_while);

	quad_struct_init(&backpatching_table_while_end); 
	quad_struct_init(&backpatching_index_while_start);

	quad_struct_init(&backpatching_table_for); 
	quad_struct_init(&backpatching_index_for);

	quad_struct_init(&backpatching_table_for_end); 
	quad_struct_init(&backpatching_index_for_start);

	quad_struct_init(&backpatching_table_for_elist); 
	quad_struct_init(&backpatching_index_for_elist);

	quad_struct_init(&backpatching_break_start_while);
	quad_struct_init(&backpatching_break_end_while);
	
	quad_struct_init(&backpatching_break_start_for);
	quad_struct_init(&backpatching_break_end_for);


	quad_struct_init(&backpatching_continue_start_while);
	quad_struct_init(&backpatching_continue_end_while);
	
	quad_struct_init(&backpatching_continue_start_for);
	quad_struct_init(&backpatching_continue_end_for);


	quad_struct_init(&backpatching_table_else);
	quad_struct_init(&backpatching_index_else);
	quad_struct_init(&sinolika_loops);


	for_quad = calloc(sizeof(struct quad), sizeof(struct quad));
	while_quad = calloc(sizeof(struct quad), sizeof(struct quad));
	
	/* scope_space */
	scope_head = calloc(sizeof(struct scope_space_list), sizeof(struct scope_space_list));
	scope_head->scope_space_type = programVal;

	/* end of scope space */
	

	last_param_created = calloc(sizeof(struct expr), sizeof(struct expr));
	/* prepei na faei delete isws dioti de to kanoume tipota pleon */
	last_expr_created = calloc(sizeof(struct expr), sizeof(struct expr));
	true_expression = calloc(sizeof(struct expr), sizeof(struct expr));
	true_expression->boolConst = 1;
	true_expression->type = constbool_e;
	dimitris = calloc(sizeof(struct expr), sizeof(struct expr));
	dimitris1 = calloc(sizeof(struct expr), sizeof(struct expr));


	false_expression = calloc(sizeof(struct expr), sizeof(struct expr));
	false_expression->boolConst = 0;
	false_expression->type = constbool_e;

	functions_created_list = calloc(sizeof(struct functions_created), sizeof(struct functions_created));

	ylval = calloc(sizeof(struct alpha_token_t), sizeof(struct alpha_token_t));
	Symbol_Table = symtable_new(StartBucket);
	yyin = stdin;	
	yyparse();


	





	return 0;
}


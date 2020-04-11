#include "library.h"
int runtime_error = 0;
int quad_counter = 0;
int label = 0;
/* statame na grafoume sto quad logw loopas */
int stop_writing_quad_loop = 0;
int stop_writing_if_quad = 0;
/* metavliti gia na grafoume sto quad arxeio */
/* an ginei logical praksi de xreiazetai na grapsoume  */
/* px or and, ara to kanoume deactivate, kai sto telos */
/* tou function to energopoioume */
int write_quad = 1;
void write_label_offset(FILE* f){
    fprintf(f, "%d: ", label);  
}

void write_jump_quad(int label, FILE* f){
    fprintf(f, "JUMP %d\n", label);
}

void print_text(expr my_expr, FILE *f){
    
/* to my_expr tha einai null otan de xreiazetai  */
/* na tipwsoume alla args opws  jump, uminus ktl */  
    if(my_expr == NULL){
        return;
    }
    if(my_expr->type == constdouble_e)
        fprintf(f, "%f", my_expr->const_double);
    else if(my_expr->type == constint_e)
        fprintf(f, "%d", my_expr->const_int);
    else if(my_expr->type == constbool_e)
        if(my_expr->boolConst == 1)
            fprintf(f, "TRUE");
        else 
            fprintf(f, "FALSE");
        
    else if (my_expr->type == var_e){
        
        if(my_expr->sym != NULL)
            fprintf(f, "%s", my_expr->sym->value.varVal->name);
        else 
            fprintf(f, "%s", my_expr->strConst);
    }else if (my_expr->type == programfunc_e){
        if(my_expr->strConst != NULL)
            fprintf(f, "%s", my_expr->strConst);
        else
            fprintf(f, "%s", my_expr->sym->value.funcVal->name);
    }else if(my_expr->type == conststring_e){
        fprintf(f, "%s", my_expr->strConst);
    }


}

char* print_text2(expr my_expr){
    char* string;

    if(my_expr == NULL){
        return NULL;
    }
    if(my_expr->type == constdouble_e) {
        string = (char*) malloc(sizeof(size_t));
        snprintf(string, sizeof(size_t), "%f", my_expr->const_double);

    }
    else if(my_expr->type == constint_e) {
        string = (char*) malloc(sizeof(size_t));
        snprintf(string, sizeof(size_t), "%d", my_expr->const_int);
    }
    else if(my_expr->type == constbool_e) {
        if(my_expr->boolConst == 1) {
            string = (char*) malloc(strlen("TRUE"));
            strcpy(string, "TRUE");
        }else { 
            string = (char*) malloc(strlen("FALSE"));
            strcpy(string, "FALSE");
        }
    }    
    else if (my_expr->type == conststring_e){
        string = strdup(my_expr->strConst);
        strcpy(string, my_expr->strConst);
    }else if (my_expr->type == var_e){
        printf("%p\n", my_expr->sym->value.varVal->name);
        string = strdup(my_expr->sym->value.varVal->name);
        //strcpy(string, my_expr->strConst);
    }else if(my_expr->type == tableitem_e)
        return my_expr->strConst;

    return string;
}

int is_expression_true(expr my_expr){
     switch(my_expr->type){
        case var_e:
            break;
        case tableitem_e:
            break;
	    case programfunc_e:
            return 1;
            break;
	    case libraryfunc_e:
            return 1;
            break;
	    case arithexpr_e:
            break;
	    case boolexpr_e:
            break;
	    case assignexpr_e:
            break;
	    case newtable_e:
            break;
	    case constint_e:
        
            return my_expr->const_int != 0;
            //redirect_output_int(my_expression->const_int);
            break;
	    case constdouble_e:
            //redirect_output_int(my_expression->const_double);
            return my_expr->const_double != 0;
            break;
	    case constbool_e:            
            return my_expr->boolConst != 0;

            break;
    	case conststring_e:
            return my_expr->strConst != NULL;
            break;
	    case nil_e:
            printf("Nil");
            return 0;
            break;
        default:
            printf("Oops\n");
           
    }
    return 0;


}
/* kanei to true false kai toumpalin */
int reverse_result(int expr){
    if(expr == 1)
        return 0;
    return 1;
}

void write_quad_to_file(char* op, char* _tmp,  expr arg1, expr arg2, FILE* f){
    if(is_objectdef){
        char *string = (char*) malloc(strlen(op) + strlen(_tmp) + 2 + sizeof(struct expr) + sizeof(struct expr));

        strcat(string, op);
        strcat(string, "\t\t");
        if(_tmp != NULL){
            strcat(string, _tmp);
            strcat(string, "\t");
        } 
        strcat(string, print_text2(arg1));

        if(strcmp(op, "UMINUS") != 0 && strcmp(op, "NOT") != 0)
           strcat(string, ", ");

        if(arg2->strConst != NULL){
           strcat(string, arg2->strConst);
           strcat(string, " ");
        }else{
           strcat(string, print_text2(arg2));
        }
        strcat(string, "\n");
        vector_set(&tableelem, tableelem.size, string);
    }else{
        write_label_offset(f);
        fprintf(f, "%s ", op);
        if(_tmp != NULL){
            fprintf(f, "%s ", _tmp);
        } 

        print_text(arg1, f);

        if(strcmp(op, "UMINUS") != 0 && strcmp(op, "NOT") != 0){
            fprintf(f, ", ");

           
        if(arg2->strConst != NULL){
            fprintf(f, "%s ", arg2->strConst);
        }else{
            print_text(arg2, f);
        }
        
      }
    
    }
    fprintf(f, "\n");
}





void write_func_quad(char* op, char* func_name, FILE* f){
     
    fprintf(f, "%s ", op);
    fprintf(f, "%s\n", func_name);
   
}

void write_tablecreate_quad1(char* op, char* func_name,int i) {
     char *string = (char*) malloc(strlen(op) + strlen(func_name) + 20);
     
     strcat(string, op);
     strcat(string, "\t");

     strcat(string, func_name);
     strcat(string, "\n");

     vector_set(&tableelem, tableelem.size, string);
 }


void write_tablesetelem_quad1(char* op, expr func_name,expr c, expr e) {
    fprintf(f, "%s\t", op);
    fprintf(f, "%s\t", print_text2(func_name));
    fprintf(f, "%s\t", print_text2(c));
    fprintf(f, "%s\t\n", print_text2(e));
 }

void write_tablesetelem_index_quad1(char* op, char* func_name,expr c, expr e) {
    char *string = (char*) malloc(strlen(op) + strlen(func_name) + 2 + sizeof(size_t) + sizeof(size_t) );
    
    strcat(string, op);
    strcat(string, "\t");
    
    strcat(string, print_text2(e));
    strcat(string, "\n");

    strcat(string, func_name);
    strcat(string, "\t");
    
    strcat(string, print_text2(c));
    strcat(string, "\t");
     
    
    
    vector_set(&tableelem, tableelem.size, string);
}

void write_tablecreate_quad(char* op, char* func_name,int i) {

       fprintf(f, "%s\t", op);
       fprintf(f, "%s\n", func_name);    
 }

void write_tablesetelem_quad(char* op, char* func_name,int i, expr e) {

      fprintf(f, "%s\t", op);
      print_text(e,f);
      fprintf(f, "%s\t%d\t", func_name,i);
      fprintf(f, "\n");


 }

void write_tablesetelem_index_quad(char* op, char* func_name,expr c, expr e) {

    fprintf(f, "%s\t", op);
    print_text(e,f);
    fprintf(f, "\t%s\t", func_name);
    print_text(c,f);
    fprintf(f, "\n");
}

void write_tablegetelem_quad(char* op, char* func_name,expr c, expr e) {
    fprintf(f, "%s\t", op);
    print_text(e,f);
    fprintf(f, "\t%s\t", func_name);
    print_text(c,f);
    fprintf(f, "\n");

}

void write_param_quad_to_file(char* op, expr arg1, FILE* f){
    if(!arg1){
  
        return;
    }
    fprintf(f, "%s ", op);

    if(arg1->type == conststring_e)
        fprintf(f, "\"%s\"", arg1->strConst);
    else if(arg1->strConst != NULL){
        printf("tmp %p\n", arg1);
        fprintf(f, "%s", arg1->strConst);
    }
    else
        print_text(arg1, f);
    fprintf(f, "\n");
     
    
}

void write_assign_quad_to_file(char* op, char* _tmp, expr arg1, FILE* f) {
    
    fprintf(f, "%s ", op);
    fprintf(f, "%s , ", _tmp);
    print_text(arg1, f); 
    fprintf(f, "\n");
    
}

void insert_last_index_if( ){
    quad q = calloc(sizeof(struct quad), sizeof(struct quad));
    q->label = quad_counter ;
    //printf(RED"THA KANW JUMP :%d\n"RESET, quad_counter);
    quad_struct_set(&backpatching_index_if, backpatching_index_if.size, q); 
    index2++;
}


void insert_last_jump_if(){
    //printf(RED"PROSTHETW LAST JUMP \n"RESET);
    quad_struct_set(&backpatching_table_if, backpatching_table_if.size, last_quad_created); 
    index1++;
}

void insert_last_index_else(){
    quad q = calloc(sizeof(struct quad), sizeof(struct quad));
    q->label = quad_counter ;
    //printf(RED"THA KANW JUMP ELSE:%d\n"RESET, quad_counter);
    quad_struct_set(&backpatching_index_else, backpatching_index_else.size, q); 

}

void insert_last_jump_else(){
    //printf(RED"PROSTHETW LAST JUMP ELSE\n"RESET);
    quad_struct_set(&backpatching_table_else, backpatching_table_else.size, last_quad_created); 

}





void insert_last_index_while(){
    quad q = calloc(sizeof(struct quad), sizeof(struct quad));
    q->label = quad_counter ;
    quad_struct_set(&backpatching_index_while, index3, q); 
    index3++;
}


void insert_last_jump_while(){
    quad_struct_set(&backpatching_table_while, index4, last_quad_created); 
    index4++;
}


void insert_last_index_while_start(){
    quad q = calloc(sizeof(struct quad), sizeof(struct quad));
    q->label = quad_counter;
    quad_struct_set(&backpatching_index_while_start, index5, q); 
    index5++;
}


void insert_last_jump_while_end(){
    quad_struct_set(&backpatching_table_while_end, index6, last_quad_created); 
    index6++;
}

void insert_last_index_for(){
    quad q = calloc(sizeof(struct quad), sizeof(struct quad));
    q->label = quad_counter;
    
    quad_struct_set(&backpatching_index_for, backpatching_index_for.size, q); 
   
}

void insert_last_jump_for(){

    quad_struct_set(&backpatching_table_for, backpatching_table_for.size, last_quad_created); 
    
}

void insert_last_index_for_start(){
    quad q = calloc(sizeof(struct quad), sizeof(struct quad));
    q->label = quad_counter;
    quad_struct_set(&backpatching_index_for_start, index9, q); 
    index9++;
}

void insert_last_jump_for_end(){

    quad_struct_set(&backpatching_table_for_end, index10, last_quad_created); 
    index10++;
}

void insert_last_index_for_elist(){
    quad q = calloc(sizeof(struct quad), sizeof(struct quad));
    q->label = quad_counter;
    quad_struct_set(&backpatching_index_for_elist, index11, q); 
    index11++;
}

void insert_last_jump_for_elist(){
    //printf(RED"EDW TELIWNEI TO for \n"RESET);

    quad_struct_set(&backpatching_table_for_elist, index12, last_quad_created); 
    index12++;
}


void insert_break_index_while(){
    int i, found;
    int extra_data;
    quad q = calloc(sizeof(struct quad), sizeof(struct quad));
    q->label = quad_counter ;
    q->extra_data = while_counter;
    for(i = 0; i < backpatching_break_end_while.size -1; i++){
        extra_data = quad_struct_get(&backpatching_break_end_while, i)->extra_data;
        if(extra_data == while_counter ){
            found = 1;
            break;
        }
    }
    if(found == 0)
        return;   
    quad_struct_set(&backpatching_break_start_while, backpatching_break_start_while.size, q); 
    break7++;
}
void insert_break_jump_while(){
    last_quad_created->extra_data = while_counter;
    quad_struct_set(&backpatching_break_end_while, break8, last_quad_created); 

    break8++;
}





void insert_break_index_for(){
    int i, found;
    int extra_data;
    quad q = calloc(sizeof(struct quad), sizeof(struct quad));
    q->label = quad_counter ;
    q->extra_data = for_counter;
    for(i = 0; i < backpatching_break_end_for.size -1; i++){
        extra_data = quad_struct_get(&backpatching_break_end_for, i)->extra_data;
        if(extra_data == for_counter ){
            found = 1;
            break;
        }
    }
    if(found == 0)
        return;   
    quad_struct_set(&backpatching_break_start_for, backpatching_break_start_for.size, q); 
    
}
void insert_break_jump_for(){
    last_quad_created->extra_data = for_counter;
    quad_struct_set(&backpatching_break_end_for, backpatching_break_end_for.size, last_quad_created); 

  
}




/* ilopoihsh gia continue */



void insert_continue_index_while(){
    int i, found;
    int extra_data;
    quad q = calloc(sizeof(struct quad), sizeof(struct quad));
    q->label = quad_counter ;
    q->extra_data = while_counter;
    //printf("THA KANW JUMP EDW :%d\n", quad_counter);
  
    quad_struct_set(&backpatching_continue_start_while, backpatching_continue_start_while.size, q); 

}
void insert_continue_jump_while(){
    
    last_quad_created->extra_data = while_counter;
    //printf("THA KANW INCOMPLETE JUMP EDW :%d\n", quad_counter);
    quad_struct_set(&backpatching_continue_end_while, backpatching_continue_end_while.size, last_quad_created); 

}





void insert_continue_index_for(){
   int i, found;
    int extra_data;
    quad q = calloc(sizeof(struct quad), sizeof(struct quad));
    q->label = quad_counter ;
    q->extra_data_for = for_counter;
    //printf("THA KANW JUMP EDW :%d\n", quad_counter);
  
    quad_struct_set(&backpatching_continue_start_for, backpatching_continue_start_for.size, q); 
    
}
void insert_continue_jump_for(){
    last_quad_created->extra_data_for = for_counter;
    quad_struct_set(&backpatching_continue_end_for, backpatching_continue_end_for.size, last_quad_created); 

  
}

void write_if_eq_op_quad_to_file(quad q, FILE* f){

    fprintf(f, "%s ",  opcode_types[if_eq]);

    if(q->arg1->strConst != NULL)
        fprintf(f, "%s", q->arg1->strConst);
    else
        print_text(q->arg1, f);
    fprintf(f, ", ");
    print_text(q->arg2, f);

    fprintf(f, ", %d", q->label + 1);
    //print_text(jump, f);
    fprintf(f, "\n");
}

void write_if_quad_to_file(quad q, FILE* f){
 

    fprintf(f, "%s ",  opcode_types[q->op]);
    
    // if(arg1->strConst != NULL){
    //     fprintf(f, "%s(", arg1->strConst);
    
    // print_text(arg1, f);
    // fprintf(f, ") ");
    // }else{
    //        print_text(arg1, f);
 
    // }
    
    if(q->arg1->strConst != NULL)
        fprintf(f, "%s", q->arg1->strConst);
    else
        print_text(q->arg1, f);
    fprintf(f, ", ");
    print_text(q->arg2, f);
    if(q->op == if_eq){
        
        fprintf(f, ", %d", q->label );
    }else 
        fprintf(f, ", %d", q->label + 1);
    //print_text(jump, f);


    fprintf(f, "\n");
    
 
}


void write_call_quad(expr arg1, FILE* f)
{
    if(arg1->sym == NULL){
        if (conflict_with_system_function(arg1->strConst) == 0){
            fprintf(f, "CALL %s\n", arg1->strConst);
        }else{
            
            fprintf(f, "CALL \"%s\"\n", arg1->strConst);
        }
        printf(RED"CALL -> sym is NULL \n"RESET);
    }else
         if (conflict_with_system_function(arg1->sym->value.funcVal->name) == 0){
            fprintf(f, "CALL %s\n", arg1->sym->value.funcVal->name);
        }else{
            
            fprintf(f, "CALL \"%s\"\n", arg1->sym->value.funcVal->name);
        }
}







void write_quad_general(quad q){
    /* efoson exoume diavasei ifstmt, prepei na mi tipwsoume                 */
    /* kanena quad(dimiourgountai kanonika sto table) kai na perimenoume     */
    /* mexri na teliwsei to ifstmt gia na kanoume to print kai reset tou var */
    if(stop_writing_quad_loop == 1)
        return;

    if(runtime_error == 1)
        return;
    q->written = true;

    /* elegxw tous 2 prwtous xaraktires an einai if */

    //printf(RED"Type %s\n"RESET, opcode_types[q->op]);
    if(q->op == if_eq_op){
        printf("LALALALA\n");
        write_label_offset(f);
        write_if_eq_op_quad_to_file(q, f);
    }else if(strncmp(opcode_types[q->op], "IF", 2) == 0){
        write_label_offset(f);
        write_if_quad_to_file(q, f);
    }else if (q->op == param){
        write_label_offset(f);
        write_param_quad_to_file("PARAM", q->arg1, f);
    }else if (q->op == funcstart){
        write_label_offset(f);
        write_func_quad("FUNCSTART", q->arg1->strConst, f);
    }else if(q->op == funcend){
        write_label_offset(f);
        write_func_quad("FUNCEND", q->arg1->strConst, f);
    }else if(q->op == assign){
        write_label_offset(f);
        write_assign_quad_to_file("ASSIGN", q->arg1->sym->value.varVal->name, q->arg2, f);
    }else if(q->op == jump){
        write_label_offset(f);
        write_jump_quad(q->label, f);
    }else if (q->op == call){
        write_label_offset(f);
        write_call_quad(q->arg1, f);
    }else if (q->op == getretval){
        write_label_offset(f);
        fprintf(f , "GETRETVAL %s\n", q->result->strConst);
    }else if (q->op == tablecreate) {
        write_label_offset(f);
        write_tablecreate_quad("TABLECREATE", q->arg1->strConst, q->arg2->const_int); //table create
    }else if (q->op == tablesetelem) {
        write_label_offset(f);         
        write_tablesetelem_index_quad("TABLESETELEM", q->arg1->strConst,q->arg2, q->result); //table setelem
    }else if (q->op == tablesetelemindex) {
        write_label_offset(f);
        write_tablesetelem_index_quad("TABLESETELEM", q->arg1->strConst,q->arg2, q->result);
    }else if (q->op == tablecreate1) {
        write_tablecreate_quad1("TABLECREATE", q->arg1->strConst, q->arg2->const_int); //table create
    }else if (q->op == tablesetelem1) {
        write_label_offset(f);
        write_tablesetelem_quad1("TABLESETELEM", q->arg1, q->arg2, q->result); //table setelem
    }else if (q->op == tablesetelemindex1) {
        write_tablesetelem_index_quad1("TABLESETELEM", q->arg1->strConst,q->arg2, q->result);
    }else if (q->op == tablegetelem) {
        write_label_offset(f);
        write_tablegetelem_quad("TABLEGETELEM", q->arg1->strConst, q->arg2, q->result); //table setelem
    }else if (q->op == ret){
        write_label_offset(f);
        fprintf(f, "RETURN ");
        print_text(q->arg1, f);
        fprintf(f, "\n");
    }else{
        write_quad_to_file(opcode_types[q->op], q->result->strConst, q->arg1, q->arg2 , f);
    }

    label++;
    
}



/* elegxei ena expr an einai number */
int is_const_num(expr arg){
    if(arg->type == constint_e || arg->type == constdouble_e)
        return 1;
    else
        return 0;

}



double get_expr_value(expr arg){
    if(arg->type == constdouble_e){
        return arg->const_double;
    }
    return arg->const_int;
}


int equal_expression(expr arg1, expr arg2){
    if(arg1 == NULL || arg2 == NULL)
        return 0;
    if(arg1->type != arg2->type)
        return 0;
    if(arg1->type == constbool_e)
        if(arg1->boolConst == arg2->boolConst)
            return 1;
    if(arg1->type == conststring_e)
        if(strcmp(arg1->strConst, arg2->strConst) == 0)
            return 1;
    if(arg1->type == constint_e)
        if(arg1->const_int == arg2->const_int){
            return 1;
    }
    if(arg1->type == constdouble_e)
        if(arg1->const_double == arg2->const_double)
            return 1;
    
    return 0;
}

short get_result_num_type(expr arg1, expr arg2){
    
    /* ena apo ta 2 na einai double, to result tha einai double */
    if(arg1->type == constdouble_e || arg2->type == constdouble_e){
        return constdouble_e;
    }
    return constint_e;
}



void print_expression_info(expr arg){
    if(arg == NULL){
        printf("NULL EXPRESSION\n");
    }else{
        printf("Type :%s\n", expression_types[arg->type]);
        printf("ENTRY:%p\n", arg->sym);
        printf(RED"Index\n");
        print_expression_info(arg->index);
        printf(RESET);
        printf("Int :%d\n", arg->const_int);        
        printf("Double :%f\n", arg->const_double);
        printf("String :");
        if(arg->strConst == NULL){
            printf("NULL\n");
        }else{
            printf("%s\n", arg->strConst);
        }
        printf("Boolean :%d\n", arg->boolConst);
        printf(RED"Index\n");
        print_expression_info(arg->next);
        printf(RESET);
    }
}

void print_quad_info(quad _quad){
    if(_quad == NULL){
        printf("NULL QUAD\n");
    }else{
        printf("Opcode :%s\n", opcode_types[_quad->op]);
        printf("RESULT\n");
        print_expression_info(_quad->result);
        printf("ARG1\n");
        print_expression_info(_quad->arg1);
        printf("ARG2\n");
        print_expression_info(_quad->arg2);
        printf("Label :%u\n", _quad->label);
        printf("Line :%u\n", _quad->line);
    }
}






void print_quad_op(int op){
	printf("Quad op:%s\n", opcode_types[op]);
}




expr create_quad(int op, expr arg1, expr arg2, expr result) {
    quad tmp_quad = (quad) calloc(sizeof(struct quad), sizeof(struct quad));
    tmp_quad->arg1 = arg1;
    tmp_quad->arg2 = arg2;
    tmp_quad->result = (expr) calloc(sizeof(struct expr), sizeof(struct expr));
    memcpy(tmp_quad->result, result, sizeof(struct expr));
    tmp_quad -> op = op;
    tmp_quad -> line = yylineno;
    tmp_quad -> label = quad_counter + 2;
   
    /* xrisi gia memcmp */
    memcpy(tmp_quad->arg1, arg1, sizeof(struct expr));
    /* se merikes periptwseis to arg2 to stelnoume null epitides */
    /* opws sto if(term) gia logous simvatotitas */
    if(arg2)
        memcpy(tmp_quad->arg2, arg2, sizeof(struct expr));


    tmp_quad->result->op = op;
    //printf("TYPE :%d\n", arg1->type);
    
    if(op == 1 || op == 2 || (op >= 4 && op <= 8)){
       //valid_expression_arg(arg1, arg2);
    }




    switch(op){
        case 0:
            
            /*assign*/
            break;   
        case 1:
            /*Addition*/

           
            tmp_quad->result->type = var_e;
   

            break;   
        case 2:
            /*Substraction*/
           
            tmp_quad->result->type = var_e;



            break;   
        case 3:
            /* null */
           
            break;   
        case 4:
            /*multiplication*/
            
            tmp_quad->result->type = var_e;
         

            
            
            break;
        case 5:
            /*division */
           
            tmp_quad->result->type = var_e;


            break;   
        case 6:
            /* modulo */
            
            tmp_quad->result->type = var_e;


            break;   
        case 7:
            /*Uminus*/
            
            tmp_quad->result->type = var_e;


            break;   
        case 8:
            /*AND*/
            
           

            break;   
        case 9:
            /*OR*/
           
          
            break;      
        case 10:
            /*not*/
        
          
            break;   
        case 11:
            /*if_equal*/
           
            break;
        case 12:
            /*if_not_equal*/
          
            break;   
        case 13:
            /*if_less_equal*/
         
            break;
        case 14:
            /*if_greater_equal*/
          
           
            break;
        case 15:
            /*if_less*/
          

            break;
        case 16:
            /*if_greater*/
        
            


            break;
        case 17:
            /*call*/
           
            break;
        case 18:
            /*param*/

            break;
        case 19:
            /*return*/
            break;
        case 20:
            /*get_return_value*/
            break;
        case 21:
            /*func_start*/

            //write_func_quad("FUNCSTART", arg1->strConst);
            break;
        case 22:
            /*func_end*/
            //write_func_quad("FUNCEND", arg1->strConst);
            break;
        case 23:
            /*table_create*/
            break;
        case 24:
            /*table_create_elem*/
            break;
        case 25:
            /*table_set_elem*/
            break;
        case 26:
            /*jump*/
            break;
        case 27: /*if_eq_op*/
            break;
        case 28: /*tablesetelemindex*/
            break;
        case 29: /*tablecreate1*/
            break;
        case 30: /*tablesetelem1*/
            break;
        case 31: /*tablesetelemindex1*/
            break;
        default:
            printf(RED "Loustike :%d"RESET, op );
            exit(-1);
    }
    /* an exw logikes prakseis, borw na xrisimopoihsw to result gia to if */
    if(op >= 10 && op <= 16 && op !=11){
        //memcpy(last_expr_created, tmp_quad->result, sizeof(struct expr));
    }else{
        tmp_quad->result->op = if_eq;

        /* alliws kanw ena pedio -1*/
        //hidden_tmp_var_counter = 0;
        //last_expr_created->active = -1;
    }
    if(write_quad == 1){
        quad_struct_set(&quad_table, quad_counter, tmp_quad); // gia na theseis timh
    

        // table_set(&instruction_array, instruction_counter, );
        quad_counter++;
  
        if(stop_writing_if_quad == 0 && runtime_error == 0) 
            write_quad_general(tmp_quad);
        //print_quad_info(tmp_quad);
    }

    write_quad = 1;
    if(op == jump){
        last_quad_created = tmp_quad;
    }
    return tmp_quad->result;
}

/* prints the type of an expression */
void expression_get_type(expr my_expression){
    printf("Expression Type:");
    switch(my_expression->type){
        case var_e:
            break;
        case tableitem_e:
            break;
	    case programfunc_e:
            break;
	    case libraryfunc_e:
            printf("%s\n", my_expression->strConst);
            break;
	    case arithexpr_e:
            break;
	    case boolexpr_e:
            break;
	    case assignexpr_e:
            break;
	    case newtable_e:
            break;
	    case constint_e:
        

            //redirect_output_int(my_expression->const_int);
            break;
	    case constdouble_e:
            //redirect_output_int(my_expression->const_double);
            break;
	    case constbool_e:
            if(my_expression->boolConst == 0){
                //redirect_output_str("TRUE");

            }else{
                //redirect_output_str("FALSE");
            }
            break;
    	case conststring_e:
            printf("String %s\n", my_expression->strConst);
            break;
	    case nil_e:
            printf("Nil");
            break;
        default:
            printf("Oops\n");
            exit(-1);
    }
}


quad get_last_loop(){
    if(sinolika_loops.size <0)
        return NULL;
    return quad_struct_get(&sinolika_loops, sinolika_loops.size -1);
}

void remove_last_loop(int loop){
    quad q = get_last_loop();
    if(q == NULL)
        return ;
    if(q == while_quad && loop == 0)
        sinolika_loops.size--;
    else if(q == for_quad && loop == 1)
        sinolika_loops.size--;

}






void insert_loop(int loop){
    /* while */
    if(loop == 0){
        quad_struct_set(&sinolika_loops, sinolika_loops.size, while_quad);
    }else{
        /* for */
        quad_struct_set(&sinolika_loops, sinolika_loops.size, for_quad);

    }

}


expr make_call(expr lvalue, expr elist){
 
    expr func = emit_iftableitem(lvalue);
    int c;
 
    expr tmp = elist;
    Dynamic_Table ex;
    table_init(&ex);
    while(tmp!=NULL){
    
        //create_quad(param, tmp, true_expression, true_expression);

        table_type p;
        p.ex = tmp;
        table_set(&ex, ex.size, p);
        tmp = tmp->next;
    }
    for(c = ex.size-1; c != -1; c--){
        expr e = table_get(&ex, c).ex;

        create_quad(param, e, true_expression, true_expression);

    }
    if(symbol_get_value_type(func->type)!=1){
        //runtime_error = 1;
    }
    create_quad(call, func, true_expression, true_expression);
 
    expr result = create_new_temp_var();
    result->type = var_e;
    create_quad(getretval, true_expression,true_expression, result);
    return result;

}
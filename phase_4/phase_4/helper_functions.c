
#include "library.h"
int is_float(char* arg1){
    int i = 0;
    while(arg1[i] != '\0'){
        if(arg1[i] == '.'){
            return 1;
        }
        i++;
    }
    return 0;
}


/*
void result(char** ss, char* arg1, int op, char* arg2){

    int size;
    float result;
    size = 4;
    if(is_float(arg1) == 1 || is_float(arg2))
        size = 8;
    
    switch(op){
        case 0:
            printf("ADD %s, %s\n", arg1, arg2);
            result = atof(arg1) + atof(arg2);
            break;   
        case 1:
            printf("SUB %s, %s\n", arg1, arg2);

            result = atof(arg1) - atof(arg2);
            break;   
        case 2:
            printf("MUL %s, %s\n", arg1, arg2);
            result = atof(arg1) * atof(arg2);
            break;   
        case 3:
            if (atof(arg2) == 0.0){
                printf(RED"SFALMA KATATMISIS\n"RESET);
                exit(-1);
            }
            printf("DIV %s, %s\n", arg1, arg2);

            result = atof(arg1) / atof(arg2);
            break;   
        case 4:
            if (atof(arg2) == 0.0){
                printf(RED"SFALMA KATATMISIS\n"RESET);
                exit(-1);
            }
            result = atoi(arg1) % atoi(arg2);
            break;   
        case 5:
            result = atof(arg1) > atof(arg2);
            break;   
        case 6:
            result = atof(arg1) < atof(arg2);
            break;   
        case 7:
            result = atof(arg1) >= atof(arg2);
            break;   
        case 8:
            result = atof(arg1) <= atof(arg2);
            break;   
        case 9:
            result = atof(arg1) == atof(arg2);
            break;   
        case 10:
            result = atof(arg1) != atof(arg2);
            break;
        case 11:
            result = atof(arg1) && atof(arg2);
            break;   
        case 12:
            result = atof(arg1) || atof(arg2);
            break;
        default:
            printf(RED "Loustike" RESET);
            break;
    }
   
    if(op >= 4 && op <= 9){
        size = 4;
    }
    *ss = malloc(size);
    if(size == 4){
        sprintf(*ss, "%d", (int)result);
    }else{
        sprintf(*ss, "%f", result);
    }
    printf("$$ = %s\n", *ss);
}
*/
/******************************************************************/
/* dimiourgia mia lista kai vazei ola ta argument mias sinartisis */
/******************************************************************/

/*********************************************/
/* tipwnei oles tis parametrous tou argument */
/*********************************************/
void print_all_arguments(struct argument_mias_sinartisis* head){
    struct argument_mias_sinartisis* p = head;
    //printf("**********************\n");
    //printf("Tipwnw ta arguments\n");
    while(p){
        printf("Argument:%s\n", p->name);
        p = p->next;
    }
    //printf("**********************\n");
}

/****************************************************************************/
/* elegxei an to onoma enos token kanei conflict me system library function */
/****************************************************************************/
int conflict_with_system_function(char* name){
    int count;
    for(count = 0;count < SYSTEM_FUNCTION_SIZE;count++){
        if(strcmp(name, system_functions[count]) == 0){
            //printf(RED "Error, symbol :%s is a System Function\n"RESET, name);
            return 1;
        }
    }
    return 0;
}

/* elegxoume ton tipo tou node,an einai function epistrefetai 1 alliws an einai variable 0 */
int symbol_get_value_type(int type){
    /* einai tipos function */
    if(type < 3 || type == 5){
        return false;
    }else{
        return true;
    }
}


/*********************************************/
/* elegxei an ta argument list einai valid   */
/* elegxei an exoun oristei idi ta simvola i */
/* ginetai conflict me lib functions         */
/*********************************************/
int function_arguments_valid(char* str, int scope){
			

		entry scope_node;
        /* psaxnw an iparxei to id sto idio scope */
        scope_node = Scope_List_Contains_Symbol(str, scope);
        if(scope_node && scope_node->isActive){
            printf(RED "Error, argument symbol :%s already Exists\n"RESET, str);
            return 0;
        }
        if(conflict_with_system_function(str) == 1){
            printf(RED "Error, argument symbol :%s collides with libfunc \n"RESET, str);
            return 0;
        }
        if(scope_node == NULL || (scope_node && scope_node->isActive == false))
            return 1;
        return 0; 
}
/***************************************************************************/
/* dest einai pointer sto string pou tha grapsoume to neo name kai kanoume allocate */
/* name_prefix eg _func, _tmp                                                       */
/* number_counter, arithmos instance, px 1, 2, 3                                    */
/************************************************************************************/
char* create_name_with_num(char* name_prefix, size_t number_counter){

    char* name = malloc(strlen(name_prefix) + sizeof(size_t));
    strcpy(name, name_prefix);

    sprintf(&name[strlen(name_prefix)], "%zu", number_counter);
    return name;
}
expr create_new_temp_var(){
    expr result = calloc(sizeof(struct expr), sizeof(struct expr));

    //result->strConst = ;
    char* s = strdup(create_name_with_num("_tmp", hidden_tmp_var_counter));
    result->strConst = strdup(s);
    //result->const_int = hidden_tmp_var_counter;
    //tmp_var->number = hidden_tmp_var_counter;
    result->type = var_e;
    if (scope == GLOBAL_T){
        SymTable_put(Symbol_Table, s, yylineno, scope, assign_counter, GLOBAL_T);
    }else{
        SymTable_put(Symbol_Table, s, yylineno, scope, assign_counter, LOCAL_T);
    }
    hidden_tmp_var_counter++;
    result->sym = Scope_List_Contains_Symbol(s, scope);
 

    return result;

}
expr calculate_expr(int op, expr arg1, expr arg2){
    /* stin periptwsi auti pou exoume return, de theloume na auksithoun ta locals */

    if(op == ret){
       dont_increase_locals = 1;
    }
    expr result = create_new_temp_var();
    if(op == ret){
        dont_increase_locals = 0;
    }
    /* grafw to entry p molis dimiourgisa sto result gia na sindesw tmp me expr */
    //result->sym = Scope_List_Contains_Symbol(result->strConst, scope);
    
    return create_quad(op, arg1, arg2, result);
}






scope_space_list get_last_node(){
    scope_space_list p;
    p = scope_head;

    while(p->next != NULL){
       
        p = p->next;
    }
    return p;

}

void enter_scope_space(int scope_space){
    printf(RED"MPAINW SE SE :%d\n"RESET, scope_space);
    scope_space_list next = calloc(sizeof(struct scope_space_list), sizeof(struct scope_space_list));
    scope_space_list last;
    next->scope_space_type = scope_space;
    //next->offset = scope_offset;
    scope_space_list tmp;
    tmp = scope_head;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    last = get_last_node();
    last->offset = scope_offset;
    tmp->next = next;
    scope_offset = 0;
    space_scope = scope_space;

}
void remove_last_scope_space(){
   

    scope_space_list p, q;
    p = scope_head;
    q = p;
    while(p->next != NULL){
        q = p;
        p = p->next;
    }
    scope_offset = q->offset;
    space_scope = q->scope_space_type;
    q->next = NULL;
}

void function_list_insert(entry func){
    functions_created f, q;
    f = functions_created_list;
    q = calloc(sizeof(struct functions_created), sizeof(struct functions_created));
    q->func = func;
    while(f->next != NULL){
        f = f->next;
    }
    f->next = q;
    last_function_created = func;
}   
void function_list_remove_last(){
    functions_created f, q;
    f = functions_created_list;
    q = f;
    while(f->next != NULL){
        q = f;
        f = f->next;
    }
    last_function_created = q->func;
    q->next = NULL;

}

/**
* expr ---> struct expr*
*@expr_t struct
*@return pointer to an expr struct
*/
expr newexpr(expr_t t) {
    expr e = (expr) malloc(sizeof(struct expr));
    memset(e, 0, sizeof(struct expr));
    e->type = t;
    return e;
}


expr newexpr_conststring(char* s) {
    expr e = newexpr(conststring_e);
    e->strConst = strdup(s);
    return e;
}


expr newexpr_constnum(double d) {
    expr e = newexpr(constdouble_e);
    e->const_double = d;
    return e;
}
expr newexpr_constint(int d) {
    expr e = newexpr(constint_e);
    e->const_int= d;
    return e;
}
expr member_item(expr e, char* name) {
    
    e = emit_iftableitem(e);
    expr ee = newexpr(tableitem_e);
    ee->sym = e->sym;
    ee->index = newexpr_conststring(name);
    //ee->strConst = strdup(e->strConst);

    return ee;
    
}

expr emit_iftableitem(expr e) {
    // /printf(YELLOW "%s\n" RESET, e->strConst);
    if(e->type != tableitem_e){
        return e;
    }
    else {
        expr result = create_new_temp_var();
        /* grafw to entry p molis dimiourgisa sto result gia na sindesw tmp me expr */
        //result->sym = Scope_List_Contains_Symbol(result->strConst, scope);
        result->type = var_e;
        
        // printf("%s\n",result->sym->value.varVal->name);
        // printf("index :%s\n", e->index->strConst);
        // printf("result :%s\n", result->strConst);
      //  printf("e->index->strConst :%s\n", e->index->strConst);

        create_quad(tablegetelem,e, e->index,result); 

        return result;
    }
}
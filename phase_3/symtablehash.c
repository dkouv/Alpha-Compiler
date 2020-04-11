/*
 * hashFunct.c
 *
 *  Created on: Mar 28, 2016
 *      Author: nubie
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "library.h"
#define HASH_MULTIPLIER 65599

/********************************************************************************************************/
struct SymTable {
	unsigned int size;
	struct SymbolTableEntry *hash[StartBucket];
};
/*********************************************/
/* sinartisi pou kanei hash vasi enos string */ 
/*********************************************/
unsigned int symtable_hash(char *pv_value, int size) {
	size_t ui;
	unsigned int uiHash = 0U;
	for (ui = 0U; pv_value[ui] != '\0'; ui++)
		uiHash = uiHash + pv_value[ui];
		/* HASH_MULTIPLIER + pv_value[ui];*/
	return uiHash % size;
}

/******************************************************************************************************/
/* epistrefei to teleutaio node se ena scope an iparxei alliws epistrefei NULL an to scope einai adio */
/******************************************************************************************************/
entry Last_Node_In_Scope(struct Scope_List* head){
	
	entry curr = head->next_same_scope;
	if (!curr){
		return NULL;
	}
	/* vriskw teleutaio stoixeio p den einai NULL */
	while(curr->next_same_scope){
		curr = curr->next_same_scope;
	}
	return curr;
}

/*************************************************************************/
/* psaxnei na dei an iparxei to sigkekrimeno scope_list me auto to scope */
/* an nai, to epistrefei alliws to dimiourgei kai to epistrefei          */
/*************************************************************************/
struct Scope_List* Search_Scope_Node(int scope){
	struct Scope_List* curr_node, *prev_node;
	prev_node = Scope_List_Head;
	curr_node = Scope_List_Head;
	while(curr_node){
		if(curr_node->scope == scope){
		/* found our scope_node, return */
			return curr_node;
		}
		prev_node = curr_node;
		curr_node = curr_node->next_scope;
	}
	/* de vrika to scope, allocate it and return */
	struct Scope_List* new_scope = calloc(sizeof(struct Scope_List), sizeof(struct Scope_List));
	new_scope->scope = scope;
	if(prev_node == NULL){
		/* to head einai NULL */
		Scope_List_Head = new_scope;
	}else{
		prev_node->next_scope = new_scope;
	}
	return new_scope;
}
/*******************************************************/
/* arxikopoioume to Symbol_Table kai to collision list */
/*******************************************************/
SymTable_T symtable_new(int size) {
	size_t i;
	SymTable_T oSymTable = calloc(sizeof(struct SymTable), sizeof(struct SymTable));
	if (oSymTable==NULL) 
		return NULL;
	for (i = 0U; i < size; i++) {
		collision_list[i] = NULL;
		oSymTable->hash[i] = NULL;
	}
	oSymTable->size = size;
	return oSymTable;
}


/****************************************************/
/* elegxw an ena entry iparxei se ena scope         */
/* an to vrei to epistrefei alliws epistrefei null  */
/****************************************************/
entry Scope_List_Contains_Symbol(char *pv_value, int scope) {
	if(pv_value == NULL)
		return NULL;
	struct Scope_List* head = Scope_List_Head;
	/* vriskoume to sigkekrimeno scope pou pasxnoume */ 
	while(head && head->scope != scope){
		head = head->next_scope;
	}
	/* vrikame to head tou scope */
	/*ksekiname search se auto to scope_list tou head poy vrikame molis*/

	 if(!head)
		return NULL;

	entry node = head->next_same_scope;
 
	
	while(node){
						

		/**************************************************************************/
		/* epeidi o monos tropos gia search einai vasi tou name, elegxw to pedio  */
		/* variable kai function antistoixa kai an kanoun match epistrefw to node */
		/**************************************************************************/
		if(symbol_get_value_type(node->type ) == 1){
			
			if(strcmp(node->value.funcVal->name, pv_value) == 0){
				
				return node;
			}
		}else{

			if(strcmp(node->value.varVal->name, pv_value) == 0){			
				return node;
			}
		}		
		node = node->next_same_scope;
	}

	return NULL;
}











/***************************************************************/
/* elegxei an iparxei ena simvolo se ola ta scope, ksekinontas */
/* apo to trexon pros to 0(eksw pros ta mesa)                  */
/***************************************************************/
entry look_up(char *pv_value, int scope){
	int scope_count = scope;
	struct Scope_List* curr_scope;
	curr_scope = Search_Scope_Node(scope);
	curr_scope->scope = scope;
	entry found_scope_list_entry;
	/* psaxnoume na doume an iparxei to antikeimeno se ola ta scopes */
	for(;scope_count != - 1; scope_count--){
		
		found_scope_list_entry = Scope_List_Contains_Symbol(pv_value, scope_count);
		
		if(found_scope_list_entry){
		
			return found_scope_list_entry;
		}
	}
	return NULL;
}

int SymTable_put(SymTable_T oSymTable,  char *pv_value, int line, int scope, int assign_counter, int symbol_table_type) {

	// if(eimai_se_function != 0){
	// 	symbol_table_type = 5;

	// }
	entry node, head, last_node_in_scope;
	/* ti xrisimopoioume gia na kanoume traverse se ola ta scopes gia tin euresi enos simvolou */	
	struct Scope_List* curr_scope;
	unsigned int index = symtable_hash(pv_value, oSymTable->size);
	/***********************************************************************/
	/* anazitisi sto scope list, an iparxei to antikeimeno, return to node */
	/* alliws dimiourgia tou kai return 								   */
	/***********************************************************************/
	curr_scope = Search_Scope_Node(scope);
	curr_scope->scope = scope;
	/*******************************************************************/
	/* afotou exoume vrei to struct_scope_ewode, kanoume full traversal */
	/*   mexri ton teleutaio !NULL combo 							   */
	/*******************************************************************/
	last_node_in_scope = Last_Node_In_Scope(curr_scope);
	/***********************************/
	/* arxikopoihsh tou neou stoixeiou */
	/***********************************/
	/* eimaste sto head*/
	node = calloc(sizeof(struct SymbolTableEntry), sizeof(struct SymbolTableEntry));
	node -> isActive = true;
	node->assign_counter = assign_counter;
	/* Variable Init */	
	Variable* variable = calloc(sizeof(struct Variable), sizeof(struct Variable));
	variable->name = strdup(pv_value);
	variable->scope = scope;
	variable->line = line;
	/* End of Variable Init */
	/* Function Init */
	Function* func = calloc(sizeof(struct Function), sizeof(struct Function));
	func->name = strdup(pv_value);
	func->scope = scope;
	func->line = line;
	/* End of Function Init */
	node->value.funcVal = NULL;
	node->value.varVal = NULL;
	node->scope_space = space_scope;
	node->scope_offset = scope_offset;
	/************************************************************************/
	/* elegxos tipou vasei tou enumaration 									*/
	/* ta enums antistoixizontai se integers opote boroume na anaferthoume  */
	/*  se auta me arithmous 0, 1, 2, 3, 4 gia kathe tipos symbolou         */
	/************************************************************************/
	switch(symbol_table_type) {
		case 0 :
			scope_offset++;
			node->value.varVal = variable;
    	  	break;  
		case 1 :
			scope_offset++;
			node->value.varVal = variable;
			break;  
		case 2 :
			scope_offset++;
			node->value.varVal = variable;
			break;
		case 3 :

			node->scope_offset = -1;
			node->value.funcVal = func;
			//last_function_created = node;
			function_list_insert(node);
			break;
		case 4 :
			node->scope_offset = -1;
			node->value.funcVal = func;
			
			function_list_insert(node);
			break;
		case 5 :
			scope_offset++;
			node->value.varVal = variable;
			break;
   		default :  
		   printf("Auto den eprepe na ginei\n");
	}

	if(space_scope == functionLocal){
		if(node->scope_offset != -1)
			last_function_created->value.funcVal->total_arguments++;
	}
	/* anathesi tou tipou tou simvolou */
	node -> type = symbol_table_type;
	/************************************************************************/
	/* An den iparxei kanena antikeimeno sto sigkekrimeno scope list		*/
	/* Tote kanoume to neo node head sti lista tou sigkekrimenou scope list */
	/************************************************************************/
	if(last_node_in_scope == NULL)
	{
		curr_scope -> next_same_scope = node;		
	}else {
		/* alliws an iparxoun idi antikeimena se auto to scope list,   */
		/* to vazoume meta to teleutaio stoixeio pou vrikame prin ligo */
		last_node_in_scope ->next_same_scope = node;
	}

	
	/*********************************************************************************/
	/* afou o komvos dimiourgithike, theloume na to prosthesoume sto collision list  */
	/* efoson to kathe neo node tha bainei panta sto telos tou hashmap, kai to       */
	/* collision list einai idio megethous me to symbol table, vriskontas to hash    */
	/* tou onomatos, vriskw index gia to collision list kai to vazw se auti ti thesi */
	/*********************************************************************************/
	collision_list[index] = node;
	print_entry_node_information(node);
	/********************** HASH_TABLE INSERTION ***************************/ 
	/* insert to hash_table */
	head = oSymTable->hash[index];
	/***************************************************/
	/* an to head einai null, tote kanoume to node     */
	/* mas to neo head sti sigkekrimeni thesi sto hash */
	/***************************************************/			
	if(!head){
		node ->next = NULL;
		oSymTable->hash[index] = node;
		return 1;
	}
	/* alliws diatrexoume oli ti lista mexri na ftasoume */
	/* sto teleutaio stoixeio tis kai kanoume insert     */
	while(head->next != NULL){
		head = head->next;
	}
	head->next= node;

	return 0;
}




/***************************/
/* tipwnei olo to hash map */
/***************************/
void print_hash_table(SymTable_T oSymTable) {
	int i=0;
	entry node;
	printf("Printing list!\n");
	for (; i<StartBucket; i++) {
	
		node = oSymTable->hash[i];
		if(node)
			printf("\n"); 
		while(node){
			print_entry_node_information(node);
			node = node->next;
		}
		
	}
	printf("\n");
}




/**************************************************/
/* tipwnei analitiki pliroforia enos node me tipo */
/*function i variable kai arguments               */
/**************************************************/
void print_entry_node_information(entry node){
	
	/*************************************/
	/* elegxos type, variable i function */
	/*************************************/
	if(symbol_get_value_type(node->type) == 1){
			Function* p = (Function*)node->value.funcVal; 
			printf("Function %s me scope :%d se grammi:%d me tipo :%s einai active:%d scope_space :%s offset %d total_args :%d\n", p->name, p->scope, p->line, variable_types[node->type], node->isActive,  scope_space_str[node->scope_space], node->scope_offset, p->total_arguments);
			print_all_arguments(p->args);
	}else {
		/* ara einai variable*/
		Variable* p = (Variable*)node->value.varVal;
		printf("Metavliti %s me scope :%d se grammi:%d me tipo :%s einai active:%d scope_space :%s offset %d\n", p->name, p->scope, p->line, variable_types[node->type], node->isActive, scope_space_str[node->scope_space], node->scope_offset);
	}
}
/*************************************/
/* tipwnei ola ta entries enos scope */
/* me full pliroforia 				 */
/*************************************/

void print_scope(int scope){
	printf("-------------------------------------\n");
	struct Scope_List* p = Search_Scope_Node(scope);
	printf("Printing Scope :%d\n", p->scope);
	entry l = p->next_same_scope;
	while(l){
		print_entry_node_information(l);
		l = l->next_same_scope;
	}
	printf("-------------------------------------\n");
}
/**********************************************/
/* printarei apo oles tis listes me ta scopes */
/**********************************************/
void print_all_scopes(){
	struct Scope_List* p = Scope_List_Head;
	while(p){
		print_scope(p->scope);
		p = p->next_scope;
	} 
}

/****************************************************************************/
/* krivei oles tis metavlites tou current scope gia na mi fame redefinition */
/* error se periptwsi p dilwthoun se allo block diaforetikou scope          */
/****************************************************************************/
void hide_variables_of_current_scope(int scope){
	/* vriskw ola ta nodes tou current scope */
	struct Scope_List* p = Search_Scope_Node(scope);
	entry tmp = p ->next_same_scope;
	//printf("HIDING\n");
	while(tmp){
		
		tmp->isActive = false;
		//print_entry_node_information(tmp);
		
		tmp = tmp->next_same_scope;
	}
	/* reset hidden_tmp_var_counter */
	//hidden_tmp_var_counter = 0;

	//	printf("HIDE END\n");
	return ;
}
/*******************************************************/
/* elegxw an iparxei ena function se ola ta scope list */
/*******************************************************/
entry get_function_entry(char* func_name, int scope){
	int scope_count = scope;
	struct Scope_List* curr_scope;
	entry found_scope_list_entry;

	curr_scope = Search_Scope_Node(scope);
	curr_scope->scope = scope;

	/* psaxnoume na doume an iparxei to antikeimeno se ola ta scopes */
	for(;scope_count != - 1; scope_count--){
		found_scope_list_entry = Scope_List_Contains_Symbol(func_name, scope_count);
		
		if(found_scope_list_entry && symbol_get_value_type(found_scope_list_entry->type) == 1){
		
			return found_scope_list_entry;
		}
	}
	return NULL;

}



// int SymTable_remove(SymTable_T oSymTable,  char *pv_value) {
// 	entry node, curr;
// 	unsigned int index = symtable_hash(pv_value, oSymTable->size);

// 	assert(oSymTable);
// 	assert(pv_value);
// 	node = SymTable_contains(oSymTable, pv_value);
// 	if (node) {
// 		if(oSymTable->hash[index] == node){
// 			oSymTable->hash[index] = oSymTable->hash[index]->next;
// 		}else {
// 			curr = oSymTable->hash[index];
// 			/* find the entry before the node */
// 			while(curr ->next != node){
// 				curr = curr->next;
// 			}
// 			/* remove the node and fix the linking */
// 			curr->next = node->next;
// 			/* free the node */
// 			free(node->pv_value);
// 			free(node);
// 	}
// 		return 1;
// 	} else {
// 		return 0;
// 	}
// }

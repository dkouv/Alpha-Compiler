#include "library.h"


char str[MAX_SIZE];
/* Prints the information of the token regarding its type */
char* category_print(alpha_token_t *head)
{
	int i=0;
	switch(head->category){
    	case ENUMERATED:
			strcpy(str, head->data);
			while(str[i]){
				str[i] = (toupper(str[i]));
				i++;
			}
      		return str;
		case P_CHARACTER:
			strcpy(str, head->data);
			while(str[i]){
				str[i] = (toupper(str[i]));
				i++;
			}
      		return str;
		default:
			return head->data;
	}
}

/* Print the type of the token */
char* type_print(alpha_token_t *head)
{
	switch(head->category){
    	case ENUMERATED:
			return "enumerated";
		case LEX_INTEGER:
			return "int";
		case LEX_REAL:
			return "real";
		default:
			return "char*";
	}
}


/* Traverse the linked list starting from head,
 * find the last element and print its fields
 */
void print_tail_token(alpha_token_t *head)
{
	while(head->next != NULL){
		head = head->next;
	}
	printf ("%d: #%d\t\t\"%s\"\t%s\t\"%s\"\n",head->line_number, head->token_number,
			head->data, head->keyword, category_print(head));
}

void print_tail_token_to_file(alpha_token_t *head)
{
	while(head->next != NULL){
		head = head->next;
	}
	fprintf(yyout, "%d: #%d\t\t\"%s\"\t%s\t\"%s\"\n",head->line_number, head->token_number,
			head->data, head->keyword, category_print(head));
}

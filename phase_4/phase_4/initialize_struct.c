#include "library.h"

int flag = 1;

/* Creates new alpha_token_t object, finds its typename (ENUMERATED, INTEGER, POINTER CHAR, REAL)
 * insert the token in the start if it is the first one (flag = 1) or insert it in the end
 * after we traverse the whole linked list ( flag = 0)
 * print the the newly added token
 */

void add_alpha_token(alpha_token_t *_head, int line_number, int token_number, char* data,
                char* keyword, char* type, int typename)
{
    alpha_token_t *node;
    node = (alpha_token_t *)calloc(sizeof(struct alpha_token_t), sizeof(struct alpha_token_t));
    if(node == NULL){
        perror("Malloc failed");
        exit(0);
    }

    node->data = strdup(data);
    node->keyword = strdup(keyword);
    node->punctuation = (char *)malloc(strlen(data + 1));
    //node->p_char_type = (char *)malloc(strlen(data + 1));
    if (node->data == NULL || node->keyword == NULL || node->punctuation == NULL ){
        perror("Malloc failed");
        exit(0);
    }

    node->line_number = line_number;
    node->token_number = token_number;
    node->category = typename;
    strcpy(node->data, data);
    strcpy(node->keyword, keyword);
    node->next = NULL;

    switch(typename){
        case ENUMERATED:
            node->enumerated_type = atoi(type);
            break;
        case LEX_INTEGER:
            node->int_type = atoi(type);
            break;
        case P_CHARACTER:
            node->p_char_type = strdup(type);
            break;
        case LEX_REAL:
            node->double_type = atof(type);
        default:
            break;
        }

    if(flag){
        *_head = *node;
        flag = 0;
    }else {
        alpha_token_t* temp = _head;
        while(temp ->next != NULL){
            temp = temp -> next;
        }
        temp -> next = node;
    }

    if(file){
        //print_tail_token_to_file(_head);
    }else {
        //print_tail_token(_head);
    }

    return;
}

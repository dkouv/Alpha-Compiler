#include "library.h"

int file = LEX_FALSE;
/*
int main (int argc, char* argv[])
{
    alpha_token_t *head = NULL;
  	head = (alpha_token_t *)malloc(sizeof(alpha_token_t));
    if(argc > 1){
        yyin = fopen(argv[1], "r");
        if(yyin == NULL){
            printf("Cannot open file\n");
            exit(EXIT_FAILURE);
        }
    }else {
        yyin = stdin;
    }

    if(argc == 3){
        yyout = fopen(argv[2], "w+");
        if(yyout == NULL){
            printf("Cannot open file\n");
            exit(EXIT_FAILURE);
        }
        file = TRUE;
    }

  	alpha_yylex(head);

    fclose(yyin);
    fclose(yyout);

	return 0;
}
*/

%{
//#define YY_DECL extern int alpha_yylex(void* ylval)

#include "library.h"
#include "assert.h"
#include "parser.h"

void comment(void* ylval);
void string(void* ylval);
void single_comment();
int token_count = 1;
extern alpha_token_t *ylval;
extern int yywrap();    
int scope = 0;
%}

%option yylineno

%%

"//".*						{single_comment(ylval); yylval.str = strdup(yytext);}

"if"						{add_alpha_token(ylval, yylineno, token_count++, "if", "KEYWORD", "0", ENUMERATED); yylval.str = strdup(yytext); return IF;}
"else"			       		{add_alpha_token(ylval, yylineno, token_count++, "else", "KEYWORD", "1", ENUMERATED); yylval.str = strdup(yytext); return ELSE;}
"while"			      		{add_alpha_token(ylval, yylineno, token_count++, "while", "KEYWORD", "2", ENUMERATED); yylval.str = strdup(yytext); return WHILE;}
"for"						{add_alpha_token(ylval, yylineno, token_count++, "for", "KEYWORD", "3", ENUMERATED); yylval.str = strdup(yytext); return FOR;}
"function"		        	{add_alpha_token(ylval, yylineno, token_count++, "function", "KEYWORD", "4", ENUMERATED); yylval.str = strdup(yytext); return FUNCTION;}
"return"		      		{add_alpha_token(ylval, yylineno, token_count++, "return", "KEYWORD", "5", ENUMERATED); yylval.str = strdup(yytext); return RETURN;}
"break"			      		{add_alpha_token(ylval, yylineno, token_count++, "break", "KEYWORD", "6", ENUMERATED); yylval.str = strdup(yytext); return BREAK;}
"continue"	         		{add_alpha_token(ylval, yylineno, token_count++, "continue", "KEYWORD", "7", ENUMERATED); yylval.str = strdup(yytext); return CONTINUE;}
"and"						{add_alpha_token(ylval, yylineno, token_count++, "and", "KEYWORD", "8", ENUMERATED); yylval.str = strdup(yytext); return AND;}
"not"						{add_alpha_token(ylval, yylineno, token_count++, "not", "KEYWORD", "9", ENUMERATED); yylval.str = strdup(yytext); return NOT;}
"or"						{add_alpha_token(ylval, yylineno, token_count++, "or", "KEYWORD", "10", ENUMERATED); yylval.str = strdup(yytext); return OR;}
"local"				    	{add_alpha_token(ylval, yylineno, token_count++, "local", "KEYWORD", "11", ENUMERATED); yylval.str = strdup(yytext); return LOCAL;}
"true"				    	{add_alpha_token(ylval, yylineno, token_count++, "true", "KEYWORD", "12", ENUMERATED); yylval.str = strdup(yytext); return TRUE;}
"false"					    {add_alpha_token(ylval, yylineno, token_count++, "false", "KEYWORD", "13", ENUMERATED); yylval.str = strdup(yytext); return FALSE;}
"nil"						{add_alpha_token(ylval, yylineno, token_count++, "nil", "KEYWORD", "14", ENUMERATED); yylval.str = strdup(yytext); return NIL;}

"/*"        				{comment(ylval); yylval.str = strdup(yytext);}

"="							{add_alpha_token(ylval, yylineno, token_count++, "=", "OPERATOR", "15", LEX_OPERATOR); yylval.str = strdup(yytext); return EQUAL;}
"+"							{add_alpha_token(ylval, yylineno, token_count++, "+", "OPERATOR", "16", LEX_OPERATOR); yylval.str = strdup(yytext); return PLUS;}
"-"							{add_alpha_token(ylval, yylineno, token_count++, "-", "OPERATOR", "17", LEX_OPERATOR); yylval.str = strdup(yytext); return MINUS;}
"*"							{add_alpha_token(ylval, yylineno, token_count++, "*", "OPERATOR", "18", LEX_OPERATOR); yylval.str = strdup(yytext); return MULTIPLICATION;}
"/"							{add_alpha_token(ylval, yylineno, token_count++, "/", "OPERATOR", "19", LEX_OPERATOR); yylval.str = strdup(yytext); return DIVISION;}
"%"							{add_alpha_token(ylval, yylineno, token_count++, "%", "OPERATOR", "20", LEX_OPERATOR); yylval.str = strdup(yytext); return PERCENTAGE;}
"=="						{add_alpha_token(ylval, yylineno, token_count++, "==", "OPERATOR", "21", LEX_OPERATOR); yylval.str = strdup(yytext); return EQUAL_EQUAL;}
"!="						{add_alpha_token(ylval, yylineno, token_count++, "!=", "OPERATOR", "22", LEX_OPERATOR); yylval.str = strdup(yytext); return NOT_EQUAL;}
"++"						{add_alpha_token(ylval, yylineno, token_count++, "++", "OPERATOR", "23", LEX_OPERATOR); yylval.str = strdup(yytext); return PLUS_PLUS;}
"--"						{add_alpha_token(ylval, yylineno, token_count++, "--", "OPERATOR", "24", LEX_OPERATOR); yylval.str = strdup(yytext); return MINUS_MINUS;}
">"							{add_alpha_token(ylval, yylineno, token_count++, ">", "OPERATOR", "25", LEX_OPERATOR); yylval.str = strdup(yytext); return GREATER;}
"<"							{add_alpha_token(ylval, yylineno, token_count++, "<", "OPERATOR", "26", LEX_OPERATOR); yylval.str = strdup(yytext); return SMALLER;}
">="						{add_alpha_token(ylval, yylineno, token_count++, ">=", "OPERATOR", "27", LEX_OPERATOR); yylval.str = strdup(yytext); return GREATER_EQUAL;}
"<="						{add_alpha_token(ylval, yylineno, token_count++, "<=", "OPERATOR", "28", LEX_OPERATOR); yylval.str = strdup(yytext); return SMALLER_EQUAL;}

"{"							{add_alpha_token(ylval, yylineno, token_count++, "{", "PUNCTUATION", "29",LEX_PUNCTUATION); yylval.str = strdup(yytext); return LEFT_CURLY;}
"}"							{add_alpha_token(ylval, yylineno, token_count++, "}", "PUNCTUATION", "30",LEX_PUNCTUATION); ; yylval.str = strdup(yytext); return RIGHT_CURLY;}
"["							{add_alpha_token(ylval, yylineno, token_count++, "[", "PUNCTUATION", "31", LEX_PUNCTUATION); yylval.str = strdup(yytext); return LEFT_BRACKET;}
"]"							{add_alpha_token(ylval, yylineno, token_count++, "]", "PUNCTUATION", "32", LEX_PUNCTUATION); yylval.str = strdup(yytext); return RIGHT_BRACKET;}
"("							{add_alpha_token(ylval, yylineno, token_count++, "(", "PUNCTUATION", "33", LEX_PUNCTUATION); yylval.str = strdup(yytext); return LEFT_PARENTHESES;}
")"							{add_alpha_token(ylval, yylineno, token_count++, ")", "PUNCTUATION", "34", LEX_PUNCTUATION); yylval.str = strdup(yytext); return RIGHT_PARENTHESES;}
";"							{add_alpha_token(ylval, yylineno, token_count++, ";", "PUNCTUATION", "35", LEX_PUNCTUATION); yylval.str = strdup(yytext); return SEMI_COLON;}
","							{add_alpha_token(ylval, yylineno, token_count++, ",", "PUNCTUATION", "36", LEX_PUNCTUATION); yylval.str = strdup(yytext); return COMMA;}
":"							{add_alpha_token(ylval, yylineno, token_count++, ":", "PUNCTUATION", "37", LEX_PUNCTUATION); yylval.str = strdup(yytext); return COLON;}
"::"						{add_alpha_token(ylval, yylineno, token_count++, "::", "PUNCTUATION", "38", LEX_PUNCTUATION); yylval.str = strdup(yytext); return COLON_COLON;}
"."							{add_alpha_token(ylval, yylineno, token_count++, ".", "PUNCTUATION", "39", LEX_PUNCTUATION); yylval.str = strdup(yytext); return DOT;}
".."						{add_alpha_token(ylval, yylineno, token_count++, "..", "PUNCTUATION", "40",  LEX_PUNCTUATION); yylval.str = strdup(yytext); return DOT_DOT;}
[a-zA-Z][_a-zA-Z0-9]*		{add_alpha_token(ylval, yylineno, token_count++, yytext, "IDENT", "41", P_CHARACTER); yylval.str = strdup(yytext); return IDENTIFIER;}
\"(\\.|[^"])*\"			    {string(ylval); yylval.str = strdup(yytext); return STRING;}

[0-9]*\.[0-9](e|E)?[0-9]*   {add_alpha_token(ylval, yylineno, token_count++, yytext, "REAL", "43", REAL); yylval.real_val = atof(yytext); return REAL;}
[0-9]+  					{add_alpha_token(ylval, yylineno, token_count++, yytext, "INTCONST", "44", INTEGER); yylval.int_val = atoi(yytext); return INTEGER;}
[ \t \r\v]	     			{} /* removes the whitespace*/ 
[\n]+				    		{}
<<EOF>>                     {
    
    fclose(f);
    if(runtime_error == 1){
        printf(RED"Error, not producing binary\n"RESET);
        exit(1);
    }
    printf(RED"KSEKINAW EDW\n"RESET);
    generate_output();

    create_instruction_output();

    create_binary_output();

    exit(1);
    
}
.                           /*{if(file){fprintf(yyout, "Unexpected character with value :%s\n", yytext);}else {printf("Unexpected character with value :%s\n", yytext);}*/ {exit(0);}


%%

/* detects the multi line comments and the nested,
 * open_comments starts = 1, we already have found / * from regex
 * Each time a opening_comment is found, open_comments++ and nested_count++
 * Each time a  is found, open_comments--
 * if open_comments<=0 it means from closing comment found than opening, break
 * Write each character we read from stream in case we found an invalid string
 * if open_comments = 0, all comments have closed, print all the nested comments
 * else unknown string, print the string and exit with error
 */

 void comment(void* ylval) {
	int c;


	/*is 1 because we already got one from regex */
	int nested_count = 0;
	int open_comments = 1;
    int newline_counter = 0;
    while ((c = input()) != EOF){

        if(c == '\n'){
            newline_counter++;
        }
        /* check if a new comment starts, increase the counter */
     	if ( c == '/'){
			c = input();


     		if  (c == '*'){

     		    open_comments++;
				nested_count++;
			}else{
     			unput(c);
     		}
     	}/* check if a comment ended, decrease the counter, if 0 break */
     	else if(c == '*'){
			c = input();

     		if (c == '/'){

     			open_comments--;
				if(nested_count > 0)
					add_alpha_token(ylval, yylineno, token_count++, "NESTED", "COMMENT", "46", COMMENT_MULTI);
				nested_count--;
     			/* all open brackets have closed*/
     			if (open_comments <=0)
     				break;
     		}/* neither of the above case matched, write the new character */
            else {
				unput(c);
     		}
     	}

     /* check if all comments have closed */
 	}


     if (open_comments == 0){
        add_alpha_token(ylval, yylineno - newline_counter, token_count++, "COMMENT_MULTI", "COMMENT", "46", COMMENT_MULTI);
        return ;
    }else{
     	/* we encountered an invalid token, print the string
        * end exit
        */
        if(file){
            fprintf(yyout, "Unexpected character when parsing multi-line comment\n");
        }else {
            printf("Unexpected character when parsing multi-line comment\n");
        }
    }
 }

 void single_comment(void* ylval){
 	add_alpha_token(ylval, yylineno, token_count++, "COMMENT_SINGLE", "COMMENT", "45", COMMENT_SINGLE);
 }
 void string(void* ylval) {
     int k = 0;
     int length;
     int counter = 0;
     int newline_counter = 0;
     char* ena;
     int invalid = 0;
     char* test;

     test = (char *) malloc(strlen(yytext + 1));

     ena =  (char *) malloc(strlen(yytext + 1));


     strcpy(test, &yytext[1]);
     test[strlen(test)-1] = '\0';
     length = (int) strlen(test) ;//- 2;
     yytext[0] = '\0';
     strcpy(yytext, test);

     while (length) {
         /*oso to string ksekinaei me \t katanalwse ta "tabs"(ta \t) */
         while(yytext[k] == '\\' && yytext[k+1] == 't') {
             ena[counter++] = '\t';
             k += 2;
             length -= 2;
         }

         /*oso to string ksekinaei me \" katanalwse ta "literal"(ta \") */
         while(yytext[k] == '\\' && yytext[k+1] == '"') {
             ena[counter++] = '\"';
             k += 2;
             length -= 2;
         }

         /*oso to string ksekinaei me \n katanalwse ta "new_lines"(ta \n) */
         while(yytext[k] == '\\' && yytext[k+1] == 'n') {
             ena[counter++] = '\n';
             k += 2;
             length -= 2;
         }


         /*oso to string ksekinaei me \\ katanalwse ta "\\"(to \) */
         while(yytext[k] == '\\' && yytext[k+1] == '\\') {
             ena[counter++] = '\\';
             k += 2;
             length -= 2;
         }

         /*oso to string ksekinaei me \ kai kati allo katanalwse ta "zeugaria" me ta lathos escape characters */
         while(yytext[k] == '\\' && ( yytext[k+1] != '\\' && yytext[k+1] != 'n' && yytext[k+1] != 't' && yytext[k+1] != '"' ) ) {

             if (length == 1){
                 ena[counter++]= yytext[k];
                 //invalid++;
                 length--;
                 break;
             }else{
                 ena[counter++] = yytext[k];
                 ena[counter++] = yytext[k+1];
                 k += 2;
                 length -= 2;
                 //invalid++;
             }
         }

         /*an den isxyei kati apo ta parapanw eite katanalwthikan oi antistixoi xaraktires eite den arxizei apo \ to strring */
         while(yytext[k] != '\\' && length > 0) {
             if(yytext[k] == '\n'){
                 newline_counter++;
             }
             ena[counter++] = yytext[k];
             k++;
             length--;

             if(yytext[k] == '\\' && length > 0) {
                 if(yytext[k+1] == 'n') {
                     ena[counter++] = '\n';
                     k += 2;
                     length -= 2;
                 }else if(yytext[k+1] == '"') {
                     ena[counter++] = '\"';
                     k += 2;
                     length -= 2;
                 }else if(yytext[k+1] == 't') {
                     ena[counter++] = '\t';
                     k += 2;
                     length -=2;
                 }else if(yytext[k+1] == '\\') {
                     ena[counter++] = '\\';
                     k += 2;
                     length -=2;
                 }else{
                     ena[counter++] = yytext[k];
                     k++;
                     length--;
                     //invalid++;
                 }
             }
         }
     }
     if (invalid){
         if(file){
             fprintf(yyout, "Invalid Escape Characters :%d\n", invalid);
         }else {
             printf("Invalid Escape Characters :%d\n", invalid);
         }
     }
     ena[counter++] = '\0';
     add_alpha_token(ylval, yylineno - newline_counter, token_count++, ena, "STRING", "42", P_CHARACTER);

}//eof_string_functions

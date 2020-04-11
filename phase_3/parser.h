/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    EQUAL = 258,
    OR = 259,
    AND = 260,
    EQUAL_EQUAL = 261,
    NOT_EQUAL = 262,
    GREATER = 263,
    GREATER_EQUAL = 264,
    SMALLER = 265,
    SMALLER_EQUAL = 266,
    PLUS = 267,
    MINUS = 268,
    MULTIPLICATION = 269,
    DIVISION = 270,
    PERCENTAGE = 271,
    NOT = 272,
    PLUS_PLUS = 273,
    MINUS_MINUS = 274,
    UMINUS = 275,
    DOT = 276,
    DOT_DOT = 277,
    RIGHT_BRACKET = 278,
    LEFT_BRACKET = 279,
    RIGHT_PARENTHESES = 280,
    LEFT_PARENTHESES = 281,
    IF = 282,
    ELSE = 283,
    WHILE = 284,
    FOR = 285,
    FUNCTION = 286,
    RETURN = 287,
    LOCAL = 288,
    TRUE = 289,
    FALSE = 290,
    NIL = 291,
    BREAK = 292,
    CONTINUE = 293,
    RIGHT_CURLY = 294,
    LEFT_CURLY = 295,
    SEMI_COLON = 296,
    COMMA = 297,
    COLON = 298,
    COLON_COLON = 299,
    IDENTIFIER = 300,
    STRING = 301,
    REAL = 302,
    INTEGER = 303
  };
#endif
/* Tokens.  */
#define EQUAL 258
#define OR 259
#define AND 260
#define EQUAL_EQUAL 261
#define NOT_EQUAL 262
#define GREATER 263
#define GREATER_EQUAL 264
#define SMALLER 265
#define SMALLER_EQUAL 266
#define PLUS 267
#define MINUS 268
#define MULTIPLICATION 269
#define DIVISION 270
#define PERCENTAGE 271
#define NOT 272
#define PLUS_PLUS 273
#define MINUS_MINUS 274
#define UMINUS 275
#define DOT 276
#define DOT_DOT 277
#define RIGHT_BRACKET 278
#define LEFT_BRACKET 279
#define RIGHT_PARENTHESES 280
#define LEFT_PARENTHESES 281
#define IF 282
#define ELSE 283
#define WHILE 284
#define FOR 285
#define FUNCTION 286
#define RETURN 287
#define LOCAL 288
#define TRUE 289
#define FALSE 290
#define NIL 291
#define BREAK 292
#define CONTINUE 293
#define RIGHT_CURLY 294
#define LEFT_CURLY 295
#define SEMI_COLON 296
#define COMMA 297
#define COLON 298
#define COLON_COLON 299
#define IDENTIFIER 300
#define STRING 301
#define REAL 302
#define INTEGER 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 126 "parser.y" /* yacc.c:1909  */

    int int_val;
    double real_val;
    char* str;
	int boolean;
	char* nil;
	expr my_expr;
	method_call method;
	struct SymbolTableEntry* my_entry;
	indexed_struct indexed_struct;

#line 162 "parser.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

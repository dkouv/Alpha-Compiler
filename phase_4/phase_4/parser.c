/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

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
	int patcharw_for_2o_elist = 0;
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
	char* system_functions[] = {"print", "input", "objectmemberkeys", "objecttotalmembers", "objectcopy", 
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

	char* vmopcode_types[] = 
	{	
		/* EXOUME ANTIKATASTISEI TO UMINUS ME TO MUL */
		"ASSIGN", "ADD", "SUB",
		"MUL", "DIVISION", "MOD",
		"MUL", "AND", "OR",
		"NOT", "IF_EQ", "IF_NOTEQ",
		"IF_LESSEQ", "IF_GREATEREQ", "IF_LESS",
		"IF_GREATER", "CALLFUNC", "PUSHARG",
		"ENTERFUNC", "EXITFUNC","NEWTABLE",
		"TABLEGETELEM", "TABLESETELEM", "NOP",
		"JUMP", "RET"
	};
	/* OPCODES GIA TO BINARY */
int vmopcode_binary_types[] = 
{	
        
    0 ,1, 2, 
    3, 4, 5, 
    6, 7, 8, 
    9, 10, 11, 
    12, 13, 14, 
    15, 16, 17,
    18, 19, 20,
    21, 22, 23, 
    24, 25
};

	char* variable_types[] = {"GLOBAL", "LOCAL", "FORMAL", "USERFUNC", "LIBFUNC", "FUNCLOCAL"};

#line 220 "parser.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
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
#line 155 "parser.y" /* yacc.c:355  */

    int int_val;
    double real_val;
    char* str;
	int boolean;
	char* nil;
	expr my_expr;
	method_call method;
	struct SymbolTableEntry* my_entry;
	indexed_struct indexed_struct;

#line 368 "parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 385 "parser.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   534

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  118
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  202

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   283,   283,   290,   283,   296,   299,   300,   312,   318,
     324,   332,   348,   370,   371,   375,   378,   379,   386,   387,
     388,   389,   390,   401,   412,   423,   432,   442,   450,   451,
     452,   465,   471,   481,   490,   520,   545,   571,   596,   599,
     652,   658,   667,   668,   675,   684,   765,   803,   824,   831,
     840,   852,   852,   853,   853,   856,   863,   862,   895,   909,
     922,   925,   938,   952,   963,   985,   992,  1010,  1026,  1031,
    1045,  1048,  1059,  1059,  1061,  1062,  1065,  1113,  1113,  1113,
    1113,  1064,  1141,  1165,  1165,  1165,  1165,  1140,  1195,  1203,
    1210,  1217,  1223,  1231,  1240,  1276,  1314,  1318,  1318,  1326,
    1335,  1346,  1354,  1353,  1369,  1375,  1375,  1368,  1396,  1397,
    1396,  1410,  1420,  1425,  1432,  1432,  1409,  1457,  1469
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "EQUAL", "OR", "AND", "EQUAL_EQUAL",
  "NOT_EQUAL", "GREATER", "GREATER_EQUAL", "SMALLER", "SMALLER_EQUAL",
  "PLUS", "MINUS", "MULTIPLICATION", "DIVISION", "PERCENTAGE", "NOT",
  "PLUS_PLUS", "MINUS_MINUS", "UMINUS", "DOT", "DOT_DOT", "RIGHT_BRACKET",
  "LEFT_BRACKET", "RIGHT_PARENTHESES", "LEFT_PARENTHESES", "IF", "ELSE",
  "WHILE", "FOR", "FUNCTION", "RETURN", "LOCAL", "TRUE", "FALSE", "NIL",
  "BREAK", "CONTINUE", "RIGHT_CURLY", "LEFT_CURLY", "SEMI_COLON", "COMMA",
  "COLON", "COLON_COLON", "IDENTIFIER", "STRING", "REAL", "INTEGER",
  "$accept", "program", "$@1", "$@2", "stmt", "expr", "term", "assignexpr",
  "primary", "lvalue", "member", "$@3", "$@4", "call", "$@5", "callsuffix",
  "normcall", "methodcall", "elist", "objectdef", "indexed",
  "multi_indexedelem", "indexedelem", "block", "$@6", "multi_stmt",
  "funcdefstmt", "$@7", "$@8", "$@9", "$@10", "$@11", "$@12", "$@13",
  "$@14", "$@15", "$@16", "const", "idlist", "ifprefix", "$@17",
  "elseprefix", "ifstmt", "whilestmt", "$@18", "whilestmt_continue",
  "$@19", "$@20", "$@21", "forstmt", "$@22", "$@23", "forstmt_continue",
  "$@24", "$@25", "$@26", "$@27", "$@28", "returnstmt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

#define YYPACT_NINF -172

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-172)))

#define YYTABLE_NINF -57

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-57)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,    42,   208,  -172,   352,   352,    11,    11,   244,   280,
      28,    59,    68,    -5,   316,     7,  -172,  -172,  -172,    54,
      56,  -172,  -172,    53,  -172,  -172,  -172,  -172,  -172,   107,
    -172,  -172,  -172,    40,  -172,   -10,  -172,  -172,  -172,  -172,
     208,  -172,  -172,  -172,  -172,  -172,  -172,    69,   -16,    21,
     -16,   352,   495,    -1,    76,    62,   410,    80,  -172,  -172,
    -172,  -172,  -172,  -172,   147,  -172,  -172,  -172,  -172,  -172,
       4,   352,   352,   352,   352,   352,   352,   352,   352,   352,
     352,   352,   352,   352,  -172,   352,  -172,  -172,    63,   352,
      31,   352,    85,   100,    97,   101,    20,  -172,   352,  -172,
      87,  -172,   102,   352,   352,   352,  -172,   103,  -172,   172,
    -172,   507,   131,   518,   518,   168,   168,   168,   168,     3,
       3,  -172,  -172,  -172,   495,  -172,   455,    88,   352,  -172,
    -172,  -172,    23,    90,   352,  -172,   208,   102,   352,   495,
    -172,  -172,   352,   433,   495,  -172,    47,   104,  -172,  -172,
    -172,  -172,   105,    25,  -172,  -172,   475,  -172,   397,    26,
    -172,   139,  -172,  -172,   123,   104,   352,  -172,  -172,  -172,
    -172,  -172,   352,   121,   142,   123,    61,   208,   495,  -172,
    -172,  -172,   143,  -172,  -172,    89,   129,  -172,  -172,  -172,
    -172,   129,   352,  -172,  -172,   132,  -172,   146,  -172,   208,
    -172,  -172
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,     0,    65,     0,
       0,     0,     0,     0,     0,     0,    92,    93,    91,     0,
       0,    72,    15,     0,    45,    90,    89,    88,     3,     0,
      30,    16,    38,    40,    48,    41,    42,    13,    14,    44,
       0,     7,     8,     9,    10,    32,    33,     0,    34,    51,
      36,     0,    63,     0,     0,    68,     0,     0,    97,   102,
     108,    82,    76,   117,     0,    46,    11,    12,    75,    47,
       2,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     6,     0,    35,    37,     0,     0,
       0,    65,     0,     0,   100,     0,     0,    66,     0,    67,
       0,    31,    43,     0,     0,    65,    83,     0,   118,     0,
       4,    29,    28,    26,    27,    22,    24,    23,    25,    17,
      18,    19,    20,    21,    39,    49,     0,     0,    65,    57,
      59,    60,     0,     0,     0,    99,     0,     0,     0,    64,
      70,    69,    65,     0,   104,   103,     0,    96,    77,    73,
      74,    50,     0,     0,    55,    52,     0,   101,     0,     0,
      98,     0,   109,    94,    84,    96,    65,    61,    54,    71,
      58,   105,     0,     0,     0,    78,     0,     0,   111,   110,
      95,    85,     0,    62,   106,     0,     0,    79,   107,   112,
      86,     0,    65,    87,    80,   113,    81,     0,   114,     0,
     115,   116
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -172,   116,  -172,  -172,   -27,    -2,  -172,  -172,  -172,    84,
    -172,  -172,  -172,    86,  -172,  -172,  -172,  -172,   -82,  -172,
      73,  -172,  -172,  -171,  -172,  -172,    -8,  -172,  -172,  -172,
    -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,    22,  -172,
    -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,
    -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    70,    28,    52,    30,    31,    32,    33,
      34,    92,    93,    35,    90,   129,   130,   131,    53,    36,
      54,   141,    55,    37,    68,   109,    38,   107,   165,   182,
     191,   196,   106,   147,   174,   186,   193,    39,   164,    40,
     103,   136,    41,    42,   104,   145,   161,   177,   188,    43,
     105,   172,   179,   185,   192,   197,   199,   201,    44
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      29,    57,    45,    46,    -5,    88,   -56,    56,    89,   132,
     -56,   -51,    64,    94,   -53,   190,    91,    81,    82,    83,
     194,    61,    97,   146,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    47,    29,    95,
      62,    98,     3,    85,    15,   -53,   153,    91,   154,    96,
     167,   170,    65,   127,    58,    23,    24,   128,    86,    87,
     159,    88,   -56,   138,    89,    98,   -56,    98,    98,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   150,   124,   176,    59,   183,   126,   162,    98,
      48,    50,    49,    49,    60,    66,   139,    67,    69,    99,
      13,   143,   144,    98,   100,   102,   133,    29,   125,   157,
     195,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,   134,   135,   137,    51,   142,   148,
     189,   166,   156,   152,    29,   155,   158,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,   163,
     184,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,   171,   173,   180,   181,   187,    21,
     178,   198,   200,   140,    98,    29,   -57,   -57,   -57,   -57,
      79,    80,    81,    82,    83,     4,   110,   175,   108,     5,
       6,     7,     0,     0,     0,     0,     8,    29,     9,    10,
       0,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,   149,    21,    22,     0,     0,    23,    24,    25,    26,
      27,     4,     0,     0,     0,     5,     6,     7,     0,     0,
       0,     0,     8,     0,     9,    10,     0,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,     0,    21,    22,
       0,     0,    23,    24,    25,    26,    27,     4,     0,     0,
       0,     5,     6,     7,     0,     0,     0,     0,     8,     0,
       9,     0,     0,     0,     0,     0,     0,    15,    16,    17,
      18,     0,     0,     0,    51,     0,     0,     0,    23,    24,
      25,    26,    27,     4,     0,     0,     0,     5,     6,     7,
       0,     0,     0,     0,     8,     0,     9,     0,     0,     0,
       0,    13,     0,    15,    16,    17,    18,     0,     0,     0,
       0,     0,     0,     0,    23,    24,    25,    26,    27,     4,
       0,     0,     0,     5,     6,     7,     0,     0,     0,     0,
       8,     0,     9,     0,     0,     0,     0,     0,     0,    15,
      16,    17,    18,     0,     0,     0,     0,    63,     0,     0,
      23,    24,    25,    26,    27,     4,     0,     0,     0,     5,
       6,     7,     0,     0,     0,     0,     8,     0,     9,     0,
       0,     0,     0,     0,     0,    15,    16,    17,    18,     0,
       0,     0,     0,     0,     0,     0,    23,    24,    25,    26,
      27,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,     0,     0,     0,
       0,     0,     0,     0,     0,   101,   169,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
       0,     0,     0,     0,     0,     0,     0,     0,   160,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,     0,     0,     0,     0,     0,     0,   151,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,     0,     0,     0,     0,     0,     0,   168,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,   -57,   -57,    75,    76,    77,    78,
      79,    80,    81,    82,    83
};

static const yytype_int16 yycheck[] =
{
       2,     9,     4,     5,     0,    21,    22,     9,    24,    91,
      26,    21,    14,    40,    24,   186,    26,    14,    15,    16,
     191,    26,    23,   105,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    26,    40,    47,
      45,    42,     0,     3,    33,    24,   128,    26,    25,    51,
      25,    25,    45,    22,    26,    44,    45,    26,    18,    19,
     142,    21,    22,    43,    24,    42,    26,    42,    42,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,   109,    85,   166,    26,    25,    89,    41,    42,
       6,     7,     6,     7,    26,    41,    98,    41,    45,    23,
      31,   103,   104,    42,    42,    25,    21,   109,    45,   136,
     192,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    24,    28,    25,    40,    26,    26,
      41,    26,   134,    45,   136,    45,   138,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    41,    45,
     177,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    25,    42,    45,    25,    25,    40,
     172,    25,   199,   100,    42,   177,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    13,    70,   165,    41,    17,
      18,    19,    -1,    -1,    -1,    -1,    24,   199,    26,    27,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    44,    45,    46,    47,
      48,    13,    -1,    -1,    -1,    17,    18,    19,    -1,    -1,
      -1,    -1,    24,    -1,    26,    27,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    -1,    40,    41,
      -1,    -1,    44,    45,    46,    47,    48,    13,    -1,    -1,
      -1,    17,    18,    19,    -1,    -1,    -1,    -1,    24,    -1,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,
      36,    -1,    -1,    -1,    40,    -1,    -1,    -1,    44,    45,
      46,    47,    48,    13,    -1,    -1,    -1,    17,    18,    19,
      -1,    -1,    -1,    -1,    24,    -1,    26,    -1,    -1,    -1,
      -1,    31,    -1,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    13,
      -1,    -1,    -1,    17,    18,    19,    -1,    -1,    -1,    -1,
      24,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    41,    -1,    -1,
      44,    45,    46,    47,    48,    13,    -1,    -1,    -1,    17,
      18,    19,    -1,    -1,    -1,    -1,    24,    -1,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      48,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    25,    39,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    23,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    23,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    50,    51,     0,    13,    17,    18,    19,    24,    26,
      27,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    40,    41,    44,    45,    46,    47,    48,    53,    54,
      55,    56,    57,    58,    59,    62,    68,    72,    75,    86,
      88,    91,    92,    98,   107,    54,    54,    26,    58,    62,
      58,    40,    54,    67,    69,    71,    54,    75,    26,    26,
      26,    26,    45,    41,    54,    45,    41,    41,    73,    45,
      52,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    41,     3,    18,    19,    21,    24,
      63,    26,    60,    61,    53,    75,    54,    23,    42,    23,
      42,    25,    25,    89,    93,    99,    81,    76,    41,    74,
      50,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    45,    54,    22,    26,    64,
      65,    66,    67,    21,    24,    28,    90,    25,    43,    54,
      69,    70,    26,    54,    54,    94,    67,    82,    26,    39,
      53,    23,    45,    67,    25,    45,    54,    53,    54,    67,
      25,    95,    41,    45,    87,    77,    26,    25,    23,    39,
      25,    25,   100,    42,    83,    87,    67,    96,    54,   101,
      45,    25,    78,    25,    53,   102,    84,    25,    97,    41,
      72,    79,   103,    85,    72,    67,    80,   104,    25,   105,
      53,   106
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    51,    52,    50,    50,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    55,    55,    55,    55,    55,    55,    55,    55,    56,
      57,    57,    57,    57,    57,    58,    58,    58,    58,    59,
      59,    60,    59,    61,    59,    62,    63,    62,    62,    64,
      64,    65,    66,    67,    67,    67,    68,    68,    69,    69,
      70,    71,    73,    72,    74,    74,    76,    77,    78,    79,
      80,    75,    81,    82,    83,    84,    85,    75,    86,    86,
      86,    86,    86,    86,    87,    87,    87,    89,    88,    90,
      91,    91,    93,    92,    95,    96,    97,    94,    99,   100,
      98,   102,   103,   104,   105,   106,   101,   107,   107
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     4,     0,     2,     1,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     2,     2,     2,     2,     2,     2,     1,     3,
       1,     1,     1,     3,     1,     1,     2,     2,     1,     3,
       4,     0,     4,     0,     5,     4,     0,     3,     6,     1,
       1,     3,     5,     1,     3,     0,     3,     3,     1,     3,
       1,     5,     0,     4,     2,     0,     0,     0,     0,     0,
       0,    11,     0,     0,     0,     0,     0,    10,     1,     1,
       1,     1,     1,     1,     1,     3,     0,     0,     5,     1,
       2,     4,     0,     4,     0,     0,     0,     6,     0,     0,
       7,     0,     0,     0,     0,     0,    10,     2,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 283 "parser.y" /* yacc.c:1646  */
    {
				if(start_counter == 0){
					printf(GREEN "********START********\n" RESET);
					start_counter++;
				}	
			}
#line 1688 "parser.c" /* yacc.c:1646  */
    break;

  case 3:
#line 290 "parser.y" /* yacc.c:1646  */
    {
				only_term = 0;
				printf("\n");
				
  		 	}
#line 1698 "parser.c" /* yacc.c:1646  */
    break;

  case 5:
#line 296 "parser.y" /* yacc.c:1646  */
    {printf("start\n");}
#line 1704 "parser.c" /* yacc.c:1646  */
    break;

  case 6:
#line 299 "parser.y" /* yacc.c:1646  */
    {printf(GREEN "expr ;\n" RESET);}
#line 1710 "parser.c" /* yacc.c:1646  */
    break;

  case 7:
#line 301 "parser.y" /* yacc.c:1646  */
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
#line 1726 "parser.c" /* yacc.c:1646  */
    break;

  case 8:
#line 313 "parser.y" /* yacc.c:1646  */
    {
					backpatch_while_quad(&quad_table);
					
					printf(GREEN "while\n"RESET);
				}
#line 1736 "parser.c" /* yacc.c:1646  */
    break;

  case 9:
#line 319 "parser.y" /* yacc.c:1646  */
    {
						backpatch_for_quad(&quad_table); 

					printf(GREEN "forstmt\n"RESET);
				}
#line 1746 "parser.c" /* yacc.c:1646  */
    break;

  case 10:
#line 325 "parser.y" /* yacc.c:1646  */
    {
				if (eimai_se_function == 0){
					printf(RED "Not in a loop\n"RESET);
					runtime_error = 1;
			}
				printf(GREEN "returnstmt ;\n"RESET);
			}
#line 1758 "parser.c" /* yacc.c:1646  */
    break;

  case 11:
#line 333 "parser.y" /* yacc.c:1646  */
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
#line 1778 "parser.c" /* yacc.c:1646  */
    break;

  case 12:
#line 349 "parser.y" /* yacc.c:1646  */
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
#line 1804 "parser.c" /* yacc.c:1646  */
    break;

  case 13:
#line 370 "parser.y" /* yacc.c:1646  */
    {printf(GREEN "block\n"RESET);}
#line 1810 "parser.c" /* yacc.c:1646  */
    break;

  case 14:
#line 371 "parser.y" /* yacc.c:1646  */
    {
												printf(GREEN "funcdefstmt\n"RESET);
												
											}
#line 1819 "parser.c" /* yacc.c:1646  */
    break;

  case 15:
#line 375 "parser.y" /* yacc.c:1646  */
    {printf(GREEN ";\n" RESET);}
#line 1825 "parser.c" /* yacc.c:1646  */
    break;

  case 16:
#line 378 "parser.y" /* yacc.c:1646  */
    {printf(BLUE "assignexpr\n" RESET);}
#line 1831 "parser.c" /* yacc.c:1646  */
    break;

  case 17:
#line 380 "parser.y" /* yacc.c:1646  */
    {
					printf(BLUE "expr + expr\n" RESET); 
					printf("TIPOS :%s\n", expression_types[(yyvsp[-2].my_expr)->type]);
					(yyval.my_expr) = calculate_expr(add, (yyvsp[-2].my_expr), (yyvsp[0].my_expr));
 
				}
#line 1842 "parser.c" /* yacc.c:1646  */
    break;

  case 18:
#line 386 "parser.y" /* yacc.c:1646  */
    {printf(BLUE "expr - expr\n" RESET); (yyval.my_expr) = calculate_expr(sub, (yyvsp[-2].my_expr), (yyvsp[0].my_expr));}
#line 1848 "parser.c" /* yacc.c:1646  */
    break;

  case 19:
#line 387 "parser.y" /* yacc.c:1646  */
    {printf(BLUE "expr * expr\n" RESET); (yyval.my_expr) = calculate_expr(mul, (yyvsp[-2].my_expr), (yyvsp[0].my_expr));}
#line 1854 "parser.c" /* yacc.c:1646  */
    break;

  case 20:
#line 388 "parser.y" /* yacc.c:1646  */
    {printf(BLUE "expr / expr\n" RESET); (yyval.my_expr) = calculate_expr(division, (yyvsp[-2].my_expr), (yyvsp[0].my_expr));}
#line 1860 "parser.c" /* yacc.c:1646  */
    break;

  case 21:
#line 389 "parser.y" /* yacc.c:1646  */
    {printf(BLUE "expr %% expr\n" RESET); (yyval.my_expr) = calculate_expr(mod, (yyvsp[-2].my_expr), (yyvsp[0].my_expr)); }
#line 1866 "parser.c" /* yacc.c:1646  */
    break;

  case 22:
#line 390 "parser.y" /* yacc.c:1646  */
    {
				printf(BLUE "expr > expr\n" RESET);
				(yyval.my_expr) = calculate_expr(if_greater, (yyvsp[-2].my_expr), (yyvsp[0].my_expr));
			 	
				create_quad(assign, (yyval.my_expr), false_expression, false_expression);
				create_quad(jump, true_expression, true_expression, true_expression);
				
				create_quad(assign, (yyval.my_expr), true_expression, false_expression);
				

				}
#line 1882 "parser.c" /* yacc.c:1646  */
    break;

  case 23:
#line 402 "parser.y" /* yacc.c:1646  */
    {
				printf(BLUE "expr < expr\n" RESET); 
				(yyval.my_expr) = calculate_expr(if_less, (yyvsp[-2].my_expr), (yyvsp[0].my_expr)); 
				
				create_quad(assign, (yyval.my_expr), false_expression, false_expression);
				create_quad(jump, true_expression, true_expression, true_expression);
				
				create_quad(assign, (yyval.my_expr), true_expression, false_expression);
				
			}
#line 1897 "parser.c" /* yacc.c:1646  */
    break;

  case 24:
#line 413 "parser.y" /* yacc.c:1646  */
    {
				printf(BLUE "expr >= expr\n" RESET); 
				(yyval.my_expr) = calculate_expr(if_greatereq, (yyvsp[-2].my_expr), (yyvsp[0].my_expr));
				create_quad(assign, (yyval.my_expr), false_expression, false_expression);
				create_quad(jump, true_expression, true_expression, true_expression);
				
				create_quad(assign, (yyval.my_expr), true_expression, false_expression);
				

			  }
#line 1912 "parser.c" /* yacc.c:1646  */
    break;

  case 25:
#line 424 "parser.y" /* yacc.c:1646  */
    {
				printf(BLUE "expr <= expr\n" RESET); 
				(yyval.my_expr) = calculate_expr(if_lesseq, (yyvsp[-2].my_expr), (yyvsp[0].my_expr));
				create_quad(assign, (yyval.my_expr), false_expression, false_expression);
				create_quad(jump, true_expression, true_expression, true_expression);
				
				create_quad(assign, (yyval.my_expr), true_expression, false_expression);
			}
#line 1925 "parser.c" /* yacc.c:1646  */
    break;

  case 26:
#line 433 "parser.y" /* yacc.c:1646  */
    {
				printf(BLUE "expr == expr\n" RESET); 
				printf(RED" %d\n"RESET, is_if);
				(yyval.my_expr) = calculate_expr(if_eq_op, (yyvsp[-2].my_expr), (yyvsp[0].my_expr)); 
				create_quad(assign, (yyval.my_expr), false_expression, false_expression);
				create_quad(jump, true_expression, true_expression, true_expression);
				create_quad(assign, (yyval.my_expr), true_expression, false_expression);	
				
			}
#line 1939 "parser.c" /* yacc.c:1646  */
    break;

  case 27:
#line 443 "parser.y" /* yacc.c:1646  */
    {
				printf(BLUE "expr != expr\n" RESET); 
				(yyval.my_expr) = calculate_expr(if_noteq, (yyvsp[-2].my_expr), (yyvsp[0].my_expr));
				create_quad(assign, (yyval.my_expr), false_expression, false_expression);
				create_quad(jump, true_expression, true_expression, true_expression);
				create_quad(assign, (yyval.my_expr), true_expression, false_expression);		
			}
#line 1951 "parser.c" /* yacc.c:1646  */
    break;

  case 28:
#line 450 "parser.y" /* yacc.c:1646  */
    {printf(BLUE "expr and expr\n" RESET);printf("str :%s %s\n", (yyvsp[-2].my_expr)->strConst , (yyvsp[0].my_expr)->strConst); (yyval.my_expr) = calculate_expr(and, (yyvsp[-2].my_expr), (yyvsp[0].my_expr)); (yyval.my_expr)->type = boolexpr_e;}
#line 1957 "parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 451 "parser.y" /* yacc.c:1646  */
    {printf(BLUE "expr or expr\n" RESET); (yyval.my_expr) = calculate_expr(or, (yyvsp[-2].my_expr), (yyvsp[0].my_expr)); (yyval.my_expr)->type = boolexpr_e;}
#line 1963 "parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 453 "parser.y" /* yacc.c:1646  */
    {
				only_term ++;
				printf(BLUE "term\n" RESET);
				/* arxikopoiw to last_param_created afou sigoura tha proerxetai apo term */
				//memcpy(last_param_created, $$, sizeof(struct expr));
					
			}
#line 1975 "parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 466 "parser.y" /* yacc.c:1646  */
    {
				
				(yyval.my_expr) = (yyvsp[-1].my_expr);
				printf(BLUE "( expr ) -> " RESET);
			}
#line 1985 "parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 472 "parser.y" /* yacc.c:1646  */
    {
				(yyval.my_expr) = (expr) calloc(sizeof(struct expr), sizeof(struct expr));
				expr e = calloc(sizeof(struct expr), sizeof(struct expr));
				e->type = constint_e;
				e->const_int = -1;
				
				(yyval.my_expr) = calculate_expr(mul, (yyvsp[0].my_expr), e);
				printf("- expr -> " RESET);
			}
#line 1999 "parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 482 "parser.y" /* yacc.c:1646  */
    {
				(yyval.my_expr) = (expr) calloc(sizeof(struct expr), sizeof(struct expr));

				(yyval.my_expr)->type = constbool_e;

				(yyval.my_expr) = calculate_expr(not, (yyvsp[0].my_expr), (yyvsp[0].my_expr));
				printf(BLUE "!  expr -> " RESET);
			}
#line 2012 "parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 491 "parser.y" /* yacc.c:1646  */
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

					//$$ = create_quad(add, ena, $2, $2);
					expr e = create_new_temp_var();
					create_quad(add, (yyvsp[0].my_expr), ena, (yyvsp[0].my_expr));

					create_quad(assign, e, (yyvsp[0].my_expr), e);
					(yyval.my_expr) = e;
					printf(BLUE "++lvalue ->" RESET);
				
				
				
				}
#line 2046 "parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 521 "parser.y" /* yacc.c:1646  */
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

					//$$ = create_quad(add, $lvalue, ena, $lvalue);
					expr e =  create_new_temp_var();
					create_quad(assign, e, (yyvsp[-1].my_expr), e);
					create_quad(add, (yyvsp[-1].my_expr), ena, (yyvsp[-1].my_expr));
					(yyval.my_expr) = e;
					printf(BLUE "lvalue++ ->" RESET);
				}
#line 2075 "parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 546 "parser.y" /* yacc.c:1646  */
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

					//$$ = create_quad(sub, $lvalue, ena, $lvalue);
					expr e = create_new_temp_var();
					create_quad(sub, (yyvsp[0].my_expr), ena, (yyvsp[0].my_expr));
					(yyval.my_expr) = create_quad(assign, e, (yyvsp[0].my_expr), e);	
					
					printf(BLUE "--lvalue -> " RESET);
				}
#line 2105 "parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 572 "parser.y" /* yacc.c:1646  */
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

					//$$ = create_quad(sub, $lvalue, ena, $lvalue);
					expr t = create_new_temp_var();
					create_quad(assign,  t, (yyvsp[-1].my_expr), (yyvsp[-1].my_expr));
					create_quad(sub, (yyvsp[-1].my_expr), ena, (yyvsp[-1].my_expr));
					(yyval.my_expr) = t;
					printf(BLUE "lvalue-- -> " RESET);
				}
#line 2134 "parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 596 "parser.y" /* yacc.c:1646  */
    {only_term ++;printf(BLUE "primary -> " RESET);}
#line 2140 "parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 600 "parser.y" /* yacc.c:1646  */
    {	
					/******************************************************/
					/* checking  gia apofigi praksis me function variable */
					/******************************************************/
				 
					if(expr_node){
						
						//printf("To expr_node einai :%d\n", expr_node->type);
						if(symbol_get_value_type(expr_node->type) == 1 && strcmp((yyvsp[-2].my_expr)->sym->value.varVal->name, expr_node->value.funcVal->name) == 0){
							printf(RED "Cannot perform assignment with function at line :%d\n"RESET, yylineno); 
						} 
					}else {
						entry e = look_up((yyvsp[-2].my_expr)->sym->value.varVal->name, scope);
						if(e && symbol_get_value_type(e->type) == 0 && eimai_se_function != 0 && e->value.varVal->scope != 0 && e->value.varVal->scope != scope && !eimai_se_loop){
								if(tipwsa_error_gia_var == 0)
									printf(RED"Cannot access :%s inside of function\n"RESET, (yyvsp[-2].my_expr)->sym->value.varVal->name);
							
						}
					}
					expr_node = NULL;
					tipwsa_error_gia_var = 0;
					printf(BLUE "lvalue = expression -> " RESET);
					if ((yyvsp[0].my_expr)->type == newtable_e) {
						is_objectdef = 0;
						vector_print(label);

						vector_free(&tableelem);
						vector_init(&tableelem);
						(yyval.my_expr) = create_quad(assign, (yyvsp[0].my_expr), (yyvsp[-2].my_expr), true_expression);


					}else if((yyvsp[-2].my_expr)->type == tableitem_e) {
		
						create_quad(tablesetelem,(yyvsp[-2].my_expr),(yyvsp[-2].my_expr)->index,(yyvsp[0].my_expr));

						(yyval.my_expr) = emit_iftableitem((yyvsp[-2].my_expr));
						(yyval.my_expr)->type = assignexpr_e; 
						
						
					}else {
						
						create_quad(assign, (yyvsp[-2].my_expr), (yyvsp[0].my_expr), true_expression);
						//$assignexpr = newexpr(assignexpr_e);
						// $assignexpr->type = assignexpr_e;
						//$assignexpr->sym = Scope_List_Contains_Symbol($assignexpr->strConst, scope);
						(yyval.my_expr) = create_new_temp_var();
						(yyval.my_expr)->type = var_e;
						create_quad(assign,(yyval.my_expr),(yyvsp[-2].my_expr),true_expression);

					}
					
				}
#line 2197 "parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 653 "parser.y" /* yacc.c:1646  */
    {
				printf(BLUE "lvalue -> " RESET);
				(yyval.my_expr) = (expr )emit_iftableitem((yyvsp[0].my_expr));
				//printf(RED "%s\n" RESET, $primary->strConst);
			}
#line 2207 "parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 659 "parser.y" /* yacc.c:1646  */
    {/* edw tha kanw to neo quad gia to function , px F(a, b) */
				
			
				//create_quad(call, $$, true_expression, true_expression);
				//$$ = calculate_expr(getretval, true_expression, true_expression);
				
				printf(BLUE "call -> " RESET);
			}
#line 2220 "parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 667 "parser.y" /* yacc.c:1646  */
    {printf(BLUE "objectdef -> " RESET);}
#line 2226 "parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 669 "parser.y" /* yacc.c:1646  */
    {
				
				(yyval.my_expr)->type = programfunc_e;
				(yyval.my_expr)->sym = (yyvsp[-1].my_entry);
				printf(BLUE "( funcdefstmt ) -> " RESET);
			}
#line 2237 "parser.c" /* yacc.c:1646  */
    break;

  case 44:
#line 676 "parser.y" /* yacc.c:1646  */
    {
				only_term ++;
				(yyval.my_expr) = (yyvsp[0].my_expr);
				
				printf(BLUE "const -> " RESET);
			}
#line 2248 "parser.c" /* yacc.c:1646  */
    break;

  case 45:
#line 685 "parser.y" /* yacc.c:1646  */
    {
						/************************************************************************/
						/* diavasa ena simvolo,  poy borei na anaferetai se function i variable */
						/* an einai omws function de borw na kanw prakseis me to lvalue opote   */
						/* to apothikeuw kai to elegxw ksexwrista se kathe periptwsi tou lvalue */
						/* to expr_node einai pedio tou yylval union                            */
						/************************************************************************/
				printf("%s -> ", (yyvsp[0].str));
				(yyval.my_expr) = calloc(sizeof(struct expr), sizeof(struct expr));

				only_term++;
				
				entry e = NULL;
				e = look_up((yyvsp[0].str), scope);
			
				
				/********************************************/
				/* elegxw an iparxei sto stoixeio $1 sto    */
				/* scope list, an oxi to eisagw me to scope */
				/********************************************/
				if (conflict_with_system_function((yyvsp[0].str)) == 0){


					entry iparxei_func = get_function_entry((yyvsp[0].str), scope);
					if (!e){
						if (scope == 0) 
							SymTable_put(Symbol_Table, (yyvsp[0].str), yylineno, scope, assign_counter, 0);
						else 
							SymTable_put(Symbol_Table, (yyvsp[0].str), yylineno, scope, assign_counter, 1);
						expr_node = Scope_List_Contains_Symbol((yyvsp[0].str), scope);

					}else{
						
						if(symbol_get_value_type(e->type) == 0 && eimai_se_function != 0 && e->value.varVal->scope != 0 && e->value.varVal->scope != scope && !eimai_se_loop){
							if(iparxei_func == NULL){
								printf(RED" SCOPE :%d\n"RESET, e->value.varVal->scope);
								printf(RED"Cannot access :%s inside of function\n"RESET, (yyvsp[0].str));
								tipwsa_error_gia_var = 1;
								expr_node = e;
								//runtime_error = 1;
							}
						}else if ( e->isActive ) {
							printf("Symbol :%s is already defined and active, den kanw put\n", (yyvsp[0].str));
							print_entry_node_information(e);
							
							expr_node = e;
						}
						else if(!e->isActive) {
							if (scope)
								SymTable_put(Symbol_Table, (yyvsp[0].str), yylineno, scope, assign_counter, 1);
							else
								SymTable_put(Symbol_Table, (yyvsp[0].str), yylineno, scope, assign_counter, 0);
							expr_node = Scope_List_Contains_Symbol((yyvsp[0].str), scope);

						}


					}
					if(symbol_get_value_type(expr_node->type) == 1){
						//printf("LALALALALALA\n");
						//expr_node->type = programfunc_e;
						//$$->type = programfunc_e;
					}
					(yyval.my_expr)->sym = expr_node;//Scope_List_Contains_Symbol($IDENTIFIER, scope);
					//$$->type = number_e;
				}else {
					printf("Referring to LIBFUNC:%s\n", (yyvsp[0].str));

					(yyval.my_expr)->sym = Scope_List_Contains_Symbol((yyvsp[0].str), 0);
					//printf(RED"PTR :%p\n", $$->sym);
					(yyval.my_expr)->type = 	libraryfunc_e;
				}	
			
				


			}
#line 2330 "parser.c" /* yacc.c:1646  */
    break;

  case 46:
#line 766 "parser.y" /* yacc.c:1646  */
    {
				local_size++;
				(yyval.my_expr) = calloc(sizeof(struct expr), sizeof(struct expr));
				//$$->strConst = strdup($2);
				only_term++;
				printf(BLUE "local %s -> " RESET, (yyvsp[0].str));
				/******************************************/
				/* an to scope einai global ,borw na kanw */
				/* local system_function xwris provlima   */
				/******************************************/
				/* an den iparxei sto local scope  */
				printf(RED);
				if (Scope_List_Contains_Symbol((yyvsp[0].str), scope) == NULL){
					/* vrikame oti kanei conflict me to name mia system sinartisis */
					if(conflict_with_system_function((yyvsp[0].str)) == 1){
						if(scope == 0){
							printf("%s, referring to function in scope 0\n", (yyvsp[0].str));
						}else {
							printf(RED"Error: symbol: %s trying to shadow system function at line: %d\n" RESET, (yyvsp[0].str), yylineno);
						}	

					}else if (scope == 0) 
						SymTable_put(Symbol_Table, (yyvsp[0].str), yylineno, scope, assign_counter, 0);
					else	
						SymTable_put(Symbol_Table, (yyvsp[0].str), yylineno, scope, assign_counter, 1);
				}else {
					/* iparxei sto current scope */
					printf("Referring to local scope symbol:%s\n", (yyvsp[0].str));


				}
				printf(RESET);
				(yyval.my_expr)->sym = look_up((yyvsp[0].str), scope);
				(yyval.my_expr)->type = var_e;

			}
#line 2371 "parser.c" /* yacc.c:1646  */
    break;

  case 47:
#line 804 "parser.y" /* yacc.c:1646  */
    {
				(yyval.my_expr) = calloc(sizeof(struct expr), sizeof(struct expr));
				 
				only_term++;
				printf(BLUE ":: %s -> " RESET, (yyvsp[0].str));

				if(conflict_with_system_function((yyvsp[0].str)) == 1){
					printf("Error: symbol: %s trying to shadow system function at line: %d\n", (yyvsp[0].str), yylineno);
				}
				else if (look_up((yyvsp[0].str),0) == NULL) //psaxnw mono sto Global scope kai an den iparxei error;
				{
					printf(RED"Error: symbol :%s does not exist in global scope\n"RESET, (yyvsp[0].str));
					
				}else 
					printf("Symbol :%s exists in global scope\n", (yyvsp[0].str));

				(yyval.my_expr)->sym = Scope_List_Contains_Symbol((yyvsp[0].str), 0);
				(yyval.my_expr)->type = var_e;
			}
#line 2395 "parser.c" /* yacc.c:1646  */
    break;

  case 48:
#line 825 "parser.y" /* yacc.c:1646  */
    { 
					(yyval.my_expr) = (yyvsp[0].my_expr);
					printf(BLUE "member -> " RESET);
				}
#line 2404 "parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 831 "parser.y" /* yacc.c:1646  */
    { 
				printf(BLUE "lvalue. %s  -> " RESET, (yyvsp[0].str));
				
				printf("TYPE :%d\n", (yyvsp[-2].my_expr)->type);	

				(yyval.my_expr)  =  member_item((yyvsp[-2].my_expr),(yyvsp[0].str));
			
			}
#line 2417 "parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 840 "parser.y" /* yacc.c:1646  */
    { 
				counter++;
				printf(BLUE "lvalue [ expr ] -> " RESET);
				(yyvsp[-3].my_expr) = emit_iftableitem((yyvsp[-3].my_expr));
				
				(yyval.my_expr) = newexpr(tableitem_e);
				(yyval.my_expr)->sym = (yyvsp[-3].my_expr)->sym;
				//$member->strConst = strdup($1->strConst);
				(yyval.my_expr)->index = (yyvsp[-1].my_expr);
				
				
			}
#line 2434 "parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 852 "parser.y" /* yacc.c:1646  */
    {expr_node = NULL;}
#line 2440 "parser.c" /* yacc.c:1646  */
    break;

  case 52:
#line 852 "parser.y" /* yacc.c:1646  */
    {printf(BLUE "lvalue . %s -> " RESET, (yyvsp[-3].my_expr)->strConst);}
#line 2446 "parser.c" /* yacc.c:1646  */
    break;

  case 53:
#line 853 "parser.y" /* yacc.c:1646  */
    {expr_node = NULL;}
#line 2452 "parser.c" /* yacc.c:1646  */
    break;

  case 54:
#line 853 "parser.y" /* yacc.c:1646  */
    {printf(BLUE "call [ expr ] -> " RESET);}
#line 2458 "parser.c" /* yacc.c:1646  */
    break;

  case 55:
#line 857 "parser.y" /* yacc.c:1646  */
    {
				(yyval.my_expr) = make_call((yyvsp[-3].my_expr), (yyvsp[-1].my_expr));

				printf(BLUE "call ( elist ) -> " RESET);
			}
#line 2468 "parser.c" /* yacc.c:1646  */
    break;

  case 56:
#line 863 "parser.y" /* yacc.c:1646  */
    {	
				entry iparxei_func = get_function_entry((yyvsp[0].my_expr)->strConst, scope);
				if(iparxei_func){
					printf("Referring to :%s at line %d\n", (yyvsp[0].my_expr)->strConst, iparxei_func->value.funcVal->line);
				}	
			}
#line 2479 "parser.c" /* yacc.c:1646  */
    break;

  case 57:
#line 870 "parser.y" /* yacc.c:1646  */
    {

				 if((yyvsp[0].method)->m_method == 1){
					expr self = (yyvsp[-2].my_expr);
					printf("%p\n", self);
					printf("%s\n", (yyvsp[0].method)->m_name);
					(yyvsp[-2].my_expr) = emit_iftableitem(member_item(self, (yyvsp[0].method)->m_name));
			
					expr tmp = (yyvsp[0].method)->m_expr;
					while(tmp->next){
					 
						tmp = tmp->next;
					}
					
					self->next = (yyvsp[0].method)->m_expr;
					(yyvsp[0].method)->m_expr = self;
					//tmp->next = self;
					//$callsuffix->m_expr = self;
				 }



				 (yyval.my_expr) = make_call((yyvsp[-2].my_expr), (yyvsp[0].method)->m_expr);
				 printf(BLUE "lvalue callsuffix -> " RESET);
			}
#line 2509 "parser.c" /* yacc.c:1646  */
    break;

  case 58:
#line 896 "parser.y" /* yacc.c:1646  */
    {
					expr f = newexpr(programfunc_e);
					f->sym = (yyvsp[-4].my_entry);
					
					(yyval.my_expr) = make_call(f, (yyvsp[-1].my_expr));

			 		printf(BLUE "( funcdefstmt ) ( elist )  -> " RESET);

					
			 	}
#line 2524 "parser.c" /* yacc.c:1646  */
    break;

  case 59:
#line 909 "parser.y" /* yacc.c:1646  */
    {
					printf("HERE\n");
 
					if((yyvsp[0].method) !=NULL && (yyvsp[0].method)->m_expr){
						expr tmp = (yyvsp[0].method)->m_expr;
						
						while(tmp){
							tmp = tmp->next;
						}
						(yyval.method) = (yyvsp[0].method);
					}
					printf(BLUE "normcall -> " RESET);
				}
#line 2542 "parser.c" /* yacc.c:1646  */
    break;

  case 60:
#line 922 "parser.y" /* yacc.c:1646  */
    {(yyval.method) = (yyvsp[0].method);printf(BLUE "methodcall -> " RESET);}
#line 2548 "parser.c" /* yacc.c:1646  */
    break;

  case 61:
#line 926 "parser.y" /* yacc.c:1646  */
    {	
					
						if((yyval.method) != NULL){
							(yyval.method)->m_expr = (yyvsp[-1].my_expr);
					
							(yyval.method)->m_method = 0;
							(yyval.method)->m_name = strdup("nil");
							
				}
					printf(BLUE "( elist ) -> " RESET);
				}
#line 2564 "parser.c" /* yacc.c:1646  */
    break;

  case 62:
#line 939 "parser.y" /* yacc.c:1646  */
    {
				
					printf(BLUE"%p\n"RESET, (yyvsp[-1].my_expr));
					printf(BLUE"%p\n"RESET, (yyval.method));
					//$$ = calloc(sizeof(struct methodcall), sizeof(struct methodcall));
					(yyval.method)->m_expr = (yyvsp[-1].my_expr);

					(yyval.method)->m_name = strdup((yyvsp[-3].str));
					(yyval.method)->m_method = 1; 
					
							printf(BLUE ".. %s ( elist ) -> " RESET, (yyvsp[-3].str));
			}
#line 2581 "parser.c" /* yacc.c:1646  */
    break;

  case 63:
#line 953 "parser.y" /* yacc.c:1646  */
    {
				
				/* edw tha kanw to neo quad gia to parameter , px f(a, b) */
				//if(se_ti_loop_eimai == 0)
				//	create_quad(param, $1, true_expression, true_expression);
				(yyval.my_expr) = (yyvsp[0].my_expr);
				
				(yyval.my_expr)->next = NULL;
				printf(BLUE "expr -> " RESET);
			}
#line 2596 "parser.c" /* yacc.c:1646  */
    break;

  case 64:
#line 964 "parser.y" /* yacc.c:1646  */
    {
				/* edw tha kanw to neo quad gia to parameter , px f(a, b) */
				//if(se_ti_loop_eimai == 0)
				//	create_quad(param, $3, true_expression, true_expression);
				expr tmp = (yyvsp[-2].my_expr);

				while(tmp->next != NULL){
					
					tmp = tmp->next;
				}
				expr l = (yyvsp[-2].my_expr);

				//$expr->next = $1;
				//$$ = $expr;
				 tmp->next = (yyvsp[0].my_expr);
			
				 (yyval.my_expr) = (yyvsp[-2].my_expr);

				printf(BLUE "elist , expr -> " RESET);
			}
#line 2621 "parser.c" /* yacc.c:1646  */
    break;

  case 65:
#line 985 "parser.y" /* yacc.c:1646  */
    {
					
					(yyval.my_expr) = NULL;
					
					printf(RED "Empty elist\n" RESET);
				}
#line 2632 "parser.c" /* yacc.c:1646  */
    break;

  case 66:
#line 993 "parser.y" /* yacc.c:1646  */
    {	
					(yyval.my_expr) = create_new_temp_var();
					
					create_quad(tablecreate, (yyval.my_expr), true_expression, true_expression);
					expr tmp = (yyvsp[-1].my_expr);
					int i = 0;
					int c;
					Dynamic_Table ex;
					table_init(&ex);
					while(tmp != NULL){
						create_quad(tablesetelem1, (yyval.my_expr), newexpr_constint (i++), tmp);
 
						tmp = tmp->next;
					}
 
					
				}
#line 2654 "parser.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1011 "parser.y" /* yacc.c:1646  */
    {
		     		(yyval.my_expr) = create_new_temp_var();
		     		create_quad(tablecreate, (yyval.my_expr), true_expression, true_expression);

		     		indexed_struct tmp = (yyvsp[-1].indexed_struct);
		     		while(tmp != NULL){

		     			create_quad(tablesetelem1, (yyval.my_expr), tmp->index, tmp->value);
		     			tmp = tmp->next;
		     		}

		    		printf("[ indexed ] -> ");
				}
#line 2672 "parser.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1027 "parser.y" /* yacc.c:1646  */
    { 
			 		(yyval.indexed_struct) = (yyvsp[0].indexed_struct);
			 		printf(BLUE "indexelem -> " RESET );
		    	}
#line 2681 "parser.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1032 "parser.y" /* yacc.c:1646  */
    { 
					indexed_struct tmp = (yyvsp[-2].indexed_struct);
					while(tmp->next != NULL){
						tmp = tmp->next;
					}

					tmp->next = (yyvsp[0].indexed_struct);
					(yyval.indexed_struct) = (yyvsp[-2].indexed_struct);

					printf(BLUE "indexelem , indexelem -> " RESET);
				}
#line 2697 "parser.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1049 "parser.y" /* yacc.c:1646  */
    {
					(yyval.indexed_struct) = calloc(sizeof(struct indexed_struct), sizeof(struct indexed_struct));
					(yyval.indexed_struct)->index =  (yyvsp[-3].my_expr);
					(yyval.indexed_struct)->value =  (yyvsp[-1].my_expr);

					printf(BLUE "{ expr : expr } -> " RESET);
				}
#line 2709 "parser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1059 "parser.y" /* yacc.c:1646  */
    {scope++;}
#line 2715 "parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1059 "parser.y" /* yacc.c:1646  */
    {hide_variables_of_current_scope(scope);scope--;printf(BLUE "{ stmt } -> " RESET);}
#line 2721 "parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1061 "parser.y" /* yacc.c:1646  */
    {printf(BLUE "multi_stmt -> " RESET);}
#line 2727 "parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1062 "parser.y" /* yacc.c:1646  */
    {printf(BLUE "Block\n" RESET);}
#line 2733 "parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1065 "parser.y" /* yacc.c:1646  */
    {
			se_ti_loop_eimai = 1;
			/* allazw scope_offset */




			/* telos allagis */
			entry node;
			
			/* elegxw an iparxei to node sto scope */

			node = Scope_List_Contains_Symbol((yyvsp[0].str), scope);

			/* vrike to idio node sto scope , error */
			if(node){
				printf(RED "Error, FUNCTION :%s already Exists\n"RESET, (yyvsp[0].str));
				function_list_insert(node);
				runtime_error = 1;
			}else{
				/**********************************************/
				/* de vrethike to node sto scope              */
				/* elegxw an exei onoma sinartisis sistimatos */
				/**********************************************/
				if(conflict_with_system_function((yyvsp[0].str)) == 1){
					printf(RED"Error: symbol: %s Collision with system function at line:%d\n"RESET, (yyvsp[0].str), yylineno);
		
				}else {
					/* efoson den petakse kapoio minima den exoun idio identifier */
					printf(YELLOW" VAZW NEA SINARTISI ! :%s\n"RESET, (yyvsp[0].str));
					SymTable_put(Symbol_Table, (yyvsp[0].str), yylineno, scope, assign_counter, 3);
					function_list_insert(Scope_List_Contains_Symbol((yyvsp[0].str), scope));
					current_function_name = strdup((yyvsp[0].str));
				}
			}
			/* memory allocation for function expression gia na to steiloume gia quad             */
			/* arkei na allaksoume mono to pedio strConst kai ton tipo afou to name tis func_expr */
			/* tha einai panta string! 															  */

			expr func_expr = calloc(sizeof(struct expr), sizeof(struct expr));
			func_expr->type = conststring_e;
			func_expr->strConst = strdup((yyvsp[0].str));
			func_expr->sym = look_up((yyvsp[0].str), scope);
			printf("%p\n",func_expr->sym);
		
			create_quad(funcstart, func_expr, true_expression, true_expression);

		}
#line 2786 "parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1113 "parser.y" /* yacc.c:1646  */
    {enter_scope_space(FORMAL_T);}
#line 2792 "parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1113 "parser.y" /* yacc.c:1646  */
    {remove_last_scope_space();}
#line 2798 "parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1113 "parser.y" /* yacc.c:1646  */
    {enter_scope_space(functionLocal);eimai_se_function++;}
#line 2804 "parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1113 "parser.y" /* yacc.c:1646  */
    {eimai_se_function--;remove_last_scope_space();}
#line 2810 "parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1114 "parser.y" /* yacc.c:1646  */
    {
				printf("PARAMETROI\n");
				/************************************************************/
				/* kanw null ti lista etsi oste ta arguments tis sinartisis */
				/* na min ta paroun oi epomenes sinartiseis					*/
				/************************************************************/
			


				expr func_expr = calloc(sizeof(struct expr), sizeof(struct expr));
				func_expr->type = conststring_e;
				printf(RED":%s\n"RESET, last_function_created->value.funcVal->name);
				func_expr->strConst = strdup(last_function_created->value.funcVal->name);
				
				func_expr->sym = look_up(func_expr->strConst, scope);
				create_quad(funcend, func_expr, true_expression, true_expression);
				printf(BLUE "%s  ( idlist ) block -> " RESET, (yyvsp[-10].str));
				argument_list_head = NULL;
				formal_argument_count = 0;
				se_ti_loop_eimai = 0;

				(yyval.my_entry) = get_function_entry((yyvsp[-9].str), scope);
				printf("TELOS\n");
				function_list_remove_last();
				
			}
#line 2841 "parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1141 "parser.y" /* yacc.c:1646  */
    {
				open_anon_functions++;
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
				function_list_insert(Scope_List_Contains_Symbol(name, scope));

					
				expr func_expr = calloc(sizeof(struct expr), sizeof(struct expr));
				func_expr->type = conststring_e;
				func_expr->strConst = strdup(name);
				func_expr->sym = look_up(name, scope);

				create_quad(funcstart, func_expr, true_expression, true_expression);
			}
#line 2870 "parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1165 "parser.y" /* yacc.c:1646  */
    {enter_scope_space(2);}
#line 2876 "parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1165 "parser.y" /* yacc.c:1646  */
    {remove_last_scope_space();}
#line 2882 "parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1165 "parser.y" /* yacc.c:1646  */
    {enter_scope_space(functionLocal);eimai_se_function++;}
#line 2888 "parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1165 "parser.y" /* yacc.c:1646  */
    {eimai_se_function--;remove_last_scope_space();}
#line 2894 "parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1166 "parser.y" /* yacc.c:1646  */
    {
					int current_name = functions_without_id - open_anon_functions;
					char* name = malloc(strlen("_func") + 4);
					strcpy(name, "_func");
					sprintf(&name[5], "%d", current_name);
					current_function_name = strdup(name);
					(yyval.my_entry) = get_function_entry(current_function_name, scope);
					
					
					open_anon_functions--;
					/* kanw null ti lista etsi oste ta arguments tis sinartisis
					na min ta paroun oi epomenes sinartiseis*/
					argument_list_head = NULL;
					formal_argument_count = 0;

					expr func_expr = calloc(sizeof(struct expr), sizeof(struct expr));
					func_expr->type = constint_e;
					func_expr->strConst = strdup(last_function_created->value.funcVal->name);
					func_expr->sym = look_up(func_expr->strConst, scope);
					create_quad(funcend, func_expr, true_expression, true_expression);
					function_list_remove_last();
					se_ti_loop_eimai = 0;
					(yyval.my_entry) = get_function_entry(func_expr->strConst, scope);

				}
#line 2924 "parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1196 "parser.y" /* yacc.c:1646  */
    {
				only_term ++;
				(yyval.my_expr) = (expr) calloc(sizeof(struct expr), sizeof(struct expr));
				(yyval.my_expr)->type = constint_e;
				(yyval.my_expr)->const_int = (yyvsp[0].int_val);
				printf(BLUE "%d -> " RESET, (yyvsp[0].int_val));
			}
#line 2936 "parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1204 "parser.y" /* yacc.c:1646  */
    {only_term ++;
				(yyval.my_expr) = (expr) calloc(sizeof(struct expr), sizeof(struct expr));
				(yyval.my_expr)->type = constdouble_e;
				(yyval.my_expr)->const_double = (yyvsp[0].real_val);
				printf(BLUE "%f -> " RESET, (yyvsp[0].real_val));
			}
#line 2947 "parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1211 "parser.y" /* yacc.c:1646  */
    {only_term ++;
				(yyval.my_expr) = (expr) calloc(sizeof(struct expr), sizeof(struct expr));
				(yyval.my_expr)->type = conststring_e;
				(yyval.my_expr)->strConst = strdup((yyvsp[0].str));
				printf(BLUE "%s -> " RESET, (yyvsp[0].str));
			}
#line 2958 "parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1218 "parser.y" /* yacc.c:1646  */
    {only_term ++;
				(yyval.my_expr) = (expr) calloc(sizeof(struct expr), sizeof(struct expr));
				(yyval.my_expr)->type = nil_e;
				printf(BLUE "NIL -> " RESET);
			}
#line 2968 "parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1224 "parser.y" /* yacc.c:1646  */
    {	only_term ++;
				(yyval.my_expr) = (expr) calloc(sizeof(struct expr), sizeof(struct expr));
				(yyval.my_expr)->type = constbool_e;
				(yyval.my_expr)->boolConst = 1;
				
				printf(BLUE "TRUE -> " RESET);
			}
#line 2980 "parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1232 "parser.y" /* yacc.c:1646  */
    {only_term ++;
				(yyval.my_expr) = (expr) calloc(sizeof(struct expr), sizeof(struct expr));
				(yyval.my_expr)->type = constbool_e;
				(yyval.my_expr)->boolConst = 0;
				printf(BLUE "FALSE -> " RESET);
			}
#line 2991 "parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1241 "parser.y" /* yacc.c:1646  */
    {
				(yyval.str) = (yyvsp[0].str);
				//argument_list_head = insert_new_argument(argument_list_head, $1);
				/* prepei na diasxisw oli ti lista me ta arguments kai na eleksw an einai valid */
				entry scope_node;
				if(current_function_name != NULL && function_arguments_valid((yyvsp[0].str), scope + 1) == 1){
					//function_arguments_valid(scope_node, scope);
					/* *********************************************************************/
					/* vriskw to function node p molis dimiourgisa gia na tou			   */
					/* valw ti lista me ta arguments pou vrika apo to idlist, to insertion */
					/* sti lista ginetai ston kanona tou idlist							   */
					/***********************************************************************/
					scope_node = Scope_List_Contains_Symbol(current_function_name, scope);
					if(scope_node != NULL){
						printf(YELLOW"ARGUMENT %s\n"RESET, (yyvsp[0].str));
						/**************************************************************/
						/* i lista twn argument vrisketai sto struct function,	      */
						/* kserw sigoura pws to node m einai function opote apla kanw */
						/* access kai vazw ti lista 								  */
						/**************************************************************/
						SymTable_put(Symbol_Table, (yyvsp[0].str), yylineno, scope + 1, assign_counter, 2);
						formal_argument_count++;
					}	
				}
					/* dimiourgw ta params gia tin function !! */
					/* edw tha kanw to neo quad gia to parameter , px f(a, b) */
				if(se_ti_loop_eimai == 0){
					last_param_created->type = param;
					last_param_created->strConst = strdup((yyvsp[0].str));

					//create_quad(param, last_param_created, true_expression, true_expression);
				}
				
				printf("%s \n", (yyvsp[0].str));
				}
#line 3031 "parser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1277 "parser.y" /* yacc.c:1646  */
    {

					//argument_list_head = insert_new_argument(argument_list_head, $3);
					/* prepei na diasxisw oli ti lista me ta arguments kai na eleksw an einai valid */
					entry scope_node;

				if(current_function_name != NULL && function_arguments_valid((yyvsp[0].str), scope + 1) == 1){
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
						SymTable_put(Symbol_Table, (yyvsp[0].str), yylineno, scope + 1, assign_counter, 2);

					
					formal_argument_count++;
					}	
				}	

					/* dimiourgw ta params gia tin function !! */
					/* edw tha kanw to neo quad gia to parameter , px f(a, b) */
					if(se_ti_loop_eimai == 0)
					{
						last_param_created->type = param;
						last_param_created->strConst = strdup((yyvsp[0].str));
						//create_quad(param, last_param_created, true_expression, true_expression);
					}
					printf("%s \n", (yyvsp[0].str));
				}
#line 3073 "parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1314 "parser.y" /* yacc.c:1646  */
    {printf(BLUE "Empty idlist\n" RESET);}
#line 3079 "parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1318 "parser.y" /* yacc.c:1646  */
    {stop_writing_if_quad++;}
#line 3085 "parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1319 "parser.y" /* yacc.c:1646  */
    {
					
					create_quad(if_eq, (yyvsp[-1].my_expr), true_expression, true_expression);
					(yyval.int_val) = quad_counter;
					create_quad(jump, true_expression, true_expression, true_expression);
				}
#line 3096 "parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1327 "parser.y" /* yacc.c:1646  */
    {
					
					(yyval.int_val) = quad_counter;
					create_quad(jump, true_expression, true_expression, true_expression);
				}
#line 3106 "parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1336 "parser.y" /* yacc.c:1646  */
    {
				quad_struct_get(&quad_table, (yyvsp[-1].int_val))->label = quad_counter;
				stop_writing_if_quad--;
}
#line 3115 "parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1346 "parser.y" /* yacc.c:1646  */
    {
					quad_struct_get(&quad_table, (yyvsp[-3].int_val))->label = (yyvsp[-1].int_val) + 1;
					quad_struct_get(&quad_table, (yyvsp[-1].int_val))->label = quad_counter;

					 {stop_writing_if_quad--;}
				}
#line 3126 "parser.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1354 "parser.y" /* yacc.c:1646  */
    {
					insert_loop(0);
					
					stop_writing_if_quad++;
					insert_last_index_while_start();


					/* patching gia continue */
					while_counter++;
					insert_continue_index_while();
				}
#line 3142 "parser.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1369 "parser.y" /* yacc.c:1646  */
    {
							create_quad(if_eq, (yyvsp[0].my_expr), true_expression, true_expression);
							create_quad(jump, true_expression, true_expression, true_expression);
							insert_last_jump_while();	
							
						}
#line 3153 "parser.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1375 "parser.y" /* yacc.c:1646  */
    {eimai_se_loop++;}
#line 3159 "parser.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1375 "parser.y" /* yacc.c:1646  */
    {eimai_se_loop--;}
#line 3165 "parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1376 "parser.y" /* yacc.c:1646  */
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
#line 3188 "parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1396 "parser.y" /* yacc.c:1646  */
    { se_ti_loop_eimai = 1;}
#line 3194 "parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1397 "parser.y" /* yacc.c:1646  */
    {
					

						insert_loop(1);
						for_counter++;
						insert_last_index_for_start();
						
						stop_writing_if_quad++;
						
					}
#line 3209 "parser.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1410 "parser.y" /* yacc.c:1646  */
    {
						create_quad(if_eq, (yyvsp[0].my_expr), true_expression, true_expression);
						/* edw paizei lathos */
						patcharw_for_2o_elist = quad_table.size - 1;
						
						create_quad(jump, true_expression, true_expression, true_expression);
						
						insert_last_jump_for();
					}
#line 3223 "parser.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1420 "parser.y" /* yacc.c:1646  */
    {
					insert_last_index_for_elist();
					insert_continue_index_for();
				}
#line 3232 "parser.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1425 "parser.y" /* yacc.c:1646  */
    {
						quad_struct_get(&quad_table, patcharw_for_2o_elist)->label = quad_counter +1;
						create_quad(jump, true_expression, true_expression, true_expression);
						insert_last_jump_for_end();
						
						
					}
#line 3244 "parser.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1432 "parser.y" /* yacc.c:1646  */
    {eimai_se_loop++;}
#line 3250 "parser.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1432 "parser.y" /* yacc.c:1646  */
    {eimai_se_loop--;}
#line 3256 "parser.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1433 "parser.y" /* yacc.c:1646  */
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
#line 3283 "parser.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1458 "parser.y" /* yacc.c:1646  */
    {
				expr p = calloc(sizeof(struct expr), sizeof(struct expr));
				p->strConst = strdup(";");
				p->type = conststring_e;
				calculate_expr(ret, p, true_expression);
				printf(BLUE "return ; \n" RESET);
				create_quad(jump, true_expression, true_expression, true_expression);

				

			}
#line 3299 "parser.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1470 "parser.y" /* yacc.c:1646  */
    {

				calculate_expr(ret, (yyvsp[-1].my_expr), true_expression);
				printf(BLUE "return expr ; \n" RESET);
				create_quad(jump, true_expression, true_expression, true_expression);

			}
#line 3311 "parser.c" /* yacc.c:1646  */
    break;


#line 3315 "parser.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1480 "parser.y" /* yacc.c:1906  */


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
	int i;
	f = fopen("quad.txt", "w");
	fclose(f);

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
	

	/* 4 pinakes dinamikwn dedomenwn */
	table_init(&string_array);
	table_init(&num_array);
	table_init(&userfunc_array);
	table_init(&libfunc_array);
	table_init(&instruction_array);
	table_init(&incomplete_jumps_target_array);
	table_init(&incomplete_jumps_functions);
	table_init(&patch_jump_functions);
	table_init(&return_incomplete_jumps_array);
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

	for(i = 0; i < SYSTEM_FUNCTION_SIZE; i ++){
		scope_offset = 0;
		SymTable_put(Symbol_Table, system_functions[i], yylineno, 0, assign_counter, 0);
	}
	scope_offset = 0;
	yyin = stdin;	
	yyparse();


	





	return 0;
}


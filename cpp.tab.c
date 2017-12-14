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
#line 1 "cpp.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "types.h"
#include "st.h"
#include "tree.h"

// stuff from flex that bison needs to know about:
//extern "C" int yylex();
//extern "C" int yyparse();
//extern "C" FILE *yyin;

extern FILE *yyin;
extern FILE *yyout;
extern int yylex(void);
extern int yyparse(void);

void yyerror(const char *s);

#line 87 "cpp.tab.c" /* yacc.c:339  */

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
   by #include "cpp.tab.h".  */
#ifndef YY_YY_CPP_TAB_H_INCLUDED
# define YY_YY_CPP_TAB_H_INCLUDED
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
    INT = 258,
    FLOAT = 259,
    STRING = 260,
    BOOL = 261,
    H_CHAR = 262,
    Q_CHAR = 263,
    C_CHAR = 264,
    IDENTIFIER = 265,
    ZERO = 266,
    CLASS = 267,
    PUBLIC = 268,
    PRIVATE = 269,
    NEW = 270,
    DOUBLEKW = 271,
    CHARKW = 272,
    VOIDKW = 273,
    BOOLKW = 274,
    IF = 275,
    FOR = 276,
    CONST = 277,
    USING = 278,
    NAMESPACE = 279,
    AND = 280,
    OR = 281,
    BITWISE_AND = 282,
    BITWISE_OR = 283,
    BITWISE_XOR = 284,
    LESS_OR_EQUAL_THAN = 285,
    GREATER_OR_EQUAL_THAN = 286,
    LESS_THAN = 287,
    GREATER_THAN = 288,
    EQUAL = 289,
    NOT_EQUAL = 290,
    ASSIGNMENT = 291,
    ADDITION = 292,
    SUBTRACTION = 293,
    MULTIPLICATION = 294,
    DIVISION = 295,
    MODULO = 296,
    INCREMENT = 297,
    DECREMENT = 298,
    ADDITION_EQUAL = 299,
    SUBTRACTION_EQUAL = 300,
    MULTIPLICATION_EQUAL = 301,
    DIVISION_EQUAL = 302,
    MODULO_EQUAL = 303,
    AND_EQUAL = 304,
    OR_EQUAL = 305,
    XOR_EQUAL = 306,
    LEFT_SHIFT_EQUAL = 307,
    RIGHT_SHIFT_EQUAL = 308,
    OBJECT_ACCESS = 309,
    POINTER_ACCESS = 310,
    COLON = 311,
    TERNARY = 312,
    DOUBLE_COLON = 313,
    SEMI_COLON = 314,
    LEFT_SHIFT = 315,
    RIGHT_SHIFT = 316,
    CHARACTER = 317,
    OPEN_PARENTHESES = 318,
    CLOSE_PARENTHESES = 319,
    OPEN_BRACE = 320,
    CLOSE_BRACE = 321,
    OPEN_BRACKET = 322,
    CLOSE_BRACKET = 323,
    DOUBLEP = 324,
    CHARP = 325,
    VOIDP = 326,
    POINTERID = 327,
    DEPOINTERID = 328,
    RETURN = 329,
    COMMA = 330,
    ELSE = 331,
    TRUE = 332,
    FALSE = 333,
    THIS = 334,
    NOT = 335,
    DIRECTIVE = 336,
    INTKW = 337,
    INTP = 338,
    BOOLP = 339,
    SINGLE_QUOTE = 340,
    DOUBLE_QUOTE = 341,
    ESCAPE_SEQUENCE = 342
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 27 "cpp.y" /* yacc.c:355  */

	int ival;
	float fval;
	char *sval;
	char cval;
	struct Sym* sym;
	struct Node* node;

#line 224 "cpp.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CPP_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 241 "cpp.tab.c" /* yacc.c:358  */

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
#define YYFINAL  19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   635

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  91
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  79
/* YYNRULES -- Number of rules.  */
#define YYNRULES  173
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  270

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   345

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   167,   187,   211,   217,   225,   231,   239,   248,   257,
     266,   276,   287,   293,   297,   298,   304,   309,   314,   368,
     377,   379,   382,   405,   414,   427,   431,   448,   451,   454,
     499,   502,   504,   506,   508,   512,   515,   523,   530,   542,
     554,   558,   561,   571,   574,   618,   661,   682,   685,   728,
     773,   776,   791,   808,   811,   854,   897,   940,   985,   988,
    1031,  1076,  1079,  1100,  1103,  1124,  1127,  1148,  1151,  1196,
    1199,  1244,  1250,  1253,  1299,  1300,  1301,  1302,  1303,  1304,
    1305,  1306,  1307,  1308,  1309,  1312,  1315,  1321,  1325,  1326,
    1328,  1330,  1332,  1334,  1338,  1342,  1343,  1346,  1348,  1351,
    1352,  1355,  1358,  1382,  1389,  1410,  1415,  1418,  1419,  1422,
    1423,  1429,  1430,  1474,  1475,  1478,  1483,  1486,  1492,  1495,
    1506,  1507,  1518,  1519,  1522,  1523,  1524,  1525,  1528,  1531,
    1534,  1537,  1540,  1547,  1550,  1550,  1599,  1602,  1610,  1614,
    1622,  1636,  1642,  1652,  1670,  1680,  1683,  1689,  1692,  1698,
    1718,  1725,  1728,  1734,  1735,  1736,  1739,  1740,  1746,  1749,
    1752,  1755,  1756,  1757,  1760,  1761,  1765,  1767,  1768,  1771,
    1772,  1775,  1776,  1780
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "STRING", "BOOL",
  "H_CHAR", "Q_CHAR", "C_CHAR", "IDENTIFIER", "ZERO", "CLASS", "PUBLIC",
  "PRIVATE", "NEW", "DOUBLEKW", "CHARKW", "VOIDKW", "BOOLKW", "IF", "FOR",
  "CONST", "USING", "NAMESPACE", "AND", "OR", "BITWISE_AND", "BITWISE_OR",
  "BITWISE_XOR", "LESS_OR_EQUAL_THAN", "GREATER_OR_EQUAL_THAN",
  "LESS_THAN", "GREATER_THAN", "EQUAL", "NOT_EQUAL", "ASSIGNMENT",
  "ADDITION", "SUBTRACTION", "MULTIPLICATION", "DIVISION", "MODULO",
  "INCREMENT", "DECREMENT", "ADDITION_EQUAL", "SUBTRACTION_EQUAL",
  "MULTIPLICATION_EQUAL", "DIVISION_EQUAL", "MODULO_EQUAL", "AND_EQUAL",
  "OR_EQUAL", "XOR_EQUAL", "LEFT_SHIFT_EQUAL", "RIGHT_SHIFT_EQUAL",
  "OBJECT_ACCESS", "POINTER_ACCESS", "COLON", "TERNARY", "DOUBLE_COLON",
  "SEMI_COLON", "LEFT_SHIFT", "RIGHT_SHIFT", "CHARACTER",
  "OPEN_PARENTHESES", "CLOSE_PARENTHESES", "OPEN_BRACE", "CLOSE_BRACE",
  "OPEN_BRACKET", "CLOSE_BRACKET", "DOUBLEP", "CHARP", "VOIDP",
  "POINTERID", "DEPOINTERID", "RETURN", "COMMA", "ELSE", "TRUE", "FALSE",
  "THIS", "NOT", "DIRECTIVE", "INTKW", "INTP", "BOOLP", "SINGLE_QUOTE",
  "DOUBLE_QUOTE", "ESCAPE_SEQUENCE", "\".\"", "\"->\"", "\"0\"", "$accept",
  "identifier", "open_brace", "close_brace", "open_parentheses",
  "close_parentheses", "literal", "integer_literal", "character_literal",
  "c_char_sequence", "floating_literal", "string_literal",
  "boolean_literal", "primary_expression", "id_expression",
  "unqualified_id", "postfix_expression", "expression_list",
  "unary_expression", "new_expression", "new_type_id",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "statement", "expression_statement",
  "compound_statement", "statement_seq.opt", "selection_statement",
  "condition", "iteration_statement", "jump_statement",
  "declaration_statement", "translation_unit", "declaration_seq",
  "declaration", "simple_declaration", "init_declarator_list",
  "init_declarator", "initializer.opt", "type_specifier_seq",
  "type_specifier", "simple_type_specifier", "elaborated_type_specifier",
  "function_definition", "$@1", "function_body", "declarator",
  "direct_declarator", "parameters_and_qualifiers",
  "parameter_declaration_clause.opt", "parameter_declaration_list",
  "parameter_declaration", "ptr_operator", "cv_qualifier", "declarator_id",
  "initializer_clause", "initializer_list", "class_specifier",
  "class_head", "class_key", "member_specification.opt",
  "access_specifier", "member_declaration", "member_declarator_list",
  "member_declarator", "pure_specifier", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345
};
# endif

#define YYPACT_NINF -176

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-176)))

#define YYTABLE_NINF -160

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      27,  -176,  -176,  -176,  -176,  -176,  -176,  -176,    30,    27,
    -176,  -176,    23,    23,  -176,     2,    37,    -4,    42,  -176,
    -176,  -176,  -176,  -176,  -176,  -176,    35,  -176,   -10,    62,
      23,  -176,    43,    18,    23,  -176,    49,  -176,    54,    10,
    -176,    23,   199,   169,  -176,    40,  -176,   479,     2,  -176,
    -176,  -176,    52,  -176,  -176,  -176,    23,     6,    41,    64,
      54,  -176,  -176,  -176,  -176,  -176,    27,   169,   169,   169,
    -176,   128,   450,  -176,  -176,  -176,  -176,  -176,  -176,  -176,
    -176,    56,  -176,  -176,   157,    97,    98,   196,   147,   134,
     137,   135,   152,   102,  -176,  -176,   126,  -176,    -6,  -176,
     255,  -176,  -176,   165,  -176,   138,    42,   146,   148,  -176,
    -176,    -2,    57,  -176,  -176,  -176,  -176,    54,  -176,  -176,
    -176,    27,  -176,  -176,  -176,  -176,  -176,  -176,  -176,    39,
    -176,     7,  -176,  -176,   149,  -176,  -176,   533,   169,    42,
      42,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,  -176,
    -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,
     169,   550,  -176,   169,   150,   159,  -176,   169,   284,    67,
    -176,  -176,  -176,   367,  -176,  -176,  -176,  -176,  -176,    14,
    -176,  -176,  -176,  -176,     2,   140,  -176,  -176,    23,  -176,
    -176,  -176,   169,  -176,  -176,   450,  -176,    92,     8,  -176,
    -176,  -176,  -176,  -176,   157,   157,    97,    97,    98,    98,
      98,    98,   196,   196,   147,   134,   137,   135,   152,  -176,
    -176,    93,  -176,   169,   169,   101,  -176,   284,  -176,  -176,
    -176,  -176,  -176,   195,  -176,  -176,  -176,  -176,  -176,  -176,
    -176,   160,   174,    17,   180,  -176,  -176,   396,   204,   169,
     171,   169,   105,   396,  -176,   169,  -176,   146,   396,  -176
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   160,   131,   128,   132,   129,   151,   130,     0,   106,
     107,   109,     0,     0,   110,     0,     0,     0,     0,     1,
     108,     2,   150,    24,   152,    23,     0,   116,   118,   138,
       0,   140,     0,   118,     0,   115,     0,     3,   161,   133,
     112,     0,     0,     0,   119,     0,     5,     0,   145,   141,
     139,   113,     0,   114,   164,   165,     0,   168,     0,     0,
     161,   117,    12,    16,    17,    18,     0,     0,     0,     0,
      20,     0,     0,    19,     7,     8,     9,    10,    11,    25,
      22,    37,    43,    40,    47,    50,    53,    58,    61,    63,
      65,    67,    69,    71,    72,   153,     0,   120,     0,    35,
       0,   135,   143,    71,    87,     0,     0,     0,   146,   147,
     111,   171,     0,   169,   167,     4,   158,   161,   162,    41,
      42,   122,   124,   125,   126,   127,    38,    39,    85,     0,
      14,     0,   155,   156,     0,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    74,
      78,    79,    75,    76,    77,    82,    84,    83,    81,    80,
       0,     0,   121,     0,     0,     0,   136,     0,     0,     0,
      97,    88,    89,     0,    90,    91,    93,    92,   105,     0,
     142,   149,     6,   144,     0,     0,   172,   166,     0,   163,
     123,    21,     0,    15,    13,     0,    30,     0,     0,    33,
      34,    44,    45,    46,    48,    49,    51,    52,    56,    57,
      54,    55,    59,    60,    62,    64,    66,    68,    70,    73,
      27,     0,    36,     0,     0,     0,    95,     0,    94,   137,
      98,   148,   173,   171,   170,    86,   154,   157,    29,    26,
      28,   101,     0,     0,     0,   104,    96,     0,     0,     0,
      99,     0,     0,     0,   102,     0,   100,     0,     0,   103
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -176,   -17,   -13,   -66,    74,   -15,  -176,  -176,  -176,  -176,
    -176,  -176,  -176,  -176,     1,  -176,  -176,   -81,   -56,  -176,
    -176,    63,    73,    95,    48,    96,   100,   110,    99,   111,
     206,   232,   -40,  -176,   -64,  -176,  -175,  -176,  -176,   104,
    -176,    46,  -176,  -176,  -176,  -176,  -176,   274,    28,    88,
     244,  -176,   170,  -176,     0,   -43,   106,  -176,  -176,    -5,
    -176,  -176,  -176,  -176,   113,  -176,   -30,  -176,   -62,  -176,
     -26,  -176,  -176,   -38,  -176,  -176,  -176,    94,  -176
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    23,   178,   116,    48,   193,    73,    74,    75,   131,
      76,    77,    78,    79,    80,    25,    81,    98,    82,    83,
     119,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,   128,   170,   179,   105,   180,   181,   182,   183,
     184,   252,   185,   186,   187,     8,     9,    10,   188,    26,
      27,    44,   120,   121,    96,    13,    57,    45,   101,    33,
      29,    49,   107,   108,   109,    30,    15,    31,    97,   134,
      16,    17,    18,    58,    59,    60,   112,   113,   196
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      12,    39,    95,    99,    38,   129,   132,    28,   240,    12,
     133,   126,   127,    24,    24,    34,   203,    24,     2,     3,
       4,     5,   118,   123,    21,    50,    42,    21,    11,    72,
      19,    24,    95,    21,   195,    24,   124,    11,    56,     1,
     125,    22,    24,     2,     3,     4,     5,    21,   106,     6,
      22,   111,    21,    43,    42,  -134,   207,    24,   172,    72,
      56,    37,   240,  -134,    22,   114,   122,    54,    55,   173,
       2,     3,     4,     5,   208,  -159,   249,   171,   123,   199,
     171,    43,   260,   202,     7,   211,   212,   213,   266,   191,
     231,   124,   204,   269,    40,   125,    35,    99,   135,   136,
     189,    32,    51,   201,    36,   100,    14,   115,    53,     7,
      41,   110,   236,   235,   202,    14,   197,    56,    41,   137,
     117,   122,    52,   138,    41,    46,   238,    41,   158,    47,
     229,    99,   198,   232,   144,   145,     7,   130,   159,   246,
     209,   210,   202,   247,   139,   140,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   248,   250,   146,   147,
     255,   154,   245,   156,   265,    95,   155,   173,   173,   251,
     251,   256,    62,    63,    64,    65,   202,   157,   189,    21,
     202,   152,   153,   189,    66,     2,     3,     4,     5,   171,
      24,   158,    72,   243,   106,   262,   141,   142,   143,    24,
     222,   223,    62,    63,    64,    65,   190,   214,   215,    21,
     192,    67,    68,   233,    66,     2,     3,     4,     5,   216,
     217,   264,    46,   194,   205,   267,   148,   149,   150,   151,
     242,   195,    69,   253,   253,   202,   258,   189,   257,   259,
     261,    67,    68,   218,   219,   220,   221,   263,    70,   234,
     224,     7,   268,   103,    71,   225,   227,   189,    62,    63,
      64,    65,    69,   189,    37,    21,   226,     1,   189,   228,
      66,     2,     3,     4,     5,   174,   175,     6,    70,   104,
     254,     7,   237,    20,    71,    61,     0,    62,    63,    64,
      65,   200,   244,     0,    21,     0,     1,    67,    68,    66,
       2,     3,     4,     5,   174,   175,     6,   241,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    69,     0,
      37,   176,     0,     0,     0,     0,    67,    68,     0,   177,
       0,     0,     0,     0,    70,     0,     0,     7,     0,     0,
      71,     0,     0,     0,     0,     0,     0,    69,     0,    37,
     115,     0,     0,     0,     0,     0,     0,     0,   177,     0,
       0,     0,     0,    70,     0,     0,     7,     0,     0,    71,
      62,    63,    64,    65,     0,     0,     0,    21,     0,     1,
       0,     0,    66,     2,     3,     4,     5,   174,   175,     6,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    62,
      63,    64,    65,     0,     0,     0,    21,     0,     1,    67,
      68,    66,     2,     3,     4,     5,   174,   175,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      69,     0,    37,   239,     0,     0,     0,     0,    67,    68,
       0,   177,     0,     0,     0,     0,    70,     0,     0,     7,
       0,     0,    71,    62,    63,    64,    65,     0,     0,    69,
      21,    37,     0,     0,     0,    66,     2,     3,     4,     5,
     177,     0,     0,     0,     0,    70,     0,     0,     7,     0,
       0,    71,    62,    63,    64,    65,     0,     0,     0,    21,
       0,     0,    67,    68,    66,     2,     3,     4,     5,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    69,     0,    37,   115,     0,     0,     0,
       0,    67,    68,     0,     0,     0,     0,     0,     0,    70,
       0,     0,     7,     0,     0,    71,    62,    63,    64,    65,
       0,     0,    69,    21,     0,     0,     0,   102,    66,     2,
       3,     4,     5,    62,    63,    64,    65,     0,    70,     0,
      21,     7,     0,     0,    71,    66,     2,     3,     4,     5,
       0,     0,     0,     0,     0,    67,    68,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    67,    68,     0,     0,    69,   206,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    70,    69,   230,     7,     0,     0,    71,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    70,
       0,     0,     7,     0,     0,    71
};

static const yytype_int16 yycheck[] =
{
       0,    18,    42,    43,    17,    69,    72,    12,   183,     9,
      72,    67,    68,    12,    13,    15,     9,    16,    16,    17,
      18,    19,    60,    66,    10,    30,    36,    10,     0,    42,
       0,    30,    72,    10,    36,    34,    66,     9,    38,    12,
      66,    27,    41,    16,    17,    18,    19,    10,    48,    22,
      27,    56,    10,    63,    36,    65,   137,    56,    64,    72,
      60,    65,   237,    65,    27,    59,    66,    13,    14,    75,
      16,    17,    18,    19,   138,    65,    68,    63,   121,   117,
      63,    63,   257,    75,    82,   141,   142,   143,   263,   106,
     171,   121,    85,   268,    59,   121,    59,   137,    42,    43,
     100,    13,    59,    64,    16,    65,     0,    66,    59,    82,
      75,    59,   178,   177,    75,     9,    59,   117,    75,    63,
      56,   121,    34,    67,    75,    63,    59,    75,    26,    67,
     170,   171,    75,   173,    37,    38,    82,     9,    36,   205,
     139,   140,    75,   205,    88,    89,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    64,    64,    60,    61,
      59,    27,   202,    28,    59,   205,    29,    75,    75,   233,
     234,   237,     3,     4,     5,     6,    75,    25,   178,    10,
      75,    34,    35,   183,    15,    16,    17,    18,    19,    63,
     189,    26,   205,   198,   194,   259,    39,    40,    41,   198,
     152,   153,     3,     4,     5,     6,    68,   144,   145,    10,
      64,    42,    43,    63,    15,    16,    17,    18,    19,   146,
     147,   261,    63,    75,    75,   265,    30,    31,    32,    33,
      90,    36,    63,   233,   234,    75,   253,   237,    64,    59,
      36,    42,    43,   148,   149,   150,   151,    76,    79,   175,
     154,    82,   267,    47,    85,   155,   157,   257,     3,     4,
       5,     6,    63,   263,    65,    10,   156,    12,   268,   158,
      15,    16,    17,    18,    19,    20,    21,    22,    79,    47,
     234,    82,   178,     9,    85,    41,    -1,     3,     4,     5,
       6,   121,   198,    -1,    10,    -1,    12,    42,    43,    15,
      16,    17,    18,    19,    20,    21,    22,   194,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,
      65,    66,    -1,    -1,    -1,    -1,    42,    43,    -1,    74,
      -1,    -1,    -1,    -1,    79,    -1,    -1,    82,    -1,    -1,
      85,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,    65,
      66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    -1,
      -1,    -1,    -1,    79,    -1,    -1,    82,    -1,    -1,    85,
       3,     4,     5,     6,    -1,    -1,    -1,    10,    -1,    12,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,    -1,    -1,    -1,    10,    -1,    12,    42,
      43,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    -1,    65,    66,    -1,    -1,    -1,    -1,    42,    43,
      -1,    74,    -1,    -1,    -1,    -1,    79,    -1,    -1,    82,
      -1,    -1,    85,     3,     4,     5,     6,    -1,    -1,    63,
      10,    65,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      74,    -1,    -1,    -1,    -1,    79,    -1,    -1,    82,    -1,
      -1,    85,     3,     4,     5,     6,    -1,    -1,    -1,    10,
      -1,    -1,    42,    43,    15,    16,    17,    18,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    -1,    65,    66,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    79,
      -1,    -1,    82,    -1,    -1,    85,     3,     4,     5,     6,
      -1,    -1,    63,    10,    -1,    -1,    -1,    68,    15,    16,
      17,    18,    19,     3,     4,     5,     6,    -1,    79,    -1,
      10,    82,    -1,    -1,    85,    15,    16,    17,    18,    19,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    79,    63,    64,    82,    -1,    -1,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,
      -1,    -1,    82,    -1,    -1,    85
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    16,    17,    18,    19,    22,    82,   136,   137,
     138,   139,   145,   146,   147,   157,   161,   162,   163,     0,
     138,    10,    27,    92,   105,   106,   140,   141,   150,   151,
     156,   158,   140,   150,   145,    59,   140,    65,    93,    92,
      59,    75,    36,    63,   142,   148,    63,    67,    95,   152,
     150,    59,   140,    59,    13,    14,   145,   147,   164,   165,
     166,   141,     3,     4,     5,     6,    15,    42,    43,    63,
      79,    85,    93,    97,    98,    99,   101,   102,   103,   104,
     105,   107,   109,   110,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   145,   159,   108,   123,
      65,   149,    68,   121,   122,   126,   145,   153,   154,   155,
      59,   150,   167,   168,    59,    66,    94,    56,   164,   111,
     143,   144,   145,   146,   157,   161,   109,   109,   123,   125,
       9,   100,    94,   159,   160,    42,    43,    63,    67,    88,
      89,    39,    40,    41,    37,    38,    60,    61,    30,    31,
      32,    33,    34,    35,    27,    29,    28,    25,    26,    36,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
     124,    63,    64,    75,    20,    21,    66,    74,    93,   125,
     127,   128,   129,   130,   131,   133,   134,   135,   139,   145,
      68,    92,    64,    96,    75,    36,   169,    59,    75,   164,
     143,    64,    75,     9,    85,    75,    64,   108,   125,   105,
     105,   109,   109,   109,   112,   112,   113,   113,   114,   114,
     114,   114,   115,   115,   116,   117,   118,   119,   120,   123,
      64,   108,   123,    63,    95,   125,    94,   130,    59,    66,
     127,   155,    90,   150,   168,   123,    94,   159,    64,    68,
      64,   125,   132,   145,   132,    59,    94,    64,    92,    59,
     127,    36,   125,    76,   123,    59,   127,   123,    96,   127
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    91,    92,    93,    94,    95,    96,    97,    97,    97,
      97,    97,    98,    99,   100,   100,   101,   102,   103,   104,
     104,   104,   104,   105,   106,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   108,   108,   109,   109,   109,
     109,   110,   111,   112,   112,   112,   112,   113,   113,   113,
     114,   114,   114,   115,   115,   115,   115,   115,   116,   116,
     116,   117,   117,   118,   118,   119,   119,   120,   120,   121,
     121,   122,   123,   123,   124,   124,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   125,   125,   126,   127,   127,
     127,   127,   127,   127,   128,   129,   129,   130,   130,   131,
     131,   132,   132,   133,   134,   135,   136,   137,   137,   138,
     138,   139,   139,   139,   139,   139,   140,   140,   141,   141,
     142,   142,   143,   143,   144,   144,   144,   144,   145,   145,
     145,   145,   145,   146,   148,   147,   149,   149,   150,   150,
     151,   151,   151,   151,   152,   153,   153,   154,   154,   155,
     156,   157,   158,   159,   159,   159,   160,   160,   161,   162,
     163,   164,   164,   164,   165,   165,   166,   166,   166,   167,
     167,   168,   168,   169
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     2,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     4,     3,     4,     4,
       3,     2,     2,     3,     3,     1,     3,     1,     2,     2,
       1,     2,     1,     1,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     3,     1,     2,     5,
       7,     1,     4,     9,     3,     1,     1,     1,     2,     1,
       1,     4,     3,     3,     3,     2,     1,     3,     1,     2,
       2,     3,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     0,     4,     2,     3,     1,     2,
       1,     2,     4,     3,     3,     0,     1,     1,     3,     2,
       1,     1,     1,     1,     4,     2,     1,     3,     4,     2,
       1,     0,     2,     3,     1,     1,     3,     2,     1,     1,
       3,     1,     2,     2
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
#line 187 "cpp.y" /* yacc.c:1646  */
    {
		printf("Identifier: %s\n", (yyvsp[0].sval));
		strcpy((yyval.sval), (yyvsp[0].sval));		
	}
#line 1637 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 211 "cpp.y" /* yacc.c:1646  */
    { 
		printf("Creating scope with depth %d\n", cur_scope->depth + 1);
		create_scope();
	}
#line 1646 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 217 "cpp.y" /* yacc.c:1646  */
    { 
		printf("Deleting scope with depth %d\n", cur_scope->depth);
		if (!cur_scope->prev) {
			fprintf(stderr, "WARNING (close brace)\n");
		} else delete_scope();
	}
#line 1657 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 225 "cpp.y" /* yacc.c:1646  */
    { 
		printf("Creating scope with depth %d\n", cur_scope->depth + 1);
		create_scope();
	}
#line 1666 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 231 "cpp.y" /* yacc.c:1646  */
    { 
		printf("Deleting scope with depth %d\n", cur_scope->depth);
		if (!cur_scope->prev) {
			fprintf(stderr, "WARNING (close parentheses)\n");
		} else delete_scope();
	}
#line 1677 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 239 "cpp.y" /* yacc.c:1646  */
    {
		struct Literal* lit = (struct Literal*) malloc(sizeof(struct Literal));
		lit->ival = (yyvsp[0].ival);
		lit->literal_type = INTEGER_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		node->literal_expression = lit;
		node->type = INTEGER_T;
		(yyval.node) = node;
	}
#line 1691 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 248 "cpp.y" /* yacc.c:1646  */
    {
		struct Literal* lit = (struct Literal*) malloc(sizeof(struct Literal));
		lit->cval = (yyvsp[0].cval);
		lit->literal_type = CHAR_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		node->literal_expression = lit;
		node->type = CHAR_T;
		(yyval.node) = node;
	}
#line 1705 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 257 "cpp.y" /* yacc.c:1646  */
    {
		struct Literal* lit = (struct Literal*) malloc(sizeof(struct Literal));
		lit->fval = (yyvsp[0].fval);
		lit->literal_type = DOUBLE_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		node->literal_expression = lit;
		node->type = DOUBLE_T;
		(yyval.node) = node;
	}
#line 1719 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 266 "cpp.y" /* yacc.c:1646  */
    {
		printf("string literal detected\n");
		struct Literal* lit = (struct Literal*) malloc(sizeof(struct Literal));
		strcpy(lit->sval, (yyvsp[0].sval));
		lit->literal_type = STRING_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		node->literal_expression = lit;
		node->type = STRING_T;
		(yyval.node) = node;
	}
#line 1734 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 276 "cpp.y" /* yacc.c:1646  */
    {
		struct Literal* lit = (struct Literal*) malloc(sizeof(struct Literal));
		lit->ival = (yyvsp[0].ival);
		lit->literal_type = BOOL_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		node->literal_expression = lit;
		node->type = BOOL_T;
		(yyval.node) = node;
	}
#line 1748 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 287 "cpp.y" /* yacc.c:1646  */
    {
		(yyval.ival) = (yyvsp[0].ival);
	}
#line 1756 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 304 "cpp.y" /* yacc.c:1646  */
    {
		(yyval.fval) = (yyvsp[0].fval);
	}
#line 1764 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 309 "cpp.y" /* yacc.c:1646  */
    {
		strcpy((yyval.sval), (yyvsp[0].sval));
	}
#line 1772 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 314 "cpp.y" /* yacc.c:1646  */
    {
		(yyval.ival) = (yyvsp[0].ival);
	}
#line 1780 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 368 "cpp.y" /* yacc.c:1646  */
    {
		struct PrimaryExpression* pri_exp = (struct PrimaryExpression*) malloc(sizeof(struct PrimaryExpression));
		pri_exp->primary_type = LITERAL_T;
		pri_exp->which = (yyvsp[0].node);
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		node->primary_expression = pri_exp;
		node->type = (yyvsp[0].node)->type;
		(yyval.node) = node;
	}
#line 1794 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 377 "cpp.y" /* yacc.c:1646  */
    {
	}
#line 1801 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 379 "cpp.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[-1].node);
	}
#line 1809 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 382 "cpp.y" /* yacc.c:1646  */
    {
		struct PrimaryExpression* pri_exp = (struct PrimaryExpression*) malloc(sizeof(struct PrimaryExpression));
		pri_exp->primary_type = ID_EXPRESSION_T;
		struct IdExpression* id_expression = (struct IdExpression*) malloc(sizeof(struct IdExpression));
		strcpy(id_expression->id, (yyvsp[0].sval));
		pri_exp->which = (struct Node*) malloc(sizeof(struct Node));
		pri_exp->which->id_expression = id_expression;
		struct Sym* sym = get_sym((yyvsp[0].sval));
		if (sym == 0) {
//			while (cur_scope->head_sym) {
//				printf("symbol in scope: %s\n", cur_scope->head_sym->name);
//				cur_scope->head_sym = cur_scope->head_sym->next;
//			}
			fprintf(stderr, "%s has not been declared before\n", (yyvsp[0].sval));
			exit(0);
		}
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		node->primary_expression = pri_exp;
		node->type = sym->type;
		(yyval.node) = node;
	}
#line 1835 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 405 "cpp.y" /* yacc.c:1646  */
    {
		strcpy((yyval.sval), (yyvsp[0].sval));
//		struct IdExpression* id_expression = (struct IdExpression*) malloc(sizeof(IdExpression));
//		strcpy(id_expression->id, $1);
//		struct Node* node = (struct Node) *
	}
#line 1846 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 414 "cpp.y" /* yacc.c:1646  */
    {
		strcpy((yyval.sval), (yyvsp[0].sval));
	}
#line 1854 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 427 "cpp.y" /* yacc.c:1646  */
    {
		printf("Primary expression ... %s\n", (yyvsp[0].node)->primary_expression->which->id_expression->id);
		(yyval.node) = (yyvsp[0].node);
	}
#line 1863 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 431 "cpp.y" /* yacc.c:1646  */
    {
		printf("array decl detected\n");
		
		if ((yyvsp[-3].node)->type == INTEGER_ARR_T || (yyvsp[-3].node)->type == INTEGER_PTR_T) (yyvsp[-3].node)->type = INTEGER_T;
		else if ((yyvsp[-3].node)->type == DOUBLE_ARR_T || (yyvsp[-3].node)->type == DOUBLE_PTR_T) (yyvsp[-3].node)->type = DOUBLE_T;
		else if ((yyvsp[-3].node)->type == CHAR_ARR_T || (yyvsp[-3].node)->type == CHAR_PTR_T) (yyvsp[-3].node)->type = CHAR_T;
		else if ((yyvsp[-3].node)->type == BOOL_ARR_T || (yyvsp[-3].node)->type == BOOL_PTR_T) (yyvsp[-3].node)->type = BOOL_T;
		else {
			fprintf(stderr, "Cannot access element of non-array type\n");
			exit(0);
		}
		if ((yyvsp[-1].node)->type != INTEGER_T) {
			fprintf(stderr, "Cannot index an array using non-integer type\n");
			exit(0);
		}
		(yyval.node) = (yyvsp[-3].node);
	}
#line 1885 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 448 "cpp.y" /* yacc.c:1646  */
    {
//		printf("-----Empty function call detected\n");
	}
#line 1893 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 451 "cpp.y" /* yacc.c:1646  */
    {
//		printf("-----Function call with params detected\n");
	}
#line 1901 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 454 "cpp.y" /* yacc.c:1646  */
    {
		printf("-----Function call (%s) with params detected\n", (yyvsp[-3].node)->primary_expression->which->id_expression->id);
		struct Sym* sym = get_sym((yyvsp[-3].node)->primary_expression->which->id_expression->id);
		struct Node* sym_node_tmp = sym->node->declarator->params;
		struct Node* sym_node = 0;
		int cnt = 0;
		struct Node* head_tmp = (yyvsp[-1].node);
		struct Node* head = 0;

		while (sym_node_tmp) {
			struct Node* cur = sym_node;
			sym_node = (struct Node*) malloc(sizeof(struct Node));
			sym_node->type = sym_node_tmp->type;
			sym_node->next = cur;
			sym_node_tmp = sym_node_tmp->next;
		}
		
		while (head_tmp) {
			struct Node* cur = head;
			head = (struct Node*) malloc(sizeof(struct Node));
			head->type = head_tmp->type;
			head->next = cur;
			head_tmp = head_tmp->next;
		}
		
		while (sym_node) {
			if (!head) {
				fprintf(stderr, "Expected more parameters to function call %s\n", (yyvsp[-3].node)->primary_expression->which->id_expression->id);
				exit(0);
			}
			printf("--------actual parameter: %d caller: %d------------\n", sym_node->type, head->type);
			if (sym_node->type != head->type) {
				fprintf(stderr, "Parameter type at position %d does not match (caller passes %d, callee expects %d)\n", cnt + 1, head->type, sym_node->type);
				exit(0);
			}
			sym_node = sym_node->next;
			head = head->next;
			cnt++;
		}
		if (head) {
			fprintf(stderr, "Too many parameters to function call %s\n", (yyvsp[-3].node)->primary_expression->which->id_expression->id);
			exit(0);
		}
		printf("number of params: %d\n", cnt);
	}
#line 1951 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 499 "cpp.y" /* yacc.c:1646  */
    {
		printf("-----Empty function call detected\n");
	}
#line 1959 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 502 "cpp.y" /* yacc.c:1646  */
    {
	}
#line 1966 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 504 "cpp.y" /* yacc.c:1646  */
    {
	}
#line 1973 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 506 "cpp.y" /* yacc.c:1646  */
    {
	}
#line 1980 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 508 "cpp.y" /* yacc.c:1646  */
    {
	}
#line 1987 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 512 "cpp.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[0].node);
	}
#line 1995 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 515 "cpp.y" /* yacc.c:1646  */
    {
//		$1->next = $3;
//		$$ = $1;
		(yyvsp[0].node)->next = (yyvsp[-2].node);
		(yyval.node) = (yyvsp[0].node);
	}
#line 2006 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 523 "cpp.y" /* yacc.c:1646  */
    {
//		struct UnaryExpressionNode* unary = (struct UnaryExpressionNode*) malloc(sizeof(struct UnaryExpressionNode));
//		unary->data.postfix = $1;
//		unary->type = $1->type;
//		$$ = unary;
		(yyval.node) = (yyvsp[0].node);
	}
#line 2018 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 530 "cpp.y" /* yacc.c:1646  */
    {
		struct UnaryExpression* unary_exp = (struct UnaryExpression*) malloc(sizeof(struct UnaryExpression));
		unary_exp->unary_type = INCREMENT_T; 
		if ((yyvsp[0].node)->type != INTEGER_T) {
			yyerror("Integer literal expected for operand");
			exit(0);
		}
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		node->unary_expression = unary_exp;
		node->type = INTEGER_T;
		(yyval.node) = node;
	}
#line 2035 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 542 "cpp.y" /* yacc.c:1646  */
    {
		struct UnaryExpression* unary_exp = (struct UnaryExpression*) malloc(sizeof(struct UnaryExpression));
		unary_exp->unary_type = DECREMENT_T; 
		if ((yyvsp[0].node)->type != INTEGER_T) {
			yyerror("Integer literal expected for operand");
			exit(0);
		}
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		node->unary_expression = unary_exp;
		node->type = INTEGER_T;
		(yyval.node) = node;
	}
#line 2052 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 554 "cpp.y" /* yacc.c:1646  */
    {
	}
#line 2059 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 571 "cpp.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[0].node);
	}
#line 2067 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 574 "cpp.y" /* yacc.c:1646  */
    {
		struct BinaryExpression* bin_exp = (struct BinaryExpression*) malloc(sizeof(struct BinaryExpression)); 
		bin_exp->left = (yyvsp[-2].node);
		bin_exp->right = (yyvsp[0].node);
		bin_exp->binary_type = MULTIPLICATION_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = (yyvsp[0].node)->type;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == CHAR_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == CHAR_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == CHAR_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == CHAR_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = (yyvsp[0].node)->type;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = (yyvsp[0].node)->type;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = (yyvsp[0].node)->type;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == CHAR_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == CHAR_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = (yyvsp[0].node)->type;
		} else {
			yyerror("Invalid operand types for multiplicative expression");
			exit(0);
		}
		
		node->binary_expression = bin_exp;
		(yyval.node) = node;
	}
#line 2116 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 618 "cpp.y" /* yacc.c:1646  */
    {
		struct BinaryExpression* bin_exp = (struct BinaryExpression*) malloc(sizeof(struct BinaryExpression)); 
		bin_exp->left = (yyvsp[-2].node);
		bin_exp->right = (yyvsp[0].node);
		bin_exp->binary_type = DIVISION_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = (yyvsp[0].node)->type;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == CHAR_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == CHAR_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == CHAR_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == CHAR_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = (yyvsp[0].node)->type;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = (yyvsp[0].node)->type;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = (yyvsp[0].node)->type;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == CHAR_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == CHAR_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = (yyvsp[0].node)->type;
		} else {
			yyerror("Invalid operand types for multiplicative expression");
			exit(0);
		}
		node->binary_expression = bin_exp;
		(yyval.node) = node;
	}
#line 2164 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 661 "cpp.y" /* yacc.c:1646  */
    {
		struct BinaryExpression* bin_exp = (struct BinaryExpression*) malloc(sizeof(struct BinaryExpression)); 
		bin_exp->left = (yyvsp[-2].node);
		bin_exp->right = (yyvsp[0].node);
		bin_exp->binary_type = MODULO_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == CHAR_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == CHAR_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = (yyvsp[-2].node)->type;
		} else {
			yyerror("Invalid operand types for multiplicative expression");
			exit(0);
		}
		node->binary_expression = bin_exp;
		(yyval.node) = node;
	}
#line 2188 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 682 "cpp.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[0].node);
	}
#line 2196 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 685 "cpp.y" /* yacc.c:1646  */
    {
		struct BinaryExpression* bin_exp = (struct BinaryExpression*) malloc(sizeof(struct BinaryExpression)); 
		bin_exp->left = (yyvsp[-2].node);
		bin_exp->right = (yyvsp[0].node);
		bin_exp->binary_type = ADDITION_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = (yyvsp[0].node)->type;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == CHAR_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == CHAR_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == CHAR_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == CHAR_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = (yyvsp[0].node)->type;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = (yyvsp[0].node)->type;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = (yyvsp[0].node)->type;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == CHAR_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == CHAR_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = (yyvsp[0].node)->type;
		} else {
			yyerror("Invalid operand types for additive expression");
			exit(0);
		}
		node->binary_expression = bin_exp;
		(yyval.node) = node;
	}
#line 2244 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 728 "cpp.y" /* yacc.c:1646  */
    {
		struct BinaryExpression* bin_exp = (struct BinaryExpression*) malloc(sizeof(struct BinaryExpression)); 
		bin_exp->left = (yyvsp[-2].node);
		bin_exp->right = (yyvsp[0].node);
		bin_exp->binary_type = SUBTRACTION_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = (yyvsp[0].node)->type;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == CHAR_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == CHAR_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == CHAR_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == CHAR_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = (yyvsp[0].node)->type;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = (yyvsp[0].node)->type;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = (yyvsp[0].node)->type;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == CHAR_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == CHAR_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = (yyvsp[0].node)->type;
		} else {
			yyerror("Invalid operand types for additive expression");
			exit(0);
		}
		node->binary_expression = bin_exp;
		(yyval.node) = node;
	}
#line 2292 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 773 "cpp.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[0].node);
	}
#line 2300 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 776 "cpp.y" /* yacc.c:1646  */
    {
		struct BinaryExpression* bin_exp = (struct BinaryExpression*) malloc(sizeof(struct BinaryExpression)); 
		bin_exp->left = (yyvsp[-2].node);
		bin_exp->right = (yyvsp[0].node);
		bin_exp->binary_type = LEFT_SHIFT_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = (yyvsp[-2].node)->type;
		} else {
			yyerror("Invalid operand types for shift expression");
			exit(0);
		}
		node->binary_expression = bin_exp;
		(yyval.node) = node;
	}
#line 2320 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 791 "cpp.y" /* yacc.c:1646  */
    {
		struct BinaryExpression* bin_exp = (struct BinaryExpression*) malloc(sizeof(struct BinaryExpression)); 
		bin_exp->left = (yyvsp[-2].node);
		bin_exp->right = (yyvsp[0].node);
		bin_exp->binary_type = RIGHT_SHIFT_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = (yyvsp[-2].node)->type;
		} else {
			yyerror("Invalid operand types for shift expression");
			exit(0);
		}
		node->binary_expression = bin_exp;
		(yyval.node) = node;
	}
#line 2340 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 808 "cpp.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[0].node);
	}
#line 2348 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 811 "cpp.y" /* yacc.c:1646  */
    {
		struct BinaryExpression* bin_exp = (struct BinaryExpression*) malloc(sizeof(struct BinaryExpression)); 
		bin_exp->left = (yyvsp[-2].node);
		bin_exp->right = (yyvsp[0].node);
		bin_exp->binary_type = LESS_THAN_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == CHAR_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == CHAR_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == CHAR_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = BOOL_T;
		} else {
			yyerror("Invalid operand types for relational expression");
			exit(0);
		}
		node->binary_expression = bin_exp;
		(yyval.node) = node;
	}
#line 2396 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 854 "cpp.y" /* yacc.c:1646  */
    {
		struct BinaryExpression* bin_exp = (struct BinaryExpression*) malloc(sizeof(struct BinaryExpression)); 
		bin_exp->left = (yyvsp[-2].node);
		bin_exp->right = (yyvsp[0].node);
		bin_exp->binary_type = GREATER_THAN_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == CHAR_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == CHAR_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == CHAR_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = BOOL_T;
		} else {
			yyerror("Invalid operand types for relational expression");
			exit(0);
		}
		node->binary_expression = bin_exp;
		(yyval.node) = node;
	}
#line 2444 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 897 "cpp.y" /* yacc.c:1646  */
    {
		struct BinaryExpression* bin_exp = (struct BinaryExpression*) malloc(sizeof(struct BinaryExpression)); 
		bin_exp->left = (yyvsp[-2].node);
		bin_exp->right = (yyvsp[0].node);
		bin_exp->binary_type = LESS_OR_EQUAL_THAN_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == CHAR_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == CHAR_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == CHAR_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = BOOL_T;
		} else {
			yyerror("Invalid operand types for relational expression");
			exit(0);
		}
		node->binary_expression = bin_exp;
		(yyval.node) = node;
	}
#line 2492 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 940 "cpp.y" /* yacc.c:1646  */
    {
		struct BinaryExpression* bin_exp = (struct BinaryExpression*) malloc(sizeof(struct BinaryExpression)); 
		bin_exp->left = (yyvsp[-2].node);
		bin_exp->right = (yyvsp[0].node);
		bin_exp->binary_type = GREATER_OR_EQUAL_THAN_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == CHAR_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == CHAR_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == CHAR_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = BOOL_T;
		} else {
			yyerror("Invalid operand types for relational expression");
			exit(0);
		}
		node->binary_expression = bin_exp;
		(yyval.node) = node;
	}
#line 2540 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 985 "cpp.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[0].node);
	}
#line 2548 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 988 "cpp.y" /* yacc.c:1646  */
    {
		struct BinaryExpression* bin_exp = (struct BinaryExpression*) malloc(sizeof(struct BinaryExpression)); 
		bin_exp->left = (yyvsp[-2].node);
		bin_exp->right = (yyvsp[0].node);
		bin_exp->binary_type = EQUAL_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == CHAR_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == CHAR_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == CHAR_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = BOOL_T;
		} else {
			yyerror("Invalid operand types for equality expression");
			exit(0);
		}
		node->binary_expression = bin_exp;
		(yyval.node) = node;
	}
#line 2596 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1031 "cpp.y" /* yacc.c:1646  */
    {
		struct BinaryExpression* bin_exp = (struct BinaryExpression*) malloc(sizeof(struct BinaryExpression)); 
		bin_exp->left = (yyvsp[-2].node);
		bin_exp->right = (yyvsp[0].node);
		bin_exp->binary_type = NOT_EQUAL_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == CHAR_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == CHAR_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == CHAR_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = BOOL_T;
		} else {
			yyerror("Invalid operand types for equality expression");
			exit(0);
		}
		node->binary_expression = bin_exp;
		(yyval.node) = node;
	}
#line 2644 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1076 "cpp.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[0].node);
	}
#line 2652 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1079 "cpp.y" /* yacc.c:1646  */
    {
		struct BinaryExpression* bin_exp = (struct BinaryExpression*) malloc(sizeof(struct BinaryExpression)); 
		bin_exp->left = (yyvsp[-2].node);
		bin_exp->right = (yyvsp[0].node);
		bin_exp->binary_type = BITWISE_AND_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == CHAR_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == CHAR_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = (yyvsp[-2].node)->type;
		} else {
			yyerror("Invalid operand types for bitwise and expression");
			exit(0);
		}
		node->binary_expression = bin_exp;
		(yyval.node) = node;
	}
#line 2676 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1100 "cpp.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[0].node);
	}
#line 2684 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1103 "cpp.y" /* yacc.c:1646  */
    {
		struct BinaryExpression* bin_exp = (struct BinaryExpression*) malloc(sizeof(struct BinaryExpression)); 
		bin_exp->left = (yyvsp[-2].node);
		bin_exp->right = (yyvsp[0].node);
		bin_exp->binary_type = BITWISE_XOR_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == CHAR_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == CHAR_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = (yyvsp[-2].node)->type;
		} else {
			yyerror("Invalid operand types for bitwise xor expression");
			exit(0);
		}
		node->binary_expression = bin_exp;
		(yyval.node) = node;
	}
#line 2708 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1124 "cpp.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[0].node);
	}
#line 2716 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1127 "cpp.y" /* yacc.c:1646  */
    {
		struct BinaryExpression* bin_exp = (struct BinaryExpression*) malloc(sizeof(struct BinaryExpression)); 
		bin_exp->left = (yyvsp[-2].node);
		bin_exp->right = (yyvsp[0].node);
		bin_exp->binary_type = BITWISE_OR_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == CHAR_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == CHAR_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = (yyvsp[-2].node)->type;
		} else {
			yyerror("Invalid operand types for bitwise or expression");
			exit(0);
		}
		node->binary_expression = bin_exp;
		(yyval.node) = node;
	}
#line 2740 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1148 "cpp.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[0].node);
	}
#line 2748 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1151 "cpp.y" /* yacc.c:1646  */
    {
		struct BinaryExpression* bin_exp = (struct BinaryExpression*) malloc(sizeof(struct BinaryExpression)); 
		bin_exp->left = (yyvsp[-2].node);
		bin_exp->right = (yyvsp[0].node);
		bin_exp->binary_type = LOGICAL_AND_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == CHAR_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == CHAR_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == CHAR_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = BOOL_T;
		} else {
			yyerror("Invalid operand types for logical and expression");
			exit(0);
		}
		node->binary_expression = bin_exp;
		(yyval.node) = node;
	}
#line 2796 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1196 "cpp.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[0].node);
	}
#line 2804 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1199 "cpp.y" /* yacc.c:1646  */
    {
		struct BinaryExpression* bin_exp = (struct BinaryExpression*) malloc(sizeof(struct BinaryExpression)); 
		bin_exp->left = (yyvsp[-2].node);
		bin_exp->right = (yyvsp[0].node);
		bin_exp->binary_type = LOGICAL_OR_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == CHAR_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == CHAR_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ((yyvsp[-2].node)->type == CHAR_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = BOOL_T;
		} else {
			yyerror("Invalid operand types for logical and expression");
			exit(0);
		}
		node->binary_expression = bin_exp;
		(yyval.node) = node;
	}
#line 2852 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1244 "cpp.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[0].node);
	}
#line 2860 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1250 "cpp.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[0].node);
	}
#line 2868 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1253 "cpp.y" /* yacc.c:1646  */
    {
		fprintf(stderr, "Inside assignment expression left type: %d right type %d\n", (yyvsp[-2].node)->type, (yyvsp[0].node)->type);
		struct BinaryExpression* bin_exp = (struct BinaryExpression*) malloc(sizeof(struct BinaryExpression)); 
		bin_exp->left = (yyvsp[-2].node);
		bin_exp->right = (yyvsp[0].node);
		bin_exp->binary_type = (yyvsp[-1].ival);
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = (yyvsp[0].node)->type;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == CHAR_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == CHAR_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == CHAR_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == CHAR_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = (yyvsp[0].node)->type;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == INTEGER_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == INTEGER_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = (yyvsp[0].node)->type;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == DOUBLE_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == DOUBLE_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = (yyvsp[0].node)->type;
		} else if ((yyvsp[-2].node)->type == BOOL_T && (yyvsp[0].node)->type == CHAR_T) {
			node->type = (yyvsp[-2].node)->type;
		} else if ((yyvsp[-2].node)->type == CHAR_T && (yyvsp[0].node)->type == BOOL_T) {
			node->type = (yyvsp[0].node)->type;
		} else {
			yyerror("Invalid operand types for assignment expression");
			exit(0);
		}
		node->binary_expression = bin_exp;
		(yyval.node) = node;
	}
#line 2915 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1299 "cpp.y" /* yacc.c:1646  */
    { (yyval.ival) = ASSIGNMENT_T; }
#line 2921 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1300 "cpp.y" /* yacc.c:1646  */
    { (yyval.ival) = MULTIPLICATION_EQUAL_T; }
#line 2927 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1301 "cpp.y" /* yacc.c:1646  */
    { (yyval.ival) = DIVISION_EQUAL_T; }
#line 2933 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1302 "cpp.y" /* yacc.c:1646  */
    { (yyval.ival) = MODULO_EQUAL_T; }
#line 2939 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1303 "cpp.y" /* yacc.c:1646  */
    { (yyval.ival) = ADDITION_EQUAL_T; }
#line 2945 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1304 "cpp.y" /* yacc.c:1646  */
    { (yyval.ival) = SUBTRACTION_EQUAL_T; }
#line 2951 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1305 "cpp.y" /* yacc.c:1646  */
    { (yyval.ival) = RIGHT_SHIFT_EQUAL_T; }
#line 2957 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1306 "cpp.y" /* yacc.c:1646  */
    { (yyval.ival) = LEFT_SHIFT_EQUAL_T; }
#line 2963 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1307 "cpp.y" /* yacc.c:1646  */
    { (yyval.ival) = AND_EQUAL_T; }
#line 2969 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1308 "cpp.y" /* yacc.c:1646  */
    { (yyval.ival) = XOR_EQUAL_T; }
#line 2975 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1309 "cpp.y" /* yacc.c:1646  */
    { (yyval.ival) = OR_EQUAL_T; }
#line 2981 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1312 "cpp.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[0].node);
	}
#line 2989 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1315 "cpp.y" /* yacc.c:1646  */
    {
		(yyvsp[0].node)->next = (yyvsp[-2].node);
		(yyval.node) = (yyvsp[0].node);
	}
#line 2998 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1326 "cpp.y" /* yacc.c:1646  */
    {
	}
#line 3005 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1328 "cpp.y" /* yacc.c:1646  */
    {
	}
#line 3012 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1330 "cpp.y" /* yacc.c:1646  */
    {
	}
#line 3019 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1332 "cpp.y" /* yacc.c:1646  */
    {
	}
#line 3026 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1334 "cpp.y" /* yacc.c:1646  */
    {
	}
#line 3033 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1338 "cpp.y" /* yacc.c:1646  */
    {
	}
#line 3040 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1342 "cpp.y" /* yacc.c:1646  */
    { printf("Empty compound statement\n"); }
#line 3046 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1343 "cpp.y" /* yacc.c:1646  */
    { printf("Statement inside braces\n"); }
#line 3052 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1346 "cpp.y" /* yacc.c:1646  */
    {
	}
#line 3059 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1355 "cpp.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[0].node);
	}
#line 3067 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1358 "cpp.y" /* yacc.c:1646  */
    {
		printf("condition found\n");
		struct Declarator* decl = (struct Declarator*) malloc(sizeof(struct Declarator));
		decl->declarator_type = VAR_DECL_T;
		strcpy(decl->id, (yyvsp[-2].sval));
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		node->declarator = decl;
		node->type = (yyvsp[-3].ival);

		union Data data;
		struct Sym* sym = add_sym(decl->id, (yyvsp[0].node), (yyvsp[-3].ival));
		if (sym == 0) {
			fprintf(stderr, "Symbol %s is already defined\n", decl->id);			
			while (cur_scope->head_sym) {
				fprintf(stderr, "Inside scope: %s\n", cur_scope->head_sym->name);
				cur_scope->head_sym = cur_scope->head_sym->next;
			}
			exit(0);
		}

		(yyval.node) = node;
	}
#line 3094 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1389 "cpp.y" /* yacc.c:1646  */
    {
		LiteralType ret_type = cur_scope->ret_type;
		if (ret_type == VOID_T) {
			fprintf(stderr, "Cannot return value from void function\n");
			exit(0);
		}
		if (ret_type == STRING_T) {
			if ((yyvsp[-1].node)->type != STRING_T) {
				fprintf(stderr, "Cannot return value different than string type\n");
				exit(0);
			}
		} else {
			if ((yyvsp[-1].node)->type == STRING_T) {
				fprintf(stderr, "Cannot return string from primitive value function\n");
				exit(0);
			}
		}
	}
#line 3117 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1410 "cpp.y" /* yacc.c:1646  */
    {
		printf("Declaration statement\n");
	}
#line 3125 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1415 "cpp.y" /* yacc.c:1646  */
    { printf("C++ program successfully parsed\n"); }
#line 3131 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1422 "cpp.y" /* yacc.c:1646  */
    { printf("Block declaration\n"); }
#line 3137 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1423 "cpp.y" /* yacc.c:1646  */
    { printf("Function declaration\n"); }
#line 3143 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1430 "cpp.y" /* yacc.c:1646  */
    {
		fprintf(stderr, "Simple declaration rule!\n");
	
		struct Node* head = (yyvsp[-1].node);
		while (head) {
			fprintf(stderr, "Adding identifier %s\n", head->declarator->id);
			if (head->declarator->declarator_type == PTR_DECL_T) {
				union Data data;
				struct Sym* sym;
				if ((yyvsp[-2].ival) == INTEGER_T) sym = add_sym(head->declarator->id, head, INTEGER_PTR_T), head->type = INTEGER_PTR_T;
				else if ((yyvsp[-2].ival) == DOUBLE_T) sym = add_sym(head->declarator->id, head, DOUBLE_PTR_T), head->type = DOUBLE_PTR_T;
				else if ((yyvsp[-2].ival) == CHAR_T) sym = add_sym(head->declarator->id, head, CHAR_PTR_T), head->type = CHAR_PTR_T;
				else if ((yyvsp[-2].ival) == BOOL_T) sym = add_sym(head->declarator->id, head, BOOL_PTR_T), head->type = BOOL_PTR_T;
				else if ((yyvsp[-2].ival) == VOID_T) sym = add_sym(head->declarator->id, head, VOID_PTR_T), head->type = VOID_PTR_T;
				else assert(0);
				if (sym == 0) {
					fprintf(stderr, "Symbol %s is already defined\n", head->declarator->id);
					exit(0);
				}
			} else if (head->declarator->declarator_type == ARR_DECL_T) {
				union Data data;
				struct Sym* sym;
				if ((yyvsp[-2].ival) == INTEGER_T) sym = add_sym(head->declarator->id, head, INTEGER_PTR_T), head->type = INTEGER_ARR_T;
				else if ((yyvsp[-2].ival) == DOUBLE_T) sym = add_sym(head->declarator->id, head, DOUBLE_PTR_T), head->type = DOUBLE_ARR_T;
				else if ((yyvsp[-2].ival) == CHAR_T) sym = add_sym(head->declarator->id, head, CHAR_PTR_T), head->type = CHAR_ARR_T;
				else if ((yyvsp[-2].ival) == BOOL_T) sym = add_sym(head->declarator->id, head, BOOL_PTR_T), head->type = BOOL_ARR_T;
				else assert(0);
//				if ($1 == VOID_T) sym = add_sym(head->declarator->id, data, VOID_PTR_T), head->type = VOID_ARR_T;
				if (sym == 0) {
					fprintf(stderr, "Symbol %s is already defined\n", head->declarator->id);
					exit(0);
				}
			} else {
				union Data data;
				struct Sym* sym = add_sym(head->declarator->id, head, (yyvsp[-2].ival));
				head->type = (yyvsp[-2].ival);
				if (sym == 0) {
					fprintf(stderr, "Symbol %s is already defined\n", head->declarator->id);
					exit(0);
				}
			}
			head = head->next;
		}
	}
#line 3192 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1475 "cpp.y" /* yacc.c:1646  */
    {
		printf("Class declaration detected\n");
	}
#line 3200 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1483 "cpp.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[0].node);
	}
#line 3208 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1486 "cpp.y" /* yacc.c:1646  */
    {
		(yyvsp[0].node)->next = (yyvsp[-2].node);
		(yyval.node) = (yyvsp[0].node);
	}
#line 3217 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1492 "cpp.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[0].node);
	}
#line 3225 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1495 "cpp.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[-1].node);
	}
#line 3233 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1528 "cpp.y" /* yacc.c:1646  */
    {
		(yyval.ival) = CHAR_T;
	}
#line 3241 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1531 "cpp.y" /* yacc.c:1646  */
    {
		(yyval.ival) = BOOL_T;
	}
#line 3249 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1534 "cpp.y" /* yacc.c:1646  */
    {
		(yyval.ival) = INTEGER_T;
	}
#line 3257 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1537 "cpp.y" /* yacc.c:1646  */
    {
		(yyval.ival) = DOUBLE_T;
	}
#line 3265 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1540 "cpp.y" /* yacc.c:1646  */
    {
		(yyval.ival) = VOID_T;		
	}
#line 3273 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1550 "cpp.y" /* yacc.c:1646  */
    {
		
		
		struct Node* head = (yyvsp[0].node);
		while (head) {
			fprintf(stderr, "Adding function identifier %s\n", head->declarator->id);
			union Data data;
			struct Sym* sym = add_sym(head->declarator->id, head, (yyvsp[-1].ival));
			head->type = (yyvsp[-1].ival);
			if (sym == 0) {
				fprintf(stderr, "Function %s is already defined\n", head->declarator->id);
				exit(0);
			}
			
			head = head->next;
		}
		
		create_scope_type((yyvsp[-1].ival));
		printf("Creating function scope\n");
		
		head = (yyvsp[0].node);
		while (head) {
			union Data data;
			struct Node* params = head->declarator->params;
			while (params) {
				union Data data;
				printf("Adding function parameter: %s\n", params->declarator->id);
				struct Sym* sym = add_sym(params->declarator->id, params, params->type);
				if (sym == 0) {
					fprintf(stderr, "Symbol %s is already defined\n", params->declarator->id);
					exit(0);
				}
				params = params->next;
			}
			head = head->next;
		}
		
	}
#line 3316 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1587 "cpp.y" /* yacc.c:1646  */
    { 
		delete_scope(); 
	}
#line 3324 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1599 "cpp.y" /* yacc.c:1646  */
    {
		printf("Empty function body\n");
	}
#line 3332 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1602 "cpp.y" /* yacc.c:1646  */
    {
		printf("Function body\n");
	}
#line 3340 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1610 "cpp.y" /* yacc.c:1646  */
    {
//		strcpy($$, $1);
		(yyval.node) = (yyvsp[0].node);
	}
#line 3349 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1614 "cpp.y" /* yacc.c:1646  */
    {
		if ((yyvsp[-1].ival) == PTR_DECL_T) {
			(yyvsp[0].node)->declarator->declarator_type = (yyvsp[-1].ival);
		}
		(yyval.node) = (yyvsp[0].node);
	}
#line 3360 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1622 "cpp.y" /* yacc.c:1646  */
    {
//		struct IdExpression* id_expression = (struct IdExpression*) malloc(sizeof(struct IdExpression));
//		strcpy(id_expression->id, $1);
//		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
//		node->id_expression = id_expression;
//		node->type = sym->type;
//		$$ = node;		
		struct Declarator* decl = (struct Declarator*) malloc(sizeof(struct Declarator));
		decl->declarator_type = VAR_DECL_T;
		strcpy(decl->id, (yyvsp[0].sval));
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		node->declarator = decl;
		(yyval.node) = node;
	}
#line 3379 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 1636 "cpp.y" /* yacc.c:1646  */
    {
		struct Node* node = (yyvsp[-1].node);
		node->declarator->params = (yyvsp[0].node);
		node->declarator->declarator_type = FUN_DECL_T;
		(yyval.node) = node;
	}
#line 3390 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1642 "cpp.y" /* yacc.c:1646  */
    {
//		struct Declarator* decl = (struct Declarator*) malloc(sizeof(struct Declarator));
//		decl->declarator_type = ARR_DECL_T;
//		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
//		node->declarator = decl;
//		$$ = node;
		struct Node* node = (yyvsp[-3].node);
		node->declarator->declarator_type = ARR_DECL_T;
		(yyval.node) = node;
	}
#line 3405 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1652 "cpp.y" /* yacc.c:1646  */
    {
//		struct Declarator* decl = (struct Declarator*) malloc(sizeof(struct Declarator));
//		decl->declarator_type = ARR_DECL_T;
//		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
//		node->declarator = decl;
//		$$ = node;
		struct Node* node = (yyvsp[-2].node);
		node->declarator->declarator_type = ARR_DECL_T;
		(yyval.node) = node;
	}
#line 3420 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1670 "cpp.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[-1].node);
//		create_scope();
	}
#line 3429 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1680 "cpp.y" /* yacc.c:1646  */
    {
		(yyval.node) = 0;
	}
#line 3437 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1683 "cpp.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[0].node);
	}
#line 3445 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1689 "cpp.y" /* yacc.c:1646  */
    {
		(yyval.node) = (yyvsp[0].node);
	}
#line 3453 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1692 "cpp.y" /* yacc.c:1646  */
    {
		(yyvsp[0].node)->next = (yyvsp[-2].node);
		(yyval.node) = (yyvsp[0].node);
	}
#line 3462 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1698 "cpp.y" /* yacc.c:1646  */
    {
		struct Declarator* decl = (struct Declarator*) malloc(sizeof(struct Declarator));
		decl->declarator_type = VAR_DECL_T;
		strcpy(decl->id, (yyvsp[0].sval));
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		node->declarator = decl;
		node->type = (yyvsp[-1].ival);
	/*
		union Data data;
		struct Sym* sym = add_sym(decl->id, data, $1);
		if (sym == 0) {
			fprintf(stderr, "Symbol %s is already defined\n", decl->id);
			exit(0);
		}
	*/
		(yyval.node) = node;		
	}
#line 3484 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1718 "cpp.y" /* yacc.c:1646  */
    { (yyval.ival) = DEREF_DECL_T; }
#line 3490 "cpp.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1728 "cpp.y" /* yacc.c:1646  */
    {
		strcpy((yyval.sval), (yyvsp[0].sval));
	}
#line 3498 "cpp.tab.c" /* yacc.c:1646  */
    break;


#line 3502 "cpp.tab.c" /* yacc.c:1646  */
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
#line 1800 "cpp.y" /* yacc.c:1906  */


int main(int argc, char** argv) {
/*	FILE *myfile = fopen("cpp.in", "r");
	if (!myfile) {
		fprintf(stderr, "Cannot open file\n");
		return -1;
	}
	yyin = myfile;*/
//	while (yyparse() > 0);
	create_scope();
	do {
		yyparse();
	} while (!feof(yyin));
	return 0;
}

void yyerror(const char *s) {
	fprintf(stderr, "Parse error: %s\n", s);
	exit(-1);
}

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
#line 27 "cpp.y" /* yacc.c:1909  */

	int ival;
	float fval;
	char *sval;
	char cval;
	struct Sym* sym;
	struct Node* node;

#line 151 "cpp.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CPP_TAB_H_INCLUDED  */

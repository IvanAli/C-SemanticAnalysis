%{
// This is the flex file that contains all the Regular Expressions for each of the token classes defined
#include <stdio.h>
#include "cpp.tab.h"
// #define YY_DECL extern "C" int yylex()
extern int yylex(void);
extern YYSTYPE yylval;
/*
union {
	int ival;
	char* sval;
	double fval;
	char cval;
} yylval;
*/
%}

%{
	// Defining sub regular expressions for later use
%}

%{
// Subexpression for a digit
%}
digitp [1-9]
digit [0-9]

%{
// Subexpression for a lowercase letter
%}
lowercase [a-z]

%{
// Subexpression for an uppercase letter
%}
uppercase [A-Z]

%{
// Subexpression for a letter
%}
letter {lowercase}|{uppercase}

%{
// Subexpression for one digit or more
%}
digits {digit}+

%{
// Subexpression for one letter or more
%}
letters {letter}+

%%

%{
	// Regular Expressions for each token class
%}

%{
// Ignore white space
%}
[ \t\n] {}

%{
// list of not accepted tokens
%}

while|auto|default|break|const_cast|goto|dynamic_cast|asm|catch|case|extern|enum|float|continue|friend|inline|long|mutable|operator|protected|reinterpret_cast|register|short|signed|sizeof|static|static_cast|struct|switch|template|throw|try|typedef|typeid|typename|union|unsigned|virtual|volatile|wchar_t

%{
// Regex for preprocessor directive
%}
#.* { printf("preprocessor directive: %s\n", yytext); yylval.sval = strdup(yytext); return DIRECTIVE; }

%{
// Regex for a single line comment
%}
"//".* { }

%{
// Regex for a multi line comment
%}
\/\*([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+\/ { }

%{
// Regex for the "return" keyword
%}
return { return RETURN; }

%{
// Regex for the "class" keyword used in OOP
%}
class { return CLASS; }

%{
// Regex for the "public" keyword used in OOP
%}
public { return PUBLIC; }

%{
// Regex for the "private" keyword used in OOP
%}
private { return PRIVATE; }

%{
// Regex for the "this" keyword used in OOP
%}
this { return THIS; }

%{
// Regex for the "new" keyword for memory allocation
%}
new { return NEW; }

%{
// Regex for the "int" keyword used as a data type
%}
int { return INTKW; }

%{
// Regex for the "double" keyword used as a data type
%}
double { return DOUBLEKW; }

%{
// Regex for the "char" keyword used as a data type
%}
char { return CHARKW; }

%{
// Regex for the "bool" keyword used as a data type
%}
bool { return BOOLKW; }

%{
// Regex for the "void" keyword as a data type
%}
void { return VOIDKW; }

%{
// Regex for the "int" keyword used as a pointer
%}
int[ ]*\* { return INTP; }

%{
// Regex for the "double" keyword used as a pointer
%}
double[ ]*\* { return DOUBLEP; }

%{
// Regex for the "char" keyword used as a pointer
%}
char[ ]*\* { return CHARP; }

%{
// Regex for the "bool" keyword used as a pointer
%}
bool[ ]*\* { return BOOLP; }

%{
// Regex for the "void" keyword as a data type
%}
void[ ]*\* { return VOIDP; }

%{
// Regex for the "if" keyword (used for conditionals)
%}
if { printf("if keyword found\n"); return IF; }

%{
// Regex for the "else" keyword (used for conditionals)
%}
else { return ELSE; }

%{
// Regex for the "for" keyword (used for loops)
%}
for { return FOR; }

%{
// Regex for the "const" keyword (to define an unchangeable value)
%}
const { return CONST; }

%{
// Regex for the "using" keyword (to include a namespace)
%}
using { return USING; }

%{
// Regex for the "namespace" keyword
%}
namespace { return NAMESPACE; }

%{
// Regex for the "and" logical operator
%}
&& { return AND; }

%{
// Regex for the "or" logical operator
%}
\|\| { return OR; }

%{
// Regex for the "not" logical operator
%}
! { return NOT; }

%{
// Regex for the "bitwise-and" logical operator
%}
& { return BITWISE_AND; }

%{
// Regex for the "bitwise-or" logical operator
%}
\| { return BITWISE_OR; }

%{
// Regex for the "bitwise-xor" logical operator
%}
\^ { return BITWISE_XOR; }

%{
// Regex for the "less or equal than" comparison operator
%}
\<= { return LESS_OR_EQUAL_THAN; }

%{
// Regex for the "greater or equal than" comparison operator
%}
>= { return GREATER_OR_EQUAL_THAN; }

%{
// Regex for the "less than" comparison operator
%}
\< { return LESS_THAN; }

%{
// Regex for the "greater than" comparison operator
%}
> { return GREATER_THAN; }

%{
// Regex for the "equal" comparison operator
%}
== { return EQUAL; }

%{
// Regex for the "not equal" comparison operator
%}
!= { return NOT_EQUAL; }

%{
// Regex for the "assignment" operator
%}
= { return ASSIGNMENT; }

%{
// Regex for the "addition" arithmetic operator
%}
\+ { return ADDITION; }

%{
// Regex for the "subtraction" arithmetic operator
%}
- { return SUBTRACTION; }

%{
// Regex for the "multiplication" arithmetic operator
%}
\* { return MULTIPLICATION; }

%{
// Regex for the "division" arithmetic operator
%}
\/ { return DIVISION; }

%{
// Regex for the "modulo" arithmetic operator
%}
% { return MODULO; }

%{
// Regex for the "increment" operator
%}
\+\+ { return INCREMENT; }

%{
// Regex for the "decrement" operator
%}
-- { return DECREMENT; }

%{
// Regex for the "plus equal" operator
%}
\+= { return ADDITION_EQUAL; }

%{
// Regex for the "minus equal" operator
%}
-= { return SUBTRACTION_EQUAL; }

%{
// Regex for the "times equal" operator
%}
\*= { return MULTIPLICATION_EQUAL; }

%{
// Regex for the "divided equal" operator
%}
\/= { return DIVISION_EQUAL; }

%{
// Regex for the "modulo equal" operator
%}
%= { return MODULO_EQUAL; }

%{
// Regex for the "and equal" operator
%}
&= { return AND_EQUAL; }

%{
// Regex for the "or equal" operator
%}
\|= { return OR_EQUAL; }

%{
// Regex for the "xor equal" operator
%}
\^= { return XOR_EQUAL; }

%{
// Regex for the "bit shift to the left equal" operator
%}
\<\<= { return LEFT_SHIFT_EQUAL; }

%{
// Regex for the "bit shift to the right equal" operator
%}
>>= { return RIGHT_SHIFT_EQUAL; }

%{
// Regex for the "member access to object" operator
%}
\. { return OBJECT_ACCESS; }

%{
// Regex for the "member access to pointer" operator
%}
-> { return POINTER_ACCESS; }

%{
// Regex for namespace operator
%}
:: { return DOUBLE_COLON; }

%{
// Regex for the "inheritance" operator
%}
: { return COLON; }

%{
// Regex for the "end of expression" character
%}
; { return SEMI_COLON; }

%{
// Regex for comma
%}
, { return COMMA; }

%{
// Regex for the "open parentheses" character
%}
\( { return OPEN_PARENTHESES; }

%{
// Regex for the "close parentheses" character
%}
\) { return CLOSE_PARENTHESES; }

%{
// Regex for the "open brace" character
%}
\{ { return OPEN_BRACE; }

%{
// Regex for the "close brace" character
%}
\} { return CLOSE_BRACE; }

%{
// Regex for the "open bracket" character
%}
\[ { return OPEN_BRACKET; }

%{
// Regex for the "close bracket" character
%}
\] { return CLOSE_BRACKET; }


%{
// Regex for the "input stream" operator and bit shift to the left operator
%}
\<\< { return LEFT_SHIFT; }

%{
// Regex for the "output stream" operator and bit shift to the right operator
%}
>> { return RIGHT_SHIFT; }



%{
// Regex for ternary operator
%}
\? { return TERNARY; }



%{
// Regex for single quote symbol
%}
' { return SINGLE_QUOTE; }


%{
// Regex for double quote symbol
%}
\" { return DOUBLE_QUOTE; }





%{
// Regex for any string
%}
\".*\" { yylval.sval = strdup(yytext); return STRING; }

%{
// Regex for the any integer
%}
{digits} { yylval.ival = atoi(yytext); return INT; }

%{
// Regex for the any floating point number
%}
{digits}\.{digit}* { yylval.fval = atof(yytext); return FLOAT; }

%{
// Regex for true value
%}
true { yylval.ival = 1; return BOOL; }

%{
// Regex for false value
%}
false { yylval.ival = 0; return BOOL; }

%{
// Regex for any pointer identifier
%}
\*({letter}|_)({letter}|{digit}|_)*	{ yylval.sval = strdup(yytext); return POINTERID; }

%{
// Regex for any pointer redeference
%}
&({letter}|_)({letter}|{digit}|_)*	{ yylval.sval = strdup(yytext); return DEPOINTERID; }

%{
// Regex for any variable identifier
%}
({letter}|_)({letter}|{digit}|_)*	{ yylval.sval = strdup(yytext); return IDENTIFIER; }

%{
// Regex for any character
%}
'.' { yylval.sval = strdup(yytext); return CHARACTER; }





%{
// Regex for any header char
%}
[^\n\"] { yylval.cval = yytext[0]; return Q_CHAR; }


%{
// Regex for any header char
%}
[^>\n] { yylval.cval = yytext[0]; return H_CHAR; }


%{
// Regex for any character literal char
%}
[^\n'\\] { yylval.cval = yytext[0]; return C_CHAR; }




%%


%{
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
%}

// returns as an object of type "yystype".  But tokens could be of any
// arbitrary data type!  So we deal with that in Bison by defining a C union
// holding each of the types of tokens that Flex could return, and have Bison
// use that union instead of "int" for the definition of "yystype":

%union {
	int ival;
	float fval;
	char *sval;
	char cval;
	struct Sym* sym;
	struct Node* node;
}

%token <ival> INT
%token <fval> FLOAT
%token <sval> STRING
%token <ival> BOOL
%token <cval> H_CHAR
%token <cval> Q_CHAR
%token <cval> C_CHAR
%token <sval> IDENTIFIER

%type <ival> simple_type_specifier
//%type <sym> init_declarator init_declarator_list simple_declaration
%type <sval> identifier
%type <sval> unqualified_id
%type <sval> declarator_id
//%type <sval> direct_declarator
%type <sval> id_expression
//%type <sval> declarator
%type <ival> integer_literal
%type <cval> character_literal
%type <fval> floating_literal
%type <sval> string_literal
%type <ival> boolean_literal
%type <node> literal primary_expression postfix_expression unary_expression multiplicative_expression additive_expression shift_expression
relational_expression equality_expression and_expression exclusive_or_expression inclusive_or_expression logical_and_expression
logical_or_expression assignment_expression conditional_expression expression init_declarator init_declarator_list simple_declaration 
declarator direct_declarator parameters_and_qualifiers parameter_declaration_clause.opt parameter_declaration_list parameter_declaration
condition expression_list

//%type <lit> literal
//%type <priexp> primary_expression
//%type <postfix> postfix_expression
//%type <unary> unary_expression
//%type <mulexp> multiplicative_expression
//%type <addexp> additive_expression
//%type <shiftexp> shift_expression
//%type <relexp> relational_expression
//%type <eqexp> equality_expression
//%type <bandexp> and_expression
//%type <bxorexp> exclusive_or_expression
//%type <borexp> inclusive_or_expression
//%type <landexp> logical_and_expression
//%type <lorexp> logical_or_expression
%type <ival> assignment_operator
%type <ival> ptr_operator
//%type <conexp> conditional_expression
//%type <assexp> assignment_expression

%token ZERO
%token CLASS   
%token PUBLIC   
%token PRIVATE   
%token NEW   
%token DOUBLEKW
%token CHARKW 
%token VOIDKW 
%token BOOLKW
%token IF   
%token FOR   
%token CONST   
%token USING   
%token NAMESPACE   
%token AND   
%token OR   
%token BITWISE_AND   
%token BITWISE_OR   
%token BITWISE_XOR   
%token LESS_OR_EQUAL_THAN   
%token GREATER_OR_EQUAL_THAN   
%token LESS_THAN   
%token GREATER_THAN   
%token EQUAL   
%token NOT_EQUAL   
%token ASSIGNMENT   
%token ADDITION   
%token SUBTRACTION   
%token MULTIPLICATION   
%token DIVISION   
%token MODULO   
%token INCREMENT   
%token DECREMENT   
%token ADDITION_EQUAL   
%token SUBTRACTION_EQUAL   
%token MULTIPLICATION_EQUAL   
%token DIVISION_EQUAL   
%token MODULO_EQUAL   
%token AND_EQUAL   
%token OR_EQUAL   
%token XOR_EQUAL   
%token LEFT_SHIFT_EQUAL   
%token RIGHT_SHIFT_EQUAL   
%token OBJECT_ACCESS   
%token POINTER_ACCESS   
%token COLON
%token TERNARY
%token DOUBLE_COLON   
%token SEMI_COLON   
%token LEFT_SHIFT   
%token RIGHT_SHIFT   
//%token IDENTIFIER   
%token CHARACTER   
%token OPEN_PARENTHESES   
%token CLOSE_PARENTHESES   
%token OPEN_BRACE   
%token CLOSE_BRACE   
%token OPEN_BRACKET   
%token CLOSE_BRACKET   
%token DOUBLEP   
%token CHARP   
%token VOIDP   
%token POINTERID   
%token DEPOINTERID   
%token RETURN   
%token COMMA   
%token ELSE   
%token TRUE   
%token FALSE   
%token THIS   
%token NOT   
%token DIRECTIVE  
%token INTKW
%token INTP
%token BOOLP
%token SINGLE_QUOTE
%token DOUBLE_QUOTE
%token ESCAPE_SEQUENCE

%start translation_unit

%%

preprocessing_token:
	header_name
	;
tok:
	keyword
	| literal
	| operator_token
	;
header_name:
	LESS_THAN h_char_sequence GREATER_THAN { printf("reading directive\n"); }
	| DOUBLE_QUOTE q_char_sequence DOUBLE_QUOTE { printf("reading directive\n"); }
	;
h_char_sequence:
	H_CHAR
	| h_char_sequence H_CHAR
	;
q_char_sequence:
	Q_CHAR
	| q_char_sequence Q_CHAR
	;
identifier:
	IDENTIFIER {
		printf("Identifier: %s\n", $1);
		strcpy($$, $1);		
	}
	;
keyword:
	BOOLKW
	| RETURN
	| DOUBLEKW
	| IF
	| NEW
	| PRIVATE
	| FALSE
	| VOIDKW
	| ELSE
	| INTKW
	| PUBLIC
	| THIS
	| CHARKW
	| FOR
	| CLASS
	| TRUE
	;
open_brace:
	OPEN_BRACE { 
		printf("Creating scope with depth %d\n", cur_scope->depth + 1);
		create_scope();
	}
	;
close_brace: 
	CLOSE_BRACE { 
		printf("Deleting scope with depth %d\n", cur_scope->depth);
		if (!cur_scope->prev) {
			fprintf(stderr, "WARNING (close brace)\n");
		} else delete_scope();
	}
	;
open_parentheses:
	OPEN_PARENTHESES { 
		printf("Creating scope with depth %d\n", cur_scope->depth + 1);
		create_scope();
	}
	;
close_parentheses: 
	CLOSE_PARENTHESES { 
		printf("Deleting scope with depth %d\n", cur_scope->depth);
		if (!cur_scope->prev) {
			fprintf(stderr, "WARNING (close parentheses)\n");
		} else delete_scope();
	}
	;
literal:
	integer_literal {
		struct Literal* lit = (struct Literal*) malloc(sizeof(struct Literal));
		lit->ival = $1;
		lit->literal_type = INTEGER_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		node->literal_expression = lit;
		node->type = INTEGER_T;
		$$ = node;
	}
	| character_literal {
		struct Literal* lit = (struct Literal*) malloc(sizeof(struct Literal));
		lit->cval = $1;
		lit->literal_type = CHAR_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		node->literal_expression = lit;
		node->type = CHAR_T;
		$$ = node;
	}
	| floating_literal {
		struct Literal* lit = (struct Literal*) malloc(sizeof(struct Literal));
		lit->fval = $1;
		lit->literal_type = DOUBLE_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		node->literal_expression = lit;
		node->type = DOUBLE_T;
		$$ = node;
	}
	| string_literal {
		printf("string literal detected\n");
		struct Literal* lit = (struct Literal*) malloc(sizeof(struct Literal));
		strcpy(lit->sval, $1);
		lit->literal_type = STRING_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		node->literal_expression = lit;
		node->type = STRING_T;
		$$ = node;
	}
	| boolean_literal {
		struct Literal* lit = (struct Literal*) malloc(sizeof(struct Literal));
		lit->ival = $1;
		lit->literal_type = BOOL_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		node->literal_expression = lit;
		node->type = BOOL_T;
		$$ = node;
	}
	;
integer_literal:
	INT {
		$$ = $1;
	}
	;

character_literal:
	SINGLE_QUOTE c_char_sequence SINGLE_QUOTE
	;

c_char_sequence:
	C_CHAR
	| c_char_sequence C_CHAR
	;
escape_sequence:
	ESCAPE_SEQUENCE
	;
floating_literal:
	FLOAT {
		$$ = $1;
	}
	;
string_literal:
	STRING {
		strcpy($$, $1);
	}
	;
boolean_literal:
	BOOL {
		$$ = $1;
	}
	;
operator_token:
	OPEN_BRACE
	| CLOSE_BRACE
	| OPEN_BRACKET
	| CLOSE_BRACKET
/*	#
	##*/
	| OPEN_PARENTHESES
	| CLOSE_PARENTHESES
	| SEMI_COLON
	| COLON
	| NEW
	| OBJECT_ACCESS
	| ADDITION
	| SUBTRACTION
	| MULTIPLICATION
	| DIVISION
	| MODULO
	| BITWISE_XOR
	| BITWISE_AND
	| BITWISE_OR
	/* ~ */
	| NOT
	| ASSIGNMENT
	| LESS_THAN
	| GREATER_THAN
	| ADDITION_EQUAL
	| SUBTRACTION_EQUAL
	| MULTIPLICATION_EQUAL
	| DIVISION_EQUAL
	| MODULO_EQUAL
	| XOR_EQUAL
	| AND_EQUAL
	| OR_EQUAL
	| LEFT_SHIFT
	| RIGHT_SHIFT
	| LEFT_SHIFT_EQUAL
	| RIGHT_SHIFT_EQUAL
	| EQUAL
	| NOT_EQUAL
	| LESS_OR_EQUAL_THAN
	| GREATER_OR_EQUAL_THAN
	| AND
	| OR
	| INCREMENT
	| DECREMENT
	| COMMA
	| POINTER_ACCESS
	;
primary_expression:
	literal {
		struct PrimaryExpression* pri_exp = (struct PrimaryExpression*) malloc(sizeof(struct PrimaryExpression));
		pri_exp->primary_type = LITERAL_T;
		pri_exp->which = $1;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		node->primary_expression = pri_exp;
		node->type = $1->type;
		$$ = node;
	}
	| THIS {
	}
	| OPEN_PARENTHESES expression CLOSE_PARENTHESES {
		$$ = $2;
	}
	| id_expression {
		struct PrimaryExpression* pri_exp = (struct PrimaryExpression*) malloc(sizeof(struct PrimaryExpression));
		pri_exp->primary_type = ID_EXPRESSION_T;
		struct IdExpression* id_expression = (struct IdExpression*) malloc(sizeof(struct IdExpression));
		strcpy(id_expression->id, $1);
		pri_exp->which = (struct Node*) malloc(sizeof(struct Node));
		pri_exp->which->id_expression = id_expression;
		struct Sym* sym = get_sym($1);
		if (sym == 0) {
//			while (cur_scope->head_sym) {
//				printf("symbol in scope: %s\n", cur_scope->head_sym->name);
//				cur_scope->head_sym = cur_scope->head_sym->next;
//			}
			fprintf(stderr, "%s has not been declared before\n", $1);
			exit(0);
		}
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		node->primary_expression = pri_exp;
		node->type = sym->type;
		$$ = node;
	}
	;
id_expression:
	unqualified_id {
		strcpy($$, $1);
//		struct IdExpression* id_expression = (struct IdExpression*) malloc(sizeof(IdExpression));
//		strcpy(id_expression->id, $1);
//		struct Node* node = (struct Node) *
	}
//	| qualified_id
	;
unqualified_id:
	identifier {
		strcpy($$, $1);
	}
	;
/*	operator_function_id */

qualified_id:
	nested_name_specifier unqualified_id
	;
nested_name_specifier:
	class_name DOUBLE_COLON nested_name_specifier
	;
postfix_expression:
	primary_expression {
		printf("Primary expression ... %s\n", $1->primary_expression->which->id_expression->id);
		$$ = $1;
	}
	| postfix_expression OPEN_BRACKET expression CLOSE_BRACKET {
		printf("array decl detected\n");
		
		if ($1->type == INTEGER_ARR_T || $1->type == INTEGER_PTR_T) $1->type = INTEGER_T;
		else if ($1->type == DOUBLE_ARR_T || $1->type == DOUBLE_PTR_T) $1->type = DOUBLE_T;
		else if ($1->type == CHAR_ARR_T || $1->type == CHAR_PTR_T) $1->type = CHAR_T;
		else if ($1->type == BOOL_ARR_T || $1->type == BOOL_PTR_T) $1->type = BOOL_T;
		else {
			fprintf(stderr, "Cannot access element of non-array type\n");
			exit(0);
		}
		if ($3->type != INTEGER_T) {
			fprintf(stderr, "Cannot index an array using non-integer type\n");
			exit(0);
		}
		$$ = $1;
	}
	| simple_type_specifier OPEN_PARENTHESES CLOSE_PARENTHESES {
//		printf("-----Empty function call detected\n");
	}
	| simple_type_specifier OPEN_PARENTHESES expression_list CLOSE_PARENTHESES {
//		printf("-----Function call with params detected\n");
	}
	| postfix_expression OPEN_PARENTHESES expression_list CLOSE_PARENTHESES {
		printf("-----Function call (%s) with params detected\n", $1->primary_expression->which->id_expression->id);
		struct Sym* sym = get_sym($1->primary_expression->which->id_expression->id);
		struct Node* sym_node_tmp = sym->node->declarator->params;
		struct Node* sym_node = 0;
		int cnt = 0;
		struct Node* head_tmp = $3;
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
				fprintf(stderr, "Expected more parameters to function call %s\n", $1->primary_expression->which->id_expression->id);
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
			fprintf(stderr, "Too many parameters to function call %s\n", $1->primary_expression->which->id_expression->id);
			exit(0);
		}
		printf("number of params: %d\n", cnt);
	}
	| postfix_expression OPEN_PARENTHESES CLOSE_PARENTHESES {
		printf("-----Empty function call detected\n");
	}
	| postfix_expression INCREMENT {
	}
	| postfix_expression DECREMENT {
	}
	| postfix_expression "." id_expression {
	}
	| postfix_expression "->" id_expression {
	}
	;
expression_list:
	assignment_expression {
		$$ = $1;
	}
	| expression_list COMMA assignment_expression {
//		$1->next = $3;
//		$$ = $1;
		$3->next = $1;
		$$ = $3;
	}
	;
unary_expression:
	postfix_expression {
//		struct UnaryExpressionNode* unary = (struct UnaryExpressionNode*) malloc(sizeof(struct UnaryExpressionNode));
//		unary->data.postfix = $1;
//		unary->type = $1->type;
//		$$ = unary;
		$$ = $1;
	}
	| INCREMENT unary_expression {
		struct UnaryExpression* unary_exp = (struct UnaryExpression*) malloc(sizeof(struct UnaryExpression));
		unary_exp->unary_type = INCREMENT_T; 
		if ($2->type != INTEGER_T) {
			yyerror("Integer literal expected for operand");
			exit(0);
		}
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		node->unary_expression = unary_exp;
		node->type = INTEGER_T;
		$$ = node;
	}
	| DECREMENT unary_expression {
		struct UnaryExpression* unary_exp = (struct UnaryExpression*) malloc(sizeof(struct UnaryExpression));
		unary_exp->unary_type = DECREMENT_T; 
		if ($2->type != INTEGER_T) {
			yyerror("Integer literal expected for operand");
			exit(0);
		}
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		node->unary_expression = unary_exp;
		node->type = INTEGER_T;
		$$ = node;
	}
	| new_expression {
	}
	;
new_expression:
	NEW new_type_id
	;
new_type_id:
	type_specifier_seq
	;
cast_expression:
	unary_expression
	;
pm_expression:
	cast_expression
	;
multiplicative_expression:
//	pm_expression
	unary_expression {
		$$ = $1;
	}
	| multiplicative_expression MULTIPLICATION unary_expression {
		struct BinaryExpression* bin_exp = (struct BinaryExpression*) malloc(sizeof(struct BinaryExpression)); 
		bin_exp->left = $1;
		bin_exp->right = $3;
		bin_exp->binary_type = MULTIPLICATION_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		if ($1->type == INTEGER_T && $3->type == INTEGER_T) {
			node->type = $1->type;
		} else if ($1->type == INTEGER_T && $3->type == DOUBLE_T) {
			node->type = $3->type;
		} else if ($1->type == DOUBLE_T && $3->type == INTEGER_T) {
			node->type = $1->type;
		} else if ($1->type == INTEGER_T && $3->type == CHAR_T) {
			node->type = $1->type;
		} else if ($1->type == CHAR_T && $3->type == INTEGER_T) {
			node->type = $1->type;
		} else if ($1->type == DOUBLE_T && $3->type == CHAR_T) {
			node->type = $1->type;
		} else if ($1->type == CHAR_T && $3->type == DOUBLE_T) {
			node->type = $3->type;
		} else if ($1->type == DOUBLE_T && $3->type == DOUBLE_T) {
			node->type = $1->type;
		} else if ($1->type == BOOL_T && $3->type == INTEGER_T) {
			node->type = $1->type;
		} else if ($1->type == INTEGER_T && $3->type == BOOL_T) {
			node->type = $3->type;
		} else if ($1->type == BOOL_T && $3->type == BOOL_T) {
			node->type = $1->type;
		} else if ($1->type == BOOL_T && $3->type == DOUBLE_T) {
			node->type = $1->type;
		} else if ($1->type == DOUBLE_T && $3->type == BOOL_T) {
			node->type = $3->type;
		} else if ($1->type == BOOL_T && $3->type == CHAR_T) {
			node->type = $1->type;
		} else if ($1->type == CHAR_T && $3->type == BOOL_T) {
			node->type = $3->type;
		} else {
			yyerror("Invalid operand types for multiplicative expression");
			exit(0);
		}
		
		node->binary_expression = bin_exp;
		$$ = node;
	}
	| multiplicative_expression DIVISION unary_expression {
		struct BinaryExpression* bin_exp = (struct BinaryExpression*) malloc(sizeof(struct BinaryExpression)); 
		bin_exp->left = $1;
		bin_exp->right = $3;
		bin_exp->binary_type = DIVISION_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		if ($1->type == INTEGER_T && $3->type == INTEGER_T) {
			node->type = $1->type;
		} else if ($1->type == INTEGER_T && $3->type == DOUBLE_T) {
			node->type = $3->type;
		} else if ($1->type == DOUBLE_T && $3->type == INTEGER_T) {
			node->type = $1->type;
		} else if ($1->type == INTEGER_T && $3->type == CHAR_T) {
			node->type = $1->type;
		} else if ($1->type == CHAR_T && $3->type == INTEGER_T) {
			node->type = $1->type;
		} else if ($1->type == DOUBLE_T && $3->type == CHAR_T) {
			node->type = $1->type;
		} else if ($1->type == CHAR_T && $3->type == DOUBLE_T) {
			node->type = $3->type;
		} else if ($1->type == DOUBLE_T && $3->type == DOUBLE_T) {
			node->type = $1->type;
		} else if ($1->type == BOOL_T && $3->type == INTEGER_T) {
			node->type = $1->type;
		} else if ($1->type == INTEGER_T && $3->type == BOOL_T) {
			node->type = $3->type;
		} else if ($1->type == BOOL_T && $3->type == BOOL_T) {
			node->type = $1->type;
		} else if ($1->type == BOOL_T && $3->type == DOUBLE_T) {
			node->type = $1->type;
		} else if ($1->type == DOUBLE_T && $3->type == BOOL_T) {
			node->type = $3->type;
		} else if ($1->type == BOOL_T && $3->type == CHAR_T) {
			node->type = $1->type;
		} else if ($1->type == CHAR_T && $3->type == BOOL_T) {
			node->type = $3->type;
		} else {
			yyerror("Invalid operand types for multiplicative expression");
			exit(0);
		}
		node->binary_expression = bin_exp;
		$$ = node;
	}
	| multiplicative_expression MODULO unary_expression {
		struct BinaryExpression* bin_exp = (struct BinaryExpression*) malloc(sizeof(struct BinaryExpression)); 
		bin_exp->left = $1;
		bin_exp->right = $3;
		bin_exp->binary_type = MODULO_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		if ($1->type == INTEGER_T && $3->type == INTEGER_T) {
			node->type = $1->type;
		} else if ($1->type == INTEGER_T && $3->type == CHAR_T) {
			node->type = $1->type;
		} else if ($1->type == CHAR_T && $3->type == INTEGER_T) {
			node->type = $1->type;
		} else {
			yyerror("Invalid operand types for multiplicative expression");
			exit(0);
		}
		node->binary_expression = bin_exp;
		$$ = node;
	}
	;
additive_expression:
	multiplicative_expression {
		$$ = $1;
	}
	| additive_expression ADDITION multiplicative_expression {
		struct BinaryExpression* bin_exp = (struct BinaryExpression*) malloc(sizeof(struct BinaryExpression)); 
		bin_exp->left = $1;
		bin_exp->right = $3;
		bin_exp->binary_type = ADDITION_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		if ($1->type == INTEGER_T && $3->type == INTEGER_T) {
			node->type = $1->type;
		} else if ($1->type == INTEGER_T && $3->type == DOUBLE_T) {
			node->type = $3->type;
		} else if ($1->type == DOUBLE_T && $3->type == INTEGER_T) {
			node->type = $1->type;
		} else if ($1->type == INTEGER_T && $3->type == CHAR_T) {
			node->type = $1->type;
		} else if ($1->type == CHAR_T && $3->type == INTEGER_T) {
			node->type = $1->type;
		} else if ($1->type == DOUBLE_T && $3->type == CHAR_T) {
			node->type = $1->type;
		} else if ($1->type == CHAR_T && $3->type == DOUBLE_T) {
			node->type = $3->type;
		} else if ($1->type == DOUBLE_T && $3->type == DOUBLE_T) {
			node->type = $1->type;
		} else if ($1->type == BOOL_T && $3->type == INTEGER_T) {
			node->type = $1->type;
		} else if ($1->type == INTEGER_T && $3->type == BOOL_T) {
			node->type = $3->type;
		} else if ($1->type == BOOL_T && $3->type == BOOL_T) {
			node->type = $1->type;
		} else if ($1->type == BOOL_T && $3->type == DOUBLE_T) {
			node->type = $1->type;
		} else if ($1->type == DOUBLE_T && $3->type == BOOL_T) {
			node->type = $3->type;
		} else if ($1->type == BOOL_T && $3->type == CHAR_T) {
			node->type = $1->type;
		} else if ($1->type == CHAR_T && $3->type == BOOL_T) {
			node->type = $3->type;
		} else {
			yyerror("Invalid operand types for additive expression");
			exit(0);
		}
		node->binary_expression = bin_exp;
		$$ = node;
	}
	| additive_expression SUBTRACTION multiplicative_expression {
		struct BinaryExpression* bin_exp = (struct BinaryExpression*) malloc(sizeof(struct BinaryExpression)); 
		bin_exp->left = $1;
		bin_exp->right = $3;
		bin_exp->binary_type = SUBTRACTION_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		if ($1->type == INTEGER_T && $3->type == INTEGER_T) {
			node->type = $1->type;
		} else if ($1->type == INTEGER_T && $3->type == DOUBLE_T) {
			node->type = $3->type;
		} else if ($1->type == DOUBLE_T && $3->type == INTEGER_T) {
			node->type = $1->type;
		} else if ($1->type == INTEGER_T && $3->type == CHAR_T) {
			node->type = $1->type;
		} else if ($1->type == CHAR_T && $3->type == INTEGER_T) {
			node->type = $1->type;
		} else if ($1->type == DOUBLE_T && $3->type == CHAR_T) {
			node->type = $1->type;
		} else if ($1->type == CHAR_T && $3->type == DOUBLE_T) {
			node->type = $3->type;
		} else if ($1->type == DOUBLE_T && $3->type == DOUBLE_T) {
			node->type = $1->type;
		} else if ($1->type == BOOL_T && $3->type == INTEGER_T) {
			node->type = $1->type;
		} else if ($1->type == INTEGER_T && $3->type == BOOL_T) {
			node->type = $3->type;
		} else if ($1->type == BOOL_T && $3->type == BOOL_T) {
			node->type = $1->type;
		} else if ($1->type == BOOL_T && $3->type == DOUBLE_T) {
			node->type = $1->type;
		} else if ($1->type == DOUBLE_T && $3->type == BOOL_T) {
			node->type = $3->type;
		} else if ($1->type == BOOL_T && $3->type == CHAR_T) {
			node->type = $1->type;
		} else if ($1->type == CHAR_T && $3->type == BOOL_T) {
			node->type = $3->type;
		} else {
			yyerror("Invalid operand types for additive expression");
			exit(0);
		}
		node->binary_expression = bin_exp;
		$$ = node;
	}
	;
shift_expression:
	additive_expression {
		$$ = $1;
	}
	| shift_expression LEFT_SHIFT additive_expression {
		struct BinaryExpression* bin_exp = (struct BinaryExpression*) malloc(sizeof(struct BinaryExpression)); 
		bin_exp->left = $1;
		bin_exp->right = $3;
		bin_exp->binary_type = LEFT_SHIFT_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		if ($1->type == INTEGER_T && $3->type == INTEGER_T) {
			node->type = $1->type;
		} else {
			yyerror("Invalid operand types for shift expression");
			exit(0);
		}
		node->binary_expression = bin_exp;
		$$ = node;
	}
	| shift_expression RIGHT_SHIFT additive_expression {
		struct BinaryExpression* bin_exp = (struct BinaryExpression*) malloc(sizeof(struct BinaryExpression)); 
		bin_exp->left = $1;
		bin_exp->right = $3;
		bin_exp->binary_type = RIGHT_SHIFT_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		if ($1->type == INTEGER_T && $3->type == INTEGER_T) {
			node->type = $1->type;
		} else {
			yyerror("Invalid operand types for shift expression");
			exit(0);
		}
		node->binary_expression = bin_exp;
		$$ = node;
	}
	;
relational_expression:
	shift_expression {
		$$ = $1;
	}
	| relational_expression LESS_THAN shift_expression {
		struct BinaryExpression* bin_exp = (struct BinaryExpression*) malloc(sizeof(struct BinaryExpression)); 
		bin_exp->left = $1;
		bin_exp->right = $3;
		bin_exp->binary_type = LESS_THAN_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		if ($1->type == INTEGER_T && $3->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ($1->type == INTEGER_T && $3->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ($1->type == DOUBLE_T && $3->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ($1->type == INTEGER_T && $3->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ($1->type == CHAR_T && $3->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ($1->type == DOUBLE_T && $3->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ($1->type == CHAR_T && $3->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ($1->type == DOUBLE_T && $3->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ($1->type == BOOL_T && $3->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ($1->type == INTEGER_T && $3->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ($1->type == BOOL_T && $3->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ($1->type == BOOL_T && $3->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ($1->type == DOUBLE_T && $3->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ($1->type == BOOL_T && $3->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ($1->type == CHAR_T && $3->type == BOOL_T) {
			node->type = BOOL_T;
		} else {
			yyerror("Invalid operand types for relational expression");
			exit(0);
		}
		node->binary_expression = bin_exp;
		$$ = node;
	}
	| relational_expression GREATER_THAN shift_expression {
		struct BinaryExpression* bin_exp = (struct BinaryExpression*) malloc(sizeof(struct BinaryExpression)); 
		bin_exp->left = $1;
		bin_exp->right = $3;
		bin_exp->binary_type = GREATER_THAN_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		if ($1->type == INTEGER_T && $3->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ($1->type == INTEGER_T && $3->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ($1->type == DOUBLE_T && $3->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ($1->type == INTEGER_T && $3->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ($1->type == CHAR_T && $3->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ($1->type == DOUBLE_T && $3->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ($1->type == CHAR_T && $3->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ($1->type == DOUBLE_T && $3->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ($1->type == BOOL_T && $3->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ($1->type == INTEGER_T && $3->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ($1->type == BOOL_T && $3->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ($1->type == BOOL_T && $3->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ($1->type == DOUBLE_T && $3->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ($1->type == BOOL_T && $3->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ($1->type == CHAR_T && $3->type == BOOL_T) {
			node->type = BOOL_T;
		} else {
			yyerror("Invalid operand types for relational expression");
			exit(0);
		}
		node->binary_expression = bin_exp;
		$$ = node;
	}
	| relational_expression LESS_OR_EQUAL_THAN shift_expression {
		struct BinaryExpression* bin_exp = (struct BinaryExpression*) malloc(sizeof(struct BinaryExpression)); 
		bin_exp->left = $1;
		bin_exp->right = $3;
		bin_exp->binary_type = LESS_OR_EQUAL_THAN_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		if ($1->type == INTEGER_T && $3->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ($1->type == INTEGER_T && $3->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ($1->type == DOUBLE_T && $3->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ($1->type == INTEGER_T && $3->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ($1->type == CHAR_T && $3->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ($1->type == DOUBLE_T && $3->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ($1->type == CHAR_T && $3->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ($1->type == DOUBLE_T && $3->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ($1->type == BOOL_T && $3->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ($1->type == INTEGER_T && $3->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ($1->type == BOOL_T && $3->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ($1->type == BOOL_T && $3->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ($1->type == DOUBLE_T && $3->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ($1->type == BOOL_T && $3->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ($1->type == CHAR_T && $3->type == BOOL_T) {
			node->type = BOOL_T;
		} else {
			yyerror("Invalid operand types for relational expression");
			exit(0);
		}
		node->binary_expression = bin_exp;
		$$ = node;
	}
	| relational_expression GREATER_OR_EQUAL_THAN shift_expression {
		struct BinaryExpression* bin_exp = (struct BinaryExpression*) malloc(sizeof(struct BinaryExpression)); 
		bin_exp->left = $1;
		bin_exp->right = $3;
		bin_exp->binary_type = GREATER_OR_EQUAL_THAN_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		if ($1->type == INTEGER_T && $3->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ($1->type == INTEGER_T && $3->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ($1->type == DOUBLE_T && $3->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ($1->type == INTEGER_T && $3->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ($1->type == CHAR_T && $3->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ($1->type == DOUBLE_T && $3->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ($1->type == CHAR_T && $3->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ($1->type == DOUBLE_T && $3->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ($1->type == BOOL_T && $3->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ($1->type == INTEGER_T && $3->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ($1->type == BOOL_T && $3->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ($1->type == BOOL_T && $3->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ($1->type == DOUBLE_T && $3->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ($1->type == BOOL_T && $3->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ($1->type == CHAR_T && $3->type == BOOL_T) {
			node->type = BOOL_T;
		} else {
			yyerror("Invalid operand types for relational expression");
			exit(0);
		}
		node->binary_expression = bin_exp;
		$$ = node;
	}
	;
equality_expression:
	relational_expression {
		$$ = $1;
	}
	| equality_expression EQUAL relational_expression {
		struct BinaryExpression* bin_exp = (struct BinaryExpression*) malloc(sizeof(struct BinaryExpression)); 
		bin_exp->left = $1;
		bin_exp->right = $3;
		bin_exp->binary_type = EQUAL_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		if ($1->type == INTEGER_T && $3->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ($1->type == INTEGER_T && $3->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ($1->type == DOUBLE_T && $3->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ($1->type == INTEGER_T && $3->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ($1->type == CHAR_T && $3->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ($1->type == DOUBLE_T && $3->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ($1->type == CHAR_T && $3->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ($1->type == DOUBLE_T && $3->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ($1->type == BOOL_T && $3->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ($1->type == INTEGER_T && $3->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ($1->type == BOOL_T && $3->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ($1->type == BOOL_T && $3->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ($1->type == DOUBLE_T && $3->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ($1->type == BOOL_T && $3->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ($1->type == CHAR_T && $3->type == BOOL_T) {
			node->type = BOOL_T;
		} else {
			yyerror("Invalid operand types for equality expression");
			exit(0);
		}
		node->binary_expression = bin_exp;
		$$ = node;
	}
	| equality_expression NOT_EQUAL relational_expression {
		struct BinaryExpression* bin_exp = (struct BinaryExpression*) malloc(sizeof(struct BinaryExpression)); 
		bin_exp->left = $1;
		bin_exp->right = $3;
		bin_exp->binary_type = NOT_EQUAL_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		if ($1->type == INTEGER_T && $3->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ($1->type == INTEGER_T && $3->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ($1->type == DOUBLE_T && $3->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ($1->type == INTEGER_T && $3->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ($1->type == CHAR_T && $3->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ($1->type == DOUBLE_T && $3->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ($1->type == CHAR_T && $3->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ($1->type == DOUBLE_T && $3->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ($1->type == BOOL_T && $3->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ($1->type == INTEGER_T && $3->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ($1->type == BOOL_T && $3->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ($1->type == BOOL_T && $3->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ($1->type == DOUBLE_T && $3->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ($1->type == BOOL_T && $3->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ($1->type == CHAR_T && $3->type == BOOL_T) {
			node->type = BOOL_T;
		} else {
			yyerror("Invalid operand types for equality expression");
			exit(0);
		}
		node->binary_expression = bin_exp;
		$$ = node;
	}
	;
and_expression:
	equality_expression {
		$$ = $1;
	}
	| and_expression BITWISE_AND equality_expression {
		struct BinaryExpression* bin_exp = (struct BinaryExpression*) malloc(sizeof(struct BinaryExpression)); 
		bin_exp->left = $1;
		bin_exp->right = $3;
		bin_exp->binary_type = BITWISE_AND_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		if ($1->type == INTEGER_T && $3->type == INTEGER_T) {
			node->type = $1->type;
		} else if ($1->type == INTEGER_T && $3->type == CHAR_T) {
			node->type = $1->type;
		} else if ($1->type == CHAR_T && $3->type == INTEGER_T) {
			node->type = $1->type;
		} else {
			yyerror("Invalid operand types for bitwise and expression");
			exit(0);
		}
		node->binary_expression = bin_exp;
		$$ = node;
	}
	;
exclusive_or_expression:
	and_expression {
		$$ = $1;
	}
	| exclusive_or_expression BITWISE_XOR and_expression {
		struct BinaryExpression* bin_exp = (struct BinaryExpression*) malloc(sizeof(struct BinaryExpression)); 
		bin_exp->left = $1;
		bin_exp->right = $3;
		bin_exp->binary_type = BITWISE_XOR_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		if ($1->type == INTEGER_T && $3->type == INTEGER_T) {
			node->type = $1->type;
		} else if ($1->type == INTEGER_T && $3->type == CHAR_T) {
			node->type = $1->type;
		} else if ($1->type == CHAR_T && $3->type == INTEGER_T) {
			node->type = $1->type;
		} else {
			yyerror("Invalid operand types for bitwise xor expression");
			exit(0);
		}
		node->binary_expression = bin_exp;
		$$ = node;
	}
	;
inclusive_or_expression:
	exclusive_or_expression {
		$$ = $1;
	}
	| inclusive_or_expression BITWISE_OR exclusive_or_expression {
		struct BinaryExpression* bin_exp = (struct BinaryExpression*) malloc(sizeof(struct BinaryExpression)); 
		bin_exp->left = $1;
		bin_exp->right = $3;
		bin_exp->binary_type = BITWISE_OR_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		if ($1->type == INTEGER_T && $3->type == INTEGER_T) {
			node->type = $1->type;
		} else if ($1->type == INTEGER_T && $3->type == CHAR_T) {
			node->type = $1->type;
		} else if ($1->type == CHAR_T && $3->type == INTEGER_T) {
			node->type = $1->type;
		} else {
			yyerror("Invalid operand types for bitwise or expression");
			exit(0);
		}
		node->binary_expression = bin_exp;
		$$ = node;
	}
	;
logical_and_expression:
	inclusive_or_expression {
		$$ = $1;
	}
	| logical_and_expression AND inclusive_or_expression {
		struct BinaryExpression* bin_exp = (struct BinaryExpression*) malloc(sizeof(struct BinaryExpression)); 
		bin_exp->left = $1;
		bin_exp->right = $3;
		bin_exp->binary_type = LOGICAL_AND_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		if ($1->type == INTEGER_T && $3->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ($1->type == INTEGER_T && $3->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ($1->type == DOUBLE_T && $3->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ($1->type == INTEGER_T && $3->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ($1->type == CHAR_T && $3->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ($1->type == DOUBLE_T && $3->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ($1->type == CHAR_T && $3->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ($1->type == DOUBLE_T && $3->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ($1->type == BOOL_T && $3->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ($1->type == INTEGER_T && $3->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ($1->type == BOOL_T && $3->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ($1->type == BOOL_T && $3->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ($1->type == DOUBLE_T && $3->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ($1->type == BOOL_T && $3->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ($1->type == CHAR_T && $3->type == BOOL_T) {
			node->type = BOOL_T;
		} else {
			yyerror("Invalid operand types for logical and expression");
			exit(0);
		}
		node->binary_expression = bin_exp;
		$$ = node;
	}
	;
logical_or_expression:
	logical_and_expression {
		$$ = $1;
	}
	| logical_or_expression OR logical_and_expression {
		struct BinaryExpression* bin_exp = (struct BinaryExpression*) malloc(sizeof(struct BinaryExpression)); 
		bin_exp->left = $1;
		bin_exp->right = $3;
		bin_exp->binary_type = LOGICAL_OR_T;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		if ($1->type == INTEGER_T && $3->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ($1->type == INTEGER_T && $3->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ($1->type == DOUBLE_T && $3->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ($1->type == INTEGER_T && $3->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ($1->type == CHAR_T && $3->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ($1->type == DOUBLE_T && $3->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ($1->type == CHAR_T && $3->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ($1->type == DOUBLE_T && $3->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ($1->type == BOOL_T && $3->type == INTEGER_T) {
			node->type = BOOL_T;
		} else if ($1->type == INTEGER_T && $3->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ($1->type == BOOL_T && $3->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ($1->type == BOOL_T && $3->type == DOUBLE_T) {
			node->type = BOOL_T;
		} else if ($1->type == DOUBLE_T && $3->type == BOOL_T) {
			node->type = BOOL_T;
		} else if ($1->type == BOOL_T && $3->type == CHAR_T) {
			node->type = BOOL_T;
		} else if ($1->type == CHAR_T && $3->type == BOOL_T) {
			node->type = BOOL_T;
		} else {
			yyerror("Invalid operand types for logical and expression");
			exit(0);
		}
		node->binary_expression = bin_exp;
		$$ = node;
	}
	;
conditional_expression:
	logical_or_expression {
		$$ = $1;
	}
//	| logical_or_expression TERNARY expression COLON assignment_expression
	;
assignment_expression:
	conditional_expression {
		$$ = $1;
	}
	| logical_or_expression assignment_operator assignment_expression {
		fprintf(stderr, "Inside assignment expression left type: %d right type %d\n", $1->type, $3->type);
		struct BinaryExpression* bin_exp = (struct BinaryExpression*) malloc(sizeof(struct BinaryExpression)); 
		bin_exp->left = $1;
		bin_exp->right = $3;
		bin_exp->binary_type = $2;
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		if ($1->type == INTEGER_T && $3->type == INTEGER_T) {
			node->type = $1->type;
		} else if ($1->type == INTEGER_T && $3->type == DOUBLE_T) {
			node->type = $3->type;
		} else if ($1->type == DOUBLE_T && $3->type == INTEGER_T) {
			node->type = $1->type;
		} else if ($1->type == INTEGER_T && $3->type == CHAR_T) {
			node->type = $1->type;
		} else if ($1->type == CHAR_T && $3->type == INTEGER_T) {
			node->type = $1->type;
		} else if ($1->type == DOUBLE_T && $3->type == CHAR_T) {
			node->type = $1->type;
		} else if ($1->type == CHAR_T && $3->type == DOUBLE_T) {
			node->type = $3->type;
		} else if ($1->type == BOOL_T && $3->type == INTEGER_T) {
			node->type = $1->type;
		} else if ($1->type == INTEGER_T && $3->type == BOOL_T) {
			node->type = $3->type;
		} else if ($1->type == BOOL_T && $3->type == BOOL_T) {
			node->type = $1->type;
		} else if ($1->type == BOOL_T && $3->type == DOUBLE_T) {
			node->type = $1->type;
		} else if ($1->type == DOUBLE_T && $3->type == BOOL_T) {
			node->type = $3->type;
		} else if ($1->type == BOOL_T && $3->type == CHAR_T) {
			node->type = $1->type;
		} else if ($1->type == CHAR_T && $3->type == BOOL_T) {
			node->type = $3->type;
		} else {
			yyerror("Invalid operand types for assignment expression");
			exit(0);
		}
		node->binary_expression = bin_exp;
		$$ = node;
	}
//	| simple_type_specifier identifier assignment_operator logical_or_expression
	;

assignment_operator:
	ASSIGNMENT { $$ = ASSIGNMENT_T; }
	| MULTIPLICATION_EQUAL { $$ = MULTIPLICATION_EQUAL_T; }
	| DIVISION_EQUAL { $$ = DIVISION_EQUAL_T; }
	| MODULO_EQUAL { $$ = MODULO_EQUAL_T; }
	| ADDITION_EQUAL { $$ = ADDITION_EQUAL_T; }
	| SUBTRACTION_EQUAL { $$ = SUBTRACTION_EQUAL_T; }
	| RIGHT_SHIFT_EQUAL { $$ = RIGHT_SHIFT_EQUAL_T; }
	| LEFT_SHIFT_EQUAL { $$ = LEFT_SHIFT_EQUAL_T; }
	| AND_EQUAL { $$ = AND_EQUAL_T; }
	| XOR_EQUAL { $$ = XOR_EQUAL_T; }
	| OR_EQUAL { $$ = OR_EQUAL_T; }
	;
expression:
	assignment_expression {
		$$ = $1;
	}
	| expression COMMA assignment_expression {
		$3->next = $1;
		$$ = $3;
	}
	;
constant_expression:
	conditional_expression
	;

statement:
	expression_statement
	| compound_statement {
	}
	| selection_statement {
	}
	| iteration_statement {
	}
	| declaration_statement {
	}
	| jump_statement {
	}
	;
expression_statement:
	expression SEMI_COLON {
	}
	;
compound_statement:
	open_brace close_brace { printf("Empty compound statement\n"); }
	| open_brace statement_seq.opt close_brace { printf("Statement inside braces\n"); }
	;
statement_seq.opt:
	statement {
	}
	| statement_seq.opt statement
	;
selection_statement:
	IF OPEN_PARENTHESES condition CLOSE_PARENTHESES statement
	| IF OPEN_PARENTHESES condition CLOSE_PARENTHESES statement ELSE statement
	;
condition:
	expression {
		$$ = $1;
	}
	| simple_type_specifier identifier ASSIGNMENT assignment_expression {
		printf("condition found\n");
		struct Declarator* decl = (struct Declarator*) malloc(sizeof(struct Declarator));
		decl->declarator_type = VAR_DECL_T;
		strcpy(decl->id, $2);
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		node->declarator = decl;
		node->type = $1;

		union Data data;
		struct Sym* sym = add_sym(decl->id, $4, $1);
		if (sym == 0) {
			fprintf(stderr, "Symbol %s is already defined\n", decl->id);			
			while (cur_scope->head_sym) {
				fprintf(stderr, "Inside scope: %s\n", cur_scope->head_sym->name);
				cur_scope->head_sym = cur_scope->head_sym->next;
			}
			exit(0);
		}

		$$ = node;
	}
	;
iteration_statement:
	FOR open_parentheses condition SEMI_COLON expression SEMI_COLON assignment_expression close_parentheses statement
	;
for_init_statement:
	expression_statement
	| simple_declaration
	;
jump_statement:
	RETURN expression SEMI_COLON {
		LiteralType ret_type = cur_scope->ret_type;
		if (ret_type == VOID_T) {
			fprintf(stderr, "Cannot return value from void function\n");
			exit(0);
		}
		if (ret_type == STRING_T) {
			if ($2->type != STRING_T) {
				fprintf(stderr, "Cannot return value different than string type\n");
				exit(0);
			}
		} else {
			if ($2->type == STRING_T) {
				fprintf(stderr, "Cannot return string from primitive value function\n");
				exit(0);
			}
		}
	}
	;

declaration_statement:
	simple_declaration {
		printf("Declaration statement\n");
	}
	;
translation_unit:
	declaration_seq { printf("C++ program successfully parsed\n"); }
	;
declaration_seq:
	declaration
	| declaration_seq declaration
	;
declaration:
	simple_declaration { printf("Block declaration\n"); }
	| function_definition { printf("Function declaration\n"); }
	;
block_declaration:
	simple_declaration
	;
simple_declaration:
	cv_qualifier simple_type_specifier init_declarator_list SEMI_COLON
	| simple_type_specifier init_declarator_list SEMI_COLON	{
		fprintf(stderr, "Simple declaration rule!\n");
	
		struct Node* head = $2;
		while (head) {
			fprintf(stderr, "Adding identifier %s\n", head->declarator->id);
			if (head->declarator->declarator_type == PTR_DECL_T) {
				union Data data;
				struct Sym* sym;
				if ($1 == INTEGER_T) sym = add_sym(head->declarator->id, head, INTEGER_PTR_T), head->type = INTEGER_PTR_T;
				else if ($1 == DOUBLE_T) sym = add_sym(head->declarator->id, head, DOUBLE_PTR_T), head->type = DOUBLE_PTR_T;
				else if ($1 == CHAR_T) sym = add_sym(head->declarator->id, head, CHAR_PTR_T), head->type = CHAR_PTR_T;
				else if ($1 == BOOL_T) sym = add_sym(head->declarator->id, head, BOOL_PTR_T), head->type = BOOL_PTR_T;
				else if ($1 == VOID_T) sym = add_sym(head->declarator->id, head, VOID_PTR_T), head->type = VOID_PTR_T;
				else assert(0);
				if (sym == 0) {
					fprintf(stderr, "Symbol %s is already defined\n", head->declarator->id);
					exit(0);
				}
			} else if (head->declarator->declarator_type == ARR_DECL_T) {
				union Data data;
				struct Sym* sym;
				if ($1 == INTEGER_T) sym = add_sym(head->declarator->id, head, INTEGER_PTR_T), head->type = INTEGER_ARR_T;
				else if ($1 == DOUBLE_T) sym = add_sym(head->declarator->id, head, DOUBLE_PTR_T), head->type = DOUBLE_ARR_T;
				else if ($1 == CHAR_T) sym = add_sym(head->declarator->id, head, CHAR_PTR_T), head->type = CHAR_ARR_T;
				else if ($1 == BOOL_T) sym = add_sym(head->declarator->id, head, BOOL_PTR_T), head->type = BOOL_ARR_T;
				else assert(0);
//				if ($1 == VOID_T) sym = add_sym(head->declarator->id, data, VOID_PTR_T), head->type = VOID_ARR_T;
				if (sym == 0) {
					fprintf(stderr, "Symbol %s is already defined\n", head->declarator->id);
					exit(0);
				}
			} else {
				union Data data;
				struct Sym* sym = add_sym(head->declarator->id, head, $1);
				head->type = $1;
				if (sym == 0) {
					fprintf(stderr, "Symbol %s is already defined\n", head->declarator->id);
					exit(0);
				}
			}
			head = head->next;
		}
	}
	| elaborated_type_specifier init_declarator_list SEMI_COLON
	| class_specifier init_declarator_list SEMI_COLON {
		printf("Class declaration detected\n");
	}
	| class_specifier SEMI_COLON
//	type_specifier_seq init_declarator_list SEMI_COLON
//	simple_type_specifier init_declarator_list SEMI_COLON
	;
init_declarator_list:
	init_declarator {
		$$ = $1;
	}
	| init_declarator_list COMMA init_declarator {
		$3->next = $1;
		$$ = $3;
	}
	;
init_declarator:
	declarator {
		$$ = $1;
	}
	| declarator initializer.opt {
		$$ = $1;
	}
	;
/*
init_declarator:
	declarator_id
	| declarator_id EQUAL initializer_clause
*/	
initializer.opt:
//	%empty
	ASSIGNMENT initializer_clause
	| OPEN_PARENTHESES expression_list CLOSE_PARENTHESES
	;
	
decl_specifier_seq:
	decl_specifier
	| decl_specifier decl_specifier_seq
	;
decl_specifier:
	type_specifier
	;
type_specifier_seq:
	type_specifier
	| type_specifier type_specifier_seq
	;
type_specifier:
	simple_type_specifier
	| elaborated_type_specifier
	| cv_qualifier
	| class_specifier
	;
simple_type_specifier:
	CHARKW {
		$$ = CHAR_T;
	}
	| BOOLKW {
		$$ = BOOL_T;
	}
	| INTKW {
		$$ = INTEGER_T;
	}
	| DOUBLEKW {
		$$ = DOUBLE_T;
	}
	| VOIDKW {
		$$ = VOID_T;		
	}
	
	;
	
elaborated_type_specifier:
	class_key identifier
	;
function_definition: /* TEMPORAL */
	simple_type_specifier declarator {
		
		
		struct Node* head = $2;
		while (head) {
			fprintf(stderr, "Adding function identifier %s\n", head->declarator->id);
			union Data data;
			struct Sym* sym = add_sym(head->declarator->id, head, $1);
			head->type = $1;
			if (sym == 0) {
				fprintf(stderr, "Function %s is already defined\n", head->declarator->id);
				exit(0);
			}
			
			head = head->next;
		}
		
		create_scope_type($1);
		printf("Creating function scope\n");
		
		head = $2;
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
		
	} function_body { 
		delete_scope(); 
	}
	;
	/* real one v*/
/*function_body:
	compound_statement {
		printf("Function body\n");
	}
	;
*/
function_body:
	OPEN_BRACE CLOSE_BRACE {
		printf("Empty function body\n");
	}
	| OPEN_BRACE statement_seq.opt CLOSE_BRACE {
		printf("Function body\n");
	}
	;
type_name:
	class_name
	;
declarator:
	direct_declarator {
//		strcpy($$, $1);
		$$ = $1;
	}
	| ptr_operator declarator {
		if ($1 == PTR_DECL_T) {
			$2->declarator->declarator_type = $1;
		}
		$$ = $2;
	}
	;
direct_declarator:
	declarator_id {
//		struct IdExpression* id_expression = (struct IdExpression*) malloc(sizeof(struct IdExpression));
//		strcpy(id_expression->id, $1);
//		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
//		node->id_expression = id_expression;
//		node->type = sym->type;
//		$$ = node;		
		struct Declarator* decl = (struct Declarator*) malloc(sizeof(struct Declarator));
		decl->declarator_type = VAR_DECL_T;
		strcpy(decl->id, $1);
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		node->declarator = decl;
		$$ = node;
	}
	| direct_declarator parameters_and_qualifiers {
		struct Node* node = $1;
		node->declarator->params = $2;
		node->declarator->declarator_type = FUN_DECL_T;
		$$ = node;
	}
	| direct_declarator OPEN_BRACKET constant_expression CLOSE_BRACKET {
//		struct Declarator* decl = (struct Declarator*) malloc(sizeof(struct Declarator));
//		decl->declarator_type = ARR_DECL_T;
//		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
//		node->declarator = decl;
//		$$ = node;
		struct Node* node = $1;
		node->declarator->declarator_type = ARR_DECL_T;
		$$ = node;
	}
	| direct_declarator OPEN_BRACKET CLOSE_BRACKET {
//		struct Declarator* decl = (struct Declarator*) malloc(sizeof(struct Declarator));
//		decl->declarator_type = ARR_DECL_T;
//		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
//		node->declarator = decl;
//		$$ = node;
		struct Node* node = $1;
		node->declarator->declarator_type = ARR_DECL_T;
		$$ = node;
	}
	;
	
noptr_declarator:
	declarator_id { printf("Declarator id\n"); }
	;
	
parameters_and_qualifiers:
//	OPEN_PARENTHESES CLOSE_PARENTHESES
	open_parentheses parameter_declaration_clause.opt close_parentheses {
		$$ = $2;
//		create_scope();
	}
	;
//trailing_return_type:
//	POINTER_ACCESS trailing_type_specifier_seq
//	;
	
parameter_declaration_clause.opt:
	%empty {
		$$ = 0;
	}
	| parameter_declaration_list {
		$$ = $1;
	}
	;
	
parameter_declaration_list:
	parameter_declaration {
		$$ = $1;
	}
	| parameter_declaration_list COMMA parameter_declaration {
		$3->next = $1;
		$$ = $3;
	}
	;
parameter_declaration:
	simple_type_specifier identifier {
		struct Declarator* decl = (struct Declarator*) malloc(sizeof(struct Declarator));
		decl->declarator_type = VAR_DECL_T;
		strcpy(decl->id, $2);
		struct Node* node = (struct Node*) malloc(sizeof(struct Node));
		node->declarator = decl;
		node->type = $1;
	/*
		union Data data;
		struct Sym* sym = add_sym(decl->id, data, $1);
		if (sym == 0) {
			fprintf(stderr, "Symbol %s is already defined\n", decl->id);
			exit(0);
		}
	*/
		$$ = node;		
	}
	;
ptr_operator:
	MULTIPLICATION cv_qualifier_seq { $$ = PTR_DECL_T; }
	| BITWISE_AND { $$ = DEREF_DECL_T; }
//	| DOUBLE_COLON nested_name_specifier MULTIPLICATION cv_qualifier_seq
	;
cv_qualifier_seq:
	cv_qualifier cv_qualifier_seq
	;
cv_qualifier:
	CONST
	;
declarator_id:
	id_expression {
		strcpy($$, $1);
	}
	;

initializer_clause:
	assignment_expression
	| open_brace initializer_list COMMA close_brace
	| open_brace close_brace
	;
initializer_list:
	initializer_clause
	| initializer_list COMMA initializer_clause
	;
class_name:
	identifier
	;
class_specifier:
	class_head open_brace member_specification.opt close_brace
	;
class_head:
	class_key identifier
	;
class_key:
	CLASS
	;
member_specification.opt:
	%empty
	| member_declaration member_specification.opt
	| access_specifier COLON member_specification.opt
	;
access_specifier:
	PUBLIC
	| PRIVATE
	;
member_declaration:
//	decl_specifier_seq member_declarator_list SEMI_COLON
	simple_type_specifier member_declarator_list SEMI_COLON
//	simple_type_specifier identifier SEMI_COLON
	| function_definition SEMI_COLON
	| function_definition
	;
member_declarator_list:
	member_declarator
	| member_declarator_list COMMA member_declarator
	;
member_declarator:
	declarator
	| declarator pure_specifier
//	| declarator constant_expression
	;
pure_specifier:
	ASSIGNMENT "0"
	;
constant_initializer:
	ASSIGNMENT constant_expression
	;
ctor_initializer:
	COLON mem_initializer_list
	;
mem_initializer_list:
	mem_initializer
	| mem_initializer COMMA mem_initializer_list
	;
mem_initializer:
	mem_initializer_id OPEN_PARENTHESES expression_list CLOSE_PARENTHESES
	;
mem_initializer_id:
	identifier
	| DOUBLE_COLON nested_name_specifier class_name
	;

%%

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
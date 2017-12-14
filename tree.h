#include <stdlib.h>
#include "types.h"

#ifndef TREE_H
#define TREE_H

struct Node;

struct UnaryExpression {
	UnaryExpressionType unary_type;
	struct Node* expression;
};

struct PostfixExpression;

struct IdExpression {
	char id[32];
};

struct Literal {
	LiteralType literal_type;
	union {
		int ival;
		float fval;
		char cval;
		char sval[32];
	};
};

struct PrimaryExpression {
	PrimaryExpressionType primary_type;
	struct Node* which;
};

struct BinaryExpression {
	BinaryExpressionType binary_type;
	struct Node* left;
	struct Node* right;
};

struct Declarator {
	DeclaratorType declarator_type;
	char id[32];
	struct Node* params;
};

struct Node {
	NodeType node_type;	
	LiteralType type;
	union {
		struct Literal* literal_expression;
		struct Declarator* declarator;
		struct IdExpression* id_expression;
		struct UnaryExpression* unary_expression;
		struct BinaryExpression* binary_expression;
		struct PrimaryExpression* primary_expression;
		struct PostfixExpression* postfix_expression;
		struct Symbol* sym;
	};
	struct Node* next;
};

#endif
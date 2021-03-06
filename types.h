#include <stdlib.h>

#ifndef TYPES_H
#define TYPES_H

typedef enum {
	UNARY_OPERATOR,
	BINARY_OPERATOR
} NodeType;

typedef enum {
	INCREMENT_T,
	DECREMENT_T
} UnaryExpressionType;

typedef enum {
	ADDITION_T,
	SUBTRACTION_T,
	MULTIPLICATION_T,
	DIVISION_T,
	MODULO_T,
	LEFT_SHIFT_T,
	RIGHT_SHIFT_T,
	LESS_THAN_T,
	LESS_OR_EQUAL_THAN_T,
	GREATER_THAN_T,
	GREATER_OR_EQUAL_THAN_T,
	EQUAL_T,
	NOT_EQUAL_T,
	BITWISE_AND_T,
	BITWISE_OR_T,
	BITWISE_XOR_T,
	LOGICAL_AND_T,
	LOGICAL_OR_T,
	ASSIGNMENT_T,
	MULTIPLICATION_EQUAL_T,
	DIVISION_EQUAL_T,
	MODULO_EQUAL_T,
	ADDITION_EQUAL_T,
	SUBTRACTION_EQUAL_T,
	RIGHT_SHIFT_EQUAL_T,
	LEFT_SHIFT_EQUAL_T,
	AND_EQUAL_T,
	XOR_EQUAL_T,
	OR_EQUAL_T
} BinaryExpressionType;

typedef enum {
	VAR_DECL_T,
	FUN_DECL_T,
	ARR_DECL_T,
	PTR_DECL_T,
	DEREF_DECL_T
} DeclaratorType;

typedef enum {
	INTEGER_T,
	DOUBLE_T,
	CHAR_T,
	STRING_T,
	BOOL_T,
	VOID_T,
	INTEGER_PTR_T,
	DOUBLE_PTR_T,
	CHAR_PTR_T,
	VOID_PTR_T,
	BOOL_PTR_T,
	INTEGER_ARR_T,
	DOUBLE_ARR_T,
	CHAR_ARR_T,
	BOOL_ARR_T
} LiteralType;

typedef enum {
	ID_EXPRESSION_T,
	LITERAL_T
} PrimaryExpressionType;

typedef enum {
	TEMP_T
} PostfixExpressionType;


#endif
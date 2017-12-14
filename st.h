#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

#ifndef ST_H
#define ST_H

const int CV_INTEGER = 0;
const int CV_DOUBLE = 1;
const int CV_STRING = 2;
const int CV_BOOL = 3;
const int CV_CHAR = 4;
const int CV_VOID = 5;

union Data {
	int ival;
	float fval;
	char sval[32];
	char cval;
};
	
struct Sym {
//	union Data data;
	struct Node* node;
	LiteralType type;
	char name[32];
	struct Sym* next;
};

struct Scope {
	struct Sym* head_sym;
	struct Scope* prev;
	int depth;
	LiteralType ret_type;
};

struct Scope* cur_scope;

struct SymTable {
	struct Scope cur_scope;
};

struct Sym* get_sym_scope(char* name, struct Scope* scope) {
	struct Sym* cur_sym = scope->head_sym;
	while (cur_sym) {
		if (strcmp(cur_sym->name, name) == 0) {
			return cur_sym;
		}
		cur_sym = cur_sym->next;
	}
	if (scope->prev) return get_sym_scope(name, scope->prev);
	return 0;
}

int is_sym_in_scope(char* name) {
	struct Sym* cur_sym = cur_scope->head_sym;
	while (cur_sym) {
		if (strcmp(cur_sym->name, name) == 0) {
			return 1;
		}
		cur_sym = cur_sym->next;
	}
	return 0;
}

struct Sym* add_sym_scope(char* name, struct Node* node, int type, struct Scope* scope) {
	if (is_sym_in_scope(name) == 1) return 0;
	struct Sym* new_sym = (struct Sym*) malloc(sizeof(struct Sym));
	strcpy(new_sym->name, name);
//	new_sym->data = data;
	new_sym->node = node;
	new_sym->type = type;
	new_sym->next = scope->head_sym;
	scope->head_sym = new_sym;
	return new_sym;
}


struct Sym* get_sym(char* name) {
	return get_sym_scope(name, cur_scope);
}

struct Sym* add_sym(char* name, struct Node* node, int type) {
	return add_sym_scope(name, node, type, cur_scope);
}

void init() {
	cur_scope = (struct Scope*) malloc(sizeof(struct Scope));	
}

struct Scope* create_scope() {
	struct Scope* new_scope = (struct Scope*) malloc(sizeof(struct Scope));
	new_scope->prev = cur_scope;
	cur_scope = new_scope;
	if (cur_scope->prev) cur_scope->depth = cur_scope->prev->depth;
	else cur_scope->depth = 0;
	cur_scope->ret_type = VOID_T;
	return new_scope;
}


struct Scope* create_scope_type(int typ) {
	struct Scope* new_scope = (struct Scope*) malloc(sizeof(struct Scope));
	new_scope->prev = cur_scope;
	cur_scope = new_scope;
	if (cur_scope->prev) cur_scope->depth = cur_scope->prev->depth;
	else cur_scope->depth = 0;
	cur_scope->ret_type = typ;
	return new_scope;
}

struct Scope* delete_scope() {
	struct Scope* cur = cur_scope;
	cur_scope = cur_scope->prev;
//	free(cur);
	return cur_scope;
}

#endif
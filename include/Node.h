#ifndef NODE_H
#define NODE_H

typedef enum NodeType {
	ERROR_NODE = -1,
	CHAR_NODE = 0,
	PAIR_NODE = 1
} NodeType;

typedef struct Node Node;
typedef char CharValue;
typedef const char* ErrorValue;

typedef struct PairValue {
	Node *left;
	Node *right;
} PairValue;

typedef union {
	PairValue pair;
	CharValue value;
	ErrorValue error;
} NodeValue;

typedef struct Node {
	NodeType type;
	NodeValue data;
} Node;

Node *CharNode_new(char c);

Node *PairNode_new(Node *left, Node *right);

Node *ErrorNode_new(const char *msg);

void *Node_drop(Node *self);

#endif

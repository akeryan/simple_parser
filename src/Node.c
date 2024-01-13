#include <stdlib.h>

#include "Node.h"
#include "Guards.h"

Node* CharNode_new(char c)
{
	Node* node = OOM_GUARD(malloc(sizeof(Node)), _FILE_, _LINE_);
	node->type = CHAR_NODE;
	node->data_value = c;
	return node;
};

Node* PairNode_new(Node *left, Node *right)
{
	Node* node = OOM_GUARD(malloc(sizeof(Node)), _FILE_, _LINE_);
	node->type = PAIR_NODE;
	node->data.pair.left = left;
	node->data.pair.right = right;
	return node;
}

Node* ErrorNode_new(const char *msg)
{
	Node* node = OOM_GUARD(malloc(sizeof(Node)), _FILE_, _LINE_);
	node->type = ERROR_NODE;
	node->data.error = msg;
	return node;
}


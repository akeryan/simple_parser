#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "CharItr.h"
#include "Scanner.h"
#include "Node.h"
#include "Parser.h"
#include "libft.h"

void visit(const Node *node, size_t spaces);
void indent(size_t n_spaces);

int main() {
	char *line;
	line = get_next_line(0);
	CharItr itr = CharItr_value(line, strlen(line));
	Scanner scanner = Scanner_value(itr);
	Node *node = parse(&scanner);
	visit(node, 0);
	Node_drop(node);
}

void visit(const Node *node, size_t spaces)
{
	indent(spaces);
	switch (node->type) {
		case PAIR_NODE:
			printf("Pair(\n");
			visit(node->data.pair.left, spaces + 2);
			visit(node->data.pair.right, spaces + 2);
			indent(spaces);
			printf(")\n");
			break;
		case CHAR_NODE:
			printf("Char('%c')\n", node->data.value);
			break;
		case ERROR_NODE:
			fprintf(stderr, "Error: %s\n", node->data.error);
			break;
	}
}

void indent(size_t spaces)
{
	size_t i = 0;
	
	while (i++ < spaces)
		putchar(' ');
}
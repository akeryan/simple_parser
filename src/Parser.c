#include "Parser.h"
#include "Token.h"
#include "Parser.h"

static Node *parse_pair(Scanner *scanner);
static Node *parse_char(Scanner *scanner);

Node *parse(Scanner *scanner)
{
	Token next = Scanner_peek(scanner);
	switch (next.type) {
		case CHAR_TOKEN:
			return parse_char(scanner);
		case LPAREN_TOKEN:
			return parse_pair(scanner);
		default:
			return ErrorNode_new("Expected (or a Char");
	}
}

static Node *parse_char(Scanner *scanner)
{
	Token next = Scanner_next(scanner);
	return CharNode_new(next.lexeme);
}

static Node *parse_pair(Scanner *scanner)
{
	Token next = Scanner_next(scanner);
	Node *left = parse(scanner); 
	next = Scanner_next(scanner);
	Node *right = parse(scanner);
	next = Scanner_next(scanner);
	return PairNode_new(left, right);
}
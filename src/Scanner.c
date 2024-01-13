#include "Scanner.h"

Scanner Scanner_value(CharItr char_itr)
{
	Scanner scanner;
	scanner.char_itr = char_itr;	
	scanner.next = CharItr_peek(&scanner.char_itr);
	return (scanner);
}

bool Scanner_has_next(const Scanner *self)
{
	if (self->next)
		return (true);
	else
		return (false);
}

Token Scanner_peek(const Scanner *self)
{
	Token	token;
	char	lex;	

	if (Scanner_has_next(self))
	{
		lex = CharItr_peek(&self->char_itr); 
		if ( lex == ' ')
		{
			token.type = SPACE_TOKEN;
			token.lexeme = lex;
		}
		else if (lex == '(')
		{
			token.type = LPAREN_TOKEN;
			token.lexeme = lex;
		}
		else if (lex == ')')
		{
			token.type = RPAREN_TOKEN;
			token.lexeme = lex;
		}
		else if (lex == '\0')
		{
			token.type = END_TOKEN;
			token.lexeme = lex;
		}
		else 
		{
			token.type = CHAR_TOKEN;
			token.lexeme = lex;
		}
	}
	return (token);
}

Token Scanner_next(Scanner *self)
{
	Token token;

	token = Scanner_peek(self);
	CharItr_next(&self->char_itr);
	return (token);
}
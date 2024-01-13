#include "CharItr.h"

CharItr CharItr_value(const char *start, size_t length)
{
	CharItr charItr;

	charItr.cursor = start;
	charItr.sentinel = start + length;	
	return charItr;
}

const char *CharItr_cursor(const CharItr *self)
{
	return self->cursor;
}

char CharItr_peek(const CharItr *self)
{
	return *(self + 1)->cursor;
}
bool CharItr_has_next(const CharItr *self)
{
	if (self->cursor < self->sentinel)
		return (true);
	else
		return (false);
}

char CharItr_next(CharItr *self)
{
	if (CharItr_has_next(self))
		self->cursor++;
	return (*self->cursor);
}
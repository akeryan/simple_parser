#include "CharItr.h"

CharItr CharItr_value(const char *start, size_t length)
{
	CharItr charItr;

	charItr.cursor = start;
	charItr.sentinel = start + length;	
	return charItr;
}
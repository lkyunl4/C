#ifndef SCC_TEST

#define _BSD_SOURCE
#include <string.h>
#include <strings.h>

char *rindex(const char *s, int c)
{
	return strrchr(s, c);
}
#endif

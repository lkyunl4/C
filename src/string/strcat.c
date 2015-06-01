#ifndef SCC_TEST

#ifndef SCC_TEST

#include <string.h>

char *strcat(char *restrict dest, const char *restrict src)
{
	strcpy(dest + strlen(dest), src);
	return dest;
}

#endif
#endif

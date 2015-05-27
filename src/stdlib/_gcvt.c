#ifndef SCC_TEST

#define _GNU_SOURCE
#include "_stdlib.h"
//#include <stdio.h>

char *_gcvt(double x, int n, char *b)
{
	sprintf(b, "%.*g", n, x);
	return b;
}
#endif

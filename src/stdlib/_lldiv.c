#ifndef SCC_TEST

#include "_stdlib.h"

lldiv_t _lldiv(long long num, long long den)
{
	return (lldiv_t){ num/den, num%den };
}
#endif

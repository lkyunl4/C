#ifndef SCC_TEST

#include "../_stdlib.h"

ldiv_t _ldiv(long num, long den)
{
	return (ldiv_t){ num/den, num%den };
}
#endif

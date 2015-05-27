#ifndef SCC_TEST

#include "../_inttypes.h"

intmax_t _imaxabs(intmax_t a)
{
	return a>0 ? a : -a;
}
#endif

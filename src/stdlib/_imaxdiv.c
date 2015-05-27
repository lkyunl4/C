#ifndef SCC_TEST

#include "../_inttypes.h"

imaxdiv_t _imaxdiv(intmax_t num, intmax_t den)
{
	return (imaxdiv_t){ num/den, num%den };
}
#endif

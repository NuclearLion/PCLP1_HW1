#include "base_conversion.h"

//convert number from base 8 to 10
long base_8_10(long x)
{
	long p8 = 1;
	long new_number = 0;
	while (x) {
		short uc = x % 10;
		new_number += uc * p8;
		p8 *= 8;
		x /= 10;
	}
	return new_number;
}

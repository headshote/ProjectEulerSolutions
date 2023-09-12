#include "eulerProblem1.h"

/**
* If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
* Find the sum of all the multiples of 3 or 5 below 1000.
*/

unsigned int eulerProblem1::sum3n5Multiples(const unsigned int topInteger)
{
	unsigned int result = 0;

	for (int i = 0; i < topInteger; ++i)
	{
		if (!(i % 3) || !(i % 5))
			result += i;
	}

	return result;
}
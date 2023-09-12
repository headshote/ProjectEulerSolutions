#include "eulerProblem9.h"

/*
*	A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
*	a^2 + b^2 = c^2
*
*	For example, 32 + 42 = 9 + 16 = 25 = 52.
*
*	There exists exactly one Pythagorean triplet for which a + b + c = 1000.
*	Find the product abc.
*/

unsigned long long eulerProblem9::pythagoreanTripletProductIfSum(const unsigned int sum)
{
	unsigned long long pythagProd = 1;

	for (unsigned int i = 1; i < sum - 2; ++i)
		for (unsigned int j = i + 1; j < sum - 1; ++j)
		{
			unsigned int k = sum - j - i;
			if (i*i + j*j == k*k && i + j + k == 1000)
				pythagProd = i * j * k;
		}

	return pythagProd;
}
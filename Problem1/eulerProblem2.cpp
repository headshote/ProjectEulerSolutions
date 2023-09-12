#include "eulerProblem2.h"


/**
*	Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:
*	1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
*	By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
*/

unsigned int eulerProblem2::sumEvenFibonacci(const unsigned int topInteger)
{
	unsigned int result = 0;

	unsigned int iteration = 1;
	unsigned int fibon = 0;

	while (fibon < topInteger)
	{
		fibon = fibonacciIter(iteration++);

		if (!(fibon % 2))
			result += fibon;
	}

	return result;
}
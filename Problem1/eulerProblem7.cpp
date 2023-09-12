#include "eulerProblem7.h"

/**
*	 By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
*	What is the 10 001st prime number?
*/
unsigned long long eulerProblem7::nthPrime(const unsigned int n)
{
	unsigned long long number = 2;

	unsigned int counter = 0;

	while (counter < n)
	{
		if (isPrime(number))
			++counter;
		++number;
	}

	return number - 1;
}
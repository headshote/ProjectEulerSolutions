#include "eulerProblem10.h"

/**
*	The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
*	Find the sum of all the primes below two million.
*/

unsigned long long eulerProblem10::sumOfPrimesBelowNaive(const unsigned int n)
{
	unsigned long long sum = 2;

	for (unsigned int i = 1; i < n; i += 2)
	{
		if (isPrime(i))
			sum += i;
	}

	return sum;
}

unsigned long long eulerProblem10::sumOfPrimesBelow(const unsigned int n)
{
	std::vector<int>& sieve = populateSieve(n);

	unsigned long long sum = 0;

	for (unsigned int i = 2; i < sieve.size(); ++i)
	{
		if (!sieve[i])
			sum += i;
	}

	return sum;
}
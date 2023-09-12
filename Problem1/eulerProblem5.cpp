#include "eulerProblem5.h"

/**
*	 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
*	What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

unsigned int eulerProblem5::smallestEvDiv1toNNaive(const unsigned int n)
{
	unsigned int evenDivisor = 1;

	while (true)
	{
		bool evenlyDivisibleByAll = true;

		unsigned int i = 1;
		for (; i <= n; i++)
			if (evenDivisor % i)	//is there's a remainder, it's not our guy, stop divisibility checking for the current candidate
			{
				evenlyDivisibleByAll = false;
				break;
			}

		if (evenlyDivisibleByAll)
			break;

		evenDivisor++;
	}

	return evenDivisor;
}

unsigned int eulerProblem5::greatestPerfectPower(const unsigned int integer, const unsigned int limit)
{
	unsigned int j = 0;

	for (unsigned int i = integer; i <= limit; j++)
	{
		i *= integer;
	}

	return j;
}

unsigned long long eulerProblem5::smallestEvDiv1toN(const unsigned int n)
{
	unsigned long long smallestNumber = 1;

	//to construct such a number, we only need prime divisors of it, and we need to use those prime divisors
	//the greatest amount of 'times', so that such any 'prime divisor' to the power of 'times' 
	//is less than or equal to the largest divisor (prime or non-prime),
	//Because the prime divisors are 'reused' to construct the non-prime divisors, by all of which the final result should be divisible,
	//BUT no non-prime divisor can  contain the amount (power) of any prime divisor, which would result in the product greater,
	//than the largest divisor in the sequence of all divisors
	for (unsigned int i = 2; i <= n; i++)
	{
		if (isPrime(i))
		{
			unsigned int power = greatestPerfectPower(i, n);

			smallestNumber *= pow(i, power);
		}
	}

	return smallestNumber;
}
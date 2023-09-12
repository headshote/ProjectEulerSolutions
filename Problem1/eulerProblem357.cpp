#include "eulerProblem357.h"

/**
*	Consider the divisors of 30: 1,2,3,5,6,10,15,30.
*	It can be seen that for every divisor d of 30, d+30/d is prime.
*
*	Find the sum of all positive integers n not exceeding 100 000 000
*	such that for every divisor d of n, d+n/d is prime.
*/

/**
* If in inpur integer n for every divisor d of n, d+n/d is prime, true will be returned
*/

bool eulerProblem357::checkDivisorsDnDPrime(unsigned int integer)
{
	unsigned int maxVal = (unsigned int)sqrt(integer);	//beyond this point, no point in seeking the divisors
	for (unsigned int divisor = 2; divisor <= maxVal; divisor++)
	{
		if (!(integer % divisor)) // if it's a divisor
		{
			//at least one of the divisors doesn't satisfy  d+n/d==prime, return immediatelly
			if (!isPrime(divisor + integer / divisor))
				return false;

			unsigned int divResult = integer / divisor;

			//process divisors "senior" counterpart, if it doesn't sarisfy, return
			if (!isPrime(divResult + integer / divResult))
				return false;
		}
	}

	return  isPrime(integer + 1);
}

/**
*	If in inpur integer n for every divisor d of n, d+n/d is prime, true will be returned
*	But for a prime integer.
*/
bool eulerProblem357::checkPrimeDivisorsDnDPrime(unsigned int integer)
{
	return isPrime(integer + 1); //1 + integer/1, or integer + integer/integer
}

unsigned long long eulerProblem357::p357SolutionNaive(const unsigned int maxInteger)
{
	unsigned long long sumOfInts = 0;

	for (unsigned int integer = maxInteger; integer >= 1; integer--)
	{
		bool checkConditionSatisfied = isPrime(integer) ? checkPrimeDivisorsDnDPrime(integer) : checkDivisorsDnDPrime(integer);

		if (checkConditionSatisfied)
			sumOfInts += integer;
	}

	return sumOfInts;
}

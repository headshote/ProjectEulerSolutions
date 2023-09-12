#include "eulerProblem3.h"

/**
*	The prime factors of 13195 are 5, 7, 13 and 29.
*	What is the largest prime factor of the number 600851475143 ?
*/

unsigned int eulerProblem3::largestPrimeFactor(const unsigned long long integer)
{
	unsigned long long primeFactor = 1;
	for (unsigned int divisor = 1; divisor < (unsigned long long)(integer / 2); ++divisor)
	{
		if (!(integer % divisor))
		{
			if (divisor <= (integer / divisor))
			{
				if (isPrime(divisor)) primeFactor = divisor;
			}
			else	//if the result of the division is bigger, than the divisor, then we passed the largest factor 
				break;
		}
	}
	return primeFactor;
}
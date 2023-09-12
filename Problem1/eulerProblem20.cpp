#include "eulerProblem20.h"

/**
*	n! means n × (n − 1) × ... × 3 × 2 × 1
*	For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
*	and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
*	Find the sum of the digits in the number 100!
*/

unsigned int eulerProblem20::calculateLargeFactorialDigitsSum(const unsigned int n)
{
	std::vector<unsigned int> digits;
	unsigned int digitSum = 0;

	digits.push_back(1);
	//Implementing factorial as digit-by-digit multiplication
	for (unsigned int j = 1; j < n; j++)
	{
		//multiplication 'remainder', fist additions remainder will always be 0, and we may need double the order of magnitude, than our current number
		std::vector<unsigned int> remainder(digits.size() * 2, 0);

		for (unsigned int i = 0; i < digits.size(); ++i)
		{
			digits[i] *= j;	//
			digits[i] += remainder[i];
			//if product of the digits and the sum with  the previous remainder is greater, that 10,
			//we produce a remainder for the next multiplication, and MAYBE have to expand
			//the order of magnitude of our number
			if (digits[i] > 9)
			{
				remainder[i + 1] = digits[i] / 10;
				if (i == digits.size() - 1)
					digits.resize(digits.size() + 1, 0);
			}

			//always store only the last digit
			digits[i] %= 10;
		}
	}

	for (unsigned int i = 0; i < digits.size(); ++i)
	{
		digitSum += digits[i];
	}

	return digitSum;
}
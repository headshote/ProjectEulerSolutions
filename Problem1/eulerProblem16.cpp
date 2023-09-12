#include "eulerProblem16.h"

/**
*	2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
*	What is the sum of the digits of the number 2^1000?
*/

unsigned int eulerProblem16::calculateLargePowerOfTwoDigitsSum(const unsigned int n)
{
	std::vector<unsigned int> digits;
	unsigned int digitSum = 0;

	digits.push_back(1);
	//multiplying by 2 is implemented as adding the number to itself
	for (unsigned int j = 0; j < n; j++)
	{
		//addition 'remainder', fist additions remainder will always be 0, and we may need one more order of magnitude, than our current digit
		std::vector<unsigned int> remainder(digits.size() + 1, 0);

		for (unsigned int i = 0; i < digits.size(); ++i)
		{
			digits[i] += digits[i] + remainder[i];	//produce the power of two by adding the digits of a number to themselves, considering the remainder of a previous addition

			//if sum of the digits and the previous remainder is greater, that 10, we produce a remainder for the next addition, and MAYBE have to expand
			//the order of magnitude of our number
			if (digits[i] > 9)
			{
				remainder[i + 1] = 1;
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
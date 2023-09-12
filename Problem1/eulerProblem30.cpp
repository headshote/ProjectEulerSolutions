#include "eulerProblem30.h"


/*
*	Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:
*	1634 = 14 + 64 + 34 + 44
*	8208 = 84 + 24 + 04 + 84
*	9474 = 94 + 44 + 74 + 44
*	As 1 = 14 is not a sum it is not included.
*	The sum of these numbers is 1634 + 8208 + 9474 = 19316.
*	Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
*/

unsigned long long eulerProblem30::sumOfDigitNthPowers(const unsigned int n)
{
	//we can't really compose an n+2 digit number by adding it's digits in power of n, such sum of digits will ALWAYS be a lower nuber, than ours
	unsigned long long upperBound = pow(10, n+1)-1;

	unsigned long long sum = 0;

	std::vector<unsigned int> luckyNumbers;

	std::vector<unsigned int> digits = { 0, 1 };
	//has to be at least a 2-digit number
	unsigned int startNumber = 10;
	//for this same reason, we skip first 11 iterations of the algo, starting at number 10
	for (unsigned int i = 11; digits.size() < n + 2 && startNumber < upperBound; ++i)
	{
		const unsigned int nDigits = digits.size();

		//check whether the sum of powered digits is == to the number
		unsigned int nPowerSum = 0;
		unsigned int theNumber = 0;
		unsigned int j = 0;
		while (j < nDigits)
		{
			nPowerSum += pow(digits[j], n);
			theNumber += pow(10, j) * digits[j];
			++j;
		}
		if (nPowerSum == theNumber)
		{
			luckyNumbers.push_back(theNumber);
			sum += theNumber;
		}

		//compose the next digits (in ascending numerical order, but this way we are "repeating" combinations that were already parsed
		//(i.e 1234 == 4321, but we are parsing it nevertheless)
		j = 0;
		while (j < nDigits)
		{
			if ((i % (int)pow(10, j)) == 0)
			{
				//maybe move order of magnitude higher
				if (digits[j] == 9 && j == nDigits-1)
					digits.push_back(1);
				digits[j] = (digits[j] + 1) % 10;
			}
			++j;
		}

		/*for (int k = digits.size()-1; k > -1; --k)
			std::cout << digits[k];
		std::cout << ",";*/
	}

	return sum;
}
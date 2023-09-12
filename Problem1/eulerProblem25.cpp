#include "eulerProblem25.h"

/**
*		TASK:
*
*	The Fibonacci sequence is defined by the recurrence relation:
*	    Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
*	Hence the first 12 terms will be:
*	    F1 = 1
*	    F2 = 1
*	    F3 = 2
*	    F4 = 3
*	    F5 = 5
*	    F6 = 8
*	    F7 = 13
*	    F8 = 21
*	    F9 = 34
*	    F10 = 55
*	    F11 = 89
*	    F12 = 144
*	The 12th term, F12, is the first term to contain three digits.
*	What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
*
*/

unsigned int eulerProblem25::findIndexOFFirstFibonacciWithNDigits(const unsigned int n)
{
	std::vector<unsigned int> digits;		//current fibonacci number for a given iteration (j in the loop)
	std::vector<unsigned int> prevDigits;	//the one before current

	prevDigits.push_back(0);
	digits.push_back(1);

	//Implementing factorial as digit-by-digit multiplication
	unsigned int j = 1;
	for (; digits.size() < n; j++)
	{
		//remainder of the adition operation
		std::vector<unsigned int> remainder(digits.size() + 1, 0);

		std::vector<unsigned int> oldDigits = digits;	//digits from the previous iteration

		for (unsigned int i = 0; i < digits.size(); ++i)
		{
			digits[i] += prevDigits[i] + remainder[i];	//

			//if sum of the digits and the previous remainder is greater, that 10, we produce a remainder for the next multiplication, 
			//and MAYBE have to expand order the of magnitude of our number
			if (digits[i] > 9)
			{
				remainder[i + 1] = digits[i] / 10;
				if (i == digits.size() - 1)
				{
					digits.resize(digits.size() + 1, 0);
					prevDigits.resize(digits.size() + 1, 0);
					oldDigits.resize(digits.size() + 1, 0);
				}
			}

			//always store only the last digit
			digits[i] %= 10;
		}

		prevDigits = oldDigits;
	}

	return j;
}
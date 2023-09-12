#include "eulerProblem4.h"

/**
* A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
*
* Find the largest palindrome made from the product of two 3-digit numbers.
*/

unsigned int eulerProblem4::largestPalidr2x3Digits()
{
	/*std::cout << isPalidrome(9283) << std::endl;
	std::cout << isPalidrome(9009) << std::endl;
	std::cout << isPalidrome(90109) << std::endl;
	std::cout << isPalidrome(91119) << std::endl;
	std::cout << isPalidrome(9001009) << std::endl;
	std::cout << isPalidrome(22) << std::endl;
	std::cout << isPalidrome(2002) << std::endl;
	std::cout << isPalidrome(123321) << std::endl;
	std::cout << isPalidrome(123) << std::endl;
	std::cout << isPalidrome(34) << std::endl;
	std::cout << isPalidrome(19) << std::endl;
	std::cout << isPalidrome(124324314123) << std::endl;*/

	unsigned int maxPalidrom = 0;
	for (unsigned int i = 999; i >= 100; --i)
		for (unsigned int j = 999; j >= i; --j)
		{
			unsigned int product = i * j;

			if (product < maxPalidrom)
				break;

			if (isPalidrome(product))
				maxPalidrom = product;
		}

	return maxPalidrom;
}
#include "eulerProblem24.h"

/**
*		TASK:
*	 A permutation is an ordered arrangement of objects. For example, 
*	3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, 
*	we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:
*	012   021   102   120   201   210
*	What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
*/

void swapDigits(unsigned int & one, unsigned int & two)
{
	unsigned int tmp = one;
	one = two;
	two = tmp;
}

/**
*	Assumes, that digits are stored in a sequence, where the digits with the smallest power  has the highest index of the vector,
*	i.e, {1, 2, 3, 4} - represents the number 1234, but 4, whose power is 0 (4*10^0) has the index 3, which is the maximum index of the vector
*/
void eulerProblem24::nextPermutation(std::vector<unsigned int>& digits)
{
	unsigned int nDigits = digits.size();

	//index of the second-to-last digit in the ascending order (digits of higher power[the ones that precede it] are smaller than it) already, 
	//statring from the "youngest" digit (highest vector index)
	int ascendingDigitId = nDigits - 1;
	while (ascendingDigitId > -1 && digits[ascendingDigitId - 1] > digits[ascendingDigitId])
		--ascendingDigitId;

	//descending digit, compared to the last ascending-ordered digit in the current permutation
	//finds the last digit, that is smaller than the ascending ordered one, among the ones, that follow the digit(have smaller power)
	int descendingDigitId = nDigits;
	while (descendingDigitId > -1 && digits[descendingDigitId - 1] <= digits[ascendingDigitId-1])
		--descendingDigitId;

	swapDigits(digits[ascendingDigitId - 1], digits[descendingDigitId - 1]);

	++ascendingDigitId;
	descendingDigitId = nDigits;
	//swap everything in between the last descendent-ordered digit, and ascendent-ordered one,
	//starting with "opposite" digits in range, ie.last ascending
	while( ascendingDigitId< descendingDigitId )
	{
		swapDigits(digits[ascendingDigitId - 1], digits[descendingDigitId - 1]);
		
		++ascendingDigitId;
		--descendingDigitId;
	}

	/*for (int k = 0; k < nDigits; ++k)
		std::cout << digits[k];
	std::cout << std::endl;*/
}

/**
n - n-th permutation will be returned
mDigitns - amount of digits in permutation(1...10);
*/
unsigned long long eulerProblem24::nThMdigitPermutation(const unsigned int n, unsigned int mDigitns)
{
	mDigitns = (unsigned int)fminf(mDigitns, 10);

	std::vector<unsigned int> digits(mDigitns);
	
	for (unsigned int i = 0; i < mDigitns; ++i)
	{
		digits[i] = i;
	}

	unsigned int totalPermutations = factorial(mDigitns);

	for (unsigned int j = 1; j < n && j < totalPermutations; ++j)
	{
		nextPermutation(digits);
	}

	unsigned long long resPermutation = 0;
	for (unsigned int i = 0; i < digits.size(); ++i)
		resPermutation += digits[i] * pow(10, mDigitns - 1 - i);

	return resPermutation;
}
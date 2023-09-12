#include "eulerProblem13.h"

/**
*	Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.
*/

unsigned long long eulerProblem13::first10DigitsOfLargeNumSum(std::vector<std::string>& nums)
{
	unsigned long long f10DigitsSum = 0;

	for (unsigned int i = 0; i < nums.size(); i++)
	{
		std::string& numString = nums[i];

		unsigned long long first10Digits = std::stoll(numString.substr(0, 12));	//a little margin of over 10 digits for the first numbers for better precision

		f10DigitsSum += first10Digits;
	}

	//discard all of the unneeded digits
	while (f10DigitsSum / 1000000000 >= 10)
		f10DigitsSum /= 10;

	return f10DigitsSum;
}

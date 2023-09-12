#ifndef EULER_PROBLEM8
#define EULER_PROBLEM8

#include "eulerHelpers.h"

using namespace eulerHelpers;

namespace eulerProblem8
{
	extern std::string pr8String;
	unsigned int getDigitAt(unsigned int i, const std::string& string);
	unsigned long long getFullProductAt(unsigned int& firstDigitId, unsigned int& lastDigitId, const unsigned int n, const std::string& pr8String);
	unsigned long long greatestProdNAdjacentDigits(const unsigned int n);
}

#endif
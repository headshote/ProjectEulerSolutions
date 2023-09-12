#ifndef EULER_PROBLEM22
#define EULER_PROBLEM22

#include "eulerHelpers.h"

using namespace eulerHelpers;

namespace eulerProblem22
{
	void sortAplabeticallyStrVector(std::vector<std::string>& vector);
	unsigned int alphabeticalScore(const std::string& word);
	unsigned long long totalOfNameScore(const std::vector<std::string>& names);
}

#endif
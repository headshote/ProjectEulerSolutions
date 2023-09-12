#ifndef EULER_PROBLEM31
#define EULER_PROBLEM31

#include "eulerHelpers.h"

using namespace eulerHelpers;

namespace eulerProblem31
{
	////Recurseive solution, that constructs all the coin combinations for value, unfeasibly slow
	extern std::vector<unsigned int> coinValues;
	extern std::vector<std::vector<std::vector<unsigned int>>> combinationsOfValues;

	std::vector<std::vector<unsigned int>> populateCombinationsVector(const unsigned int value);
	void mergeCombinations(std::vector<std::vector<unsigned int>> lowCombinations, std::vector<std::vector<unsigned int>> highCombinations, std::vector<std::vector<unsigned int>>& targetContainer);
	
	unsigned int nWaysToCombineCoinsIntoValue(const unsigned int value);

	//////Recursive, just counts
	unsigned int nWaysToMakeValueWithCoins(int value, const unsigned int nCoins);
	unsigned int p31RecursiveSolution(int value);

	////Plain loop
	unsigned int nWaysToCombineCoinsInto200();
}

#endif
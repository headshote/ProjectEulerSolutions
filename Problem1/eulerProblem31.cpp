#include "eulerProblem31.h"

/**
*		TASK:
*	In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:
*   1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
*	It is possible to make £2 in the following way:
*   1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
*	How many different ways can £2 be made using any number of coins?
*/

std::vector<unsigned int> eulerProblem31::coinValues = { 1, 2, 5, 10, 20, 50, 100, 200 };

/////Recursive, builds all combinations, but is slow af

//value-indexed array of all possible coin combinations for that value, for memoization
std::vector<std::vector<std::vector<unsigned int>>> eulerProblem31::combinationsOfValues;

void eulerProblem31::mergeCombinations(std::vector<std::vector<unsigned int>> lowCombinations, std::vector<std::vector<unsigned int>> highCombinations, 
	std::vector<std::vector<unsigned int>>& targetContainer)
{
	for (unsigned int k = 0; k < lowCombinations.size(); ++k)
		for (unsigned int l = 0; l < highCombinations.size(); ++l)
		{
			std::vector<unsigned int> combination;
			//iterate over all the digits, and create a sorted combination out of them
			unsigned int kId = 0, lId = 0;
			while (kId < lowCombinations[k].size() && lId < highCombinations[l].size())
			{
				if (lowCombinations[k][kId] <= highCombinations[l][lId])
				{
					combination.push_back(lowCombinations[k][kId]);
					++kId;
				}
				else
				{
					combination.push_back(highCombinations[l][lId]);
					++lId;
				}
			}

			//push the arrays, that have leftovers (in case when one array had more coins thatn the other
			while (kId < lowCombinations[k].size())
			{
				combination.push_back(lowCombinations[k][kId]);
				++kId;
			}

			while (lId < highCombinations[l].size())
			{
				combination.push_back(highCombinations[l][lId]);
				++lId;
			}

			//chack out, whether the combination already exists
			if (std::find(targetContainer.cbegin(), targetContainer.cend(), combination) == targetContainer.cend())
				targetContainer.push_back(combination);
		}
}

std::vector<std::vector<unsigned int>> eulerProblem31::populateCombinationsVector(const unsigned int value)
{
	//Here the recursion ends
	if (value == 1)
		return std::vector<std::vector<unsigned int>>(1, std::vector<unsigned int>(1, 1));

	//Get moized value, if available, to avoid redundant recursive calls
	if (combinationsOfValues[value].size() > 0)
		return combinationsOfValues[value];

	//this vector contains all possible unique combinations of coins for the current value (each combination - list of coins, that adds up to value)
	std::vector<std::vector<unsigned int>> combinationsForValue;

	//here we split this stuff into all possible parts recursively, and combine UNIQUE combinations into one vector
	unsigned int i = 1;
	unsigned int j = value - i;
	while (i <= j && i + j == value)
	{
		//Compute the lower halves
		std::vector<std::vector<unsigned int>> lowCombinations = populateCombinationsVector(i);
		std::vector<std::vector<unsigned int>> highCombinations = populateCombinationsVector(j);

		//Combine their combinations into current value combinations, filtering out stuff, that repeats
		mergeCombinations(lowCombinations, highCombinations, combinationsForValue);
		
		//if the value has it's own whole coin, push it into the combinations
		if (std::find(coinValues.cbegin(), coinValues.cend(), value) != coinValues.cend())
			combinationsForValue.push_back( std::vector<unsigned int>(1,value) );

		++i;
		j = value - i;
	}

	//Memoization
	combinationsOfValues[value] = combinationsForValue;

	return combinationsForValue;
}

unsigned int eulerProblem31::nWaysToCombineCoinsIntoValue(const unsigned int value)
{
	//clears combinationsOfValues, and allocates space forcoin combination for  "value" amount of values
	std::vector<std::vector<std::vector<unsigned int>>>(value + 1).swap(combinationsOfValues);

	for (unsigned int i = 1; i <= value; ++i)
		combinationsOfValues[i] = std::vector< std::vector<unsigned int> >();

	//
	std::vector<std::vector<unsigned int>> combinations = populateCombinationsVector(value);

	return combinations.size();
}

/////Recursive, but just counts

unsigned int eulerProblem31::nWaysToMakeValueWithCoins(int value, const unsigned int nCoins)
{
	if (nCoins == 1)
		return 1;

	unsigned int nCombinations = 0;

	while (value >= 0)
	{
		nCombinations += nWaysToMakeValueWithCoins(value, nCoins - 1);

		value -= coinValues[nCoins - 1];
	}

	return nCombinations;
}

unsigned int eulerProblem31::p31RecursiveSolution(int value)
{
	return nWaysToMakeValueWithCoins(value, coinValues.size());
}

/////////Straight-up loops, counts combinations

unsigned int eulerProblem31::nWaysToCombineCoinsInto200()
{
	unsigned int combinations = 0;

	for (int c1 = 200; c1 >= 0; c1 -= 200)
		for (int c2 = c1; c2 >= 0; c2 -= 100)
			for (int c3 = c2; c3 >= 0; c3 -= 50)
				for (int c4 = c3; c4 >= 0; c4 -= 20)
					for (int c5 = c4; c5 >= 0; c5 -= 10)
						for (int c6 = c5; c6 >= 0; c6 -= 5)
							for (int c7 = c6; c7 >= 0; c7 -= 2)
									++combinations;
	return combinations;
}
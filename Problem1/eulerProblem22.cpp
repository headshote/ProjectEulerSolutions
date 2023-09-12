#include "eulerProblem22.h"

/**
*	Using names.txt, a 46K text file containing over five-thousand first names,
*	begin by sorting it into alphabetical order. Then working out the alphabetical value for each name,
*	multiply this value by its alphabetical position in the list to obtain a name score.
*	For example, when the list is sorted into alphabetical order, COLIN,
*	which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.
*	What is the total of all the name scores in the file?
*/

//Is the first string "lees" than the second one alphabetically

void eulerProblem22::sortAplabeticallyStrVector(std::vector<std::string>& vector)
{
	mergeSortVector(vector);
}

unsigned int eulerProblem22::alphabeticalScore(const std::string& word)
{
	unsigned int score = 0;

	char Avalue = 'A';
	for (std::size_t i = 0; i < word.size(); i++)
		score += word.at(i) - Avalue + 1;

	return score;
}

unsigned long long eulerProblem22::totalOfNameScore(const std::vector<std::string>& names)
{
	unsigned long long total = 0;

	for (std::size_t i = 0; i < names.size(); ++i)
	{
		total += alphabeticalScore(names[i]) * (i + 1);
	}

	assert(total == 871198282 && "Incorrectly calculated total of name scores");
	return total;
}
#include "eulerHelpers.h"

////
unsigned int eulerHelpers::fibonacciRec(const unsigned int iteration)
{
	if (iteration < 2)
		return 1;
	else
		return fibonacciRec(iteration - 1) + fibonacciRec(iteration - 2);
}

unsigned int eulerHelpers::fibonacciIter(const unsigned int iteration)
{
	unsigned int result = 0;
	unsigned int prev;
	unsigned int preprev;
	for (unsigned int i = 1; i <= iteration; ++i)
	{
		if (i == 1)
		{
			prev = 1;
			preprev = 0;
		}

		result = prev + preprev;

		preprev = prev;
		prev = result;
	}
	return result;
}

////
bool eulerHelpers::isPrime(const unsigned int integer)
{
	if (integer == 1)
		return false;
	else if (integer < 4)
		return true;
	else if (integer % 2 == 0)
		return false;
	else if (integer % 3 == 0)
		return false;
	else
	{
		unsigned int maxVal = (unsigned int)sqrt(integer);	//beyond this point, no point in seeking the divisors
		for (unsigned int i = 5; i <= maxVal; i += 6)
		{
			if (integer % i == 0) return false;
			if (integer % (i + 2) == 0) return false;
		}
	}

	return true;
}

////
std::vector<int> eulerHelpers::readIntsFromString(const std::string& inString, const std::string& separator)
{
	std::vector<int> vector;

	std::size_t commaIndex = 0;
	std::size_t prevCommaIndex = -1;
	while (commaIndex != std::string::npos)
	{
		commaIndex = inString.find_first_of(separator, commaIndex + 1);

		std::string intStr = inString.substr(prevCommaIndex + 1);
		if (commaIndex != std::string::npos)
			intStr = inString.substr(prevCommaIndex + 1, commaIndex - prevCommaIndex - 1);

		int integer = std::stoi(intStr);
		vector.push_back(integer);

		prevCommaIndex = commaIndex;
	}

	return vector;
}

std::vector< std::vector<int>> eulerHelpers::readMatrixFromFile(const std::string& filePath, const std::string& deliminer)
{
	std::ifstream matrixFile;

	std::vector< std::vector<int>> vector;

	matrixFile.exceptions(std::ifstream::badbit);

	try
	{
		std::string fileLine;

		matrixFile.open(filePath);

		while (std::getline(matrixFile, fileLine))
		{
			vector.push_back(readIntsFromString(fileLine, deliminer));
		}
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "Matrix file read failure" << std::endl;
	}

	return vector;
}

////
bool eulerHelpers::isPalidrome(const unsigned int integer)
{
	const int mask = 0x01;

	unsigned int parts = integer;
	unsigned int numDigits = 0;
	for (; parts != 0; numDigits++)
		parts /= 10;

	parts = integer;
	unsigned int i = 0;
	while (i < (numDigits + 1) / 2 && parts > 0)
	{
		if ((parts % 10 != (integer / (unsigned int)pow(10, numDigits - 1 - i)) % 10)
			&& (i != (numDigits) / 2))
			return false;
		parts /= 10;
		++i;
	}

	return true;
}

////
unsigned long long eulerHelpers::sumOfSquares(const unsigned int maxInt)
{
	unsigned long long result = 0;

	result = (2 * maxInt + 1) * (maxInt + 1) * maxInt / 6;

	return result;
}

unsigned long long eulerHelpers::squareOfSum(const unsigned int maxInt)
{
	unsigned long long result = 0;

	result = (1 + maxInt) * maxInt / 2;

	result *= result;

	return result;
}

////
/*
First, we initialise the array to false because we have not yet crossed out any num-
bers. In crossing out, we discriminate between even and odd numbers, slightly
deviating from the description. After all even numbers > 2 have been crossed
out as multiples of 2, there is no point in crossing them out again as multiples
of their odd divisors. So when crossing out multiples of odd primes p, we can
proceed in steps of 2p instead of p, sparing the even multiples. As noted above,
all multiples of p less than p 2 will already have been crossed out as multiples of
smaller primes, so we need not revisit them. Also, if n is an odd composite, when
the loop reaches n, that number and its multiples have already been crossed out,
so we need not enter the inner loop then.
*/
std::vector<int> eulerHelpers::populateSieve(const unsigned int limit)
{
	const unsigned int sieveBound = limit;
	const unsigned int crossLimit = (unsigned int)sqrt(limit);

	std::vector<int> sieve(sieveBound);

	for (unsigned int i = 0; i < sieveBound; ++i)
		sieve[i] = false;

	for (unsigned int i = 4; i < sieveBound; i += 2)//// mark even numbers > 2
		sieve[i] = true;;

	for (unsigned int i = 3; i < crossLimit; i += 2)
		if (!sieve[i])//// n not marked, hence prime
			for (unsigned int j = i * i; j < sieveBound; j += 2 * i)
				sieve[j] = true;

	return sieve;
}

////
std::vector<std::string> eulerHelpers::readLinesFromFile(const std::string& filePath)
{
	std::ifstream numbersFile;

	std::vector<std::string> vector;

	numbersFile.exceptions(std::ifstream::badbit);

	try
	{
		std::string fileLine;

		numbersFile.open(filePath);

		while (std::getline(numbersFile, fileLine))
		{
			vector.push_back(fileLine);
		}
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "File read failure" << std::endl;
	}

	return vector;
}

////
double eulerHelpers::factorial(unsigned int n)
{
	double fact = 1.0;

	for (unsigned int i = 1; i <= n; i++)
	{
		fact *= i;
	}

	return fact;
}

////
std::string eulerHelpers::readFileString(const std::string& fileName)
{
	std::ifstream textFile;

	std::string fileString;

	textFile.exceptions(std::ifstream::badbit);

	try
	{
		std::string fileLine;

		textFile.open(fileName);

		while (std::getline(textFile, fileLine))
		{
			fileString += fileLine;
		}
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "Matrix file read failure" << std::endl;
	}


	return fileString;
}

std::vector<std::string> eulerHelpers::prepareArrayOfWords(const std::string& wordString, const unsigned int startIndex, const unsigned int endIndex, const std::string& wordDeliminer)
{
	std::vector<std::string> words;


	std::size_t deliminerInd = startIndex;
	std::size_t prevDeliminerInd = startIndex;

	std::size_t delimSize = wordDeliminer.size();

	while (deliminerInd != std::string::npos && prevDeliminerInd < endIndex)
	{
		deliminerInd = wordString.find_first_of(wordDeliminer, prevDeliminerInd);

		std::string word;
		if (deliminerInd != std::string::npos)
			word = wordString.substr(prevDeliminerInd, deliminerInd - prevDeliminerInd);
		else
			word = wordString.substr(prevDeliminerInd + 1);

		words.push_back(word);

		prevDeliminerInd = deliminerInd + delimSize;
	}

	return words;
}

bool eulerHelpers::compareStrings(const std::string& s1, const std::string s2)
{
	std::size_t i = 0;

	while (i < s1.size() && i < s2.size())
	{
		if (s1.at(i) < s2.at(i))
			return true;
		else if (s1.at(i) > s2.at(i))
			return false;
		i++;
	}

	return s1.size() <= s2.size();
}

void eulerHelpers::mergeSortVector(std::vector<std::string>& vector)
{
	//mean we have split the vector into a one-element vector, recursion stops here
	if (vector.size() < 2)
		return;

	//Sizes of halves
	std::size_t firstHalfSize = vector.size() / 2;
	std::size_t secondHalfSize = vector.size() % 2 ? vector.size() / 2 + 1 : vector.size() / 2;

	//construct the halves vectors
	std::vector<std::string>::const_iterator fstHalfBegin = vector.begin();
	std::vector<std::string> firstHalf(fstHalfBegin, fstHalfBegin + firstHalfSize);
	std::vector<std::string>::const_iterator sndHalfBegin = vector.begin() + firstHalfSize;
	std::vector<std::string> secondHalf(sndHalfBegin, sndHalfBegin + secondHalfSize);

	//Recursive calls on halves
	mergeSortVector(firstHalf);
	mergeSortVector(secondHalf);

	//Now compare the splitted halves (already sorted in the previous recursive calls) and merge them into our vector
	std::size_t i = 0, j = 0, k = 0;
	for (; j < firstHalfSize && k < secondHalfSize; ++i)
	{
		if (compareStrings(firstHalf[j], secondHalf[k]))
			vector[i] = firstHalf[j++];
		else
			vector[i] = secondHalf[k++];
	}

	//If one of the arrays wasn't fully merged, just push the rest of 
	while (j < firstHalfSize)
		vector[i++] = firstHalf[j++];
	while (k < secondHalfSize)
		vector[i++] = secondHalf[k++];
}


////
int eulerHelpers::dijkstraShortestPathSum(const std::vector< std::vector<int>>& matrix,
	std::vector<std::pair<int, int>>(*neighborFunction)(const unsigned int, const unsigned int, const unsigned int, const unsigned int))
{
	const unsigned int nRows = matrix.size();
	const unsigned int nCols = matrix[nRows - 1].size();

	//std::greater < std::pair<int, std::pair<int, int>> >;

	std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>, muhGrater> frontier;	//[priority, (elem.i, elem.j)]
	/*frontier.push(std::pair<int, std::pair<int, int>>(1, std::pair<int, int>(100, 100)));
	frontier.push(std::pair<int, std::pair<int, int>>(4, std::pair<int, int>(10, 10)));
	frontier.push(std::pair<int, std::pair<int, int>>(5, std::pair<int, int>(150, 200)));
	frontier.push(std::pair<int, std::pair<int, int>>(2, std::pair<int, int>(30, 40)));
	frontier.push(std::pair<int, std::pair<int, int>>(222, std::pair<int, int>(-1, -1)));
	frontier.push(std::pair<int, std::pair<int, int>>(0, std::pair<int, int>(150, 200)));
	frontier.push(std::pair<int, std::pair<int, int>>(14, std::pair<int, int>(100, -1)));
	while (!frontier.empty())
	{
	std::cout << frontier.top().first << " (" << frontier.top().second.first << ", " << frontier.top().second.second << ")" << std::endl;
	frontier.pop();
	}*/
	frontier.push(std::pair<int, std::pair<int, int>>(matrix[0][0], std::pair<int, int>(0, 0)));	//first element, top-left corner, priority is it's value

	std::map<std::pair<int, int>, std::pair<int, int>> cameFrom;
	cameFrom[std::pair<int, int>(0, 0)] = std::pair<int, int>(0, 0);	//came to this element from nowhere

	std::map<std::pair<int, int>, int> costOfPath;
	costOfPath[std::pair<int, int>(0, 0)] = matrix[0][0];

	//Dijkstra pathfinding
	while (!frontier.empty())
	{
		//priority queue, least expensive element to visit is accessed with top()
		const std::pair<int, int> currentElement = frontier.top().second;
		frontier.pop();
		unsigned int i = currentElement.first, j = currentElement.second;

		if (i == -1 && j == nCols - 1)
			break;

		std::vector<std::pair<int, int>> neigbors = neighborFunction(nRows, nCols, i, j);

		for (auto neigborIter = neigbors.begin(); neigborIter != neigbors.end(); neigborIter++)
		{
			const std::pair<int, int>& neighbor = *neigborIter;
			int newCost = costOfPath[currentElement] + matrix[neighbor.first][neighbor.second];

			if (costOfPath.find(neighbor) == costOfPath.end() || newCost < costOfPath[neighbor])	//if not in the list of costSofar, or is a cheaper path
			{
				costOfPath[neighbor] = newCost;
				int priority = newCost;
				frontier.push(std::pair<int, std::pair<int, int>>(priority, neighbor));
				cameFrom[neighbor] = currentElement;
			}
		}
	}

	return costOfPath[std::pair<int, int>(nRows - 1, nCols - 1)];
}

bool eulerHelpers::muhGrater::operator()(const  std::pair<int, std::pair<int, int>>& _Left, const  std::pair<int, std::pair<int, int>>& _Right) const
{	// apply operator> to operands
	return (_Left.first > _Right.first);
}



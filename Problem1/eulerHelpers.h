#ifndef EULER_HELPERS
#define EULER_HELPERS

#include <string>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <assert.h>
#include <queue>
#include <map>

namespace eulerHelpers
{
	unsigned int fibonacciRec(const unsigned int iteration);
	unsigned int fibonacciIter(const unsigned int iteration);

	bool isPrime(const unsigned int integer);

	std::vector<int> readIntsFromString(const std::string& inString, const std::string& separator);
	std::vector< std::vector<int>> readMatrixFromFile(const std::string& filePath, const std::string& deliminer = ",");

	bool isPalidrome(const unsigned int integer);

	unsigned long long sumOfSquares(const unsigned int maxInt);
	unsigned long long squareOfSum(const unsigned int maxInt);

	std::vector<int> populateSieve(const unsigned int limit);

	std::vector<std::string> readLinesFromFile(const std::string& filePath);

	double factorial(unsigned int n);

	std::string readFileString(const std::string& fileName);
	std::vector<std::string> prepareArrayOfWords(const std::string& wordString, const unsigned int startIndex, const unsigned int endIndex, const std::string& wordDeliminer);
	bool compareStrings(const std::string& s1, const std::string s2);
	void mergeSortVector(std::vector<std::string>& vector);


	struct muhGrater : public std::binary_function < std::pair<int, std::pair<int, int>>, std::pair<int, std::pair<int, int>>, bool >
	{
		bool operator()(const  std::pair<int, std::pair<int, int>>& _Left, const  std::pair<int, std::pair<int, int>>& _Right) const;
	};
	/**
	*	This one return the shortest path (sum of grid values) through the grid, from the very first element (0,0), to the very last (N-1,N-1)
	*/
	int dijkstraShortestPathSum(const std::vector< std::vector<int>>& matrix,
		std::vector<std::pair<int, int>>(*neighborFunction)(const unsigned int, const unsigned int, const unsigned int, const unsigned int));

	/**
	*	 Same as the other dijkstra algo, but this time populate the map of costs of all best (most or least expensive, depending opn parametrization) paths (from the starting element)
	*	*	*	*
	*	Also, template horseshit forced me to move the code to the header file
	*	*	*	*
	*	Parametrized as follows: Comparator - data struct with the () operator, used for priority_queue sorting (if you use muhGreater, bundled with dijkstraShortestPathSum(...),
	*	priority_queue pop() operation will return the smallest path first);
	*	neighborFunction - function, that returns pair of grid indices, neighbors of the current grid cell;
	*	elementComparison - will compare path values from the priority_queue for each grid element, that is to be traversed, to chose one that we want to visit
	*/
	template <typename Comparator>
	std::map<std::pair<int, int>, int> dijkstraGetPathsCosts(const std::vector< std::vector<int>>& grid, std::pair<int, int> startingElement,
		std::vector<std::pair<int, int>>(*neighborFunction)(const unsigned int, const unsigned int, const unsigned int, const unsigned int),
		bool(*elementComparison)(int, int))
	{
		const unsigned int nRows = grid.size();		

		std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>, Comparator> frontier;	//[priority, (elem.i, elem.j)]
		frontier.push(std::pair<int, std::pair<int, int>>(grid[startingElement.first][startingElement.second], startingElement));	//first element, priority is it's value

		std::map<std::pair<int, int>, std::pair<int, int>> cameFrom;
		cameFrom[startingElement] = startingElement;	//came to this element from nowhere

		std::map<std::pair<int, int>, int> costOfPath;
		costOfPath[startingElement] = grid[startingElement.first][startingElement.second];

		//Dijkstra pathfinding
		while (!frontier.empty())
		{
			//priority queue, least expensive element to visit is accessed with top()
			const std::pair<int, int> currentElement = frontier.top().second;
			frontier.pop();
			unsigned int i = currentElement.first, j = currentElement.second;

			const unsigned int nCols = grid[i].size();

			std::vector<std::pair<int, int>> neigbors = neighborFunction(nRows, nCols, i, j);

			for (auto neigborIter = neigbors.begin(); neigborIter != neigbors.end(); neigborIter++)
			{
				const std::pair<int, int>& neighbor = *neigborIter;
				int newCost = costOfPath[currentElement] + grid[neighbor.first][neighbor.second];

				if (costOfPath.find(neighbor) == costOfPath.end() || elementComparison(newCost, costOfPath[neighbor]))	//if not in the list of costSofar, or is the path satisfies comparison
				{
					costOfPath[neighbor] = newCost;
					int priority = newCost;
					frontier.push(std::pair<int, std::pair<int, int>>(priority, neighbor));
					cameFrom[neighbor] = currentElement;
				}
			}
		}

		return costOfPath;
	}

}

#endif
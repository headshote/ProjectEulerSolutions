#include "eulerProblem18.h"

/**
*	By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.
*		 3
*		7 4
*	   2 4 6
*	  8 5 9 3
*	That is, 3 + 7 + 4 + 9 = 23.
*	Find the maximum total from top to bottom of the triangle below file p18.txt
*/

bool eulerProblem18::muh_less::operator()(const  std::pair<int, std::pair<int, int>>& _Left, const  std::pair<int, std::pair<int, int>>& _Right) const
{	// apply operator< to operands
	return (_Left.first <_Right.first);
}

std::vector<std::pair<int, int>> eulerProblem18::geTriangledNeighbors(const unsigned int nRows, const unsigned int nCols, const unsigned int i, const unsigned int j)
{
	std::vector<std::pair<int, int>> neigbors;
	if (i < nRows - 1)
	{
		neigbors.push_back(std::pair<int, int>(i + 1, j)); //bottomNeighbor
		neigbors.push_back(std::pair<int, int>(i + 1, j + 1)); //rightNeighbor
	}

	return neigbors;
}

bool eulerProblem18::greaterThan(int first, int second)
{
	return first > second;
}

int eulerProblem18::longestTrianglePathSum(const std::vector< std::vector<int>>& grid)
{
	std::map<std::pair<int, int>, int> costOfPath = dijkstraGetPathsCosts<muh_less>(grid, std::pair<int, int>(0, 0), geTriangledNeighbors, greaterThan);

	int bestPath = 0;

	for (unsigned int i = 0; i < grid[grid.size() - 1].size(); i++)
	{
		int currPath = costOfPath[std::pair<int, int>(grid.size() - 1, i)];
		if (currPath > bestPath)
			bestPath = currPath;
	}

	return bestPath;
}
#include "eulerProblem82.h"

/*
*The minimal path sum in the 5 by 5 matrix below, by starting in any cell in the left column and finishing in any cell in the right column, 
*	and only moving up, down, and right, is indicated in red and bold; the sum is equal to 994.
*	https://projecteuler.net/problem=82
*	Find the minimal path sum, in matrix.txt(right click and "Save Link/Target As..."),
*	a 31K text file containing a 80 by 80 matrix, from the left column to the right column.
*/

int eulerProblem82::shortest3WayMatrixPathSum(const std::vector< std::vector<int>>& matrix)
{
	int bestPath = 0;
	
	for (unsigned int j = 0; j < matrix.size(); j++)
	{
		std::map<std::pair<int, int>, int> costOfPath = dijkstraGetPathsCosts<muhGrater>(matrix, std::pair<int, int>(j, 0), get3WayGridNeighbors, lessThan);

		for (unsigned int i = 0; i < matrix.size(); i++)
		{
			int currPath = costOfPath[std::pair<int, int>(i, matrix[i].size() - 1 )];
			if (bestPath == 0 || currPath < bestPath)
				bestPath = currPath;
		}
	}

	return bestPath;
}

std::vector<std::pair<int, int>> eulerProblem82::get3WayGridNeighbors(const unsigned int nRows, const unsigned int nCols, const unsigned int i, const unsigned int j)
{
	std::vector<std::pair<int, int>> neigbors;
	if (i < nRows - 1)
		neigbors.push_back(std::pair<int, int>(i + 1, j)); //rightNeighbor
	if (j < nCols - 1)
		neigbors.push_back(std::pair<int, int>(i, j + 1)); //bottomNeighbor
	if (i > 0)
		neigbors.push_back(std::pair<int, int>(i - 1, j)); //topNeighbor

	return neigbors;
}

bool eulerProblem82::lessThan(int first, int second)
{
	return first < second;
}
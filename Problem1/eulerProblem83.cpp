#include "eulerProblem83.h"

/**
*	Find the minimal path sum, in matrix.txt (right click and "Save Link/Target As..."),
*	a 31K text file containing a 80 by 80 matrix, from the top left to the bottom right by moving left, right, up, and down.
*/

/**
*	pretty much just redirects to the problem81 dijkstra pathfinder, but with the different neighbor-seeking function
*/
int eulerProblem83::shortest4WayMatrixPathSum(const std::vector< std::vector<int>>& matrix)
{
	return dijkstraShortestPathSum(matrix, ge4WayGridNeighbors);
}

std::vector<std::pair<int, int>> eulerProblem83::ge4WayGridNeighbors(const unsigned int nRows, const unsigned int nCols, const unsigned int i, const unsigned int j)
{
	std::vector<std::pair<int, int>> neigbors;
	if (i < nRows - 1)
		neigbors.push_back(std::pair<int, int>(i + 1, j)); //bottomNeighbor
	if (i > 0)
		neigbors.push_back(std::pair<int, int>(i - 1, j)); //topNeighbor
	if (j < nCols - 1)
		neigbors.push_back(std::pair<int, int>(i, j + 1)); //rightNeighbor
	if (j > 0)
		neigbors.push_back(std::pair<int, int>(i, j - 1)); //leftNeighbor

	return neigbors;
}
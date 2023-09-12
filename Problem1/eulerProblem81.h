#ifndef EULER_PROBLEM81
#define EULER_PROBLEM81

#include "eulerHelpers.h"
#include <algorithm>
#include <queue>
#include <map>
#include <functional>     // std::greater

using namespace eulerHelpers;

namespace eulerProblem81
{
	//////Bruteforce
	bool isNeighbor(const std::pair<int, int>& element, const std::pair<int, int>& elementsProbableNeighbor);
	int bruteforceShortestPathSum(const std::vector< std::vector<int>>& matrix);

	////DIJKSTRA HERE
	std::vector<std::pair<int, int>> ge2WayGridNeighbors(const unsigned int nRows, const unsigned int nCols, const unsigned int i, const unsigned int j);

	int shortest2WayMatrixPathSum(const std::vector< std::vector<int>>& matrix);
}

#endif
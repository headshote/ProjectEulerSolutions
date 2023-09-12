#ifndef EULER_PROBLEM82
#define EULER_PROBLEM82

#include "eulerHelpers.h"

using namespace eulerHelpers;

namespace eulerProblem82
{
	std::vector<std::pair<int, int>> get3WayGridNeighbors(const unsigned int nRows, const unsigned int nCols, const unsigned int i, const unsigned int j);

	int shortest3WayMatrixPathSum(const std::vector< std::vector<int>>& matrix);

	bool lessThan(int first, int second);
}

#endif
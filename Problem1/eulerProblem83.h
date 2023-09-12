#ifndef EULER_PROBLEM83
#define EULER_PROBLEM83

#include "eulerHelpers.h"

using namespace eulerHelpers;

namespace eulerProblem83
{
	std::vector<std::pair<int, int>> ge4WayGridNeighbors(const unsigned int nRows, const unsigned int nCols, const unsigned int i, const unsigned int j);
	int shortest4WayMatrixPathSum(const std::vector< std::vector<int>>& matrix);
}

#endif
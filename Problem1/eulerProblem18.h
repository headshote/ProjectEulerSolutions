#ifndef EULER_PROBLEM18
#define EULER_PROBLEM18

#include "eulerHelpers.h"
#include <map>

using namespace eulerHelpers;

namespace eulerProblem18
{
	struct muh_less : public std::binary_function<std::pair<int, std::pair<int, int>>, std::pair<int, std::pair<int, int>>, bool>
	{	// functor for operator<
		bool operator()(const  std::pair<int, std::pair<int, int>>& _Left, const  std::pair<int, std::pair<int, int>>& _Right) const;
	};

	std::vector<std::pair<int, int>> geTriangledNeighbors(const unsigned int nRows, const unsigned int nCols, const unsigned int i, const unsigned int j);

	bool greaterThan(int first, int second);	

	int longestTrianglePathSum(const std::vector< std::vector<int>>& grid);
}

#endif
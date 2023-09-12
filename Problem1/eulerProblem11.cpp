#include "eulerProblem11.h"

/**
*	What is the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally) in the 20×20 grid?
*/

long long eulerProblem11::max4IntsMatrixProduct(std::vector< std::vector<int>>& matrix)
{
	long long horizontalProduct = 0;
	long long verticalProduct = 0;
	long long lefrRightDiagProduct = 0;
	long long rightLeftProduct = 0;
	long long maxProduct = horizontalProduct;

	for (unsigned int i = 0; i < matrix.size(); ++i)
		for (unsigned int j = 0; j < matrix[i].size(); ++j)
		{
			if (i < matrix.size() - 3 && j < matrix[i].size() - 3)
				lefrRightDiagProduct = matrix[i][j] * matrix[i + 1][j + 1] * matrix[i + 2][j + 2] * matrix[i + 3][j + 3];

			if (i > 2 && j < matrix[i].size() - 3)
				rightLeftProduct = matrix[i][j] * matrix[i - 1][j + 1] * matrix[i - 2][j + 2] * matrix[i - 3][j + 3];

			if (j < matrix[i].size() - 3)
				horizontalProduct = matrix[i][j] * matrix[i][j + 1] * matrix[i][j + 2] * matrix[i][j + 3];

			if (i < matrix.size() - 3)
				verticalProduct = matrix[i][j] * matrix[i + 1][j] * matrix[i + 2][j] * matrix[i + 3][j];

			if (horizontalProduct > maxProduct)
				maxProduct = horizontalProduct;
			if (verticalProduct > maxProduct)
				maxProduct = verticalProduct;
			if (lefrRightDiagProduct > maxProduct)
				maxProduct = lefrRightDiagProduct;
			if (rightLeftProduct > maxProduct)
				maxProduct = rightLeftProduct;
		}

	return maxProduct;
}
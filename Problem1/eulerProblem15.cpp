#include "eulerProblem15.h"

/**
*	Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
*	How many such routes are there through a 20×20 grid?
*/

unsigned long long eulerProblem15::numMatrixPathsCombinatorial(const unsigned int m, const unsigned int n)
{
	return factorial(m + n) / (factorial(m) * factorial(n));
}

unsigned long long eulerProblem15::longiterativeNumMatrixPaths(const unsigned int m, const unsigned int n)
{
	const unsigned int nCols = m + 1;
	const unsigned int nRows = n + 1;

	std::vector<std::vector<unsigned long long>> paths(nRows);


	//1s in the first row
	for (unsigned int i = 0; i < nRows; i++)
	{
		paths[i] = std::vector<unsigned long long>(nCols);
		paths[i][0] = 1;
	}

	//1s in the first colon
	for (unsigned int j = 0; j < nCols; j++)
	{
		paths[0][j] = 1;
	}

	//Calculate the amount of paths,, as the sum of 'indices' of the left and top neighbors, 
	//that way filling the matrix with the anount of paths there is from top left to to the curent element
	//Once we reach the last element, we'll have our answer
	for (unsigned int i = 1; i <= m; i++)
		for (unsigned int j = 1; j <= n; j++)
			paths[i][j] = paths[i - 1][j] + paths[i][j - 1];

	return paths[m][n];
}
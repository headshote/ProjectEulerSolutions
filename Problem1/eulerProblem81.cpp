#include "eulerProblem81.h"

/**
*	Find the minimal path sum, in matrix.txt, a 31K text file containing a 80 by 80 matrix,
*	from the top left to the bottom right by only moving right and down.
*/

///////Bruteforce
bool eulerProblem81::isNeighbor(const std::pair<int, int>& element, const std::pair<int, int>& elementsProbableNeighbor)
{
	return (element.first + 1 == elementsProbableNeighbor.first && element.second == elementsProbableNeighbor.second) ||
		(element.first == elementsProbableNeighbor.first && element.second + 1 == elementsProbableNeighbor.second);
}

int eulerProblem81::bruteforceShortestPathSum(const std::vector< std::vector<int>>& matrix)
{
	const unsigned int nCols = matrix.size();
	const unsigned int nRows = matrix[nCols - 1].size();

	//std::vector<int> paths;

	std::vector<std::pair<int, int>> elementList;
	std::vector<std::pair<int, int>> visitedElements;
	elementList.push_back(std::pair<int, int>(0, 0));

	int path = 0;
	int minPath = -1;

	while (elementList.size() > 0)
	{
		const std::pair<int, int>& currentElement = elementList[elementList.size() - 1];
		visitedElements.push_back(currentElement);
		elementList.pop_back();

		unsigned int i = currentElement.first, j = currentElement.second;

		path += matrix[i][j];

		if (i < nCols - 1)
			elementList.push_back(std::pair<int, int>(i + 1, j)); //rightNeighbor
		if (j < nRows - 1)
			elementList.push_back(std::pair<int, int>(i, j + 1)); //bottomNeighbor

		if (i == nCols - 1 && j == nRows - 1)
		{
			if (minPath < 0 || path < minPath)
				minPath = path;

			//paths.push_back(path);

			//while visited item's bottom or right neighbor't isn't equal to the item on top of the searchlist, 
			//keep popping items from visited, and reducing the path sum, by those elems 
			if (elementList.size() > 0)
			{
				const std::pair<int, int>& nextSearchElem = elementList[elementList.size() - 1];
				do
				{
					const std::pair<int, int>& lastVisitedElem = visitedElements[visitedElements.size() - 1];
					visitedElements.pop_back();
					path -= matrix[lastVisitedElem.first][lastVisitedElem.second];
				} while (!isNeighbor(visitedElements[visitedElements.size() - 1], nextSearchElem));
			}
		}
	}

	//std::sort(paths.begin(), paths.end(), [](int i, int j){return i < j; });

	return minPath;
}

//////Dijkstra
std::vector<std::pair<int, int>> eulerProblem81::ge2WayGridNeighbors(const unsigned int nRows, const unsigned int nCols, const unsigned int i, const unsigned int j)
{
	std::vector<std::pair<int, int>> neigbors;
	if (i < nRows - 1)
		neigbors.push_back(std::pair<int, int>(i + 1, j)); //bottomNeighbor
	if (j < nCols - 1)
		neigbors.push_back(std::pair<int, int>(i, j + 1)); //rightNeighbor

	return neigbors;
}

int eulerProblem81::shortest2WayMatrixPathSum(const std::vector< std::vector<int>>& matrix)
{
	return dijkstraShortestPathSum(matrix, ge2WayGridNeighbors);
}

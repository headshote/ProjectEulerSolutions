#include "eulerProblem67.h"

/**
*	By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.
*
*	   3
*	  7 4
*	 2 4 6
*	8 5 9 3
*	
*	That is, 3 + 7 + 4 + 9 = 23.
*	
*	Find the maximum total from top to bottom in triangle.txt (right click and 'Save Link/Target As...'), a 15K text file containing a triangle with one-hundred rows.
*/


unsigned int eulerProblem67::p67Solution(std::vector< std::vector<int>> pyramid)
{
	//Just forward to Dijkstra path-finding from problem 18
	return eulerProblem18::longestTrianglePathSum(pyramid);
}
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

#include "eulerHelpers.h"
#include "eulerProblem1.h"
#include "eulerProblem2.h"
#include "eulerProblem3.h"
#include "eulerProblem4.h"
#include "eulerProblem5.h"
#include "eulerProblem6.h"
#include "eulerProblem7.h"
#include "eulerProblem8.h"
#include "eulerProblem10.h"
#include "eulerProblem11.h"
#include "eulerProblem12.h"
#include "eulerProblem13.h"
#include "eulerProblem15.h"
#include "eulerProblem16.h"
#include "eulerProblem18.h"
#include "eulerProblem20.h"
#include "eulerProblem22.h"
#include "eulerProblem81.h"
#include "eulerProblem357.h"
#include "eulerProblem25.h"
#include "eulerProblem24.h"
#include "eulerProblem67.h"
#include "eulerProblem83.h"
#include "eulerProblem82.h"
#include "eulerProblem31.h"
#include "eulerProblem9.h"
#include "eulerProblem30.h"

using namespace eulerHelpers;

int main(const int argc, const char** argv)
{
	unsigned int problem1 = eulerProblem1::sum3n5Multiples(1000);
	std::cout << "Problem 1. sum of 3 and 5 multiples up to 1000: " << problem1 << std::endl;
	
	unsigned int problem2 = eulerProblem2::sumEvenFibonacci(4000000);
	std::cout << "Problem 2. sum of the even terms in the Fibonacci sequence under 4M: " << problem2 << std::endl;

	unsigned int problem3 = eulerProblem3::largestPrimeFactor(600851475143);
	std::cout << "Problem 3. largestPrimeFactor(600851475143): " << problem3 << std::endl;

	std::vector< std::vector<int>> matrix81 = readMatrixFromFile("inputs/p81_matrix.txt");
	unsigned int problem81 = eulerProblem81::shortest2WayMatrixPathSum(matrix81);
	std::cout << "Problem 81: matrix's 2-way diagonal shortest path: " << problem81 << std::endl;

	unsigned int problem4 = eulerProblem4::largestPalidr2x3Digits();
	std::cout << "Problem 4: Largest 6-digit palidrome num: " << problem4 << std::endl;

	unsigned long long problem5 = eulerProblem5::smallestEvDiv1toN(20);
	std::cout << "Problem 5: Smallest num, evenly divisible by 1..20: " << problem5 << std::endl;

	long long problem6 = eulerProblem6::problem6Solution(100);
	std::cout << "Problem 6: sum of squares - square of sum: " << problem6 << std::endl;

	unsigned long long problem7 = eulerProblem7::nthPrime(10001);
	std::cout << "Problem 7: 10001st prime: " << problem7 << std::endl;

	unsigned long long problem8 = eulerProblem8::greatestProdNAdjacentDigits(13);
	std::cout << "Problem 8: last 13 digits of 50 100-digits nums sum: " << problem8 << std::endl;

	unsigned long long problem9 = eulerProblem9::pythagoreanTripletProductIfSum(1000);
	std::cout << "Problem 9: product of pythag triple with sum of 1k: " << problem9 << std::endl;

	unsigned long long problem10 = eulerProblem10::sumOfPrimesBelow(2000000);
	std::cout << "Problem 10: sum of primes below 2m: " << problem10 << std::endl;

	unsigned long long problem357 = 1739023853137L;//eulerProblem357::p357SolutionNaive(100000000);	//slow af, about 2 mins to compute, naive
	std::cout << "Problem 357: " << problem357 << std::endl;

	std::vector< std::vector<int>> matrix11 = readMatrixFromFile("inputs/p11Matrix.txt", " ");
	unsigned int problem11 = eulerProblem11::max4IntsMatrixProduct(matrix11);
	std::cout << "Problem 11: matrix's max 4 int product: " << problem11 << std::endl;

	unsigned long long problem12 = eulerProblem12::firstTriangNumWithNDivisors(500);
	std::cout << "Problem 12: first triang num with 500 divisors: " << problem12 << std::endl;

	std::vector<std::string> bigNmbers = readLinesFromFile("inputs/p13.txt");
	unsigned long long problem13 = eulerProblem13::first10DigitsOfLargeNumSum(bigNmbers);
	std::cout << "Problem 13: first 10 digits of a sum of 100 50-digit numbers: " << problem13 << std::endl;

	unsigned long long problem15 = eulerProblem15::numMatrixPathsCombinatorial(20, 20);
	unsigned long long problem15b = eulerProblem15::longiterativeNumMatrixPaths(20, 20);
	std::cout << "Problem 15: paths in 20x20 matrix: " << problem15 << " iterative: " << problem15b << std::endl;

	unsigned long long problem16 = eulerProblem16::calculateLargePowerOfTwoDigitsSum(1000);
	std::cout << "Problem 16: 2^1k digit sum " << problem16 << std::endl;

	std::vector< std::vector<int>> pyram18 = readMatrixFromFile("inputs/p18.txt", " ");
	unsigned int problem18 = eulerProblem18::longestTrianglePathSum(pyram18);
	std::cout << "Problem 18: longest pyramid path: " << problem18 << std::endl;

	unsigned long long problem20 = eulerProblem20::calculateLargeFactorialDigitsSum(100);
	std::cout << "Problem 20: 100! digit sum " << problem20 << std::endl;

	unsigned int problem25 = eulerProblem25::findIndexOFFirstFibonacciWithNDigits(1000);
	std::cout << "Problem 25: index of the first 1k-digit fibon num: " << problem25 << std::endl;

	unsigned long long problem24 = eulerProblem24::nThMdigitPermutation(1000000, 10);
	std::cout << "Problem 24: 1M-th 10-digit permutation: " << problem24 << std::endl;

	unsigned int problem31 = eulerProblem31::p31RecursiveSolution(200);
	std::cout << "Problem 31: Number of times you can make 2pounds with coins: " << problem31 << std::endl;

	unsigned long long problem30 = eulerProblem30::sumOfDigitNthPowers(5);
	std::cout << "Problem 30: Sum of nums that = the sum of their digits^5: " << problem30 << std::endl;

	std::string& p22Names = readFileString("inputs/p022_names.txt");
	std::vector<std::string>& p22NamesArray = prepareArrayOfWords(p22Names, 1, p22Names.size()-1, "\",\"");
	eulerProblem22::sortAplabeticallyStrVector(p22NamesArray);
	unsigned long long problem22 = eulerProblem22::totalOfNameScore(p22NamesArray);
	std::cout << "Problem 22: names total score: " << problem22 << std::endl;

	std::vector< std::vector<int>> pyram67 = readMatrixFromFile("inputs/p067_triangle.txt", " ");
	unsigned int problem67 = eulerProblem67::p67Solution(pyram67);
	std::cout << "Problem 67: longest pyramid path: " << problem67 << std::endl;

	std::vector< std::vector<int>> matrix83 = readMatrixFromFile("inputs/p081_matrix.txt");
	unsigned int problem83 = eulerProblem83::shortest4WayMatrixPathSum(matrix83);
	std::cout << "Problem 83: matrix's 4-way diagonal shortest path: " << problem83 << std::endl;

	std::vector< std::vector<int>> matrix82 = readMatrixFromFile("inputs/p082_matrix.txt");
	unsigned int problem82 = eulerProblem82::shortest3WayMatrixPathSum(matrix82);
	std::cout << "Problem 82: matrix's 3-way left-to-right shortest path: " << problem82 << std::endl;

	getchar();

	return EXIT_SUCCESS;
}
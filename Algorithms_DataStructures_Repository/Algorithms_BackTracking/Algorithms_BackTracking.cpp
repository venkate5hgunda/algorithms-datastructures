#include <iostream>
#include "NQueensProblem.h"
#include "GraphColoring.h"
#include "KnightTourProblem.h"

int main()
{
	#pragma region NQueensProblem
	//NQueensProblem problem{ 50 };
	//problem.solve();
	//return 0;
	#pragma endregion

	#pragma region GraphColoringProblem
	//const vector<vector<int>> graphMatrix = {
	//	{0,1,0,1,0},
	//	{1,0,1,1,0},
	//	{0,1,0,1,0},
	//	{1,1,1,0,1},
	//	{0,0,0,1,0}
	//};
	//constexpr int numberOfColors = 3;

	//GraphColoring graphColoring(graphMatrix, numberOfColors);
	//graphColoring();
	//return 0;
	#pragma endregion

	#pragma region KnightTourProblem
	KnightTourProblem knightTour;
	knightTour.solveKnightTourProblem();
	return 0;
	#pragma endregion
}

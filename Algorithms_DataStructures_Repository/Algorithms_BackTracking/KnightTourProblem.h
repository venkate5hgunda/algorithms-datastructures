#pragma once
#include <vector>
#include <array>
using std::vector;

class KnightTourProblem
{
	vector<vector<int>> solutionMatrix;
	const static std::array<int, 8> xMoves;
	const static std::array<int, 8> yMoves;
	constexpr static int Board_Size = 8;

public:
	KnightTourProblem();

	void solveKnightTourProblem();
	bool solveProblem(int stepCount, int x, int y);
	
	bool isValidMove(int x, int y);

	void showSolution();

private:
	void initializeBoard();
};


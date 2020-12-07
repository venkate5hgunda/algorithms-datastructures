#include "KnightTourProblem.h"
#include <iostream>
#include <iomanip>

using namespace std;

const std::array<int, 8> KnightTourProblem::xMoves = {1,2,2,1,-1,-2,-2,-1};
const std::array<int, 8> KnightTourProblem::yMoves = {2,1,-1,-2,-2,-1,1,2};

KnightTourProblem::KnightTourProblem() {
	solutionMatrix.resize(Board_Size);

	for (auto& subMatrix : solutionMatrix) {
		subMatrix.resize(Board_Size);
	}
	initializeBoard();
}

void KnightTourProblem::solveKnightTourProblem() {
	solutionMatrix[0][0] = 0;

	if (!solveProblem(1, 0, 0)) {
		cout << "No Solution Found for the Problem..." << endl;
		return;
	}
	showSolution();
}

bool KnightTourProblem::solveProblem(int stepCount, int x, int y) {
	if (stepCount == Board_Size * Board_Size) {
		return true;
	}

	for (size_t i = 0; i < xMoves.size(); ++i) {
		int nextX = x + xMoves[i];
		int nextY = y + yMoves[i];

		if (isValidMove(nextX, nextY)) {
			solutionMatrix[nextX][nextY] = stepCount;

			if (solveProblem(stepCount + 1, nextX, nextY)) {
				return true;
			}
			solutionMatrix[nextX][nextY] = INT_MIN;
		}
	}
	return false;
}

bool KnightTourProblem::isValidMove(int x, int y) {
	if (x < 0 || x >= Board_Size) {
		return false;
	}
	if (y < 0 || y >= Board_Size) {
		return false;
	}
	if (solutionMatrix[x][y] != INT_MIN) {
		return false;
	}
	return true;
}

void KnightTourProblem::showSolution() {
	for (int i = 0; i < Board_Size; ++i) {
		cout << std::left;
		for (int j = 0; j < Board_Size; ++j) {
			cout << std::setw(2) << solutionMatrix[i][j] << std::setw(2) << ' ';
		}
		cout << endl;
	}
}

void KnightTourProblem::initializeBoard() {
	for (int i = 0; i < Board_Size; ++i) {
		for (int j = 0; j < Board_Size; ++j) {
			solutionMatrix[i][j] = INT_MIN;
		}
	}
}
#include "NQueensProblem.h"
#include <iostream>
#include <stdio.h>

using namespace std;

NQueensProblem::NQueensProblem(int _numberOfQueens) : numberOfQueens(_numberOfQueens) {
	chessTable.resize(numberOfQueens);
	for (auto& chessRow : chessTable) {
		chessRow.resize(numberOfQueens);
	}
}

void NQueensProblem::solve() {
	if (setQueens(0)) {
		printQueens();
	}
	else {
		cout << "There is no solution..." << endl;
	}
}

bool NQueensProblem::setQueens(int colIndex) {
	if (colIndex == numberOfQueens) {
		return true;
	}

	for (int rowIndex = 0; rowIndex < numberOfQueens; ++rowIndex) {
		if (isPlaceValid(rowIndex, colIndex)) {
			chessTable[rowIndex][colIndex] = 1;

			if (setQueens(colIndex + 1)) {
				return true;
			}

			chessTable[rowIndex][colIndex] = 0;
		}
	}

	return false;
}

bool NQueensProblem::isPlaceValid(int rowIndex, int colIndex) const {
	for (int i = 0; i < colIndex; i++) {
		if (chessTable[rowIndex][i] == 1) {
			return false;
		}
	}

	for (int i = rowIndex, j = colIndex; i >= 0 && j >= 0; i--, j--) {
		if (chessTable[i][j] == 1) {
			return false;
		}
	}

	for (int i = rowIndex, j = colIndex; i < numberOfQueens && j >= 0; i++, j--) {
		if (chessTable[i][j] == 1) {
			return false;
		}
	}

	return true;
}

void NQueensProblem::printQueens() const {
	for (size_t i = 0; i < chessTable.size(); i++) {
		for (size_t j = 0; j < chessTable.size(); j++) {
			if (chessTable[i][j] == 1) {
				cout << " Q ";
			}
			else {
				cout << " . ";
			}
		}
		cout << endl;
	}
}
#pragma once
#include <vector>
using std::vector;


class NQueensProblem
{
	vector<vector<int>> chessTable;
	int numberOfQueens = 0;

public:
	NQueensProblem(int _numberOfQueens);
	void solve();

private:
	bool setQueens(int colIndex);
	bool isPlaceValid(int rowIndex, int colIndex) const;
	void printQueens() const;
};


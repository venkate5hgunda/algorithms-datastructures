#ifndef GraphColoring_h
#define GraphColoring_h

#include <vector>
using std::vector;

class GraphColoring {
	vector<vector<int>> graphMatrix;
	int numberOfColors;
	vector<int> nodeColors;

public:
	GraphColoring(const vector<vector<int>>& graph, int _numberOfColors);

	void operator()();

private:
	bool solve(size_t nodeIndex);

	bool isColorValid(size_t nodeIndex, size_t colorIndex);

	void showResult();
};

#endif // !GraphColoring_h





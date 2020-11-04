#include "GraphColoring.h"
#include <iostream>
using namespace std;

GraphColoring::GraphColoring(const vector<vector<int>>& graph, int _numberOfColors) : graphMatrix(graph), numberOfColors(_numberOfColors) {
	nodeColors.resize(graphMatrix.size());
}

void GraphColoring::operator()() {
	if (solve(0)) {
		showResult();
	}
	else {
		cout << "No solution with the given parameters..." << endl;
	}
}

bool GraphColoring::solve(size_t nodeIndex) {
	if (nodeIndex == graphMatrix.size()) {
		return true;
	}

	for (int colorIndex = 1; colorIndex <= numberOfColors; colorIndex++) {
		if (isColorValid(nodeIndex, colorIndex)) {
			nodeColors[nodeIndex] = colorIndex;

			if (solve(nodeIndex + 1)) {
				return true;
			}
		}
	}
	return false;
}

bool GraphColoring::isColorValid(size_t nodeIndex, size_t colorIndex) {
	for (size_t i = 0; i < graphMatrix.size(); i++) {
		if (graphMatrix[nodeIndex][i] == 1 && colorIndex == nodeColors[i]) {
			return false;
		}
	}
	return true;
}

void GraphColoring::showResult() {
	for (size_t i = 0; i < graphMatrix.size(); i++) {
		cout << "Node " << (i + 1) << " has color index: " << nodeColors[i] << endl;
	}
	cout << endl;
}

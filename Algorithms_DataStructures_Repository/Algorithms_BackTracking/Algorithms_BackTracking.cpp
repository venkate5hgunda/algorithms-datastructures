#include <iostream>
#include "NQueensProblem.h"

int main()
{
	#pragma region NQueensProblem
	NQueensProblem problem{ 8 };
	problem.solve();
	return 0;
	#pragma endregion
}

#include <stdio.h>
#include <vector>
#include <string>
#include "solveNQueens.h"

using namespace std;

void printMatrix(vector<vector<string>> matrix)
{
	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix[i].size(); ++j)
		{
			printf("%s", matrix[i][j].c_str());
		}
		printf("\n");
	}
	printf("\n");
}

int main()
{
	SolutionSolveNQueens s;
	vector<vector<string>> queens = s.solveNQueens(4);

	printMatrix(queens);

	return 0;
}
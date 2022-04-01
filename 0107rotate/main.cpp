#include <stdio.h>
#include <vector>

#include "rotate.h"

void printMatrixInRotate(vector<vector<int>>& matrix)
{
	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix[i].size(); ++j)
		{
			printf("%2d ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main()
{
	vector<vector<int>> matrix
	{
		{5, 1, 9,11},
		{2, 4, 8,10},
		{13, 3, 6, 7},
		{15,14,12,16}
	};

	printMatrixInRotate(matrix);

	SolutionRotate s;
	s.rotate(matrix);

	printMatrixInRotate(matrix);

	return 0;
}
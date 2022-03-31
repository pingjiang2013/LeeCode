#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int m = matrix.size();
		int n = matrix[0].size();

		vector<bool> row(m), col(n);
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (0 == matrix[i][j])
				{
					row[i] = col[j] = true;
				}
			}
		}

		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (row[i] || col[j])
				{
					matrix[i][j] = 0;
				}

			}
		}
	}
};


void printMatrix(vector<vector<int>>& matrix)
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
		{0, 1, 9,0},
		{2, 4, 8,10},
		{13, 3, 6, 7},
		{15,14,12,16}
	};

	printMatrix(matrix);

	Solution s;
	s.setZeroes(matrix);

	printMatrix(matrix);

	return 0;
}
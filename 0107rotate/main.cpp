#include <stdio.h>
#include <vector>

#include "rotate.h"

/*
[ 5,  1,  9, 11]
[ 2,  4,  8, 10]
[13,  3,  6,  7]
[15, 14, 12, 16]

[15, 13,  2,  5]
[14,  3,  4,  1]
[12,  6,  8,  9]
[16,  7, 10, 11]

0, 0 -> 0, 3
0, 3 -> 3, 3
3, 3 -> 3, 0
3, 0 -> 0, 0

0, 1 -> 1, 3
1, 3 -> 3, 2
3, 2 -> 2, 0
2, 0 -> 0, 1

经过观察得出结论：
i, j -> j, n - i - 1
这个规则适合矩阵中的每一个元素。

当i和j一定时（比如都为0），要进行4个数字交换，
所以，需要把右侧的j代入到左侧的i中，
并且把右侧的 n - i - 1代入到左侧的j中
得到：
j, n - i - 1 -> n - i - 1, n - j - 1
继续代入
n - i - 1, n - j - 1 -> n - j - 1, i
继续代入
n - j - 1, i -> i, j

因此，每一轮交换需要一个临时变量和4次交换
temp = i, j
i, j = n - j - 1, i
n - j - 1, i = n - i - 1, n - j - 1
n - i - 1, n - j - 1 = j, n - i - 1
j, n - i - 1 = temp

下一个问题时如何避免重复交换。
有两种解法
一种是从外圈到里圈
for (int i = 0; i < n / 2; ++i)
	for (int j = i; j < n - i - 1; ++j)
n = 3时，外层循环1次，交换一圈
n = 4时，外层循环2次，交换两圈
n = 5时，外层循环2次，交换两圈
每次进入内层循环，内层循环的交换次数减去2，
因为开始的下标加一，结束的下标减一。

另一种是4个角的部分轮转（官方解答）

*/


void SolutionRotate::rotate(vector<vector<int>>& matrix) {
	int n = matrix.size();
	int temp = 0;
	for (int i = 0; i < n / 2; ++i)
	{
		for (int j = i; j < n - i - 1; ++j)
		{
			temp = matrix[i][j];
			matrix[i][j] = matrix[n - j - 1][i];
			matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
			matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
			matrix[j][n - i - 1] = temp;
		}
	}
}


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
		{5, 1, 9,11},
		{2, 4, 8,10},
		{13, 3, 6, 7},
		{15,14,12,16}
	};

	printMatrix(matrix);

	SolutionRotate s;
	s.rotate(matrix);

	printMatrix(matrix);

	return 0;
}
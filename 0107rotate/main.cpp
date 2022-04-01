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

�����۲�ó����ۣ�
i, j -> j, n - i - 1
��������ʺϾ����е�ÿһ��Ԫ�ء�

��i��jһ��ʱ�����綼Ϊ0����Ҫ����4�����ֽ�����
���ԣ���Ҫ���Ҳ��j���뵽����i�У�
���Ұ��Ҳ�� n - i - 1���뵽����j��
�õ���
j, n - i - 1 -> n - i - 1, n - j - 1
��������
n - i - 1, n - j - 1 -> n - j - 1, i
��������
n - j - 1, i -> i, j

��ˣ�ÿһ�ֽ�����Ҫһ����ʱ������4�ν���
temp = i, j
i, j = n - j - 1, i
n - j - 1, i = n - i - 1, n - j - 1
n - i - 1, n - j - 1 = j, n - i - 1
j, n - i - 1 = temp

��һ������ʱ��α����ظ�������
�����ֽⷨ
һ���Ǵ���Ȧ����Ȧ
for (int i = 0; i < n / 2; ++i)
	for (int j = i; j < n - i - 1; ++j)
n = 3ʱ�����ѭ��1�Σ�����һȦ
n = 4ʱ�����ѭ��2�Σ�������Ȧ
n = 5ʱ�����ѭ��2�Σ�������Ȧ
ÿ�ν����ڲ�ѭ�����ڲ�ѭ���Ľ���������ȥ2��
��Ϊ��ʼ���±��һ���������±��һ��

��һ����4���ǵĲ�����ת���ٷ����

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
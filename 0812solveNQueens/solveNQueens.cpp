#include <vector>
#include <string>
#include "solveNQueens.h"

using namespace std;

// ���ڱ�־�Ƿ���Է��ûʺ�
const string ALLOWED = "O";
const string FORBIDDEN = "*";

// �ʺ�Ϳ�λ��
const string QUEEN = "Q";
const string EMPTY = ".";

void SolutionSolveNQueens::updateMark(vector<vector<string>> board)
{
	m_mark.clear();

	// ��ʼ����־
	int n = board.size();
	vector<string> row;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			row.push_back(ALLOWED);
		}
		m_mark.push_back(row);
		row.clear();
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (!board[i][j].compare(QUEEN))
			{
				for (int k = 0; k < n; ++k)
				{
					m_mark[i][k] = FORBIDDEN;
					m_mark[k][j] = FORBIDDEN;
				}

				int distance = 1;
				for (int l = i + 1; l < n; ++l)
				{
					if (j - distance >= 0)
					{
						m_mark[l][j - distance] = FORBIDDEN;
					}
					if (j + distance < n)
					{
						m_mark[l][j + distance] = FORBIDDEN;
					}
					++distance;
				}
				break;
			}
		}
	}
}

bool SolutionSolveNQueens::impSolution(int n, int row, vector<vector<string>> board, vector<vector<string>>& solutions)
{
	if (n == row)
		return true;

	for (int i = 0; i < n; ++i)
	{
		if (!m_mark[row][i].compare(ALLOWED))
		{
			board[row][i] = QUEEN;
			updateMark(board);
			//if (checkQueens(board))
			{
				if (impSolution(n, row + 1, board, solutions))
				{
					for (int j = 0; j < n; ++j)
					{
						solutions.push_back(board[j]);
					}
				}
			}
			board[row][i] = EMPTY;
			updateMark(board);
		}
		else
		{
			continue;
		}
	}

	return false;
}

vector<vector<string>> SolutionSolveNQueens::solveNQueens(int n)
{
	// ��ʼ��������
	vector<vector<string>> board(n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			board[i].push_back(EMPTY);
		}
	}

	// ���������лʺ��λ�ø��±�־
	// ��ʱ��û�лʺ���������λ�ö���־ΪALLOWED
	updateMark(board);

	// ���е���ȷ�Ľⶼ�洢��solutions��
	vector<vector<string>> solutions;

	impSolution(n, 0, board, solutions);

	// �ⲿ�ִ�����Ϊ�˷���LeeCode��Ҫ����ַ����ϲ���
	// ÿһ��string��һ�У�ÿһ��vector<string>��һ���⣬
	// vector<vector<string>>�����еĽ⡣
	vector<vector<string>> queens;
	string row;
	vector<string> solution;
	for (int j = 0; j < solutions.size(); ++j)
	{
		row.clear();
		for (int k = 0; k < solutions[j].size(); ++k)
		{
			row = row + solutions[j][k];
		}
		solution.push_back(row);
		if (0 == (j + 1) % solutions[0].size())
		{
			queens.push_back(solution);
			solution.clear();
		}
	}

	return queens;
}
#include <vector>
#include <string>
#include "solveNQueens.h"

using namespace std;

// 用于标志是否可以放置皇后
const string ALLOWED = "O";
const string FORBIDDEN = "*";

// 皇后和空位置
const string QUEEN = "Q";
const string EMPTY = ".";

void SolutionSolveNQueens::updateMark(vector<vector<string>> board)
{
	m_mark.clear();

	// 初始化标志
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
	// 初始化空棋盘
	vector<vector<string>> board(n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			board[i].push_back(EMPTY);
		}
	}

	// 根据棋盘中皇后的位置更新标志
	// 此时还没有皇后所以所有位置都标志为ALLOWED
	updateMark(board);

	// 所有的正确的解都存储在solutions中
	vector<vector<string>> solutions;

	impSolution(n, 0, board, solutions);

	// 这部分代码是为了符合LeeCode的要求把字符串合并了
	// 每一个string是一行，每一个vector<string>是一个解，
	// vector<vector<string>>是所有的解。
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
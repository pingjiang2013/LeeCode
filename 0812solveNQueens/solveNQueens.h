#pragma once
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class SolutionSolveNQueens {
public:
	void updateMark(vector<vector<string>> board);
	vector<vector<string>> solveNQueens(int n);
	bool impSolution(int n, int row, vector<vector<string>> board, vector<vector<string>>& solutions);

	vector<vector<string>> m_mark;
};



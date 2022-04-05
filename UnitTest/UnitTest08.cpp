#include "pch.h"
#include "CppUnitTest.h"
#include "utils.h"

#include "../0812solveNQueens/solveNQueens.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest08
{
	TEST_CLASS(UnitTest08)
	{
	public:
		void printMatrix(vector<vector<string>> matrix)
		{
			std::string row;
			char buf[MAX_LENGTH];
			for (int i = 0; i < matrix.size(); ++i)
			{
				row.clear();
				for (int j = 0; j < matrix[i].size(); ++j)
				{
					sprintf_s(buf, MAX_LENGTH, "%s", matrix[i][j].c_str());
					row = row + buf;
				}
				printInUnitTest("%s", row.c_str());

				if (0 == ((i + 1) % matrix[0].size()))
					printInUnitTest(DIVIDING_LINE.c_str());
			}
		}

		TEST_METHOD(TestMethod0812)
		{
			SolutionSolveNQueens s;
			vector<vector<string>> queens = s.solveNQueens(4);
			printMatrix(queens);
			Assert::AreEqual((int)queens.size(), 2);
		}
	};
}

#include "pch.h"
#include "CppUnitTest.h"
#include "utils.h"

#include "../0105oneEditAway/oneEditAway.h"
#include "../0107rotate/rotate.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest01
{
	TEST_CLASS(UnitTest01)
	{
	public:
		TEST_METHOD(TestMethod0105)
		{
			SolutionOneEditAway s;
			bool b = s.oneEditAway("b", "");
			printInUnitTest("%s\n", b ? "true" : "false");
			printInUnitTest(DIVIDING_LINE.c_str());
			Assert::IsTrue(s.oneEditAway("b", ""));
		}

		void printMatrixInRotate(vector<vector<int>>& matrix)
		{
			std::string row;
			char buf[MAX_LENGTH];
			for (int i = 0; i < matrix.size(); ++i)
			{
				row.clear();
				for (int j = 0; j < matrix[i].size(); ++j)
				{
					sprintf_s(buf, MAX_LENGTH, "%2d ", matrix[i][j]);
					row = row + buf;
				}
				printInUnitTest("%s", row.c_str());
			}
			printInUnitTest(DIVIDING_LINE.c_str());
		}

		TEST_METHOD(TestMethod0107)
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
		}
	};
}

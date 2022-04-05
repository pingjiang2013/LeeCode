#include "pch.h"
#include "CppUnitTest.h"
#include "../0105oneEditAway/oneEditAway.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest01
{
	const int MAX_LENGTH = 256;

	TEST_CLASS(UnitTest01)
	{
	public:
		void printInUnitTest(const char* fmt, va_list va)
		{
			char buf[MAX_LENGTH];
			sprintf_s(buf, MAX_LENGTH, fmt, va);
			Logger::WriteMessage(buf);
		}
		TEST_METHOD(TestMethod0105)
		{
			SolutionOneEditAway s;
			bool b = s.oneEditAway("b", "");
			printInUnitTest("%s\n", b ? "true" : "false");
			Assert::IsTrue(s.oneEditAway("b", ""));
		}
	};
}

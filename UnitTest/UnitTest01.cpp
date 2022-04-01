#include "pch.h"
#include "CppUnitTest.h"
#include "../0105oneEditAway/oneEditAway.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest01
{
	TEST_CLASS(UnitTest01)
	{
	public:

		TEST_METHOD(TestMethod01)
		{
			SolutionOneEditAway s;
			Assert::IsTrue(s.oneEditAway("b", ""));
			Assert::IsFalse(s.oneEditAway("ab", ""));
			Assert::IsTrue(s.oneEditAway("abc", "abd"));
		}
	};
}

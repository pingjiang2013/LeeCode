#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
	bool oneEditAway(string first, string second)
	{
		if (first.length() > second.length())
			return (oneEditAway(second, first));

		if (second.length() - first.length() > 1)
			return false;

		bool bDiff = false;

		// 两个字符串等长
		if (first.length() == second.length())
		{
			for (int i = 0; i < first.length(); ++i)
			{
				if (first[i] != second[i])
				{
					if (bDiff)
						return false;
					else
						bDiff = true;
				}
			}
			return true;
		}

		// 两个字符串长度差1
		int i = 0;
		int j = 0;
		for (; i < first.length(); ++i, ++j)
		{
			if (first[i] != second[j])
			{
				if (bDiff)
					return false;
				else
					bDiff = true;

				if (first[i] != second[j + 1])
					return false;
				else
					++j;
			}
		}

		return true;
	}
};

int main()
{
	Solution s;
	bool b = s.oneEditAway("b", "");
	printf("%s\n", b ? "true" : "false");
	return 0;
}
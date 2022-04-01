#include <stdio.h>
#include "oneEditAway.h"

int main()
{
	SolutionOneEditAway s;
	bool b = s.oneEditAway("b", "");
	printf("%s\n", b ? "true" : "false");
	return 0;
}
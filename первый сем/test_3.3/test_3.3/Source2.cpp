#include "automat.h"

bool test()
{
	char testString1[20] = "Abs123";
	if (!finiteAutomaton(testString1))
	{
		return false;
	}

	char testString2[20] = "abs123";
	if (!finiteAutomaton(testString2))
	{
		return false;
	}

	char testString3[20] = "_abc--";
	if (finiteAutomaton(testString3))
	{
		return false;
	}

	char testString4[20] = "Zbc--";
	if (finiteAutomaton(testString4))
	{
		return false;
	}

	char testString5[20] = "Zb158";
	if (!finiteAutomaton(testString5))
	{
		return false;
	}

	char testString6[20] = "Zbckgkjkjdf_47";
	if (!finiteAutomaton(testString6))
	{
		return false;
	}
	
	return true;
}
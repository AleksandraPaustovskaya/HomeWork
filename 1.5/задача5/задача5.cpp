#include <stdio.h>

int main()
{
	const int length = 100;
	char bracketCounter[length]{};
	fgets(bracketCounter, length, stdin);

	if (bracketCounter[0] == ')')
	{
		printf("error 0");
		return 0;
	}

	int counterOpen = 0;
	int counterClose = 0;
	for (int counterOfArray = 0; counterOfArray < length; ++counterOfArray)
	{
		if (bracketCounter[counterOfArray] == '(')
		{
			counterOpen++;
			printf("%d\n", counterOpen);
		}
		else if (bracketCounter[counterOfArray] == ')')
		{
			counterClose++;
			printf("%d\n", counterClose);
		}
		else
		{
			break;
		}
	
		if (counterClose > counterOpen)
		{
			printf("error 1");
			return 0;
		}
	}
	if (counterClose == counterOpen)
	{
		printf("ok");
	}
	else if (counterClose < counterOpen)
	{
		printf("error 2");
	}
	return 0;
}
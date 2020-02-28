#include <stdio.h>

int main()
{
	int a = 0;
	int b = 0;
	bool signB = true;
	int answer = 0;

	printf("enter a and b\n");

	scanf("%d", &a);
	scanf("%d", &b);

	if (b == 0)
	{
		printf("\n Error \n");
		return 0;
	}
	else if (a == 0)
	{
		printf("0");
	}
	else if (b < 0)
	{
		signB = false;
		b = -b;
	}
	
	if (a < 0)
	{
		while (a < 0)
		{
			answer++;
			a = a + b;
		}
		answer = -answer;
	}
	else
	{
		while (a >= b)
		{
			answer++;
			a = a - b;
		}
	}
	if (!signB)
	{
		answer *= -1;
	}
	printf("%d", answer);
	return 0;
}
#include <stdio.h>

int fibonachiRecursive(int i)
{
	if (i <= 0)
	{
		return -1;
	}
	else if (i < 3)
	{
		return 1;
	}
	else
	{
		return fibonachiRecursive(i - 1) + fibonachiRecursive(i - 2);
	}
}

int fibonachiIterative(int size)
{
	if (size <= 0)
	{
		return -1;
	}

	if (size < 2)
	{
		return 1;
	}

	int fibonacci1 = 0;
	int fibonacci2 = 1;
	int result = 0;

	for (int j = 2; j <= size; j++)
	{
		if (fibonacci1 < fibonacci2)
		{
			fibonacci1 = fibonacci1 + fibonacci2;
			result = fibonacci1;
		}
		else
		{
			fibonacci2 = fibonacci1 + fibonacci2;
			result = fibonacci2;
		}
	}
	return result;
}

bool test()
{
	if (fibonachiRecursive(1) != 1)
	{
		return false;
	}
	if (fibonachiIterative(1) != 1)
	{
		return false;
	}
	if (fibonachiRecursive(-5) != -1)
	{
		return false;
	}
	if (fibonachiIterative(-1) != -1)
	{
		return false;
	}
	if (fibonachiIterative(-7) != -1)
	{
		return false;
	}
	if (fibonachiRecursive(10) != 55)
	{
		return false;
	}
	if (fibonachiIterative(10) != 55)
	{
		return false;
	}

	return true;
}

int main()
{
	printf("Enter number, please\n");
	int n = 0;
	scanf("%d", &n);

	if ((fibonachiRecursive(n) == -1) || (fibonachiIterative(n) == -1))
	{
		printf("incorrect value");
	}
	else if (!test())
	{
		printf("incorrect work of program");
	}
	else
	{
		printf("Numbers of Fibonachi (recursive method):\n\n");
		for (int i = 1; i <= n; i++)
		{
			printf("\t %d element = %d\n", i, fibonachiRecursive(i));
		}

		printf("\n Numbers of Fibonachi (iterative method):\n\n");
		for (int j = 1; j <= n; j++)
		{
			printf("\t %d element = %d\n", j, fibonachiIterative(j));
		}
	}

	return 0;
}
#include <stdio.h>
#include <stdlib.h>

int degreeRecursive(int x, int n)
{
	/*if (((n / 10) * 10) != n)
	{
		return EOF;
	}*/

	if (n == 0)
	{
		return 1;
	}

	if (n == 1)
	{
		return x;
	}
	else
	{
		return x * degreeRecursive(x, n - 1);
	}
}

int degreeIterative(int x, int n)
{
	/*if (((n / 10) * 10) != n)
	{
		return EOF;
	}*/

	if (n == 0)
	{
		return 1;
	}

	int result = 1;
	for (int j = 1; j <= n; j++)
	{
		result = result * x;
	}

	return result;
}


bool test()
{
	if (degreeRecursive(1, 0) != 1)
	{
		return false;
	}

	if (degreeIterative(0, 1) != 0)
	{
		return false;
	}

	if (degreeRecursive(1, 0) != 1)
	{
		return false;
	}

	if (degreeIterative(1, 0) != 1)
	{
		return false;
	}

	if (degreeRecursive(-5, 3) != -125)
	{
		return false;
	}

	if (degreeIterative(-7, 2) != 49)
	{
		return false;
	}

	if (degreeIterative(-7, 1) != -7)
	{
		return false;
	}

	if (degreeRecursive(10, 2) != 100)
	{
		return false;
	}

	if (degreeIterative(10, 2) != 100)
	{
		return false;
	}

	return true;
}

int main()
{
	printf("Enter number, please\n");
	int number = 0;
	scanf("%d", &number);

	printf("Enter degree , please\n");
	int degree = 0;
	scanf("%d", &degree);

	if ((degreeRecursive(number, degree) == EOF) || (degreeIterative(number, degree) == EOF))
	{
		printf("incorrect value");
	}

	else if (test() == false)
	{
		printf("incorrect work of program");
	}

	else
	{
		printf("\nThere is a small chance that the program works correctly\n\n");
		

		printf("\t%d to degree %d (Recursive method) = %d\n\n", number, degree, degreeRecursive(number, degree));

		printf("\t%d to degree %d (Iterative method) = %d\n\n", number, degree, degreeIterative(number, degree));
	}
	return 0;
}
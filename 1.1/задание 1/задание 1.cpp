#include <stdio.h>

int main()
{
	printf("vvedite znachenie x = ");

	int x = 0;
	scanf("%d", &x);

	const int squareOfX = x * x;

	const int result = ((squareOfX + 1) * (squareOfX + x) + 1) / 100;
	printf("%d", result);

	return 0;
}
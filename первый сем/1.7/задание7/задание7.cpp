#include <stdio.h>
#include <math.h>

int main()
{
	int number = 0;
	printf("Enter number, please\n");
	scanf("%d", &number);
	printf("%d\n\n", number);
	printf(" Answer:\n");

	for (int j = 2; j <= number; j++)
	{
		bool hasDivisors = false;
		for (int k = 2; k <= sqrt(j); k++)
		{
			if (j % k == 0)
			{
				hasDivisors = true;
			}
			
		}
		if (!hasDivisors)
		{
			printf("\t%d\n", j);
		}
	}
	return 0;
}
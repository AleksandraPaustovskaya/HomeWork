// Написать программу, считающую количество нулевых элементов в массиве.
#include <stdio.h>

int main()
{
	printf("Enter size of array, please\n");
	int size = 0;
	scanf("%d", &size);
	printf("size = %d\n", size);

	printf("Enter array, please\n");
	int number[100]{};
	int counter = 0;
	for(int i = 0; i < size; i++)
	{
		scanf("%d", &number[i]);
		if (number[i] == 0)
		{
			counter++;
		}
	}
	printf("number of zero elements:\n\t%d", counter);
	return 0;
}
#include <stdio.h>

int check(int array[], int size)
{
	for (int i = 1; i < size; i++)
	{
		if (array[i] < array[i - 1])
			{
				return false;
			}
	}
	return true;
}

void bubble(int bubbleArray[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (bubbleArray[j] > bubbleArray[j + 1])
			{
				int swap = bubbleArray[j];
				bubbleArray[j] = bubbleArray[j + 1];
				bubbleArray[j + 1] = swap;
			}
		}
	}
}

void counting(int countingArray[], int size)
{
	int helpArray[1000]{};
	int copyArray[100]{};
	int maxNumber = countingArray[0];
	for (int i = 0; i < size; i++)
	{
		helpArray[countingArray[i]]++;
		copyArray[i] = countingArray[i];
		if (maxNumber < countingArray[i])
		{
			maxNumber = countingArray[i];
		}
	}
	for (int i = 1; i <= maxNumber; i++)
	{
		helpArray[i] = helpArray[i] + helpArray[i - 1];
	}
	for (int j = size - 1; j >= 0; j--)
	{
		countingArray[helpArray[copyArray[j]] - 1] = copyArray[j];
		helpArray[copyArray[j]]--;
	}
}

bool test()
{
	int checkArray[100]{};
	for (int i = 0; i < 100; i++)
	{
		checkArray[i] = 99 - i;
	}
	bubble(&checkArray[0], 100);
	if (!check(&checkArray[0], 100))
	{
		return false;
	}

	for (int i = 0; i < 100; i++)
	{
		checkArray[i] = 99 - i;
	}
	counting(&checkArray[0], 100);
	if (!check(&checkArray[0], 100))
	{
		return false;
	}

	for (int i = 0; i < 25; i++)
	{
		checkArray[i] = 50 - i;
		checkArray[50 - i] = 50 - i;
	}
	bubble(&checkArray[0], 50);
	if (!check(&checkArray[0], 50))
	{
		return false;
	}

	for (int i = 0; i < 25; i++)
	{
		checkArray[i] = 90 - i;
		checkArray[50 - i] = 90 - i;
	}
	counting(&checkArray[0], 50);
	if (!check(&checkArray[0], 50))
	{
		return false;
	}

	return true;
}

int main()
{
	if (!test())
	{
		printf("-1");
		return 0;
	}
	printf("Enter size of array, please\n");
	int size = 0;
	scanf("%d", &size);
	printf("size = %d\n", size);

	printf("Enter array, please\n");
	int number[100]{};
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &number[i]);
	}

	printf("Select a sorting method, please (0 - bubble sorting, 1 - counting sorting\n");
	int method = 0;
	scanf("%d", &method);

	if (!method)
	{
		bubble(&number[0], size);
	}
	else
	{
		counting(&number[0], size);
	}

	for (int i = 0; i < size; i++)
	{
		printf("in main = %d\n", number[i]);
	}
	return 0;
}
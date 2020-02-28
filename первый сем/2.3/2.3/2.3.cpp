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
		for (int j = 0; j < size - 1 - i ; j++)
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
	int helpArrayNegative[1000]{};
	int copyArray[100]{};
	int maxNumber = countingArray[0];
	int minNumber = 0;

	for (int i = 0; i < size; i++)
	{
		copyArray[i] = countingArray[i];
		if (countingArray[i] >= 0)
		{
			helpArray[countingArray[i]]++;
			if (maxNumber < countingArray[i])
			{
				maxNumber = countingArray[i];
			}
		}
		else
		{
			helpArrayNegative[-countingArray[i]]++;
			if (minNumber > countingArray[i])
			{
				minNumber = countingArray[i];
			}
		}
	}
	for (int i = minNumber + 1; i <= maxNumber; i++)
	{
		if (i > 0)
		{
			helpArray[i] = helpArray[i] + helpArray[i - 1];
		}
		else if (i == 0)
		{
			helpArrayNegative[0] = helpArray[0] + helpArrayNegative[1];
			helpArray[0] = helpArrayNegative[0];
		}
		else
		{
			helpArrayNegative[-i] = helpArrayNegative[-i] + helpArrayNegative[-i + 1];
		}
	}
	for (int j = size - 1; j >= 0; j--)
	{
		if (copyArray[j] >= 0)
		{
			countingArray[helpArray[copyArray[j]] - 1] = copyArray[j];
			helpArray[copyArray[j]]--;
		}
		else
		{
			countingArray[helpArrayNegative[-copyArray[j]] - 1] = copyArray[j];
			helpArrayNegative[-copyArray[j]]--;
		}
	}
}

bool test()
{
	int checkArray[100]{};
	for (int i = 0; i < 100; i++)
	{
		checkArray[i] = 99 - i;
	}
	bubble(checkArray, 100);
	if (!check(checkArray, 100))
	{
		return false;
	}

	for (int i = 0; i < 100; i++)
	{
		checkArray[i] = 99 - i;
	}
	counting(checkArray, 100);
	if (!check(checkArray, 100))
	{
		return false;
	}

	for (int i = 0; i < 25; i++)
	{
		checkArray[i] = 50 - i;
		checkArray[50 - i] = 50 - i;
	}
	bubble(checkArray, 50);
	if (!check(checkArray, 50))
	{
		return false;
	}

	for (int i = 0; i < 25; i++)
	{
		checkArray[i] = 90 - i;
		checkArray[50 - i] = 90 - i;
	}
	counting(checkArray, 50);
	if (!check(checkArray, 50))
	{
		return false;
	}

	for (int i = -10; i < 25; i++)
	{
		checkArray[i + 10] = i;
	}
	counting(checkArray, 35);
	if (!check(checkArray, 35))
	{
		return false;
	}

	return true;
}

int main()
{
	printf("Enter size of array, please\n");
	int size = 0;
	scanf("%d", &size);

	if (!test())
	{
		printf("-1");
		return -1;
	}
	else if (size <= 0)
	{
		printf("Incorrect value");
		return -2;
	}

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
		bubble(number, size);
	}
	else
	{
		counting(number, size);
	}

	for (int i = 0; i < size; i++)
	{
		printf("in main = %d\n", number[i]);
	}
	return 0;
}
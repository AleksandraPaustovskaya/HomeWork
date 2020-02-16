// Реализовать qsort, который для сортировки
//кусков массива размером меньше 10 использует сортировку вставкой.

#include <stdio.h>

int check(int array[], int size)
{
	for (int i = 1; i <= size; i++)
	{
		if (array[i] < array[i - 1])
		{
			return false;
		}
	}
	return true;
}

int insertSort(int countingArray[], int lo, int hi)
{	
	for (int i = lo; i < hi; i++)
	{
		int j = i;
		while ((j >= lo) && (countingArray[j] > countingArray[j + 1]))
		{
			int swap = countingArray[j + 1];
			countingArray[j + 1] = countingArray[j];
			countingArray[j] = swap;
			j--;
		}
	}
	return 0;
}

void qsort(int array[], int lo, int hi)
{
	if (lo >= hi)
	{
		return;
	}

	if ((hi - lo) <= 9)
	{
		insertSort(array, lo, hi);
		return;
	}
	
	int firstNumber = array[lo];
	int workingNumber = array[lo];
	int counterLess = lo;
	int counterOver = 0;

	for (int i = lo; i <= hi; i++)
	{
		if (workingNumber < firstNumber)
		{
			int swap = workingNumber;
			workingNumber = array[counterLess + 1];
			array[counterLess] = swap;
			counterLess++;
		}
		else
		{
			int swap = workingNumber;
			workingNumber = array[hi - counterOver];
			array[hi - counterOver] = swap;
			counterOver++;
		}
	}

	qsort(array, lo, counterLess - 1);
	qsort(array, counterLess, hi);
}

bool test()
{
	int checkArray[100]{};
	for (int i = 0; i < 100; i++)
	{
		checkArray[i] = 50 - i;
	}
	qsort(checkArray, 0, 99);
	if (!check(checkArray, 99))
	{
		return false;
	}

	for (int i = 0; i < 100; i++)
	{
		checkArray[i] = 20 - i;
	}
	insertSort(checkArray, 0, 99);
	if (!check(checkArray, 99))
	{
		return false;
	}

	for (int i = 0; i < 25; i++)
	{
		checkArray[i] = 50 - i;
		checkArray[50 - i] = 50 - i;
	}
	qsort(checkArray, 0, 50);
	if (!check(checkArray, 50))
	{
		return false;
	}

	for (int i = 0; i < 25; i++)
	{
		checkArray[i] = 90 - i;
		checkArray[50 - i] = 90 - i;
	}
	insertSort(checkArray, 0, 50);
	if (!check(checkArray, 50))
	{
		return false;
	}

	return true;
}

int main()
{
	if (!test())
	{
		printf("All is very bad!\n");
		return -1;
	}
	printf("Enter size of array, please\n");
	int size = 0;
	scanf("%d", &size);
	
	printf("Enter array, please\n");
	int number[100]{};
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &number[i]);
	}

	qsort(number, 0, size - 1);

	for (int i = 0; i < size; i++)
	{
		printf("in main = %d\n", number[i]);
	}
	return 0;
}
//Найти наиболее часто встречающийся элемент в массиве быстрее, чем за O(n2 ).
//Если таких элементов несколько, надо вывести любой из них.


#include <stdio.h>


int partition(int array[], int lo, int hi)
{
	int pivot = array[hi];
	int i = lo;
	for (int j = lo; j < hi; j++)
	{
		if (array[j] <= pivot)
		{
			int swap = array[i];
			array[i] = array[j];
			array[j] = swap;
			i = i++;
		}
	}
	int swap = array[i];
	array[i] = array[hi];
	array[hi] = swap;
	return i;
}

void sort(int array[], int start, int end)
{
	if (start < end)
	{
		int p = partition(array, start, end);
		sort(array, start, p - 1);
		sort(array, p + 1, end);
	}
}

void search(int array[], int size, int answer[])
{
	for (int i = 1; i < size; i++)
	{
		int help = 1;
		while (array[i] == array[i - 1])
		{
			help++;
			if (answer[0] < help)
			{
				answer[0] = help;
				answer[1] = array[i];
			}
			i++;
		}

	}
}

bool test()
{
	int checkArray[100]{ 10, 50, 30, 0, 9, 4, 15, 10, 6, 0 };
	sort(checkArray, 0, 9);
	for (int i = 1; i < 10; i++)
	{
		if (checkArray[i - 1] > checkArray[i])
		{
			return false;
		}
	}

	int answer[2]{1, checkArray[1]};
	search(checkArray, 10, answer);
	if (answer[0] != 2)
	{
		return false;
	}
	if (answer[1] != 0)
	{
		return false;
	}
	
	
	for (int i = 90; i >= 0; i--)
	{
		checkArray[90 - i] = i;
	}
	checkArray[0] = 0;
	checkArray[10] = 0;
	sort(checkArray, 0, 90);

	for (int i = 1; i < 90; i++)
	{
		if (checkArray[i - 1] > checkArray[i])
		{
			return false;
		}
	}
	search(checkArray, 90, answer);
	if (answer[0] != 3)
	{
		return false;
	}
	if (answer[1] != 0)
	{
		return false;
	}

	for (int i = 0; i <= 50; i = i + 2)
	{
		checkArray[i] = 7;
	}
	sort(checkArray, 0, 90);
	for (int i = 1; i < 90; i++)
	{
		if (checkArray[i - 1] > checkArray[i])
		{
			return false;
		}
	}

	search(checkArray, 90, answer);
	if (answer[0] != 27)
	{
		return false;
	}
	if (answer[1] != 7)
	{
		return false;
	}


	for (int i = 0; i <= 30; i++)
	{
		checkArray[i] = checkArray[i] % 8;
	}
	sort(checkArray, 0, 30);
	for (int i = 1; i <= 30; i++)
	{
		if (checkArray[i - 1] > checkArray[i])
		{
			return false;
		}
	}

	return true;
}

int main()
{
	if (!test())
	{
		return 1;
	}

	printf("Enter size of array, please\n");
	int size = 0;
	scanf("%d", &size);

	printf("Enter array, please\n");
	int array[1000]{};
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &array[i]);
	}

	sort(array, 0, size - 1);

	int answer[2]{1, array[0]};
	search(array, size, answer);

	printf("\n answer = %d \n", answer[1]);

	return 0;
}
// Получить с клавиатуры 2 числа, n и k, сгенерировать случайно массив из n чисел,
//сгенерировать k случайных целых чисел, для каждого из них проверить, содержится
//ли оно в массиве. Надо придумать алгоритм с временной сложностью O(n log n + k log n), или лучший.
//

#include <stdio.h>
#include <stdlib.h>

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

void search(int array[], int size, int numbers[], int quantity, bool answer[])
{
	for (int i = 0; i <= quantity; i++)
	{
		int left = 0;
		int right = size;
		while (left < right - 1)
		{
			int middle = (left + right) / 2;

			if (numbers[i] < array[middle])
			{
				right = middle;
			}
			else if (numbers[i] > array[middle])
			{
				left = middle;
			}
			else
			{
				answer[i] = true;
				break;
				
			}
			if (((left + right) % 2) && (numbers[i] == array[middle + 1]))
			{
				answer[i] = true;
				break;
			}
		}
	}
}

bool test()
{
	int checkArray[100]{ 10, 50, 30, 2, 9, 4, 15, 10, 6, 0 };
	int arrayOfNumbers[100]{ 1, 5, 8, 6, 10 };
	bool answer[100]{};

	sort(checkArray, 0, 9);
	for (int i = 1; i < 10; i++)
	{
		if (checkArray[i - 1] > checkArray[i])
		{
			return false;
		}
	}
	search(checkArray, 9, arrayOfNumbers, 5, answer);
	if (answer[0])
	{
		return false;
	}
	if (answer[1])
	{
		return false;
	}
	if (answer[2])
	{
		return false;
	}
	if (!answer[3])
	{
		return false;
	}
	if (!answer[4])
	{
		return false;
	}
	
	for (int i = 90; i >= 0; i--)
	{
		checkArray[90 - i] = i;
		arrayOfNumbers[i] = i;
	}
	sort(checkArray, 0, 90);
	search(checkArray, 90, arrayOfNumbers, 90, answer);
	for (int i = 1; i < 90; i++)
	{
		if (checkArray[i - 1] > checkArray[i])
		{
			return false;
		}
		if (!(answer[i]))
		{
			return false;
		}
	}

	for (int i = 90; i >= 3; i = i - 2)
	{
		checkArray[90 - i] =  checkArray[i] / i;
	}
	sort(checkArray, 0, 90);
	for (int i = 1; i < 90; i++)
	{
		if (checkArray[i - 1] > checkArray[i])
		{
			return false;
		}
	}

	for (int i = 0; i <= 30; i++)
	{
		checkArray[i] = checkArray[i] % 8;
	}
	sort(checkArray, 0, 30);
	for (int i = 1; i < 30; i++)
	{
		if (checkArray[i - 1] > checkArray[i])
		{
			return false;
		}
	}
	
	for (int i = 0; i < 10; i++)
	{
		checkArray[i] = i;
		arrayOfNumbers[i] = i;
		answer[i] = 0;
	}
	sort(checkArray, 0, 9);
	search(checkArray, 9, arrayOfNumbers, 9, answer);
	for (int i = 1; i < 10; i++)
	{
		if (checkArray[i - 1] > checkArray[i])
		{
			return false;
		}
		if (!(answer[i]))
		{
			return false;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		checkArray[i] = i;
		checkArray[i + 3] = i;
		arrayOfNumbers[i] = i;
		answer[i] = 0;
	}
	sort(checkArray, 0, 5);
	search(checkArray, 5, arrayOfNumbers, 2, answer);
	for (int i = 1; i < 6; i++)
	{
		if (checkArray[i - 1] > checkArray[i])
		{
			return false;
		}
		if (!(answer[i / 2]))
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

	printf("Enter n and k, please\n");
	int n = 0;
	scanf("%d", &n);
	int k = 0;
	scanf("%d", &k);

	int randomArray[1000]{};
	for (int i = 0; i < n; i++)
	{
		randomArray[i] = rand() % 100;
		printf("randomArray = %d\n", randomArray[i]);
	}

	int randomNumbers[1000]{};
	for (int i = 0; i < k; i++)
	{
		randomNumbers[i] = rand() % 100;
	}

	bool answer[1000]{};

	sort(randomArray, 0, n - 1);
	search(randomArray, n - 1, randomNumbers, k - 1, answer);

	for (int i = 0; i < n; i++)
	{
		printf("randomArray = %d\n", randomArray[i]);
	}
	for (int i = 0; i < k; i++)
	{
		printf("randomNumbers = %d answer = %d \n", randomNumbers[i], answer[i]);
	}
	return 0;
}
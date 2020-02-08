// Получить с клавиатуры 2 числа, n и k, сгенерировать случайно массив из n чисел,
//сгенерировать k случайных целых чисел, для каждого из них проверить, содержится
//ли оно в массиве. Надо придумать алгоритм с временной сложностью O(n log n + k log n), или лучший.
//

#include <stdio.h>
#include <stdlib.h>

void sort(int array[], int start, int end)
{
	int low = start;
	int more = end;
	int work = array[start];
	int counting = 0;
	while (low < more)
	{
		if (counting % 2)
		{
			while ((array[low] < work) && (low < more))
			{
				low++;
			}	
		}
		else
		{
			while ((work <= array[more]) && (low < more))
			{
				more--;
			}
		}
		
		int swap = array[low];
		array[low] = array[more];
		array[more] = swap;
		counting++;
	}
	
	if (low - start > 0)
	{
		sort(array, start, low - 1);
	}
	if (more < end)
	{
		sort(array, more + 1, end);
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
	if (answer[0] == 1)
	{
		return false;
	}
	if (answer[1] == 1)
	{
		return false;
	}
	if (answer[2] == 1)
	{
		return false;
	}
	if (answer[3] == 0)
	{
		return false;
	}
	if (answer[4] == 0)
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
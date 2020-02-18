//Переделать задачу 3 из прошлого задания так,
//чтобы сортировка была в отдельном модуле и читала входные данные из файла.

#include "qsort.h"
#include <stdio.h>

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

	int answer[2]{ 1, checkArray[1] };
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

	FILE *file = fopen("Array.txt", "r");
	if (!file)
	{
		printf("file not found!");
		return 1;
	}
	int array[1000]{};
	int size = 0;
	while (!feof(file))
	{
		int* buffer = new int[1000];
		const int readBytes = fscanf(file, "%d", buffer);
		if (readBytes < 0)
		{
			break;
		}
		array[size] = * buffer;
		++size;
		delete[] buffer;
	}
	
	fclose(file);
	
	sort(array, 0, size - 1);

	int answer[2]{ 1, array[0] };
	search(array, size, answer);

	printf("\n answer = %d \n", answer[1]);

	return 0;
}
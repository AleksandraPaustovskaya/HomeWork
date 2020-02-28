//Отсортировать столбцы матрицы по первым элементам

#include <stdio.h>
int sort(int(*array)[50], int rows, int columns)
{
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < columns - i - 1; j++)
		{
			if (array[0][j] > array[0][j + 1])
			{
				for (int k = 0; k < rows; k++)
				{
					int swap = array[k][j];
					array[k][j] = array[k][j + 1];
					array[k][j + 1] = swap;
				}
			}
		}
	}
	return 0;
}

int check(int(*array)[50], int columns)
{
	for (int i = 1; i < columns; i++)
	{
		if (array[0][i] < array[0][i - 1])
		{
			return false;
		}
	}
	return true;
}

bool test()
{
	int checkArray[50][50]{};
	for (int i = 0; i < 10; i++)
	{
		int j = 0;
		do
		{
			checkArray[i][j] = i + j;
			j++;
		} while (j < 11);
	}
	sort(checkArray, 10, 11);
	if (!check(checkArray, 11))
	{
		return false;
	}

	for (int i = 0; i < 50; i++)
	{
		if (i < 25)
		{
			checkArray[i][0] = 99 - i;
		}
		else
		{
			checkArray[i][1] = 99 - i;
		}
	}
	sort(checkArray, 25, 25);
	if (!check(checkArray, 25))
	{
		return false;
	}

	for (int i = 0; i < 25; i++)
	{
		checkArray[i][0] = i - 50;
	}
	sort(checkArray, 20, 50);
	if (!check(checkArray, 50))
	{
		return false;
	}

	for (int i = 0; i < 50; i++)
	{
		checkArray[i][0] = i - 90;
	}
	sort(checkArray, 10, 50);
	if (!check(checkArray, 50))
	{
		return false;
	}

	for (int i = -10; i < 25; i++)
	{
		checkArray[i + 10][0] = i;
	}
	sort(checkArray, 3, 35);
	if (!check(checkArray, 35))
	{
		return false;
	}
	return true;
}

int main()
{
	printf("Hello! Enter the number of rows in the array: ");
	int rows = 0;
	scanf("%d", &rows);
	printf("Enter the number of columns in the array: ");
	int columns = 0;
	scanf("%d", &columns);
	
	if (!test())
	{
		printf("-1");
		return -1;
	}
	else if (rows <= 0 || columns <= 0)
	{
		printf("Incorrect value");
		return -2;
	}

	int array[50][50]{};
	for (int i = 0; i < rows; i++)
	{
		int j = 0;
		do
		{
			scanf("%d", &array[i][j]);
			j++;
		} while (j < columns);
	}
	sort(array, rows, columns);

	printf("\n");
	for (int i = 0; i < rows; i++)
	{
		int j = 0;
		do
		{
			printf("%d ", array[i][j]);
			j++;
		} while (j < columns);
		printf("\n");
	}

	return 0;
}
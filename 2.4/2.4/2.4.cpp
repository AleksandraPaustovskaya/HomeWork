
//Написать программу, которая заполняет массив случайными значениями(с использованием функции rand из stdlib.h),
//потом преобразует его без использования дополнительных массивов так, что в начале массива будут элементы, 
//меньшие первого, а в конце-- - большие либо равные первому.Программа должна работать за линейное время.

#include <stdio.h>
#include <stdlib.h>

void sorting(int countingArray[], int size)
{
	int firstNumber = countingArray[0];
	int workingNumber = countingArray[0];
	int counterLess = 0;
	int counterOver = 0;

	for (int i = 0; i < size; i++)
	{
		if (workingNumber < firstNumber)
		{
			int swap = workingNumber;
			workingNumber = countingArray[counterLess + 1];
			countingArray[counterLess] = swap;
			counterLess++;
		}
		else
		{
			int swap = workingNumber;
			workingNumber = countingArray[(size - 1) - counterOver];
			countingArray[(size - 1) - counterOver] = swap;
			counterOver++;
		}
	}
}

bool test()
{
	int checkArray[100]{10, 50, 30, 2, 9, 4, 15, 10, 6, 0};
	
	sorting(&checkArray[0], 10);
	for (int i = 0; i < 5; i++)
	{
		if (checkArray[i] >= 10)
		{
			return false;
		}
	}

	for (int i = 5; i < 10; i++)
	{
		if (10 > checkArray[i])
		{
			return false;
		}
	}

	checkArray[0] = 50;
	for (int i = 1; i < 100; i++)
	{
		checkArray[i] = 100 - i;
	}
	sorting(&checkArray[0], 100);
	for (int i = 0; i < 49; i++)
	{
		if (checkArray[i] >= 50)
		{
			return false;
		}
	}

	for (int i = 49; i < 100; i++)
	{
		if (50 > checkArray[i])
		{
			return false;
		}
	}

	checkArray[0] = 40;
	for (int i = 1; i < 100; i++)
	{
		checkArray[i] = 100 - i;
	}
	sorting(&checkArray[0], 100);
	for (int i = 0; i < 39; i++)
	{
		if (checkArray[i] >= 40)
		{
			return false;
		}
	}

	for (int i = 39; i < 100; i++)
	{
		if (40 > checkArray[i])
		{
			return false;
		}
	}

	checkArray[0] = 4;
	for (int i = 1; i < 40; i++)
	{
		checkArray[i] = i % 8;
	}
	sorting(&checkArray[0], 40);
	for (int i = 0; i < 19; i++)
	{
		if (checkArray[i] >= 4)
		{
			return false;
		}
	}

	for (int i = 19; i < 40; i++)
	{
		if (4 > checkArray[i])
		{
			return false;
		}
	}

	checkArray[0] = 65;
	for (int i = 1; i < 40; i++)
	{
		checkArray[i] = (i * 13) % 100;
	}
	sorting(&checkArray[0], 40);
	for (int i = 0; i < 25; i++)
	{
		if (checkArray[i] >= 65)
		{
			return false;
		}
	}

	for (int i = 25; i < 40; i++)
	{
		if (65 > checkArray[i])
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
		return false;
	}

	printf("Enter size of array, please\n");
	int size = 0;
	scanf("%d", &size);

	int number[100]{};
	for (int i = 0; i < size; i++)
	{
		number[i] = rand() % 100;
	}

	for (int i = 0; i < size; i++)
	{
		printf(" = %d\n", number[i]);
	}

	sorting(&number[0], size);
	
	for (int i = 0; i < size; i++)
	{
		printf("in main = %d\n", number[i]);
	}
	return 0;
}
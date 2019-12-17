//Написать программу, которая вводит с клавиатуры набор целых чисел
//(в любом порядке, конец — число 0), и выводящую числа из этого набора
//в порядке возрастания и без повторений, с указанием того, сколько каждое
//число раз встретилось в этом наборе.

#include <stdio.h>

int sort(int(*array)[2], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (array[i][0] > array[j][0])
			{
				int swap = array[j][0];
				array[j][0] = array[i][0];
				array[i][0] = swap;
				swap = array[j][1];
				array[j][1] = array[i][1];
				array[i][1] = swap;
			}
			else if (array[j][0] == array[i][0])
			{
				array[i][1] = array[i][1] + array[j][1];
				array[j][1] = array[size - 1][1];
				array[j][0] = array[size - 1][0];
				size--;
			}
		}
	}
	for (int j = 0; j < size; j++)
	{
		printf("%d  %d\n", array[j][0], array[j][1]);
	}
	return 0;
}

int main()
{
	
	int b[1000][2]{};

	int i = 0;
	do
	{
		scanf("%d", &b[i][0]);
		b[i][1] = 1;
		i++;
	} while (b[i - 1][0]);

	sort(b, i - 1);

	return 0;
}
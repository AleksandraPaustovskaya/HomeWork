#include "qsort.h"
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
			i++;
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
// По данному неориентированному графу построить минимальное остовное дерево одним из рассмотренных алгоритмов. 
// В файле задаётся матрица смежности, программа должна вывести на консоль минимальное остовное дерево в каком-либо представлении.
//

#include <stdio.h>
#include "Prim.h"

int main()
{
	FILE* file = fopen("input.txt", "r");
	int size = 0;
	fscanf(file, "%d", &size);

	int** graph = new int* [size];
	for (int i = 0; i < size; ++i)
	{
		graph[i] = new int[size] {};
		for (int j = 0; j < size; ++j)
		{
			fscanf(file, "%d", &graph[i][j]);
		}
	}

	int** tree = createMinimalSpanningTree(graph, size);
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			printf("%d ", tree[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < size; ++i)
	{
		delete[] graph[i];
		delete[] tree[i];
	}
	delete[] graph;
	delete[] tree;
	return 0;
}
// Есть множество городов и дороги, связывающие эти города. Для каждой дороги задана её длина. 
// Задача – распределить города между государствами по такому алгоритму: задаются k столиц каждого государства, 
// далее по очереди каждому государству добавляется ближайший незанятый город, непосредственно связанный дорогой 
// с каким-либо городом, уже принадлежащим государству (столицей или каким-либо городом, добавленным на одном из предыдущих шагов). 
// Процесс продолжается до тех пор, пока все города не будут распределены. Граф дорог связный. Во входном файле: n – число городов и m – число дорог. 
// Далее следуют сами дороги в формате: i j len, i и j – номера городов, len – длина дороги. 
// Далее задано число k – число столиц, далее – k чисел – номера столиц. Надо вывести на консоль номера государств и списки городов, принадлежащих государствам.
//

#include <stdio.h>
#include "list.h"
#include "algoritm.h"

bool test()
{
	const int size = 5;
	int** test = new int* [size];
	for (int i = 0; i < size; ++i)
	{
		test[i] = new int[size] {};
	}

	FILE* file = fopen("test.txt", "r");
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			fscanf(file, "%d", &test[i][j]);
		}
	}
	fclose(file);

	int capitals[2] = { 0, 1 };
	const int numberOfCapitals = 2;

	List** states = new List * [numberOfCapitals];
	for (int i = 0; i < numberOfCapitals; ++i)
	{
		states[i] = createList();
	}

	List* answer1 = createList();
	addValue(answer1, 0);
	addValue(answer1, 2);
	addValue(answer1, 3);
	addValue(answer1, 4);

	List* answer2 = createList();
	addValue(answer2, 1);

	distributeCities(test, size, capitals, numberOfCapitals, states);

	for (int i = 0; i < size; ++i)
	{
		delete[] test[i];
	}
	delete[] test;

	const bool testPassed = compareLists(states[0], answer1) && compareLists(states[1], answer2);

	for (int i = 0; i < numberOfCapitals; ++i)
	{
		deleteList(states[i]);
	}
	delete[] states;
	deleteList(answer1);
	deleteList(answer2);
	return testPassed;
}

int main()
{
	if (!test())
	{
		printf("Testing error\n");
		return 1;
	}

	FILE* file = fopen("input.txt", "r");
	if (!file)
	{
		printf("File not found\n");
		return 1;
	}

	int size = 0;
	fscanf(file, "%d", &size);

	int** graph = new int* [size];
	for (int i = 0; i < size; ++i)
	{
		graph[i] = new int[size] {};
	}

	int numberOfRoads = 0;
	fscanf(file, "%d", &numberOfRoads);

	for (int i = 0; i < numberOfRoads; ++i)
	{
		int firstCityNumber = 0;
		fscanf(file, "%d", &firstCityNumber);
		int secondCityNumber = 0;
		fscanf(file, "%d", &secondCityNumber);
		int length = 0;
		fscanf(file, "%d", &length);
		graph[firstCityNumber][secondCityNumber] = length;
		graph[secondCityNumber][firstCityNumber] = length;
	}

	int numberOfCapitals = 0;
	fscanf(file, "%d", &numberOfCapitals);
	int* capitals = new int[numberOfCapitals];

	List** states = new List * [numberOfCapitals];
	for (int i = 0; i < numberOfCapitals; ++i)
	{
		int capitalNumber = 0;
		fscanf(file, "%d", &capitalNumber);
		capitals[i] = capitalNumber;
		states[i] = createList();
	}
	fclose(file);

	distributeCities(graph, size, capitals, numberOfCapitals, states);

	for (int i = 0; i < size; ++i)
	{
		delete[] graph[i];
	}
	delete[] graph;

	delete[] capitals;

	for (int i = 0; i < numberOfCapitals; ++i)
	{
		printf("Cities of state %d: ", i + 1);
		printList(states[i]);
		printf("\n");
	}

	for (int i = 0; i < numberOfCapitals; ++i)
	{
		deleteList(states[i]);
	}
	delete[] states;
	return 0;
}
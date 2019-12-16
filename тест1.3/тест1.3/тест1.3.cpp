//Дан файл, содержащий в себе целые числа, записанные через пробел. 
//Написать программу, разворачивающую порядок чисел в этом файле 
//(например, если в исходном файле было "10 20 30", в нём же должно оказаться "30 20 10"). 
//Известно, что чисел в файле не более 100.

#include <stdio.h>
#include <string.h>
#include <conio.h>

int change()
{
	FILE* file = fopen("test.txt", "r");


	if (!file) {
		printf("file not found!");
		return 1;
	}
	char* data[100] = {};
	int linesRead = 0;
	while (!feof(file))
	{
		char* buffer = new char[100];
		const int readBytes = fscanf(file, "%s", buffer);
		if (readBytes < 0)
		{
			break;
		}
		data[linesRead] = buffer;
		++linesRead;
	}
	fclose(file);
	getch();

	int size = 0;
	for (int i = 0; i < 100; i++)
	{

		if (!data[i])
		{
			size = i;
			i = 100;
		}
	}

	fopen("test.txt", "w");
	for (int i = size - 1; i >= 0; i--)
	{
		fprintf(file, "%s ", data[i]);
	}
	printf("Done");
	fclose(file);
}

int test()
{
	return true;
}

int main() 
{
	if (!test())
	{
		return 0;
	}
	change();
	return 0;
}
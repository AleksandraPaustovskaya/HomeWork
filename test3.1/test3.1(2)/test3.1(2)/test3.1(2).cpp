//Имеется произвольный текстовый файл. Сгенерируйте другой текстовый файл, содержащий уникальные неповторяющиеся строки из первого файла
//в отсортированном по алфавиту порядке.

#include <stdio.h>

int reader()
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

	fopen("answer.txt", "w");
	
	fclose(file);

	char answer[100]{};
	char counter = 0;
	for (int i = 0; i < linesRead; i++)
	{
		if (!i)
		{
			answer[i] = *data[i];
		}
		bool check = true;
		for (int j = linesRead - 1; j >= i; j--)
		{
			if (!i)
			{
				answer[j] = *data[j];
			}
			if (answer[i] == answer[j])
			{
				check = false;
			}
		}
		if (check)
		{
			fopen("answer.txt", "a");
			fprintf(file, "%c\n", answer[i]);
			fclose(file);

		}
		check = true;
	}
	return 0;
}

int main()
{

	reader();
	return 0;
}

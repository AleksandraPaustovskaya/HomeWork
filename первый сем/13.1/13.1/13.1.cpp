// Реализовать с помощью switch по состоянию лексический анализатор, проверяющий, 
// является ли введённая последовательность символов вещественным числом 
// (вещественное число задаётся регулярным выражением digit+ (. digit+)? (E(+ | -)? digit+)?, где digit - [0..9]).
//

#include <stdio.h>
#include "lexicalAnalyzer.h"
#include "test.h"

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

	char sequence[100] = {};
	fscanf(file, "%s", sequence);
	fclose(file);

	printf(lexicalAnalyzer(sequence) ? "This is a number\n" : "This isn't a number\n");
	return 0;
}
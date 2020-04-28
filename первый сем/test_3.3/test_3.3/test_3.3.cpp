#include <stdio.h>
#include <locale.h>
#include "automat.h"
#include "test.h"

int main()
{
	setlocale(LC_ALL, "Rus");

	if (!test())
	{
		return -1;
	}

	printf("Введите строку\n");
	char string[100]{};
	scanf("%s", string);
	bool answer = finiteAutomaton(string);
	if (answer)
	{
		printf("true");
	}
	else
	{
		printf("false");
	}
}
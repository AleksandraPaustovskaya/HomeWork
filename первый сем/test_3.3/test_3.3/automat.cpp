#include <string.h>
#include <ctype.h>
#include <stdio.h>

bool finiteAutomaton(char* string)
{
	const int length = strlen(string);
	int state = 0;
	for (int i = 0; i < length + 1; i++)
	{
		switch (state)
		{
		case 0:
			if (isalpha(string[i]))
			{
				state = 1;
				break;
			}
			return string[i] == '\0';

		case 1:
			if (isalpha(string[i]))
			{
				state = 1;
				break;
			}
			if (isdigit(string[i]) || string[i] == '_')
			{
				state = 2;
				break;
			}
			return string[i] == '\0';

		case 2:
			if (isalnum(string[i]) || string[i] == '_')
			{
				state = 2;
				break;
			}
			return string[i] == '\0';
		}
	}
}
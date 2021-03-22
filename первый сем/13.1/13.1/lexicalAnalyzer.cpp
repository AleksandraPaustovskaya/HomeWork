#include <string.h>
#include <ctype.h>
#include "lexicalAnalyzer.h"

enum type { entere, check, isNumber, isE, isSign, isNumberAfterSign, isNumberInTheLastCharacters};

type state;

bool lexicalAnalyzer(char* string)
{
	const int length = strlen(string);

	state = entere;

	for (int i = 0; i < length + 1; ++i)
	{
		switch (state)
		{
		case entere:
			if (isdigit(string[i]))
			{
				state = check;
				break;
			}
			return false;

		case check:
			if (isdigit(string[i]))
			{
				state = check;
				break;
			}
			if (string[i] == '.')
			{
				state = isNumber;
				break;
			}
			if (string[i] == 'E')
			{
				state = isSign;
				break;
			}
			return string[i] == '\0';

		case isNumber:
			if (isdigit(string[i]))
			{
				state = isE;
				break;
			}
			return false;

		case isE:
			if (isdigit(string[i]))
			{
				state = isE;
				break;
			}
			if (string[i] == 'E')
			{
				state = isSign;
				break;
			}
			return string[i] == '\0';

		case isSign:
			if (isdigit(string[i]))
			{
				state = isNumberInTheLastCharacters;
				break;
			}
			if (string[i] == '+' || string[i] == '-')
			{
				state = isNumberAfterSign;
				break;
			}
			return false;

		case isNumberAfterSign:
			if (isdigit(string[i]))
			{
				state = isNumberInTheLastCharacters;
				break;
			}
			return false;

		case isNumberInTheLastCharacters:
			if (isdigit(string[i]))
			{
				state = isNumberInTheLastCharacters;
				break;
			}
			return string[i] == '\0';
		}
	}
}
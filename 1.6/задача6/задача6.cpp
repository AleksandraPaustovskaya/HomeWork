#include <stdio.h>
#include <string.h>

int main()
{
	printf("Enter string S, please\n"); 
	char string[100]{};
	fgets(string, 100, stdin);
	string[strlen(string) - 1] = '\0';
	const int lengthOfString = strlen(string);

	printf("Enter string S1, please\n");
	char string1[100]{};
	fgets(string1, 100, stdin);
	string1[strlen(string1) - 1] = '\0';
	const int lengthOfString1 = strlen(string1);

	int counterEntry = 0;
	for (int i = 0; i < lengthOfString; i++)
	{
		char counterSinglEntery = 0;
		for (char counter = 0; counter < lengthOfString1; counter++)
		{
			if (string[i + counter] == string1[counter])
			{
				counterSinglEntery++;
			}
		}
		printf("counter = %d\ndlina =%d\n", counterSinglEntery, lengthOfString1);
		if (counterSinglEntery == lengthOfString1)
		{
			counterEntry++;
		}
	}
	printf("Numbers of entry = %d\n", counterEntry);
	return 0;
}

#include <stdio.h>

int main()
{
	char k = 0;
	int counterHappy[28];

	for (k = 0; k < 28; k++)
	{
		counterHappy[k] = 0;
	}

	int i = 0;
	int halfOfTickets[1000];
	for (i = 0; i < 1000; i++)
	{
		halfOfTickets[i] = i;

		char thousand = 0;
		thousand = halfOfTickets[i] / 100;

		char hundred = 0;
		hundred = halfOfTickets[i] / 10 - thousand * 10;

		char unit = 0;
		unit = halfOfTickets[i] % 10;

		char summa = 0;
		summa = thousand + hundred + unit;
		counterHappy[summa]++;
	}

	int ansver = 0;
	for (k = 0; k < 28; k++)
	{		
		counterHappy[k] = counterHappy[k] * counterHappy[k];
		ansver = ansver + counterHappy[k];
	}

	printf("The number of winning tickets = %d\n", ansver);

//	delete[] counterHappy;
//	delete[] halfOfTickets;
	return 0;
}
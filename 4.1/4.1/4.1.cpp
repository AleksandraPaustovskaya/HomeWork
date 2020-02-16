// Ввести два числа, перевести в двоичное представление в дополнительном коде и напечатать,
//сложить в столбик в двоичном представлении, вывести сумму, перевести в десятичное,
//вывести сумму в десятичном виде. Все сообщения писать по-русски
//(рекомендуется использовать функцию setlocale, чтобы сообщения выводились по-русски и под Windows тоже).

#include <stdio.h>
#include <locale.h>

void translationToBin(int dec, bool bin[])
{
	int counter = 0;
	bool sign = false;
	if (dec < 0)
	{
		dec = 4294967296 + dec;
	}

	while (dec && (counter < 32))
	{
		if (dec & 0b1)
		{
			bin[counter] = true;
		}
		else
		{
			bin[counter] = false;
		}
		
		dec = dec >> 1;
		
		counter++;
	}
}

int translationToDec(bool sumBin[])
{
	int sumDec = 0;
	for (int i = 31; i >= 0; i--)
	{
		sumDec = sumDec | sumBin[i];
		if (i)
		{
			sumDec = sumDec << 1;
		}
	}
	return sumDec;
}

void sum(bool summand1[], bool summand2[], bool sum[])
{
	bool remains = 0;
	for (int i = 0; i < 32; i++)
	{
		sum[i] = (summand1[i] ^ summand2[i] ^ remains) | (summand1[i] & summand2[i] & remains);
		if ((summand1[i] & remains) | (summand2[i] & remains) | (summand1[i] & summand2[i]))
		{
			remains = 1;
		}
		else
		{
			remains = 0;
		}
	}
}

bool test()
{
	bool checkSummandBin1[32]{};
	translationToBin(128, checkSummandBin1);
	for (int i = 0; i < 32; i++)
	{
		if (!(checkSummandBin1[7]))
		{
			return false;
		}
		else if (checkSummandBin1[i] && (i != 7))
		{
			return false;
		}
		checkSummandBin1[i] = true;
	}
	 
	checkSummandBin1[25] = 0;
	if (translationToDec(checkSummandBin1) != -33554433)
	{
		return false;
	}
	
	bool checkSummandBin2[32]{};
	bool sumBin[32]{};
	checkSummandBin2[27] = 1;
	sum(checkSummandBin1, checkSummandBin2, sumBin);
	for (int i = 0; i < 25; i++)
	{
		if (!sumBin[i])
		{
			return false;
		}
	}
	if (sumBin[25])
	{
		return false;
	}
	if (!sumBin[26])
	{
		return false;
	}
	for (int i = 27; i < 32; i++)
	{
		if (sumBin[i])
		{
			return false;
		}
	}
	if (translationToDec(sumBin) != 100663295)
	{
		return false;
	}
	return true;
}

int main()
{
	if (!test())
	{
		return -1;
	}
	setlocale(LC_ALL, "Rus");
    printf ("Введите первое слагаемое: ");
	int summand1 = 0;
	scanf("%d", &summand1);
	
	printf("\nВведите второе слагаемое: ");
	int summand2 = 0;
	scanf("%d", &summand2);
		
	bool summandBin1[32]{};
	translationToBin(summand1, summandBin1);
	printf("\nСумма в двоичном представлении :\n\n ");
	for (int i = 31; i >= 0; i--)
	{
		if (!((i + 1) % 4))
		{
			printf(" ");
		}
		printf("%d", summandBin1[i]);
	}
	
	printf("\n+\n ");

	bool summandBin2[32]{};
	translationToBin(summand2, summandBin2);
	for (int i = 31; i >= 0; i--)
	{
		if (!((i + 1) % 4))
		{
			printf(" ");
		}
		printf("%d", summandBin2[i]);
	}

	bool summaBin[32]{};
	sum(summandBin1, summandBin2, summaBin);
	printf("\n  _______________________________________\n ");
	for (int i = 31; i >= 0; i--)
	{
		if (!((i + 1) % 4))
		{
			printf(" ");
		}
		printf("%d", summaBin[i]);
	}

	int summaDec = translationToDec(summaBin);
	printf("\n\nОтвет в десятичном виде: %d.\n", summaDec);
}
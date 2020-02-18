//Написать программу, которая в диалоговом режиме позволяет осуществлять следующие операции:
//0 - выйти
//1 - добавить значение в заданную позицию в односвязный список
//2 - удалить значение в заданной позиции из списка
//3 - распечатать список
//Позиции задаются целыми числами, 0 соответствует голове списка.


#include <stdio.h>
#include <locale.h>
#include "list.h"


int main()
{
	setlocale(LC_ALL, "Rus");
	List* list = createList();

	while (true)
	{
		printf("\n\nЗдравствуйте, введите номер команды, для выполнения:\n0 - выйти\n1 - добавить значение в заданную позицию в односвязный список\n2 - удалить значение в заданной позиции из списка\n3 - распечатать список\n\n");
		int comand = 0;
		scanf("%d", &comand);
		if (comand == 0)
		{
			//0 - выйти
			break;
		}
		else if (comand == 1)
		{
			//1 - добавить значение в заданную позицию в односвязный список

			printf("Введите значение\n");
			int value;
			scanf("%d", &value);

			printf("Введите позицию эллемента в списке\n");
			int numberAdd = 0;
			scanf("%d", &numberAdd);

			if (listLength(list) < numberAdd)
			{
				return -2;
			}

			addValue(list, value, numberAdd);
		}
		else if (comand == 2)
		{
			//2 - удалить значение в заданной позиции из списка

			printf("Введите позицию эллемента в списке\n");
			int numberDel = 0;
			scanf("%d", &numberDel);

			if (listLength(list) < numberDel)
			{
				return -3;
			}

			deleteValue(list, numberDel);

		}
		else if (comand == 3)
		{
			//3 - распечатать список
			int length = listLength(list);
			int counter = 0;
			while (length - 1 >= counter)
			{
				printf("The list is %d\n", returnValue(list, counter));
				//printf(isSymmetric(list) ? "symmetric\n" : "asymmetric\n");
				counter++;
			}
		}
	}

	deleteList(list);
	return 0;
}
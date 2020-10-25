// Написать программу, которая в диалоговом режиме позволяет осуществлять следующие операции:
//0 – выйти
//1 – добавить значение в сортированный список
//2 – удалить значение из списка
//3 – распечатать список
//Все операции должны сохранять сортированность.Начинаем с пустого списка.

#include <stdio.h>
#include <locale.h>
#include "list.h"
#include "tests.h"

int main()
{
	setlocale(LC_ALL, "Rus");

	if (!test())
	{
		printf("Ошибка в работе программы\n");
		return -1;
	}

	int comand = 1;
	printf("Здравствуйте!");
	List* list = createList();
	while (true)
	{
		printf("\nВведите номер команды, для выполнения:\n");
		printf("0 - выйти\n");
		printf("1 - добавить значение в сортированный список\n");
		printf("2 - удалить значение из списка\n");
		printf("3 - распечатать список\n\n");

		scanf("%d", &comand);
		switch (comand)
		{
			case 0:
			{
				deleteList(list);
				return 0;
			}
			case 1:
			{
				int value = 0;
				printf("Введите значение элемента\n");
				scanf("%d", &value);
				addElement(list, value);
				break;
			}
			case 2:
			{
				int value = 0;
				printf("Введите удаляемое значение\n");
				scanf("%d", &value);
				if (deleteElement(list, value))
				{
					printf("Удаление завершено успешно.\n");
				}
				else
				{
					printf("Данное значение отсутствует!\n");
				}
				break;
			}
			case 3:
			{
				printf("Ваш список:\n");
				printList(list);
				break;
			}

			default:
			{
				break;
			}
		}
	}
}
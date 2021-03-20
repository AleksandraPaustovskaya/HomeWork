// Реализовать словарь с ключами и значениями типа char * на основе АВЛ-дерева. Должны поддерживаться следующие операции.
// Добавить значение по заданному ключу в словарь.Если такой ключ уже есть, значение заменяется на новое.
// Получить значение по заданному ключу из словаря.Если такого ключа нет, возвращается nullptr.
// Проверить наличие заданного ключа.
// Удалить заданный ключ и связанное с ним значение из словаря.Если такого ключа нет, функция ничего не делает.
// Программа должна работать в интерактивном режиме, то есть пользователю должно предоставляться меню, позволяющее выполнить эти операции..
//

#include <stdio.h>
#include <locale.h>
#include "AVLTree.h"
#include "test.h"

int main()
{
	setlocale(LC_ALL, "Rus");

	if (!test())
	{
		printf("Ошибка тестирования\n");
		return 1;
	}

	int command = 0;
	Tree* tree = createTree();
	while (true)
	{
		printf("Введите номер команды, для выполнения:\n");
		printf(" 0 - выход.\n");
		printf(" 1 - Добавить значение (по ключу) в словарь.\n");
		printf(" 2 - Получить значение (по заданному ключу) из словаря.\n");
		printf(" 3 - Проверить наличие заданного ключа в словаре.\n");
		printf(" 4 - Удалить заданный ключ и связанное с ним значение из словаря.\n");

		scanf("%d", &command);
		int key = 0;
		switch (command)
		{
		case 0:
		{
			deleteTree(tree);
			return 0;
		}
		case 1:
		{
			printf("Введите ключ: ");
			scanf("%d", &key);

			printf("Введите значение: ");
			char value[1000] = {};
			scanf("%s", value);

			addValue(tree, key, value);
			break;
		}
		case 2:
		{
			printf("Введите ключ: ");
			scanf("%d", &key);

			char* value = getValue(tree, key);
			if (value != nullptr)
			{
				printf("\nИскомое значение:\n %s\n", value);

			}
			else
			{
				printf("Искомое значение отсутствует!\n");
			}
			delete[] value;
			break;
		}
		case 3:
		{
			printf("Введите ключ\n");
			scanf("%d", &key);

			if (contains(tree, key))
			{
				printf("Данный ключ существует.\n");
				break;
			}
			printf("Данный ключ отсутствует!\n");

			break;
		}
		case 4:
		{
			printf("Введите ключ\n");
			scanf("%d", &key);

			deleteValue(tree, key);
			break;
		}

		default:
		{
			printf("Неправильная команда\n");
			break;
		}
		return 0;
		}
	}
}
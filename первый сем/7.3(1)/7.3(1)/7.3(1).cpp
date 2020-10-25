// Реализовать сортировку слиянием. Во входном файле последовательность записей "имя - номер телефона".
// Программа должна отсортировать эти записи либо по имени, либо по номеру телефона, 
// в зависимости от выбора пользователя, и вывести результат на экран. Количество записей заранее неизвестно,
// так что надо реализовывать списками на указателях.
//

#include <stdio.h>
#include "list.h"
#include "mergeSort.h"
#include "tests.h"

int main()
{
	if (!tests())
	{
		printf(" error");
		return -1;
	}

	FILE* file = fopen("contacts.txt", "r");
	if (!file)
	{
		printf("File not found");
		return 1;
	}

	List* list = createList();
	while (!feof(file))
	{
		char name[1000] = {};
		char number[1000] = {};
		fscanf(file, "%[^-]%*c%*c", name);
		fscanf(file, "%[^\n]%*c", number);
		addContact(list, name, number);
	}
	fclose(file);

	printf("Enter:\n 1 - sort by name\n 2 - sort by number\n");
	int input = 0;
	scanf("%d", &input);
	if (input != 1 && input != 2)
	{
		printf("Invalid input\n");
		deleteList(list);
		return 1;
	}

	List* sortedList = mergeSort(list, input == 1);
	printf("\nSorted entries:\n");
	printList(sortedList);

	deleteList(sortedList);
	return 0;
}
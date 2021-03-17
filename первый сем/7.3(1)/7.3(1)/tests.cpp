
#include <stdio.h>
#include <string.h>
#include "list.h"
#include "mergeSort.h"

bool tests()
{
	List* list = createList();
	char name1[10] = "Misha";
	char phone1[10] = "123456";
	addContact(list, name1, phone1);

	char name2[10] = "Masha";
	char phone2[10] = "698754321";
	addContact(list, name2, phone2);

	char name3[10] = "Nick";
	char phone3[10] = "454621";
	addContact(list, name3, phone3);

	char name4[10] = "Valeri";
	char phone4[10] = "278945632";
	addContact(list, name4, phone4);

	List* sortedList1 = mergeSort(list, true);
	bool testsPassed = checkSort(sortedList1, true);
	
	if (!testsPassed)
	{
		printf("Sort by name");
		deleteList(sortedList1);
		return testsPassed;
	}
	else
	{
		List* sortedList2 = mergeSort(sortedList1, false);
		testsPassed = testsPassed && checkSort(sortedList2, false);
		if (!testsPassed)
		{
			printf("Sort by number");
		}
		deleteList(sortedList2);
		return testsPassed;
	}
}
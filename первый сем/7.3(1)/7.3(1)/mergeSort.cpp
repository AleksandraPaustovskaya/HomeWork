#include <stdio.h>
#include <string.h>
#include "list.h"
#include "mergeSort.h"

void transferElements(List* list1, List* list2, int quantity)
{
	for (int i = 0; i < quantity; ++i)
	{
		addContact(list2, returnNameFromHead(list1), returnNumberFromHead(list1));
		deleteHead(list1);
	}
}

List* merge(List* list1, List* list2, bool sortByName)
{
	List* newList = createList();
	while (listLength(list1) != 0 && listLength(list2) != 0)
	{
		int comparison = 0;
		if (sortByName)
		{
			comparison = strcmp(returnNameFromHead(list1), returnNameFromHead(list2));
		}
		else
		{
			comparison = strcmp(returnNumberFromHead(list1), returnNumberFromHead(list2));
		}
		comparison < 0 ? transferElements(list1, newList, 1) : transferElements(list2, newList, 1);
	}

	if (listLength(list2) == 0)
	{
		transferElements(list1, newList, listLength(list1));
	}
	else
	{
		transferElements(list2, newList, listLength(list2));
	}
	deleteList(list1);
	deleteList(list2);
	return newList;
}

List* mergeSort(List* list, bool sortByName)
{
	const int length = listLength(list);
	if (length <= 1)
	{
		return list;
	}

	List* leftList = createList();
	transferElements(list, leftList, length / 2);
	List* rightList = createList();
	transferElements(list, rightList, length - length / 2);
	deleteList(list);

	leftList = mergeSort(leftList, sortByName);
	rightList = mergeSort(rightList, sortByName);
	return merge(leftList, rightList, sortByName);
}

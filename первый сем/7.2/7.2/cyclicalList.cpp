#include <stdio.h>
#include "cyclicalList.h"
#include "tests.h"

struct ListElement
{
	int value;
	ListElement *next;
};

struct List
{
	ListElement *head = nullptr;
	ListElement* tail = nullptr;
};

List* createList()
{
	return new List;
}

bool isEmpy(List *list)
{
	return list->head == nullptr;
}

bool isOneElement(List* list)
{
	return list->head == list->tail;
}

int head(List* list)
{
	return list->head->value;
}

void addElement(List *list, int value)
{
	if (isEmpy(list))
	{
		list->head = new ListElement{ value, nullptr };
		list->head->next = list->head;
		list->tail = list->head;
	}
	else
	{
		list->tail->next = new ListElement{ value, list->head };
		list->tail = list->tail->next;
	}
}

void deleteElement(List *list, int position)
{
	ListElement* current = list->head;
	ListElement* previous = list->tail;
	for (int i = 1; i < position; i++)
	{
		previous = current;
		current = current->next;
	}

	list->head = current->next;
	list->tail = previous;
	previous->next = current->next;
	delete current;
}

void deleteList(List *list)
{
	while (!isOneElement(list))
	{
		ListElement* temp = list->head->next;
		delete list->head;
		list->head = temp;
	}
	delete list->head;
	delete list;
}
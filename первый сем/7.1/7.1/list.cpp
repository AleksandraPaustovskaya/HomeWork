#include <stdio.h>
#include "list.h"
#include "tests.h"

struct ListElement
{
	int value;
	ListElement *next;
};

struct List
{
	ListElement *head = nullptr;
};

List* createList()
{
	return new List;
}

bool isEmpy(List *list)
{
	return list->head == nullptr;
}

void addElement(List *list, int value)
{
	ListElement* current = list->head;
	ListElement* previous = nullptr;

	while(current != nullptr && value > current->value)
	{
		previous = current;
		current = current->next;
	}

	ListElement* newElement = new ListElement {value, current};
	if (previous == nullptr)
	{
		list->head = newElement;
	}
	else
	{
		previous->next = newElement;
	}
}

bool deleteElement(List *list, int value)
{
	ListElement* current = list->head;
	ListElement* previous = nullptr;
	while (current != nullptr && current->value != value)
	{
		previous = current;
		current = current->next;
	}
	if (current == nullptr)
	{
		return false;
	}
	ListElement* temp = current->next;
	delete current;
	if (previous == nullptr)
	{
		list->head = temp;
	}
	else
	{
		previous->next = temp;
	}
	return true;
}

void printList(List* list)
{
	ListElement* current = list->head;
	while (current != nullptr)
	{
		printf("%d ", current->value);
		current = current->next;
	}
}

void deleteList(List *list)
{
	while (!isEmpy(list))
	{
		ListElement* temp = list->head->next;
		delete list->head;
		list->head = temp;
	}
	delete list;
}

bool checkingTheOrder(List* list)
{
	ListElement* current = list->head->next;
	ListElement* previous = list->head;
	while (current != nullptr)
	{
		if (previous->value > current->value)
		{
			return false;
		}
		previous = current;
		current = current->next;
	}
	return true;
}
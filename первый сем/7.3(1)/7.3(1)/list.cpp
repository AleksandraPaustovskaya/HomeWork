#include <stdio.h>
#include <string.h>
#include "list.h"

struct Contact
{
	char *name = nullptr;
	char *number = nullptr;
	Contact* next = nullptr;
};

struct List
{
	int length = 0;
	Contact *head = nullptr;
	Contact* tail = nullptr;
};

List *createList()
{
	return new List;
}

bool isEmpty(List *list)
{
	return list->head == nullptr;
}

void addContact(List *list, char *name, char *number)
{
	list->length++;
	char *newName = new char[strlen(name) + 1];
	char *newNumber = new char[strlen(number) + 1];
	strcpy(newName, name);
	strcpy(newNumber, number);
	Contact* newContact = new Contact {newName, newNumber, nullptr};

	if (isEmpty(list))
	{
		list->head = newContact;
		list->tail = newContact;
		return;
	}
	list->tail->next = newContact;
	list->tail = list->tail->next;
}

char* returnNameFromHead(List* list)
{
	return list->head->name;
}

char* returnNumberFromHead(List* list)
{
	return list->head->number;
}

int listLength(List* list)
{
	return list->length;
}

void deleteHead(List* list)
{
	if (isEmpty(list))
	{
		return;
	}
	list->length--;
	Contact* temp = list->head->next;
	delete list->head->name;
	delete list->head->number;
	delete list->head;
	list->head = temp;
}

bool checkSort(List* list, bool byName)
{
	if (isEmpty(list))
	{
		return true;
	}
	Contact* current = list->head->next;
	Contact* previous = list->head;
	while (current != nullptr)
	{
		int comparison = 0;
		if (byName)
		{
			comparison = strcmp(current->name, previous->name);
		}
		else
		{
			comparison = strcmp(current->number, previous->number);
		}

		if (comparison < 0)
		{
			return false;
		}
		previous = current;
		current = current->next;
	}
	return true;
}

void printList(List* list)
{
	if (isEmpty(list))
	{
		return;
	}
	Contact* current = list->head;
	while (current != nullptr)
	{
		printf("%s- %s\n", current->name, current->number);
		current = current->next;
	}
}

void deleteList(List* list)
{
	while (!isEmpty(list))
	{
		deleteHead(list);
	}
	delete list;
}
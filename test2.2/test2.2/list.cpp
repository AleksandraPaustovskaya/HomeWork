#include <stdio.h>
#include "list.h"

struct Node
{
	int value;
	Node* next;
};

struct List
{
	Node* head = nullptr;
	Node* tail = nullptr;
	int length = 0;
};

List* createList()
{
	return new List;
}

int listLength(List* list)
{
	return list->length;
}

bool isEmpty(List* list)
{
	return list->head == nullptr;
}

void addValue(List* list, int value, int number)
{
	list->length++;
	if (!isEmpty(list))
	{
		list->tail->next = new Node{ value, nullptr };
		list->tail = list->tail->next;
		return;
	}
	list->head = new Node{ value, list->head };

	Node* element1 = list->head;
	Node* element2 = list->head->next;
	for (int i = 0; i < number; ++i)
	{
		element1 = element1->next;
		element2 = element2->next;
	}
	element1->next = list->head;
	list->head->next = element2;
}

void deleteValue(List* list, int number)
{
	list->length--;
	if (!isEmpty(list))
	{
		list->tail->next = new Node{ value, nullptr };
		list->tail = list->tail->next;
		return;
	}
	list->head = new Node{ value, list->head };

	Node* element1 = list->head;
	Node* element2 = list->head->next;
	for (int i = 0; i < number; ++i)
	{
		element1 = element1->next;
		element2 = element2->next;
	}
	element1->next = list->head;
	list->head->next = element2;
}


int returnValue(List* list, int positionNumber)
{
	Node* current = list->head;
	for (int i = 0; i < positionNumber; ++i)
	{
		current = current->next;
	}
	return current->value;
}

void deleteList(List* list)
{
	while (!isEmpty(list))
	{
		Node* temp = list->head->next;
		delete list->head;
		list->head = temp;
	}
	delete list;
}
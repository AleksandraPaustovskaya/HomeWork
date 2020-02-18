#pragma once

struct Node;

struct List;

List* createList();

int listLength(List* list);

bool isEmpty(List* list);

void addValue(List* list, int value, int number);

void deleteValue(List* list, int number);

int returnValue(List* list, int positionNumber);

void deleteList(List* list);

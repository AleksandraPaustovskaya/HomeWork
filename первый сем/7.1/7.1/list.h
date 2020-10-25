#pragma once

// элемент списка, содержащий значение и ссылку
struct ListElement;

// список
struct List;

// создание списка
List* createList();

// проверка наличия элементов в списке
bool isEmpy(List* list);

// добавление элемента с сохранением в списке возрастающего порядка
void addElement(List* list, int value);

// удаление элемента
bool deleteElement(List* list, int value);

void printList(List* list);

// удаление списка
void deleteList(List* list);

// проверка отсортированности списка
bool checkingTheOrder(List* list);
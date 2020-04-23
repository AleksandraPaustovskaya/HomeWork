#pragma once

// элемент списка, содержащий значение и ссылку
struct ListElement;

// список
struct List;

// создание списка
List* createList();

// проверка наличия элементов в списке
bool isEmpy(List* list);

// проверка на наличе единственного эллемента в списке 
bool isOneElement(List* list);

int head(List* list);

// добавление элемента с сохранением в списке возрастающего порядка
void addElement(List* list, int value);

// удаление элемента
void deleteElement(List* list, int position);

// удаление списка
void deleteList(List* list);
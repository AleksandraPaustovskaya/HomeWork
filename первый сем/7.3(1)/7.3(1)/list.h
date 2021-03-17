#pragma once

// список
struct List;

// создание списка
List* createList();

// добавление элемента (контакта)
// функция принимает указатели на список, имя и номер одного контакта;
void addContact(List* list, char* name, char* number);

// возвращение имени первого контакта
char* returnNameFromHead(List* list);

// возращение номера первого контакта
char* returnNumberFromHead(List* list);

// возвращение длинны списка
int listLength(List* list);

// удаление первого контакта
void deleteHead(List* list);

// проверка сортировки
// функция принимает булевое значение (true - сортировка по имени, false - по номеру);
bool checkSort(List* list, bool byName);

// печать списка
void printList(List* list);

// удаление списка
void deleteList(List* list);
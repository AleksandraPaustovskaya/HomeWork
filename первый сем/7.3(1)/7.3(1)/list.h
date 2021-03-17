#pragma once

// ������
struct List;

// �������� ������
List* createList();

// ���������� �������� (��������)
// ������� ��������� ��������� �� ������, ��� � ����� ������ ��������;
void addContact(List* list, char* name, char* number);

// ����������� ����� ������� ��������
char* returnNameFromHead(List* list);

// ���������� ������ ������� ��������
char* returnNumberFromHead(List* list);

// ����������� ������ ������
int listLength(List* list);

// �������� ������� ��������
void deleteHead(List* list);

// �������� ����������
// ������� ��������� ������� �������� (true - ���������� �� �����, false - �� ������);
bool checkSort(List* list, bool byName);

// ������ ������
void printList(List* list);

// �������� ������
void deleteList(List* list);
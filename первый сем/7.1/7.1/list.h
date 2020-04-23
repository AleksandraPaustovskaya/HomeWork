#pragma once

// ������� ������, ���������� �������� � ������
struct ListElement;

// ������
struct List;

// �������� ������
List* createList();

// �������� ������� ��������� � ������
bool isEmpy(List* list);

// ���������� �������� � ����������� � ������ ������������� �������
void addElement(List* list, int value);

// �������� ��������
bool deleteElement(List* list, int value);

void printList(List* list);

// �������� ������
void deleteList(List* list);

// �������� ����������������� ������
bool checkingTheOrder(List* list);
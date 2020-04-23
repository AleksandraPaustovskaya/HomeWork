#pragma once

// ������� ������, ���������� �������� � ������
struct ListElement;

// ������
struct List;

// �������� ������
List* createList();

// �������� ������� ��������� � ������
bool isEmpy(List* list);

// �������� �� ������ ������������� ��������� � ������ 
bool isOneElement(List* list);

int head(List* list);

// ���������� �������� � ����������� � ������ ������������� �������
void addElement(List* list, int value);

// �������� ��������
void deleteElement(List* list, int position);

// �������� ������
void deleteList(List* list);
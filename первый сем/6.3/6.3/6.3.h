#pragma once
#include "stack.h"

// �������� ������� ����������� ������
bool checkingTheBalanceOfBrackets(char expression[], int counter);

// �������� �������������� ��������
int checkingPriority(char operation);

// ���������� �������� �������
int convertingAnExpression(char expression[], int counter, char answer[]);

int main();
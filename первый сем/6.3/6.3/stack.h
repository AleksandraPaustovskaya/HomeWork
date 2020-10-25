#pragma once

//������� �����, ���������� �������� � ������
struct StackElement;

//����,��������� �� ���������� �����
struct Stack;

//���������� ��������
void push(Stack* stack, char value);

//�������� �������� � ����������� ��� ��������
char pop(Stack* stack);

//�������� �� ������� ��������� �� �����
bool isEmpty(Stack* stack);

//�������� �����
void deleteStack(Stack* stack);

// �������� �����
Stack* createStack();
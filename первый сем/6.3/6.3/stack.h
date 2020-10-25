#pragma once

//Элемент стэка, содержащий значение и ссылку
struct StackElement;

//Стэк,состоящий из эллементов стэка
struct Stack;

//добавление элемента
void push(Stack* stack, char value);

//удаление элемента с возращением его значения
char pop(Stack* stack);

//проверка на наличие элементов на стэке
bool isEmpty(Stack* stack);

//удаление стэка
void deleteStack(Stack* stack);

// создание стэка
Stack* createStack();
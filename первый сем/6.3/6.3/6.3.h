#pragma once
#include "stack.h"

// Проверка условия вложенности скобок
bool checkingTheBalanceOfBrackets(char expression[], int counter);

// Проверка приорететности операций
int checkingPriority(char operation);

// Сортировка входного массива
int convertingAnExpression(char expression[], int counter, char answer[]);

int main();
// Написать программу, преобразующую выражение из инфиксной формы в постфиксную.
// В выражении могут быть знаки +, -, *, /, скобки и цифры. Пример: (1 + 1) * 2 должно преобразовываться в 1 1 + 2 *.
// Алгоритм перевода предлагается найти самостоятельно (алгоритм "сортировочной станции" Э. Дейкстры).

#include <stdio.h>
#include "stack.h"
#include "tests.h"
#include "6.3.h"

bool checkingTheBalanceOfBrackets(char expression[], int counter)
{
	Stack* balanceOfBrackets = createStack();
	for (int i = 0; i < counter; i++)
	{
		if (expression[i] == '(')
		{
			push(balanceOfBrackets, expression[i]);
		}
		else if (expression[i] == ')')
		{
			if (!isEmpty(balanceOfBrackets))
			{
				pop(balanceOfBrackets);
			}
			else
			{
				deleteStack(balanceOfBrackets);
				return false;
			}
		}
	}
	if (!isEmpty(balanceOfBrackets))
	{
		deleteStack(balanceOfBrackets);
		return false;
	}
	deleteStack(balanceOfBrackets);
	return true;
}

int checkingPriority(char operation)
{
	if (operation == '-' || operation == '+')
	{
		return 0;
	}
	if (operation == '*' || operation == '/')
	{
		return 1;
	}
	if (operation == '(')
	{
		return 2;
	}
	else
	{
		return -1;
	}
}

int convertingAnExpression(char expression[], int counter, char answer[])
{
	int value = 0;
	Stack* stack = createStack();
	int counterAnswerArray = 0;
	for (int i = 0; i < counter; i++)
	{
		int priority = checkingPriority(expression[i]);
		if (priority >= 0)
		{
			if (!isEmpty(stack))
			{
				char sign = pop(stack);
				if (checkingPriority(sign) <= priority)
				{
					push(stack, sign);
					push(stack, expression[i]);
				}
				else
				{
					int priorityOfSackElement = checkingPriority(sign);
					while (priorityOfSackElement > priority && priorityOfSackElement < 2)
					{
						if (answer[counterAnswerArray - 1] != ' ')
						{
							answer[counterAnswerArray] = ' ';
							counterAnswerArray++;
						}
						answer[counterAnswerArray] = sign;//выводим оператора в выходной масив
						counterAnswerArray++;
						sign = 0;
						if (!isEmpty(stack))//если не пустой стэк достаем седующего оператора
						{
							sign = pop(stack);
							priorityOfSackElement = checkingPriority(sign);
						}//нужна проверка на пустоту, чтобы знать нужно ли класть эллемент обратно
						else
						{
							break;
						}
					}
					if (sign != '0')//если стек не был пустым кладем последний взятый опреатор
					{
						push(stack, sign);// кладем текущий эллемент входного массива
					}
					push(stack, expression[i]);
				}
			}
			else push(stack, expression[i]);
		}
		else if (expression[i] == ')')
		{
			char sign = pop(stack);
			while (sign != '(')
			{
				if (answer[counterAnswerArray - 1] != ' ')
				{
					answer[counterAnswerArray] = ' ';
					counterAnswerArray++;
				}
				answer[counterAnswerArray] = sign;//выводим в выходной массив эллемент
				counterAnswerArray++;
				sign = pop(stack);
			}
		}
		else if ((expression[i] == ' ' && answer[counterAnswerArray - 1] != ' ') || expression[i] != ' ')
		{
			answer[counterAnswerArray] = expression[i];//выводим эллемент в выходной массив
			counterAnswerArray++;
		}
	}

	while (!isEmpty(stack))// если стэк не пуст поkа не окажется пустым выкидываем эллементы в выход
	{
		char element = pop(stack);
		answer[counterAnswerArray] = ' ';
		counterAnswerArray++;
		answer[counterAnswerArray] = element;
		counterAnswerArray++;
	}
	deleteStack(stack);

	return counterAnswerArray;
}

int main()
{
	if (!test())
	{
		printf("Test failed!\n");
		return 1;
	}
	char expression[100]{};
	printf("Enter the expression, please\n\n");
	int counter = 0;
	char sign = 0;
	while (sign != '\n')
	{
		scanf("%c", &sign);
		expression[counter] = sign;
		counter++;
	}
	if (expression[0] == '\n')
	{
		printf("incorrect expression\n");
		return -1;
	}
	if (!checkingTheBalanceOfBrackets(expression, counter - 1))
	{
		printf("incorrect expression\n");
		return -1;
	}
	char answer[100]{};
	convertingAnExpression(expression, counter - 1, answer);

	for (int i = 0; i < counter; i++)
	{
		printf("%c", answer[i]);
	}

	return 0;
}
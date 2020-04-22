//Задачи 1, 2 и 3 решаются с помощью стека - его надо реализовать единожды в отдельном модуле,
//и использовать во всех этих задачах.Комментарии ко всем функциям из заголовочного файла обязательны.

#include "stack.h"
#include "tests.h"

struct StackElement
{
	char value;
	StackElement *next;
};

struct Stack
{
	StackElement *first = nullptr;
};

void push(Stack *stack, char value)
{
	stack->first = new StackElement {value, stack->first};
}

char pop(Stack* stack)
{
	if (!isEmpty(stack))
	{
		char value = stack->first->value;
		StackElement* NewFirstElement = stack->first->next;
		delete stack->first;
		stack->first = NewFirstElement;
		return value;
	}
	return 0;
}

bool isEmpty(Stack* stack)
{
	return stack->first == nullptr;
}

void deleteStack(Stack* stack)
{
	while (!isEmpty(stack))
	{
		pop(stack);
	}
	delete stack;
}

Stack *createStack()
{
	return new Stack;
}
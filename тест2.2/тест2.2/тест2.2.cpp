// тест2.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <stdio.h>

struct StackElement
{
	int value;
	StackElement* next;
};

void push(int value, StackElement** head)
{
	StackElement* element = new StackElement{ value, *head };
	*head = element;
}

int pop(StackElement** head)
{
	int headValue = (*head)->value;
	StackElement* help = (*head)->next;
	delete* head;
	*head = help;
	return headValue;
}

int getNth(StackElement** head, int n)
{
	int counter = 0;
	while (counter < n && *head)
	{
		*head = (*head)->next;
		counter++;
	}
	int headValue = (*head)->value;
	return headValue;
}

struct StackElement* swap(struct StackElement* lst1, struct StackElement* lst2, struct StackElement* head)
{
	struct StackElement* prev1, * prev2, * next1, * next2;
	prev1 = head;
	prev2 = head;
	if (prev1 == lst1)
	{
		prev1 = NULL;
	}
	else
	{
		while (prev1->next != lst1)
		{
			prev1 = prev1->next;
		}
	}
	if (prev2 == lst2)
	{
		prev2 = NULL;
	}
	else
	{
		while (prev2->next != lst2)
		{
			prev2 = prev2->next;
		}
	}
	next1 = lst1->next;
	next2 = lst2->next;
	if (lst2 == next1)
	{
		lst2->next = lst1;
		lst1->next = next2;
		if (lst1 != head)
		{
			prev1->next = lst2;
		}
	}
	else if (lst1 == next2)
	{
		lst1->next = lst2;
		lst2->next = next1;
		if (lst2 != head)
		{
			prev2->next = lst2;
		}
	}
	else
	{
		if (lst1 != head)
		{
			prev1->next = lst2;
		}
		lst2->next = next1;
		if (lst2 != head)
		{
			prev2->next = lst1;
		}
			lst1->next = next2;
	}
	if (lst1 == head)
	{
		return lst2;
	}
	if (lst2 == head)
	{
		return lst1;
	}
	return head;
}

bool isEmpty(StackElement* head)
{
	return head == nullptr;
}

int main()
{
	StackElement* head = nullptr;

	printf("Enter a size of list\n");
	int size = 0;
	scanf("%d", &size);
	
	printf("Enter the list\n");
	for (int i = 0; i < size; i++)
	{
		int element;
		scanf("%d", &element);
		push(element, &head);
	}
		
	printf("Enter n\n");
	int n = 0;
	scanf("%d", &n);
	printf("n == %d\n", getNth(&head, n));

	for (int i = 0; i < (size / 2); i++)
	{ 
		swap(i, size - i, &head);
		int value = pop(&head);
		printf("%d\n", value);
		//printf("isEmpty == %d\n", isEmpty(head));
	}
	return 0;
}
#include <stdio.h>
#include "list.h"
#include "tests.h"

bool testList()
{
	List* test = createList();
	if (!isEmpy(test))
	{
		deleteList(test);
		printf("error creating a list\n");
		return false;
	}
	addElement(test, 10);
	if (isEmpy(test))
	{
		deleteList(test);
		printf("error add element to list\n");
		return false;
	}
	if (deleteElement(test, 11))
	{
		printf("error delete element\n");
		deleteList(test);
		return false;
	}
	if (!deleteElement(test, 10))
	{
		printf("error delete element\n");
		deleteList(test);
		return false;
	}
	if (!isEmpy(test))
	{
		deleteList(test);
		printf("error working a list\n");
		return false;
	}

	addElement(test, 1);
	addElement(test, 100);
	addElement(test, 10);
	if (!checkingTheOrder(test))
	{
		deleteList(test);
		printf("error in the order of list items\n");
		return false;
	}
	addElement(test, 50);
	addElement(test, 50);
	addElement(test, 101);
	if (!checkingTheOrder(test))
	{
		deleteList(test);
		printf("error in the order of list items\n");
		return false;
	}
	if (!deleteElement(test, 50))
	{
		printf("error delete element\n");
		deleteList(test);
		return false;
	}
	if (!deleteElement(test, 50))
	{
		printf("error delete element\n");
		deleteList(test);
		return false;
	}
	if (deleteElement(test, 50))
	{
		printf("error delete element\n");
		deleteList(test);
		return false;
	}
	deleteList(test);
	return true;
}

bool test()
{
	return testList();
}
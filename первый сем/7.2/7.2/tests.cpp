#include <stdio.h>
#include "cyclicalList.h"
#include "7.2.h"

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
	addElement(test, 11);

	deleteElement(test, 11);

	if (head(test) != 11)
	{
		printf("error delete element\n");
		deleteList(test);
		return false;
	}
	
	if (isEmpy(test))
	{
		deleteList(test);
		printf("error working a list\n");
		return false;
	}
	
	addElement(test, 1);
	addElement(test, 100);
	addElement(test, 10);
	deleteElement(test, 14);
	if (head(test)!= 100)
	{
		deleteList(test);
		printf("error delete element\n");
		return false;
	}
	addElement(test, 50);
	addElement(test, 50);
	addElement(test, 101);
	deleteElement(test, 23);

	if (head(test) != 101)
	{
		deleteList(test);
		printf("error delete element\n");
		return false;
	}
	deleteList(test);
	return true;
}

bool testCalculation()
{
	if (calculation(5, 10) != 4)
	{
		printf("error working calculations\n");
		return false;
	}

	if (calculation(10, 3) != 4)
	{
		printf("error working calculations\n");
		return false;
	}

	if (calculation(41, 3) != 31)
	{
		printf("error working calculations\n");
		return false;
	}

	if (calculation(7, 2) != 7)
	{
		printf("error working calculations\n");
		return false;
	}
	return true;
}

bool test()
{
	return testList() && testCalculation();
}
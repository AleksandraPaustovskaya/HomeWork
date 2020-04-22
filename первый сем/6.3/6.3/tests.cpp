#include <stdio.h>
#include "stack.h"
#include "tests.h"
#include "6.3.h"

bool testStack()
{
	Stack* test = createStack();
	if (!isEmpty)
	{
		deleteStack(test);
		printf("error creating a stack\n");
		return false;
	}
	push(test, '=');
	if (pop(test) != '=')
	{
		printf("error working a stack\n");
		deleteStack(test);
		return false;
	}
	if (!isEmpty)
	{
		deleteStack(test);
		printf("error working a stack\n");
		return false;
	}

	push(test, '(');
	push(test, '-');
	push(test, '+');
	if ((pop(test) != '+') && (pop(test) != '-'))
	{
		deleteStack(test);
		printf("error working a stack\n");
		return false;
	}

	if (isEmpty(test))
	{
		deleteStack(test);
		printf("error working a stack\n");
		return false;
	}

	deleteStack(test);
	return true;
}

bool testCheckingTheBalanceOfBrackets()
{
	char expression[16] = "1 + 3 / (1 + 3)";
	if (!checkingTheBalanceOfBrackets(expression, 15))
	{
		return false;
	}
	
	expression[14] = ' ';
	if (checkingTheBalanceOfBrackets(expression, 14))
	{
		return false;
	}
	
	expression[14] = ')';
	expression[8] = '0';
	if (checkingTheBalanceOfBrackets(expression, 15))
	{
		return false;
	}

	expression[8] = '(';
	expression[4] = '(';
	if (checkingTheBalanceOfBrackets(expression, 15))
	{
		return false;
	}

	expression[4] = ')';
	if (checkingTheBalanceOfBrackets(expression, 15))
	{
		return false;
	}
	return true;
}

bool testCheckingPriority()
{
	if (checkingPriority('+') != 0)
	{
		return false;
	}

	if (checkingPriority('-') != 0)
	{
		return false;
	}

	if (checkingPriority('5') != -1)
	{
		return false;
	}

	if (checkingPriority('(') != 2)
	{
		return false;
	}

	if (checkingPriority('/') != 1)
	{
		return false;
	}

	return true;
}

bool testConvertingAnExpression()
{
	char testArray0[50] = { "4 + 5 * 7" };
	char answer0[50] = { "4 5 7 * +" };
	char answerArray[50]{};
	bool check = false;
	convertingAnExpression(testArray0, 9, answerArray);
	if (answerArray != answer0)
	{
		return false;
	}
	char testArray1[50] = {(4 + 5) * 8 + 7 / 5};
	char answer1[50] = { "4 5 + * 8 7 5 / +" };
	convertingAnExpression(testArray1, 19, answerArray);
	if (answerArray != answer1)
	{
		return false;
	}
	char testArray2[50] = { "9 - 6 * (1 + 2)" };
	char answer2[50] = { "9 6 - 1 2 + *" };
	convertingAnExpression(testArray2, 14, answerArray);
	if (answerArray != answer2)
	{
		return false;
	}

	return true;
}

bool test()
{
	return testStack() && testCheckingTheBalanceOfBrackets() && testCheckingPriority()/*testConvertingAnExpression()*/;
}
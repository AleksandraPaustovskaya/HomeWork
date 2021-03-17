#include <stdio.h>
#include "tree.h"

bool check(char* string, int answer)
{
	Tree* tree = build(string);
	const bool testPassed = calculate(tree) == answer;
	deleteTree(tree);
	return testPassed;
}

bool test()
{
	char string1[] = "* (+ 47 38) (- 6 63)";
	const int answer1 = -4845;

	char string2[] = "(- (* 13 (- 82 51))(/ (* (+ 17 219) 8) 4))";
	const int answer2 = -69;
	const int wrongAnswer = 1;

	return check(string1, answer1) && check(string2, answer2) && !check(string2, wrongAnswer);
}
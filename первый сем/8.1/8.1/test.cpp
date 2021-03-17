#include "tree.h"

bool test()
{

	Tree* tree = createTree();
	char value[5] = "QWER";
	bool test = !contains(tree, 1);

	addValue(tree, 10, value);
	addValue(tree, 3, value);
	addValue(tree, 20, value);
	addValue(tree, 41, value);
	addValue(tree, 5, value);
	addValue(tree, 82, value);
	addValue(tree, 2, value);
	addValue(tree, 7, value);

	test = test && contains(tree, 20) && !contains(tree, 4);
	deleteValue(tree, 10);
	deleteValue(tree, 3);
	deleteValue(tree, 20);
	deleteValue(tree, 41);
	test = test && !contains(tree, 20) && !contains(tree, 10) && contains(tree, 5);

	deleteTree(tree);
	return test;
}
// С помощью ДКА с явной таблицей состояний, заданной в файле,
//  вывести на консоль все комментарии С++ вида /* комментарий */ из входного файла (вместе с символами "/* */").
//

#include <stdio.h>
#include <string.h>
#include "searchComments.h"

bool test()
{
	char fileName[] = "test.txt";
	char answer[] = "/*ads/*dsf***/\n/*qwe/*/\n";
	return strcmp(comments(fileName), answer) == 0;
}

int main()
{
	if (!test())
	{
		printf("Testing error\n");
		return 1;
	}

	char fileName[] = "input.txt";
	printf("Comments from file:\n%s", comments(fileName));
	return 0;
}
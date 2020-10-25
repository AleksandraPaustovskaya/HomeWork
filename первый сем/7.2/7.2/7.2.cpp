//"Считалочка" – отряд из 41-го сикария, защищавший галилейскую крепость Массада,
// не пожелал сдаваться в плен блокировавшим его превосходящим силам римлян.
// Сикарии стали в круг и договорились, что каждые два воина будут убивать третьего,
// пока не погибнут все. Самоубийство – тяжкий грех, но тот, кто в конце концов останется последним,
// должен будет его совершить. Иосиф Флавий, командовавший этим отрядом, якобы быстро рассчитал,
// где нужно стать ему и его другу, чтобы остаться последними, но не для того, чтобы убить друг друга,
// а чтобы сдать крепость римлянам. В нашем случае участвует n воинов и убивают каждого m-го.
// Требуется определить номер k начальной позиции воина, который должен будет остаться последним. 
// Считать с помощью циклического списка.

#include <stdio.h>
#include "cyclicalList.h"
#include "tests.h"

int calculation(int numberOfWarriors, int frequency)
{
	List* list = createList();
	for (int i = 1; i <= numberOfWarriors; i++)
	{
		addElement(list, i);
	}
	
	while (!isOneElement(list))
	{
		deleteElement(list, frequency);
	}

	int answer = head(list);
	deleteList(list);
	return answer;
}

int main()
{
	if (!test())
	{
		printf("error");
		return -1;
	}
	printf("Enter the number of warriors\n");
	int numberOfWarriors = 0;
	scanf("%d", &numberOfWarriors);

	printf("enter the frequency\n");
	int frequency = 0;
	scanf("%d", &frequency);

	printf("\nanswer: %d\n", calculation(numberOfWarriors, frequency));
}

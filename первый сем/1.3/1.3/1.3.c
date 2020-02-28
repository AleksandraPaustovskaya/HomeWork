#include <stdio.h>

void reverse(int list[], int left, int right)
{
	for (int i = 0; i < (right - left + 1) / 2; i++)
	{
		int tmp = list[left + i];
		list[left + i] = list[right - i];
		list[right - i] = tmp;
	}
}

int main()
{
	const int m = 0;
	const int n = 0;
	printf("vvedite m \n");
	scanf("%d", &m);
	printf("vvedite n \n");
	scanf("%d", &n);
	int* numbers = new int[m + n]{};
	for (int i = 0; i < m + n; ++i)
	{
		printf("vvedite massiv\n");
		scanf("%d", &numbers[i]);
	}
	reverse(numbers, 0, m - 1);
	reverse(numbers, m, m + n - 1);
	reverse(numbers, 0, m + n - 1);
	for (int i = 0; i < m + n; ++i)
	{
		printf("%d", numbers[i]);
	}
	return 0;
}
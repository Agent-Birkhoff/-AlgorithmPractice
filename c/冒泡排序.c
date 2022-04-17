#include<stdio.h>

void BubbleSort(int num[]);

int main(void)
{
	int num[5];
	int n;
	for (n = 0; n < 5; n++)
		scanf("%d", &num[n]);
	BubbleSort(num);
	for (n = 0; n < 5; n++)
		printf("%d ", num[n]);
	return 0;
}

void BubbleSort(int num[])
{
	int n;
	int i;
	for (i = 4; i > 0; i--)
	{
		for (n = 0; n < i; n++)
		{
			if (num[n] > num[n + 1])
			{
				int temp = num[n];
				num[n] = num[n + 1];
				num[n + 1] = temp;
			}
		}
	}
}

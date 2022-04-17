#include<stdio.h>

int main(void)
{
	int n;
	int num[1000];
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}
	int count = 0;
	for (i = 0; i < n - 1; i++)
	{
		int j;
		for (j = i + 1; j < n; j++)
		{
			if (num[i] - num[j] == 1 || num[i] - num[j] == -1)
				count++;
		}
	}
	printf("%d", count);
	return 0;
}

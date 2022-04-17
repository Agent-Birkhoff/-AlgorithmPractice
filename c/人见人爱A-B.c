#include<stdio.h>

int main(void)
{
	int n, m, is_null = 1;
	int a[100][2];
	int b[100];
	int i;
	for (i = 0; i < 100; i++)
	{
		a[i][0] = 0;
		a[i][1] = 0;
		b[i] = 0;
	}
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i][0]);
		a[i][1] = 1;
	}
	for (i = 0; i < m; i++)
	{
		scanf("%d", &b[i]);
		int j;
		for (j = 0; j < n; j++)
		{
			if (a[j][1] != 1)
				continue;
			if (b[i] == a[j][0])
				a[j][1] = 0;
		}
	}
	int j;
	for (i = n - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (a[j][0] > a[j + 1][0])
			{
				int temp = a[j][0];
				a[j][0] = a[j + 1][0];
				a[j + 1][0] = temp;
				temp = a[j][1];
				a[j][1] = a[j + 1][1];
				a[j + 1][1] = temp;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		if (a[i][1] == 1)
		{
			is_null = 0;
			break;
		}
	}
	if (is_null == 1)
		printf("NULL");
	else
	{
		for (i = 0; i < n; i++)
		{
			if (a[i][1] == 1)
				printf("%d ", a[i][0]);
		}
	}
	return 0;
}

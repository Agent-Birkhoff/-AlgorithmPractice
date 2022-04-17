#include<stdio.h>

int main(void)
{
	int num[1000][2];
	int i;
	for (i = 0; i < 1000; i++)
	{
		num[i][0] = 0;
		num[i][1] = 1;
	}
	int n = 1;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &num[i][0]);
	for (i = 0; i < n; i++)
	{
		if (num[i][1] == 0)
			continue;
		int j;
		for (j = i + 1; j < n; j++)
		{
			if (num[i][0] == num[j][0])
			{
				num[i][1]++;
				num[j][1] = 0;
			}
		}
	}
	for (i = n - 1; i > 0; i--)
	{
		int j;
		for (j = 0; j < i; j++)
		{
			if (num[j][1] < num[j + 1][1])
			{
				int temp = num[j][1];
				num[j][1] = num[j + 1][1];
				num[j + 1][1] = temp;
				temp = num[j][0];
				num[j][0] = num[j + 1][0];
				num[j + 1][0] = temp;
			}
		}
	}
	for (i = n - 1; i > 0; i--)
	{
		int j;
		for (j = 0; j < i; j++)
		{
			if (num[j][1] == num[j + 1][1] && num[j][0] > num[j + 1][0])
			{
				int temp = num[j][0];
				num[j][0] = num[j + 1][0];
				num[j + 1][0] = temp;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		if (num[i][1] != 0)
			printf("%d %d\n", num[i][0], num[i][1]);
	}
	return 0;
}

#include<stdio.h>

int check(int num[6][6], int n, int x, int y);

int main(void)
{
	int n = 1;
	int a[6][6];
	printf("Input n:");
	scanf("%d", &n);
	printf("Input array:\n");
	int x;
	for (x = 0; x < n; x++)
	{
		int y;
		for (y = 0; y < n; y++)
			scanf("%d", &a[x][y]);
	}
	for (x = 0; x < n; x++)
	{
		int y;
		for (y = 0; y < n; y++)
		{
			if (check(a, n, x, y) == 1)
			{
				printf("a[%d][%d]=%d\n", x, y, a[x][y]);
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
}

int check(int num[6][6], int n, int x, int y)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (num[x][y] < num[x][i])
			return 0;
	}
	for (i = 0; i < n; i++)
	{
		if (num[x][y] > num[i][y])
			return 0;
	}
	return 1;
}

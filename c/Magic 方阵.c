#include<stdio.h>

int main(void)
{
	int N;
	int x, y;
	int num[9][9];//最大9*9
	scanf("%d", &N);
	x = 1;
	y = (N + 1) / 2;
	num[x - 1][y - 1] = 1;//第一行正中

	int n;
	for (n = 2; n <= N * N; n++)
	{
		if ((n - 1) % N == 0)
		{
			x += 1;
			num[x - 1][y - 1] = n;
		}
		else
		{
			x -= 1;
			y += 1;
			if (x < 1)
				x = N;
			if (y > N)
				y = 1;
			num[x - 1][y - 1] = n;
		}
	}
	for (x = 0; x < N; x++)
	{
		for (y = 0; y < N; y++)
		{
			printf("%4d", num[x][y]);
		}
		printf("\n\n");
	}
	return 0;
}

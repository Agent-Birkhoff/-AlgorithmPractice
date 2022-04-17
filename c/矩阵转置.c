#include<stdio.h>

int main(void)
{
	int num[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};
	int x, y;
	for (x = 0; x < 3; x++)
		for (y = 0; y < 3; y++)
		{
			scanf("%d", &num[x][y]);
		}
	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			printf("%d ", num[y][x]);
		}
		printf("\n\n");
	}
	return 0;
}

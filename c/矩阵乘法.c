#include<stdio.h>

int main(void)
{
	int a1, a2, b1, b2;
	int a[10][10], b[10][10], result[10][10];
	int x, y;
	for (x = 0; x < 10; x++)
		for (y = 0; y < 10; y++)
			result[x][y] = 0;

	scanf("%d", &a1);
	scanf("%d", &a2);
	scanf("%d", &b1);
	scanf("%d", &b2);
	for (x = 0; x < a1; x++)
		for (y = 0; y < a2; y++)
			scanf("%d", &a[x][y]);
	for (x = 0; x < b1; x++)
		for (y = 0; y < b2; y++)
			scanf("%d", &b[x][y]);
	for (x = 0; x < a1; x++)
		for (y = 0; y < b2; y++)
		{
			int c;
			for (c = 0; c < a2; c++)
				result[x][y] += a[x][c] * b[c][y];
		}
	for (x = 0; x < a1; x++)
	{
		for (y = 0; y < b2; y++)
			printf("%d ", result[x][y]);
		printf("\n");
	}
	return 0;
}

#include<stdio.h>

int check(int num);

int main(void)
{
	int m, n, count = 0;
	scanf("%d %d", &m, &n);
	int a;
	for (a = m; a <= n; a++)
	{
		if (check(a) == 1&&a!=1)
		{
			if (count >= 6) {
				printf("\n");
				count = 0;
			}
			printf("%4d", a);
			count++;
		}
	}
	return 0;
}

int check(int num)
{
	int n;
	for (n = 2; n < num; n++)
	{
		if (num % n == 0)
			return 0;
	}
	return 1;
}

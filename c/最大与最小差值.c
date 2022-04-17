#include<stdio.h>

int abs2(int a, int b)
{
	if(a-b>=0)
		return a - b;
	if(a-b<0)
		return b - a;
	return 0;
}

int main(void)
{
	int n = 2;
	int num[1000];

	scanf("%d", &n);

	int a;
	for (a = 0; a < n; a++)
	{
		num[a] = 0;
	}

	for (a = 0; a < n; a++)
	{
		scanf("%d", &num[a]);
	}

	int min = abs2(num[0],num[1]);
	int max = min;
	for (a = 0; a < n; a++)
	{
		int i;
		for (i = 0; i < n; i++)
		{
			if (a == i)
				continue;
			if (abs2(num[a],num[i]) < min)
				min = abs2(num[a],num[i]);
			if (abs2(num[a],num[i]) > max)
				max = abs2(num[a],num[i]);
		}
	}

	printf("%d %d", max, min);
	return 0;
}

#include<stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);
	int num[10];
	int i;
	for (i = 0; i < 10; i++)
		num[i] = i + 1;
	int remain = 10, n = 0, count = 0;
	while (remain > 0)
	{
		if (num[n] != 0)
			count++;
		if (count == N)
		{
			printf("%4d", num[n]);
			count = 0;
			remain--;
			num[n] = 0;
		}
		if (n == 9)
			n = 0;
		else
			n++;
	}
	return 0;
}

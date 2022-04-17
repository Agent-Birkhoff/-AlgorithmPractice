#include<stdio.h>

int main(void)
{
	int num[10], average = 0;
	int n;
	for (n = 0; n < 10; n++)
	{
		scanf("%d", &num[n]);
		average += num[n];
	}
	average /= 10;
	for (n = 0; n < 10; n++)
	{
		if (num[n] > average)
			printf("%4d", num[n]);
	}
	printf("\n");
	for (n = 0; n < 10; n++)
	{
		if (num[n] < average)
			printf("%4d", num[n]);
	}
	return 0;
}

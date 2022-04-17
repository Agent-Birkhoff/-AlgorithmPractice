#include<stdio.h>

int main(void)
{
	int num[10] = { 0,12, 14, 18, 20, 26, 28, 30, 32, 38 };
	int input;
	scanf("%d", &input);
	num[0] = input;
	int n;
	for (n = 1; n < 10; n++)
	{
		if (input > num[n])
		{
			num[n - 1] = num[n];
			num[n] = input;
		}
	}
	for (n = 0; n < 10; n++)
		printf("%2d\t", num[n]);
	return 0;
}

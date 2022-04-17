#include<stdio.h>

int check(int arg);

int main()
{
	int N, number, sum = 0;
	scanf("%d", &N);
	int i = 0;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &number);
		if (check(number) == 1)
			sum++;
	}
	printf("%d\n",sum);
	return 0;
}

int check(int arg)
{
	while (arg % 2 == 0)
		arg /= 2;
	while (arg % 3 == 0)
		arg /= 3;
	while (arg % 5 == 0)
		arg /= 5;
	while (arg % 7 == 0)
		arg /= 7;
	if (arg == 1)
		return 1;
	else
		return 0;
}

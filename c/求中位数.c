#include<stdio.h>

void BubbleSort(int num[], int n);

int main(void)
{
	int n, count = 0;
	float middle;
	int num[50];
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++)
		scanf("%d", &num[i]);
	BubbleSort(num, n);
	if (n % 2 == 0)
		middle = (num[n / 2 - 1] + num[n / 2]) / 2.0;
	else
		middle = num[(n - 1) / 2];
	printf("%.1f\n", middle);
	for (i = 0; i < n; i++)
	{
		if (num[i] > middle)
			count++;
	}
	printf("%d", count);
	return 0;
}

void BubbleSort(int num[], int n)
{
	int i, j;
	for (i = n - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (num[j] > num[j + 1])
			{
				int temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
		}
	}
}

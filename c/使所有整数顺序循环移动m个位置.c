#include<stdio.h>

int main(void)
{
	int n, m;
	int num[1000];
	printf("Input n,m:");
	scanf("%d %d", &n, &m);
	int i;
	for (i = 0; i < n; i++)
		scanf("%d", &num[i]);
	for (i = 1; i <= m; i++)
	{
		int j;
		for (j = n - 1; j > 0; j--)
		{
			int temp = num[j - 1];
			num[j - 1] = num[j];
			num[j] = temp;
		}
	}
	printf("After move:");
	for (i = 0; i < n; i++)
		printf("%5d", num[i]);
	return 0;
}

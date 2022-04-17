#include<stdio.h>

int main()
{
	int n;
	double sum = 0;
	printf("Enter n: ");
	scanf("%d", &n);
	int a;
	for (a=1;a<=2*n-1;a=a+2)
	{
		sum = sum + 1.0/a;
	}
	printf("sum=%.6f",sum);
	return 0;
}

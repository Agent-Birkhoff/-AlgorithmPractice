#include<stdio.h>

void sort(double a[10]);

int main(void)
{
	double a[10];
	int n;
	for (n = 0; n < 10; n++)
		scanf("%lf", &a[n]);
	sort(a);

	FILE* fp;
	fp = fopen("a.txt", "w");
	for (n = 0; n < 10; n++)
		fprintf(fp, "%.2lf ", a[n]);
	fclose(fp);

	fp = fopen("a.txt", "r");
	for (n = 0; n < 10; n++)
		fscanf(fp, "%lf", &a[n]);
	fclose(fp);

	for (n = 0; n < 10; n++)
		printf("%.2lf ", a[n]);
	return 0;
}

void sort(double a[10])
{
	int n;
	for (n = 9; n > 0; n--)
	{
		int i;
		for (i = 0; i < n; i++)
		{
			if (a[i] > a[i + 1])
			{
				double temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
		}
	}
}

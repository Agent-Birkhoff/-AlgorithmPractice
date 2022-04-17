#include<stdio.h>

int days_of_year(int y)
{
	if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
		return 366;
	else
		return 365;
}

int days_of_month(int y, int m)
{
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		return 31;
	if (m == 4 || m == 6 || m == 9 || m == 11)
		return 30;
	if (m == 2)
	{
		if (days_of_year(y) == 366)
			return 29;
		else
			return 28;
	}
	return 0;
}

int calculate(int y)
{
	int days = 0;

	int i, j, n;
	for (i = 1900; i < y; i++)
		days = days + days_of_year(i);
	for (j = 1; j < 5; j++)
		days = days + days_of_month(y, j);

	for (n = 8; n <= 14; n++)
	{
		if ((days+n)%7==0)
			return n;
	}
	return 0;
}

int main(void)
{
	int start, end;
	scanf("%d %d", &start, &end);
	int s;
	for (s = start; s <= end; s++)
	{
		printf("%d 5 %d\n",s,calculate(s));
	}
	return 0;
}

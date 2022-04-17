#include<stdio.h>

void stringNx(char* a);

int main(void)
{
	char a[1000] = { 0 };
	scanf("%s", a);
	stringNx(a);
	return 0;
}

void stringNx(char* a)
{
	a += 999;
	int n;
	for (n = 999; n >= 0; n--)
	{
		if (*a != '\0')
			printf("%c", *a);
		a--;
	}
}

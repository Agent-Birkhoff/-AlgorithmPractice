#include<stdio.h>
#include<string.h>

void stringNx(char* a);

int main(void)
{
	char input[1000];
	scanf("%[^\n]", input);
	stringNx(input);
	return 0;
}

void stringNx(char* a)
{
	int length = strlen(a);
	a += length - 1;
	int i;
	for (i = 0; i < length; i++)
	{
		printf("%c", *a);
		a--;
	}
}

#include<stdio.h>
#include<string.h>

int count(char string[], char character);

int main(void)
{
	char input[1000];
	char character;
	scanf("%[^\n]", input);
	getchar();
	scanf("%c", &character);
	printf("%d\n", count(input, character));
	return 0;
}

int count(char string[], char character)
{
	int count = 0;
	int length = strlen(string);
	int i;
	for (i = 0; i < length; i++)
	{
		if (string[i] == character)
			count++;
	}
	return count;
}

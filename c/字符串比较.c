#include<stdio.h>

int strcmp(char* str1, char* str2);

int main(void)
{
	char string1[1000];
	char string2[1000];
	scanf("%[^\n]", string1);
	getchar();
	scanf("%[^\n]", string2);
	printf("%d", strcmp(string1, string2));
	return 0;
}

int strcmp(char* str1, char* str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 != *str2)
		{
			if (*str2 < *str1)//ÒìÒé
				return 1;
			else if (*str1 < *str2)//ÒìÒé
				return -1;
		}
		str1++;
		str2++;
	}
	return 0;
}

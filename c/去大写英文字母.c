#include<stdio.h>
#include<string.h>

int main(void)
{
	char input[1000];
	int length;
	scanf("%[^\n]", input);
	length = strlen(input);
	char* p = input;
	int i = 0;
	while (i < length)
	{
		if (*p >= 65 && *p <= 90)
			*p = 0;
		//if (*p == ' ')//ȥ���ո�
		//	*p = 0;//ȥ���ո�
		i++;
		p++;
	}
	for (i = 0; i < length; i++)
	{
		if (input[i] != 0)
			printf("%c", input[i]);
	}
	return 0;
}

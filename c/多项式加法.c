#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void plus_polunome(char string[], int length);

long int polunome[1001];

int main(void)
{
	char string[1000];
	char string2[1000];

	int i;
	for (i = 0; i < 1001; i++)
		polunome[i] = 0;

	scanf("%s", string);
	scanf("%s", string2);
	int length = strlen(string);
	int length2 = strlen(string2);

	plus_polunome(string, length);
	plus_polunome(string2, length2);

	int is_first = 1;
	for (i = 0; i < 1001; i++)
	{
		if (polunome[i] == 0)
			continue;
		else
		{
			if (i == 0)
			{
				printf("%ld", polunome[i]);
				is_first = 0;
			}
			else if (i == 1)
			{
				if (polunome[i] > 0 && is_first != 1)
					printf("+");
				printf("%ldx", polunome[i]);
				is_first = 0;
			}
			else
			{
				if (polunome[i] > 0 && is_first != 1)
					printf("+");
				printf("%ldx^%d", polunome[i], i);
				is_first = 0;
			}
		}
	}
	if (is_first == 1)
		printf("0");
	return 0;
}

void plus_polunome(char string[], int length)
{
	char num[10];
	int count = 0, i, k;
	for (k = 0; k < 10; k++)
		num[k] = '\0';
	int sign = 1;
	long int coefficient = 0;
	int index = 0;
	for (i = 0; i < length; i++)
	{
		if (string[i] >= '0' && string[i] <= '9')
			num[count++] = string[i];
		else
		{
			if (coefficient == 0)
				coefficient = atol(num) * sign;
			for (k = 0; k < 10; k++)
				num[k] = '\0';
			count = 0;
			switch (string[i])
			{
			case 'x':
				if (string[i + 1] != '^' && i + 1 < length)
				{
					index = 1;
					if (i == 0)
						coefficient = 1;
					else if (string[i - 1] == '-')
						coefficient = -1;
				}
				else if (i + 1 == length)
					index = 1;
				else
				{
					i++;
					for (k = 1; k <= 4; k++)
					{
						if (string[i + k] >= '0' && string[i + k] <= '9')
							num[count++] = string[i + k];
						else
							break;
					}
					index = atol(num);
					for (k = 0; k < 10; k++)
						num[k] = '\0';
					i += count;
					count = 0;
				}
				break;
			case '^':
				break;
			case '+':
				sign = 1;
				polunome[index] += coefficient;
				coefficient = 0;
				index = 0;
				break;
			case '-':
				sign = -1;
				polunome[index] += coefficient;
				coefficient = 0;
				index = 0;
				break;
			}
		}
	}
	polunome[index] += coefficient;
}

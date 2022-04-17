#include<stdio.h>

int main(void)
{
	int input, units, tens, hundreds;
	scanf("%d", &input);
	units = input % 10;
	tens = input / 10 % 10;
	hundreds = input / 100;
	printf("%d %d %d\n", units, tens, hundreds);
	return 0;
}

#include <stdio.h>
 
int main() {
	int i1, i2;
	int useless = scanf("%d %d",&i1,&i2);
	printf("%d\n",i1+i2);
	return useless;
}

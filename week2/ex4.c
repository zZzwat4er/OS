#include <stdio.h>
#include <string.h>

void swap(int *a,int *b);

int main(void){
	char str [256];
	int a, b;
	printf("%s","enter 2 integers a and b:\n");
	scanf("%[^\n]", str);

	sscanf(str, "%d%d", &a, &b);
	printf("%s","before swap:\n");
	printf("a = %d\nb = %d\n", a, b);
	swap(&a,&b);
	printf("%s","after swap:\n");
	printf("a = %d\nb = %d\n", a, b);

	return 0;
}

void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
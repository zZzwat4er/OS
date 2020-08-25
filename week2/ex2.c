#include <stdio.h>
#include <string.h>

int main(void){

	char str [100];
	printf("%s","enter some string:\n");
	scanf("%s", str);

	printf("%s","reverse version of given string:\n");
	for(int i = strlen(str) - 1; i >= 0; i--){
		printf("%c",str[i]);
	}

	printf("\n");

	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(void){
   
   	char str[] = "Hello";
   	
	char *buf;
   
	setvbuf(stdout, buf, _IOLBF, 5);


   	for(int i = 0; i < sizeof(str); i++){
   		printf("%c", str[i]);
   		sleep(1);
   	}
   	printf("\n");

   	return 0;
}
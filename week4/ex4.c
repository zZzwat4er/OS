#include <stdio.h> 
#include<string.h>
#include<sys/types.h>
#include<unistd.h>

int main(void){
    char cmd[256];
    while(1){
    	printf(">>");
    	fgets(cmd, 256, stdin);
    	system(cmd);
	}
    return 0; 
}
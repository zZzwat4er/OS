#include <stdio.h> 
#include<string.h>
#include<sys/types.h>
#include<unistd.h>

int main(void){
    char cmd[256];
    while(1){
    	printf(">>");
    	scanf("%s", cmd);
    	system(cmd);
	}
    return 0; 
}
#include <stdio.h> 
#include<string.h>
#include<sys/types.h>

int main(void){
    pid_t pid = fork();
    //the output show "PID - <some number>" if it is a parent and showen number is an addres of parent function
    //the output show "PID - 0" if it is a child and 0 means tha child procces was creaated and can be executed
    if(pid > 0){
        printf("Hello from parent[PID - %d]\n", pid);
    }
    else{
        printf("Hello from child[PID - %d]\n", pid);
    }
    return 0; 
}
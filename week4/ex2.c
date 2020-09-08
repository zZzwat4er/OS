#include <stdio.h> 
#include<string.h>
#include<sys/types.h>
#include<unistd.h>

int main(void){
    // it well create 2^n proces since it copy all program with it current state and each proces well create 2 more proces
    //untill for loop won't end
    for(int i = 0; i < 5; i++){
        fork();
    }

    sleep(5);

    return 0; 
}
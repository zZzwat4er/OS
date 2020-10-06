#include<stdio.h>
#include <sys/time.h>
#include<sys/resource.h>
#include<stdlib.h> 
#include<string.h>
#include<sys/types.h>
#include<unistd.h>

int main(void){
   struct rusage ru;
   int mem;
	int** arr = malloc(sizeof(int*)*10);
   	for(int i = 0; i < 10; i++){
   		arr[i] = malloc(1024*1024*10);
   		memset(arr[i], 0, 1024*1024*10);

         mem = getrusage(RUSAGE_SELF, &ru);
         printf("ru_maxrss= %d\n", ru.ru_maxrss);

         sleep(1);
   	}
   	for(int i = 0; i < 10; i++){
   		free(arr[i]);
   	}

   	free(arr);
    return 0; 
}
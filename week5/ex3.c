#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

#define BUFFER_SIZE 100

void *producer(void *arg);
void *consumer(void *arg);
int itemCount = 0;
int isProdSleep = 0;
int isConsSleep = 0;

int main(void){
	pthread_t tidp[2];
	time_t start = time(0);
	
	pthread_create(&tidp[0], NULL, &producer, NULL);
	pthread_create(&tidp[1], NULL, &consumer, NULL);
	
	int missCounter = 0;
	while(1){
		printf("isProdSleep -> %d, isConsSleep -> %d\n", isProdSleep, isConsSleep);
		if(isProdSleep == 1 && isConsSleep == 1) missCounter++;
		else missCounter = 0;
		if(missCounter > 10) {
			printf("%f\n",difftime( time(0), start));
			return 1;
		}
	} 
	/*
	this program gose to deadlock after few milliseconds because when produser should sleep 
	customer trying to wokeup him and he do it befor produser gose sleep
	and since produser sleep after customer's wakeup signal when customer gose sleep we have deadlock
	because of produser and customer are bouth sleeping
	*/
	return 0;
}



void *producer(void *arg) {
    while (1) 
    {
    	if(isProdSleep == 0){
        	if (itemCount == BUFFER_SIZE) isProdSleep = 1;
        	itemCount ++;
        	if (itemCount == 1) isConsSleep = 0;
    	}
    }
}

void *consumer(void *arg){
    while (1) 
    {
    	if(isConsSleep == 0){
    	    if (itemCount == 0) isConsSleep = 1;
   	        itemCount --;
    	    if (itemCount == BUFFER_SIZE - 1) isProdSleep = 0;
    	}
    }
}



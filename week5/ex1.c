#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void * tFunc(void *arg);




pthread_t *tidp;
int n, order;// order var shows which thread should execute now
//without order varrible threads allways switch between each outher and because of that 
//order of massages was incorrecr
//but right now order varrible force threads be executed in order

int main(void){
	// input number of treads
	char str [256];
	order = 0;
	printf("%s","enter number of threads: ");
	scanf("%s", str);
	sscanf(str, "%d", &n);
	tidp = malloc(sizeof(pthread_t*) * n);// allocate mem for array of threads addresses 
	for(int i = 0; i < n; i++){
		pthread_create(&tidp[i], NULL, &tFunc, NULL);
		
	}
	pthread_exit(NULL);
	return 0;
}

void * tFunc(void *arg){
	pthread_t id = pthread_self();
	while(1){
		if(pthread_equal(id,tidp[order])) {
			printf("thread %d sucsessfuly created!\n", order + 1);
			printf("this is some text for thread %d\n", order + 1);
			printf("thread %d exits\n", order + 1);
			order++;
			break;
		}
	}

}
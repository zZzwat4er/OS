#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	int n;
	int *arr;
	printf("%s","enter the array size: ");
	scanf("%d", &n);
	arr = malloc(sizeof(int) * n);
	for(int i = 0; i < n; i++){
		arr[i] = i;
	}
	for(int i = 0; i < n; i++) printf("%d ", arr[i]);
	printf("\n");
	free(arr);
	return 0;
}
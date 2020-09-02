#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#define ARRAYSIZE 20

void bubble_sort(int *a, int n);
void swap(int* a, int* b);

int main(void){
    int *a;
    int n;
    char str[256]; 

    srand(time(NULL));

    printf("enter an array size (it well fill in randomly)\n");

    scanf("%s", str);
    sscanf(str, "%d", &n);

    a = malloc(sizeof(int [n]));

    printf("initial array\n");
    for(int i = 0; i < n; i++){ 
        a[i] = rand() % 100;
        printf("%d ", a[i]);
    }
    printf("\nsorted array\n");
    bubble_sort(a, n);

    for(int i = 0; i < n; i++){ 
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0; 
}

void bubble_sort(int *a, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(a[j] > a[j+1]) swap(&a[j], &a[j+1]);
        }
    }
}

void swap(int* a, int* b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}
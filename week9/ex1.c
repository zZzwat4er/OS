#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define INT_FIRST_BIT 1073741824

void sort(int *arr1, int *arr2, int n){
   for(int i = 0; i < n; i++){
      for(int j = i; j < n; j++){
         if(arr1[i] > arr1[j]){
            int temp[2];
            temp[0] = arr1[i];
            temp[1] = arr2[i];
            arr1[i] = arr1[j];
            arr2[i] = arr2[j];
            arr1[j] = temp[0];
            arr2[j] = temp[1];
         }
      }
   }
}

int main(void){
   double HIT = 0;
   double MISS = 1;
   int count = 0;
   int n;
   FILE *f;
   int * page;
   int * age;
   char buff[1024*1024];
   printf("%s","enter the page count: ");
   scanf("%d", &n);
   page = calloc(n, sizeof(int));
   age = calloc(n, sizeof(int));
   for(int i = 0; i < n; i++){
      page[i] = -1;
      age[i] = 0;
   }
   f = fopen("./input.txt", "r");
   fgets(buff, 1024*1024, f);
   int tempInt = 0;
   char temp[16];
   int tempCounter = 0;
   for(int i = 0; i < sizeof(buff); i++){
      if(buff[i] == '\n') break;
      if(buff[i] == ' '){

         // debuging output
         // count++;
         // printf("current pages status: %d", page[0]);
         // for(int j = 1; j < n; j++){
         //    printf(" %d", page[j]);
         // }
         // printf("\n");
         // printf("current age status: %d", age[0]);
         // for(int j = 1; j < n; j++){
         //    printf(" %d", age[j]);
         // }
         // printf("\n");

         // printf("temp = : %s\n", temp);

         tempCounter = 0;
         sscanf(temp, "%d", &tempInt);
         int flag = 0;
         for(int j = 0; j < n; j++){
            age[j] /= 2;
            if(page[j] == tempInt){
               age[j] += INT_FIRST_BIT;
               flag = 1;
               HIT++;

            }
            if(j == n-1 && flag == 0){
               sort(age, page, n);
               page[0] = tempInt;
               age[0] = INT_FIRST_BIT;
               MISS++;
            }
         }
         for(int j = 0; j < 16; j++) temp[j] = 'a';
      }
      else{
         temp[tempCounter] = buff[i];
         tempCounter++;
      }
   
   }
   printf("hit = %f\n", HIT);
   printf("miss = %f\n", MISS);

   if(MISS != 0) printf("hit/miss = %f\n", HIT/MISS);

   fclose(f);

   return 0;
}
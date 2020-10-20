#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int main(void){
   DIR *dir; 
   dir = opendir(".");
   int counter = 0;
   if(dir == NULL) return 1;
   struct dirent **dp;
   dp = calloc(256, sizeof(struct dirent *));
   while(1){
      dp[counter] = readdir(dir);
      if(dp[counter] == NULL) break;
      counter++;
   }
   int *n = calloc(counter, sizeof(int));
   int *flag = calloc(counter, sizeof(int));

   for(int i =0; i < counter; i++){
      for(int j = 0; j < counter; j++){
         if(n[j] == 0) {
            n[j] = dp[i]->d_ino;
            break;
         }
         if(n[j] == dp[i]->d_ino){
            flag[j] = 1;
            break;
         }

      }
   }

   FILE *file = fopen("./ex4.txt", "w");

   for(int i =0; i < counter; i++){
      if(flag[i] == 1){
         fprintf(file,"i - %d\t- ", n[i]);
         for(int j = 0; j < counter; j++){
            if(n[i] == dp[j]->d_ino) fprintf(file,"%s, ", dp[j]->d_name);
         }
         fprintf(file, "\n");
      }
   }
   closedir(dir);
   fclose(file);

   return 0;
}
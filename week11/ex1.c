#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void){
   
   char *str = "This is a nice day";

   size_t size = strlen(str);

   FILE *file = fopen("./ex1.txt", "w");
   ftruncate(fileno(file), size);
   fclose(file);

   int fd = open("./ex1.txt", O_RDWR);

   char *map = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

   for(int i = 0; i <= size; i++){
      map[i] = str[i];
   }

   return 0;
}
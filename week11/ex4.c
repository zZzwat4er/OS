#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void){
   int fd1 = open("./ex1.txt", O_RDWR);
   FILE *file2 = fopen("./ex1.memcpy.txt", "w");
   
   struct stat s;
   fstat(fd1, &s);
   size_t size = s.st_size;
   ftruncate(fileno(file2), size);
   
   fclose(file2);

   int fd2 = open("./ex1.memcpy.txt", O_RDWR);
   char *map1 = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd1, 0);
   char *map2 = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd2, 0);

   memcpy(map2, map1, size);

   return 0;
}

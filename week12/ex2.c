#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>


#define BUF_SIZE 10240

// in this code some parts from copy.c are used
// this code copy all info from "/proc/spuinfo" to spesified files and stdout
// also it supports "-a" option
// sh script call this this sctipt twise (second time with pregenerated file with some info in it)

int main(int argc, char *argv[]){
    char buf[BUF_SIZE];
    int numRead;
    int inputFd;
    int filePerms, openFlags;
    int shift = 1;

    if(argc > 1){
    	if (strcmp(argv[1],"-a") == 0) shift++;
    }

    int outFd[argc - shift];
	inputFd = open("/proc/cpuinfo", O_RDONLY);

	openFlags = O_CREAT | O_WRONLY;
	if(shift == 2) openFlags |= O_APPEND; 
    filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
                S_IROTH | S_IWOTH;      /* rw-rw-rw- */
    
    for(int i = shift; i < argc; i++){
    	outFd[i - shift] = open(argv[i], openFlags, filePerms);
    }

    while((numRead = read(inputFd, buf, BUF_SIZE)) > 0){
    	for(int i = 0; i < argc - shift; i++){
    		write(outFd[i], buf, numRead);
    	}
    	write(0, buf, numRead);
    }

    close(inputFd);
    for(int i = 0; i < argc - shift; i++){
    	close(outFd[i]);
    }


    return 0; 
}
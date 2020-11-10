#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


#define BUF_SIZE 512
#define RES_AMOUNT 3
#define PROC_AMOUNT 5
//macro that used several times in a program
#define PARSE(x) \
    fgets(buf, BUF_SIZE, finput); \
    x = parseString(buf, resAmount)


//in order to run this program on data set with different res/proc amount
// you need to provide arguments in form
// ./out1 <res_amount> <proc_amount>

//parse string of integers to array of integers
//with given amount of integers
int * parseString(char* buff, int arrLen){
    int * arr = calloc(arrLen, sizeof(int));
    int intCounter = 0;
    char temp[16];
    int tempCounter = 0;
    for(int i = 0; i < BUF_SIZE; i++){
        if(buff[i] == '\n') break;
        if(buff[i] == ' '){
            tempCounter = 0;
            sscanf(temp, "%d", &arr[intCounter]);
            intCounter++;
            if(intCounter == arrLen) return arr;
            for(int j = 0; j < 16; j++) temp[j] = 'a';
        }
        else{
            temp[tempCounter] = buff[i];
            tempCounter++;
        }
   }
   if(intCounter != arrLen) sscanf(temp, "%d", &arr[intCounter]);
   return arr;
}


int main(int argc, char* argv[]){
    char buf[BUF_SIZE];
    char temp[16];
    int resAmount = RES_AMOUNT;
    int procAmount = PROC_AMOUNT;

    FILE * finput; 
    FILE * foutput;
    //getting arguments if provided
    if(argc == 3){
        sscanf(argv[1], "%d", &resAmount);
        sscanf(argv[2], "%d", &procAmount);
    }
    

    int * E;
    int * A;
    int * isExecuted = calloc(procAmount, sizeof(int));


    int ** curAlloc;
    int ** reqvest;

    curAlloc = calloc(procAmount, sizeof(int*));
    reqvest = calloc(procAmount, sizeof(int*));

	finput = fopen("./input.txt", "r");
    foutput = fopen("./output.txt", "w");

    //see macro at the beginning
    PARSE(E);
    PARSE(A);
    //skip empty line
    fgets(buf, BUF_SIZE, finput);

    for(int i = 0; i < procAmount; i++){
        PARSE(curAlloc[i]);
    }
    //skip enpty line
    fgets(buf, BUF_SIZE, finput);

    for(int i = 0; i < procAmount; i++){
        PARSE(reqvest[i]);
    }
    
    while(1){
        int flag = 0;
        for(int i = 0; i < procAmount; i++){
            int innerFlag = 0;
            if(isExecuted[i] != 1){
                for(int j = 0; j < resAmount; j++){
                    if(!(reqvest[i][j] <= A[j])) innerFlag = 1;
                }
            }
            if(innerFlag == 0 && isExecuted[i] != 1){
                isExecuted[i] = 1;
                flag = 1;
                for(int j = 0; j < resAmount; j++){
                    A[j] += curAlloc[i][j];
                }
            }
        }
        //break if no proc terminated during iteration
        if(flag != 1) break;
    }

    for(int i = 0; i < procAmount; i++){
        //if there is proc that was not terminated
        //put a massage to output file and exit
        if(isExecuted[i] == 0){
            fputs("processes: \n", foutput);
            for(; i < procAmount; i++){
                if(isExecuted[i] == 0) fprintf(foutput, "%d ", i);
            }
            fputs("\nare deadlocked", foutput);
            fclose(finput);
            fclose(foutput);
            return 0;
        }
    }
    fputs("all processes terminated", foutput);

    fclose(finput);
    fclose(foutput);


    return 0; 
}
// [proc][res type]
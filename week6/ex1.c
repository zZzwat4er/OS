#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(int *arr1, int *arr2, int *index, int n){
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			if(arr1[i] > arr1[j]){
				int temp[3];
				temp[0] = arr1[i];
				temp[1] = arr2[i];
				temp[2] = index[i];
				arr1[i] = arr1[j];
				arr2[i] = arr2[j];
				index[i] = index[j];
				arr1[j] = temp[0];
				arr2[j] = temp[1];
				index[j] = temp[2];
			}
		}
	}
}


void FCFS(int *AT, int *BT, int n);


int systemTime = 0;
int *CT;
int *TAT;
int *WT;

/*
CT - Completion time
TAT - Turn around time
WT - Waiting time
AT - arrival time
BT - burst time
index - process number
Q - quantum
FCFS - first come, first served
SJF - shortest job first

FCFS is a simple alhoritm whith have average results but also it have some problems 
SJF actualy it is an extended FCFS alhoritm it works a little bit beter but not much
round_robin is an anouther aproutch to solve schedluer problen and it can be beter then others alhoritms presented here 
when quantum is big anough to handle process in one iteration 
and it deals with operations slovwer whem it took more then one iteration per precess


COMPARISONS:
dataset:
1 - (0,1)
2 - (0,2)
3 - (0,4)
4 - (0,6)
5 - (0,8)
6 - (11,8)
7 - (11,6)
8 - (11,4)
9 - (11,2)
10 - (11,1)

FCFS - Average TAT: 17.600000	Average WT: 13.400000
SJF - Average TAT: 12.100000	Average WT: 7.900000
round_robin(Q = 3) - Average TAT: 20.600000	Average WT: 16.400000
round_robin(Q = 6) - Average TAT: 19.200000	Average WT: 15.000000
round_robin(Q = 8) - Average TAT: 17.600000	Average WT: 13.400000
*/

int main(void){
	int n;
	int *AT;
	int *BT;
	int *index;
	printf("%s","enter number of process: ");
	scanf("%d", &n);
	AT = malloc(sizeof(int) * n);
	BT = malloc(sizeof(int) * n);
	CT = malloc(sizeof(int) * n);
	TAT = malloc(sizeof(int) * n);
	WT = malloc(sizeof(int) * n);
	index = malloc(sizeof(int) * n);
	for(int i = 0; i < n; i++){
		printf("%s%d %s\n","enter data for process ", i + 1, "using space as a seporaitor");
		scanf("%d %d", &AT[i], &BT[i]); 
		index[i] = i + 1;
	}

	sort(AT, BT, index, n);

	FCFS(AT, BT, n);

	printf("%s\t%s\t%s\t%s\t%s\t%s\n","process" , "AT", "BT", "CT", "TAT", "WT");
	double total_WT = 0;
	double total_TAT = 0;
	for(int i = 0; i < n; i++){
		total_WT += WT[i];
		total_TAT += TAT[i];
		printf("%d\t%d\t%d\t%d\t%d\t%d\n", index[i], AT[i], TAT[i] - WT[i], CT[i], TAT[i], WT[i]);
	}

	printf("Average TAT: %f\tAverage WT: %f\n", total_TAT/n, total_WT/n);


	return 0;
}

void FCFS(int *AT, int *BT, int n){
	while(1){
		int breackCondition = 0;
		for(int i = 0; i < n; i++){
			if(BT[i] != 0){
				if(systemTime < AT[i]) systemTime = AT[i];
				systemTime += BT[i];
				TAT[i] = WT[i] + BT[i];
				CT[i] = systemTime;
				BT[i] = 0;
				for(int j = 0; j < n; j++){
					if(AT[j] <= systemTime && BT[j] != 0) WT[j] = systemTime - AT[j];
				}
				break;
			}
			if(i == n-1){
				breackCondition = 1;
				break;
			}
		}
		if(breackCondition == 1){
			break;
		}
	}
}
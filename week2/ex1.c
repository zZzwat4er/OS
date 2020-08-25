#include <stdio.h>
#include <limits.h>
#include <float.h>


int main(void){

	int a = INT_MAX; 
	float b = FLT_MAX;
	double c = DBL_MAX;


	printf("Size of a = %lu\nSize of b = %lu\nSize of c = %lu\n", sizeof(a), sizeof(b), sizeof(c));
	printf("INT_MAX = %d\nFLOAT_MAX = %f\nDOUBLE_MAX = %f\n", a, b, c);


	return 0;
}
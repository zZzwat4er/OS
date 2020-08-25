#include <stdio.h>
#include <string.h>

void drawAShape(int mod, int n);

int main(void){
	char str [256];
	int mod, n;

	printf("%s","enter shape\n0) right-side-up triangle\n1) right triangle\n2) side triangle\n3) square\n");

	scanf("%s", str);
	sscanf(str, "%d", &mod);
	printf("%s","enter n:");
	scanf("%s", str);
	sscanf(str, "%d", &n);
	drawAShape(mod, n);

	return 0;
}

void drawAShape(int mod, int n){

	switch(mod){
		case 0:
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n - i; j++){
					printf(" "); 
				}
				for(int j = 0; j <= i * 2; j++){
					printf("*");
				}
				printf("\n");
			}
			break;
		case 1:
			for(int i = 0; i < n; i++){
				for(int j = 0; j < i + 1; j++){
					printf("*");
				}
				printf("\n");
			}
			break;
		case 2:
			for(int i = 0; i < n; i++){
				if(i < n / 2)
					for(int j = 0; j < i + 1; j++){
						printf("*");
					}
				else 
					for(int j = n - i; j > 0; j--){
						printf("*");
					}
				printf("\n");
			}
			break;
		case 3:
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					printf("*");
				}
				printf("\n");
			}
			break;
	}

}
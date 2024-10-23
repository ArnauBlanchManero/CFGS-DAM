#include <stdio.h>
#include <stdlib.h>

/*
 * 	Autor: Arnau Blanch
 */

int main(){
	int i, n;
	double factorial = 1;
	printf("De qué número quieres el factorial? ");
	scanf("%d", &n);
	printf("%d! = ", n);
	if (n==0)
		printf("1\n");
	else{
		for (i=n; i>=1; i--){
			factorial = factorial * i;
			if (i!=1)
				printf("%d * ", i);
			else
				printf("1 = %.0lf\n", factorial);	
		}
	}
	return EXIT_SUCCESS;
}

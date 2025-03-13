#include <stdio.h>
#include <stdlib.h>

/*
 * 	Autor: Arnau Blanch
 */

int main(){
	int i, fibo1, fibo2, fibo3;
	fibo1 = 0;
	fibo2 = 1;
	printf("%d %d ", fibo1, fibo2);
	for (i=0; i<=10; i++){
		fibo3 = fibo1 + fibo2;
		fibo1 = fibo2;
		fibo2 = fibo3;
		printf("%d ",fibo3);
	}
	return EXIT_SUCCESS;
}

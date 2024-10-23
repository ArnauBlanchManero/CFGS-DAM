#include <stdio.h>
#include <stdlib.h>

/*
 * 	Autor: Arnau Blanch
 */

int main(){
	int i;
	int suma=0;
	for (i=0; i<=10; i++){
		printf("%d + %d ", suma, i);
		suma = suma+i; 
		printf("= %d\n", suma);
	}
	return EXIT_SUCCESS;
}

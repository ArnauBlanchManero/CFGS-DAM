#include <stdio.h>
#include <stdlib.h>

/*
 * 	Autor: Arnau Blanch
 */

int main(){
	int numeros[5] = {10, 20, 30, 40, 50};
	int *p = numeros;
	int suma = 0;
	for(int i = 0; i<5; i++){
		suma += *(p+i);
	}
	printf("%d\n", suma);
	return EXIT_SUCCESS;
}

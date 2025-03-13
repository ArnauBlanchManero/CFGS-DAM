#include <stdio.h>
#include <stdlib.h>

/*
 * 	Autor: Arnau Blanch
 */

int main(){
	float numero = 8.3;
	int * puntero = &numero; // Genera un warning, pero si lo ejecutas ves el chorro de 0 y 1 del float 8.3 traducido a int.
	printf("Valor de la variable: %f\n", numero);
	printf("Dirección de memoria de la variable: %p\n", puntero);
	printf("Valor apuntado por el puntero: %d\n", *puntero);
	return EXIT_SUCCESS;
}

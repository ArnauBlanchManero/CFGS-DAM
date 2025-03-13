#include <stdio.h>
#include <stdlib.h>

/*
 * 	Autor: Arnau Blanch
 */

void incrementar1(int n){
	printf("Valor recibido: %d\n", n);
	n++;
	printf("Valor incrementado en uno: %d\n", n);
}

int main(){
	int valor = 10;
// Paso de un argumento a una función por valor
	incrementar1(valor);
	printf("Valor del main: %d\n", valor); // Imprime un 10
	return EXIT_SUCCESS;
}

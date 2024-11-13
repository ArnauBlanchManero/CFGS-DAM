#include <stdio.h>
#include <stdlib.h>

/*
 * 	Autor: Arnau Blanch
 */

void incrementar(int *n){
	printf("Valor recibido: %d\n", *n);
	(*n)++; // Me faltaban los parentesis y ++ tenía prioridad.
	printf("Valor incrementado en uno: %d\n", *n);
}

int main(){
	int valor = 10;
// Paso de un argumento a una función por referencia 
	incrementar(&valor); // Le paso la dirección de memoria
	printf("Valor del main: %d\n", valor); // Imprime un 11
	return EXIT_SUCCESS;
}

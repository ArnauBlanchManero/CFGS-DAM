#include <stdio.h>
#include <stdlib.h>

/*
 * 	Autor: Arnau Blanch
 */

void intercambiar(int *a, int *b){
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

int main(){
	int n1 = 10;
	int n2 = 5;
	printf("Valor de n1 inicial: %d\n", n1); // Imprime un 10
	printf("Valor de n2 inicial: %d\n", n2); // Imprime un 5
// Paso de un argumento a una función por referencia 
	intercambiar(&n1, &n2); // Le paso la dirección de memoria
	printf("Valor de n1 intercambiado: %d\n", n1); // Imprime un 5
	printf("Valor de n2 intercambiado: %d\n", n2); // Imprime un 10
	return EXIT_SUCCESS;
}

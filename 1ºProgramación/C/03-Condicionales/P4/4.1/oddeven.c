#include <stdio.h>
#include <stdlib.h>

/*
 * 	Autor: Arnau Blanch
 */

int main(){
	
	// Declaramos la variable que vamos a usar para guardar el número que quiera el usuario
	int num;
	
	// Le pedimos un número
	printf("Introduce un número ");
	scanf("%d", &num);
	
	// Comprobamos que sea par
	if (num % 2 == 0){ // Cuando dividimos num entre dos comprobamos si el resto == cero
		printf("Es par\n");
	}else {
		printf("Es impar\n");
	}
	return EXIT_SUCCESS;
}

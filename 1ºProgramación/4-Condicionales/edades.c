#include <stdio.h>
#include <stdlib.h>

/*
 * 	Autor: Arnau Blanch
 */

int main(){
	// Declaramos la variable
	int edad;

	// Preguntamos la edad
	printf("¿Qué edad tienes? ");
	scanf("%d", &edad);

	// Buscamos la categoría a la que pertenece y se lo mostramos
	if (edad < 12){
		printf("Eres un niño\n");
	} else if (edad < 18){
		printf("Eres un adolescente\n");
	} else if (edad < 65){
		printf("Eres un adulto\n");
	} else {
		printf("Eres mayor\n");
	}	       
	return EXIT_SUCCESS;
}

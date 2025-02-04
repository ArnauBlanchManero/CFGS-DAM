#include <stdio.h>
#include <stdlib.h>

/*
 * 	Autor: Arnau Blanch
 */

int main(){
	char palabra[23], letra;
	int posicion;
	printf("Introduzca una palabra: ");
	scanf("%s", palabra);
	printf("¿Qué posición desea modificar? ");
	scanf("%d", &posicion);
	printf("¿Qué caracter desea poner? ");
	scanf(" %c", &letra);
	palabra[posicion-1] = letra;
	printf("La nueva palabra es: %s\n", palabra);
	return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>

/*
 * 	Autor: Arnau Blanch
 *	
 *	Haz un código que defina dos cadenas de caracteres que contengan la misma palabbra y haz comparaciones.
 */

int main(){
	char palabra1[8]="iguales";
	char palabra2[8]="iguales";
	printf("La palabra1 es %s y la palabra2 es %s\n", palabra1, palabra2);
	if (palabra1 == palabra2)
		printf("Las dos palabras son iguales\n");
	else 
		printf("Las palabras no son iguales\n");
	if (palabra1 > palabra2)
		printf("palabra1 es mayor que palabra2\n");
	else if (palabra1 < palabra2)
		printf("palabra2 es mayor que palabra1\n");
	for (int i = 0; i == 8; i++){
		if (palabra1[i] == palabra2[i]){
			printf("El caracter %d de las palabras es igual\n", i);
		}
	}
	return EXIT_SUCCESS;
}

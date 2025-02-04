#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 	Autor: Arnau Blanch
 */

int main(){
	char * cadena = (char *) calloc(9999, sizeof(char));
	if (cadena == NULL) return 1;
	printf("Introduce tu cadena: ");
	fgets(cadena, 9999, stdin);
	char * cadena_final = (char *) realloc(cadena, strlen(cadena));
	if (cadena_final == NULL) return 1;
	printf("Esto es lo que has escrito: %s", cadena_final);
	cadena = cadena_final;
	free(cadena_final);
	return EXIT_SUCCESS;
}
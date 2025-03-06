#include <stdio.h>
#include <stdlib.h>

/*
 * 	Autor: Arnau Blanch
 *	
 *	Haz un código que sustituya el '\0' de la úlima posición de una cadena de caracteres perdida por pantalla e imprime por pantalla la cadena, antes y después de la sustitución del '\0'.
 */

int main(){
	char cero[4];
	printf("Escribe una palabra de 4 caracteres: ");
	scanf("%s", cero);
	printf("Has escrito la palabra '%s'\n", cero);
	cero[4]='0';
	printf("Después de sustituir el quinto caracter por 0 se me queda '%s'\n", cero);
	return EXIT_SUCCESS;
}

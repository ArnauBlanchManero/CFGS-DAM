#include <stdio.h>
#include <stdlib.h>

/*
 * 	Autor: Arnau Blanch
 */

int main(){
	char str1[5]="hola";
	char str2[10];
	printf("%s\n", str1);
	printf("%c\n", str1[3]); // Imprime el cuarto caracter, porque empieza a contar en 0.
	str1[4] = '$';
	printf("%s\n", str1);
	str1[1] = '\0'; // El \0 indica que acaba de leerlo
	printf("%s\n", str1);
	
	scanf("%s", str2); // No hace falta el & porque ya se ha reservado la dirección de memoria donde empieza el string.
	printf("%s\n", str2);
	return EXIT_SUCCESS;
}

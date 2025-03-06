#include <stdio.h>
#include <stdlib.h>

/*
 * 	Autor: Arnau Blanch
 */

int main(){
	int longitud;
	printf("Qué longitud quieres que sea tu string? ");
	scanf("%d", &longitud);
	char * frase = (char *) malloc(longitud+1);
	if (frase == NULL) return 1;
	int i;
	for (i = 0; i <= longitud; i++){
		scanf("%c", &frase[i]);
	}
	frase[i] = '\0';
	printf("Lo que has escrito es %s\n", frase);
	free(frase);
	return EXIT_SUCCESS;
}
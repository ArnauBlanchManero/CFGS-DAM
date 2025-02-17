#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 	Autor: Arnau Blanch
 */

void guardar_vocales(char * origen, char ** destino, int posicion);
int esVocal(char vocal);

int main(){
	char * frase;
	char * vocales;
	int posicion = 0;
	frase = (char *) malloc (sizeof(char) * 500);
	printf("Escribe una cadena de texto: ");
	fgets(frase, 500, stdin);
	vocales = (char *) malloc (strlen(frase));
	guardar_vocales(frase, &vocales, posicion);
	printf("Frase original:\n\t%sFrase con vocales:\n\t%s\n", frase, vocales);
	free(frase);
	free(vocales);
	return EXIT_SUCCESS;
}

void guardar_vocales(char * origen, char ** destino, int posicion){
	if (origen[0] == '\0'){
		return;
	}
	if (esVocal(origen[0])){
		(*destino)[posicion] = origen[0];
		posicion++;
	}
	guardar_vocales(origen+1, destino, posicion);
}

int esVocal(char vocal){
	if(vocal == 'A' || vocal == 'a' || vocal == 'E' || vocal == 'e' || vocal == 'I' || vocal == 'i' || vocal == 'O' || vocal == 'o' || vocal == 'U' || vocal == 'u'){
		return 1;
	}
	return 0;
}

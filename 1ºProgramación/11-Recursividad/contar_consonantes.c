#include <stdio.h>
#include <stdlib.h>

int contar_caracteres(char * caracter);
int es_consonante(char consonante);

int main(){
	char palabra[50] = "Supercalifragilisticoespialidoso";
	int cantidad;
	cantidad = contar_caracteres(&(palabra[0]));
	printf("La palabra %s tiene %d consonantes.\n", palabra, cantidad);
	return 0;
}

int contar_caracteres(char * caracter){
	if(*caracter == '\0'){
		return 0;
	}
	if(es_consonante(*caracter)){
		return 1 + contar_caracteres(caracter+1);
	}
	return contar_caracteres(caracter+1);
}

int es_consonante(char consonante){
	if(consonante == 'A' || consonante == 'a' || consonante == 'E' || consonante == 'e' || consonante == 'I' || consonante == 'i' || consonante == 'O' || consonante == 'o' || consonante == 'U' || consonante == 'u'){
		return 0;
	}
	return 1;
}

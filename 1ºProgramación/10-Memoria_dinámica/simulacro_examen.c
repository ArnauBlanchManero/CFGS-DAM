#include <stdio.h>
#include <stdlib.h>

int main(){
	float tamanio;
	int nuevo_tamanio;
	float * numeros;
	printf("Determina el tamaño del array: ");
	scanf("%f", &tamanio);
	numeros = (float *) malloc(sizeof(float) * tamanio);
	if (numeros == NULL) return 1;
	for (int i = 0; i < tamanio; ++i){
		*(numeros+i) = i/tamanio;
	}
	for (int i = 0; i < tamanio; ++i){
		printf("Posición %d: %d/%.0f = %.2f\n", i, i, tamanio, numeros[i]);
	}
	nuevo_tamanio = tamanio/2;
	numeros = (float *) realloc(numeros, sizeof(float) * nuevo_tamanio);
	if (numeros == NULL) return 1;
	printf("Hacemos el realloc a la mitad\n");
	for (int i = 0; i < nuevo_tamanio; ++i){
		printf("Posición %d: %d/%d = %.2f\n", i, i, nuevo_tamanio, numeros[i]);
	}
	free(numeros);
	return 0;
}
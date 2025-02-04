#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 	Autor: Arnau Blanch
 *  Crea un array de enteros con calloc, 
 *  inicialízalo con valores, imprímelos y
 *  luego libera la memoria.
 */

#define CANTIDAD 5

int main(){
    int * numeros = (int *) calloc(CANTIDAD, sizeof(int));
    if (numeros == NULL) return 1;
    for(int i = 0; i < CANTIDAD; i++){
        numeros[i] = i*17%6+2;
    }
    for (int i = 0; i < CANTIDAD; i++){
        printf("Numero %d: %d\n", i, *(numeros+i));
    }
    free(numeros);
	return EXIT_SUCCESS;
}

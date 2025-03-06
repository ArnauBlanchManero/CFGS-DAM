#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 	Autor: Arnau Blanch
 *  Convierte un array de enteros declarado estáticamente 
 *  en un array asignado dinámicamente con malloc,
 *  rellénalo con valores y libéralo.
 */

#define MAX_NUM 4

void rellena_malloc(int * n, int vueltas){
    for (int i = 0; i < vueltas; i++)
        n[i] = vueltas+i;
}

void imprimir_numeros(int * n, int vueltas){
    for(int i = 0; i < vueltas; i++)
        printf("Numero %d: %d\n", i, *(n+i));
}

int main(){
    int numeros1[MAX_NUM] = {5, 7, 9, 11};
    printf("Núemros asignados estáticamente:\n");
    imprimir_numeros(numeros1, MAX_NUM);
    int * numeros2 = (int *) malloc (sizeof(int) * MAX_NUM);
    if (numeros2 == NULL) return 1;
    printf("Números rellenados en el malloc: \n");
    rellena_malloc(numeros2, MAX_NUM);
    imprimir_numeros(numeros2, MAX_NUM);
    free(numeros2);
	return EXIT_SUCCESS;
}
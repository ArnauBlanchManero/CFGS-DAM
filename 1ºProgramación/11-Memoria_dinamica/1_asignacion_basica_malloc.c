#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 	Autor: Arnau Blanch
 *  Escribe un programa que asigne memoria dinámicamente 
 *  para un solo entero con malloc, asigne un valor y 
 *  luego lo imprima y libere.
 */

int main(){
    int * num = (int *) malloc(sizeof(int));
    if (num == NULL) return 1;
    num[0] = 3;
    printf("El número es: %d\n", *num);
    free(num);
	return EXIT_SUCCESS;
}
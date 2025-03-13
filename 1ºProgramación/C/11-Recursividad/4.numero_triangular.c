#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 	Autor: Arnau Blanch
 */

int contar_puntitos(int n){
	if(n==0)return 0;
	return n + contar_puntitos(n-1);
}

int main(){
	int num_pisos, num_puntitos;
	printf("Dime el número de pisos: ");
	scanf("%d", &num_pisos);
	num_puntitos = contar_puntitos(num_pisos);
	printf("Necesitas %d puntitos.\n", num_puntitos);
	return EXIT_SUCCESS;
}

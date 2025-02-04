#include <stdio.h>
#include <stdlib.h>

/*
 * 	Autor: Arnau Blanch
 */

int main(){
	int i, suma;
	printf("Cuántos números quieres sumar? ");
	scanf("%d", &suma);
	for (i=0; i<=10; i++){
		printf("%d + %d = %d\n", suma, i, suma=suma+i);
	}
	return EXIT_SUCCESS;
}

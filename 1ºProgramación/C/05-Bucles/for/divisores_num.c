#include <stdio.h>
#include <stdlib.h>

/*
 * 	Autor: Arnau Blanch
 */

int main(){
	int i, divisor, n;
	printf("Qué número quieres hayar sus divisores? ");
	scanf("%d", &n);
	for (i=1; i<=n; i++){
		if (n%i == 0)
			divisor++;
	}
	printf("El número %d tiene %d divisores.\n", n, divisor);
	return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>

/*
 * 	Autor: Arnau Blanch
 */

int main(){
	
	for (int i=2; i<=20; i+=2){
		printf("%d", i);
		if (i<20)
			printf(", ");
	}
	printf(".\n");
	int i;
	for (i=0; i<19; i+=2)
		printf("%d, ", i);
	printf("%d.\n", i); //Al salir del bucle, i vale 20.
	return EXIT_SUCCESS;
}

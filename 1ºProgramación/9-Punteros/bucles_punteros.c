#include <stdio.h>
#include <stdlib.h>

/*
 * 	Autor: Arnau Blanch
 */

int main(){
	int arr[5] = {1, 2, 3, 4, 5};
	
	for(int * p = arr; p <= &arr[4]; p++){
		printf("%d\n", *p);
	}
	printf("Elementos del array: %ld\n", sizeof(arr)/sizeof(int)); // sizeof cuenta bytes por eso lo divido
	
	char palabra[10] = "letras";
	
	for(char * l = palabra; *l != '\0'; l++)
		printf("%c ", *l);
	printf("\n");
	return EXIT_SUCCESS;
}

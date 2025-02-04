#include <stdio.h>
#include <stdlib.h>

/*
 * 	Autor: Arnau Blanch
 */

int main(){
	
	for (int i=0; i<=100; i=i+2){
	/*	
	 * Para incrementar se puede usar la siguiente sintaxis:
	 * i=i+x //incrementa x
	 * i+=x // incrementa x
	 * i++ // incrementa 1
	*/
		printf("%d ", i);
	}
	printf("Terminé, finalizé, concluí, acabé\n");
	return EXIT_SUCCESS;
}

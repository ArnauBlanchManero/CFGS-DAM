#include <stdio.h>
#include <stdlib.h>

/*
 * 	Autor: Arnau Blanch
 */

// *ptr será lo que hay que imprimir
// 'tipo' indica el tipo de variable
void printValor(void * ptr, char tipo){
	switch(tipo){
		case'i':
			// printf("Int %d\n", (int *)ptr); No funciona porque hay que escribir * para mostrar el contenido después de la conversión
			printf("Int %d\n", *((int *)ptr)); // Un casting es convertir de un tipo a otro (tiene que ser explícito)
						// El único casting implícito que hay en c es entre int a char
			break;
		case'c':
			printf("Char %c\n", *((char *)ptr)); 
			break;
		case'f':
			printf("Float %f\n", *((float *)ptr)); 
			break;
		case'd':
			printf("Double %lf\n", *((double *)ptr)); 
			break;
		default:
			printf("Error");
	}
}

int main(){
	float num = 7.3;
	void * dir = &num;
	printValor(dir,'i');
	printValor(dir,'c');
	printValor(dir,'f');
	printValor(dir,'d');
	return EXIT_SUCCESS;
}

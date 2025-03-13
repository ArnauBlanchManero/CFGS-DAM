#include <stdio.h>
#include <stdlib.h>

/*
 * 	Autor: Arnau Blanch
 */

int main(){
	// Declaramos la variable
	int num_semana;

	// Pedimos el número al usuario
	printf("Introduce un número: ");
	scanf("%d", &num_semana);

	// Le devolvemos un resultado u otro dependiendo de su número
	switch(num_semana){
		case 1:
			printf("Resultado: Lunes\n");
			break;
		case 2:
			printf("Resultado: Martes\n");
			break;
		case 3:
			printf("Resultado: Miércoles\n");
			break;
		case 4:
			printf("Resultado: Jueves\n");
			break;
		case 5:
			printf("Resultado: Viernes\n");
			break;
		case 6:
			printf("Resultado: Sábado\n");
			break;
		case 7:
			printf("Resultado: Domingo\n");
			break;
		default:
			printf("Número inválido\n");	
	}
	return EXIT_SUCCESS;
}

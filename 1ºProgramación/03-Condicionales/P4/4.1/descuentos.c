#include <stdio.h>
#include <stdlib.h>

/*
 * 	Autor: Arnau Blanch
 */

void descuento(float total, float porcentaje){ //Para calcular el % de descuento
	float resultado;
	resultado = (100-porcentaje)*total/100;
	printf("Con el descuento se te ha quedado en %.2f\n", resultado);
}
int main(){
	// Declaración de variables
	float total;
	char rol;

	// Pedimos los datos al usuario
	printf("Pon el precio del producto: ");
	scanf("%f", &total);
	printf("e: estudiante\np: profesor\no: otro\nEscribe tu rol: ");
	scanf(" %c", &rol);
	
	// Dependiendo de su rol, le ponemos un descuento u otro
	if (rol == 'e'){
		descuento(total, 15);
	} else if (rol == 'p'){
		descuento(total, 10);
	} else if (rol == 'o'){
		descuento(total, 0);
	} else {
		printf("Por favor, escribe e, p, o\n");
	}
	return EXIT_SUCCESS;
}

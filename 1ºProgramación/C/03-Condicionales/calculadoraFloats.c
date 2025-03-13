#include <stdio.h>
#include <stdlib.h>
/*
 * 	Proyecto creado por Arnau
 */

// Creamos funciones para operar
float sum(float a, float b){
	return a+b;
}
float rest(float a, float b){
	return a-b;
}
float multi(float a, float b){
	return a*b;
}
float divi(float a, float b){
	return a/b;
}

int main(){
	// Declaración de variables
	float num1, num2, suma, resta, mult, div;
	char operacion;

	// Pedimos los valores a las variables
	
	printf("Escribe el primer número: ");
	scanf("%f", &num1);
	printf("Y el segundo: ");
	scanf("%f", &num2);
	printf("Escribe la inicial de la operación que quieras hacer:\ns --> suma\tr --> resta\tm --> multiplicación\td --> división\n");
	scanf(" %c", &operacion);

	
	// Hacemos la operación que nos ha pedido
	if (operacion == 's'){
		suma = sum(num1, num2);
		printf("%.2f+%.2f=%.2f\n", num1, num2, suma);
	}else if (operacion == 'r'){
		resta = rest(num1, num2);
		printf("%.2f-%.2f=%.2f\n", num1, num2, resta);
	}else if (operacion == 'm'){
		mult = multi(num1, num2);
		printf("%.2f*%.2f=%.2f\n", num1, num2, mult);
	}else if (operacion == 'd'){
		div = divi(num1, num2);
		printf("%.2f/%.2f=%.2f\n", num1, num2, div);
	}else{
		printf("Tu eres tonto o no sabes leer?\n");
	}
	return 0;
}

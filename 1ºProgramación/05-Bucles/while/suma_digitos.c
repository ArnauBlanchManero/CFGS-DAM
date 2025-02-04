#include <stdio.h>
#include <stdlib.h>

/*
 * 	Autor: Arnau Blanch
 */

int main(){
	int num;
	printf("Escribe un número de tres dígitos: ");
	scanf("%d", &num); // pido el número que sumare sus digitos
	int inicial = num; // para luego imprimir el numero inicial
	int sumadigito = 0; // qui voy a ir sumando los digitos
	int division = 100; // es 100 porque empiezo con tres dígitos
	while(num != 0){ // cuando num sea 0 ya podemos parar el bucle
		sumadigito += num/division; // vamos a sumar el resultado de dividir el numero entre division, ya que son numeros enteros el resultado sera el digito mas a la izquierda.
		num = num % division; // renombramos el valor de num para que sea el resto de la division en la siguiente vuelta
		division = division /10; // dividimos entre diez para quitar un 0 a la hora de dividir
	}
	printf("La suma de los dígitos de %d es %d\n", inicial, sumadigito);
	

	printf("Escribe un número con tantos dígitos como quieras: ");
	scanf("%d", &num);	
	inicial = num; // para luego imprimir el numero inicial
	sumadigito = 0; // qui voy a ir sumando los digitos
	while(num == 0){
		sumadigito += num /10;
		num = num / 10;
	}
	printf("La suma de los dígitos de %d es %d\n", inicial, sumadigito);
	return EXIT_SUCCESS;
}

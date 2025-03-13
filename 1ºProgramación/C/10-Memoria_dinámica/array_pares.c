#include <stdio.h>
#include <stdlib.h>

/*
 * 	Autor: Arnau Blanch
 */

/* 
	CREA UN PROGRAMA QUE PIDA POR PANTALLA UN NÚMERO ENTERO Y 
	CREE UN ARRAY DE ENTEROS DE ESTE TAMAÑO INICIALIZANDO CON LOS NÚMEROS PARES.
	DESPUÉS, IMPRIMELO
	MODIFICA EL PUNTERO PARA QUE SEA UN ARRAY 
	EL DOBLE DE GRANDE Y, EN LA SEGUNDA PARTE DEL ARRAY, SE GUARDEN LOS NÚMEROS IMPARES.
*/

int main(int argc, char ** argv){
	if (argc < 2){ // Verificar que haya argumentos desde la línea de comandos
		printf("Ingresa un número\n");
		return EXIT_FAILURE;
	}

	int cantidad_numeros = atoi(argv[1]); // atoi para convertir de char a int desde la línea de comandos
	int * arr = (int *) malloc(sizeof(int) * cantidad_numeros); // malloc devuelve void * y necesita un casting especifico a int *. 
	int par = 0; // Inicilizo en el primer número par.
	int impar = 1; // Inicializo en el primer número impar.

	if (arr == NULL){ // Verificar si malloc falló
		printf("Error al asignar memoria\n");
		return EXIT_FAILURE;
	}

	printf("\nEl número que has insertado es: %d\n\n", cantidad_numeros);

	for(int i = 0; i < cantidad_numeros; i++){
		arr[i] = par;
		par += 2; // Para mostrar sólo los pares (me ahorro de hacer un if par % 2 ...)
	}
	
	for(int i = 1; i <= cantidad_numeros; i++){ // Uso <= para dar las vueltas necesarias.
		printf("Numero %d: %d\n", i, *(arr+i-1)); // Poniendo arr+i puedo acceder a todos los elementos del array manteniendo el puntero de arr en el primero. Resto uno porque en un array se empieza en 0 y i empieza en 1.
	}
	
	printf("\nSegunda parte\n\n");

	int doble_cantidad_numeros = cantidad_numeros * 2;
	int * arr2 = (int *) realloc(arr, sizeof(int) * doble_cantidad_numeros); // realloc copia lo que hay en arr y se va a otra dirección de memoria donde crea arr2 con el espacio indicado.
	arr = arr2; // para que arr no apunte a un sitio en el que no hay información que está reservada.

	for(int i = cantidad_numeros; i < doble_cantidad_numeros; i++){ // relleno los números impares
		arr2[i] = impar;
		impar += 2;
	}
	
	for(int i = 1; i <= doble_cantidad_numeros; i++){
		printf("Numero %d: %d\n", i, *(arr2+i-1));
	}
	
	free(arr2); // libero la memoria reservada.
	return EXIT_SUCCESS;
}

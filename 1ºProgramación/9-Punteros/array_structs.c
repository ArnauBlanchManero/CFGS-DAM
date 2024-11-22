#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 * 	Autor: Arnau Blanch
 */


// Defino mis constantes
#define MAX_NOMBRE 20
#define MAX_ESTUDIANTES 30


typedef struct{
	char nombre[MAX_NOMBRE];
	int edad;
	float nota;
} Estudiante;

/*
Estudiante inicializar(char * nombre, int edad, float nota){
	// Creo una variable de tipo Estudiante
	Estudiante estudiante_nuevo;
	
	// Inicializo el estudiante.
	
	return estudiante_nuevo;
}
No está del todo bien porque creo una variable que ocupa un espacio en memoria que luego se va a liberar.*/

/*
Estudiante * inicializar(char * nombre, int edad, float nota){
	Estudiante * estudiante_nuevo = malloc; // Memoria dinámica	
	// Inicializo el estudiante.
	return estudiante_nuevo;
}
Está bien pero no lo hemos dado aún */

void inicializar(Estudiante * nuevo_estudiante, char * nombre, int edad, float nota){
	
	//nuevo_estudiante.edad = edad; Esto no funciona porque nuevo_estudiante es una dirección de memoria, habría que acceder al contenido así:
	(*nuevo_estudiante).edad = edad; // Esto estaría bien
	// Pero C permite hacer esto:
	nuevo_estudiante -> nota = nota;
	// nuevo_estudiante.nombre = nombre; no funciona porque cmabia la dirección de memoria.
	strcpy(nuevo_estudiante -> nombre, nombre);
}

int main(){
	Estudiante listado[MAX_ESTUDIANTES]; // Aquí se reserva la memoria para los estudiantes.
	
	int num_estudiantes;
	int edad;
	float nota;
	char nombre[MAX_NOMBRE];
	
	printf("%p\n", listado);
	printf("Sizeof listado: %lu\n", sizeof(listado)); // 840 porque hay 30 Estudiantes
	printf("Sizeof estudiante: %lu\n", sizeof(Estudiante)); // 28 porque teine un char de 20, un int y un float.
	
	printf("¿Cuántos estudiantes desea inicializar? ");
	scanf("%d", &num_estudiantes);
	
	for(int i = 0; i < num_estudiantes; i++){
		printf("Introduce la edad%d: ", i);
		scanf("%d", &edad);
		printf("Introduce la nota%d: ", i);
		scanf("%f", &nota);
		printf("Introduce el nombre%d: ", i);
		scanf("%s", nombre);
		inicializar(&listado[i], nombre, edad, nota);
		//inicializar(listado + i, nombre, edad, nota);
	}
	return EXIT_SUCCESS;
}

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

// No necesito que devuelva nada.
void cumpleanios(Estudiante * cumpleaniero){ // Tiene que recibir un puntero a estudiante porque va a modificar la variable que está en la variable y tiene que perdurar.
	(*cumpleaniero).edad ++;
	// Sería mejor poner cumpleanioero->edad++;
}

// Crea una funcion que cree una cadna de texto con la informaicon del estudiante. 
// Puedes creando una funcion que imprima por mantalla la info de un estudiante.

void imprimirEstudiante(const Estudiante * estudiante_a_imprimir){ // Pasar por valor tiene un "coste" por eso pasamos sólo la dirección de memoria pero no queremos que cambie por lo que usaremos const.
	printf("\nNombre: %s\n", estudiante_a_imprimir->nombre);
	printf("\tEdad: %d\n", estudiante_a_imprimir->edad);
	printf("\tNota: %f\n", estudiante_a_imprimir->nota);
}

// Convertir de Estudiante a string

/*
char * estudianteToStr_warning(const Estudiante * datos){
	char retval[200];
	// string number printf dónde, cuánto, el qué
	snprintf(retval, 200, "El estudiante %s de %d años ha sacado un %.2f", datos->nombre, datos->edad, datos->nota);
	return retval; // Esto da warning porque devuelve la direccion de memoria de una variable local que luego se liberará 
}
*/

void estudianteToStr(const Estudiante * datos, char * retval){
	// string number printf dónde, cuánto, el qué
	snprintf(retval, 400, "El estudiante %s de %d años ha sacado un %.2f\n", datos->nombre, datos->edad, datos->nota);
}

/*
void modificaNombreEstudiante(Estudiante * datos, char * nuevoNombre){
	strcpy (datos->nombre , nuevoNombre);
}
*/

void modificacionAntonio(Estudiante * datos){
	printf("\nCómo quieres renombrar al estudiante0? ");
	scanf("%s", datos->nombre);
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

		printf("\nEdad antigua de %s: %d\n", listado[i].nombre, listado[i].edad);
		cumpleanios(&listado[i]); // Aquí le estoy pasando una dirección de memoria, si quisiera especificar de qué alumno debería poner &listado[0] 
		printf("Nueva edad: %d\n", listado[i].edad);
		imprimirEstudiante(&listado[i]);
	
//		char nuevo_nombre[MAX_NOMBRE];
//		printf("\nCómo quieres renombrar al estudiante0? ");
//		scanf("%s", nuevo_nombre);
//		modificaNombreEstudiante(&listado[i], nuevo_nombre);
	
		imprimirEstudiante(&listado[i]);
		modificacionAntonio(&listado[i]);
		imprimirEstudiante(&listado[i]);
		char frase[200];
		estudianteToStr(&listado[i], frase);
		printf("\nDesde el main, %s\n", frase);
	}
	return EXIT_SUCCESS;
}

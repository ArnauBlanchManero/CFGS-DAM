#include <stdio.h>
#include <stdlib.h>

#define NOTA_APROBADO 5.00

int main(){
// 1. Ingreso de notas
	int cantidad_estudiantes;
	printf("Ingresa la cantidad de estudiantes que hay: ");
	scanf("%d", &cantidad_estudiantes);
	double nota[cantidad_estudiantes]; // Aquí guardaremos las notas de todos los estudiantes.
	for (int i = 0; i < cantidad_estudiantes; i++){ // Este bucle se repetirá tantas veces como estudiantes haya.
		printf("Nota final del estudiante %d: ", i);
		scanf("%lf", &nota[i]);
	}
// 2. Cálculo del promedio
	double acumulador = 0;
	double promedio;
	for (int i = 0; i < cantidad_estudiantes; i++){ // Este bucle se repetirá tantas veces como estudiantes haya.
		acumulador += nota[i]; // Iremos sumando cada valor del array.
	}
	promedio = acumulador / cantidad_estudiantes; // La fórmula para hallar el promedio es sumar todos los datos y dividirlos entre la cantidad de esos datos que hay.
	printf("Promedio de notas: %.2lf\n", promedio);
// 3. Número de Aprobados y Suspensos:
	int aprobados = 0;
	int suspensos = 0;
	for (int i = 0; i < cantidad_estudiantes; i++){ // Este bucle se repetirá tantas veces como estudiantes haya.
		if (nota[i] >= NOTA_APROBADO){
			aprobados++;
		} else {
			suspensos++;
		}
	}
	printf("Número de estudiantes aprobados: %d\nNúmero de estudiantes suspensos: %d\n", aprobados, suspensos);
// 4. Nota máxima y nota mínima
	double min = nota[0]; // Inicializamos en la nota del primer estudiante.
	double max = nota[0];
	int posicion_max = 0;
	int posicion_min = 0;
	for (int i = 0; i < cantidad_estudiantes; i++){ // Este bucle se repetirá tantas veces como estudiantes haya.
		if (nota[i] >= max){ // Para guardar la nota máxima y su posición
			max = nota[i];
			posicion_max = i;
		}
		if (nota[i] <= min){ // Para hayar la nota mínima y su posición
			min = nota[i];
			posicion_min = i;
		}
	}
	printf("Nota máxima: %.1lf (Estudiante en la posición %d)\nNota mínima: %.1lf (Estudiante en la posición %d)\n", max, posicion_max, min, posicion_min);
// 5. Listado de notas por encima del promedio
	printf("Notas por encima del promedio: \n");
	for (int i = 0; i < cantidad_estudiantes; i++){ // Este bucle se repetirá tantas veces como estudiantes haya.
		if (nota[i] > promedio){
			printf("Estudiante en la posición %d: %.1lf\n", i, nota[i]);
		}
	}
	return 0;
}

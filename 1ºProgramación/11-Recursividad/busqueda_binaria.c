#include <stdio.h>
#include <stdlib.h>

int busqueda_binaria(int * array, int n, int ini, int fin){
	int cantidad = fin - ini + 1;
	if (cantidad <= 2){
		if (n == array[ini-1]){
			return 1;
		} else if (n == array[fin-1]){
			return 1;
		} else {
			return 0;
		}
	}
	int mitad = (ini+fin+1)/2;
	if (n >= array[mitad-1]){
		ini = mitad;
	} else if (n <= array[mitad-1]){
		fin = mitad;
	}
	return busqueda_binaria(array, n, ini, fin);
}

int main(){
	//int longitud = 10;
	int arr[10] = {-5, 1, 9, 10, 11, 12, 17, 120, 150, 1500};
	int a_buscar = 120;
	printf("Escribe el número que quieres buscar dentro de mi array: ");
	scanf("%d", &a_buscar);
	int encontrado = busqueda_binaria(arr, a_buscar, 0, 9);
	if(encontrado){
		printf("He encontrado el número %d en el array.\n", a_buscar);
	} else{
		printf("No he encontrado el número %d en el array.\n", a_buscar);
	}
	return 0;
}

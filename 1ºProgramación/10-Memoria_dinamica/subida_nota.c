#include <stdio.h>
#include <stdlib.h>

int * rellena_array(int * arr, int cantidad){
	for (int i = 0; i < cantidad; i++){
		arr[i] = 3 * i;
	}
	return arr;
}

int pedir_numero(){
	int numero = 0;
	printf("Escribe un número entero positivo: ");
	int comprobar = scanf("%d", &numero);
	if (comprobar == 0) {printf("Tendrías que haber escrito un número entero.\n"); return 0;}
	if ( numero < 0 ) {printf("Tendrías que haber escrito un número entero positivo.\n"); return 0;}
	return numero;
}

void concatenar(int * arr1, int cant1, int * arr2, int cant2){
	int i, j;
	printf("Para el segundo array. ");
	cant2 = pedir_numero();
	arr2 = rellena_array(arr2, cant2);
	int * arr3 = (int *) malloc (sizeof(int)*(cant1+cant2));
	for(i = 0; i < cant1; i++){
		arr3[i] = arr1[i];
	}
	for(j = 0; j < cant2; j++){
		arr3[i] = arr2[j];
		i++;
	}
	for (int i = 0; i < cant1+cant2; i++){
		printf("%d\n", arr3[i]);
	}
	free(arr3);
}

void sumar(int * arr1, int * arr2, int cant){
	int * arr3 = (int *) malloc (sizeof(int)*cant);
	for(int i = 0; i < cant; i++){
		arr3[i] = arr1[i] + arr2[i];
	}
	for (int i = 0; i < cant; i++){
		printf("%d\n", arr3[i]);
	}
	free(arr3);
}

int main(){
	int num = 0;
	int respuesta;
	int * array_numeros;
	int * array_numeros2;

	num = pedir_numero();

	array_numeros = (int *) malloc (sizeof(int)*num);
	array_numeros2 = (int *) malloc (sizeof(int)*num);
	array_numeros = rellena_array(array_numeros, num);
	array_numeros2 = rellena_array(array_numeros2, num);

	printf("¿Quieres 1-concatenar o 2-sumar? ");
	scanf("%d", &respuesta);

	if (respuesta == 1){
		concatenar(array_numeros, num, array_numeros2, num);
	}else if (respuesta == 2){
		sumar(array_numeros, array_numeros2, num);
	}else {printf("Tendrías que haber escrito 1 o 2.\n");}
	free(array_numeros);
	free(array_numeros2);
	return 0;
}

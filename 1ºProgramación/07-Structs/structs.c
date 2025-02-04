#include <stdio.h>
#include <stdlib.h>

/*
 * 	Autor: Arnau Blanch
 */

#define NUM_CLIENTES 10

struct fecha {
	int mes;
	int dia;
	int anio;
};

struct cuenta {
	int num_cuenta;
	char tipo_cuentas;
	char nombre[20];
	float saldo;
	struct fecha ultimopago;
};

int main(){
	struct cuenta cliente[NUM_CLIENTES];
	for (int i = 0; i<=NUM_CLIENTES; i++){
		printf("Numero de cuenta del cliente %d: ", i);
		scanf("%d", &cliente[i].num_cuenta);
		printf("Tipo de cuenta del cliente %d: ", i);
		scanf(" %c", &cliente[i].tipo_cuentas);
		printf("Nombre del cliente %d: ", i);
		scanf(" %s", cliente[i].nombre);
		printf("Saldo del cliente %d: ", i);
		scanf("%f", &cliente[i].saldo);
		printf("Mes último día del cliente %d: ", i);
		scanf("%d", &cliente[i].ultimopago.mes);
		printf("Dia último día del cliente %d: ", i);
		scanf("%d", &cliente[i].ultimopago.dia);
		printf("Año último día del cliente %d: ", i);
		scanf("%d", &cliente[i].ultimopago.anio);
	}
	for (int i = 0; i<=NUM_CLIENTES; i++){
		printf("Cliente %d\n", i);	
		printf("Numero de cuenta del cliente %d\n: ", cliente[i].num_cuenta);
		printf("Tipo de cuenta del cliente %d\n: ", cliente[i].tipo_cuentas);
		printf("Nombre del cliente %s\n: ", cliente[i].nombre);
		printf("Saldo del cliente %f\n: ", cliente[i].saldo);
		printf("Mes último día del cliente %d\n: ", cliente[i].ultimopago.mes);
		printf("Dia último día del cliente %d\n: ", cliente[i].ultimopago.dia);
		printf("Año último día del cliente %d\n: ", cliente[i].ultimopago.anio);
	}
	return EXIT_SUCCESS;
}

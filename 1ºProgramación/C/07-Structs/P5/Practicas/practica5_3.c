#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct articulo {
	char nombre[100];
	int cantidad;
};

int pedir_cantidad_productos(){ // Creo una función para llamarla simpre que el usuario ingrese una cantidad mayor a 10
	int cantidad;
	printf("Cuántos productos quieres gestionar? (máximo de 10) ");
	scanf("%d", &cantidad);
	return cantidad;
}


int main(){
// 1. Ingreso de productos y cantidades
	int n_productos;

	do{
		n_productos = pedir_cantidad_productos();
	} while (n_productos > 10); // Compruebo que el usuario haya introducido menos de 10 productos

	struct articulo producto[n_productos];

	for (int i = 0; i < n_productos; i++){ // Se repite tantas veces como número de productos haya
		printf("Nombre del producto %d: ", i);
		scanf(" %s", producto[i].nombre);
		printf("Cantidad de %s: ", producto[i].nombre);
		scanf("%d", &producto[i].cantidad);
	}

// 2. Mostrar inventario completo

	printf("Inventario Completo:\n");
	for (int i = 0; i < n_productos; i++){ // Se repite tantas veces como número de productos haya
		printf("Producto %d: %s - %d unidades\n", i, producto[i].nombre, producto[i].cantidad);
	}

// 3. Rebastecimiento de productos
	
	char respuesta[4];
	char reabastecer_producto[100];
	int cant = 0;
	int i;
	do {
		printf("¿Desea reabastecer algún producto? (sí/no): ");
		scanf(" %s", respuesta); 
		if (strcmp(respuesta, "sí") == 0 || strcmp(respuesta, "si") == 0){ // Puede reabastecer productos sólo si escribe "si" o "sí"
			printf("Ingrese el nombre del producto: ");
			scanf(" %s", reabastecer_producto);
			i = 0;
			for (i = 0; i < n_productos; i++){
				if (strcmp(producto[i].nombre, reabastecer_producto) == 0){ // Para buscar el producto
					printf("Cantidad a añadir: ");
					scanf("%d", &cant);
					producto[i].cantidad += cant; // Se incrementa
					break;
				}
			}
		}
	}while (strcmp(respuesta, "no") != 0); // Sólo sale del bucle si pone la palabra "no"

// 4. Cálculo de productos en baja existencia 

	printf("Productos en baja existencia:\n");
	for (int i = 0; i < n_productos; i++){ // Se repite tantas veces como número de productos haya
		if (producto[i].cantidad < 5)
			printf("%s - %d unidades\n", producto[i].nombre, producto[i].cantidad);
	}

// 5. Busca un producto por nombre
	
	char busca[100];
	int j;
	printf("Ingrese el nombre del producto a buscar: ");
	scanf(" %s", busca);
	for (j = 0; j < n_productos; j++){
		if (strcmp(producto[j].nombre, busca) == 0){ // Cuando encuentro el nombre, imprimo su stock y salgo del bucle
			printf("Cantidad en stock: %d unidades\n", producto[j].cantidad);
			break;
		}else if (j ==  n_productos-1){ // Si no encuentra el nombre del producto (llega a n_productos-1) imprime que no existe
			printf("El producto no existe\n");
		}
	}

// 6. Meta de stock diario
	
	int meta;
	printf("Cuál es tu meta de stock diario: ");
	scanf("%d", &meta);
	for (int i = 0; i < n_productos; i++){
		if(producto[i].cantidad == meta){
			printf("El primer día en el que se alcanzó la meta es %s\n", producto[i].nombre);
            break;
		}else if(i == n_productos-1){
			printf("Ningún producto ha alcanzado la meta");
		}
	}

	return 0;
}

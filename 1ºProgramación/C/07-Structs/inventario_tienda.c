#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * 	Autor: Arnau Blanch
 */

#define MAX_ITEMS 10

typedef struct {
	char nombre[100];
	char direccion[100];
	char telefono[13];
}Proveedor;

typedef struct {
	char nombre[100];
	float precio;
	Proveedor proveedor;
}Articulo;

typedef struct {
	Articulo articulos[MAX_ITEMS];
	int cantidades[MAX_ITEMS];
	int totalArticulos;
}Inventario;

int main(){
	
	// Una opción es inicializar miInventario con llaves
	Inventario miInventario = {{"Pantalla", 45, {"LG", "España", "+34615645753"}}, 93, 500};
	// Y otra opción es hacerlo una por una
//	Inventario miInventario;
	strcpy(miInventario.articulos[1].nombre, "Monitor");
	miInventario.articulos[1].precio = 89.99;
	strcpy(miInventario.articulos[1].proveedor.nombre, "Samsung");
	strcpy(miInventario.articulos[1].proveedor.direccion, "China");
	strcpy(miInventario.articulos[1].proveedor.telefono, "+34648314159");
	miInventario.cantidades[1] = 27;
	miInventario.totalArticulos = 500;
	
	printf("Mi inventario:\n	Articulo 0:\n		Nombre: %s\n		Precio: %.2f\n		Proveedor:\n			Nombre: %s\n			Direccion: %s\n			Telefono: %s\n	Cantidad 0: %d\n	Total articulos: %d\n", miInventario.articulos[0].nombre, miInventario.articulos[0].precio, miInventario.articulos[0].proveedor.nombre, miInventario.articulos[0].proveedor.direccion, miInventario.articulos[0].proveedor.telefono, miInventario.cantidades[0], miInventario.totalArticulos);
	printf("Mi inventario:\n	Articulo 1:\n		Nombre: %s\n		Precio: %.2f\n		Proveedor:\n			Nombre: %s\n			Direccion: %s\n			Telefono: %s\n	Cantidad 1: %d\n	Total articulos: %d\n", miInventario.articulos[1].nombre, miInventario.articulos[1].precio, miInventario.articulos[1].proveedor.nombre, miInventario.articulos[1].proveedor.direccion, miInventario.articulos[1].proveedor.telefono, miInventario.cantidades[1], miInventario.totalArticulos);
	return EXIT_SUCCESS;
}

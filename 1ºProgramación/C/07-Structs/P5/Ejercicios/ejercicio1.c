#include <stdio.h>
#include <stdlib.h>

int main(){
    // Una empresa que gestiona el inventario mundial de productos electrónicos tiene almacenes en dos continentes (América y Europa), cada continente tiene 3 sedes de almacenes, cada sede almacena 4 categorías (televisores, teléfonos, ordenadores y electrodomésticos) cada categoría tiene 5 modelos específicos y cada modelo tiene 10 lotes diferentes.
    // inventario[continente][sede][categoria][modelo][lote]
    int inventario[2][3][4][5][10];

    // Continentes:
    int america = 0;
    int europa = 1;

    // Sedes:
    int primera = 0;
    int segunda = 1;
    int tercera = 2;

    // Categorías: 
    int televisores = 0;
    int telefonos = 1;
    int ordenadores = 2;
    int electrodomesticos = 3;

    // En América, en la primera sede, en la categoría de televisores, el modelo 0, en el lote 0, hay 50 unidades:
    inventario[america][primera][televisores][0][0] = 50;
    printf("Unidades en América, primera sede, categoría televisiones, modelo 0 y lote 0: %d\n", inventario[america][primera][televisores][0][0]);
    // En Europa, en la segunda sede, en la categoría de teléfonos, el modelo 3, en el lote 2, hay 120 unidades:
    inventario[america][segunda][telefonos][3][2] = 120;
    printf("Unidades en Europa, segunda sede, categoría teléfonos, modelo 3 y lote 2: %d\n", inventario[america][segunda][telefonos][3][2]);
    // En América, en la tercera sede, en la categoría de electrodomésticos, el modelo 1, en el lote 7, hay 75 unidades:
    inventario[america][tercera][electrodomesticos][1][7] = 75;
    printf("Unidades en América, tercera sede, categoría electrodomésticos, modelo 1 y lote 7: %d\n", inventario[america][tercera][electrodomesticos][1][7]);
    // En América, en la segunda sede, en la categoría de ordenadores, el modelo 0, en el lote 4, hay 150 unidades:
    inventario[america][segunda][ordenadores][0][4] = 150;
    printf("Unidades en América, segunda sede, categoría ordenadores, modelo 0 y lote 4: %d\n", inventario[america][segunda][ordenadores][0][4]);
    // En Europa, en la tercera sede, en la categoría de televisores, el modelo 3, en el lote 3, hay 30 unidades:
    inventario[europa][tercera][televisores][3][3] = 30;
    printf("Unidades en Europa, tercera sede, categoría televisiones, modelo 3 y lote 3: %d\n", inventario[europa][tercera][televisores][3][3]);
    // En Europa, en la primera sede, en la categoría de ordenadores, el modelo 5, en el lote 8, hay 100 unidades:
    inventario[europa][primera][ordenadores][5][8] = 100;
    printf("Unidades en Europa, primera sede, categoría ordenadores, modelo 5 y lote 8: %d\n", inventario[europa][primera][ordenadores][5][8]);
    return 0;
}

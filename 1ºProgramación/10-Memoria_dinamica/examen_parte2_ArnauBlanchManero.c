#include <stdio.h>
#include <stdlib.h>

void modificar_elemento(int valor);
void modificar_por_referencia(int *valor);

int main(){
    // Declaración de variables
    int n, comprobacion, numeros;
    int * array_enteros;
    // Pedimos al usuario los datos necesarios
    printf("Determina el tamaño del array de enteros: ");
    comprobacion = scanf("%d", &n);
    if (comprobacion == 0){
        printf("ERROR. Tienes que escribir un número\n");
        return 1;
    }
    // Reservamos la memoria necesaria
    array_enteros = (int *) malloc(n * sizeof(int));
    if (array_enteros == NULL){
        printf("ERROR.\n");
        return 1;
    }
    // Rellenamos el array con los números que le pedimos al usuario
    for (int i = 0; i < n; i++){
        numeros = 0;
        printf("Escribe el número para la posición %d: ", i+1);
        comprobacion = scanf(" %d", &numeros);
        if (comprobacion == 0){
            printf("ERROR. Tienes que escribir un número\n");
            free (array_enteros);
            return 1;
        }
        array_enteros[i] = numeros;
    }
    printf("\n");
    // Cambiamos un número para ver la diferencia entre paso por valor y paso por referencia
    printf("Voy a cambiar el último número por valor\n");
    modificar_elemento(array_enteros[n-1]);
    // Muestro lo que contiene el array para ver si ha cambiado algo
    printf("\tDesde el main, se han quedado estos números: ");
    for(int i = 0; i < n; i++){
        printf("%d ", array_enteros[i]);
    }
    printf("\n\n");
    printf("Voy a cambiar el último número por referencia\n");
    modificar_por_referencia(&array_enteros[n-1]);
    // Muestro lo que contiene el array para ver si ha cambiado algo
    printf("\tDesde el main, se han quedado estos números: ");
    for(int i = 0; i < n; i++){
        printf("%d ", array_enteros[i]);
    }
    printf("\n");
    // Liberamos la memoria que hemos reservado
    free (array_enteros);
    return 0;
}

// Esta función crea una copia del valor original y lo modifica
void modificar_elemento(int valor){
    printf("\tEstoy sumando 10 al valor original\n");
    printf("\tValor antiguo: %d\n", valor);
    valor = valor + 10;
    printf("\tNuevo valor: %d\n", valor);
}
// Esta función accede al contenido de la dirección de memoria donde se encuentra el valor y lo modifica
void modificar_por_referencia(int *valor){
    printf("\tEstoy sumando 10 al valor original\n");
    printf("\tValor antiguo: %d\n", *valor);
    *valor = *valor + 10;
    printf("\tNuevo valor: %d\n", *valor);
}

/* Preguntas:

    - Explica lo que pasa:
    Reservo un tamaño adecuado para guardar la cantidad de números que quiera el usuario.
    Relleno el array con los números que me diga el usuario.
    Cambio el último número de dos formas.
    1. Paso por valor. La función modificar_elemento crea una copia del número y lo cambia pero cuando acaba la función, el cambio que se ha hecho en la copia se libera.
    2. Paso por referencia. La función modificar_por_referencia crea una copia de la dirección de memoria del número que voy a cambiar accediendo al contenido de esa dirección de memoria y que cuando acabe la función, se libera la copia de la dirección de memoria pero como el número que he cambiado sigue estando en el mismo sitio, cuando acceda desde el main sí que se podrán ver los cambios.
    Muestro los números que hay en el array desde el main.

    - ¿Cuánto espacio ocupa un array de n elementos en memoria si cada elemento es de tipo double?¿Cómo podemos calcuarlo con sizeof()?
    Un número de tipo double ocupa un total de 8 bytes por lo que n elementos de un array ocupan n*8 bytes.
    Si queremos calcularlo con sizeof(), escibiremos n*sizeof(double).
*/
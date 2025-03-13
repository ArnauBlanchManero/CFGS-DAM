#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char palabra[5][20];
    int tiene;
    printf("Escribe una lista de palabras:\n");
    for(int i = 0; i < 5; i++){ // Pido que el usuario escriba 5 palabras
        printf("- ");
        scanf(" %s", palabra[i]);
    }
    printf("Ahora voy a imprimir las palabras que no tienen la letra 'a'\n");
    for(int i = 0; i < 5; i++){
    tiene = 0; // Es importante darle el valor 0 dentro del bucle para que en cada palabra diferente se resetee
        for(int j = 0; j < strlen(palabra[i]); j++){ //Este bucle se repetirá tantas veces como letras tenga la palabra
            if(palabra[i][j] == 'a'){
                tiene = 1; // Sólo se igualará a 1 si la palabra contiene la letra a
                continue;
            }
        }
        if(tiene == 0) // Si antes no se ha igualado a 1 significa que no tiene a
            printf("- %s\n", palabra[i]);
    }
    return 0;
}

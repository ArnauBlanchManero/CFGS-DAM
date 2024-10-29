#include <stdio.h>
#include <stdlib.h>

int main(){
  char caracter;
  printf("Introduce un número o una letra");
  scanf("%c", &caracter);
  if (caracter > 64 && caracter < 91 || caracter > 96 && caracter < 123){
    printf("El caracter %c es una letra", caracter);
  } else if (caracter > 47 && caracter < 58){
    printf("El caracter %c es un número", caracter);
  } else {
    printf("El caracter %c es un símbolo", caracter);
  }
  return 0;
}

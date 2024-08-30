#include <stdio.h>
#include "lista.h"

int main(void) {
  tlista l;
  int num;
  inicialista(&l);
  for(int i=0;i<5;i++){
    printf("Digite o dado:");
    scanf("%d",&num);
    if(!inserir(&l,num))
      return 0;
  }
  elementos(l);
  remover(&l,3);
  elementos(l);
  return 0;
}
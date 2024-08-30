#include <stdio.h>
#include "lista.h"
int main(void) {
  tlista l;
  int n[3];
  inicialista(&l);
  for(int i=0;i<3;i++)
    scanf("%d",&n[i]);
  for(int i=0;i<3;i++)
    insere(&l,n[i]);
  imprimircres(l);
  imprimirdec(l);
  remover(&l,n[1]);
  imprimircres(l);
  imprimirdec(l);
  return 0;
}
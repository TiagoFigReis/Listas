#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(void) {
  tlista l;
  int n;
  inicialista (&l);
  for (int i = 0; i < 5; i++){
   printf ("Digite o dado:");
    scanf ("%d", &n);
    inserirlista (&l, n);
  }
  imprimirlistaCrescente(l);
  imprimirlistaDecrescente(l);
  removerlista(&l,5);
  imprimirlistaCrescente(l);
  removerlista(&l,4);
  imprimirlistaCrescente(l);
  removerlista(&l,3);
  imprimirlistaCrescente(l);
  removerlista(&l,7);
  imprimirlistaCrescente(l);
  removerlista(&l,9);
  imprimirlistaCrescente(l);
  removerlista(&l,8);
  imprimirlistaCrescente(l);
  removerlista(&l,8);
  imprimirlistaCrescente(l);
}
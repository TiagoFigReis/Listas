#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  tlista l;
  int n, total, soldado = 1;
  inicialista (&l);
  scanf ("%d %d", &total, &n);
  for (int i = 1 ; i <= total; i++)
  inserir(&l, i);
   return 0;
  }

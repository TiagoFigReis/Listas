#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void inicialista (tlista *l){
 l->fim = NULL;
 return;
}

int inserirlista (tlista *l, int dado){
  tno *no, *aux;
  no = (tno*)malloc(sizeof(tno));
  if (!no)
    return 0;
  no->dado = dado;
  if (!l->fim){// lista vazia
   no->prox = no->ant = l->fim = no;
   return 1;
  }else if (dado > l->fim->dado){// novo fim
    no->prox = l->fim->prox;
    no->prox->ant = no;
    no->ant = l->fim;
    l->fim->prox = no;
    l->fim = no;
    return 1;
   }
  aux = l->fim->prox;
  while (aux != l->fim && aux->dado < dado)//inserção no começo ou no meio
    aux = aux->prox;
  aux->ant->prox = no;
  no->ant = aux->ant;
  no->prox = aux;
  aux->ant = no;
  return 1;
}

int removerlista (tlista *l, int dado){
  tno *aux;
  if (!l->fim){return 0;}
  if (l->fim->dado == dado){//remoçao do fim
    aux = l->fim;
   if (l->fim == l->fim->prox)// so um elemento
     l->fim = NULL;
    else {// mais de um elemento
    l->fim->ant->prox = l->fim->prox;
    l->fim->prox->ant = l->fim->ant;
    l->fim = l->fim->ant;
    }
    free (aux);
    return 1;
  }
  aux = l->fim->prox;
  while (aux != l->fim && aux->dado != dado)// remoçao do meio ou do começo
    aux = aux->prox;
  if (aux == l->fim)
    return 0;
  aux->ant->prox = aux->prox;
  aux->prox->ant = aux->ant;
  free (aux);
  return 1;
}

void imprimirlistaCrescente(tlista l) {
  tno *no;
  if (!l.fim) {
    printf("\nA lista está vazia.");
    return;
  }
  no = l.fim->prox;
  printf("\nA lista em ordem crescente é: ");
  do {
    printf("%d ", no->dado);
    no = no->prox;
  } while (no != l.fim->prox);
  return;
}
void imprimirlistaDecrescente(tlista l) {
  tno *no;
  if (!l.fim) {
    printf("\nA lista está vazia.");
    return;
  }
  no = l.fim;
  printf("\nA lista em ordem decrescente é: ");
  do {
    printf("%d ", no->dado);
    no = no->ant;
  } while (no != l.fim);
  return;
}
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void inicialista(tlista *l) {
  l->fim = NULL;
  return;
}

int inserir(tlista *l, int dado) {
  tno *no, *ant, *aux;
  no = (tno *)malloc(sizeof(tno));
  if (!no)
    return 0;
  no->dado = dado;
  if (!l->fim) {//lista vazia
    no->prox = no;
    l->fim = no;
    return 1;
  }
  if (dado > l->fim->dado) {//novo fim
    no->prox = l->fim->prox;
    l->fim->prox = no;
    l->fim = no;
    return 1;
  } //novo começo ou no meio da lista
  aux = l->fim->prox;//começo
  ant = l->fim;
  while (aux != l->fim && aux->dado < dado) {
    ant = aux;
    aux = aux->prox;
  }
    no->prox = aux;
    ant->prox = no;
  return 1;
}

int remover(tlista *l, int dado) {
  tno *aux, *ant;
  if (!l->fim)
    return 0;
  aux=l->fim->prox;
  ant = l->fim;
  if (l->fim->dado == dado) {// remoção do fim
    while (ant->prox != l->fim)
      ant = ant->prox;
    aux = l->fim;
    if (ant == l->fim) {// a lista tem so um elemento
      l->fim = NULL;
    }else {// tem mais de um elemento
      ant->prox = l->fim->prox;
      l->fim = ant;
    }
    free(aux);
    return 1;
  }
  while (aux != l->fim && aux->dado != dado) {
    ant = aux;
    aux = aux->prox;
  }
  if (aux == l->fim)
    return 0;
  ant->prox = aux->prox;
  free(aux);
  return 1;
}

void imprimir(tlista l) {
  tno *no;
  if (!l.fim) {
    printf("A lista está vazia.");
    return;
  }
  no = l.fim->prox;
  printf("A lista em ordem crescente é:\n");
  do {
    printf("%d ", no->dado);
    no = no->prox;
  } while (no != l.fim->prox);
  return;
}
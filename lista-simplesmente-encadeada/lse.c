#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void inicialista(tlista *l){
  l->com=NULL;
}
int inserir(tlista *l,int n){
  tno *no,*aux,*ant;
  no=(tno*)malloc(sizeof(tno));
  if(!no)
    return 0;
  no->dado=n;
  no->prox=NULL;
  aux=l->com;
  while(aux && aux->dado<n){
    ant=aux;
    aux=aux->prox;
  }
  if(aux==l->com){
    no->prox=aux;
    l->com=no;
  }else{
    ant->prox=no;
    no->prox=aux;
  }
  return 1;
}
int remover(tlista *l,int n){
  tno *aux,*ant;
  aux=l->com;
  if(!aux)
    return 0;
  while(aux && aux->dado!=n){
    ant=aux;
    aux=aux->prox;
  }
  if(aux){ 
    if(aux==l->com){
      l->com=aux->prox;
    }else{
      ant->prox=aux->prox;
    }
    free(aux);
    return 1;
  }
  return 0;
}
void elementos(tlista l){
  tno *aux;
  aux=l.com;
  if(!aux)
    return;
  while(aux){
    printf("%d\n",aux->dado);
    aux=aux->prox;
  }
}
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
void inicialista(tlista *l){
  l->com=NULL;
  l->fim=NULL;
}
int insere(tlista *l,int n){
  tno *no,*aux;
  no=(tno*)malloc(sizeof(tno));
  if(!no)
    return 0;
  no->dado=n;
  aux=l->com;
  if(!aux){// lista vazia
    no->ant=NULL;
    no->prox=NULL;
    l->com=no;
    l->fim=no;
    return 1;
  }
  while(aux && aux->dado < n){
    aux=aux->prox;
  }
  if(!aux){// inserção no fim
    no->ant=l->fim;
    no->prox=NULL;
    l->fim->prox=no;
    l->fim=no;
  }else if(aux ==l->com){// inserção no começo
    no->ant=NULL;
    no->prox=aux;
    aux->ant=no;
    l->com=no;
  }else{// inserção no meio 
    aux->ant->prox=no;
    no->ant=aux->ant;
    no->prox=aux;
    aux->ant=no;
  }
  return 1;
}
int remover(tlista *l,int n){
  tno *aux;
  aux=l->com;
  if(!aux)
    return 0;
  while(aux && aux->dado!=n)
    aux=aux->prox;
  if(aux){
    if(aux==l->com){// retirar o começo
      l->com=aux->prox;
      l->com->ant=NULL;
    }else{
      aux->ant->prox=aux->prox;
      if(aux->prox){// retirar no meio
        aux->prox->ant=aux->ant;
      }else{// retirar o fim
        l->fim=aux->ant;
      }
    }
    free (aux);
    return 1;
  }
  return 0;
}
void imprimircres(tlista l){
  tno *aux;
  aux=l.com;
  if(!aux){
    printf("Lista vazia\n");
    return;
  }
  while(aux){
    printf("%d\n",aux->dado);
    aux=aux->prox;
  }
}void imprimirdec(tlista l){
  tno *aux;
  aux=l.fim;
  while(aux){
    printf("%d\n",aux->dado);
    aux=aux->ant;
  }
}
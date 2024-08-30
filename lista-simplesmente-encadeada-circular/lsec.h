typedef struct no {
 int dado;
 struct no *prox;
}tno;

typedef struct lista {
 tno *fim;
}tlista;

void inicialista (tlista *l);
int inserir (tlista *l, int dado);
int remover (tlista *l, int dado);
void imprimir (tlista l);
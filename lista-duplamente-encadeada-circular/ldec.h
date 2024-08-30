typedef struct no {
 int dado;
struct no *prox;
struct no *ant;
}tno;

typedef struct lista {
 tno *fim;
}tlista;

void inicialista (tlista *l);
int inserirlista (tlista *l, int dado);
int removerlista (tlista *l, int dado);
void imprimirlistaCrescente (tlista l);
void imprimirlistaDecrescente (tlista l);
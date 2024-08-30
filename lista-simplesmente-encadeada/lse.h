typedef struct no{
int dado;
struct no *prox;
}tno;
typedef struct lista{
tno *com;
}tlista;
void inicialista(tlista *l);
int inserir(tlista *l,int n);
int remover (tlista *l,int n);
void elementos(tlista l);

typedef struct no{
int dado;
struct no *prox;
struct no *ant;
}tno;
typedef struct lista{
tno *com;
tno *fim;
}tlista;
void inicialista(tlista *l);
int insere(tlista *l,int n);
int remover(tlista *l,int n);
void imprimircres(tlista l);
void imprimirdec(tlista l);
//Arquivo LDED.h - Lista Dinamica Encadeada Dupla

#define FALSO      0
#define VERDADEIRO 1

#define OK         1
#define ERRO       0

typedef double  Tipo_Dado;

//Definição do tipo lista
struct elemento{
    struct elemento *ant;
    Tipo_Dado x;
    Tipo_Dado y;
    struct elemento *prox;
};

typedef struct elemento Elem;

typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int insere_lista_ordenada(Lista* li, Tipo_Dado x, Tipo_Dado y);
int reorganiza_lista(Lista* li);
void imprime_lista_especial(Lista* li, int questao);
void imprime_lista(Lista* li, int questao);

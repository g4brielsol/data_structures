//Arquivo LDED.h - Lista Dinamica Encadeada Dupla
#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#endif

#define FALSO      0
#define VERDADEIRO 1

#define OK         1
#define ERRO       0

typedef double  Tipo_Dado;
typedef int Tipo_tempo;

//Definição do tipo lista
struct elemento{
    struct elemento *ant;
    Tipo_Dado latitude;
    Tipo_Dado longitude;
    Tipo_tempo tempo;
    Tipo_Dado velocidade;
    Tipo_Dado distancia_percorrida;
    struct elemento *prox;
};

typedef struct elemento Elem;

typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
//int insere_lista_ordenada(Lista* li, Tipo_Dado x, Tipo_Dado y);
int insere_lista_final(Lista* li, Tipo_Dado latitude, Tipo_Dado longitude);
int radar(Lista* li, int posicao, double distancia, double velocidade);
//int reorganiza_lista(Lista* li);
//void imprime_lista_especial(Lista* li, int questao);
void imprime_lista(Lista* li);
double grauParaRadiano(double angulo);
double distancia(double latitude1, double longitude1,
                 double latitude2, double longitude2);

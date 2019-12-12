//  Arquivo ArvBinaria.h

#define USER_SIZE 10000

typedef int Tipo_int;
typedef float Tipo_float;
typedef char Tipo_char;

//Definindo do tipo Arvore
struct NO{
    Tipo_char letra;
    Tipo_int indice;
    Tipo_char *frase;
    Tipo_char letra_pai;
    Tipo_int indice_pai;
    Tipo_char esq_dir;
    float teste_certeza;
    
    struct NO *esq;
    struct NO *dir;
    //struct NO *ant;
};

typedef struct NO NodoArvBin;
typedef struct NO *ArvBin;

ArvBin* cria_ArvBin();
void libera_NO(struct NO* no);
void libera_ArvBin(ArvBin *raiz);
void insere_raiz(ArvBin* raiz, Tipo_char letra_pass, Tipo_int indice_pass, Tipo_char *frase_pass, float numero);
void Procura_preOrdem_insere(ArvBin* raiz, Tipo_int tipo_no, Tipo_int indice_int, Tipo_char frase[100],
                             Tipo_int tipo_no_B, Tipo_int indice_int_2, int esq_dir, float tc);


NodoArvBin* consulta_raiz(NodoArvBin* atual, int valor);
void Procura_maior_confianca(NodoArvBin* atual, double *valor, Tipo_char *frase_final);


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
    Tipo_float teste_certeza;
    
    struct NO *esq;
    struct NO *dir;
    //struct NO *ant;
};

typedef struct NO NodoArvBin;
typedef struct NO *ArvBin;

ArvBin* cria_ArvBin();
char *get_no();
char *get_esq_dir();
void libera_ArvBin(ArvBin *raiz);
void Procura_preOrdem_insere(ArvBin* raiz, Tipo_int tipo_no, Tipo_int indice_int, Tipo_char frase[100],
                             Tipo_int tipo_no_B, Tipo_int indice_int_2, Tipo_char esq_dir, Tipo_float tc);
void insere_raiz(ArvBin* raiz, Tipo_char letra_pass, Tipo_int indice_pass, Tipo_char *frase_pass);
int insere_binario(ArvBin* raiz, char letra_pass, Tipo_int indice_pass, char frase_pass);
NodoArvBin* consulta_raiz(NodoArvBin* atual, int valor);
void Procura_maior_confianca(NodoArvBin* atual, Tipo_float *valor, Tipo_char *frase_final);

void print_binario(ArvBin *raiz, Tipo_float valor);
void print_numero(ArvBin *raiz, Tipo_float valor);

int remove_ArvBin(ArvBin *raiz, Tipo_int valor);
int estaVazia_ArvBin(ArvBin *raiz);
int altura_ArvBin(ArvBin *raiz);
int totalNO_ArvBin(ArvBin *raiz);
int consulta_ArvBin(ArvBin *raiz, Tipo_int valor);
void preOrdem_ArvBin(ArvBin *raiz);
void emOrdem_ArvBin(ArvBin *raiz);
void posOrdem_ArvBin(ArvBin *raiz);

// Funcoes Adicionais
void Procura_preOrdem_ArvBin(ArvBin *raiz, Tipo_char valor, int *achou);
void Exibe_emOrdem_ArvBin(ArvBin *raiz);


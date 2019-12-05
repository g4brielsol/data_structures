#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "ArvoreBinaria.h" //inclui os Prot�tipos


ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

char *get_no()
{
    char *no_arvore;
    no_arvore = (char*)malloc ( USER_SIZE * sizeof (char));
    scanf("%s", no_arvore);
    return(no_arvore);
}

char *get_esq_dir()
{
    char *escolha;
    escolha = (char*)malloc ( USER_SIZE * sizeof (char));
    scanf("%s", &escolha);
    return(escolha);
}
void libera_NO(struct NO* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada n0
    free(raiz);//libera a raiz
}

void insere_raiz(ArvBin* raiz, Tipo_char letra_pass, Tipo_int indice_pass, Tipo_char *frase_pass)
{    
    if(raiz == NULL)
        return;
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL)
        return;
        
    printf("ver constantes\n");
    novo->letra = letra_pass;
    novo->indice = indice_pass;
    novo->frase = frase_pass;
    novo->esq_dir = NULL;
    novo->letra_pai = 82;
    novo->indice_pai = 0;
    novo->dir = NULL;
    novo->esq = NULL;
    printf("constantes vistas\n");
    printf("letra ascii %c\n", novo->letra);
    printf("letra indice %d\n", novo->indice);
    printf("letra frase %s\n", novo->frase);

    if(*raiz == NULL)
    {
        printf("nova raiz\n");
        *raiz = novo;
    }
    else{
        
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while(atual != NULL)
        {
            ant = atual;
            if((novo->letra == atual->letra) && (novo->indice == atual->indice))
            {
                free(novo);
                return;//elemento j� existe
            }
        /*
            if(letra_ASCII > atual->indice)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if(letra_ASCII > ant->indice)
            ant->dir = novo;
        else
            ant->esq = novo;
        */
        }
    return;
    }
}

void Procura_preOrdem_insere(ArvBin* raiz, Tipo_int tipo_no, Tipo_int indice_int, Tipo_char *frase,
                             Tipo_int tipo_no_B, Tipo_int indice_int_2, Tipo_char esq_dir, Tipo_float tc)
{
    printf("Entrou procura\n");
    //char teste = achou;
    //printf("achou %s\n", achou);
    //printf("achou %d\n", *achou);
    // se achou for a letra V
    if(raiz == NULL)
    {
        return;
    }
    //  if (*achou == 86)
    //{
    //    return;
    //}

    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));

    novo->letra = tipo_no;
    novo->indice = indice_int;
    novo->frase = frase;      
    novo->letra_pai = tipo_no_B;
    novo->indice_pai = indice_int_2;
    novo->esq_dir = esq_dir;
    novo->teste_certeza = tc;
    novo->dir = NULL;
    novo->esq = NULL;
    printf("letra %c indice %d frase %s letra pai %c indice pai %d esq_dir %c tc %f\n", novo->letra, novo->indice,
           novo->frase, novo->letra_pai, novo->indice_pai, novo->esq_dir, novo->teste_certeza);
    //printf("letra %c\n", (*raiz)->letra);
    
    struct NO *atual;
    atual = *raiz;

    if(*raiz != NULL)
    {
        if ((novo->letra_pai == (*raiz)->letra) && (novo->indice_pai == (*raiz)->indice))
        {
            //achou = "V\0";
            printf("Achou: %d! \n",(*raiz)->indice);   // indice  Int
            if(novo->esq_dir == 69)
            {
                printf("Colocou no a esquerda\n");
                printf("\n");
                (*raiz)->esq = novo;
                return;
            }
            else if(novo->esq_dir == 68)
            {
                printf("Colocou no a direita\n");
                printf("\n");
                (*raiz)->dir = novo;
                return;
            }
        }
        // ja existe
        else if((novo->letra == (*raiz)->letra) && (novo->indice == (*raiz)->indice))
        {
            printf("No existente, retornar");
            return;
        }
        //printf("achou 2 %d\n", *achou);
        printf("Recursao a esquerda\n");
        Procura_preOrdem_insere(&((*raiz)->esq), novo->letra, novo->indice, novo->frase, novo->letra_pai, novo->indice_pai,
                                  novo->esq_dir, novo->teste_certeza);//, achou);
        printf("Recursao a direita\n");
        Procura_preOrdem_insere(&((*raiz)->dir), novo->letra, novo->indice, novo->frase, novo->letra_pai, novo->indice_pai,
                                  novo->esq_dir, novo->teste_certeza);//, achou);

    }
    return;
}

/*
int insere_ArvBin(ArvBin* raiz, Tipo_Dado valor){
    if(raiz == NULL)
        return 0;
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL)
        return 0;
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL)
        *raiz = novo;
    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor == atual->info){
                free(novo);
                return 0;//elemento já existe
            }

            if(valor > atual->info)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if(valor > ant->info)
            ant->dir = novo;
        else
            ant->esq = novo;
    }
    return 1;
}
*/
struct NO* remove_atual(struct NO* atual) {
    struct NO *no1, *no2;
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    // no2 � o n� anterior a r na ordem e-r-d
    // no1 � o pai de no2
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}
// http://www.ime.usp.br/~pf/algoritmos/aulas/binst.html
int remove_ArvBin(ArvBin *raiz, Tipo_int valor){
    if(raiz == NULL)
        return 0;
    struct NO* ant = NULL;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->indice){
            if(atual == *raiz)
                *raiz = remove_atual(atual);
            else{
                if(ant->dir == atual)
                    ant->dir = remove_atual(atual);
                else
                    ant->esq = remove_atual(atual);
            }
            return 1;
        }
        ant = atual;
        if(valor > atual->indice)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

int estaVazia_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

int totalNO_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = totalNO_ArvBin(&((*raiz)->esq));
    int alt_dir = totalNO_ArvBin(&((*raiz)->dir));
    return(alt_esq + alt_dir + 1);
}

int altura_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvBin(&((*raiz)->esq));
    int alt_dir = altura_ArvBin(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}

int consulta_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->indice){
            return 1;
        }
        if(valor > atual->indice)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

void preOrdem_ArvBin(ArvBin *raiz)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%d %s %s \n",(*raiz)->indice, (*raiz)->letra, (*raiz)->frase);          // Info � Int
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}

void emOrdem_ArvBin(ArvBin *raiz)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        emOrdem_ArvBin(&((*raiz)->esq));
        printf("%d\n",(*raiz)->indice);          // Info � Int
        emOrdem_ArvBin(&((*raiz)->dir));
    }
}

void posOrdem_ArvBin(ArvBin *raiz)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        posOrdem_ArvBin(&((*raiz)->esq));
        posOrdem_ArvBin(&((*raiz)->dir));
        printf("%d\n",(*raiz)->indice);         // Info � Int
    }
}

// Funcoes Adicionais de Arvore

void Procura_preOrdem_ArvBin(ArvBin *raiz, Tipo_char valor, int *achou)
{
    printf("achou %s\n", achou);
    printf("achou %d\n", *achou);
    printf("raiz %s\n", (*raiz)->letra);
    printf("raiz %d\n", (*raiz)->letra);
    if(raiz == NULL)
        return;
    if (*achou)
        return;
    if(*raiz != NULL)
    {
        if (valor == (*raiz)->letra)
        {
            printf("Achou: %d! \n",(*raiz)->letra);   // indice � Int
            *achou=1;
        }
        Procura_preOrdem_ArvBin(&((*raiz)->esq),valor,&achou);
        Procura_preOrdem_ArvBin(&((*raiz)->dir),valor,&achou);
    }
}

void Exibe_emOrdem_ArvBin(ArvBin *raiz)
{
    if(raiz == NULL)
        return;

    if(*raiz != NULL)
    {
        printf("Atual: %d - Vai para Esquerda \n",(*raiz)->indice);   // indice � Int
        Exibe_emOrdem_ArvBin(&((*raiz)->esq));
        printf("Dado : %d \n",(*raiz)->indice);
        printf("Atual: %d - Vai para Direita \n",(*raiz)->indice);    // indice � Int
        Exibe_emOrdem_ArvBin(&((*raiz)->dir));
        printf("Feito(%d) \n",(*raiz)->indice);                       // Info � Int
    }
    else
        printf("NULL\n");

}

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "ArvoreBinaria2.h" //inclui os Prot�tipos


ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
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
        
   // printf("ver constantes\n");
    novo->letra = letra_pass;
    novo->indice = indice_pass;
    novo->frase = (char*)malloc ( USER_SIZE * sizeof (char)); 
    strcpy(novo->frase, frase_pass);
    //strcpy(novo->esq_dir, 32);
    novo->letra_pai = 82;
    novo->indice_pai = 0;
    novo->dir = NULL;
    novo->esq = NULL;
    
    
   //novo->ant = NULL;
   
   
   // printf("constantes vistas\n");
   // printf("letra ascii %c\n", novo->letra);
   // printf("letra indice %d\n", novo->indice);
   // printf("letra frase %s\n", novo->frase);

    if(*raiz == NULL)
    {
        //printf("nova raiz\n");
        *raiz = novo;
    }
    else{
        
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while(atual != NULL)
        {
            ant = atual;
            // se for igual a raiz
            if((novo->letra == atual->letra) && (novo->indice == atual->indice))
            {
                free(novo);
                //free(frase_pass);
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
    //free(frase_pass);
    return;
    }
}

void Procura_preOrdem_insere(ArvBin* raiz, Tipo_int tipo_no, Tipo_int indice_int, Tipo_char *frase,
                             Tipo_int tipo_no_B, Tipo_int indice_int_2, Tipo_char esq_dir, Tipo_float tc)
{
    //printf("Entrou procura\n");
    if(raiz == NULL)
    {
        return;
    }

    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));

    novo->letra = tipo_no;
    novo->indice = indice_int;
    novo->frase = (char*)malloc ( USER_SIZE * sizeof (char)); 
    strcpy(novo->frase, frase);    
    novo->letra_pai = tipo_no_B;
    novo->indice_pai = indice_int_2;
    novo->esq_dir = esq_dir;
    novo->teste_certeza = tc;
    novo->dir = NULL;
    novo->esq = NULL;
    //printf("letra %c indice %d frase %s letra pai %c indice pai %d esq_dir %c tc %f\n", novo->letra, novo->indice,
    //       novo->frase, novo->letra_pai, novo->indice_pai, novo->esq_dir, novo->teste_certeza);

    if(*raiz != NULL)
    {
        // se achar o no pai
        if ((novo->letra_pai == (*raiz)->letra) && (novo->indice_pai == (*raiz)->indice))
        {
            //printf("Achou: %d! \n",(*raiz)->indice);   // indice  Int
            // Se for E
            if(novo->esq_dir == 69)
            {
            //    printf("Colocou no a esquerda\n");
            //    printf("\n");
                (*raiz)->esq = novo;
                return;
            }
            // Se for D
            else if(novo->esq_dir == 68)
            {
            //    printf("Colocou no a direita\n");
            //    printf("\n");
                (*raiz)->dir = novo;
                return;
            }
        }
        // Se o indice e a letra ja existem
        else if((novo->letra == (*raiz)->letra) && (novo->indice == (*raiz)->indice))
        {
        //    printf("No existente, retornou");
            return;
        }
        //printf("achou 2 %d\n", *achou);
       // printf("Recursao a esquerda\n");
        Procura_preOrdem_insere(&((*raiz)->esq), novo->letra, novo->indice, novo->frase, novo->letra_pai, novo->indice_pai,
                                  novo->esq_dir, novo->teste_certeza);
       // printf("Recursao a direita\n");
        Procura_preOrdem_insere(&((*raiz)->dir), novo->letra, novo->indice, novo->frase, novo->letra_pai, novo->indice_pai,
                                  novo->esq_dir, novo->teste_certeza);

    }
}

NodoArvBin* consulta_raiz(NodoArvBin* atual, int valor){
    if(atual == NULL)
        return (atual);
    //ArvBin* copia;
    //NO* atual;
    //copia = raiz;
    //while(atual != NULL){
    // se for V, vai pra esquerda
    //printf("ATUAL %c indice %d valor %d \n", atual->letra, atual->indice, valor);
    // se for V, vai pra esquerda
    if(valor == 86)
    {
    //    printf("entrou esquerda\n");
        atual = atual->esq;
        return (atual);
    }
    // se for F, vai pra direita
    else if(valor == 70)
    {
    //    printf("entrou direita\n");
        atual = atual->dir;
        return (atual);
    }
    //}
    //return (*raiz);
}

void Procura_maior_confianca(NodoArvBin* atual, Tipo_float *valor, Tipo_char *frase_final)
{
    //printf("frase %s\n", frase_final);
    if(atual == NULL)
    {
        //printf("frase null %s\n", frase_final);
    //    printf("retornou\n");
        return;
    }

    float tres_mil = 3000;
    //printf("letra %c indice %d valor %f \n", (*raiz)->letra, (*raiz)->indice, valor);
    //printf("raiz letra %c raiz indice %d raiz teste certeza %f valor %f \n", atual->letra, atual->indice, atual->teste_certeza, *valor);    
    
    if(atual != NULL)
    {
        if ((*valor < atual->teste_certeza) && (atual->teste_certeza < tres_mil))
        {
    //        printf("Entrou Mudanca\n");
            *valor = atual->teste_certeza;
            strcpy(frase_final, atual->frase);
    //        printf("%s\n", frase_final);
    //        printf("%f\n", *valor);
            return;
        }
        //printf("recursao a esquerda\n");
        Procura_maior_confianca(atual->dir, &(*valor), frase_final);
        Procura_maior_confianca(atual->esq, &(*valor), frase_final);
        //printf("recursao a direita\n");

    }
}

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
        //printf("%d %s %s \n",(*raiz)->indice, (*raiz)->letra, (*raiz)->frase);          // Info � Int
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
        //printf("%d\n",(*raiz)->indice);          // Info � Int
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
        //printf("%d\n",(*raiz)->indice);         // Info � Int
    }
}

// Funcoes Adicionais de Arvore
/*
void Procura_preOrdem_ArvBin(ArvBin *raiz, Tipo_char valor, int *achou)
{
    //printf("achou %s\n", achou);
    //printf("achou %d\n", *achou);
    //printf("raiz %s\n", (*raiz)->letra);
    //printf("raiz %d\n", (*raiz)->letra);
    if(raiz == NULL)
        return;
    if (*achou)
        return;
    if(*raiz != NULL)
    {
        if (valor == (*raiz)->letra)
        {
            //printf("Achou: %d! \n",(*raiz)->letra);   // indice � Int
            *achou=1;
        }
        Procura_preOrdem_ArvBin(&((*raiz)->esq),valor,&achou);
        Procura_preOrdem_ArvBin(&((*raiz)->dir),valor,&achou);
    }
}
*/
void Exibe_emOrdem_ArvBin(ArvBin *raiz)
{
    if(raiz == NULL)
        return;

    if(*raiz != NULL)
    {
        //printf("Atual: %d - Vai para Esquerda \n",(*raiz)->indice);   // indice � Int
        Exibe_emOrdem_ArvBin(&((*raiz)->esq));
        //printf("Dado : %d \n",(*raiz)->indice);
        //printf("Atual: %d - Vai para Direita \n",(*raiz)->indice);    // indice � Int
        Exibe_emOrdem_ArvBin(&((*raiz)->dir));
       // printf("Feito(%d) \n",(*raiz)->indice);                       // Info � Int
    }
    //else
        //printf("NULL\n");

}

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "ArvoreBinaria2.h" //inclui os Prot�tipos

// cria nova arvore
ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}
// libera no da raiz
void libera_NO(struct NO* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}
// libera a arvore
void libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada no
    free(raiz);//libera a raiz
}
// insere a raiz da arvore
void insere_raiz(ArvBin* raiz, Tipo_char letra_pass, Tipo_int indice_pass, Tipo_char *frase_pass, float numero)
{    
    if(raiz == NULL)
        return;
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL)
        return;
        
    novo->letra = letra_pass;
    novo->indice = indice_pass;
    novo->frase = (char*)malloc ( USER_SIZE * sizeof (char)); 
    strcpy(novo->frase, frase_pass);
    novo->teste_certeza = numero;
    novo->letra_pai = 82;
    novo->indice_pai = 0;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL)
    {
        *raiz = novo;
    }
    else
    {       
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while(atual != NULL)
        {
            ant = atual;
            // se for igual a raiz
            if((novo->letra == atual->letra) && (novo->indice == atual->indice))
            {
                free(novo);
                return;//elemento ja existe
            }
        }
    return;
    }
}
// insere o no na arvore
void Procura_preOrdem_insere(ArvBin* raiz, Tipo_int tipo_no, Tipo_int indice_int, Tipo_char *frase,
                             Tipo_int tipo_no_B, Tipo_int indice_int_2, int esq_dir, float tc)
{
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

    if(*raiz != NULL)
    {
        // se achar o no pai
        if ((novo->letra_pai == (*raiz)->letra) && (novo->indice_pai == (*raiz)->indice))
        {
            // Se for a letra E, coloca na esquerda
            if(novo->esq_dir == 69)
            {
                (*raiz)->esq = novo;
                return;
            }
            // Se for a letra D, coloca na direita
            else if(novo->esq_dir == 68)
            {
                (*raiz)->dir = novo;
                return;
            }
        }
        // Se o indice e a letra ja existem, retorna
        else if((novo->letra == (*raiz)->letra) && (novo->indice == (*raiz)->indice))
        {
            return;
        }
        // recursao a esquerda
        Procura_preOrdem_insere(&((*raiz)->esq), novo->letra, novo->indice, novo->frase, novo->letra_pai, novo->indice_pai,
                                  novo->esq_dir, novo->teste_certeza);
        // recursao a direita
        Procura_preOrdem_insere(&((*raiz)->dir), novo->letra, novo->indice, novo->frase, novo->letra_pai, novo->indice_pai,
                                  novo->esq_dir, novo->teste_certeza);

    }
}
// percorre a arvore de acordo com o valor e retorna o no
NodoArvBin* consulta_raiz(NodoArvBin* atual, int valor){
    if(atual == NULL)
        return (atual);
    // se for V, vai pra esquerda
    if(valor == 86)
    {
        atual = atual->esq;
        return (atual);
    }
    // se for F, vai pra direita
    else if(valor == 70)
    {
        atual = atual->dir;
        return (atual);
    }
}
// procura a maior confianca recursivamente a partir do no atual, altera a frase final se encontrar uma confianca maior
void Procura_maior_confianca(NodoArvBin* atual, double *valor, Tipo_char *frase_final)
{
    if(atual == NULL)
    {
        return;
    }
    double tres_mil = 3000;
    if(atual != NULL)
    {
        // se o valor da confianca atual for maior que o armazenado, muda o valor da confianca atual e a frase
        if ((*valor < atual->teste_certeza) && (atual->teste_certeza < tres_mil))
        {
            *valor = atual->teste_certeza;
            strcpy(frase_final, atual->frase);
        }
        // recursao a direita do no
        Procura_maior_confianca(atual->dir, &(*valor), frase_final);
        // recursao a esquerda do no
        Procura_maior_confianca(atual->esq, &(*valor), frase_final);
    }
}

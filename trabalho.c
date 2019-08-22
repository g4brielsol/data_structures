#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct frase{
    char string;
};

struct ponteiro{
    struct frase letra;
    struct ponteiro *prox;
};

typedef struct ponteiro* lista;
typedef struct ponteiro pont;

lista* cria_lista(){
    lista* li = (lista*) malloc(sizeof(lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(lista* li){
    if(li != NULL){
        pont* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int posicao_da_lista(lista* li, int pos, struct frase *le){
    if(li == NULL || pos <= 0)
        return 0;
    pont *no = *li;
    int i = 1;
    while(no != NULL && i < pos){
        no = no->prox;
        i++;
    }
    if(no == NULL)
        return 0;
    else{
        *le = no->letra;
        return i;
    }
}

int insere_lista_inicio(lista* li, struct frase le){
    if(li == NULL)
        return 0;
    pont* no;
    no = (pont*) malloc(sizeof(pont));
    if(no == NULL)
        return 0;
    no->letra = le;
    no->prox = (*li);
    *li = no;
    return 1;
}

int insere_lista_ordenada(lista* li, struct frase le){
    if(li == NULL)
        return 0;
    pont *no = (pont*) malloc(sizeof(pont));
    if(no == NULL)
        return 0;
    no->letra = le;
    if((*li) == NULL){//lista vazia: insere início
        no->prox = NULL;
        *li = no;
        return 1;
    }
    else{
        pont *ant, *atual = *li;
        while(atual != NULL && atual->letra < le.matricula){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){//insere início
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = atual;
            ant->prox = no;
        }
        return 1;
    }
}

int tamanho_lista(Lista* li){
    if(li == NULL)
        return 0;
    int cont = 0;
    pont* no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int main()
{
    printf("Digite 0 para encriptar, 1 para decriptar: ");
    int cripto;
    scanf("%d", &cripto);
    printf("Digite a mensagem: ");
    char mensagem[50];
    fgets(mensagem, 50, stdin);
    printf("mensagem: %s", mensagem);
}
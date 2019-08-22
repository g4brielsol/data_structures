#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct lista {
 char info;
 struct lista* prox;
};

typedef struct lista Lista;

// inicialização da lista: retorna uma lista vazia
Lista* criar (void)
{
    return NULL;
}

// insercao: retorna a lista atualizada 
Lista* inserir(Lista* proximo, char informacao)
{
    /*
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    //Lista* next
    novo->info = informacao;
    novo->prox = NULL;
    */
    Lista* novo = (Lista*) malloc(sizeof(Lista));

    if(proximo->prox == NULL){
    proximo->prox = novo;
    //printf("added at beginning\n");
    }

    else
    {
        //else loop through the list and find the last
        //node, insert next to it
        Lista* atual = proximo;
        while (1) 
        { // Change 2
            if(atual->prox == NULL)
            {
                atual->prox = novo;
                //printf("added later\n");
                break; // Change 3
            }
            atual = atual->prox;
        }   
    return novo;
    }
}

// percorrer: percorre os elementos
void percorrer(Lista* list)
{
    Lista* p; /* variável auxiliar para percorrer a lista */
    p = list;
    while(p != NULL)
        {
            printf("%c", p->info);// fazer alguma coisa;
            p = p->prox;
        }
}

int deslocamento(Lista* list)
{
    Lista* p; 
    int deslocamento = 0;
    for (p = list; p != NULL; p = p->prox)
    {
        deslocamento = deslocamento ^ p->info;
    }
    
    deslocamento = deslocamento % 26;
    return deslocamento;
}

void intervalos(Lista* list, int desloc, int *intervalo)
{
    Lista* p; /* variável auxiliar para percorrer a lista */
    int i = 0;
    for (p = list; p != NULL; p = p->prox)
    {
        *(intervalo+i) = (p->info - 97) ^ desloc;
        i++;
    }
}

Lista* insercao_nos(Lista* list_mens, Lista* list_chave, int *intervalo, int tamanho)
{
    Lista* pon_mens; 
    Lista* pon_chave;
    int contador_intervalo = 0, seletor_intervalo = 0;
    pon_chave = list_chave;
    for(pon_mens = list_mens; pon_mens != NULL; pon_mens = pon_mens->prox)
    {
        if(contador_intervalo >= *(intervalo+(seletor_intervalo % tamanho)))
        {
            pon_mens = inserir(pon_mens, pon_chave->info);
            contador_intervalo = 0;
            seletor_intervalo++;
            pon_chave = pon_chave->prox;
            if(pon_chave == NULL)
            {
                pon_chave = list_chave;
            }
        }
        contador_intervalo++;
    }
    return pon_mens;
}

// retira: retira elemento da lista */
Lista* retirar(Lista* lista, char caractere_retirado) 
{
    Lista* ant = NULL; /* ponteiro para elemento anterior */
    Lista* ponteiro = lista; /* ponteiro para percorrer a lista*/
    /* procura elemento na lista, guardando anterior */
    while (ponteiro != NULL && ponteiro->info != caractere_retirado)
    {
        ant = ponteiro;
        ponteiro = ponteiro->prox;
    }
    /* verifica se achou elemento */
    if (ponteiro == NULL)
    {
        return lista; /* não achou: retorna lista original */
    }
    /* retira elemento */
    if (ant == NULL) 
    {
        //retira elemento do inicio 
        lista = ponteiro->prox;
    }
    else 
    {
        // retira elemento do meio da lista
        ant->prox = ponteiro->prox;
    }
    free(ponteiro);
    return lista;
}

// faz um free em todos os nos da lista encadeada
void liberar (Lista* lista)
{
    Lista* p = lista;
    while (p != NULL) 
    {
        Lista* t = p->prox; // guarda referência para o próximo elemento
        free(p); // libera a memória apontada por p
        p = t; // faz p apontar para o próximo
    }
}


void main()
{
    printf("Digite 0 para encriptar, digite 1 para decriptar: ");
    int cripto;
    scanf("%d", &cripto);
    printf("Digite a mensagem: ");
    char mensagem[50];
    scanf("%s", &mensagem);
    printf("Digite a chave simetrica: ");
    char chave_simetrica[50];
    scanf("%s", &chave_simetrica);
    int i;
    
    Lista* lista_mensagem;
    lista_mensagem = criar();
    for(i=0; i < strlen(mensagem); i++)
    {
        printf("%c", mensagem[i]);
        lista_mensagem = inserir(lista_mensagem, mensagem[i]);
    }
    
    Lista* lista_chave_simetrica;
    lista_chave_simetrica = criar();
    int tamanho = 0;
    for(i=0; i < strlen(chave_simetrica); i++)
    {
        lista_chave_simetrica = inserir(lista_chave_simetrica, chave_simetrica[i]);
        tamanho += 1;
    }

    int desloc;
    desloc = deslocamento(lista_chave_simetrica);
    //printf("%d\n", desloc);
    int inter[tamanho];
    intervalos(lista_chave_simetrica, desloc, &inter);
    
    Lista* new;
    //new = insercao_nos( lista_mensagem, lista_chave_simetrica, &inter, tamanho);
    percorrer(lista_mensagem);
    /* for(i=0; i < tamanho; i++)
    {
        printf("%d\n", inter[i]);
    }*/
}
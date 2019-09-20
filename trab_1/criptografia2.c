#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct lista {
 char info;
 struct lista* prox;
};

typedef struct lista Lista;

// insercao: retorna a lista atualizada 
Lista* inserir(Lista* proximo, char informacao)
{
 Lista* novo = (Lista*) malloc(sizeof(Lista));
 novo->info = informacao;
 novo->prox = proximo;
 return novo;
}

// percorrer: percorre a lista printando os elementos
void percorrer(Lista* list)
{
    Lista* p = list;
    while(p != NULL)
    {
        printf("%c", p->info);
        p = p->prox;
    }
    printf("\n");
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
    // ler opreacao de encriptar ou decifrar
    int cripto;
    scanf("%d", &cripto);
    // ler mensagem
    char mensagem[10000], carac;
    int cont_str = 0;
    scanf("%s", mensagem);
    // ler chave
    char chave_simetrica[500];
    cont_str = 0;
    scanf("%s", chave_simetrica);

    Lista* lista_mensagem = (Lista*) malloc(sizeof(Lista));
    // insere o ultimo caractere da variavel mensagem na lista
    lista_mensagem->info = mensagem[strlen(mensagem) - 1];
    // ultima posicao na lista aponta para nulo
    lista_mensagem->prox = NULL;
    int i;
    //adiciona os caracteres de tras para frente, para a lista ficar em ordem
    for(i=strlen(mensagem) - 2; i >= 0; i--)
    {
        lista_mensagem = inserir(lista_mensagem, mensagem[i]);
    }
    
    //faz a lista encadeada com a chave
    Lista* lista_chave_simetrica = (Lista*) malloc(sizeof(Lista));
    lista_chave_simetrica->info = chave_simetrica[strlen(chave_simetrica) - 1]; 
    lista_chave_simetrica->prox = NULL;
    int tamanho_chave = 1;
    for(i=strlen(chave_simetrica) - 2; i >= 0 ; i--)
    {
        lista_chave_simetrica = inserir(lista_chave_simetrica, chave_simetrica[i]);
        tamanho_chave += 1;
    }

    //cria array com intervalos
    int *intervalos = (int*)malloc(sizeof(int) * tamanho_chave);
    int desloc;
    //calcula o deslocamento
    desloc = deslocamento(lista_chave_simetrica);

    // copia o inicio da lista encadeada da chave
    Lista* copia_chave = (Lista*) malloc(sizeof(Lista));
    copia_chave = lista_chave_simetrica;
    int j =0;
    // calcular intervalos encriptacao ou decriptacao
    while(copia_chave != NULL)
    {
      intervalos[j] = (copia_chave->info - 97) ^ desloc;
      copia_chave = copia_chave->prox;
      j += 1; 
    }

    // se for para fazer a criptografia
    if(cripto == 0)
    {
    
        int contador_intervalo = 2, seletor_intervalo = 0;
        Lista* copia_mens = lista_mensagem;
        Lista* copia_chave_1 = lista_chave_simetrica;
        // insere nos da chave na mensagem
        while(lista_mensagem != NULL)
        {
            lista_mensagem = lista_mensagem->prox;
            if(contador_intervalo >= intervalos[seletor_intervalo % tamanho_chave])
            {
                Lista* ponteiro = (Lista*) malloc(sizeof(Lista));
                ponteiro->info = copia_chave_1->info;
                ponteiro->prox = lista_mensagem->prox;
                lista_mensagem->prox = ponteiro;
                contador_intervalo = 0;
                seletor_intervalo += 1;
                copia_chave_1 = copia_chave_1->prox;
                lista_mensagem = lista_mensagem->prox;
                if(copia_chave_1 == NULL)
                {
                    copia_chave_1 = lista_chave_simetrica;
                }
            }
            contador_intervalo += 1;
        }

        // aplicacao da cifra de cesar: mudar as letras da mensagem + chave para finalizar a criptografia
        Lista* ponteiro_deslocamento_inicial = copia_mens;
        int tamanho_crypto = 0;
        while(copia_mens != NULL)
        {
            copia_mens->info = (((copia_mens->info - 97) + desloc) % 26) + 97;
            copia_mens = copia_mens->prox;
            desloc += 1;
            tamanho_crypto += 1;
        }
        // printa a saida da encriptacao
        printf("%ld\n", strlen(mensagem));
        printf("%d\n", tamanho_crypto);
        percorrer(ponteiro_deslocamento_inicial);
        // da um free nos espacos de memoria alocados dinamicamente
        liberar(copia_mens);
        liberar(ponteiro_deslocamento_inicial);
    }

    // se for para decriptar
    else
    {
        //aplicacao da cifra de cesar de modo reverso para decifrar a mensagem
        int aux_desloc = desloc;
        Lista* copia_mensagem = lista_mensagem;
        while(copia_mensagem != NULL)
        {
            int caractere = (copia_mensagem->info - 97) - (aux_desloc % 26);
            if (caractere < 0)
            {
                copia_mensagem->info = caractere + 26 + 97;
            }
            else
            {
                copia_mensagem->info = caractere + 97;
            }
            aux_desloc += 1;
            copia_mensagem = copia_mensagem->prox;
            
        }
        //remocao dos nos da chave que estao na mensagem original
        int contador_intervalo = 2, seletor_intervalo = 0;
        int tamanho_decrypto = 0;
        Lista* copia_mens = lista_mensagem;
        Lista* atual = NULL;
        while(copia_mens != NULL)
        {
            copia_mens = copia_mens->prox;
            if(contador_intervalo >= intervalos[seletor_intervalo % tamanho_chave])
            {
                atual = copia_mens;
                if(copia_mens->prox == NULL)
                {
                    copia_mens = NULL;
                    atual->prox = NULL;
                    tamanho_decrypto += 1;
                }
                else
                {
                    copia_mens = copia_mens->prox;
                    atual->prox = copia_mens->prox;   
                }
                contador_intervalo = 0;
                seletor_intervalo += 1;
            }
            contador_intervalo += 1;
            tamanho_decrypto += 1;
        }
        // printa a saida para a mensagem decifrada
        printf("%ld\n", strlen(mensagem));
        printf("%d\n", tamanho_decrypto);
        percorrer(lista_mensagem);
        // da um free nos espacos de memoria alocados dinamicamente
        liberar(copia_mensagem);
        liberar(copia_mens);        
    }
    // da um free nos espacos de memoria alocados dinamicamente
    free(intervalos);
    liberar(lista_mensagem);
    liberar(lista_chave_simetrica);
    liberar(copia_chave);
}
    
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

Lista* inserir_qqr_posicao(Lista* lista, Lista* no)
{
    Lista* ponteiro;
    ponteiro = (Lista*) malloc(sizeof(Lista));
    ponteiro->info = no;
    ponteiro->prox = lista->prox;
    lista->prox = ponteiro;
    return ponteiro;
}

// percorrer: percorre os elementos
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

    
    Lista* lista_chave_simetrica = (Lista*) malloc(sizeof(Lista));
    lista_chave_simetrica->info = chave_simetrica[strlen(chave_simetrica) - 1]; 
    lista_chave_simetrica->prox = NULL;
    int tamanho_chave = 1;
    for(i=strlen(chave_simetrica) - 2; i >= 0 ; i--)
    {
        lista_chave_simetrica = inserir(lista_chave_simetrica, chave_simetrica[i]);
        tamanho_chave += 1;
    }
    //percorrer(lista_chave_simetrica);
    int j =0;
    int intervalos[tamanho_chave];
    int desloc;
    desloc = deslocamento(lista_chave_simetrica);
    Lista* copia = (Lista*) malloc(sizeof(Lista));
    copia = lista_chave_simetrica;
    //printf("%d\n", tamanho_chave);
   //percorrer(copia);

   while(copia != NULL)
  {
      intervalos[j] = (copia->info - 97) ^ desloc;
      copia = copia->prox;
      j += 1; 
  }
  /*
  for(j=0; j<tamanho_chave; j++)
  {
      printf("%d\n", intervalos[j]);
  }
   */
    Lista* lista_mensagem = (Lista*) malloc(sizeof(Lista));
    // insere o ultimo caractere da variavel mensagem
    lista_mensagem->info = mensagem[strlen(mensagem) - 1];
    lista_mensagem->prox = NULL;
    // aponta para o null, fim da lista
    int tamanho_mensagem = 0;
    //adiciona os caracteres de tras para frente, para a lista ficar em ordem
    for(i=strlen(mensagem) - 2; i >= 0; i--)
    {
        //printf("%c", mensagem[i]);
        lista_mensagem = inserir(lista_mensagem, mensagem[i]);
        tamanho_mensagem += 1;
    }
    //percorrer(lista_mensagem);
    //Lista* copia_2 = lista_chave_simetrica; //(Lista*) malloc(sizeof(Lista));
    //copia_2 = lista_chave_simetrica;
    
    //Lista* copia_lista_mensagem = lista_mensagem; //(Lista*) malloc(sizeof(Lista));
    //copia_lista_mensagem = lista_mensagem; 
    int posicao=0, contador_nos=1;
    Lista* copia_mens = lista_mensagem;

    while(lista_mensagem != NULL)
    {
        lista_mensagem = lista_mensagem->prox;
        contador_nos += 1;
        //printf("%d", intervalos[posicao]);
        if(contador_nos == intervalos[posicao])
        {
            //lista_mensagem = inserir_qqr_posicao(lista_mensagem, lista_chave_simetrica);
            //lista_chave_simetrica = lista_chave_simetrica->prox;
            
            Lista* ponteiro = (Lista*) malloc(sizeof(Lista));
            ponteiro->info = lista_chave_simetrica->info;
            ponteiro->prox = lista_mensagem->prox;
            lista_mensagem->prox = ponteiro;
            lista_chave_simetrica = lista_chave_simetrica->prox;
            posicao += 1;
            contador_nos = -1;
        }
    }
    //percorrer(copia_mens);
    Lista* ponteiro_deslocamento = (Lista*) malloc(sizeof(Lista));
    Lista* ponteiro_deslocamento_inicial = copia_mens;
    while(copia_mens != NULL)
    {
        copia_mens->info = (((copia_mens->info - 97) + desloc) % 26) + 97;
        copia_mens = copia_mens->prox;
        desloc += 1;
        //ponteiro_deslocamento = ponteiro_deslocamento->prox; 
    }
    percorrer(ponteiro_deslocamento_inicial);


}
    
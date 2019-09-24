#include <stdio.h>
#include <stdlib.h>

#include "LDED.h" //inclui as chamadas de funcao

Lista* cria_lista()
{
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if (li != NULL)
        *li = NULL;
    return li;
}

void ler_data_inserir(Lista* li)
{
    FILE *Arq;
    double num_1, num_2;
    Arq=fopen("dados.txt","rt");
    while (!feof(Arq))
    {
        // le as duas cordenadas
        fscanf(Arq, "%lf", &num_1);
        fscanf(Arq, "%lf", &num_2);
        //insere as coordenadas de maneira ordenada
        insere_lista_ordenada(li, num_1, num_2);
    }
    fclose(Arq);
    return;
}

int insere_lista_ordenada(Lista* li, Tipo_Dado x, Tipo_Dado y)
{
    if (li == NULL)
        return ERRO;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL)
        return ERRO;
    // dados das corrdenadas
    no->x = x;
    no->y = y;
    if ((*li) == NULL)
	{  //lista vazia: insere inicio
        no->prox = NULL;
        no->ant = NULL;
        *li = no;
        return OK;
    }
    else{
        Elem *anterior, *atual = *li;
        while (atual != NULL && ((atual->x < x) && (atual->y < y)))
		{
            anterior = atual;
            atual = atual->prox;
        }
        if (atual == *li)
		{   //insere inicio
            no->ant = NULL;
            (*li)->ant = no;
            no->prox = (*li);
            *li = no;
        } else
		{
            no->prox = anterior->prox;
            no->ant = anterior;
            anterior->prox = no;
            if (atual != NULL)
                atual->ant = no;
        }
        return OK;
    }
}

void imprime_lista(Lista* li, int questao)
{
    Elem* no = *li;
    printf("----------QUESTAO %d----------\n", questao);
    if (li == NULL)
        return;
    // imprime as coordendas x e y
    while (no != NULL)
    {
        printf("Dado: X = %.3lf - Y =  %.3lf\n",no->x,no->y);
        no = no->prox;
    }
    free(no);
}

int reorganiza_lista(Lista* li)
{
    Elem *anterior, *atual = *li;
    anterior = atual;
    atual = atual->prox;
    while(atual != NULL)
    {
        // so atualiza o "anterior" quando a diferenca 
        // for mais de 0.5
        if((atual->x - anterior->x > 0.5))
        {
            anterior->prox = atual; 
            anterior = atual;    
        }
        // caso contrario avanca os nós
        atual = atual->prox;    
    }
    free(atual);
    return OK;
}

void imprime_lista_especial(Lista* li, int questao)
{
    Elem* no = *li;
    Elem* compare;
    printf("----------QUESTAO %d----------\n", questao);
    while(no != NULL)
    {
        // compare = ultimo elemento da lista na ultima iteracao do while
        compare = no;
        // no = NULL na ultima iteracao do while
        no = no->prox;
    }
    // no = penultimo elemento da lista
    no = compare->ant;
    while(compare != NULL)
    {
        // se o compare for o ultimo ou o primeiro elemento da lista entra no if
        if(compare->prox == NULL || compare->ant == NULL)
        {
            printf("Dado: X = %.3lf - Y =  %.3lf\n",compare->x,compare->y);
        }
        // se a diferenca do compare para seu elemento anterior for menor que 0.5 entra no else if
        else if(compare->x - no->x <= 0.5)
        {
            printf("PULOU NODO => Dado: X = %.3lf - Y =  %.3lf\n",compare->x,compare->y);
        }
        // se a diferenca for maior que 0.5, entra no else
        else
        {
            printf("Dado: X = %.3lf - Y =  %.3lf\n",compare->x,compare->y);
        }
        // compare = seu elemento anterior da lista
        compare = no;
        if(compare == NULL)
        {
            // se o compare for null, nao existe "no" anterior
            continue;
        }
        else
        {
            //pega o anterior do "no" ja que ele existe
            no = no->ant;
        }
    }
    free(no);
    free(compare);
}
 
void libera_lista(Lista* li)
{
    if (li != NULL)
	{
        Elem* no;
        while ((*li) != NULL)
		{
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}
// a parte boa é que eu aprendi bastante resolvendo pelo computador
// a parte ruim foi ver a quantidade de coisas que eu errei :(

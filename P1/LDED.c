#include <stdio.h>
#include <stdlib.h>

#include "LDED.h" //inclui os Protitipos

Lista* cria_lista()
{
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if (li != NULL)
        *li = NULL;
    return li;
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

int insere_lista_ordenada(Lista* li, Tipo_Dado x, Tipo_Dado y)
{
    if (li == NULL)
        return ERRO;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL)
        return ERRO;
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

int reorganiza_lista(Lista* li)
{
    Elem *anterior, *atual = *li;
    anterior = atual;
    atual = atual->prox;
    while(atual != NULL)
    {
        if((atual->x - anterior->x > 0.5))
        {
            anterior->prox = atual; 
            anterior = atual;    
        }
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
        compare = no;// vai ate o ultimo elemento
        no = no->prox; // vai até o null
    }
    no = compare->ant; // penultimo elemento
    while(compare != NULL)
    {
        if(compare->prox == NULL || compare->ant == NULL)
        {
            printf("Dado: X = %.3lf - Y =  %.3lf\n",compare->x,compare->y);
        }
        else if(compare->x - no->x <= 0.5)
        {
            printf("PULOU NODO => Dado: X = %.3lf - Y =  %.3lf\n",compare->x,compare->y);
        }
        else
        {
            printf("Dado: X = %.3lf - Y =  %.3lf\n",compare->x,compare->y);
        }
        compare = no;
        if(compare == NULL)
        {
            continue;// se o compare for null, nao existe anterior do no
        }
        else
        {
            no = no->ant;//pega o anterior do "no" caso o "no" nao seja nulo
        }
    }
    free(no);
    free(compare);
}
 
void imprime_lista(Lista* li, int questao)
{
    Elem* no = *li;
    printf("----------QUESTAO %d----------\n", questao);
    if (li == NULL)
        return;
    while (no != NULL)
    {
        printf("Dado: X = %.3lf - Y =  %.3lf\n",no->x,no->y);
        no = no->prox;
    }
    free(no);
}

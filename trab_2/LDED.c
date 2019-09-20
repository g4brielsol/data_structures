#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int insere_lista_final(Lista* li, Tipo_Dado latitude, Tipo_Dado longitude)
{
    Elem *no;

    if (li == NULL) return ERRO;
    no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL)  return ERRO;
	
    no->latitude = latitude;
    no->longitude = longitude;
    no->prox = NULL;
    
	if ((*li) == NULL) 
	{   //lista vazia: insere início
        no->ant = NULL;
        no->tempo = 0;
        no->velocidade = 0;
        no->distancia_percorrida = 0;
        *li = no;
    }else
	{
        Elem *aux;
        aux = *li;
        while (aux->prox != NULL){
            aux = aux->prox;
        }
        no->tempo += aux->tempo + 1;
        no->distancia_percorrida = (aux->distancia_percorrida + distancia(aux->latitude, aux->longitude,
                                                                 no->latitude, no->longitude));
        no->velocidade = no->distancia_percorrida - aux->distancia_percorrida;
        aux->prox = no;
        no->ant = aux;
    }
    return OK;
}
int radar(Lista* li, int posicao, double distancia_limite, double velocidade_limite)
{
    Elem* no = *li;
    if (li == NULL)
        return ERRO;
    for(int i = 0; i < posicao; i++)
    {
        no = no->prox;
    }
    Elem* aux = no;
    while(fabs(aux->distancia_percorrida - no->distancia_percorrida) <= distancia_limite)
    {
        if( aux->velocidade > velocidade_limite)
        {
            ;// colocar maior velocidade aferida no limite
        }
    }

    free(no);
}
/* FUNCAO VAI SER USADA, ESTA COMENTADA PARA NAO DAR ERRO
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
*/

/* FUNCAO VAI SER USADA, ESTA COMENTADA PARA NAO DAR ERRO
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
*/
void imprime_lista(Lista* li)
{
    Elem* no = *li;
    if (li == NULL)
        return;
    while (no != NULL)
    {
        printf("%.6lf %.6lf %d %.6lf %.6lf\n",no->latitude,no->longitude,
               no->tempo, no->velocidade, no->distancia_percorrida);
        no = no->prox;
    }
    free(no);
}

double grauParaRadiano(double angulo)
{
    return (angulo * M_PI) / 180.0;
}

double distancia(double latitude1, double longitude1,
                 double latitude2, double longitude2)
{
    double diferencaLatitude = grauParaRadiano(latitude1 - latitude2);
    double diferencaLongitude = grauParaRadiano(longitude1 - longitude2);
    double a = pow(sin(diferencaLatitude / 2.0), 2.0) + cos(grauParaRadiano(latitude2)) *
               cos(grauParaRadiano(latitude1)) * pow(sin(diferencaLongitude / 2.0), 2.0);
    return 6378137.0 * (2.0 * atan2(sqrt(a), sqrt(1.0 - a)));
}

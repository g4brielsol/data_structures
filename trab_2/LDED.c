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
    if(posicao)
    for(int i = 0; i < posicao; i++)
    {
        no = no->prox;
    }
    Elem* aux = no;
    double velo_maxima = 0;
    
    while(fabs(aux->distancia_percorrida - no->distancia_percorrida) <= distancia_limite && (aux->ant != NULL))
    {
        if((aux->velocidade > velocidade_limite) && (aux->velocidade >= velo_maxima))
        {
            velo_maxima = aux->velocidade;
        }
        aux = aux->ant;
    }
    aux = no;
    while(fabs(aux->distancia_percorrida - no->distancia_percorrida) <= distancia_limite && (aux->prox != NULL))
    {
        if((aux->velocidade > velocidade_limite) && (aux->velocidade >= velo_maxima))
        {
            velo_maxima = aux->velocidade;
        }
        aux = aux->prox;
    }
    if(velo_maxima > velocidade_limite)
    {
        printf("autuado\n");
        printf("%.6lf\n", velo_maxima);
    }
    else
    {
        printf("liberado\n");
    }
    free(no);
    free(aux);
    return OK;
}
int remocao_gps(Lista* li, double distancia_limite)
{
    Elem *compare = *li;
    Elem *aux = *li;
    while(compare->prox != NULL)
    {
        // compare = ultimo elemento da lista na ultima iteracao do while
        compare = compare->prox;
    }

    Elem *inicio = aux;
    Elem *fim = compare;
    // divisao para ver se havera encontrao entre os dois nos
    int divisao = compare->distancia_percorrida / 2;
    // se nao houver encontrao entre os dois lados da lista
    if(distancia_limite < divisao)
    {
        double esquerdo = 0, direito = 0;
        // enquanto a distancia entre os dois nos for maior que a distancia passada pelo usuario
        while(fabs(aux->distancia_percorrida - compare->distancia_percorrida) > distancia_limite)
        {   //enquanto o esquerdo for menor ou igual ao o direito, aux avanca pra frente
            if(esquerdo <= direito)
            {
                aux = aux->prox;
                esquerdo += fabs(aux->distancia_percorrida - (aux->ant)->distancia_percorrida);
            }
            // se o direito for menor, compare avanca pra tras
            else
            {
                compare = compare->ant;
                direito += fabs(compare->distancia_percorrida - (compare->prox)->distancia_percorrida);
            }
            // se a distancia do aux->prox até o início for maior que o limite,
            //  exclui todos elementos entre o aux atual e o inicio
            if(fabs((aux->prox)->distancia_percorrida) - inicio->distancia_percorrida > distancia_limite)
            {
                //printf("entrou aux\n");
                aux->ant = inicio;
                inicio->prox = aux;
                inicio = aux;
            }
            else
            {
                ;
            }
            // se a distancia do compara->ant até fim for maior que o limite, exclui 
            // todos elementos entre o compare atual e o fim
            if(fabs((compare->ant)->distancia_percorrida - fim->distancia_percorrida) > distancia_limite)
            {
                compare->prox = fim;
                fim->ant = compare;
                fim = compare;
            }
            else
            {
                ;
            }
        }
        // aponta o aux para o compare e o compare para o aux
        aux->prox = compare;
        compare->ant = aux; 
    }
    // caso haja encontrao entre os dois nos
    else
    {
        // faz o aux ser igual ao compare
        while(aux != compare)
        {
            aux = aux->prox;
            compare = compare->ant;
        }
        inicio->prox = aux;
        aux->ant = inicio;
        aux->prox = fim;
        fim->ant = aux;
    }
    free(aux);
    free(compare);
    free(inicio);
    free(fim);
    return OK;
}

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

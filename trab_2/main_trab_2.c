#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "LDED.h"

void ler_data_inserir(Lista* li)
{
    int quantidade_de_dados;
    scanf("%d", &quantidade_de_dados);
    double num_1, num_2;
 
    for(int i = 0; i < quantidade_de_dados; i++)
    {
        scanf("%lf %lf", &num_1, &num_2);
        
        insere_lista_final(li, num_1, num_2);
    }
    return;
}

void funcao_decisao(Lista* li, int decisao)
{
    if(decisao == 0)
    {
        imprime_lista(li);
    }

    else if(decisao == 1)
    {
        int posicao, distancia, velocidade;
        scanf("%d", posicao);
        scanf("%d", distancia);
        scanf("%d", velocidade);
        radar(li, posicao, distancia, velocidade);
    }
    /*
    else if(decisao == 2)
    {

    }
    else
    {
        ;
    }
    */
}

void main()
{
    Lista *li = cria_lista();
    ler_data_inserir(li);
    int decisao;
    scanf("%d", &decisao);
    funcao_decisao(li, decisao);
    //reorganiza_lista(li);
    //imprime_lista(li, 5);
    //imprime_lista_especial(li, 6);
    libera_lista(li);
}
    
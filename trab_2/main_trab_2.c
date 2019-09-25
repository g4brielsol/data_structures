#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "LDED.h"
// pega os dados digitados pelo usuario e faz a LDED
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
// verifica e executa a funcao digitada pelo usuario: 0, 1 ou 2
void funcao_decisao(Lista* li)
{
    int decisao;
    // scaneia a decisao do usuario: 0, 1 ou 2
    scanf("%d", &decisao);
    
    if(decisao == 0)
    {
        // imprime as coordenadas, tempo, velocidade e distancia percorrida
        imprime_lista(li);
    }

    else if(decisao == 1)
    {
        double posicao, distancia, velocidade;
        scanf("%lf", &posicao);
        scanf("%lf", &distancia);
        scanf("%lf", &velocidade);
        radar(li, posicao, distancia, velocidade);
    }
    
    else if(decisao == 2)
    {
        double distancia;
        scanf("%lf", &distancia);
        remocao_gps(li, distancia);
        imprime_lista(li);
    }
    else
    {
        ;
    }
    return;
}

void main()
{
    Lista *li = cria_lista();
    ler_data_inserir(li);
    funcao_decisao(li);
    libera_lista(li);
}
    
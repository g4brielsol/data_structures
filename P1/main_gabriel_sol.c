#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "LDED.h"

void ler_data_inserir(Lista* li)
{
    FILE *Arq;
    double num_1, num_2;
    Arq=fopen("dados.txt","rt");
    while (!feof(Arq))
    {
        fscanf(Arq, "%lf", &num_1);
        fscanf(Arq, "%lf", &num_2);
        insere_lista_ordenada(li, num_1, num_2);
    }
    fclose(Arq);
    return;
}

void main()
{
    Lista *li = cria_lista();
    ler_data_inserir(li);
    imprime_lista(li, 3);
    reorganiza_lista(li);
    imprime_lista(li, 5);
    imprime_lista_especial(li, 6);
    libera_lista(li);
}
    
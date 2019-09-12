#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "LDED.h"

void ler_data()
{
    FILE *Arq;
    char linha[256];
    char numero[30];
    char *pos;
    double num;
    int i=0;
    Arq=fopen("dados.txt","rt");
    // for (i=0; i < 360; i++)
    while (!feof(Arq))
    {
        for(int j=0; j<2; j++)
        {
            fscanf(Arq, "%lf", &num);
            printf(" %lf", num);
        }
        printf("\n");
        i++;
    }
    fclose(Arq);
}

void main()
{
    printf("foi");
    ler_data();
}
    
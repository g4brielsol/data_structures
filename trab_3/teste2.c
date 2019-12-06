#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

void main()
{
    int entradas;
    char salario_string[100];
    float salario_float;
    char linha[100], info[100];
    
    scanf("%d", &entradas);
    scanf(" %[^\n]s", linha);

    printf("%d", entradas);

    for(int j = 0; j < entradas; ++j)
    {
        for(int k = 0; k < strlen(linha); ++k)
        {
            printf("%c", linha[k]);
            // Se for igual a F ou V
            if((linha[k] == 70) || (linha[k] == 86))
            {
                strncpy(info, linha[k], 1);
            }
            // Se nao for espaco ou a letra N -> vai ser numero
            else if((linha[k] != 32) || (linha[k] != 78))
            {
                strncpy(salario_string, linha[k], 1);
            }
        }
        printf("%s", info);
        printf("%s", salario_string);
    }
}



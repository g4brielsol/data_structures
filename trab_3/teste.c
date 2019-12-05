#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"
#define USER_SIZE 10
void chamar_funcao(char teste[4], char tipo[2], char frase[])
{
    printf("indice: %s\n", teste);
    printf("tipo: %s\n", tipo);
    printf("frase: %s\n", frase);
}

char *get_no_nao_folha()
{
    char *no_nao_folha;
    no_nao_folha = (char*)malloc ( USER_SIZE * sizeof (char));
    scanf("%s", no_nao_folha);
    return(no_nao_folha);
}

void main()
{
    //char *no_nao_folha;
    char *frase, *no_pai;
    //no_nao_folha = (char*)malloc ( USER_SIZE * sizeof (char));
    frase = (char*)malloc ( USER_SIZE * sizeof (char));
    no_pai = (char*)malloc ( USER_SIZE * sizeof (char));
    //scanf("%s", no_nao_folha);
    char *no_nao_folha = get_no_nao_folha();
    scanf(" \"%[^\"]\"", frase);  
    //scanf("%s", no_pai);

    char tipo_no[2];
    strncpy(tipo_no, no_nao_folha, 1);
    tipo_no[1] = '\0';
    char indice_char[4];
    strncpy(indice_char, no_nao_folha+1, 3);
    indice_char[4] = '\0';
    int indice_string = atoi(indice_char);

    //printf("nome: %d\n", tipo_no[0]);
    //printf("indice: %i\n", indice_string);
 
    if(tipo_no[0] == 66)
    {
        chamar_funcao(indice_char, tipo_no, frase);
    }
    //printf("frase: %s\n", frase);
    //printf("frase: %s\n", no_pai);
}



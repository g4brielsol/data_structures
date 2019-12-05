#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"
#define USER_SIZE 10

void main()
{
    int contador = 0;
    // cria arvore
    ArvBin* arvore = cria_ArvBin();

    // quantos nos a arvore tera
    int quantos_nos;
    scanf("%d", &quantos_nos);

    // loop dos nos
    for(int i = 0; i < quantos_nos; i++)   
    { 
        // pega os 4 primeiros caracteres
        //char *nodo = get_no();
        char *nodo;
        nodo = (char*)malloc ( USER_SIZE * sizeof (char));
        scanf("%s", nodo);
        //return(no_arvore);
        // pega a primeira letra da entrada, B, N ou C
        char tipo_no[2];
        strncpy(tipo_no, nodo, 1);
        tipo_no[1] = '\0';
        
        // pega o primeiro indice XXX
        char indice_char[4];
        strncpy(indice_char, nodo +1, 3);
        indice_char[4] = '\0';
        int indice_int = atoi(indice_char);

        // le a frase
        //char frase[100];
        char *frase;
        frase = (char*)malloc ( USER_SIZE * sizeof (char));
        scanf(" \"%[^\"]\"", frase);
        //char frase_final[100];
        //strcpy(frase_final, frase);
        //char frase_final[] = *frase;
        //printf("frase final: %s\n", frase);

        // le quarta info
        char *nodo_2;// = get_no();
        nodo_2 = (char*)malloc ( USER_SIZE * sizeof (char));
        scanf("%s", nodo_2);

       // pega a segunda letra da entrada, B, N, C ou R. se for float seguira com if
        char tipo_no_2[2];
        strncpy(tipo_no_2, nodo_2, 1);
        tipo_no_2[1] = '\0';
        
        // pega o segundo indice XXX, se for float seguira com o if
        char indice_char_2[4];
        strncpy(indice_char_2, nodo_2 +1, 3);
        indice_char_2[4] = '\0';
        int indice_int_2 = atoi(indice_char_2);
/*
        printf("tipo_no %s\n", tipo_no);
        printf("indice %d\n", indice_int);
        printf("frase %s\n", frase);

        printf("tipo_no_2 %d\n", tipo_no_2[0]);
        printf("indice_2 %d\n", indice_int_2);
*/
        //se na quarta info se for R000 na tabela ASCII
        if(tipo_no_2[0] == 82)
        {       
            printf("Entrou R\n");
            printf("tipo_no %s\n", tipo_no);
            printf("indice %d\n", indice_int);
            printf("frase %s\n", frase);
            insere_raiz(arvore, tipo_no[0], indice_int, frase);
        }
        // se a quarta info tiver letra B
        else if(tipo_no_2[0] == 66)
        {
            scanf("Entrou B");
            // pega D ou E
            //char *B_esq_dir = get_esq_dir();
            char escolha;
            //escolha = (char*)malloc ( USER_SIZE * sizeof (char));
            scanf(" %c", &escolha);
            printf("%c\n", escolha);
            float tc;
            // Se for letra C
            if(tipo_no[0] == 67)
            {
                scanf("%f", &tc);
            }
            else
            {
                tc = -1;
            }
            //fflush(stdin);
            //return(escolha);
            //char *achou = 70;
            //int *achou;
            Procura_preOrdem_insere(arvore, tipo_no[0], indice_int, frase, tipo_no_2[0], indice_int_2, escolha, tc);//, &achou);
            //Procura_preOrdem_ArvBin(arvore, 66, &achou);
        }

        // testaaaaaaaaaaar no nnnnnnnnnnnnnnnnnnnnnnnn
        // fazer no c e prints


        // se a quarta info tiver letra N
        else if(tipo_no_2[0] == 78)
        {
            printf("Entrou N\n");
            char escolha;
            //escolha = (char*)malloc ( USER_SIZE * sizeof (char));
            scanf(" %c", &escolha);
            printf("%c\n", escolha);
            //return(escolha);
            //char *N_esq_dir = get_esq_dir();
            //char achou = 70;
            float tc_2;
            scanf("%f", &tc_2);
            Procura_preOrdem_insere(arvore, tipo_no[0], indice_int, frase, tipo_no_2[0], indice_int_2, escolha, tc_2);//, achou);
        }
        else
        {
            printf("Entrou Numero");
            char *nodo_3;
            nodo_3 = (char*)malloc ( USER_SIZE * sizeof (char));
            scanf("%s", nodo_3);
            
            // pega a segunda letra da entrada, B, N, C ou R. se for float seguira com if
            char tipo_no_3[2];
            strncpy(tipo_no_3, nodo_3, 1);
            tipo_no_3[1] = '\0';
            
            // pega o segundo indice XXX, se for float seguira com o if
            char indice_char_3[4];
            strncpy(indice_char_3, nodo_3 +1, 3);
            indice_char_3[4] = '\0';
            int indice_int_3 = atoi(indice_char_3);

            char escolha;
            scanf(" %c", &escolha);
            printf("%c\n", escolha);
            float tc;
            tc = atof(nodo_2); // numero de teste
            Procura_preOrdem_insere(arvore, tipo_no[0], indice_int, frase, tipo_no_3[0], indice_int_3, escolha, tc);
            free(nodo_3);
        }
        free(nodo);
        //free(frase);
        free(nodo_2);
    }
                
        //char *no_pai;
        //no_pai = (char*)malloc ( USER_SIZE * sizeof (char));
        //preOrdem_ArvBin(arvore);
        //scanf("%s", no_pai);

        //printf("letra: %s", tipo_no);
        //printf("letra: %d", indice_int);
}

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "ArvoreBinaria2.h"

void main()
{
    int contador = 0;
    // cria arvore
    ArvBin* arvore = cria_ArvBin();

    // quantos nos a arvore tera
    int quantos_nos;
    scanf("%d", &quantos_nos);

    // loop dos nos
    for(int i = 0; i < quantos_nos; ++i)   
    { 
        printf("Comeco funcao\n");
        char frase_inicial[100];
        scanf(" %[^\n]s", frase_inicial);
        printf("%s\n", frase_inicial);

        //4 primeiros caracteres das letras e indices
        char *nodo, *nodo_2;
        nodo = (char*)malloc ( USER_SIZE * sizeof (char));
        nodo_2 = (char*)malloc ( USER_SIZE * sizeof (char));

        //letra da entrada, R, B, N ou C
        char tipo_no[2], tipo_no_2[2];
        
        //indice XXX
        char indice_char[4], indice_char_2[4];

        int chave_nodo_1 = 0, chave_nodo_2 = 0, chave_frase = 0, float_test = 0;

        for(int iteracao = 0; iteracao < strlen(frase_inicial); ++iteracao)
        {
            // se a da entrada for R, B, N ou C e o nodo 1 nao tiver sido atualizado
            if( ((frase_inicial[iteracao] == 82) || (frase_inicial[iteracao] == 66) ||
               (frase_inicial[iteracao] == 67)|| (frase_inicial[iteracao] == 78) ) && chave_nodo_1 == 0)
            {
                chave_nodo_1 = 1;
                scanf("%s", nodo);
                // pega a primeira letra da entrada, R, B, N ou C
                strncpy(tipo_no, nodo, 1);
                // Faz o fim da frase ser igual a \0
                tipo_no[1] = '\0';
                
                // pega o primeiro indice XXX
                strncpy(indice_char, nodo +1, 3);
                // Faz o fim da frase ser igual a \0
                indice_char[4] = '\0';
                // trasnforma a string em int
                int indice_int = atoi(indice_char);
            }
            else if(frase_inicial[iteracao] == 34)
            {
                // FAZER FRASE
            }
            // se a da entrada for R, B, N ou C e o nodo 2 nao tiver sido atualizado
            else if(((frase_inicial[iteracao] == 82) || (frase_inicial[iteracao] == 66) ||
               (frase_inicial[iteracao] == 67)|| (frase_inicial[iteracao] == 78) ) && chave_nodo_2 == 0)
            {
                chave_nodo_2 = 1;
                scanf("%s", nodo_2);
                // pega a primeira letra da entrada, R, B, N ou C
                strncpy(tipo_no_2, nodo_2, 1);
                // Faz o fim da frase ser igual a \0
                tipo_no_2[1] = '\0';
                
                // pega o primeiro indice XXX
                strncpy(indice_char_2, nodo_2 +1, 3);
                // Faz o fim da frase ser igual a \0
                indice_char_2[4] = '\0';
                // trasnforma a string em int
                int indice_int_2 = atoi(indice_char_2);
            }
            
        }
    /*
        // pega os 4 primeiros caracteres
        char *nodo;
        nodo = (char*)malloc ( USER_SIZE * sizeof (char));
        scanf("%s", nodo);

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
        char *frase;
        frase = (char*)malloc ( USER_SIZE * sizeof (char));
        scanf(" \"%[^\"]\"", frase);

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

        //se na quarta info se for R000 na tabela ASCII
        if(tipo_no_2[0] == 82)
        {       
            printf("Entrou R\n");
            //printf("tipo_no %s\n", tipo_no);
            //printf("indice %d\n", indice_int);
            //printf("frase %s\n", frase);
            insere_raiz(arvore, tipo_no[0], indice_int, frase);
            printf("retorno raiz\n");
        }

        // se a quarta info tiver letra B
        else if(tipo_no_2[0] == 66)
        {
            printf("Entrou B\n");

            // pega D ou E
            char escolha;
            //escolha = (char*)malloc ( USER_SIZE * sizeof (char));
            scanf(" %c", &escolha);
            //printf("%c\n", escolha);
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

            Procura_preOrdem_insere(arvore, tipo_no[0], indice_int, frase, tipo_no_2[0], indice_int_2, escolha, tc);
            printf("retorno insere letra B\n");
        }

        // se a quarta info tiver letra N
        else if(tipo_no_2[0] == 78)
        {
           printf("Entrou N\n");

            char escolha;
            scanf(" %c", &escolha);
            //printf("%c\n", escolha);
            float tc_2;
            scanf("%f", &tc_2);
            Procura_preOrdem_insere(arvore, tipo_no[0], indice_int, frase, tipo_no_2[0], indice_int_2, escolha, tc_2);
            printf("retorno insere letra n\n");
        }
        // se o 4 item for numerico
        else
        {
            printf("Entrou Numero\n");
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
            
            // pega se for E ou D 
            char escolha;
            scanf(" %c", &escolha);
            printf("%c\n", escolha);

            // transforma o nodo_2 de char para float
            float tc;
            tc = atof(nodo_2); // numero de teste
            Procura_preOrdem_insere(arvore, tipo_no[0], indice_int, frase, tipo_no_3[0], indice_int_3, escolha, tc);
            printf("retorno insere numerico \n");
            //free(nodo_3);
        }


    free(nodo);
    free(frase);
    free(nodo_2);
*/


    }
    printf("entradas\n");
    int entradas;// = 1;
    char salario_string[100];
    float salario_float = -1;
    //char *linha; 
 
    scanf("%d", &entradas);
    printf("%d\n", entradas);
    //Elem* no = *li;
    
    for(int j = 0; j < entradas; ++j)
    {
        char linha[100];
        scanf(" %[^\n]s", linha);
        printf("%s\n", linha);

        //printf("digite V F\n");
        //ArvBin* copia = arvore;
        struct NO* atual = (*arvore);
        //ArvBin *copia = arvore;
        int chave = 0;
        for(int k = 0; k < strlen(linha); ++k)
        {
            printf("%c\n", linha[k]);
            // Se for igual a E
            if(linha[k] == 69)
            {
                printf("Entrou E\n");
            }
            // Se for igual a V
            else if(linha[k] == 86)
            {
                printf("Entrou V\n");
                atual = consulta_raiz(atual,  linha[k]);
            }
            // se for igual a F
            else if(linha[k] == 70)
            {
                printf("entrou F \n");
                atual = consulta_raiz(atual, linha[k]);
            }
            else if(linha[k] == 32)
            {
                printf("entrou SPACE \n");
            }
            // Se nao for espaco e a letra N: vai ser numero
            else if((linha[k] != 32) && (linha[k] != 78) && chave == 0)
            {
                chave = 1;
                printf("entrou Numero\n");
                int tamanho_restante = strlen(linha) - k;
                int fim_caractere = tamanho_restante + 1;
                strncpy(salario_string, linha + k, tamanho_restante);
                salario_string[fim_caractere] = '\0';
                printf("salario %s\n", salario_string);
            //}
            // Se for a letra N: printa
            //else if (linha[k] == 78)
            //{
                //printf("entrou N e printa\n");
                salario_float = atof(salario_string);        
                //print_numero(copia, salario_float);//, (copia->frase);
                if(salario_float >= atual->teste_certeza && atual->teste_certeza > 3000)
                {
                    atual = atual->dir;
                }
                else if (salario_float < atual->teste_certeza && atual->teste_certeza > 3000)
                {
                    atual = atual->esq;
                }
            }
            // Se for a letra N
            if((linha[k] == 78))
            {
                printf("Entrou N\n");
                Tipo_float valor = -1;
                char *frase_n;
                frase_n = (char*)malloc ( USER_SIZE * sizeof (char));  
                //strcpy(frase_n, frase_final);
                Procura_maior_confianca(atual, &valor, frase_n);
                printf("final %s\n", frase_n);

            }
            // Se for o ultimo caractere
            else if(k == strlen(linha) - 1)
            {
                printf("entrou Printa\n");
                printf("final %s\n", atual->frase);
                //salario_float = atof(salario_string);
                //print_binario(copia, salario_float);//, (*copia)->frase);    
            }
            printf("ARVORE letra %c indice %d valor %f \n", (*arvore)->letra, (*arvore)->indice, (*arvore)->teste_certeza);
        }
    }

}

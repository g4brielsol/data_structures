#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "ArvoreBinaria2.h"

void main()
{
    // cria arvore
    ArvBin* arvore = cria_ArvBin();

    // quantos nos a arvore tera
    int quantos_nos;
    scanf("%d", &quantos_nos);

    // loop dos nos
    for(int i = 0; i < quantos_nos; ++i)   
    { 
        // leitura de toda a linha
        char sentenca[100];
        scanf(" %[^\n]s", sentenca);

        //criacao das variaveis que serao as letras + indices
        char *nodo, *nodo_2;
        nodo = (char*)malloc ( USER_SIZE * sizeof (char));
        nodo_2 = (char*)malloc ( USER_SIZE * sizeof (char));

        // variaveis que serao as letras da entrada: R, B, N ou C
        char tipo_no[2], tipo_no_2[2];
        
        //criacao dos indices XXX
        char *indice_char, *indice_char_2;//,  *esq_dir;
        indice_char = (char*)malloc ( USER_SIZE * sizeof (char));
        indice_char_2 = (char*)malloc ( USER_SIZE * sizeof (char));
        int indice_int, indice_int_2;

        // chaves que liberarao as leituras das respectivas partes da linha
        int chave_nodo_1 = 0, chave_nodo_2 = 1, chave_frase_1 = 0, chave_frase_2 = 0;
        int chave_float_1 = 1, chave_float_2 = 1, chave_esq_dir = 1;

        // variavel que armazenara a frase da linha
        char *frase;
        frase = (char*)malloc ( USER_SIZE * sizeof (char));

        // variavel que armazenara o float da linha
        char *string_float;
        string_float = (char*)malloc ( USER_SIZE * sizeof (char));
        
        float numero_float = 0;

        // variavel que armazenara as posicoes iniciais e finais das frases e floats
        int posicao_inicial_frase, posicao_final_frase, posicao_inicial_float, posicao_final_float;

        // variavel que armazenara o valor em ASCII de D ou E
        int esq_dir; 

        for(int iteracao = 0; iteracao < strlen(sentenca); iteracao++)
        {                    
            // se a da entrada for R, B, N ou C e o nodo 1 estiver liberado
            if( ((sentenca[iteracao] == 82) || (sentenca[iteracao] == 66) ||
            (sentenca[iteracao] == 67)|| (sentenca[iteracao] == 78) ) && chave_nodo_1 == 0)
            {                
                chave_nodo_1 = 1;
                // pega a primeira letra da entrada, R, B, N ou C
                strncpy(tipo_no, sentenca , 1);
                // Faz o fim da frase ser igual a \0
                tipo_no[1] = '\0';
                
                // pega o primeiro indice XXX
                strncpy(indice_char, sentenca + 1, 3);
                // transforma a string em float
                indice_int = atoi(indice_char);
                // pula os proximos 3 numeros para nao entrar na condicao do float
                iteracao += 3;
            }
            // pega o primeiro indice da frase
            else if((sentenca[iteracao] == 34) && (chave_frase_1 == 0))
            {
                chave_frase_1 = 1;
                posicao_inicial_frase = iteracao + 1;
            }
            // pega o fim da frase e a armazena em na variavel
            else if((sentenca[iteracao] == 34) && (chave_frase_2 == 0))
            {
                chave_frase_2 = 1;
                posicao_final_frase = iteracao - posicao_inicial_frase;
                strncpy(frase, sentenca + posicao_inicial_frase, posicao_final_frase);

                // libera a condicao do float, do nodo 2 e da direcao E ou D
                chave_float_1 = 0;
                chave_float_2 = 0;
                chave_nodo_2 = 0;
                chave_esq_dir = 0;
            }
            // se a da entrada for R, B, N ou C e o nodo 2 estiver liberado
            else if(((sentenca[iteracao] == 82) || (sentenca[iteracao] == 66) ||
            (sentenca[iteracao] == 67)|| (sentenca[iteracao] == 78) ) && chave_nodo_2 == 0)
            {
                chave_nodo_2 = 1;
                // pega a primeira letra da entrada, R, B, N ou C
                strncpy(tipo_no_2, sentenca + iteracao, 1);
                // Faz o fim da frase ser igual a \0
                tipo_no_2[1] = '\0';
                
                // pega o primeiro indice XXX
                strncpy(indice_char_2, sentenca + iteracao +1, 3);
                // trasnforma a string em int
                indice_int_2 = atoi(indice_char_2);
                // pula os proximos 3 numeros para nao entrar na condicao do float
                iteracao += 3;
            }
            // se for a letra D ou E
            else if(((sentenca[iteracao] == 68) || (sentenca[iteracao] == 69)) && chave_esq_dir == 0)
            {
                chave_esq_dir = 1;
                esq_dir = sentenca[iteracao];
            }
            // pega o primeiro indice do float
            else if((sentenca[iteracao] != 32) && (chave_float_1 == 0))
            {
                posicao_inicial_float = iteracao;
                chave_float_1 = 1;
            }
            // pega o fim do float
            else if(((strlen(sentenca) - 1 == iteracao) || (sentenca[iteracao] == 32))
                    && (chave_float_1 == 1) && chave_float_2 == 0)
            {
                chave_float_2 = 1;
                posicao_final_float = iteracao - posicao_inicial_float + 1;
                strncpy(string_float, sentenca + posicao_inicial_float, posicao_final_float);
                // trasnforma a string em float
                numero_float = atof(string_float);
                chave_float_2 = 1;     
            }
        }
        //se for a raiz (letra R em ASCII) 
        if(tipo_no_2[0] == 82)
        {       
            insere_raiz(arvore, tipo_no[0], indice_int, frase, numero_float);
        }

        // se for qualquer outra letra, insere na arvore
        else
        {
            Procura_preOrdem_insere(arvore, tipo_no[0], indice_int, frase, tipo_no_2[0], indice_int_2, esq_dir, numero_float);
        }

    }
    int entradas;
    char *salario_string;
    salario_string = (char*)malloc ( USER_SIZE * sizeof (char));
    float salario_double = -1;
    // checa a quantidade de entradas com o usuario
    scanf("%d", &entradas);
    // loop das entradas
    for(int j = 0; j < entradas; ++j)
    {
        // linha com as entradas do usuario
        char linha[100];
        scanf(" %[^\n]s", linha);
        // copia a raiz da arvore para um no que vai percorrer a arvore
        struct NO* atual = (*arvore);

        int chave_float = 0;
        int posicao_inicial, posicao_final;
        float precision = 0.0001;
        float tres_mil = 3000;

        // loop da entrada do usuario
        for(int k = 0; k < strlen(linha); ++k)
        {
            // Se o caractere for igual a E em ASCII
            if(linha[k] == 69)
            {
                // faz nada
            }
            // Se o caractere for igual a V em ASCII
            else if(linha[k] == 86)
            {
                atual = consulta_raiz(atual, linha[k]);
            }
            // Se o caractere for igual a F em ASCII
            else if(linha[k] == 70)
            {
                atual = consulta_raiz(atual, linha[k]);
            }
            // Se o caractere for igual a ESPACO em ASCII e a leitura de float estiver liberada
            else if(linha[k] == 32 && chave_float == 0)
            {
                // fazer nada
            }
            // Se o caractere nao for ESPACO e nao for a letra N em ASCII: vai ser float
            else if((linha[k] != 32) && (linha[k] != 78) && chave_float == 0)
            {
                // tranca a leitura do float
                chave_float = 1;
                // pega a posicao inicial do float
                posicao_inicial = k;
            }
            // Pega a posicao final do float
            if((((strlen(linha) - 1 == k) || (linha[k] == 32)) && chave_float == 1))
            {
                // se for o fim da linha
                if(strlen(linha) - 1 == k)
                {
                    posicao_final = k;
                }
                // se nao for o fim da linha
                else
                {
                    posicao_final = k-1;
                }     
                // quantidade de caracteres do float     
                int caracteres = posicao_final - posicao_inicial + 1;
                // copia  o char para para variavel
                strncpy(salario_string, linha + posicao_inicial, caracteres);
                
                // transforma a string em float
                salario_double = atof(salario_string);   
                // se o float for igual a certeza e for a Letra N
                if(((salario_double + precision > atual->teste_certeza) && (salario_double - precision < atual->teste_certeza))
                     && atual->letra == 78)
                {
                    atual = atual->dir;
                }
                // se o float for maior que a certeza e for a Letra N
                else if((salario_double >= atual->teste_certeza) && atual->letra == 78)
                {
                    atual = atual->dir;
                }
                // se o float for menor que a certeza e for a Letra N
                else if (salario_double < atual->teste_certeza && atual->letra == 78 )
                {
                    atual = atual->esq;
                }
                // libera a leitura de float
                chave_float = 0;
            }
            // Se for a letra N ou o ultimo caractere
            if((linha[k] == 78) || k == strlen(linha) - 1)
            {
                // seta um valor baixo para haver a mudanca na procura da maior confianca
                double valor = -1;
                // frase que sera printada
                char *frase_n;
                frase_n = (char*)malloc ( USER_SIZE * sizeof (char));  

                // procura maior confianca a partir do no atual
                Procura_maior_confianca(atual, &valor, frase_n);
                
                // printa a frase com maior confianca 
                printf("%s\n", frase_n);
            }        
        }
    }    
    // libera a arvore
    libera_ArvBin(arvore);
}

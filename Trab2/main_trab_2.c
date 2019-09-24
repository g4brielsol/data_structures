#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LDED.h" //inclui as chamadas de funcao

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
    
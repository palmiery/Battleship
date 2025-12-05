#include <stdio.h>
#include <ctype.h> // Necessário para a função toupper()

#include "valor_c.h"

void valor_c(char *letra, int *valor)
{
    // 1. Converte o caractere recebido para Maiúsculo (a -> A)
    // Usamos *letra para pegar o valor do caractere apontado
    char c = toupper(*letra); 

    // 2. Verifica se está entre A e O (intervalo do tabuleiro 15x15)
    if (c >= 'A' && c <= 'O') 
    {
        // 3. Matemática ASCII para converter letra em índice
        // 'A' - 'A' = 0
        // 'B' - 'A' = 1
        // ...
        // 'O' - 'A' = 14
        *valor = c - 'A'; 
    }
    else 
    {
        // Se não for uma letra válida, define um valor de erro (ex: -1)
        *valor = -1;
    }
}

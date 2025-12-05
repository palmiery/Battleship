#include <stdio.h>
#include "lerLinCol.h"

void lerLinCol(int *linha, int *coluna)
{
    // ---------------------------------------------------------
    // LEITURA DA LINHA
    // ---------------------------------------------------------
    int entradaValida = 0;
    do
    {
        printf("Digite linha (1 a %d): ", TAM);
        
        // Tenta ler um número inteiro
        if (scanf("%d", linha) == 1) 
        {
            // Valida o intervalo
            if(*linha < 1 || *linha > TAM)
            {
                printf("\nValor invalido! Digite entre 1 e %d.\n\n", TAM);
            }
            else 
            {
                entradaValida = 1; // Sucesso
            }
        }
        else 
        {
            // Erro: Usuário digitou letra ou símbolo
            printf("\nCaractere invalido! Digite apenas numeros.\n\n");
            
            // Limpa o buffer para não entrar em loop infinito
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

    } while(!entradaValida);

    *linha = *linha - 1; // Ajusta para índice do vetor (0 a 14)


    // ---------------------------------------------------------
    // LEITURA DA COLUNA
    // ---------------------------------------------------------
    entradaValida = 0;
    do
    {
        printf("Digite coluna (1 a %d): ", TAM);
        
        if (scanf("%d", coluna) == 1) 
        {
            if(*coluna < 1 || *coluna > TAM)
            {
                printf("\nValor invalido! Digite entre 1 e %d.\n\n", TAM);
            }
            else 
            {
                entradaValida = 1;
            }
        }
        else 
        {
            printf("\nCaractere invalido! Digite apenas numeros.\n\n");
            
            // Limpa o buffer
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

    } while(!entradaValida);

    *coluna = *coluna - 1; // Ajusta para índice do vetor
}

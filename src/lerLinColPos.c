#include <stdio.h>
#include "lerLinColPos.h"

void lerLinColPos(int *linha, int *coluna, int *pos)
{
    int entradaValida; // Variável de controle para os loops

    // ---------------------------------------------------------
    // 1. LEITURA DA LINHA
    // ---------------------------------------------------------
    entradaValida = 0;
    do
    {
        printf("Digite linha do posicionamento (1 a %d): ", TAM);
        
        // Verifica se o usuário digitou um número
        if (scanf("%d", linha) == 1) 
        {
            // Se for número, verifica se está dentro do limite
            if(*linha < 1 || *linha > TAM)
            {
                printf("\nValor fora do intervalo! Tente entre 1 e %d.\n\n", TAM);
            }
            else 
            {
                entradaValida = 1; // Tudo certo, sai do loop
            }
        }
        else 
        {
            // Se cair aqui, o usuário digitou letra ou símbolo
            printf("\nCaractere invalido! Digite apenas numeros.\n\n");
            
            // Limpa o buffer (Substituto do fflush)
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

    } while(!entradaValida);

    *linha = *linha - 1; // Ajusta para índice do vetor (0 a 14)


    // ---------------------------------------------------------
    // 2. LEITURA DA COLUNA
    // ---------------------------------------------------------
    entradaValida = 0;
    do
    {
        printf("Digite coluna do posicionamento (1 a %d): ", TAM);
        
        if (scanf("%d", coluna) == 1) 
        {
            if(*coluna < 1 || *coluna > TAM)
            {
                printf("\nValor fora do intervalo! Tente entre 1 e %d.\n\n", TAM);
            }
            else 
            {
                entradaValida = 1;
            }
        }
        else 
        {
            printf("\nCaractere invalido! Digite apenas numeros.\n\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

    } while(!entradaValida);

    *coluna = *coluna - 1; // Ajusta para índice do vetor


    // ---------------------------------------------------------
    // 3. LEITURA DA POSIÇÃO (HORIZONTAL/VERTICAL)
    // ---------------------------------------------------------
    entradaValida = 0;
    do
    {
        printf("Horizontal tecle (1), vertical (0): ");
        
        if (scanf("%d", pos) == 1) 
        {
            if(*pos < 0 || *pos > 1)
            {
                printf("\nOpcao invalida! Digite 0 ou 1.\n\n");
            }
            else 
            {
                entradaValida = 1;
            }
        }
        else 
        {
            printf("\nCaractere invalido! Digite apenas numeros.\n\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

    } while(!entradaValida);
}

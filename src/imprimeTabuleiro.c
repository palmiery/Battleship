#include <stdio.h>

// Inclui o cabeçalho correspondente
#include "imprimeTabuleiro.h"

void imprimeTabuleiro(int matriz[TAM][TAM])
{
    int i, j;

    printf("\t\t\t Esquadra \n\n");
    printf("     1   2   3   4   5   6   7   8   9   10  11  12  13  14  15 \n");// colunas da malha

    for(i = 0; i < TAM; i++)
    {
        printf("%2d", i+1); // Índice da linha
        for(j = 0; j < TAM; j++)
        {
            if(matriz[i][j]==0)
            {
                printf("   ~");
            }
            else if(matriz[i][j]==1)
            {
                printf("   P"); // Porta-Aviões
            }
            else if(matriz[i][j]==2)
            {
                printf("   F"); // Fragata
            }
            else if(matriz[i][j]==3)
            {
                printf("   C"); // Corveta
            }
            else if(matriz[i][j]==4)
            {
                printf("   S"); // Submarino
            }
            else if(matriz[i][j]==10)
            {
                printf("   +"); // Borda de segurança
            }
            else if(matriz[i][j]==6)
            {
                printf("   X"); // Tiro acertado
            }
            else if(matriz[i][j]==7)
            {
                printf("   *"); // Tiro na água
            }
        }
        printf("\n");
    }
    printf("\n\n");
}

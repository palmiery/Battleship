#include <stdio.h>
#include <stdlib.h> // Necessário para system()

// Inclui o próprio header
#include "batalha.h"

// Outras dependências do projeto
// (Mantive as que você listou, mas verifique se são realmente usadas aqui)
#include "imprimeTabuleiro.h"
#include "iniciaTabuleiro.h"
#include "valor_c.h"
#include "IA.h"

int batalha(int matriz[TAM][TAM], int matriz2[TAM][TAM])
{
    // Limpa a tela de forma portável (Linux e Windows)
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    int i, j;
    printf("\n\n");
    printf("\t/////////////////////////////////////////////\n");
    printf("\t/////////////////////////////////////////////\n");
    printf("\t//             BATALHA NAVAL               //\n");
    printf("\t/////////////////////////////////////////////\n");
    printf("\t/////////////////////////////////////////////\n");
    printf("\n");
    
    // ----------------------------------------------------
    // IMPRESSÃO DA ESQUADRA INIMIGA (MATRIZ 2)
    // ----------------------------------------------------
    printf("\t\t\tEsquadra Inimiga \n\n");
    printf("     1   2   3   4   5   6   7   8   9   10  11  12  13  14  15 \n"); // Cabeçalho colunas

    for(i = 0; i < TAM; i++)
    {
        printf("%2d", i+1); // Índice lateral
        for(j = 0; j < TAM; j++)
        {
            if(matriz2[i][j]==0)      printf("   ~"); // Água
            else if(matriz2[i][j]==1) printf("   P"); // Porta-aviões
            else if(matriz2[i][j]==2) printf("   F"); // Fragata
            else if(matriz2[i][j]==3) printf("   C"); // Corveta
            else if(matriz2[i][j]==4) printf("   S"); // Submarino
            else if(matriz2[i][j]==10)printf("   ~"); // Borda de segurança (esconde como água)
            else if(matriz2[i][j]==6) printf("   X"); // Tiro acertado (Destruído)
            else if(matriz2[i][j]==7) printf("   *"); // Tiro na água (Erro)
        }
        printf("\n");
    }

    printf("\n\n");

    // ----------------------------------------------------
    // IMPRESSÃO DA SUA ESQUADRA (MATRIZ 1)
    // ----------------------------------------------------
    printf("\t\t\tSua Esquadra\n\n");
    printf("     1   2   3   4   5   6   7   8   9   10  11  12  13  14  15 \n");

    for(i = 0; i < TAM; i++)
    {
        printf("%2d", i+1);
        for(j = 0; j < TAM; j++)
        {
            if(matriz[i][j]==0)       printf("   ~");
            else if(matriz[i][j]==1)  printf("   P");
            else if(matriz[i][j]==2)  printf("   F");
            else if(matriz[i][j]==3)  printf("   C");
            else if(matriz[i][j]==4)  printf("   S");
            else if(matriz[i][j]==10) printf("   ~"); // Borda (mostra ~ ou + dependendo da sua lógica)
            else if(matriz[i][j]==6)  printf("   X");
            else if(matriz[i][j]==7)  printf("   *");
        }
        printf("\n");
    }

    printf("\n\n");
    
    return 0; // Adicionado retorno pois a função é 'int'
}

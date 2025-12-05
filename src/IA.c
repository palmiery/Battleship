#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Inclui o próprio header
#include "IA.h"

// Includes de dependências (Verifique se os nomes dos arquivos estão corretos no seu projeto)
#include "iniciaTabuleiro.h"
#include "imprimeTabuleiro.h"
#include "valor_r.h" // Assumo que este arquivo contém a função valor_r usada abaixo

int ia(int matriz2[TAM][TAM])
{
    int linha, coluna, cont=0;
    int posicional;

    typedef struct{
        int portaaviao;
        int fragata;
        int corveta;
        int submarino;
    } Esquadra;

    Esquadra navio;
    navio.portaaviao = 4;
    navio.fragata = 3;
    navio.corveta = 2;
    navio.submarino = 1;

    // Limpa a matriz antes de começar
    iniciatabuleiro(matriz2);

    // ----------------------------------------------------------------
    // PORTA-AVIÕES (1 unidade)
    // ----------------------------------------------------------------
    valor_r(&linha, &coluna, &posicional);

    if(posicional == 1) // Horizontal
    {
        while((navio.portaaviao + coluna > TAM)||(matriz2[linha][coluna]!=0)||
                (matriz2[linha][coluna+1]!=0)||
                (matriz2[linha][coluna+2]!=0)||
                (matriz2[linha][coluna+3]!=0))
        {
            valor_r(&linha, &coluna, &posicional);
        }
        
        // Preenche o navio
        matriz2[linha][coluna] = 1;
        matriz2[linha][coluna+1] = 1;
        matriz2[linha][coluna+2] = 1;
        matriz2[linha][coluna+3] = 1;

        // Borda Esquerda
        if (coluna >= 1) {
            matriz2[linha][coluna-1] = 10;
            if(linha + 1 < TAM) matriz2[linha+1][coluna-1]= 10;
            if(linha - 1 >= 0)  matriz2[linha-1][coluna-1]= 10;
        }
        // Borda Direita
        if (coluna + 4 < TAM) {
            matriz2[linha][coluna+4] = 10;
            if(linha - 1 >= 0)  matriz2[linha-1][coluna+4]= 10;
            if(linha + 1 < TAM) matriz2[linha+1][coluna+4]= 10;
        }
        // Borda Superior
        if (linha >= 1) {
            matriz2[linha-1][coluna]= 10;
            matriz2[linha-1][coluna+1]= 10;
            matriz2[linha-1][coluna+2]= 10;
            matriz2[linha-1][coluna+3]= 10;
        }
        // Borda Inferior
        if (linha + 1 < TAM) {
            matriz2[linha+1][coluna]= 10;
            matriz2[linha+1][coluna+1]= 10;
            matriz2[linha+1][coluna+2]= 10;
            matriz2[linha+1][coluna+3]= 10;
        }
    }
    else // Vertical (posicional == 0)
    {
        while((navio.portaaviao + linha > TAM)||(matriz2[linha][coluna]!=0)||
                (matriz2[linha+1][coluna]!=0)||
                (matriz2[linha+2][coluna]!=0)||
                (matriz2[linha+3][coluna]!=0)) // Faltava verificar o indice +3 no while original
        {
            valor_r(&linha, &coluna, &posicional);
        }

        // Preenche o navio
        matriz2[linha][coluna] = 1;
        matriz2[linha+1][coluna] = 1;
        matriz2[linha+2][coluna] = 1;
        matriz2[linha+3][coluna] = 1;
        
        // Borda Superior
        if (linha >= 1) {
            matriz2[linha-1][coluna] = 10;
        }
        // Borda Inferior
        if (linha + 4 < TAM) {
            matriz2[linha+4][coluna] = 10;
        }
        // Borda Esquerda
        if (coluna >= 1) {
            if(linha >= 1) matriz2[linha-1][coluna-1]= 10;
            matriz2[linha][coluna-1]= 10;
            matriz2[linha+1][coluna-1]= 10;
            matriz2[linha+2][coluna-1]= 10;
            matriz2[linha+3][coluna-1]= 10;
            if(linha + 4 < TAM) matriz2[linha+4][coluna-1]= 10;
        }
        // Borda Direita
        if(coluna + 1 < TAM) {
            if(linha >= 1) matriz2[linha-1][coluna+1]= 10;
            matriz2[linha][coluna+1]= 10;
            matriz2[linha+1][coluna+1]= 10;
            matriz2[linha+2][coluna+1]= 10;
            matriz2[linha+3][coluna+1]= 10;
            if(linha + 4 < TAM) matriz2[linha+4][coluna+1]= 10;
        }
    }

    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    printf("Posicionando esquadra da IA, aguarde.\n");

    // ----------------------------------------------------------------
    // FRAGATAS (2 unidades - O loop vai até cont!=2)
    // ----------------------------------------------------------------
    cont=0;
    do
    {
        valor_r(&linha, &coluna, &posicional);
        
        if(posicional == 1) // Horizontal
        {
            while((navio.fragata + coluna > TAM)||(matriz2[linha][coluna]!=0)||
                    (matriz2[linha][coluna+1]!=0)||
                    (matriz2[linha][coluna+2]!=0))
            {
                valor_r(&linha, &coluna, &posicional);
            }

            matriz2[linha][coluna] = 2;
            matriz2[linha][coluna+1] = 2;
            matriz2[linha][coluna+2] = 2;

            // Borda Esquerda
            if (coluna >= 1) {
                matriz2[linha][coluna-1] = 10;
                if(linha+1 < TAM) matriz2[linha+1][coluna-1]= 10;
                if(linha-1 >= 0)  matriz2[linha-1][coluna-1]= 10;
            }
            // Borda Direita
            if (coluna + 3 < TAM) {
                matriz2[linha][coluna+3] = 10;
                if(linha-1 >= 0)  matriz2[linha-1][coluna+3]= 10;
                if(linha+1 < TAM) matriz2[linha+1][coluna+3]= 10;
            }
            // Borda Superior
            if (linha >= 1) {
                matriz2[linha-1][coluna]= 10;
                matriz2[linha-1][coluna+1]= 10;
                matriz2[linha-1][coluna+2]= 10;
            }
            // Borda Inferior
            if (linha + 1 < TAM) {
                matriz2[linha+1][coluna]= 10;
                matriz2[linha+1][coluna+1]= 10;
                matriz2[linha+1][coluna+2]= 10;
            }
        }
        else // Vertical
        {
            while((navio.fragata + linha > TAM)||(matriz2[linha][coluna]!=0)||
                    (matriz2[linha+1][coluna]!=0)||
                    (matriz2[linha+2][coluna]!=0))
            {
                valor_r(&linha, &coluna, &posicional);
            }

            matriz2[linha][coluna] = 2;
            matriz2[linha+1][coluna] = 2;
            matriz2[linha+2][coluna] = 2;

            // Borda Superior
            if (linha >= 1) {
                matriz2[linha-1][coluna] = 10;
            }
            // Borda Inferior
            if (linha + 3 < TAM) {
                matriz2[linha+3][coluna] = 10;
            }
            // Borda Esquerda
            if (coluna >= 1) {
                if(linha>=1) matriz2[linha-1][coluna-1]= 10;
                matriz2[linha][coluna-1]= 10;
                matriz2[linha+1][coluna-1]= 10;
                matriz2[linha+2][coluna-1]= 10;
                if(linha+3 < TAM) matriz2[linha+3][coluna-1]= 10;
            }
            // Borda Direita
            if(coluna + 1 < TAM) {
                if(linha>=1) matriz2[linha-1][coluna+1]= 10;
                matriz2[linha][coluna+1]= 10;
                matriz2[linha+1][coluna+1]= 10;
                matriz2[linha+2][coluna+1]= 10;
                if(linha+3 < TAM) matriz2[linha+3][coluna+1]= 10;
            }
        }
        cont++;
        
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        printf("Posicionando esquadra da IA, aguarde.\n");
    }
    while(cont!=2);

    // ----------------------------------------------------------------
    // CORVETAS (3 unidades - O loop vai até cont!=3)
    // ----------------------------------------------------------------
    cont=0;
    do
    {
        valor_r(&linha, &coluna, &posicional);
        if(posicional == 1) // Horizontal
        {
            while((navio.corveta + coluna > TAM)||(matriz2[linha][coluna]!=0)||
                    (matriz2[linha][coluna+1]!=0))
            {
                valor_r(&linha, &coluna, &posicional);
            }
            
            matriz2[linha][coluna] = 3;
            matriz2[linha][coluna+1] = 3;

            // Borda Esquerda
            if (coluna >= 1) {
                matriz2[linha][coluna-1] = 10;
                if(linha+1 < TAM) matriz2[linha+1][coluna-1]= 10;
                if(linha-1 >= 0)  matriz2[linha-1][coluna-1]= 10;
            }
            // Borda Direita
            if (coluna + 2 < TAM) {
                matriz2[linha][coluna+2] = 10;
                if(linha-1 >= 0)  matriz2[linha-1][coluna+2]= 10;
                if(linha+1 < TAM) matriz2[linha+1][coluna+2]= 10;
            }
            // Borda Superior
            if (linha >= 1) {
                matriz2[linha-1][coluna]= 10;
                matriz2[linha-1][coluna+1]= 10;
            }
            // Borda Inferior
            if (linha + 1 < TAM) {
                matriz2[linha+1][coluna]= 10;
                matriz2[linha+1][coluna+1]= 10;
            }
        }
        else // Vertical
        {
            while((navio.corveta + linha > TAM)||(matriz2[linha][coluna]!=0)||
                    (matriz2[linha+1][coluna]!=0))
            {
                valor_r(&linha, &coluna, &posicional);
            }
            
            matriz2[linha][coluna] = 3;
            matriz2[linha+1][coluna] = 3;

            // Borda Superior
            if (linha >= 1) {
                matriz2[linha-1][coluna] = 10;
            }
            // Borda Inferior
            if (linha + 2 < TAM) {
                matriz2[linha+2][coluna] = 10;
            }
            // Borda Esquerda
            if (coluna >= 1) {
                if(linha>=1) matriz2[linha-1][coluna-1]= 10;
                matriz2[linha][coluna-1]= 10;
                matriz2[linha+1][coluna-1]= 10;
                if(linha+2 < TAM) matriz2[linha+2][coluna-1]= 10;
            }
            // Borda Direita
            if(coluna + 1 < TAM) {
                if(linha>=1) matriz2[linha-1][coluna+1]= 10;
                matriz2[linha][coluna+1]= 10;
                matriz2[linha+1][coluna+1]= 10;
                if(linha+2 < TAM) matriz2[linha+2][coluna+1]= 10;
            }
        }
        cont++;
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        printf("Posicionando esquadra da IA, aguarde.\n");
    }
    while(cont!=3);

    // ----------------------------------------------------------------
    // SUBMARINOS (4 unidades - O loop vai até cont!=4)
    // ----------------------------------------------------------------
    cont=0;
    do
    {
        valor_r(&linha, &coluna, &posicional);
        
        while((navio.submarino + coluna > TAM)||(matriz2[linha][coluna]!=0))
        {
            valor_r(&linha, &coluna, &posicional);
        }

        matriz2[linha][coluna] = 4;

        // Borda Superior
        if (linha >= 1) {
            matriz2[linha-1][coluna] = 10;
        }
        // Borda Inferior
        if (linha + 1 < TAM) {
            matriz2[linha+1][coluna] = 10;
        }
        // Borda Esquerda
        if (coluna >= 1) {
            if(linha >= 1) matriz2[linha-1][coluna-1]= 10;
            matriz2[linha][coluna-1]= 10;
            if(linha + 1 < TAM) matriz2[linha+1][coluna-1]= 10;
        }
        // Borda Direita
        if(coluna + 1 < TAM) {
            if(linha >= 1) matriz2[linha-1][coluna+1]= 10;
            matriz2[linha][coluna+1]= 10;
            if(linha + 1 < TAM) matriz2[linha+1][coluna+1]= 10;
        }

        cont++;
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        printf("Posicionando esquadra da IA, aguarde.\n");
    }
    while(cont!=4);

    printf("\nPosicionamento completo!\n");
    printf("Pressione Enter para continuar.");
    getchar();

    return 0;
}

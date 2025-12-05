#include <stdio.h>
#include <stdlib.h>

// Incluímos nosso próprio header para pegar a definição de TAM e o protótipo
#include "aloca_esquadra.h" 

// Incluímos as outras dependências necessárias para ESTE código funcionar
// Nota: Como usaremos uma flag especial no compilador, não precisa mudar o include
#include "iniciaTabuleiro.h"
#include "imprimeTabuleiro.h"
#include "valor_c.h"
#include "lerLinCol.h"
#include "lerLinColPos.h"

// A implementação completa vem aqui
int aloca_esquadra(int matriz[TAM][TAM])
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

    // Inicia valores na matriz
    iniciatabuleiro(matriz);
    // Imprime matriz de alocação
    imprimeTabuleiro(matriz);
    
    // ----------------------------------------------------
    // PORTA AVIAO
    // ----------------------------------------------------
    printf("Digite o posicionamento do Porta-Aviao! \n");
    lerLinColPos(&linha, &coluna, &posicional);

    if(posicional == 1) // Horizontal
    {
        while((navio.portaaviao + coluna > TAM)||(matriz[linha][coluna]!=0)||
                (matriz[linha][coluna+1]!=0)||
                (matriz[linha][coluna+2]!=0)||
                (matriz[linha][coluna+3]!=0))
        {
            printf("Posicao invalida. Digite novamente!\n");
            lerLinCol(&linha, &coluna);
        }
        
        matriz[linha][coluna] = 1;
        matriz[linha][coluna+1] = 1;
        matriz[linha][coluna+2] = 1;
        matriz[linha][coluna+3] = 1;

        // Extremidade esquerda
        if (coluna >= 1)
        {
            matriz[linha][coluna-1] = 10;
            if(linha + 1 < TAM) matriz[linha+1][coluna-1]= 10;
            if(linha - 1 >= 0)  matriz[linha-1][coluna-1]= 10;
        }
        // Extremidade direita
        if (4+coluna < TAM)
        {
            matriz[linha][coluna+4] = 10;
            if(linha - 1 >= 0)  matriz[linha-1][coluna+4]= 10;
            if(linha + 1 < TAM) matriz[linha+1][coluna+4]= 10;
        }
        // Linha superior
        if (linha >= 1)
        {
            matriz[linha-1][coluna]= 10;
            matriz[linha-1][coluna+1]= 10;
            matriz[linha-1][coluna+2]= 10;
            matriz[linha-1][coluna+3]= 10;
        }
        // Linha inferior
        if (linha + 1 < TAM) 
        {
            matriz[linha+1][coluna]= 10;
            matriz[linha+1][coluna+1]= 10;
            matriz[linha+1][coluna+2]= 10;
            matriz[linha+1][coluna+3]= 10;
        }
    }
    else if(posicional == 0) // Vertical
    {
        while((navio.portaaviao + linha > TAM)||(matriz[linha][coluna]!=0)||
                (matriz[linha+1][coluna]!=0)||
                (matriz[linha+2][coluna]!=0))
        {
            printf("Posicao invalida. Digite novamente!\n");
            lerLinCol(&linha, &coluna);
        }

        matriz[linha][coluna] = 1;
        matriz[linha+1][coluna] = 1;
        matriz[linha+2][coluna] = 1;
        matriz[linha+3][coluna] = 1;
        
        // Linha superior
        if (linha >= 1)
        {
            matriz[linha-1][coluna] = 10;
        }
        // Linha inferior
        if (linha + 4 < TAM)
        {
            matriz[linha+4][coluna] = 10;
        }

        // Extremidade esquerda
        if (coluna >= 1)
        {
            if(linha >= 1) matriz[linha-1][coluna-1]= 10;
            matriz[linha][coluna-1]= 10;
            matriz[linha+1][coluna-1]= 10;
            matriz[linha+2][coluna-1]= 10;
            matriz[linha+3][coluna-1]= 10;
            if(linha + 4 < TAM) matriz[linha+4][coluna-1]= 10;
        }
        // Extremidade direita
        if(1+coluna < TAM)
        {
            if(linha >= 1) matriz[linha-1][coluna+1]= 10;
            matriz[linha][coluna+1]= 10;
            matriz[linha+1][coluna+1]= 10;
            matriz[linha+2][coluna+1]= 10;
            matriz[linha+3][coluna+1]= 10;
            if(linha + 4 < TAM) matriz[linha+4][coluna+1]= 10;
        }
    }
    
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    imprimeTabuleiro(matriz);

    // ----------------------------------------------------
    // FRAGATAS (3 unid)
    // ----------------------------------------------------
    cont=0;
    do
    {
        printf("Digite o posicionamento da Fragata %d: \n",cont+1);
        lerLinColPos(&linha, &coluna, &posicional);
        if(posicional == 1) // Horizontal
        {
            while((navio.fragata + coluna > TAM)||(matriz[linha][coluna]!=0)||
                    (matriz[linha][coluna+1]!=0)||
                    (matriz[linha][coluna+2]!=0))
            {
                printf("Posicao invalida. Digite novamente!\n");
                lerLinCol(&linha, &coluna);
            }

            matriz[linha][coluna] = 2;
            matriz[linha][coluna+1] = 2;
            matriz[linha][coluna+2] = 2;

            // Extremidade esquerda
            if (coluna >= 1)
            {
                matriz[linha][coluna-1] = 10;
                if(linha+1 < TAM) matriz[linha+1][coluna-1]= 10;
                if(linha-1 >= 0)  matriz[linha-1][coluna-1]= 10;
            }
            // Extremidade direita
            if (3+coluna < TAM)
            {
                matriz[linha][coluna+3] = 10;
                if(linha-1 >= 0)  matriz[linha-1][coluna+3]= 10;
                if(linha+1 < TAM) matriz[linha+1][coluna+3]= 10;
            }
            // Linha superior
            if (linha >= 1)
            {
                matriz[linha-1][coluna]= 10;
                matriz[linha-1][coluna+1]= 10;
                matriz[linha-1][coluna+2]= 10;
            }
            // Linha inferior
            if (linha + 1 < TAM)
            {
                matriz[linha+1][coluna]= 10;
                matriz[linha+1][coluna+1]= 10;
                matriz[linha+1][coluna+2]= 10;
            }
        }
        else if(posicional == 0) // Vertical
        {
            while((navio.fragata + linha > TAM)||(matriz[linha][coluna]!=0)||
                    (matriz[linha+1][coluna]!=0)||
                    (matriz[linha+2][coluna]!=0))
            {
                printf("Posicao invalida. Digite novamente!\n");
                lerLinCol(&linha, &coluna);
            }

            matriz[linha][coluna] = 2;
            matriz[linha+1][coluna] = 2;
            matriz[linha+2][coluna] = 2;

            // Linha superior
            if (linha >= 1)
            {
                matriz[linha-1][coluna] = 10;
            }
            // Linha inferior
            if (linha + 3 < TAM)
            {
                matriz[linha+3][coluna] = 10;
            }
            // Extremidade esquerda
            if (coluna >= 1)
            {
                if(linha>=1) matriz[linha-1][coluna-1]= 10;
                matriz[linha][coluna-1]= 10;
                matriz[linha+1][coluna-1]= 10;
                matriz[linha+2][coluna-1]= 10;
                if(linha+3 < TAM) matriz[linha+3][coluna-1]= 10;
            }
            // Extremidade direita
            if(1 + coluna < TAM)
            {
                if(linha>=1) matriz[linha-1][coluna+1]= 10;
                matriz[linha][coluna+1]= 10;
                matriz[linha+1][coluna+1]= 10;
                matriz[linha+2][coluna+1]= 10;
                if(linha+3 < TAM) matriz[linha+3][coluna+1]= 10;
            }
        }
        cont++;
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        imprimeTabuleiro(matriz);
    }
    while(cont!=2);

    // ----------------------------------------------------
    // CORVETAS
    // ----------------------------------------------------
    cont=0;
    do
    {
        printf("Digite o posicionamento da Corveta %d: \n",cont+1);
        lerLinColPos(&linha, &coluna, &posicional);
        if(posicional == 1) // Horizontal
        {
            while((navio.corveta + coluna > TAM)||(matriz[linha][coluna]!=0)||
                    (matriz[linha][coluna+1]!=0))
            {
                printf("Posicao invalida. Digite novamente!\n");
                lerLinCol(&linha, &coluna);
            }
            
            matriz[linha][coluna] = 3;
            matriz[linha][coluna+1] = 3;

            // Extremidade esquerda
            if (coluna >= 1)
            {
                matriz[linha][coluna-1] = 10;
                if(linha+1 < TAM) matriz[linha+1][coluna-1]= 10;
                if(linha-1 >= 0)  matriz[linha-1][coluna-1]= 10;
            }
            // Extremidade direita
            if (2 + coluna <  TAM)
            {
                matriz[linha][coluna+2] = 10;
                if(linha-1 >= 0)  matriz[linha-1][coluna+2]= 10;
                if(linha+1 < TAM) matriz[linha+1][coluna+2]= 10;
            }
            // Linha superior
            if (linha >= 1)
            {
                matriz[linha-1][coluna]= 10;
                matriz[linha-1][coluna+1]= 10;
            }
            // Linha inferior
            if (linha + 1 < TAM)
            {
                matriz[linha+1][coluna]= 10;
                matriz[linha+1][coluna+1]= 10;
            }
        }
        else if(posicional == 0) // Vertical
        {
            while((navio.corveta + linha > TAM)||(matriz[linha][coluna]!=0)||
                    (matriz[linha+1][coluna]!=0))
            {
                printf("Posicao invalida. Digite novamente!\n");
                lerLinCol(&linha, &coluna);
            }

            matriz[linha][coluna] = 3;
            matriz[linha+1][coluna] = 3;

            // Linha superior
            if (linha >= 1)
            {
                matriz[linha-1][coluna] = 10;
            }
            // Linha inferior
            if (linha + 2 < TAM)
            {
                matriz[linha+2][coluna] = 10;
            }
            // Extremidade esquerda
            if (coluna >= 1)
            {
                if(linha>=1) matriz[linha-1][coluna-1]= 10;
                matriz[linha][coluna-1]= 10;
                matriz[linha+1][coluna-1]= 10;
                if(linha+2 < TAM) matriz[linha+2][coluna-1]= 10;
            }
            // Extremidade direita
            if(1 +coluna <  TAM)
            {
                if(linha>=1) matriz[linha-1][coluna+1]= 10;
                matriz[linha][coluna+1]= 10;
                matriz[linha+1][coluna+1]= 10;
                if(linha+2 < TAM) matriz[linha+2][coluna+1]= 10;
            }
        }
        cont++;
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        imprimeTabuleiro(matriz);
    }
    while(cont!=3);

    // ----------------------------------------------------
    // SUBMARINOS
    // ----------------------------------------------------
    cont=0;
    do
    {
        printf("Digite o posicionamento do Submarino %d: \n",cont+1);
        lerLinCol(&linha, &coluna);
        while((navio.submarino + coluna > TAM)||(matriz[linha][coluna]!=0))
        {
            printf("Posicao invalida. Digite novamente!\n");
            lerLinCol(&linha, &coluna);
        }

        matriz[linha][coluna] = 4;

        // Linha superior
        if (linha >= 1)
        {
            matriz[linha-1][coluna] = 10;
        }
        // Linha inferior
        if (linha + 1 < TAM)
        {
            matriz[linha+1][coluna] = 10;
        }
        // Extremidade esquerda
        if (coluna >= 1)
        {
            if(linha >= 1) matriz[linha-1][coluna-1]= 10;
            matriz[linha][coluna-1]= 10;
            if(linha + 1 < TAM) matriz[linha+1][coluna-1]= 10;
        }
        // Extremidade direita
        if(1+coluna < TAM)
        {
            if(linha >= 1) matriz[linha-1][coluna+1]= 10;
            matriz[linha][coluna+1]= 10;
            if(linha + 1 < TAM) matriz[linha+1][coluna+1]= 10;
        }
        
        cont++;
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        imprimeTabuleiro(matriz);
    }
    while(cont!=4);

    printf("Posicionamento completo!\n\n");
    printf("Pressione Enter para continuar.");
    getchar();
    
    return 0;
}

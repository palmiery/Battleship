#include <stdio.h>
#include <stdlib.h>

#include "vitoria.h"

// Dependências para reiniciar o jogo
#include "menu.h"
#include "iniciaTabuleiro.h"
#include "aloca_esquadra.h"
#include "IA.h"
#include "batalha.h"
#include "tiromanual.h"
// #include "tiroIA.h" // Se precisar chamar IA diretamente

void limparTelaVitoria() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Função auxiliar para desenhar o troféu
void desenharTrofeu(char *vencedor) {
    printf("                                \n");
    printf("\t\t      ____________________        \n");
    printf("\t\t    /|                     |\\     \n");
    printf("\t\t   / |                     | \\    \n");
    printf("\t\t   | |                     |  |    \n");
    printf("\t\t    \\ |                     | /    \n");
    printf("\t\t     \\|                     |/     \n");
    printf("\t\t      |                     |       \n");
    printf("\t\t       \\                   /       \n");
    printf("\t\t        \\                 /        \n");
    printf("\t\t         \\               /         \n");
    printf("\t\t          |             |           \n");
    printf("\t\t           |           |            \n");
    printf("\t\t            |         |             \n");
    printf("\t\t             |       |              \n");
    printf("\t\t             |       |              \n");
    printf("\t\t       ______|       |______         \n");
    printf("\t\t      |                     |       \n");
    printf("\t\t      |   %s   |       \n", vencedor); // Imprime quem venceu
    printf("\t\t      |      PARABENS       |       \n");
    printf("\t\t      |                     |       \n");
    printf("\t\t      |                     |       \n");
    printf("\t\t       ------------------         \n");
}

int vitoria(int matriz[TAM][TAM], int matriz2[TAM][TAM])
{
    int i, j, cont1=0, cont2=0;

    // CONTA PONTOS DA IA (matriz do jogador tem '6')
    for(i=0; i<TAM; i++)
    {
        for(j=0; j<TAM; j++)
        {
            if(matriz[i][j] == 6) // Navio destruído
            {
                cont1++;
            }
        }
    }

    // SE A IA VENCEU (20 pontos = 4+3+3+3+2+2+2+1?)
    // Verifique se 20 é o número correto de células de navio no seu jogo
    if(cont1 == 20) 
    {
        getchar();
        limparTelaVitoria();
        desenharTrofeu("IA VENCEU!!  ");
        
        printf("\n\t\t\tFim de jogo\n\n\n");
        printf("\n\n\t\t\tPlacar: VOCE %d X %d IA\n\n", cont2, cont1);
        
        batalha(matriz, matriz2);
        
        printf("\nPara encerrar ou jogar novamente pressione Enter para ir ao menu.\n");
        getchar();
        
        // Reinicia o jogo
        iniciatabuleiro(matriz2);
        iniciatabuleiro(matriz);
        menu();
        
        // CUIDADO: Verifique se aloca_esquadra pede 1 ou 2 argumentos no seu .h
        // No código anterior era: int aloca_esquadra(int matriz[TAM][TAM])
        aloca_esquadra(matriz); 
        
        ia(matriz2);
        batalha(matriz, matriz2);
        tiromanual(matriz, matriz2);
        return 1; // Fim de jogo
    }

    // CONTA PONTOS DO JOGADOR (matriz2 da IA tem '6')
    for(i=0; i<TAM; i++)
    {
        for(j=0; j<TAM; j++)
        {
            if(matriz2[i][j] == 6)
            {
                cont2++;
            }
        }
    }

    // SE O JOGADOR VENCEU
    if(cont2 == 20)
    {
        getchar();
        limparTelaVitoria();
        desenharTrofeu("VOCE VENCEU!!");
        
        printf("\n\t\t\tFim de jogo\n\n\n");
        printf("\n\n\t\t\tPlacar: VOCE %d X %d IA\n\n", cont2, cont1);
        
        batalha(matriz, matriz2);
        
        printf("\nPara encerrar ou jogar novamente pressione Enter para ir ao menu.\n");
        getchar();
        
        iniciatabuleiro(matriz2);
        iniciatabuleiro(matriz);
        menu();
        
        aloca_esquadra(matriz);
        
        ia(matriz2);
        batalha(matriz, matriz2);
        tiromanual(matriz, matriz2);
        return 1;
    }

    // Se ninguém ganhou, mostra o placar parcial
    printf("\n\nPlacar: VOCE %d X %d IA\n\n", cont2, cont1);
    return 0; // Jogo continua
}

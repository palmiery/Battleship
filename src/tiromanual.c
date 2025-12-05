#include <stdio.h>
#include <stdlib.h>

#include "tiromanual.h"

// Includes necessários para a lógica
#include "batalha.h"
#include "lerLinCol.h"
#include "tiroIA.h"
#include "vitoria.h" 
// (Outros includes como iniciaTabuleiro ou aloca_esquadra 
// não são usados DENTRO dessa função específica, então removi para limpar)

// Função auxiliar para limpar tela
void limparTelaManual() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int tiromanual(int matriz[TAM][TAM], int matriz2[TAM][TAM])
{
    limparTelaManual();
    int l, c;

    // Mostra o tabuleiro atualizado (Sua esquadra e a Inimiga)
    batalha(matriz, matriz2);
    
    // Lê as coordenadas do tiro
    printf("Sua vez de atirar!\n");
    lerLinCol(&l, &c);

    limparTelaManual();

    // -----------------------------------------------------------
    // CASO 1: TIRO NA ÁGUA (0) OU BORDA (10) -> ERROU
    // -----------------------------------------------------------
    if(matriz2[l][c] == 0 || matriz2[l][c] == 10)
    {
        matriz2[l][c] = 7; // Marca como erro (*)
        
        limparTelaManual();
        batalha(matriz, matriz2);
        
        printf("Voce ERROU (Agua)! Vez da IA.\n");
        printf("Pressione Enter para continuar...");
        getchar(); // Pausa
        
        // Passa a vez para o Computador
        tiroIA(matriz, matriz2);
    }
    // -----------------------------------------------------------
    // CASO 2: LUGAR JÁ ATIRADO (6 ou 7) -> TENTAR DE NOVO
    // -----------------------------------------------------------
    else if(matriz2[l][c] == 7 || matriz2[l][c] == 6)
    {
        printf("\nVoce ja atirou nessas coordenadas! Tente outras.\n");
        printf("Pressione Enter...");
        getchar();
        tiromanual(matriz, matriz2); // Chama a si mesmo para tentar de novo
    }
    // -----------------------------------------------------------
    // CASO 3: ACERTOU NAVIO (1, 2, 3, 4) -> ACERTOU
    // -----------------------------------------------------------
    else
    {
        matriz2[l][c] = 6; // Marca como acerto (X)
        
        limparTelaManual();
        // Som de beep (pode não funcionar em todos os terminais Linux)
        printf("\a"); 
        
        batalha(matriz, matriz2);
        
        printf("\t\t\tACERTOU UM NAVIO!\n");
        printf("\tCoordenada atingida: (%d, %d)\n", l+1, c+1);
        
        // Verifica se o jogo acabou
        // Nota: Certifique-se que vitoria() trata o fim do jogo ou retorna algo
        vitoria(matriz, matriz2); 
        
        printf("Pressione Enter para atirar novamente...");
        getchar();
        
        // Se acertou, a regra geralmente permite jogar de novo
        tiromanual(matriz, matriz2);
    }

    return 0;
}

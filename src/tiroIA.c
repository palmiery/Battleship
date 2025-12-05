#include <stdio.h>
#include <stdlib.h>

#include "tiroIA.h"

// Includes necessários para a lógica interna
#include "batalha.h"
#include "tiromanual.h"
#include "valor_r.h"
// #include "vitoria.h" // Se tiver função de checar vitoria, descomente

// Helper para limpar tela
void limparTelaIA() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

/* Tiro IA geograficamente próximo ACIMA */
int tiroInteligenteA(int matriz[TAM][TAM], int matriz2[TAM][TAM], int l, int c)
{
    limparTelaIA();
    l--; // Move para cima

    // SEGURANÇA: Verifica se saiu do tabuleiro
    if(l < 0) {
        tiroIA(matriz, matriz2); // Volta a atirar aleatoriamente
        return 0;
    }

    if(matriz[l][c] == 0 || matriz[l][c] == 10 ) // Água ou Borda
    {
        matriz[l][c] = 7; // Errou
        limparTelaIA();
        batalha(matriz, matriz2);
        printf("Computador errou (Acima)! Sua vez. Enter para continuar.");
        getchar();
        tiromanual(matriz, matriz2);
    }
    else // Acertou algo ou já tinha atirado
    {
        if(matriz[l][c] == 7 || matriz[l][c] == 6) // Já atirou aqui antes
        {
             // Evita ficar preso, tenta outra direção ou aleatório
             tiroIA(matriz, matriz2);
             return 0;
        }
        
        // Acertou navio!
        matriz[l][c] = 6;
        limparTelaIA();
        batalha(matriz, matriz2);
        printf("Computador ACERTOU (Acima)!\n");
        // Continua atirando na mesma direção (recursão)
        tiroInteligenteA(matriz, matriz2, l, c);
    }
    return 0;
}

/* Tiro IA geograficamente próximo ABAIXO */
int tiroInteligenteB(int matriz[TAM][TAM], int matriz2[TAM][TAM], int l, int c)
{
    limparTelaIA();
    l++; // Move para baixo

    if(l >= TAM) {
        tiroIA(matriz, matriz2);
        return 0;
    }

    if(matriz[l][c] == 0 || matriz[l][c] == 10 )
    {
        matriz[l][c] = 7;
        limparTelaIA();
        batalha(matriz, matriz2);
        printf("Computador errou (Abaixo)! Sua vez. Enter para continuar.");
        getchar();
        tiromanual(matriz, matriz2);
    }
    else
    {
        if(matriz[l][c] == 7 || matriz[l][c] == 6)
        {
             tiroIA(matriz, matriz2);
             return 0;
        }
        
        matriz[l][c] = 6;
        limparTelaIA();
        batalha(matriz, matriz2);
        printf("Computador ACERTOU (Abaixo)!\n");
        tiroInteligenteB(matriz, matriz2, l, c);
    }
    return 0;
}

/* Tiro IA geograficamente próximo ESQUERDA */
int tiroInteligenteE(int matriz[TAM][TAM], int matriz2[TAM][TAM], int l, int c)
{
    limparTelaIA();
    c--; // Move para esquerda

    if(c < 0) {
        tiroIA(matriz, matriz2);
        return 0;
    }

    if(matriz[l][c] == 0 || matriz[l][c] == 10 )
    {
        matriz[l][c] = 7;
        limparTelaIA();
        batalha(matriz, matriz2);
        printf("Computador errou (Esquerda)! Sua vez. Enter para continuar.");
        getchar();
        tiromanual(matriz, matriz2);
    }
    else
    {
        if(matriz[l][c] == 7 || matriz[l][c] == 6)
        {
             tiroIA(matriz, matriz2);
             return 0;
        }
        
        matriz[l][c] = 6;
        limparTelaIA();
        batalha(matriz, matriz2);
        printf("Computador ACERTOU (Esquerda)!\n");
        tiroInteligenteE(matriz, matriz2, l, c);
    }
    return 0;
}

/* Tiro IA geograficamente próximo DIREITA */
int tiroInteligenteD(int matriz[TAM][TAM], int matriz2[TAM][TAM], int l, int c)
{
    limparTelaIA();
    c++; // Move para direita

    if(c >= TAM) {
        tiroIA(matriz, matriz2);
        return 0;
    }

    if(matriz[l][c] == 0 || matriz[l][c] == 10 )
    {
        matriz[l][c] = 7;
        limparTelaIA();
        batalha(matriz, matriz2);
        printf("Computador errou (Direita)! Sua vez. Enter para continuar.");
        getchar();
        tiromanual(matriz, matriz2);
    }
    else
    {
        if(matriz[l][c] == 7 || matriz[l][c] == 6)
        {
             tiroIA(matriz, matriz2);
             return 0;
        }

        matriz[l][c] = 6;
        limparTelaIA();
        batalha(matriz, matriz2);
        printf("Computador ACERTOU (Direita)!\n");
        tiroInteligenteD(matriz, matriz2, l, c);
    }
    return 0;
}

/* Tiro IA Principal (Aleatório) */
int tiroIA(int matriz[TAM][TAM], int matriz2[TAM][TAM])
{
    limparTelaIA();
    int l, c, p;
    
    // Gera tiro aleatório
    valor_r(&l, &c, &p);

    if(matriz[l][c] == 0 || matriz[l][c] == 10 )
    {
        matriz[l][c] = 7; // Errou
        limparTelaIA();
        batalha(matriz, matriz2);
        printf("Computador atirou em [%d][%d] e ERROU. Sua vez.\n", l+1, c+1);
        getchar();
        tiromanual(matriz, matriz2);
    }
    else
    {
        // Se já atirou nesse lugar, tenta de novo (recursão simples)
        if(matriz[l][c] == 7 || matriz[l][c] == 6)
        {
            tiroIA(matriz, matriz2);
            return 0;
        }
        
        // Acertou um navio novo!
        matriz[l][c] = 6;
        limparTelaIA();
        batalha(matriz, matriz2);
        printf("Computador atirou em [%d][%d] e ACERTOU!\n", l+1, c+1);
        getchar(); // Pausa dramática
        
        // IA tenta ser inteligente: tenta atirar na direita primeiro
        // Se quiser melhorar, poderia sortear qual direção tentar primeiro
        tiroInteligenteD(matriz, matriz2, l, c);
    }
    return 0;
}

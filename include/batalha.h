#ifndef BATALHA_H_INCLUDED
#define BATALHA_H_INCLUDED

// Garante que TAM esteja definido
#ifndef TAM
    #define TAM 15
#endif

// Protótipo da função
// Recebe duas matrizes: a do jogador e a do computador/inimigo
int batalha(int matriz[TAM][TAM], int matriz2[TAM][TAM]);


#endif // BATALHA_H_INCLUDED

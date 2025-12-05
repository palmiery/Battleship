#ifndef TIROIA_H_INCLUDED
#define TIROIA_H_INCLUDED

// Garante a definição de TAM
#ifndef TAM
    #define TAM 15
#endif

// Protótipos das funções de IA
int tiroInteligenteA(int matriz[TAM][TAM], int matriz2[TAM][TAM], int l, int c);
int tiroInteligenteB(int matriz[TAM][TAM], int matriz2[TAM][TAM], int l, int c);
int tiroInteligenteE(int matriz[TAM][TAM], int matriz2[TAM][TAM], int l, int c);
int tiroInteligenteD(int matriz[TAM][TAM], int matriz2[TAM][TAM], int l, int c);
int tiroIA(int matriz[TAM][TAM], int matriz2[TAM][TAM]);

#endif // TIROIA_H_INCLUDED

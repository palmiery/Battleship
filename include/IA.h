#ifndef IA_H_INCLUDED
#define IA_H_INCLUDED

// Garante que TAM esteja definido
#ifndef TAM
    #define TAM 15
#endif

// Protótipo da função
// Recebe a matriz onde a IA vai posicionar os navios
int ia(int matriz2[TAM][TAM]);

#endif // IA_H_INCLUDED

#ifndef VITORIA_H_INCLUDED
#define VITORIA_H_INCLUDED

// Garante que TAM esteja definido
#ifndef TAM
    #define TAM 15
#endif

// Protótipo da função
// Verifica se alguém ganhou (contando tiros acertados '6')
int vitoria(int matriz[TAM][TAM], int matriz2[TAM][TAM]);

#endif // VITORIA_H_INCLUDED

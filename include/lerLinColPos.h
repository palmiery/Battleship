#ifndef LERLINCOLPOS_H_INCLUDED
#define LERLINCOLPOS_H_INCLUDED

// Garante que TAM esteja definido apenas uma vez
#ifndef TAM
    #define TAM 15
#endif

// Protótipo da função
// Lê Linha, Coluna e Posição (Horizontal/Vertical) com validação
void lerLinColPos(int *linha, int *coluna, int *pos);

#endif // LERLINCOLPOS_H_INCLUDED

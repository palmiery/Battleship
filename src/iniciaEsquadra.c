#include "iniciaEsquadra.h"

void iniciaEsquadra(int matriz[TAM][TAM])
{
    int i, j;
    
    // Percorre a matriz preenchendo com 0
    for(i = 0; i < TAM; i++)
    {
        for(j = 0; j < TAM; j++)
        {
            matriz[i][j] = 0;
        }
    }
}

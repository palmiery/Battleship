// Inclui o cabeçalho para saber o que é TAM e validar a função
#include "iniciaTabuleiro.h" 

void iniciatabuleiro(int matriz[TAM][TAM])
{
    int i, j;
    
    // Percorre toda a matriz preenchendo com 0 (água/vazio)
    for(i=0; i<TAM; i++)
    {
        for(j=0; j<TAM; j++)
        {
            matriz[i][j] = 0;
        }
    }
}

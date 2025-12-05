#include <stdlib.h> // Necessário para rand() e srand()
#include <time.h>   // Necessário para time()
#include "valor_r.h"

void valor_r(int *linha, int *coluna, int *pos)
{
    // PROTEÇÃO: Garante que a semente aleatória só seja iniciada UMA vez.
    // Sem isso, se a função rodar muito rápido, gera sempre os mesmos números.
    static int sementeIniciada = 0;
    if (!sementeIniciada) {
        srand(time(NULL));
        sementeIniciada = 1;
    }

    // Gera número entre 0 e 14 diretamente
    // (Não precisa somar 1 e depois subtrair, dá no mesmo)
    *linha = rand() % TAM;
    
    *coluna = rand() % TAM;
    
    // Gera 0 ou 1
    *pos = rand() % 2;
}

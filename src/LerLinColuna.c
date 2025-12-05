#include <stdio.h>
#include "LerLinColuna.h"

void LerLinColuna(int *linha, int *coluna, int *pos)
{
    int entradaValida;

    // ---------------------------------------------------------
    // 1. LEITURA DA LINHA
    // ---------------------------------------------------------
    entradaValida = 0;
    do {
        printf("Digite linha do posicionamento (1 a %d): ", TAM);
        
        // Lê e valida se é número E se está no intervalo
        if (scanf("%d", linha) == 1 && *linha >= 1 && *linha <= TAM) {
            entradaValida = 1;
        } else {
            printf("Entrada invalida! Digite um numero entre 1 e %d.\n", TAM);
            // Limpa buffer (essencial no Linux)
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    } while (!entradaValida);

    // Ajusta para índice do vetor (Usuário digita 1, vira 0)
    *linha = *linha - 1; 

    // ---------------------------------------------------------
    // 2. LEITURA DA COLUNA
    // ---------------------------------------------------------
    entradaValida = 0;
    do {
        printf("Digite coluna do posicionamento (1 a %d): ", TAM);

        if (scanf("%d", coluna) == 1 && *coluna >= 1 && *coluna <= TAM) {
            entradaValida = 1;
        } else {
            printf("Entrada invalida! Digite um numero entre 1 e %d.\n", TAM);
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    } while (!entradaValida);

    // Ajusta para índice do vetor
    *coluna = *coluna - 1;

    // ---------------------------------------------------------
    // 3. LEITURA DA POSIÇÃO
    // ---------------------------------------------------------
    entradaValida = 0;
    do {
        printf("Horizontal tecle (1), vertical (0): ");

        if (scanf("%d", pos) == 1 && (*pos == 0 || *pos == 1)) {
            entradaValida = 1;
        } else {
            printf("Opcao invalida! Digite 0 ou 1.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }
    } while (!entradaValida);

    // Debug opcional (pode comentar depois)
    printf("Debug -> Linha(Index): %d, Coluna(Index): %d, Pos: %d\n", *linha, *coluna, *pos);
}

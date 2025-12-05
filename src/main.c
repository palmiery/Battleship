#include <stdio.h>
#include <stdlib.h>
//#include <conio.h> removido para compilação no linux
#include <stdlib.h>
#include <time.h>
#define TAM 15  // tamanho do tabuleiro
#include "iniciaTabuleiro.h" //Função para inicializar Matriz tabuleiro
#include "imprimeTabuleiro.h"
#include "aloca_esquadra.h"
#include "menu.h"
#include "valor_c.h"
#include "valor_r.h"
#include "batalha.h"
#include "IA.h"
#include "tiromanual.h"
#include "tiroIA.h"
#include "vitoria.h"
#include "lerLinCol.h"

int main()
{
    int matriz[TAM][TAM];
    int matriz2[TAM][TAM];
    menu();
    iniciatabuleiro(matriz);
    iniciatabuleiro(matriz2);
    aloca_esquadra(matriz);
    ia(matriz2);
    tiromanual(matriz, matriz2);
    return 0;
}

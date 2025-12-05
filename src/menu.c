#include <stdio.h>
#include <stdlib.h> // Necessário para exit() e system()
#include "menu.h"

void menu()
{
    // Limpa a tela antes de mostrar o menu
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    int opcao = 0; // Inicializa com 0 para evitar lixo de memória
    int c; // Variável auxiliar para limpeza do buffer

    printf("\n\n");
    printf("\t/////////////////////////////////////////////////////////////\n");
    printf("\t/////////////////////////////////////////////////////////////\n");
    printf("\t//                                                         //\n");
    printf("\t//       ***      BEM VINDO AO BATALHA NAVAL        ***    //\n");
    printf("\t//                                                         //\n");
    printf("\t//           [1] INICIAR JOGO - (ENTER)                    //\n");
    printf("\t//           [2] INSTRUCOES (RECOMENDADO) - (ENTER)        //\n");
    printf("\t//           [3] CREDITOS - (ENTER)                        //\n");
    printf("\t//           [4] SAIR                                      //\n");
    printf("\t//                                                         //\n");
    printf("\t//                                                         //\n");
    printf("\t/////////////////////////////////////////////////////////////\n");
    printf("\t/////////////////////////////////////////////////////////////\n");
    
    printf("\tEscolha uma opcao: ");
    scanf("%d", &opcao);

    // -------------------------------------------------------------------
    // Limpamos o buffer IMEDIATAMENTE após ler a opção.
    // Isso consome o "Enter" sobrando ou qualquer letra errada digitada.
    // -------------------------------------------------------------------
    while ((c = getchar()) != '\n' && c != EOF);


    switch(opcao)
    {
    case 1:
        printf("\nDistribua as embarcacoes na malha!\n\n");
        printf("Pressione ENTER para continuar... ");
        getchar(); // Agora funciona, pois o buffer foi limpo acima
        
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        break; // Sai do menu e retorna para a main continuar o jogo

    case 2:
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        
        printf(
                "\n"
                "\t=======================================================\n"
                "\t                   INSTRUCOES DO JOGO                  \n"
                "\t=======================================================\n\n"
                "1. O Batalha Naval e um jogo de estrategia por turnos (1x1). O objetivo\n"
                "   e afundar a esquadra rival antes que a sua seja destruida.\n\n"
                "2. Posicionamento: Informe a Linha e a Coluna (valores entre 1 e 15).\n"
                "   Valores fora deste intervalo serao rejeitados.\n\n"
                "3. Orientacao: Digite (1) para Horizontal ou (0) para Vertical.\n\n"
            );
        
        printf("\n\n\n\n\n\nPressione ENTER para voltar ao menu... ");
        getchar(); // Pausa aguardando o Enter
        menu(); // Volta ao menu (recursivo)
        break;

    case 3:
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        
        printf("\n\n\tPROJETO DE INTRODUCAO A TECNICAS DE PROGRAMACAO\n\n");
        printf("\tDesenvolvido por: ");
        printf("Renato Campos e Wanderson Alves\n");
        printf("\tCodigo, sintaxe e Estrutura desenvolvida em equipe.");
        
        printf("\n\n\n\n\n\nPressione ENTER para voltar ao menu... ");
        getchar(); 
        menu();
        break;

    case 4:
        exit(0); 
        break;

    default:
        printf("Opcao invalida! Pressione ENTER para tentar novamente.");
        getchar(); 
        menu();
    }
}

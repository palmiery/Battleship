# 🚢 Batalha Naval em C

Um jogo clássico de Batalha Naval desenvolvido em linguagem C, rodando diretamente no terminal. O projeto implementa lógica de posicionamento de navios, sistema de turnos e uma Inteligência Artificial (IA) capaz de realizar tiros estratégicos.

## 📋 Sobre o Projeto

Este projeto foi desenvolvido como parte da disciplina de **Introdução a Técnicas de Programação (ITP)**. O objetivo é afundar a esquadra inimiga antes que ela afunde a sua. O jogo acontece em um tabuleiro 15x15.

### Funcionalidades
- **Modo Jogador vs IA:** Jogue contra o computador.
- **Posicionamento Manual:** Escolha onde colocar seus navios.
- **IA Inteligente:** O computador atira aleatoriamente até acertar, e então busca navios nas células adjacentes.
- **Feedback Visual:** O tabuleiro é atualizado a cada turno mostrando água (`~`), acertos (`X`) e erros (`*`).
- **Validação de Entradas:** Proteção contra coordenadas inválidas ou sobreposição de navios

## 📂 Estrutura de Arquivos

O projeto segue uma estrutura organizada para separar a implementação da interface:

```text
.
├── include/        # Arquivos de cabeçalho (.h)
│   ├── IA.h
│   ├── batalha.h
│   └── ...
├── src/            # Códigos fonte (.c)
│   ├── main.c
│   ├── IA.c
│   └── ...
└── README.md

🚀 Como Baixar e Executar

Pré-requisitos

Você precisa ter um compilador C instalado. Recomendamos o GCC (GNU Compiler Collection).

Linux (Ubuntu/Debian): Geralmente já vem instalado ou pode ser instalado via sudo apt install build-essential.

Windows: Pode ser usado via MinGW ou WSL.

1. Clonar o repositório
Abra o terminal e execute:

git clone [https://github.com/palmiery/Battleship.git](https://github.com/palmiery/Battleship.git)
cd Battleship

2. Compilar o Projeto
Para transformar o código em um executável, utilize o comando abaixo. Este comando informa ao compilador onde buscar os arquivos .h (pasta include) e onde estão os códigos .c (pasta src).

No Terminal (Linux/Mac/WSL):

gcc -Wall -I include src/*.c -o batalha_naval

🎮 Como Jogar
Menu Inicial: Escolha "Iniciar Jogo".

Posicionamento: Digite a Linha (1-15), a Coluna (1-15) e a Orientação (1 para Horizontal, 0 para Vertical) para cada navio solicitado.

Batalha:

O tabuleiro mostra sua esquadra e a esquadra inimiga (oculta).

Digite as coordenadas para atirar.

Legenda:

~ : Água (Desconhecido)

* : Tiro na água (Errou)

X : Navio atingido

P, F, C, S : Seus navios

Vitória: O primeiro a destruir todos os 20 pontos de estrutura da esquadra inimiga vence.

🛠️ Tecnologias Utilizadas
Linguagem C (Padrão C99/C11)

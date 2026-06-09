#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    // 1. Representação do Tabuleiro
    // Matriz 10x10 inicializada com 0 (representando água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // 2. Definição dos Navios
    // Navio Horizontal (inicia na linha 2, coluna 2 e ocupa 3 posições para a direita)
    int linhaNavioH = 2;
    int colunaNavioH = 2;
    int orientacaoH = 0; // 0 para Horizontal, 1 para Vertical

    // Navio Vertical (inicia na linha 5, coluna 7 e ocupa 3 posições para baixo)
    int linhaNavioV = 5;
    int colunaNavioV = 7;
    int orientacaoV = 1;

    // 3. Validação e Posicionamento dos Navios

    // Posicionamento do Navio Horizontal
    if (orientacaoH == 0) {
        // Valida se o navio não ultrapassa os limites do tabuleiro
        if (colunaNavioH + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaNavioH][colunaNavioH + i] = NAVIO;
            }
        } else {
            printf("Erro: Navio horizontal ultrapassa os limites do tabuleiro!\n");
        }
    }

    // Posicionamento do Navio Vertical
    if (orientacaoV == 1) {
        // Valida se o navio não ultrapassa os limites do tabuleiro
        if (linhaNavioV + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaNavioV + i][colunaNavioV] = NAVIO;
            }
        } else {
            printf("Erro: Navio vertical ultrapassa os limites do tabuleiro!\n");
        }
    }

    // 4. Exibição do Tabuleiro
    printf("Tabuleiro de Batalha Naval:\n\n");
    
    // Imprime os cabeçalhos das colunas (0 a 9)
    printf("  ");
    for (int c = 0; c < TAMANHO_TABULEIRO; c++) {
        printf("%d ", c);
    }
    printf("\n");

    // Loop aninhado para exibir as linhas e colunas da matriz
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        // Imprime o cabeçalho da linha
        printf("%d ", i); 
        
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}


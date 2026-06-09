#include <stdio.h>

int main() {
    // 1. Definição do Tabuleiro 10x10
    int tabuleiro[10][10] = {0}; 
    // Exemplo de navio posicionado na linha 4, colunas 2, 3 e 4
    tabuleiro[4][2] = 3; tabuleiro[4][3] = 3; tabuleiro[4][4] = 3;

    // 2. Definição das Matrizes de Habilidade (5x5)
    int cone[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    int cruz[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };

    int octaedro[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    // 3. Ponto de Origem da Habilidade no Tabuleiro 10x10
    int origemLinha = 4;
    int origemColuna = 3;
    
    // Escolha qual habilidade aplicar (ex: cone)
    int (*habilidade)[5] = cone; 

    // 4. Lógica de Sobreposição
    int tamanhoHabilidade = 5;
    int deslocamento = tamanhoHabilidade / 2; // = 2

    for (int i = 0; i < tamanhoHabilidade; i++) {
        for (int j = 0; j < tamanhoHabilidade; j++) {
            if (habilidade[i][j] == 1) {
                // Calcula a linha e coluna real no tabuleiro
                int linhaTab = origemLinha - deslocamento + i;
                int colunaTab = origemColuna - deslocamento + j;

                // Verifica se a coordenada está dentro dos limites do tabuleiro 10x10
                if (linhaTab >= 0 && linhaTab < 10 && colunaTab >= 0 && colunaTab < 10) {
                    // Se a posição do tabuleiro possui um navio (valor 3), marca como atingido. 
                    // Se for água (valor 0), podemos marcar como atingido (ex: valor 8 ou -1)
                    if (tabuleiro[linhaTab][colunaTab] == 3) {
                        tabuleiro[linhaTab][colunaTab] = -1; // -1 indica dano
                    } else {
                        tabuleiro[linhaTab][colunaTab] = 8;  // 8 indica tiro na água
                    }
                }
            }
        }
    }

    // 5. Exibição do Tabuleiro atualizado
    printf("Tabuleiro Atualizado:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

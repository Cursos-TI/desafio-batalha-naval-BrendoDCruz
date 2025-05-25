#include <stdio.h>

int main() {
    char tabuleiro[10][10];
    int i, j;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = '0';
        }
    }

    char navio1[3] = {'3', '3', '3'};
    char navio2[3] = {'3', '3', '3'};

    int linha1 = 2, coluna1 = 2; 
    int linha2 = 0, coluna2 = 1; 

    if (coluna1 + 3 <= 10) {
        for (i = 0; i < 3; i++) {
            if (tabuleiro[linha1][coluna1 + i] == '3') {
                printf("Erro: sobreposição detectada no navio1.\n");
                return 1;
            }
        }
        for (i = 0; i < 3; i++) {
            tabuleiro[linha1][coluna1 + i] = navio1[i];
        }
    }

    if (linha2 + 3 <= 10) {
        for (i = 0; i < 3; i++) {
            if (tabuleiro[linha2 + i][coluna2] == '3') {
                printf("Erro: sobreposição detectada no navio2.\n");
                return 1;
            }
        }
        for (i = 0; i < 3; i++) {
            tabuleiro[linha2 + i][coluna2] = navio2[i];
        }
    }

    printf("\n   TABULEIRO  BATALHA  NAVAL\n");
    printf("   A B C D E F G H I J\n");

    for (i = 0; i < 10; i++) {
        if (i < 9)
            printf(" %d ", i + 1);
        else
            printf("%d ", i + 1);

        for (j = 0; j < 10; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
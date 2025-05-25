#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10

int main() {
    char tabuleiro[LINHAS][COLUNAS];
    int i, j;

    for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++) {
            tabuleiro[i][j] = '0';
        }
    }

    int l1 = 2, c1 = 1;
    int valido1 = 1;
    for (i = 0; i < 3; i++) {
        if (c1 + i >= COLUNAS || tabuleiro[l1][c1 + i] == '3') {
            valido1 = 0;
            break;
        }
    }
    if (valido1) {
        for (i = 0; i < 3; i++) {
            tabuleiro[l1][c1 + i] = '3';
        }
    }

    int l2 = 4, c2 = 5;
    int valido2 = 1;
    for (i = 0; i < 3; i++) {
        if (l2 + i >= LINHAS || tabuleiro[l2 + i][c2] == '3') {
            valido2 = 0;
            break;
        }
    }
    if (valido2) {
        for (i = 0; i < 3; i++) {
            tabuleiro[l2 + i][c2] = '3';
        }
    }

    int l3 = 0, c3 = 4;
    int valido3 = 1;
    for (i = 0; i < 3; i++) {
        if (l3 + i >= LINHAS || c3 + i >= COLUNAS || tabuleiro[l3 + i][c3 + i] == '3') {
            valido3 = 0;
            break;
        }
    }
    if (valido3) {
        for (i = 0; i < 3; i++) {
            tabuleiro[l3 + i][c3 + i] = '3';
        }
    }

    int l4 = 6, c4 = COLUNAS - 1;
    int valido4 = 1;
    for (i = 0; i < 3; i++) {
        if (l4 + i >= LINHAS || c4 - i < 0 || tabuleiro[l4 + i][c4 - i] == '3') {
            valido4 = 0;
            break;
        }
    }
    if (valido4) {
        for (i = 0; i < 3; i++) {
            tabuleiro[l4 + i][c4 - i] = '3';
        }
    }

    printf("\n   TABULEIRO  BATALHA  NAVAL\n   ");
    for (j = 0; j < COLUNAS; j++) {
        printf("%c ", 'A' + j);
    }
    printf("\n");

    for (i = 0; i < LINHAS; i++) {
        if (i < 9) printf(" %d ", i + 1);
        else printf("%d ", i + 1);

        for (j = 0; j < COLUNAS; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

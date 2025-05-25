#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10
#define TAM_HABILIDADE 5

void inicializaTabuleiro(char tabuleiro[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            tabuleiro[i][j] = '0';
        }
    }
}

void posicionaNavios(char tabuleiro[LINHAS][COLUNAS]) {
    for (int i = 0; i < 3; i++) tabuleiro[2][1 + i] = '3';   
    for (int i = 0; i < 3; i++) tabuleiro[4 + i][5] = '3';     
    for (int i = 0; i < 3; i++) tabuleiro[0 + i][4 + i] = '3'; 
    for (int i = 0; i < 3; i++) tabuleiro[6 + i][9 - i] = '3'; 
}

void criaMatrizCone(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (j >= 2 - i && j <= 2 + i) matriz[i][j] = 1;
            else matriz[i][j] = 0;
        }
    }
}

void criaMatrizCruz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == TAM_HABILIDADE / 2 || j == TAM_HABILIDADE / 2) matriz[i][j] = 1;
            else matriz[i][j] = 0;
        }
    }
}

void criaMatrizOctaedro(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int distLinha = i > centro ? i - centro : centro - i;
            int distColuna = j > centro ? j - centro : centro - j;
            if (distLinha + distColuna <= centro) matriz[i][j] = 1;
            else matriz[i][j] = 0;
        }
    }
}

void aplicaHabilidade(char tabuleiro[LINHAS][COLUNAS], int matriz[TAM_HABILIDADE][TAM_HABILIDADE], int origemLinha, int origemColuna) {
    int centro = TAM_HABILIDADE / 2;

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (matriz[i][j] == 1) {
                int linhaTab = origemLinha + i - centro;
                int colunaTab = origemColuna + j - centro;

                if (linhaTab >= 0 && linhaTab < LINHAS && colunaTab >= 0 && colunaTab < COLUNAS) {
                    if (tabuleiro[linhaTab][colunaTab] == '0') {
                        tabuleiro[linhaTab][colunaTab] = '5';
                    }
                }
            }
        }
    }
}

void exibeTabuleiro(char tabuleiro[LINHAS][COLUNAS]) {
    printf("\n   TABULEIRO BATALHA NAVAL\n   ");
    for (int j = 0; j < COLUNAS; j++) {
        printf("%c ", 'A' + j);
    }
    printf("\n");

    for (int i = 0; i < LINHAS; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < COLUNAS; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void lerOrigem(int *linha, int *coluna, const char *nomeHabilidade) {
    char letra;
    printf("\nDigite a linha e a coluna para aplicar a habilidade %s (ex: 5 D): ", nomeHabilidade);
    scanf("%d %c", linha, &letra);

    if (letra >= 'a' && letra <= 'z') {
        letra = letra - ('a' - 'A');
    }

    *linha -= 1;           
    *coluna = letra - 'A'; 
}

int main() {
    char tabuleiro[LINHAS][COLUNAS];
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    int linha, coluna;

    inicializaTabuleiro(tabuleiro);
    posicionaNavios(tabuleiro);

    criaMatrizCone(cone);
    criaMatrizCruz(cruz);
    criaMatrizOctaedro(octaedro);

    lerOrigem(&linha, &coluna, "Cone");
    aplicaHabilidade(tabuleiro, cone, linha, coluna);

    lerOrigem(&linha, &coluna, "Cruz");
    aplicaHabilidade(tabuleiro, cruz, linha, coluna);

    lerOrigem(&linha, &coluna, "Octaedro");
    aplicaHabilidade(tabuleiro, octaedro, linha, coluna);

    exibeTabuleiro(tabuleiro);

    return 0;
}

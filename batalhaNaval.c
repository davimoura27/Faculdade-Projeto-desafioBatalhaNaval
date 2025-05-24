#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define TAM_HABILIDADE 5
#define TAM_HABILIDADE2 2
#define TAM_HABILIDADE3 1

// Função para iniciar o tabuleiro com zeros
void iniciarTabuleiro(int t[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++)
        for (int j = 0; j < TAM_TABULEIRO; j++)
            t[i][j] = 0;
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int t[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("  ");
    for (int i = 0; i < TAM_TABULEIRO; i++) printf("%d ", i);
    printf("\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAM_TABULEIRO; j++)
            printf("%d ", t[i][j]);
        printf("\n");
    }
}

// Função para posicionar navios ou habilidades no tabuleiro
int posicaoNavio(int t[TAM_TABULEIRO][TAM_TABULEIRO], int lin, int col, char ori) {
    if (ori == 'H' || ori == 'V') {
        if ((ori == 'H' && col + TAM_NAVIO > TAM_TABULEIRO) ||
            (ori == 'V' && lin + TAM_NAVIO > TAM_TABULEIRO))
            return 0;

        for (int i = 0; i < TAM_NAVIO; i++) {
            int x = lin + (ori == 'V' ? i : 0);
            int y = col + (ori == 'H' ? i : 0);
            if (t[x][y] != 0) return 0;
        }
        for (int i = 0; i < TAM_NAVIO; i++) {
            int x = lin + (ori == 'V' ? i : 0);
            int y = col + (ori == 'H' ? i : 0);
            t[x][y] = 3;
        }
    }
    else if (ori == 'D') { // Diagonal direita
        if (lin + TAM_NAVIO > TAM_TABULEIRO || col + TAM_NAVIO > TAM_TABULEIRO)
            return 0;
        for (int i = 0; i < TAM_NAVIO; i++)
            if (t[lin + i][col + i] != 0) return 0;
        for (int i = 0; i < TAM_NAVIO; i++)
            t[lin + i][col + i] = 3;
    }
    else if (ori == 'C') { // Cone
        if (col + TAM_HABILIDADE > TAM_TABULEIRO) return 0;
        for (int i = 0; i < TAM_HABILIDADE; i++) {
            for (int j = -i; j <= i; j++) {
                int x = lin + i, y = col + j;
                if (x >= 0 && x < TAM_TABULEIRO && y >= 0 && y < TAM_TABULEIRO && t[x][y] == 0)
                    t[x][y] = 5;
            }
        }
    }
    else if (ori == 'X') { // Cruz
        if (lin < 0 || lin >= TAM_TABULEIRO || col < 0 || col >= TAM_TABULEIRO)
            return 0;
        t[lin][col] = 5;
        for (int i = 1; i <= TAM_HABILIDADE2; i++) {
            if (lin - i >= 0) t[lin - i][col] = 5;
            if (lin + i < TAM_TABULEIRO) t[lin + i][col] = 5;
            if (col - i >= 0) t[lin][col - i] = 5;
            if (col + i < TAM_TABULEIRO) t[lin][col + i] = 5;
        }
    }
    else if (ori == 'O') { // Octaedro (cruz menor)
        if (lin < 0 || lin >= TAM_TABULEIRO || col < 0 || col >= TAM_TABULEIRO)
            return 0;
        t[lin][col] = 5;
        for (int i = 1; i <= TAM_HABILIDADE3; i++) {
            if (lin - i >= 0) t[lin - i][col] = 5;
            if (lin + i < TAM_TABULEIRO) t[lin + i][col] = 5;
            if (col - i >= 0) t[lin][col - i] = 5;
            if (col + i < TAM_TABULEIRO) t[lin][col + i] = 5;
        }
    }
    else return 0; // Orientação inválida
    return 1;
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    iniciarTabuleiro(tabuleiro); // Inicializa com zeros

    // Posicionamentos com checagem
    if (!posicaoNavio(tabuleiro, 2, 4, 'H')) printf("Erro navio horizontal\n");
    if (!posicaoNavio(tabuleiro, 5, 7, 'V')) printf("Erro navio vertical\n");
    if (!posicaoNavio(tabuleiro, 0, 0, 'D')) printf("Erro navio diagonal\n");
    if (!posicaoNavio(tabuleiro, 7, 5, 'C')) printf("Erro cone\n");
    if (!posicaoNavio(tabuleiro, 6, 2, 'X')) printf("Erro cruz\n");
    if (!posicaoNavio(tabuleiro, 4, 6, 'O')) printf("Erro octaedro\n");

    exibirTabuleiro(tabuleiro); // Mostra o resultado final

    return 0;
}

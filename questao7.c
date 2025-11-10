#include <stdio.h>
#include <string.h>

#define LIN 5
#define COL 5

int buscarDirecao(char mat[LIN][COL], int l, int c, char palavra[], int dl, int dc) {
    int tam = strlen(palavra);

    for (int i = 0; i < tam; i++) {
        int nl = l + i * dl;
        int nc = c + i * dc;

        if (nl < 0 || nl >= LIN || nc < 0 || nc >= COL) return 0;
        if (mat[nl][nc] != palavra[i]) return 0;
    }

    return 1;
}

void procurarPalavra(char mat[LIN][COL], char palavra[]) {
    int direcoes[8][2] = {
        {0, 1},   // direita
        {0,-1},   // esquerda
        {1, 0},   // baixo
        {-1,0},   // cima
        {1, 1},   // diag baixo direita
        {1,-1},   // diag baixo esquerda
        {-1,1},   // diag cima direita
        {-1,-1}   // diag cima esquerda
    };

    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) {
            if (mat[i][j] == palavra[0]) {

                for (int d = 0; d < 8; d++) {
                    if (buscarDirecao(mat, i, j, palavra, direcoes[d][0], direcoes[d][1])) {
                        printf("Encontrada iniciando em (%d, %d) direção (%d, %d)\n",
                               i, j, direcoes[d][0], direcoes[d][1]);
                    }
                }
            }
        }
    }
}

void testQ7() {
    char matriz[LIN][COL] = {
        {'C','A','S','A','X'},
        {'B','A','R','A','K'},
        {'Q','U','E','S','T'},
        {'A','S','A','A','B'},
        {'Z','A','C','A','S'}
    };

    printf("TESTE 1:\n");
    procurarPalavra(matriz, "ASA");

    printf("\nTESTE 2:\n");
    procurarPalavra(matriz, "CASA");

    printf("\nTESTE 3:\n");
    procurarPalavra(matriz, "AAB");

    printf("\nTESTE 4:\n");
    procurarPalavra(matriz, "AR");
}

int main() {
    testQ7();
    return 0;
}

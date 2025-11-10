#include <stdio.h>
#include <string.h>

int contarOcorrencias(int N, int K) {
    char strN[30], strK[30];
    int cont = 0;

    sprintf(strN, "%d", N);
    sprintf(strK, "%d", K);

    int tamN = strlen(strN);
    int tamK = strlen(strK);

    for (int i = 0; i <= tamN - tamK; i++) {
        int j;
        for (j = 0; j < tamK; j++) {
            if (strN[i + j] != strK[j]) break;
        }
        if (j == tamK) cont++;
    }

    return cont;
}

void testQ6() {
    printf("TESTE 1: N=3539343, K=3 -> %d\n",
           contarOcorrencias(3539343, 3)); // 4

    printf("TESTE 2: N=5444, K=44 -> %d\n",
           contarOcorrencias(5444, 44)); // 1

    printf("TESTE 3: N=54444, K=44 -> %d\n",
           contarOcorrencias(54444, 44)); // 2

    printf("TESTE 4: N=1234562354, K=23 -> %d\n",
           contarOcorrencias(1234562354, 23)); // 2

    printf("TESTE 5: N=100100100, K=100 -> %d\n",
           contarOcorrencias(100100100, 100)); // 3

    printf("TESTE 6: N=7777, K=7 -> %d\n",
           contarOcorrencias(7777, 7)); // 4
}

int main() {
    testQ6();
    return 0;
}

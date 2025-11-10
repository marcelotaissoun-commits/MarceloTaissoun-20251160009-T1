#include<stdio.h>
#include<string.h>

#include "marcelotaissoun20251160009.h"

int ano_bissexto(int ano) {
    if (ano % 400 == 0) return 1;
    if (ano % 100 == 0) return 0;
    if (ano % 4 == 0) return 1;
    return 0;
}

int dias_no_mes(int mes, int ano) {
    switch (mes) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return ano_bissexto(ano) ? 29 : 28;
    }
    return 0;
}

int validar(int diaa, int mess, int anoo) {
    if (anoo < 1) return 0;
    if (mess < 1 || mess > 12) return 0;
    if (diaa < 1 || diaa > dias_no_mes(m, a)) return 0;
    return 1;
}

int main() {
    int dia1, mes1, ano1;
    int dia2, mes2, ano2;

    if (!validar(dia1, mes1, ano1) || !validar(dia2, mes2, ano2)) {
        printf("Alguma das datas eh invalida!\n");
        return 0;
    }

    if (ano2 < ano1 || (ano2 == ano1 && mes2 < mes1) || (ano2 == ano1 && mes2 == mes1 && dia2 < dia1)) {
        printf("Data final deve ser maior ou igual a inicial!\n");
        return 0;
    }

    int anos = ano2 - ano1;
    int meses = mes2 - mes1;
    int dias = dia2 - dia1;

    if (dias < 0) {
        meses--;
        int mes_prev = mes2 - 1;
        int ano_prev = ano2;
        if (mes_prev == 0) {
            mes_prev = 12;
            ano_prev--;
        }
        dias += dias_no_mes(mes_prev, ano_prev);
    }

    if (meses < 0) {
        meses += 12;
        anos--;
    }

void testQ2(){
    show_log("testQ2()");
    char datainicial[11], datafinal[11];
    int qtdDias, qtdMeses, qtdAnos;
    DiasMesesAnos dma;
    int retorno;

    //teste 1
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial, "01/06/2015");
    strcpy(datafinal, "01/06/2016");
    dma = q2(datainicial, datafinal);
    printf("%d\n", dma.retorno == 1);
    printf("%d\n", dma.qtdDias == 0);
    printf("%d\n", dma.qtdMeses == 0);
    printf("%d\n", dma.qtdAnos == 1);

    //teste 2 - retornos
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial,"01/30/2015");
    strcpy(datafinal,"01/06/2016");
    dma = q2(datainicial, datafinal);
    printf("%d\n",dma.retorno == 2);

    strcpy(datainicial,"01/3/2015");
    strcpy(datafinal,"40/06/2016");
    dma = q2(datainicial, datafinal);
    printf("%d\n",dma.retorno == 3);

    strcpy(datainicial,"01/06/2016");
    strcpy(datafinal,"01/06/2015");
    dma = q2(datainicial, datafinal);
    printf("%d\n",dma.retorno == 4);

    //teste 3
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial,"06/06/2017");
    strcpy(datafinal,"07/07/2017");
    dma = q2(datainicial, datafinal);
    printf("%d\n",dma.retorno == 1);
    printf("%d\n",dma.qtdDias == 1);
    printf("%d\n",dma.qtdMeses == 1);
    printf("%d\n",dma.qtdAnos == 0);

    //teste 4
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial,"06/06/2017");
    strcpy(datafinal,"05/07/2018");
    dma = q2(datainicial, datafinal);
    printf("%d\n",dma.retorno == 1);
    printf("%d\n",dma.qtdDias == 29);
    printf("%d\n",dma.qtdMeses == 0);
    printf("%d\n",dma.qtdAnos == 1);

    //teste 5
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datainicial,"26/07/2017");
    strcpy(datafinal,"25/08/2017");
    dma = q2(datainicial, datafinal);
    printf("%d\n",dma.retorno == 1);
    printf("%d\n",dma.qtdDias == 30);
    printf("%d\n",dma.qtdMeses == 0);
    printf("%d\n",dma.qtdAnos == 0);

    return 0;
}

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

void testQ1(){
    show_log("testQ1()");
    char str[11];
    strcpy(str,"29/02/2015");
    printf("%d\n",q1(str) == 0);
    strcpy(str,"29/02/2012");
    printf("%d\n",q1(str) == 1);
    strcpy(str,"9/13/2014");
    printf("%d\n",q1(str) == 0);
    strcpy(str,"45/4/2014");
    printf("%d\n",q1(str) == 0);
    strcpy(str,"12/1/15");
    printf("%d\n",q1(str) == 1);
    strcpy(str,"1/9/2016");
    printf("%d\n",q1(str) == 1);
    strcpy(str,"//2016");
    printf("%d\n",q1(str) == 0);
    strcpy(str,"1//20");
    printf("%d\n",q1(str) == 0);
    strcpy(str,"1/R/2016");
    printf("%d\n",q1(str) == 0);
    strcpy(str,"1/12/19");
    printf("%d\n",q1(str) == 1); 
   }
return 0;
}

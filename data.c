/*==========================================================
Entrada de datas e passagem dos valores utilizando ponteiro
============================================================*/

#include <stdio.h>
#include <stdlib.h>

struct data{
    int dia;
    int mes;
    int ano;

}; typedef struct data DMA;

void pegadata(DMA *d){

    printf("Dia: ");
        scanf("%d", &d->dia);

    printf("Mes: ");
        scanf("%d", &d->mes);

    printf("Ano: ");
        scanf("%d", &d->ano);
        printf("\n");
}

int main(){
    DMA dma;
    DMA *d;

    d = &dma;

    pegadata(d);

    system("clear");
    printf("\n");
    printf("\tData informada: %d/%d/%d\n\n", dma.dia, dma.mes, dma.ano);
    return 0;
}


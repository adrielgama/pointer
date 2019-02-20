/*
* 2) Faça um programa que tenha uma função troca que recebe dois parâmetros inteiros 
* e troque o valor das variáveis um pelo outro. A função main deve ler do usuário os 
* dois valores, chamar a função troca, e depois imprimir os valores trocados.
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//void troca(int *, int *);

void troca(int *x, int *y){
    int aux;

    aux = *x;
    *x = *y;
    *y = aux;
}

int main(){
    int a, b;

    printf("Primeiro numero: ");
    scanf("%d", &a);
    
    printf("Segundo numero: ");
    	scanf("%d", &b);

	printf("\n");

    /* Troca a e b -- passa enderecos */
    troca(&a, &b);
    
    printf("\nTrocados: %d e %d\n", a, b);
	
	return 0;
}

/*
* 3) Faça um programa que tenha uma função ordena que recebe um vetor de 
* inteiros e ordene os valores. A função main deve ler do usuário os valores 
* (ex. 5 valores), chamar a função ordena, e depois imprimir os valores ordenados.
*/


#include <stdio.h>
#include <stdlib.h>

#define TAM 5


void ordena(int vetor[]){ 
	int i, j, min, aux = 0;
	
	for(i = 0; i < TAM - 1; i++){
		min = i;
		for(j = i + 1; j < TAM; j++){
			if(vetor[j] < vetor[min]) 
				min = j;
     	}
     	
	if(i != min){
		aux = vetor[min];
		vetor[min] = vetor[i];
		vetor[i] = aux;
    }
  }
}

void imprime(int vetor[]){
	int i, j;
	
	printf("\nOrdenado: ");
	for(i = 0; i < TAM; i++){
    	printf("%d ", vetor[i]);
	}
}


int main(){
    int numeros[TAM];
    int i;
 
    for(i = 0 ; i < TAM ; i++){
        printf("Entre com o %d numero: ", i + 1);
        scanf("%d", &numeros[i]);
    }
 
 	ordena(numeros);
 	imprime(numeros);
    
    return 0;
}

/*
* 1) Crie um programa que defina variáveis do tipo int, char, string [10 posições], 
* float, double. Deve ser definido também uma variável ponteiro para cada um dos tipos 
* acima. Faça leituras (scanf) e escrita (printf) das variáveis primitivas e depois faça 
* o mesmo utilizando ponteiros.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){
	int inteiro;
	char caractere;
	char str[10];
	float fl;
	double db;
	
	int *ptrInt = &inteiro;
	char *ptrChar = &caractere;
	char *ptrStr;
	float *ptrfl = &fl;
	double *ptrDb = &db;
	
	ptrStr = str;
	
	printf("\nInt: ");
		scanf("%d", &inteiro);
		fflush(stdin);	
	printf("\nChar: ");
		scanf("%c", &caractere);
		fflush(stdin);	
	printf("\nString: ");
		scanf("%s", str);
		fflush(stdin);	
	printf("\nFloat: ");
		scanf("%f", &fl);
		fflush(stdin);
	printf("\nDouble: ");
		scanf("%lf", &db);
		fflush(stdin);
	printf("\n\n");
	

	printf("\tInt: %d\n", inteiro);
	printf("\tChar: %c\n", caractere);
	printf("\tString: %s\n", str);
	printf("\tFloat: %.2f\n", fl);
	printf("\tDouble: %.2lf\n", db);	
	
		printf("\n\n");
	
	printf("\t*Int: %d\n", *ptrInt);
	printf("\t*Char: %c\n", *ptrChar);
	printf("\t*String: %s\n", ptrStr);
	printf("\t*Float: %.2f\n", *ptrfl);
	printf("\t*Double: %.2lf\n", *ptrDb);
	
	return 0;
}

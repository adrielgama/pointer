/*=====================================================

Montar uma lista encadeada a partir dos valores que 
estão nas pilhas par e impar de forma alternada


Pilha PAR: 2 | 8 | 4
Pilha IMPAR: 1 | 13 

Lista: 2 -> 1 -> 8 -> 13 -> 4

=====================================================*/


#include <stdio.h>
#include <stdlib.h>

#define tam 10

struct pilhaPar{
	int top;
	int num[tam];
}; typedef struct pilhaPar Par;

struct pilhaImpar{
	int top;
	int num[tam];
}; typedef struct pilhaImpar Impar;

struct lista{
	int num;
	struct lista *prox;
}; typedef struct lista Lista;

/*======= Iniciando as funcoes =======*/
Par *par;
Impar *impar;
Lista *inicio;

Par* criaPilhaPar();
int Pilha_cheiaPar(Par *p);
Impar* criaPilhaImpar();
int Pilha_cheiaImpar(Impar *i);
void inserir_Pilha(Par *p, Impar *i, int num);
void libera_Pilha(Par* p, Impar* i);
void imprimePar(Par *p);
void imprimeImpar(Impar *i);
void inserirLista(Par *p, Impar *i);
void inserirPar(Par *p, int cont);
void inserirImpar(Impar *i, int cont);
void imprimeLista();

/*======= MAIN =======*/
int main(){

	par=criaPilhaPar();
	impar=criaPilhaImpar();
	inicio=NULL;
	int sair, num;
	
	
	/*======= Interacao com usuario =======*/
	/*do{
  		puts("Digite um numero: ");
		scanf("%d", &num);
		inserir_Pilha(par, impar,num);

		puts("Deseja sair?\n");
		puts("1-Nao\n");
		puts("0-Sim\n");
		scanf("%d", &sair);


	} while(sair!=0);*/


	inserir_Pilha(par,impar,4);
	inserir_Pilha(par,impar,13);
	inserir_Pilha(par,impar,8);
	inserir_Pilha(par, impar,1);
	inserir_Pilha(par,impar,2);
	imprimePar(par);
	imprimeImpar(impar);

  	inserirLista(par, impar);
  	imprimeLista();

  	libera_Pilha(par, impar);
  	free(inicio);
  	return 0;
}

/*======= Cria pilha par =======*/
Par* criaPilhaPar(){
	Par *p = (Par*) malloc (sizeof(Par));

	if(p != NULL)
		p->top = 0;

	return p;
}

/*======= Cria pilha impar =======*/
Impar* criaPilhaImpar(){
	Impar *i = (Impar*) malloc (sizeof(Impar));

	if(i != NULL)
		i->top = 0;

	return i;
}

/*======= Libera pilha =======*/
void libera_Pilha(Par* p, Impar* i){
	free(p);
	free(i);
}

/*======= Verifica pilha Par cheia =======*/
int Pilha_cheiaPar(Par *p){
	if(p == NULL)
		return -1;
	return (p->top == tam);
}

/*======= Verifica pilha Impar cheia =======*/
int Pilha_cheiaImpar(Impar *i){
	if(i == NULL)
		return -1;
	return (i->top == tam);
}

/*======= Inserir na PILHA =======*/
void inserir_Pilha(Par *p, Impar *i, int num){

	if(p != NULL && i != NULL){
		if(num % 2 == 0){
    		if(!Pilha_cheiaPar(p)){
        		p->num[p->top] = num;
        		p->top++;
      		} else{
        		puts("Pilha par cheia!!");
      	}
    } else{
    	if(!Pilha_cheiaImpar(i)){
        	i->num[i->top] = num;
        	i->top++;
      } else{
        	puts("Pilha impar cheia!!");
      	}
    }
  }
}

/*======= Imprime pilha Par =======*/
void imprimePar(Par *p){
	if(p->top == 0)
		printf("\nPilha vazia\n");
	else{
    	int i;
    	puts("PAR: ");
    	for(i = p->top - 1; i >= 0; i--)
      		printf(" %d ", p->num[i]);
  	}
}

/*======= Imprime pilha Impar =======*/
void imprimeImpar(Impar* im){
	if(im->top == 0)
		printf("\nPilha vazia\n");
  	else{
    	int i;
    	puts("\nIMPAR: ");
    	for(i = im->top - 1; i >= 0; i--)
      		printf(" %d ", im->num[i]);
  	}
}

/*======= Inserir na LISTA =======*/
void inserirLista(Par *p, Impar *i){
	int cont = 0;
    int par = p->top - 1, impar = i->top - 1;
    int total = p->top + i->top;

	do{
    	if(cont % 2 == 0){
      		inserirPar(p, par);
      		par--;
    	} else{
      		inserirImpar(i, impar);
      		impar--;
    	}
	cont++;
	} while(cont < total);
}

/*======= Inserir na lista Par =======*/
void inserirPar(Par *p, int cont){
	Lista *novo, *aux;
	novo = (Lista*) malloc (sizeof(Lista));
	aux =  inicio;

	if(aux == NULL){
		if(novo != NULL){
	    	novo->num = p->num[cont];
	    	novo->prox = inicio;
	    	inicio = novo;
    	}
  	} else{
  		
	    while(aux->prox != NULL)
	    	aux = aux->prox;
	    	
			novo->num = p->num[cont];
	    	aux->prox = novo;
	    	novo->prox = NULL;
  	}
}

/*======= Inserir na lista Impar =======*/
void inserirImpar(Impar *i, int cont){
	Lista *novo, *aux;
	novo = (Lista*) malloc (sizeof(Lista));
	aux = inicio;

	if(aux == NULL){
    	if(novo != NULL){
      		novo->num = i->num[cont];
      		novo->prox = inicio;
      		inicio = novo;
    	}
  	} else{

	    while(aux->prox != NULL)
	    	aux = aux->prox;
	
	    	novo->num = i->num[cont];
	    	aux->prox = novo;
	    	novo->prox = NULL;
  	}
}

/*======= Imprime a lista =======*/
void imprimeLista(){
	Lista* listar = inicio;

	if(listar == NULL)
    	printf("\nLista vazia\n");
  	
	else{
    	printf("\n\nLista Alternada: ");
    
		while(listar != NULL){ //esse while é diferente, pois esta pegando o conteudo de dentro, como um todo, se for colocar listar->prox só imprime o proximo.
	    	printf(" %d ", listar->num);
	    	listar = listar->prox;
	    }
  	}
}

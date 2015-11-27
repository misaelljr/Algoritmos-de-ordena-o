#include <stdio.h>

#define TAM_VET 10

void qsort(int*,int , int);                  /* funcao para ordenacao */
void criavetor(int *,int , int);             /* funcao auxiliar para gerar o vetor aleatorio */

int main(){
   int vetor[TAM_VET];
   int i;
   criavetor(vetor,TAM_VET,TAM_VET);
   printf("Estado Inicial:\n");
   for(i=0;i<TAM_VET;i++)
   {
      printf("%d ",vetor[i]);  
   }
   printf("\n");
   qsort(vetor,0,TAM_VET-1);
   printf("\nOrdenado:\n");
   for(i=0;i<TAM_VET;i++)
   {
      printf("%d ",vetor[i]);  
   }
   getchar();
   return 0;
}
/**
 * Funcao que ordena um vetor de inteiros utilizando o algoritmo QuickSort
 * @param *vet: ponteiro para o vetor a ser ordenado
 * @param inicio : posicao inicial do (sub)vetor a ser ordenado
 * @param fim : posicao final do (sub)veotr a ser ordenado
**/
void qsort(int *vet, int inicio, int fim){
   /* inicia os indices */
	int i = inicio;
	int j = fim;
	int tmp;
	/* verifica se ainda é necessário a ordenacao (> 2 elementos)  */
	if (i >= j)
   {
	    return;
	}
	/*  considera o elemento central como pivo*/
	int pivo = vet[inicio];
	/* 'corre' todo o vetor até que os indices se encontrem */
	while (i < j) 
   {
	    while (i<j && vet[i] < pivo) { i++; }              /* 'procura' por um elemento menor ou igual ao pivo*/
	    while (i<j && vet[j] > pivo) { j--; }              /* 'procura' por um elemento maior ou igual ao pivo*/
      /* troca os elementos encontrados se os indices nao tivem se cruzado*/
	    if (i < j)                           
       {
		    tmp= vet[i];
		    vet[i] = vet[j];
		    vet[j] = tmp;
		    i++;
		    j--;
	    }
	}
	/* se os indices se cruzaram, reorganiza os indices*/
	if (j < i)
   {
	    tmp = j;
	    j = i;
	    i = tmp;
	}
	/* ordernar o subvetor da esquerda */
	qsort(vet, inicio, i);
	/* se o pivo escolhido era o primeiro elemento, ordena os demais à direita*/
	if(i == inicio)
	{
      qsort(vet,i+1,fim);
   }
   else
   {
    /* ordena o subvetor a direta*/
     qsort(vet,i,fim);
   }
}
/**
 * Funcao que gera valores aleatório de 0 à max 
 * @param: *vet: ponteiro para o vetor destino dos números gerados
 * @param: tam: tamanho do vetor destino
 * @param: max: valor máximo para a faixa de valores gerados de 0 até max
**/
void criavetor(int *vet,int tam,int max)
{
	size_t t; 
	int i;
	srand(time(&t));
	for(i = 0;i < tam;i++)
   {
		vet[i]  = rand() % (max+1);
	}
}
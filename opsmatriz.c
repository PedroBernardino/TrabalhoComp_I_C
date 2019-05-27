#include <stdio.h>
#include "matriz.h"
#include <stdlib.h>
float * criaMatriz (int lin, int col)
{
	float *p;
	p = (float *) malloc (lin*col*sizeof(float));
	return p;
}
float * criaMatrizZero (int lin, int col)
{
	float *p;
	p = (float *) malloc (lin*col*sizeof(float));
	int i, j;
	for(i = 0;i<lin;i++)
	{
		for(j=0;j<col;j++)
		{
			*(p+(col*i)+j) = 0;
		}
	}
	return p;
}

void destroiMatriz(float * matriz)
{
	free(matriz);
}
void carregaMatrizTeclado (float * matriz, int lin, int col)
{
	int i,j;
	for(i=0;i<lin;i++)
	{
		for(j=0;j<col;j++)
		{
			scanf("%f", matriz+(col*i)+j);
		}
	}
}
float * carregaMatrizBinario (FILE * descArquivo);

unsigned short int leElementoMatriz (float * matriz, int lin, int col, int i, int j, float * elem)
{
	if(i>=lin || j>= col)
		return 0;
	*elem = *(matriz+(col*i)+j);
	return 1;
}


void imprimeMatriz (float * matriz, int lin, int col)
{
	int i,j;
	printf("\n");
	for(i=0;i<lin;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("%.2f ", *(matriz+(col*i)+j));
		}
		printf("\n");
	}
}
int main(void)
{
	float *p, *elemento;
	elemento = (float *) malloc (sizeof(float));
	p = criaMatriz(3,5);
	carregaMatrizTeclado(p, 3, 5);
	imprimeMatriz(p,3,5);
	leElementoMatriz(p,3,5,2,3,elemento);
	printf("%.2f", *elemento);
	return 0;
}
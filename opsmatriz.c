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

void salvaMatrizBinario (float * matriz, int lin, int col, char * nomeArquivo);

unsigned short int leElementoMatriz (float * matriz, int lin, int col, int i, int j, float * elem)
{
	if(i>=lin || j>= col)
		return 0;
	*elem = *(matriz+(col*i)+j);
	return 1;
}

float * somaMatrizes (float * matA, float * matB, int lin, int col)
{
	int i,j;
	float *soma;
	soma = criaMatriz(lin,col);
	for(i=0;i<lin;i++)
	{
		for(j=0;j<col;j++)
		{
			*(soma+(col*i)+j) = *(matA+(col*i)+j) + *(matB+(col*i)+j);
		}
	}
	return soma;
}

float * multiplicaMatrizes (float * matA, float * matB, int linA, int colA, int colB)
{
	int i, j,k;
	float *result, soma;
	result = criaMatriz(linA, colB);
	for(i=0;i<linA;i++)
	{
		for(j=0;j<colB;j++)
		{
			soma = 0;
			for(k=0;k<colA;k++)
			{
				soma+= *(matA+(colA*i)+k) * *(matB+(colB*k)+j);
			}
			*(result+(colB*i)+j) = soma;
		}
	}
	return result;
}


int main(void)
{
	float *p1, *p2;
	p1 = criaMatriz(2,2);
	p2 = criaMatriz(2,4);
	carregaMatrizTeclado(p1, 2, 2);
	carregaMatrizTeclado(p2, 2, 4);
	imprimeMatriz(multiplicaMatrizes(p1,p2,2,2,4),2,4);
	return 0;
}
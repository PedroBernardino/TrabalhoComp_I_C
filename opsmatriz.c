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
float * carregaMatrizBinario (FILE * descArquivo)
{
	float *mat;
	int lin, col;
	fread(&lin,sizeof(int),1,descArquivo);
	fread(&col,sizeof(int),1,descArquivo);
	mat = criaMatriz(lin,col);
	fread(mat,sizeof(float),lin*col,descArquivo);
	return mat;
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

void salvaMatrizBinario (float * matriz, int lin, int col, char * nomeArquivo)
{
	FILE *p;
	p = fopen(nomeArquivo, "wb");
	fwrite(&lin, sizeof(int), 1, p);
	fwrite(&col, sizeof(int), 1, p);
	fwrite(matriz, sizeof(float), lin*col, p);
	fclose(p);
}

unsigned short int leElementoMatriz (float * matriz, int lin, int col, int i, int j, float * elem)
{
	if(i>=lin || j>= col)
		return 0;
	*elem = *(matriz+(col*i)+j);
	return 1;
}

unsigned short int alteraElementoMatriz (float * matriz, int lin, int col, int i, int j, float novoElem)
{
	if(i>=lin || j>= col)
		return 0;
	*(matriz+(col*i)+j) = novoElem;
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

float * transpostaMatriz (float * mat, int lin, int col)
{
	int i, j;
	float *transp;
	transp = criaMatriz(col,lin);
	for(i=0;i<col;i++)
		for (j = 0; j < lin; ++j)
		{
			*(transp+(lin*i)+j) = *(mat+(col*j)+i);
		}
	return transp;
}
unsigned short int ehMatrizIdentidade (float * mat, int lin, int col)
{
	int i,j;
	if(lin != col)
		return 0;
	for(i=0;i<lin;i++)
	{
		for(j=0;j<col;j++)
		{
			if((i==j && *(mat+(col*i)+j) != 1) || (i!=j && *(mat+(col*i)+j) != 0))
				return 0;
		}
	}
	return 1;
}

unsigned short int ehMatrizTriangularSuperior (float * mat, int lin, int col)
{
	int i,j;
	if(lin != col)
		return 0;
	for(i = 1;i<lin;i++)
	{
		for(j=i-1;j>=0;j--)
		{
			if(*(mat+(col*i)+j) != 0)
				return 0;
		}
	}
	return 1;
}

unsigned short int ehMatrizTriangularInferior (float * mat, int lin, int col)
{
	int i,j;
	if(lin != col)
		return 0;
	for(i=0;i<lin;i++)
	{
		for(j=i+1;j<col;j++)
		{
			if(*(mat+(col*i)+j) != 0)
				return 0;	
		}
	}
	return 1;
}

unsigned short int somaAdjacentesElementoMatriz (float * matriz, int lin, int col, int i, int j, float * soma)
{
	int a, b;
	*(soma) = 0;
	if(i>=lin || j>= col)
	{
		return 0;
	}
	for(a=i-1;a<=i+1;a++)
	{
		for(b=j-1;b<=j+1;b++)
		{
			if(a<lin && b<col)
			{ 
				*(soma) += *(matriz+(col*a)+b);
			}
		}
	}
	*(soma) -= *(matriz+(col*i)+j);
	return 1;
}

int main(void)
{
	float *p, *soma;
	p = criaMatriz(1,1);
	soma = criaMatriz(1,1);
	carregaMatrizTeclado(p,1,1);
	somaAdjacentesElementoMatriz(p,1,1,0,0,soma);
	printf("%f\n", *(soma));
}
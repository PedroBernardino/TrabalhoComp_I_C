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

unsigned short int alteraElementoMatriz (float * matriz, int lin, int col, int i, int j, float novoElem);

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

int main(void)
{
	float *p;
	p = criaMatriz(2,4);
	carregaMatrizTeclado(p, 2, 4);
	imprimeMatriz(p,2,4);
	salvaMatrizBinario(p,2,4,"matrizbin.dat");
	FILE *a;
	a = fopen("matrizbin.dat","rb");
	imprimeMatriz(carregaMatrizBinario(a),2,4);
	fclose(a);
	return 0;
}
#include <stdio.h>
#include "matriz.h"
#include <stdlib.h>
float * criaMatriz (int lin, int col) 
// cria uma matriz com as dimensões definidas nos parâmetros de entrada
{
	float *p;
	p = (float *) malloc (lin*col*sizeof(float));
	return p;
}
float * criaMatrizZero (int lin, int col)
//cria uma matriz totalmente zerada com as dimensões dos parâmetros de entrada
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
//apaga a matriz da memória
{
	free(matriz);
}

void carregaMatrizTeclado (float * matriz, int lin, int col)
// recebe uma matriz lin x col do teclado e armazena na matriz dada 
{
	int i,j;
	for(i=0;i<lin;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("Insira a posicao [%d] [%d]:", i, j);
			scanf("%f", matriz+(col*i)+j);
		}
	}
}
float * carregaMatrizBinario (FILE * descArquivo, int * lin, int *col)
{
	float *mat;
// le os 2 primeiros ints do arquivo, que são as dimensões da matriz
	fread(lin,sizeof(int),1,descArquivo);
	fread(col,sizeof(int),1,descArquivo);
	mat = criaMatriz(*(lin),*(col));
// le a matriz lin x col do arquivo
	fread(mat,sizeof(float),*(lin)**(col),descArquivo);
	return mat;
}


void imprimeMatriz (float * matriz, int lin, int col)
//imprime uma matriz salva na tela
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
//guarda uma matriz dada em um arquivo binario
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
//retorna 0 caso o elemento não exista na matriz
		return 0;
	*elem = *(matriz+(col*i)+j);
//retorna 1 e devolve no ponteiro elem o valor do elemento na matriz, caso ele exista
	return 1;
}

unsigned short int alteraElementoMatriz (float * matriz, int lin, int col, int i, int j, float novoElem)
{
	if(i>=lin || j>= col)
//retorna 0 caso o elemento não exista na matriz
		return 0;
	*(matriz+(col*i)+j) = novoElem;
//retorna 1 e altera o valor do elemento na matriz, caso ele exista
	return 1;
}

float * somaMatrizes (float * matA, float * matB, int lin, int col)
//soma duas matrizes com a restrição de que elas tem as mesmas dimensões
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
// multiplica duas matrizes tendo como restrição que o num de linhas de uma é igual ao num de colunas da outra
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
				soma+= *(matA+(colA*i)+k) * *(matB+(colB*k)+j); //multiplica cada elemento de colA com seu par de linB e acumula para gerar o elemento [linA][colB] da matriz resposta
			}
			*(result+(colB*i)+j) = soma;
		}
	}
	return result;
}

float * transpostaMatriz (float * mat, int lin, int col)
//retorna a matriz dada transposta
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
//retorna 0 caso a matriz não seja identidade, 1 caso seja
{
	int i,j;
	if(lin != col)
// testa se a matriz é quadrada, senão não pode ser identidade
		return 0;
	for(i=0;i<lin;i++)
	{
		for(j=0;j<col;j++)
		{
//testa se cada elemento na diagonal é 1 e os demais são 0
			if((i==j && *(mat+(col*i)+j) != 1) || (i!=j && *(mat+(col*i)+j) != 0))
				return 0;
		}
	}
//caso ele saia do for sem retornar 1, a matriz é identidade
	return 1;
}

unsigned short int ehMatrizTriangularSuperior (float * mat, int lin, int col)
// retorna 1 se a matriz é triangular superior, 0 caso contrário
{
	int i,j;
	if(lin != col)
//a matriz deve ser quadrada
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
// retorna 1 caso a matriz seja triangular ingerior, 0 caso contrário
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
//caso o elemento não exista na matriz, retorna 0
		return 0;
	}
	for(a=i-1;a<=i+1;a++)
//for que varre uma matriz 3x3 tendo o elemento como ponto central
	{
		for(b=j-1;b<=j+1;b++)
		{
			if(a<lin && b<col)
// testa se cada um desses elementos existe na matriz
			{ 
// caso exista, adiciona ao ponteiro acumulador soma
				*(soma) += *(matriz+(col*a)+b);
			}
		}
	}
//no fim, basta apenas retirar o valor do elemento central, pois ele não deve ser considerado na soma adjacente
	*(soma) -= *(matriz+(col*i)+j);
	return 1;
}
/*
int main(void)
{
	float *p, *soma;s
	p = criaMatriz(1,1);
	soma = criaMatriz(1,1);
	carregaMatrizTeclado(p,1,1);
	somaAdjacentesElementoMatriz(p,1,1,0,0,soma);
	printf("%f\n", *(soma));
}*/

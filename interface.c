#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"


// deve ser usado com janela de terminal em 35 linhas e 113 colunas //

//funcao para dar espacos para alinhar em relacao ao canto esquerdo da tela do terminal//
void margem(void){
    printf("                                ");
}
void mostraOpcoesMenu(void){
    margem(); printf("--> Digite 1 para carregar matriz do teclado\n");
    margem(); printf("--> Digite 2 para carregar matriz do arquivo binario \n");
    margem(); printf("--> Digite 3 para imprimir matriz\n");
    margem(); printf("--> Digite 4 para salvar uma matriz em um arquivo binario\n");
    margem(); printf("--> Digite 5 para alterar um elemento da matriz\n");
    margem(); printf("--> Digite 6 para somar duas matrizes\n");
    margem(); printf("--> Digite 7 para multiplicar duas matrizes\n");
    margem(); printf("--> Digite 8 para transpor uma matriz\n");
    margem(); printf("--> Digite 9 para verificar se eh indentidade ou triangular\n");
    margem(); printf("--> Digite 10 para somar os elementos adjacentes de um dado elemento da matriz\n");
    margem(); printf("--> Digite 11 para terminar o programa \n\n");
}

//funcao para mostrar o titulo grande.
void printHeader(){
    int c;
    FILE * menuFilePointer;
    menuFilePointer = fopen("menu.txt", "r");
    //testando se abriu com sucesso//
    if(menuFilePointer == NULL){
        printf("erro ao carregar arquivo\n");
        exit(1);
    }
    system("clear");
    while((c = fgetc(menuFilePointer)) != EOF){
        printf("%c", c);
    }
    printf("\n\n\n");
    fclose(menuFilePointer);
}

//funcao para perguntar se o usuario deseja continuar no programa ou sair//
void continua(){
    int result = 0;
    while(!result){
        char escolha_continuar; // variavel que armazena a escolha do usuario nos loops de continuacao//
        getchar();
        printf("Deseja continuar?[s/n]:");
        scanf("%c", &escolha_continuar);
        if(escolha_continuar == 'n' || escolha_continuar == 'N'){
            exit(1);
        }else if( escolha_continuar == 's' || escolha_continuar == 'S'){
            return;
        }
    }
}


int main(){
    int menuEscolha, lin, col, posicaoLin, posicaoCol, auxLin, auxCol;
    float * matrizPointer, * auxMatrizPointer, *soma, elemento;
    FILE * matrizFilePointer;
    char nomeArquivo[20];
    matrizPointer = NULL;
    soma = (float *) malloc(sizeof(float));

    do{
        printHeader();
        mostraOpcoesMenu();
        scanf("%d", &menuEscolha);
        
        switch(menuEscolha){
            case 1:
                printHeader();
                printf("Insira a dimensao da matriz:[lin] [col]:");
                scanf("%d %d", &lin, &col);
                matrizPointer = criaMatriz(lin, col);
                carregaMatrizTeclado( matrizPointer, lin, col);
                imprimeMatriz( matrizPointer, lin, col);

                //para o usuario poder visualizar a matriz e prosseguir//
                continua();
                break;
            case 2:
                printHeader();
                printf("insira o nome do arquivo:");
                scanf("%s", nomeArquivo);
                printf("insira as dimensoes da matriz de destino:[lin] [col]:");
                scanf("%d %d", &lin, &col);
                matrizPointer = criaMatriz(lin,col);
                matrizFilePointer = fopen(nomeArquivo, "rb");
                matrizPointer = carregaMatrizBinario(matrizFilePointer, &lin, &col);
                printf("matriz carregada: \n");
                imprimeMatriz( matrizPointer, lin, col);
                continua();
                break;
            case 3:
                if(matrizPointer != NULL){
                    imprimeMatriz(matrizPointer, lin, col);
                }else{
                    printf("Nenhuma matriz no programa...\n");
                }
                continua();
                break;
            case 4:
                printHeader();
                printf("Insira a dimensao da matriz:[lin] [col]:");
                scanf("%d %d", &lin, &col);
                matrizPointer = criaMatriz(lin, col);
                printf("Insira o nome do arquivo que deseja salvar:");
                scanf("%19s", nomeArquivo);
                carregaMatrizTeclado(matrizPointer, lin, col);
                salvaMatrizBinario(matrizPointer, lin, col, nomeArquivo);
                printf("matriz salva em %s \n", nomeArquivo);
                imprimeMatriz(matrizPointer,lin, col);
                continua();
                break;
            case 5:
                printHeader();
                if(matrizPointer != NULL){
                    printf("Insira a posicao do elemento que deseja alterar:[lin] [col]:");
                    scanf("%d %d", &posicaoLin, &posicaoCol);
                    printf("Insira o novo valor:");
                    scanf("%f", &elemento);
                    if(alteraElementoMatriz(matrizPointer, lin, col, posicaoLin, posicaoCol, elemento))
			puts("Elemento alterado com sucesso");
		    else printf("O Elemento nao existe na matriz\n");
                    imprimeMatriz(matrizPointer, lin, col);
                }else{
                    printf("Nenhuma matriz no programa...");
                }
                continua();
                break;
            case 6:
                printHeader();
                printf("Insira a dimensao das matrizes:[lin] [col]:");
                scanf("%d %d", &lin , &col);
                matrizPointer = criaMatriz(lin, col);
                auxMatrizPointer = criaMatriz(lin, col);
                printf("preencha a primeira matriz a ser somada:\n");
                carregaMatrizTeclado(matrizPointer, lin, col);
                printf("preencha a segunda matriz a ser somada:\n");
                carregaMatrizTeclado(auxMatrizPointer, lin, col);
                matrizPointer = somaMatrizes(matrizPointer, auxMatrizPointer, lin, col);
                printf("O resultado eh:\n");
                imprimeMatriz(matrizPointer, lin, col);
                continua();
                break;
            case 7:
                printHeader();
                printf("Insira a dimensao da primeira matriz:[lin] [col]:");
                scanf("%d %d",&lin, &col);
                printf("Insira a dimensao da segunda matriz:[lin] [col]:");
                scanf("%d %d",&auxLin, &auxCol);
                matrizPointer = criaMatriz(lin, col);
                auxMatrizPointer = criaMatriz(auxLin, auxCol);
                printf("Preencha primeira matriz:\n");
                carregaMatrizTeclado(matrizPointer, lin, col);
                printf("Preencha segunda matriz:\n");
                carregaMatrizTeclado(auxMatrizPointer, auxLin, auxCol);
                matrizPointer = multiplicaMatrizes (matrizPointer,auxMatrizPointer, lin, col, auxCol);
                printf("O resultado eh:\n");
                imprimeMatriz(matrizPointer, lin, col);
                continua();
                break;
            case 8:
                printHeader();
                if(matrizPointer != NULL){
                    matrizPointer = transpostaMatriz(matrizPointer, lin, col);
                    printf("A matriz transposta eh:\n");
                    imprimeMatriz(matrizPointer, lin, col);
                }else{
                    printf("nenhuma matriz no programa...\n");
                }
                continua();
                break;
            case 9:
                printHeader();
                if(matrizPointer != NULL){
                    if(ehMatrizIdentidade(matrizPointer, lin,col)){
                        printf("eh identidade\n");
                    }else if(ehMatrizTriangularSuperior(matrizPointer, lin, col)){
                        printf("eh tringular superior\n");
                    }else if(ehMatrizTriangularInferior(matrizPointer,lin,col)){
                        printf("eh triangular inferior\n");
                    }else{
                        printf("nao eh triangular nem identidade.\n");
                    }
                }else{
                    printf("Nenhuma matriz no programa...\n");
                }
                continua();
                break;
            case 10:
                printHeader();
                if(matrizPointer != NULL)
		{
                    printf("Insira a posicao do elemento para soma:[lin] [col]:");
                    scanf("%d %d",&posicaoLin, &posicaoCol);
                    if(somaAdjacentesElementoMatriz (matrizPointer, lin, col, posicaoLin, posicaoCol, soma))
                    	printf("A soma eh: %.1f\n", *(soma));
		    else printf("Elemento nao existe na matriz\n");
                }
		else
                    printf("Nenhuma matriz no programa...\n");
                
                continua();
        }
    }while (menuEscolha != 11);
    return 0;
}

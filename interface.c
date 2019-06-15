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
    margem(); printf("--> Digite 3 para imprimir uma matriz na tela\n");
    margem(); printf("--> Digite 4 para salvar uma matriz em um arquivo binario\n");
    margem(); printf("--> Digite 5 para alterar um elemento da matriz\n");
    margem(); printf("--> Digite 6 para somar duas matrizes\n");
    margem(); printf("--> Digite 7 para multiplicar duas matrizes\n");
    margem(); printf("--> Digite 8 para transpor uma matriz\n");
    margem(); printf("--> Digite 9 para verificar se eh indentidade ou triangular\n");
    margem(); printf("--> Digite 10 para somar os elementos adjacentes de um dado elemento da matriz\n");
    margem(); printf("--> Digite 11 para terminar o programa \n\n");
}
void PrintMenu(){
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
int continua(){
    int result = 0;
    while(!result){
        char escolha_continuar; // variavel que armazena a escolha do usuario nos loops de continuacao//
        getchar();
        printf("Deseja continuar?[s/n]:");
        scanf("%c", &escolha_continuar);
        if(escolha_continuar == 'n' || escolha_continuar == 'N'){
            exit(1);
        }else if( escolha_continuar == 's' || escolha_continuar == 'S'){
            return 1;
        }
    }
}


int main(){
    int menuEscolha, lin, col;
    float * matrizPointer;
    FILE * matrizFilePointer;
    char nomeArquivo[20];

    do{
        PrintMenu();
        mostraOpcoesMenu();
        scanf("%d", &menuEscolha);
        
        switch(menuEscolha){
            case 1:
                PrintMenu();
                printf("Insira a dimensao da matriz:[lin] [col]:");
                scanf("%d %d", &lin, &col);
                matrizPointer = criaMatriz(lin, col);
                carregaMatrizTeclado( matrizPointer, lin, col);
                imprimeMatriz( matrizPointer, lin, col);

                //para o usuario poder visualizar a matriz e prosseguir//
                continua();
                break;
            case 2:
                PrintMenu();
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

            //case 3://
            case 4:
                PrintMenu();
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
            /*case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:*/
        }
    }while (menuEscolha != 11);
    return 0;
}
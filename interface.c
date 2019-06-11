#include <stdio.h>
#include <stdlib.h>


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

int main(){
    int c,menuEscolha;
    FILE * menuFilePointer;
    menuFilePointer = fopen("menu.txt", "r");
    //testando se abriu com sucesso//
    if(menuFilePointer == NULL){
        printf("erro ao carregar arquivo\n");
        return -1;
    }

    //esvaziando a tela e mostrando o menu//
    system("clear");
    while((c = fgetc(menuFilePointer)) != EOF){
        printf("%c", c);
    }
    printf("\n\n\n");
    
    // opcoes do menu //
    mostraOpcoesMenu();

    

    
/*
    do{
        scanf("%d", &menuEscolha);
        switch(menuEscolha){
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            default:
        }
    }while (menuEscolha != 11);
*/
    fclose(menuFilePointer);
    return 0;
}
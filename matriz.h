/*
Define um conjunto de operacoes sobre matriz.
*/

/* Cria uma matriz de float vazia */
/* Entrada: dimensoes da matriz (numero de linhas e colunas) */ 
/* Saida: a matriz criada (ponteiro para float) */ 
float * criaMatriz (int lin, int col);

/* Cria e inicializa uma matriz de float com todos os elementos iguais a zero */
/* Entrada: dimensoes da matriz (numero de linhas e colunas) */ 
/* Saida: a matriz criada (ponteiro para float) com seus elementos iguais a zero */ 
float * criaMatrizZero (int lin, int col);

/* Destroi uma matriz previamente alocada (libera o espaco de memoria ocupado por ela) */
/* Entrada: matriz (ponteiro para float) */ 
/* Saida: <vazio> */ 
void destroiMatriz(float * matriz);

/* Carrega uma matriz da entrada padrao (teclado) */ 
/* Entrada: uma matriz e suas dimensoes */ 
/* Saida: a matriz com todos os seus valores alterados (lidos da entrada padrao) */ 
void carregaMatrizTeclado (float * matriz, int lin, int col);

/* Carrega uma matriz de um arquivo binario */ 
/* Entrada: o descritor do arquivo binario de onde a matriz sera carregada (previamente aberto para leitura binaria) */ 
/* Saida: a matriz criada e carregada do arquivo de entrada */
/* Restricao: assume que o arquivo de entrada tem o seguinte conteudo: numero de linhas da matriz (int), numero de colunas da matriz (int), sequencia de elementos da matriz, linha por linha (float) */ 
float * carregaMatrizBinario (FILE * descArquivo);

/* Imprime uma matriz na tela */ 
/* Entrada: uma matriz e suas dimensoes */ 
/* Saida: a matriz impressa na tela */ 
/* Descricao: devera exibir cada linha da matriz em uma linha separada na tela, separando os elementos de cada linha com um espaco em branco
*/
void imprimeMatriz (float * matriz, int lin, int col);

/* Salva uma matriz em um arquivo binario */ 
/* Entrada: uma matriz, suas dimensoes e o nome do arquivo de saida */ 
/* Saida: <vazio> */ 
/* Descricao: o arquivo de saida devera ter o seguinte conteudo: numero de linhas da matriz (int), numero de colunas da matriz (int), sequencia de elementos da matriz, linha por linha (float) */ 
void salvaMatrizBinario (float * matriz, int lin, int col, char * nomeArquivo);

/* Le um elemento da matriz */
/* Entrada: uma matriz, suas dimensoes, os indices (i,j) do elemento a ser lido */ 
/* Saida: o elemento lido e a sinalizacao se a operacao ocorreu com sucesso ou nao */
/* Descricao: se a posicao (i,j) nao existir na matriz, a funcao devera apenas retornar 0, caso a posicao exista, a funcao devera copiar o valor do elemento para a variavel passada por referencia e retornar 1 */ 
unsigned short int leElementoMatriz (float * matriz, int lin, int col, int i, int j, float * elem);

/* Altera um elemento da matriz */
/* Entrada: uma matriz, suas dimensoes, os indices (i,j) do elemento a ser alterado e o novo elemento */ 
/* Saida: a matriz com o elemento na posicao indicada alterado e a sinalizacao se a operacao ocorreu com sucesso ou nao */
/* Descricao: se a posicao (i,j) nao existir na matriz, a funcao devera apenas retornar 0, caso a posicao exista, a funcao devera alterar o elemento dessa posicao e retornar 1 */ 
unsigned short int alteraElementoMatriz (float * matriz, int lin, int col, int i, int j, float novoElem);

/* Soma duas matrizes */
/* Entrada: as duas matrizes e suas dimensoes (numero de linhas e colunas) */ 
/* Saida: a matriz resultante da soma das matrizes de entrada */
/* Restricao: assume que as dimensoes das matrizes de entrada sao identicas */ 
float * somaMatrizes (float * matA, float * matB, int lin, int col);

/* Multiplica duas matrizes */
/* Entrada: as duas matrizes e suas dimensoes (numero de linhas e colunas) */ 
/* Saida: a matriz resultante da multiplicacao das matrizes de entrada */
/* Restricao: assume que o numero de colunas da primeira matriz eh igual ao numero de linhas da segunda matriz */ 
float * multiplicaMatrizes (float * matA, float * matB, int linA, int colA, int colB);

/* Gera a matriz transposta da matriz dada */
/* Entrada: a matriz e suas dimensoes (numero de linhas e colunas) */ 
/* Saida: a matriz resultante da transposicao da matriz de entrada */
float * transpostaMatriz (float * mat, int lin, int col);

/* Verifica se a matriz de entrada eh uma matriz identidade */
/* Entrada: a matriz e suas dimensoes (numero de linhas e colunas) */ 
/* Saida: 1 se eh uma matriz identidade e 0 caso contrario */
unsigned short int ehMatrizIdentidade (float * mat, int lin, int col);

/* Verifica se a matriz de entrada eh uma matriz triangular superior */
/* Entrada: a matriz e suas dimensoes (numero de linhas e colunas) */ 
/* Saida: 1 se eh uma matriz triangular superior e 0 caso contrario */
unsigned short int ehMatrizTriangularSuperior (float * mat, int lin, int col);

/* Verifica se a matriz de entrada eh uma matriz triangular inferior */
/* Entrada: a matriz e suas dimensoes (numero de linhas e colunas) */ 
/* Saida: 1 se eh uma matriz triangular inferior e 0 caso contrario */
unsigned short int ehMatrizTriangularInferior (float * mat, int lin, int col);

/* Soma os elementos adjacentes a um dado elemento da matriz */
/* Entrada: uma matriz, suas dimensoes, os indices (i,j) do elemento dereferencia */ 
/* Saida: a soma dos valores dos elementos da matriz adjacentes ao elemento dado e a sinalizacao se a operacao ocorreu com sucesso ou nao */
/* Descricao: se a posicao (i,j) nao existir na matriz, a funcao devera apenas retornar 0, caso a posicao exista, a funcao devera copiar a soma calculada para a variavel passada por referencia e retornar 1 */ 
unsigned short int somaAdjacentesElementoMatriz (float * matriz, int lin, int col, int i, int j, float * soma);


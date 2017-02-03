/* matriz.h
 * funções para manipulação de matrizes 
 * projeto desenvolvido para a disciplina Programação Estruturada na Universidade Federal do ABC, em novembro de 2016
 * Mariana Gregório Candido
 * colaboração: Wellington Souza Marques
 */
 
#ifndef MATRIZ_H
#define MATRIZ_H


/* aloca um array 2D na memória */
int ** aloca (int i, int j);

/* copia uma matriz */
int ** copia (int ** matriz,int i, int j);

/* verifica se uma linha só tem zeros */
int linha_nula (int * linha, int n);

/* verifica se uma coluna só tem zeros */
int coluna_nula (int ** matriz, int i, int j);

/* verifica se uma linha só tem zeros */
void remove_coluna (int ** matriz,int i, int j,int n);

/* verifica se uma coluna só tem zeros */
void remove_linha (int ** matriz, int i, int j, int n);

/* remove as colunas e linhas que só contiverem elementos nulos */
int ** reduz_matriz (int ** matriz, int i, int j);  

/* rotaciona uma matriz 4x4 uma vez no sentido horário */
int ** rotaciona (int ** matriz);

/* acrescenta uma linha de zeros no topo - complemento da remove_linha */
void nova_linha (int ** matriz, int i, int j);

/* imprime uma matriz */
void print_matriz (int ** matriz, int i, int j);


#endif

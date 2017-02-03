/* tetris.h
 * funções referentes ao jogo 
 * projeto desenvolvido para a disciplina Programação Estruturada na Universidade Federal do ABC, em novembro de 2016
 * Mariana Gregório Candido
 * colaboração: Wellington Souza Marques
 */
 
#include <stdlib.h>

#ifndef TETRIS_H
#define TETRIS_H

typedef struct tetrimino { 
    int ** pos1;
    int i_pos1,j_pos1;
    int ** pos2;
    int i_pos2,j_pos2;
    int ** pos3;
    int i_pos3,j_pos3;
    int ** pos4;
    int i_pos4, j_pos4;
}tetrimino;

/* inicializa o jogo */
int ** inicio (int ** jogo);

/* aloca as 4 posições de cada peça */
void aloca_pecas (tetrimino pecas[]);

/* cria a peça base */
void primeira_peca (tetrimino pecas[]);

/*cria peça por peça */
void peca_atual(tetrimino pecas[],int p);

/* inicializa a lista de peças, com suas rotações possíveis */
void cria_pecas (tetrimino pecas[]);

/* reduz as dimenões das matrizes das peças às mínimas possíveis */
void reduz_pecas (tetrimino * pecas, int n);

/* verifica se a linha foi preenchida */
int linha (int * linha, int n); 

/* verifica quantas linhas foram preenchidas */
int num_linhas (int ** matriz, int lin, int col);

/* verifica espaços bloqueados num possível estado do jogo */
int bloqueados (int ** matriz, int i, int j);

/* verifica a altura máxima de um possível estado do jogo */
int altura (int ** matriz, int i, int j); //se altura = n-1, fim de jogo

/* encaixa uma peça em uma determinada coluna - de 0 a 8 */
int ** encaixa (int ** jogo, int ** peca, int lin_peca, int col_peca, int col);

/* calcula a pontuação de um possível estado do jogo */
int score (int ** matriz);

/* atualiza o jogo com o melhor estado possível */
int ** best_score (int ** matriz, tetrimino peca, int lin_peca, int col_peca, int col_max);

/* remove linhas prenchidas */
void apaga_preenchidas (int ** matriz, int i, int j);

#endif

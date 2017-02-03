/* principal.c
 * algoritmo para simular um jogo de tetris
 * projeto desenvolvido para a disciplina Programação Estruturada na Universidade Federal do ABC, em novembro de 2016
 * Mariana Gregório Candido
 * colaboração: Wellington Souza Marques
 */

#include <stdio.h>
#include <stdlib.h> 
#include <time.h>  
#include "tetris.h"
#include "matriz.h"


tetrimino pecas [7];                                    

int ** jogo;

int main ( )
{
    srand(time(NULL));
    jogo = inicio(jogo);            
    aloca_pecas(pecas);             
    cria_pecas(pecas);              
    int i,j;
    int jogadas;
    printf("Digite o número de jogadas: ");
    scanf("%d",&jogadas);
 
 while(jogadas){                                  
    int prox_peca = rand()%7;                      
    //peca atual
    printf("peca atual: \n");
    print_matriz(pecas[prox_peca].pos1,4,4);
    printf("\n");

    //colocar peça no jogo
    jogo = best_score(jogo,pecas[prox_peca],4,4,9);
    
    printf("jogo\n");
    print_matriz(jogo,20,12);
    
    apaga_preenchidas(jogo,20,12);

    jogadas--;
  }
   return 0;
}

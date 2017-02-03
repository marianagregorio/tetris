#include "tetris.h" 
#include "matriz.h"
#include <stdio.h>                                        
#include <stdlib.h>                                      
#include <time.h>                                       


int ** inicio (int ** jogo)
{
    jogo = aloca (20,12);
    int i,j;
    for (i=0; i<20; i++)
        for (j=0; j<12; j++)
            jogo[i][j]=0;
    return jogo;
}

void aloca_pecas (tetrimino pecas[]) 
{
    int i;
    for (i=0;i<7;i++) {
        pecas[i].pos1=aloca(4,4);
        pecas[i].pos2=aloca(4,4);
        pecas[i].pos3=aloca(4,4);
        pecas[i].pos4=aloca(4,4);
    }
}
  
void primeira_peca (tetrimino pecas[]) 
{
    int i,j;
    for (j=0;j<7;j++){
        for (i=0;i<4;i++) {
            pecas[j].pos1 [3][i]=1;
        }
    }
}

void peca_atual(tetrimino pecas[],int p){              
    int i;
    int temp;
    if(p<4){
        temp = 3;
        for(i=0;i<p;i++){
            pecas[p].pos1[2][i] = 1;
            pecas[p].pos1[3][temp] = 0;
            temp--;
        }
    }
    else if(p<6){
        temp = 3;
        for(i=0;i<p-3;i++){
            pecas[p].pos1[2][i+1] = 1;
            pecas[p].pos1[3][temp] = 0;
            temp--;
        }
    }
    else {
        pecas[p].pos1[2][1] = 1;
        pecas[p].pos1[2][2] = 1;
        pecas[p].pos1[3][0] = 0;
        pecas[p].pos1[3][1] = 0;
    }
}

void cria_pecas (tetrimino pecas[] )                       
{
    int i,j;
    primeira_peca(pecas);
    for (i = 0; i<7; i++) {
        peca_atual (pecas,i);
        pecas[i].pos2 = rotaciona (pecas[i].pos1);         
        pecas[i].pos3 = rotaciona (pecas[i].pos2);
        pecas[i].pos4 = rotaciona (pecas[i].pos3);
    }
}

void reduz_pecas (tetrimino * pecas, int n)
{
    
}

int linha (int * linha, int n)                     
{
    int i = 0;
    for (;i<n;i++) {
        if(!linha[i]) return 0;
    }
    return 1;
}

int num_linhas (int **matriz,int lin, int col)            
{
    if (!lin) return linha (matriz[0],col);
    return linha (matriz[lin],col) + num_linhas (matriz, lin-1, col);
}

int bloqueados (int ** matriz, int i, int j)
{
    int i2, j2, bloq = 0;
    for (i2=1; i2<i; i2++) {
        for (j2=0; j2<j; j2++) {
            if (!matriz[i2][j2]) {
                if(matriz[i2-1][j2]) bloq--;
            }
        }
    }
    return bloq;
}

int altura (int ** matriz, int i, int j)
{
    int n = 0, altura=0;
    while (!linha_nula(matriz[n],j) && n<i) {
        altura++;
        n++;
    }
    return altura;
}


int ** encaixa (int ** jogo, int ** peca, int lin_peca, int col_peca, int col)
{
   int ** estado = aloca(20,12);
   int i_jogo=0,i,j,k;
   
   estado = copia(jogo,20,12);
   
   for (i_jogo=0;i_jogo<21;i_jogo++) {
        if(i_jogo==20) break;
        if((jogo[i_jogo][col] + peca [3][0])>1) break; 
        if((jogo[i_jogo][col+1] + peca [3][1])>1) break;
        if((jogo[i_jogo][col+2] + peca [3][2])>1) break;
        if((jogo[i_jogo][col+3] + peca [3][3])>1) break;
   }
   i_jogo--;
   if (i_jogo<3) return NULL;
   for (i=0;i<lin_peca;i++)
        for (j=0;j<col_peca;j++)
            if (estado[i_jogo-i][col+j] == 0 && peca[lin_peca-1-i][j] == 1){
                    estado[i_jogo-i][col+j] = peca[lin_peca-1-i][j];
            }
    return estado;
   
}

int score (int ** matriz)
{
    return num_linhas (matriz,19,12) + altura (matriz,20,12)+ bloqueados (matriz, 20, 12);
}

int ** best_score (int ** matriz, tetrimino peca, int lin_peca, int col_peca, int col_max)
{
    int max = -7000, tmp, i;
    int ** atualiza_jogo = aloca(20,12);
   // printf("linhas: %d\n", num_linhas(atualiza_jogo,19,12));
    for (i=0; i<col_max;i++) {
        tmp = score (encaixa (matriz, peca.pos1,lin_peca,col_peca,i));
        if (tmp> max) {
            max = tmp;
            atualiza_jogo = encaixa (matriz, peca.pos1,lin_peca,col_peca,i);
        }
        tmp = score (encaixa (matriz, peca.pos2,lin_peca,col_peca,i));
        if (tmp> max) {
            max = tmp;
            atualiza_jogo = encaixa (matriz, peca.pos2,lin_peca,col_peca,i);
        }
        tmp = score (encaixa (matriz, peca.pos3,lin_peca,col_peca,i));
        if (tmp> max) {
            max = tmp;
            atualiza_jogo = encaixa (matriz, peca.pos3,lin_peca,col_peca,i);
        }
        tmp = score (encaixa (matriz, peca.pos4,lin_peca,col_peca,i));
        if (tmp> max) {
            max = tmp;
            atualiza_jogo = encaixa (matriz, peca.pos4,lin_peca,col_peca,i);
        }
    }
    
    return atualiza_jogo;
    
}

void apaga_preenchidas (int ** matriz, int i, int j)
{
    int k;
    for (k=0; k<i; k++)
        if (linha(matriz[k],j)) remove_linha(matriz,i,j,k);
}

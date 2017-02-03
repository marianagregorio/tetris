
#include "matriz.h"
#include <stdlib.h>
#include <stdio.h>

int ** aloca (int i, int j)                              
{
    int ** matriz;                                      
    int k;
    matriz = (int **) malloc (i*sizeof(int*));
    for (k=0;k<i;k++) {
        matriz[k] = (int *) malloc (j*sizeof(int));
    }
    return matriz;                                 
}

int ** copia (int **matriz,int i, int j)           
{
    int ** copia = aloca(i,j);                     
    int i2,j2;
    for (i2=0;i2<i;i2++)
        for (j2=0; j2<j;j2++)
            copia[i2][j2] = matriz[i2][j2];

    return copia;                                
}

int linha_nula (int * linha, int n)                 
{
    if (!n) return 0;
    if (*linha) return 1;
    return linha_nula (linha+1, n-1);
}

int coluna_nula (int ** matriz, int i, int j)     
{
    int col=0, i2=i;
    while (i2--) {
        if (matriz[i2-1][j]) return 1;
    }
    return 0;
}

void remove_linha (int **matriz, int i, int j, int n)  
{
    int i2, j2;
    for (i2=n; i2>0; i2--) {
        for (j2=0; j2<j; j2++) {
            matriz[i2][j2] = matriz[i2-1][j2];
        }
    }
    printf("\n");
    //print_matriz (matriz,20,12);
}

void remove_coluna (int ** matriz, int i, int j, int n)
{
    
}

int ** reduz_matriz (int ** matriz, int i, int j) //
{/*
    int ** reduzida, i_red=0, j_red=0, i2,j2;
    i2 = i;
    j2 = j;
    while (i2--) i_red += linha_nula (matriz[i2-1],j);
    while (j2--) j_red += coluna_nula (matriz,i,j);
    reduzida = aloca(i_red,j_red);
    for (i2=0; i2<i_red; i2++) {
        
    }*/
    
}

int ** rotaciona (int ** matriz)
{
    int ** novapos = aloca(4,4);
    int n=4;
    int i=4,j;
    for (i=0;i<4;i++)
        for (j=0; j<4; j++)
            novapos[i][j] = matriz[j][3-i];
    return novapos;
} 

void print_matriz (int ** matriz, int i, int j)
{
    int i2, j2;
    for (i2 = 0; i2<i; i2++) {
        for (j2=0; j2<j;j2++) {
            printf ("%d ",matriz[i2][j2]);
        }
        printf("\n");
    }
}

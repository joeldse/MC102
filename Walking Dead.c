/*
 Joel da Silva Evangelista - RA: 176463
 Lab 10 - Walking Dead
 Entrada: 1° linha: linhas e colunas da matriz, 2° linha: número de dias da simulação, 
          3° linha: condião inicial, inteiros, onde 0 representa o vazio, 1 um humano e 2 um zumbi.
 Saida: Deve reportar o estado da população para cada um dos i dias transcorridos.
 Objetivo: Dada a configuração inicial da população, simular o estado da população
           durante alguns dias utilizando as regras de interação humano/zumbi definidas
 */

#include <stdio.h>

int main(){
    
int m, n, i, j, k, l, cont, mat[200][200], matf[200][200];

  scanf("%d %d", &m ,&n);
  scanf("%d", &i);
 
/*zerando matriz para nao conservar valores invalidos*/
    for(k=0; k <= m+1; k++)
      for (l=0; l <= n+1; l++){
         mat[k][l] =0;
      }
             
/*Salvando matriz inicial*/
    for(k=1; k <= m; k++)
       for (l=1; l <= n; l++)
          scanf("%d", & mat[k][l]);
          
/*Impressao da iteraçao inicial*/
    printf("iteracao 0\n");
       for(k=1; k <= m; k++){
          for (l=1; l <= n; l++)
            printf("%d", mat[k][l]);
       printf("\n");
       }
       
/*Copiando matrizes*/
     for(k=0; k <= m+1; k++)
      for (l=0; l <= n+1; l++)
         matf[k][l] = mat[k][l];
       
/*Analisando iteraçoes*/
    for (j=1 ; j<=i; j++ ){             /*primeiro for de contagem de iteracoes*/
       
/*Analise dos casos com humanos*/
       for(k=1; k <= m; k++)
          for (l=1; l <= n; l++)
             if (mat[k][l] == 1){
                if (mat[k-1][l-1]==2 || mat[k-1][l]==2 || mat[k-1][l+1]==2 || mat[k][l-1]==2 || mat[k][l+1]==2 || mat[k+1][l-1]==2 || mat[k+1][l]==2 || mat[k+1][l+1]==2)
                   matf[k][l]=2;
          }
          
/*Analise dos casos com zumbi e pelo menos dois vizinhos humanos*/
       for(k=1; k <= m; k++)
          for (l=1, cont=0; l <= n; l++)
             if (mat[k][l] == 2){
                if (mat[k-1][l-1]==1)
                   cont++;
                if (mat[k-1][l]==1)
                   cont++;
                if (mat[k-1][l+1]==1)
                   cont++;
                if (mat[k][l-1]==1)
                   cont++;
                if (mat[k][l+1]==1)
                   cont++;
                if (mat[k+1][l-1]==1)
                   cont++;
                if (mat[k+1][l]==1)
                   cont++;
                if (mat[k+1][l+1]==1)
                   cont++;
                if (cont >= 2)
                   matf[k][l] = 0;
        cont=0;
              }
    
/*Analise dos casos com zumbi e nenhum humano ao lado*/
      for(k=1; k <= m; k++)
          for (l=1; l <= n; l++)
             if (mat[k][l] == 2){
                if (mat[k-1][l-1]!=1 && mat[k-1][l]!=1 && mat[k-1][l+1]!=1 && mat[k][l-1]!=1 && mat[k][l+1]!=1 && mat[k+1][l-1]!=1 && mat[k+1][l]!=1 && mat[k+1][l+1]!=1)
                   matf[k][l]=0;
          }       
          
/*Analise dos casos em que existe exatamente dois vizinhos humanos e o local estiver vazio*/
    for(k=1; k <= m; k++)
          for (l=1, cont=0; l <= n; l++)
             if (mat[k][l] == 0){
                if (mat[k-1][l-1]==1)
                   cont++;
                if (mat[k-1][l]==1)
                   cont++;
                if (mat[k-1][l+1]==1)
                   cont++;
                if (mat[k][l-1]==1)
                   cont++;
                if (mat[k][l+1]==1)
                   cont++;
                if (mat[k+1][l-1]==1)
                   cont++;
                if (mat[k+1][l]==1)
                   cont++;
                if (mat[k+1][l+1]==1)
                   cont++;
                if (cont == 2)
                   matf[k][l] = 1;
        cont=0;
              }
          
/*Alterando matriz anterior para realizar nova iteraçao*/
       for(k=0; k <= m+1; k++)
          for (l=0; l <= n+1; l++)
             mat[k][l] = matf[k][l];
    
/*Imprimindo resultados*/
       printf("iteracao %d\n", j);
         for(k=1; k <= m; k++){
           for (l=1; l <= n; l++)
              printf("%d", matf[k][l]);
         printf("\n");
       }
     }

    return 0;
}
/*
 Joel da Silva Evangelista - RA: 176463
 Lab 09 - Normas para uma boa senha
 Entrada: O quantidade e a sequencia de palavras reservadas do dicionario, e a senha do usuario
 Saida: Se a senha digitada satisfaz as normas para uma senha
 Objetivo: Indicar se a senha digitada satisfaz todas as normas para uma boa senha
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){

    int n, i, j, aux, aux1, aux2, aux3, aux4, aux5, tamanho;
    char senha[50], dic[50][21];

/*Salvando numero de palavras reservadas*/
    scanf ("%d",&n);         

/*Salvando as palavras reservadas e a senha*/
    for (j = 0; j < n; j++)
       scanf("%s", dic[j]);
    
    scanf("%s",senha);                              
    
/*Comparando se possue no  minimo 8 caracter*/
    tamanho = strlen(senha);                             /*Verifica o numero de caracteres*/
        if (tamanho < 8)
          printf("A senha deve conter pelo menos 8 caracteres\n");
    
/*Comparando se possue pelo menos uma letra maiuscula*/
    aux = 1;    
    for(j=0; j< tamanho; j++)
      if (isupper(senha[j])!=0)
        aux=0;
      if(aux==1)
        printf("A senha deve conter pelo menos uma letra maiuscula\n");
    
/*Comparando se possue pelo menos uma letra minuscula  islower*/
    aux1 = 1;    
    for(j=0; j< tamanho; j++)
      if (islower(senha[j])!=0)
        aux1=0;
      if(aux1==1)
        printf("A senha deve conter pelo menos uma letra minuscula\n");
    
/*Verificando se possue pelo menos um numero*/
    aux2 = 1;    
    for(j=0; j< tamanho; j++)
      if (isdigit(senha[j])!=0)
        aux2=0;
    if(aux2==1)
        printf("A senha deve conter pelo menos um numero\n");
    
/*Verificando se contem pelo menos um simbolo*/
    aux3 = 1;
    for(j=0; j < tamanho; j++)
      if ((senha[j] == '?') || (senha[j] == '!') || (senha[j] == '#') || (senha[j] == '@') || (senha[j] == '$'))
        aux3=0;
    if(aux3==1)
      printf("A senha deve conter pelo menos um simbolo\n");
        
/*Verificando se e um palindromo*/
    aux4 = 1;
    for (i=0, j = tamanho - 1; i<j; i++,j--)
      if (senha[i] != senha[j])
        aux4 =0;
    if (aux4 == 1)
      printf("A senha e um palindromo\n");
    
/*Verificando se a senha se encontra entre as palavras reservadas*/
    aux5 = 0;
    for (j=0; j<tamanho; j++)
      senha[j] = tolower(senha[j]);
    
    for (j = 0; j < n; j++)
      if (strstr( senha,dic[j] ) != NULL) {
         aux5 = 1;
      }
    if(aux5 == 1)
      printf("A senha nao pode conter palavras reservadas\n");
    
    /*Verificando se todas as condiçoes foram realizadas*/
    if (aux == 0 && aux1==0 && aux2==0 && aux3==0 && aux4==0 && aux5==0 && tamanho>=8)
      printf("ok\n");
    
return 0;
}
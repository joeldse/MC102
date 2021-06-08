/*
 Joel da Silva Evangelista - RA: 176463
 Lab 07 - Street Fighter Avancado
 Entrada: Numeros inteiros representando os valores dos golpes aplicados e recebidos
 Saida: Resultado geral da luta
 Objetivo: Simular a luta entre Ryu e Ken e indicar o ganhador
 */
 
#include <stdio.h>

int main()
{
    int golpea,golpek,golper,somar,somak,somavp,somavt,i,j;                   /*ga: Variaveis correspondentes aos golpes aplicados*/
    golpek = 0;                               /*gk: Valor final do golpe de Ken*/
    somar = 0;                               /*sr: Somatoria de vitorias de Ryu*/
    somak = 0;                               /*sk: Somatoria de vitorias de Ken*/
    golper = 0;                               /*gr: Valor final do golpe de Ryu*/

    scanf("%d",&golpea);
    
    while (golpea!=0){     
   
             /*Atribuindo resultado de golpes aos lutadores*/
    while (golpea > 0){
     
      /*Variavel perfeito*/
   for (i=1, somavp = 0;i<golpea;i++){                            /*somavp: Somatoria para analise do valor perfeito*/
      if (golpea%i==0 && somavp < golpea)
        somavp += i;
      }

   if(somavp == golpea)
      golpea = 3*golpea;
 
   /*Variavel triangular*/
   else{
      for(j=1, somavt = 0;j<golpea;j++){                        /*somavt: Somatoria para analise do valor triangular*/
          if(somavt < golpea)
             somavt += j;}
     
      if(golpea == somavt)
        golpea = 2*golpea;
    }
    
       golper += golpea;
     scanf("%d",&golpea);
    }
    
    while (golpea < 0){
     
      /*Variavel perfeito*/
   for (i=1, somavp = 0;i<-golpea;i++){                            
      if (-golpea%i==0 && somavp < -golpea)
        somavp += i;
      }

   if(somavp == -golpea)
      golpea = 3*golpea;
 
   /*Variavel triangular*/
   else{
      for(j=1, somavt = 0;j<-golpea;j++){                       
          if(somavt < -golpea)
             somavt += j;}
     
      if(-golpea == somavt)
        golpea = 2*golpea;
    }
    
       golpek += golpea;
     scanf("%d",&golpea);                         
    }
      if (golper > -golpek)
         somar++;
      else if(golper < -golpek)
         somak++;
    
      golper = 0;                      /*Zerando contador para novo round*/
      golpek = 0;
    }

    if (somar > somak)
      printf("Ryu venceu\n");
    else if (somar < somak)
      printf("Ken venceu\n");
    else
      printf("empatou\n");

return 0;
}
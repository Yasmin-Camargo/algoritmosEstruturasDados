#include <stdlib.h>
#include <stdio.h>

//NOME: Yasmin
//Exercício 3
/*Fac a um programa que leia do usu  ́ario o tamanho de um vetor a ser lido e fac ̧a a alocacao din ˆamica de mem  ́oria. Em seguida, leia do usu  ́ario seus valores e mostre quantos dos n  ́umeros s  ̃ao pares e quantos s  ̃ao  ́ımpares.*/

int main (){
  int tamanho=0, cont=0, par=0, impar=0;
  int *vetor;
  
  printf ("Digite o tamanho do vetor: ");
  scanf("%d",&tamanho);

  vetor = (int *) malloc(tamanho * sizeof(int));
  printf ("\n");
  
  for (cont = 0; cont < tamanho; cont++){
    printf ("Digite a posicao %d do vetor: ",cont+1);
    scanf("%d",&vetor[cont]);
    if (vetor[cont]%2==0){
      par = par +1;
    }
    else{
      impar = impar + 1;
    }
  }
  printf("\n\n %d sao pares", par);
  printf("\n\n %d sao impares", impar);
  
}
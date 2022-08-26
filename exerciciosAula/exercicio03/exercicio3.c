//NOME: Yasmin Souza Camargo
//Exercício 3 - Lista 10 - Alocação dinâmica
/*Faca um programa que leia do usuario o tamanho de um vetor a ser lido e faca a alocacao dinamica de memoria. Em seguida, leia do usuario seus valores e mostre quantos dos numeros sao pares e quantos sao ımpares*/

#include <stdlib.h>
#include <stdio.h>

int main (){
  int tamanho = 0, cont = 0, par = 0, impar = 0;
  int *vetor;
  
  printf ("Digite o tamanho do vetor: ");
  scanf("%d", &tamanho);

  vetor = (int *) malloc(tamanho * sizeof(int));
  printf ("\n");
  
  for (cont = 0; cont < tamanho; cont++){
    printf ("Digite a posicao %d do vetor: ",cont+1);
    scanf("%d", &vetor[cont]);
    if (vetor[cont] % 2 == 0){
      par = par + 1;
    } else{
      impar = impar + 1;
    }
  }
  printf("\n\n %d sao pares", par);
  printf("\n\n %d sao impares", impar); 
}
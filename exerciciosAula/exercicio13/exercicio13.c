//NOME: Yasmin Souza Camargo
//Exercício 13 - Lista 11 - Arquivos
/*Faca um programa que permita que o usuario entre com diversos nomes e telefone para cadastro, e crie um arquivo com essas informacoes, uma por linha. O usuario finaliza a entrada com ‘0’ para o telefone*/

#include <stdlib.h>
#include <stdio.h>

int main (){
    int telefone = 0, op = 1;
    char nome[50]; 

    FILE *arquivo;
    arquivo = fopen("nomesTelefones.txt","w");  

    printf ("\nATENCAO: Para sair do programa no telefone digite zero \n\n");
    while (op != 0){
      printf ("\nDigite o nome: ");
      scanf("%s", nome);

      fprintf(arquivo, nome);
      fprintf(arquivo, "\n");

      printf ("Digite o numero de telefone: ");
      scanf ("%d", &telefone);
      
      if (telefone == 0){
        printf("\n\n\nsaindo...\n\n");
        op = 0;
      }

    }

}
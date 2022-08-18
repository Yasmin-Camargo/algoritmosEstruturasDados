#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//NOME: Yasmin
//Exercício 4 - Lista 10 - Alocação dinâmica
/* Faca um programa que receba do usuario o tamanho de uma string e chame uma ´
func¸ao para alocar dinamicamente essa string. Em seguida, o usuario dever a informar o
conteudo dessa string. O programa imprime a string sem suas vogais
*/

void alocarString(int tamanhoStringAlocada);
void imprimirString();

char *string;

int main (){
  int tamanho;

  printf("Digite o tamanho da string: ");
  scanf("%d", &tamanho);

  alocarString(tamanho);

  printf("Digite o conteudo da string: ");
  scanf("%s", string);

  imprimirString();
  free (string);
}

// Função para alocar espaço na string
void alocarString(int tamanhoStringAlocada){
	string = (char *) malloc(tamanhoStringAlocada * sizeof(char) + 1);
}


// Função para imprimir a string
void imprimirString(){
	printf("\n\n Conteudo da string digitada sem vogais: \n ");

	for (int i = 0; i < strlen(string); i++){
		if (!(string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u')){
			printf("%c", string[i]);
		}
	}
}
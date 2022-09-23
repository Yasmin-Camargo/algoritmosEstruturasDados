//NOME: Yasmin Souza Camargo

//Trabalho prático 2 turma M1
/* Fazer um programa que testa a sequencia de caracteres fornecidas pelo usuario é um palindromo, ou seja, é uma palavra cuja primeira metade é simétrica a segunda metade
 AABCCBAA - sim
 ADDFDDA - sim
 ABFFBB - não
O usuário digita uma letra e tecla enter, até que digite x  e enter para terminar a sequencia
Implemente a função POP e PUSH de pilha e resolva o problema com elas */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 20
typedef struct{
	char sequencia[MAX];
	int base;
	int topo;
	int limite;
}Pilha;

//Escopo de funções
Pilha *RESET();
void PUSH(Pilha *minhaPilha, char letraDigitada);
char POP(Pilha *minhaPilha);
void CLEAR(Pilha *minhaPilha);

int TestaPalindromo(Pilha *novaPilha, Pilha *novaPilha2, int metade, int par);

int main()
{
	char letra[3];
	int metade = 0, teste = 0;
	Pilha *novaPilha;

	novaPilha = RESET();

	while (letra[0] != 'x'){
		printf(" Digite uma letra: ");
		scanf("%s", letra);
		letra[0] = tolower(letra[0]);
		if (letra[0] != 'x'){
			PUSH (novaPilha, letra[0]);
		}
	}

	Pilha *novaPilha2;
	novaPilha2 = RESET();	

	//CASO 1: Palavra tem tamanho impar
	if ((novaPilha->topo)%2 != 0){
		metade = (novaPilha->topo - 1) / 2;
		teste = TestaPalindromo(novaPilha, novaPilha2, metade, 0);
	} else{	
		//CASO 2: Palavra tem tamanho par
		metade = (novaPilha->topo) / 2;
		teste = TestaPalindromo(novaPilha, novaPilha2, metade, 1);
	}

	if (teste == 1){
		printf("\n\n --- A palavra e um palindromo! --- \n\n");
	} else{
		printf("\n\n --- A palavra NAO e um palindromo! --- \n\n");
	}
	CLEAR(novaPilha);
	CLEAR(novaPilha2);
	return (0);
}

Pilha *RESET(){
	Pilha *minhaPilha;
	minhaPilha = malloc(sizeof(Pilha));
	minhaPilha->base = 0;
	minhaPilha->topo = 0;
	minhaPilha->limite = MAX;

	return minhaPilha;
}

void PUSH(Pilha *minhaPilha, char letraDigitada){
	if (minhaPilha->topo == minhaPilha->limite){
		printf("A pilha esta cheia");
	}
	else{
		minhaPilha->sequencia[minhaPilha->topo] = letraDigitada;
		minhaPilha->topo++;
	}
}

char POP(Pilha *minhaPilha){
	char dadoRemovido;
	if (minhaPilha->topo == minhaPilha->base){
		printf("A pilha esta vazia");
	}
	else{
		dadoRemovido = minhaPilha->sequencia[minhaPilha->topo - 1];
		minhaPilha->topo--;
	}
	return dadoRemovido;
}

void CLEAR(Pilha *minhaPilha){
    free(minhaPilha);
}

int TestaPalindromo(Pilha *novaPilha, Pilha *novaPilha2, int metade, int par){
	for (int i = 0; i < metade; i++){ //Divide o conteúdo em duas pilhas
		PUSH(novaPilha2, POP(novaPilha));
	} 
	if (par == 0){ 
		POP(novaPilha); //Se a quantidade de letras é par, pilha original tem um elemento a mais
	}
	for (int i = 0; i < metade; i++){ //Para ser um palindromo as duas pilhas devem ser iguais
		if (POP(novaPilha) != POP(novaPilha2)){
			return (0);
		}
	} 
	return (1);
}
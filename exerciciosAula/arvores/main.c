//NOME: Yasmin Souza Camargo

/* Implementar uma agenda (nome, idade, telefone) que armazena os dados numa árvore binária de busca (usuário escolhe qual dado é o fator de precedência). A agenda deve permitir incluir, buscar, remover e imprimir toda a árvore usando pré-ordem, central e pós-ordem. */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct{
	char *chave;
	char *nome;
	int idade;
	char *telefone; 
	struct Arvore *esquerda; 
	struct Arvore *direita;  
}Arvore;

Arvore *raiz = NULL;
int numPessoas = 0;

//Escopo de funções
Arvore *newNodo(char nome[], int idade, char telefone[], int fatorPrecedencia);
void PUSH(Arvore **tracer, Arvore *newp);
void imprimirPreOrdem(Arvore *minhaArvore);
void imprimirOrdem(Arvore *minhaArvore);
void imprimirPosOrdem(Arvore *minhaArvore);
Arvore *search(Arvore **tracer, char *chave);

int main()
{
	int op = 1, fatorPrecedencia = 0, imprimir = 0, tempIdade = 0;
	char tempNome[30], tempTelefone[20];

	numPessoas = 0;
	
	do {
		printf ("\n\n ----------------------------\n");
		printf ("\n  1 - nome ");
		printf ("\n  2 - idade ");
		printf ("\n  3 - telefone \n");
		printf ("\nEscolha o fator de precedencia que voce deseja adicionar dados na arvore: ");
		scanf ("%d", &fatorPrecedencia);
	} while (!(fatorPrecedencia >= 1 && fatorPrecedencia <= 3));

	while (op != 0){
        printf ("\n\n ----------------------------");
        printf ("\n          AGENDA            ");
        printf ("\n ----------------------------  ");
        printf ("\n  1) Incluir ");
        printf ("\n  2) Mostrar ");
        printf ("\n  3) Buscar ");
        printf ("\n  4) Apagar ");
		printf ("\n  5) Alterar fator de precedencia ");
        printf ("\n  0) Sair ");
        printf ("\n\n Escolha uma opcao: ");
        scanf ("%d", &op);
        printf ("\n ----------------------------  ");
        switch (op){
        case 1:
            printf("\n\nAdicione os seguintes dados: ");
            printf("\n Nome: ");
            scanf("%s", tempNome);
            printf(" Idade: ");
            scanf("%d", &tempIdade);
            printf(" Telefone: ");
            scanf("%s", tempTelefone);
			PUSH(&raiz, newNodo(tempNome, tempIdade, tempTelefone, fatorPrecedencia));
			
			printf("\n\nNome: %s, Idade: %d, telefone: %s", raiz->nome, raiz->idade, raiz->telefone);
            break;

        case 2:
			do {
				printf ("\n\n  1 - Pre-ordem");
				printf ("\n  2 - Ordem ");
				printf ("\n  3 - Pos-ordem \n");
				printf ("\n Como voce deseja imprimir toda a arvore: ");
				scanf ("%d", &imprimir);
			} while (!(imprimir >= 1 && imprimir <= 3));
			switch(imprimir){
				case 1:
					printf("\n\n  PRE-ORDEM:\n  ");
					imprimirPreOrdem(raiz);
				break;

				case 2:
					printf("\n\n  ORDEM:\n  ");
					imprimirOrdem(raiz);
				break;

				case 3:
					printf("\n\n  POS-ORDEM:\n  ");
					imprimirPosOrdem(raiz);
				break;

				case 4:
					
				break;

				case 5:
					
				break;
			}
            break;

        case 3:      
            printf("\n Digite a chave que voce deseja buscar: ");
            scanf("%s", tempNome);
            
            Arvore *busca;
            busca = search (&raiz, tempNome);
            if (busca == NULL){
                printf("\n\n DADO NAO FOI ENCONTRADO");
            } else{
                printf("\n\n Objeto foi encontrado: ");
                printf("\n nome: %s", busca->nome);
                printf("\n idade: %d", busca->idade);
                printf("\n telefone: %s", busca->telefone);
            }
            break;

        case 4:
		
            break;

        case 0:
            printf("\n\n Saindo...\n");
          
			return (0);
            break;

        default:
            printf("\n\n\n OPCAO INVALIDA!!! Por favor, tente novamente\n");
            break;
        }
    }
}


Arvore *newNodo(char nome[], int idade, char telefone[], int fatorPrecedencia){
	Arvore *novoNodo = (Arvore *) (malloc(sizeof(Arvore)));
	novoNodo->nome = (char *) (malloc(sizeof(strlen(nome) * sizeof(char)) + sizeof(char)));
	novoNodo->telefone = (char *) (malloc(sizeof(strlen(telefone) * sizeof(char)) + sizeof(char)));

	novoNodo->direita = NULL;
	novoNodo->esquerda = NULL;
	novoNodo->idade = idade;
	strcpy(novoNodo->nome, nome);
	strcpy(novoNodo->telefone, telefone);

	//defindo a chave a ser utilizada
	if (fatorPrecedencia == 1){
		novoNodo->chave = (char *) (malloc(sizeof(char) * strlen(nome) + sizeof(char)));
		if (novoNodo->chave == NULL){
			printf ("\n ERRO de alocacao!!");
			exit (1);
		}
		strcpy(novoNodo->chave, nome);
	} else if (fatorPrecedencia == 2){
		novoNodo->chave = (char *) (malloc(sizeof(char) * 2 + sizeof(char)));
		if (novoNodo->chave == NULL){
			printf ("\n ERRO de alocacao!!");
			exit (1);
		}
		sprintf(novoNodo->chave, "%d", idade); //Converte idade para string
	} else{
		novoNodo->chave = (char *) (malloc(sizeof(char) * strlen(telefone) + sizeof(char)));
		if (novoNodo->chave == NULL){
			printf ("\n ERRO de alocacao!!");
			exit (1);
		}
		strcpy(novoNodo->chave, telefone);
	}

	return novoNodo;
}


void PUSH(Arvore **tracer, Arvore *newp){
	int posicao = 0;
	if (raiz == NULL){	//Primeira pessoa a ser inserida
		*tracer = newp;
	}
	else {
		while((*tracer)){ //Percorre a árvore até encontrar uma folha
			if(strcmp(newp->chave, (*tracer)->chave) > 0){ //Se é maior insere na direita
				if((*tracer)->direita == NULL){ //Encontrou uma folha
					(*tracer)->direita = newp;
					break;
				} else{	//Continua percorrendo a árvore
					tracer = &((*tracer)->direita);
				}
			}
			else {
				if((*tracer)->esquerda == NULL){
					(*tracer)->esquerda = newp;
					break;
				} else{
					tracer = &((*tracer)->esquerda);
				}
			}
		}

	}
}


void imprimirPreOrdem(Arvore *minhaArvore){
	if (minhaArvore){
		printf("%s, ", minhaArvore->chave);
		imprimirPreOrdem(minhaArvore->esquerda);
		imprimirPreOrdem(minhaArvore->direita);
	}
}

void imprimirOrdem(Arvore *minhaArvore){
	if (minhaArvore){
		imprimirOrdem(minhaArvore->esquerda);
		printf("%s, ", minhaArvore->chave);
		imprimirOrdem(minhaArvore->direita);
	}
}

void imprimirPosOrdem(Arvore *minhaArvore){
	if (minhaArvore){
		imprimirPosOrdem(minhaArvore->esquerda);
		imprimirPosOrdem(minhaArvore->direita);
		printf(" %s, ", minhaArvore->chave);
	}
}

Arvore *search(Arvore **tracer, char *chave){
    int encontrou = 0;
    while((*tracer)){
        if (strcmp(chave, (*tracer)->chave) == 0){
            encontrou = 1;
            break;
        }
        else{
            if (strcmp(chave, (*tracer)->chave) > 0){
                tracer = &((*tracer)->direita);
            } else{
                tracer = &((*tracer)->esquerda);
            }
        }
    }

    if (encontrou == 1){
        return *tracer;
    } else{
        return NULL;
    }
}

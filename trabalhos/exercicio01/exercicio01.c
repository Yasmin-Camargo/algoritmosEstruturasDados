//Nome: Yasmin Souza Camargo
/* Faça um programa que solicita do usuário uma série de números, cada número pode ser um
int, float ou double. Antes de solicitar o número pergunte qual tipo de dado o usuário vai entrar. Todos os números entrados devem ser armazenados num buffer único. Esse buffer deve ter tamanho dinâmico e não deve desperdiçar memória, por exemplo, alocar sempre espaço para um double quando o usuário inserir um int ou float. Você não deve solicitar para o usuário quantos números ele deseja entrar, na escolha do tipo de dados coloque uma opção para parar a entrada da série de números. Após isso você deve imprimir todos os números do buffer, primeiro toda a série em sequência depois novamente, mas primeiro os ints seguido dos floats e doubles.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	void *buffer = NULL;
	int *numInt = NULL;
	float *numFloat = NULL;
	double *numDouble = NULL;

	int opMenu = 1, tamanho = 0;
	char *sequencia = NULL;
	
	sequencia = (char *) (malloc(sizeof(char) + 1));
	buffer = (void *) (malloc (sizeof(int)));
	if (!buffer || !sequencia){
		printf("Erro de alocacao de memoria");
	}
	
	strcpy(sequencia, "");

	while (opMenu != 0){
		printf("\n\n\n===================\n");
		printf("\n0) Sair");
		printf("\n1) Inteiro");
		printf("\n2) Float");
		printf("\n3) Double");
		printf("\n\nEscolha uma opcao: ");
		scanf ("%d", &opMenu);
		
		switch (opMenu){
		case 1:
			sequencia = (char *) (realloc (sequencia, (sizeof(char) * strlen(sequencia)) + sizeof(char) + 1));
			buffer = (void *) (realloc (buffer, tamanho + sizeof(int)));
			numInt = (int *) (buffer + tamanho);
			if (!buffer || !sequencia || !numInt){
				printf("Erro de alocacao de memoria");
			}

			tamanho = tamanho + sizeof(int);
			strcat(sequencia, "i");
			
			printf("\nDigite um inteiro: ");
			scanf ("%d", numInt);
			break;

		case 2:
			sequencia = (char *) (realloc (sequencia, (sizeof(char) * strlen(sequencia)) + sizeof(char) + 1));
			buffer = (void *) (realloc (buffer, tamanho + sizeof(float)));
			numFloat = (float *) (buffer + tamanho);
			if (!buffer || !sequencia || !numFloat){
				printf("Erro de alocacao de memoria");
			}

			tamanho = tamanho + sizeof(float);
			strcat(sequencia, "f");
			
			printf("\nDigite um float: ");
			scanf ("%f", numFloat);
			break;

		case 3:
			sequencia = (char *) (realloc (sequencia, (sizeof(char) * strlen(sequencia)) + sizeof(char) + 1));
			buffer = (void *) (realloc (buffer, tamanho + sizeof(double)));
			numDouble = (double *) (buffer + tamanho);
			if (!buffer || !sequencia || !numDouble){
				printf("Erro de alocacao de memoria");
			}

			tamanho = tamanho + sizeof(double);
			strcat(sequencia, "d");
			
			printf("\nDigite um double: ");
			scanf ("%lf", numDouble);
			break;

		case 0:
			printf("\n\nSEQUENCIA: ");
			tamanho = 0;
			for (int i = 0; i < strlen(sequencia); i++){
				if (sequencia[i] == 'i'){
					printf("\n %d", *(int *) (buffer + tamanho));
					tamanho = tamanho + sizeof(int);
				} else if (sequencia[i] == 'f'){
					printf("\n %f", *(float *) (buffer + tamanho));
					tamanho = tamanho + sizeof(float);
				}else if (sequencia[i] == 'd'){
					printf("\n %f", *(double *) (buffer + tamanho));
					tamanho = tamanho + sizeof(double);
				}
			}

			printf("\n\n => INTEIRO: ");
			tamanho = 0;
			for (int i = 0; i < strlen(sequencia); i++){
				if (sequencia[i] == 'i'){
					printf(" %d ", *(int *) (buffer + tamanho));
					tamanho = tamanho + sizeof(int);
				} else if (sequencia[i] == 'f'){
					tamanho = tamanho + sizeof(float);
				} else if (sequencia[i] == 'd'){
					tamanho = tamanho + sizeof(double);
				}
			}

			printf("\n\n => FLOAT: ");
			tamanho = 0;
			for (int i = 0; i < strlen(sequencia); i++){
				if (sequencia[i] == 'i'){
					tamanho = tamanho + sizeof(int);
				} else if (sequencia[i] == 'f'){
					printf(" %f ", *(float *) (buffer + tamanho));
					tamanho = tamanho + sizeof(float);
				} else if (sequencia[i] == 'd'){
					tamanho = tamanho + sizeof(double);
				}
			}
			
			printf("\n\n => DOUBLE: ");
			tamanho = 0;
			for (int i = 0; i < strlen(sequencia); i++){
				if (sequencia[i] == 'i'){
					tamanho = tamanho + sizeof(int);
				} else if (sequencia[i] == 'f'){
					tamanho = tamanho + sizeof(float);
				} else if (sequencia[i] == 'd'){
					printf(" %lf ", *(double *) (buffer + tamanho));
					tamanho = tamanho + sizeof(double);
				}
			}

			printf("\n\n\n saindo... \n");

			free(sequencia);
			free(buffer);
			numInt = NULL;
			numFloat = NULL;
			numDouble = NULL;
			buffer = NULL;
			sequencia = NULL;

			return (0);
			break;
		
		default:
			printf("\nOPCAO INVALIDA");
			break;
		}
	}
}
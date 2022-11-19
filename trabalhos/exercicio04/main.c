// NOME: Yasmin Souza Camargo
/* EXERCÍCIO: Dado um vetor nums contendo n número inteiros positivos e únicos encontre o número faltante na sequência. Assuma que somente um número está faltando para completar a
sequência numérica. */

#include <stdio.h>
#include <stdlib.h>

// Escopo das funções
void Print(int *vet, int tamanho);
void MergeSort(int * vet, int limiteEsquerda, int limiteDireita);
int NumeroFaltante(int *vet, int tamanho);

int main()
{
	int n = 0, *vet = NULL, numero = 1;

	vet = (int *)(malloc(sizeof(int) * n));
	printf("\n\n --- Para sair digite (- 1) ----\n\n");

	//Lê inteiros positivos
	while (numero >= 0){
		printf("Digite um numero: ");
		scanf("%d", &numero);
		if (numero >= 0){
			n++;
			vet = (int *)(realloc(vet, sizeof(int) * n + 1));
			vet[n - 1] = numero;
		}
	}

	printf("\n\n Vetor original: | ");	// mostra vetor
	Print(vet, n);
	
	printf("\n\n Vetor ordenado: | ");	// mostra vetor depois da ordenação 
	MergeSort(vet, 0, n - 1);
	Print(vet, n);

	printf("\n\n Numero faltante: %d\n\n", NumeroFaltante(vet, n));
	
	free(vet);
	return (0);
}

//--------------------------------------------------------------
// FUNÇÕES

void Print(int *vet, int tamanho){
	for (int i = 0; i < tamanho; i++){
		printf("%d | ", vet[i]);
	}
}

void MergeSort(int * vet, int limiteEsquerda, int limiteDireita){  // Ordena vetor
	int i = 0, j = 0, k = 0, metade = 0, aux[limiteDireita - limiteEsquerda + 1];

	if (limiteEsquerda < limiteDireita){ 
		metade = (limiteEsquerda + limiteDireita) / 2;

		// divide vetor
		MergeSort(vet, limiteEsquerda, metade);
		MergeSort(vet, metade + 1, limiteDireita);

		i = limiteEsquerda;		// inicio da primeira metade
		j = metade + 1;			// inicio da segunda metade
		k = 0;					// inicio do vetor auxiliar

		while (i <= metade && j <= limiteDireita){	// Ordena numeros
			if (vet[i] < vet[j]){
				aux[k] = vet[i];
				i++;
			} else{
				aux[k] = vet[j];
				j++;
			}
			k++;
		}

		while (i <= metade){	// lado direito é maior
			aux[k] = vet[i];
			i++;
			k++;
		}

		while (j <= limiteDireita){	// lado esquerdo é maior
			aux[k] = vet[j];
			j++;
			k++;
		}

		// coloca números ordenados no vetor principal
		for (i = limiteEsquerda; i <= limiteDireita; i++){
			vet[i] = aux[i - limiteEsquerda];
		}
	}
}

int NumeroFaltante(int *vet, int tamanho){	// Encontra número que esta faltando na sequencia
	int num = vet[0];
	for (int i = 0; i < tamanho; i++){
		if (num != vet[i]){
			return num;
		}
		num++;
	}
	return num++;
}


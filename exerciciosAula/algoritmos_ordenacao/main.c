// NOME: Yasmin Souza Camargo
// EXERCÍCIO: 3- O programa deve preencher um vetor de tamanho n com números aleatórios. Usar srand(time(NULL)); no inicio do programa.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
	

//Escopo das funções
void Print(int tamanho, int vetor[]);
void RandVetor(int tamanho, int *vetor);
void InsertionSort(int tamanho, int *vetor);
int verifica(int tamanho, int vetor[]);

int main()
{
    int tamanho = 6, vetor[tamanho];

    srand(time(NULL));          // definindo semente
    RandVetor(tamanho, vetor);  // coloca valores aleatórios no vetor

    printf("\n Vetor original: ");  // mostra vetor original
    Print(tamanho, vetor);
    
    printf("\n Insertion sort: ");  // ordena vetor
    InsertionSort(tamanho, vetor);
    Print(tamanho, vetor);

    if (verifica(tamanho, vetor)){
        printf("\n\n O vetor esta ordenado");
    }
    else{
        printf("\n\n --- O vetor nao esta ordenado ---\n\n");
    }
}

void Print(int tamanho, int vetor[]){
    for (int i = 0; i < tamanho; i ++){
        printf("%d, ", vetor[i]);
    }
}

void RandVetor(int tamanho, int *vetor){
    for (int i = 0; i < tamanho; i++){
        vetor[i] = rand()%100;
    }
}

void InsertionSort(int tamanho, int *vetor){
    int aux, i, j;

    for (i = 1; i < tamanho; i++){
        aux = vetor[i];
        j = i - 1;
        while (j >= 0 && aux < vetor[j]){
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = aux;
    }
}


int verifica(int tamanho, int vetor[]){
    int antes = 0, estaordenado = 1;
    for (int i = 0; i < tamanho; i++){
        if (antes <= vetor[i]){
            antes = vetor[i];
        } else{
            estaordenado = 0;
        }
    }
    return estaordenado;
}
// NOME: Yasmin Souza Camargo
/* 
EXERCÍCIO: 3 
O programa deve preencher um vetor de tamanho n com números aleatórios. Usar srand(time(NULL)); no inicio do programa.
Ordenar valores por Insertion Sort, Selection Sort, Quick Sertion e Merge Sort
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
	

//Escopo das funções
void Print(int tamanho, int vetor[]);
void RandVetor(int tamanho, int *vetor);
int verifica(int tamanho, int vetor[]);

void InsertionSort(int tamanho, int *vetor);
void SelectionSort(int tamanho, int *vetor);
void QuickSort(int *vetor, int limiteDireita, int limiteEsquerda);
void MergeSort(int *vetor, int limiteEsquerda, int limiteDireita);

int main()
{
    int tamanho = 6, vetor1[tamanho], vetor2[tamanho], vetor3[tamanho], vetor4[tamanho];

    // Gerando vetor com números aleatórios
    srand(time(NULL));           // definindo semente
    RandVetor(tamanho, vetor1);  
    RandVetor(tamanho, vetor2);  
    RandVetor(tamanho, vetor3);  
    RandVetor(tamanho, vetor4);  

    // INSERTION SORT
    printf("\n___________________________________________\n");
    printf("\n Vetor original: | ");  // mostra vetor original
    Print(tamanho, vetor1);
    printf("\n Insertion sort: | ");  // ordena vetor
    InsertionSort(tamanho, vetor1);
    Print(tamanho, vetor1);

    // SELECTION SORT
    printf("\n___________________________________________\n");
    printf("\n Vetor original: | ");  // mostra vetor original
    Print(tamanho, vetor2);
    printf("\n Selection sort: | ");  // ordena vetor
    InsertionSort(tamanho, vetor2);
    Print(tamanho, vetor2);

    // QUICK SORT
    printf("\n___________________________________________\n");
    printf("\n Vetor original: | ");  // mostra vetor original
    Print(tamanho, vetor3);
    printf("\n Quick sort:     | ");  // ordena vetor
    QuickSort(vetor3, 0, tamanho - 1);
    Print(tamanho, vetor3);

    // MERGE SORT
    printf("\n___________________________________________\n");
    printf("\n Vetor original: | ");  // mostra vetor original
    Print(tamanho, vetor4);
    printf("\n Merge sort:     | ");  // ordena vetor
    MergeSort(vetor4, 0, tamanho - 1);
    Print(tamanho, vetor4);
    printf("\n___________________________________________\n");

    //verifica se todos os vetores estão ordenados
    if (verifica(tamanho, vetor1) && verifica(tamanho, vetor2) && verifica(tamanho, vetor3) && verifica(tamanho, vetor4)){
        printf("\n\n   --- O vetores estao ordenados ---\n\n");
    }
    else{
        printf("\n\n   --- Nao sao todos os vetores que estao ordenados ---\n\n");
    }
}

// --------------------------------------------------------------------
// FUNÇÕES
void Print(int tamanho, int vetor[]){ // Mostra vetor
    for (int i = 0; i < tamanho; i ++){
        printf("%d | ", vetor[i]);
    }
}

void RandVetor(int tamanho, int *vetor){    // Coloca números aleatórios no vetor
    for (int i = 0; i < tamanho; i++){
        vetor[i] = rand()%10;
    }
}

int verifica(int tamanho, int vetor[]){ // Verifica se os números estão ordenados
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


// ALGORITMOS DE ORDENAÇÃO
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

void SelectionSort(int tamanho, int *vetor){
    int aux, menor, id;
    for (int i = 0; i < tamanho; i++){
        menor = vetor[i];
        id = i;
        for (int j = i + 1; j < tamanho; j++){
            if (vetor[j] < menor){
               menor = vetor[j];
               id = j;
            }
        }
        aux = vetor[i];
        vetor[i] = vetor[id];
        vetor[id] = aux;
    }
}

void QuickSort(int *vetor, int limiteEsquerda, int limiteDireita){
    int pivo = vetor[(limiteEsquerda + limiteDireita) / 2], i = limiteEsquerda, j = limiteDireita, aux;
    do{
        while (vetor[i] < pivo && i < limiteDireita){    // procura um elemento que é maior que o pivo
            i++;
        }
        while (vetor[j] > pivo && j > limiteEsquerda){    // procura um elemento que é menor que o pivo
            j--;
        }

        if (i <= j){    // Inverte os elementos trocados se i e j não se cruzaram
            aux = vetor[i];        
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++;
            j--;
        }
    } while(i <= j);

    //Separou uma metadade separa outra
    if (j > limiteEsquerda){
        QuickSort(vetor, limiteEsquerda, j);
    }
    if (i < limiteDireita){
        QuickSort(vetor, i, limiteDireita);
    }
}

void MergeSort(int *vetor, int limiteEsquerda, int limiteDireita){
    int metade, i, j, k, temp[limiteDireita - limiteEsquerda + 1];

    if (limiteEsquerda < limiteDireita){                 // tamanho do vetor deve ser maior que um
        metade = (limiteEsquerda + limiteDireita) / 2;   // meio do vetor

        // divide vetor 
        MergeSort(vetor, limiteEsquerda, metade);
        MergeSort(vetor, metade + 1, limiteDireita);

        i = limiteEsquerda;     // inicio da primeira parte do vetor
        j = metade + 1;         // inicio da segunda parte do vetor
        k = limiteEsquerda;     // inicio do vetor auxiliar para colocar valores ordenados

        // ordena números e coloca eles em um vetor auxiliar
        while (i <= metade && j <= limiteDireita){  
            if (vetor[i] < vetor[j]){
                temp[k] = vetor[i];
                i++;
            } else{
                temp[k] = vetor[j];
                j++;
            }
            k++;
        }

        while (i <= metade){    // lado direito é menor
            temp[k] = vetor[i];
            i++;
            k++;
        }

        while (j <= limiteDireita){ // lado esquerdo é menor
            temp[k] = vetor[j];
            j++;
            k++;
        }

        // coloca números ordenados no vetor principal
        for (i = limiteEsquerda; i <= limiteDireita; i++){   
            vetor[i] = temp[i];
        }
    }   
}
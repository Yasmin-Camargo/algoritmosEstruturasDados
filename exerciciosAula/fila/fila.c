//NOME: Yasmin Souza Camargo
//FILA

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10

typedef struct{
	int numero[MAX];
    int first;
    int last;
    int limite;
}Fila;

//Escopo de funções
Fila* Reset ();
void Push(int num, Fila *minhaFila);
int Pop(Fila *minhaFila);
void Clear(Fila *minhaFila);
void Print(Fila *minhaFila);

int main()
{
    Fila *novoNumero;
    novoNumero = Reset();
    printf("\n\nTodos Elementos:");
    Push(1, novoNumero);
    Push(2, novoNumero);
    Push(3, novoNumero);
    Push(4, novoNumero);
    Print(novoNumero);
    printf("\n\nElemento Removido: %d", Pop(novoNumero));
  
    printf("\n\nTodos Elementos:");
    Print(novoNumero);
}

Fila* Reset (){
    Fila *numeros = (Fila *) malloc(sizeof(Fila));
    numeros->last = 0;
    numeros->limite = MAX;
    numeros->first = 0;
    return numeros;
}

void Push(int num, Fila *minhaFila){
    if (minhaFila->last == minhaFila->limite){
        printf("A Fila ja atingiu a sua capacidade");
    }
    else{
        minhaFila->numero[minhaFila->last] = num;
        minhaFila->last++;
    }
}


int Pop(Fila *minhaFila){
    int numRemov = 0;
    if (minhaFila->last == 0){
        printf("\nA Fila esta vazia");
        exit (1);
    }
    else{
        numRemov = minhaFila->numero[minhaFila->first];
        for(int i = minhaFila->first; i < minhaFila->last - 1; i++){
            minhaFila->numero[minhaFila->first + i] = minhaFila->numero[minhaFila->first + i + 1];
        }
        minhaFila->last--;
        return (numRemov);
    }
}

void Clear(Fila *minhaFila){
    free(minhaFila);
}

void Print(Fila *minhaFila){
    for (int i = minhaFila->first; i < minhaFila->last; i++){
        printf("\n%d) %d", i, minhaFila->numero[i]);
    }
}
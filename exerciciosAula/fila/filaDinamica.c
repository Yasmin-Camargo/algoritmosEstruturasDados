//NOME: Yasmin Souza Camargo
//FILA

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10

typedef struct{
	int numero;
    struct Fila *next;  
}Fila;
Fila *first;
Fila *last;
int limite;

//Escopo de funções
void Reset ();
void Push(int num);
int Pop();
void Clear();
void Print();

int main()
{
    Reset();
    printf("\n\nTodos Elementos:");
    Push(1);
    Push(2);
    Push(3);
    Push(4);
    Print();
    Pop();
    Print();
    Clear();
    printf("\nlimpou");
    Print();
 
}

void Reset (){
    last = NULL;
    first = NULL;
    limite = 0;
}

void Push(int num){   
    Fila *minhaFilaNova;
    minhaFilaNova = (Fila *) malloc(sizeof(Fila));
    minhaFilaNova->numero = num;
    minhaFilaNova->next = NULL;

    if (first == NULL){
        first = minhaFilaNova;
        last = minhaFilaNova;
    }
    else{
        last->next = minhaFilaNova;
        last = minhaFilaNova;
        minhaFilaNova->next = NULL;
    }
}

int Pop(){
    int numRemov = 0;
    if (first == NULL){
        printf("\nA Fila esta vazia");
        exit (1); 
    }
    else{
        Fila *aux;
        aux = first;
        numRemov = first->numero;
        first = first->next;
        free (aux);
        return (numRemov);
    }
}

void Clear(){
    while (first != NULL){
        Pop();
    }
}

void Print(){
     printf("\n ");
    for (Fila *i = first; i != NULL; i = i->next){
        printf("\n %d", i->numero);
    }
}
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10

typedef struct{
	int numero[MAX];
    int topo;
    int base;
    int limite;
}Pilha;

//Escopo de funções
Pilha* Reset ();
void Push(int num, Pilha *minhaPilha);
int Pop(Pilha *minhaPilha);
void Clear(Pilha *minhaPilha);
void Print(Pilha *minhaPilha);

int main()
{
    Pilha *novoNumero;
    novoNumero = Reset();
    Push(1, novoNumero);
    Push(3, novoNumero);
    Push(4, novoNumero);
    Push(2, novoNumero);
    Print(novoNumero);
    printf("\n\n%d",Pop(novoNumero));
    printf("\n%d",Pop(novoNumero));
    printf("\n%d",Pop(novoNumero));
    printf("\n%d",Pop(novoNumero));
}

Pilha* Reset (){
    Pilha *numeros = (Pilha *) malloc(sizeof(Pilha));
    numeros->base = 0;
    numeros->limite = MAX;
    numeros->topo = 0;
    return numeros;
}

void Push(int num, Pilha *minhaPilha){
    if (minhaPilha->topo == minhaPilha->limite){
        printf("A pilha ja atingiu a sua capacidade");
    }
    else{
        minhaPilha->numero[minhaPilha->topo] = num;
        minhaPilha->topo++;
    }
}


int Pop(Pilha *minhaPilha){
    int numRemov = 0;
    if (minhaPilha->topo == minhaPilha->base){
        printf("\nA pilha esta vazia");
        exit (1);
    }
    else{
        numRemov = minhaPilha->numero[minhaPilha->topo - 1];
        minhaPilha->topo--;
        return (numRemov);
    }
}

void Clear(Pilha *minhaPilha){
    free(minhaPilha);
}

void Print(Pilha *minhaPilha){
    for (int i = minhaPilha->topo; i > minhaPilha->base; i--){
        printf("\n%d", minhaPilha->numero[i - 1]);
    }
}
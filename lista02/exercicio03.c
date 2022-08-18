//NOME: Yasmin Souza Camargo
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Escopo das funções
void adicionarPessoa();
void mostrarPessoa();
void buscarPessoa();
void apagarPessoa();

int main (){
    void *pBuffer;
    int op=0;

    while (op!=5){
        printf ("\n\n ----------------------------");
        printf ("\n            AGENDA            ");
        printf ("\n ----------------------------  ");
        printf ("\n  1) Incluir ");
        printf ("\n  2) Mostrar ");
        printf ("\n  3) Buscar ");
        printf ("\n  4) Apagar ");
        printf ("\n  0) Sair ");
        printf ("\n Escolha uma opcao: ");
        scanf ("%d",&op);
        switch (op){
        case 1:
            /* code */
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 0:
            printf("\n\n Saindo...");
            break;
        default:
            printf("\n\n OPCAO INVALIDA!!! Por favor, tente novamente");
            break;
        }
    }
}
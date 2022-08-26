//NOME: Yasmin Souza Camargo
/*Faça um programa que armazene a informação de várias pessoas.
O programa só deve sair quando o usuário disser que não deseja mais entrar com os dados de outra pessoa.
Antes de sair o programa deve apresentar, de forma organizada, os dados de todas as pessoas
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Escopo das funções
void adicionarPessoa(int numPessoas);
void mostrarPessoa(int numPessoas);

//Struct para armazenar dados da pessoa
typedef struct registroAluno{
    char nome[10];
    int idade;
    char telefone[11];
}Pessoa;
Pessoa *novaPessoa;

int main()
{
    int numPessoas = 0, op = 1;

    novaPessoa = (Pessoa *) malloc(sizeof(Pessoa));

    while (op != 0){
        printf("\n==========================================\n");
        printf("\nPara sair pressione 0\n");
        printf("Para entrar com dados de mais uma pessoa digite 1: ");
        scanf ("%d", &op);
        printf("\n==========================================\n");

        switch (op){
            case 1:
                numPessoas++;
                novaPessoa = (Pessoa *) realloc(novaPessoa, numPessoas * sizeof(Pessoa));
                adicionarPessoa(numPessoas);
                break;
            case 0:
                mostrarPessoa(numPessoas);
                free (novaPessoa); 
                break;
            default:
                printf("\n OPCAO INVALIDA!!! Por favor, tente novamente\n");
                break;
        }    
    }
}

void adicionarPessoa(int numPessoas){
    printf("\n\nDigite os seguintes dados da pessoa %d: ", numPessoas);
    printf("\n  Nome: ");
    scanf ("%s", &novaPessoa[numPessoas-1].nome);
    printf("  Idade: ");
    scanf ("%d", &novaPessoa[numPessoas-1].idade);
    printf("  Telefone: ");
    scanf ("%s", &novaPessoa[numPessoas-1].telefone);
}

void mostrarPessoa(int numPessoas){
    printf ("\n\nRESUMO");
    for (int i = 0; i < numPessoas; i++){
        printf ("\n__________________________________");
        printf("\n\n %d)", i+1);
        printf("\n Nome: %s", novaPessoa[i].nome);
        printf("\n Idade: %d", novaPessoa[i].idade);
        printf("\n Telefone %s", novaPessoa[i].telefone);
    }
}
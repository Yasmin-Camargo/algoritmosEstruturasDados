//NOME: Yasmin Souza Camargo
/*
O programa deve armazenar no máximo 10 pessoas
Todas as variáveis que forem usadas no programa deve ser ponteiros. A única exceção é o item 1 que deve ser uma variável global Pessoa pessoas[10].
Os ponteiros devem apontar para um buffer chamado pBuffer onde os dados devem
ser armazenados. Por exemplo, um contador para um for deve ser um ponteiro para
int e o int vai ficar armazenado dentro de pBuffer
Não pode usar struct dentro do pBuffer
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Escopo das funções
void adicionarPessoa(int *numPessoas);
void mostrarPessoa(int *numPessoas, void *pBuffer, int *i);
void buscarPessoa(int *numPessoas, void *pBuffer, char *palavra, int *op, int *i);
void apagarPessoa(int *numPessoas, void *pBuffer, char *palavra, int *op, int *i);

//Struct para armazenar dados da pessoa
typedef struct registroAluno{
    char nome[10];
    int idade;
    char telefone[11];
}Pessoa;

Pessoa pessoas[10];

int main()
{
    //Ponteiros
    void *pBuffer = NULL;
    int *numPessoas = NULL, *i, *op, *palavra;

    //alocando memória
    pBuffer = (void *) malloc(3*sizeof(int)+sizeof(char)*10); 
    if (pBuffer == NULL){
        printf("\n\n ERRO de alocacao de memoria!!");
        exit(1);
    }

    //Definindo onde irá apontar cada ponteiro
    op = pBuffer;
    numPessoas = pBuffer + sizeof(int);
    i = pBuffer + 2*sizeof(int);
    palavra = pBuffer + 3*sizeof(int);

    //Inicializando váriaveis
    *op = 1;
    *numPessoas = 0;
    *i = 0;
    strcpy(palavra,"");

    while (*op != 0){
        printf ("\n\n ----------------------------");
        printf ("\n          AGENDA 1.2           ");
        printf ("\n ----------------------------  ");
        printf ("\n  1) Incluir ");
        printf ("\n  2) Mostrar ");
        printf ("\n  3) Buscar ");
        printf ("\n  4) Apagar ");
        printf ("\n  0) Sair ");
        printf ("\n Escolha uma opcao: ");
        scanf ("%d",op);
        switch (*op){
        case 1:
            adicionarPessoa(numPessoas);
            break;
        case 2:
            mostrarPessoa(numPessoas, pBuffer, i);
            break;
        case 3:
            buscarPessoa(numPessoas, pBuffer, palavra, op, i);
            break;
        case 4:
            apagarPessoa(numPessoas, pBuffer, palavra, op, i);
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

void adicionarPessoa(int *numPessoas){
    if (*numPessoas + 1 <= 10){
        *numPessoas = *numPessoas + 1;
        //Adicinando dados
        fflush(stdin);
        printf("\n\nAdicione os seguintes dados: ");
        printf("\n Nome: ");
        scanf("%s", pessoas[*numPessoas-1].nome);

        printf(" Idade: ");
        scanf("%d", &pessoas[*numPessoas-1].idade);

        printf(" Telefone: ");
        scanf("%s", pessoas[*numPessoas-1].telefone);
    }
    else{
        printf("\n\nERRO!\nO numero maximo de pessoas ja foi atingido");
    }
    
}

void mostrarPessoa(int *numPessoas, void *pBuffer, int *i){
    printf ("\n\nQuantidade de pessoas armazenadas: %d", *(int *) (pBuffer + sizeof(int)));
    printf ("\n__________________________________");
    
    //Mostra os dados armazenados
    for (*i=0; *i < *numPessoas; *i = *i + 1){
        printf("\n\n %d)", *i+1);
        printf("\n Nome: %s", pessoas[*i].nome);
        printf("\n Idade: %d", pessoas[*i].idade);
        printf("\n Telefone %s", pessoas[*i].telefone);
    }
}

void buscarPessoa(int *numPessoas, void *pBuffer, char *palavra, int *op, int *i){
    *op=0;
    printf("\nQual nome voce deseja buscar: ");
    scanf("%s", palavra);
    for (*i=0; *i < *numPessoas; *i = *i + 1){
        if (strcmp(pessoas[*i].nome, pBuffer + 3*sizeof(int)) == 0){
            *op=1;
            printf("\n\n == O nome foi encontrado! ==\n");
            printf("\n Nome: %s", pessoas[*i].nome);
            printf("\n Idade: %d", pessoas[*i].idade);
            printf("\n Telefone %s", pessoas[*i].telefone);
        }
    }
    if (*op != 1){
        printf("\n\n O nome nao foi encontrado!");
        *op=1;
    } 
}

void apagarPessoa(int *numPessoas, void *pBuffer, char *palavra, int *op, int *i){
    *op=0;
    printf("\nDigite o nome a ser excluido: ");
    scanf("%s", palavra);
    for (*i=0; *i < *numPessoas; *i = *i + 1){
        if (strcmp(pessoas[*i].nome, pBuffer + 3*sizeof(int)) == 0){
            *op=1;
        }
        if (*op == 1){
            strcpy(pessoas[*i].nome, pessoas[*i+1].nome);
            pessoas[*i].idade = pessoas[*i+1].idade;
            strcpy(pessoas[*i].telefone, pessoas[*i+1].telefone);
        }
    }
    if (*op==1){
        printf("\nPalavra excluida com sucesso!\n");
        *numPessoas = *numPessoas - 1;
    } 
    else{
        printf("\nPalavra não encontrada!\n");
        *op=1;
    }
}


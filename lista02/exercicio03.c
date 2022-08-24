//NOME: Yasmin Souza Camargo
/*Faça uma agenda capaz de incluir, apagar, buscar e listar quantas pessoas o usuário desejar, porém, toda a informação incluída na agenda deve ficar num único lugar chamado: “void *pBuffer”.
- Não pergunte para o usuário quantas pessoas ele vai incluir.
- Não pode alocar espaço para mais pessoas do que o necessário.
- Cada pessoa tem nome[10], idade e telefone.*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Escopo das funções
void adicionarPessoa();
void mostrarPessoa();
void buscarPessoa();
void apagarPessoa();

//Ponteiros
void *pBuffer = NULL;
char *nome = NULL, *telefone = NULL;
int *idade = NULL, *numPessoas = NULL;

int main (){
    //Variaveis
    int op=1;

    //alocando memória
    //                      num de pessoas         nome             idade        telefone
    pBuffer = (void *) malloc(sizeof(int) + sizeof(char)*10 + 1 + sizeof(int) + sizeof(char)*11 + 2); 

    if (pBuffer == NULL){
        printf("\n\n ERRO de alocacao de memoria!!");
        exit(1);
    }

    numPessoas = pBuffer;
    nome = pBuffer + sizeof(int);
    idade = pBuffer + sizeof(int) + sizeof(char) * 10 + 1;
    telefone = pBuffer + sizeof(int) + sizeof(char) * 10 + 1 + sizeof(int);

    if (numPessoas==NULL || nome == NULL || idade == NULL || telefone == NULL){
        printf("\n\n ERRO de alocacao de memoria!!");
        exit(1);
    }

    //Inicializando váriaveis
    *numPessoas = 0;
    strcpy(nome, "");
    *idade = 0;
    strcpy(telefone, "");

    printf ("\n CONTEUDO VETORES:");
    printf ("\n %d", *numPessoas);
    printf ("\n %s", nome);
    printf ("\n %d", *idade);
    printf ("\n %s", telefone);

    printf ("\n\n CONTEUDO *pBuffer:");
    printf ("\n %d", *(int *) (pBuffer));
    printf ("\n %s", (char *) (pBuffer + sizeof(int)));
    printf ("\n %d",  *(int *) (pBuffer + sizeof(int) + sizeof(char)*10 + 1));
    printf ("\n %s",  (char *) (pBuffer + sizeof(int) + sizeof(char)*10 + 1 + sizeof(int)));

    
    while (op!=0){
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
            adicionarPessoa();
            break;
        case 2:
            mostrarPessoa();
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
    free(pBuffer);
}

void adicionarPessoa(){
    char caracteres[20];
    int idadeaux;

    *numPessoas=*numPessoas+1; //nova pessoa
    printf ("++ %d", *(int *) (pBuffer));
    

    fflush(stdin);
    printf("\n\nAdicione os seguintes dados: ");
    printf("\n Nome: ");
    scanf("%s", caracteres);
    strcat(nome,caracteres);

    printf(" Idade: ");
    scanf("%d", &idadeaux);
    *idade = idadeaux;

    printf(" Telefone: ");
    scanf("%s", caracteres);
    strcat(telefone,caracteres);
    strcat(telefone,";");
}


void mostrarPessoa(){
    printf ("\n\n CONTEUDO *pBuffer atualizado:");
    printf ("\n %d", *(int *) (pBuffer));
    printf ("\n %s", (char *) (pBuffer + sizeof(int)));
    printf ("\n %d",  *(int *) (pBuffer + sizeof(int) + sizeof(char)*10 + 1));
    printf ("\n %s",  (char *) (pBuffer + sizeof(int) + sizeof(char)*10 + 1 + sizeof(int))); 
}
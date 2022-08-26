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
int *numPessoas = NULL, *idade = NULL;
char *nome = NULL, *telefone = NULL;

//Tamanho do ponteiro void
//                   nome                idade          telefone
#define TAMANHO (sizeof(char)*10 + 1 + sizeof(int) + sizeof(char)*11 + 1)

int main (){
    //Variaveis
    int op=1;

    //alocando memória
    pBuffer = (void *) malloc(sizeof(int) + TAMANHO); 
    if (pBuffer == NULL){
        printf("\n\n ERRO de alocacao de memoria!!");
        exit(1);
    }

    //Definindo onde irá apontar cada ponteiro
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
    
    while (op!=0){
        printf ("\n\n ----------------------------");
        printf ("\n          AGENDA 1.1           ");
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
            buscarPessoa();
            break;
        case 4:
            apagarPessoa();
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
    char caracteres[10];
    int tamanhoFoiArmazenado;

    strcpy(caracteres,"");
    *numPessoas=*numPessoas+1; //nova pessoa

    //Adicionando novos dados
    if (*numPessoas != 1){
        tamanhoFoiArmazenado = (*numPessoas-1) *  TAMANHO + sizeof(int);

        //Realocando espaço para mais um item
        pBuffer = (void*)realloc(pBuffer, *numPessoas *  TAMANHO + sizeof(int));
        if (pBuffer == NULL){
            printf("Erro na alocacao de memoria");
            exit (1);
        }

        //Definindo onde os novos enderereços onde vão apontar
        nome = pBuffer + tamanhoFoiArmazenado;
        idade = pBuffer + sizeof(char) * 10 + 1 + tamanhoFoiArmazenado;
        telefone = pBuffer + sizeof(char) * 10 + 1 + sizeof(int) + tamanhoFoiArmazenado;
        if (numPessoas==NULL || nome == NULL || idade == NULL || telefone == NULL){
            printf("\n\n ERRO de alocacao de memoria!!");
            exit(1);
        }
    }

    //Adicinando dados
    fflush(stdin);
    printf("\n\nAdicione os seguintes dados: ");
    numPessoas = pBuffer;
    printf("\n Nome: ");
    scanf("%s", caracteres);
    strcpy(nome,caracteres);

    printf(" Idade: ");
    scanf("%d", idade);

    printf(" Telefone: ");
    scanf("%s", caracteres);
    strcpy(telefone,caracteres);
}


void mostrarPessoa(){
    printf ("\n\nQuantidade de pessoas armazenadas: %d", *(int *) pBuffer );
    printf ("\n__________________________________");

    for (int i = 0; i < *numPessoas; i++){
        printf ("\n\n %d)", i+1);
        printf ("\n Nome: %s", (char *) (pBuffer + (TAMANHO * i) + sizeof(int)));
        printf ("\n Idade: %d",  *(int *) (pBuffer + (TAMANHO * i) + sizeof(int) + sizeof(char)*10 + 1));
        printf ("\n Telefone: %s",  (char *) (pBuffer + (TAMANHO * i) + sizeof(int) + sizeof(char)*10 + 1 + sizeof(int))); 
    }
    printf ("\n__________________________________\n");
}


void buscarPessoa(){
    char caracteres[10];
    int encontrou=0;
    strcpy(caracteres,"");

    printf("\nQual nome voce deseja buscar: ");
    scanf("%s",caracteres);
    
    for (int i = 0; i < *numPessoas; i++){
        if (strcmp(((char *) (pBuffer + (TAMANHO * i) + sizeof(int))), caracteres) == 0){
            printf("\n\n == O nome foi encontrado! ==\n");
            encontrou=1;

            //Mostra dados da pessoa se encontrou o nome
            printf ("\n Nome: %s", (char *) (pBuffer + (TAMANHO * i) + sizeof(int)));
            printf ("\n Idade: %d",  *(int *) (pBuffer + (TAMANHO * i) + sizeof(int) + sizeof(char)*10 + 1));
            printf ("\n Telefone: %s",  (char *) (pBuffer + (TAMANHO * i) + sizeof(int) + sizeof(char)*10 + 1 + sizeof(int))); 
            break;
        }
    }  
    if (encontrou==0){
        printf("\n\n Este nome nao foi encontrado! :( ");
    }
}


void apagarPessoa(){
    char caracteres[10];
    int apagar=0, encontrou=0;

    printf("\nDigite o nome a ser excluido: ");
    scanf("%s", caracteres);

    for (int i = 0; i < *numPessoas; i++){
        if (strcmp(((char *) (pBuffer + (TAMANHO * i) + sizeof(int))), caracteres) == 0){
            apagar=1; //Se encontrou o nome começa a mover a informação
            encontrou=1;
        }
        if (apagar==1){
            //Sobrescreve os dados até que toda a palavra esteja removida (nome a ser removido é substituido pelo que vem depois dele)
            //nome
            strcpy((char *) (pBuffer + (TAMANHO * (i)) + sizeof(int)), (char *) (pBuffer + (TAMANHO * (i+1)) + sizeof(int)));
            
            //idade
            *(int *) (pBuffer + (TAMANHO * (i)) + sizeof(int) + sizeof(char)*10 + 1) = *(int *) (pBuffer + (TAMANHO * (i+1)) + sizeof(int) + sizeof(char)*10 + 1);
            
            //telefone
            strcpy((char *) (pBuffer + (TAMANHO * (i)) + sizeof(int) + sizeof(char)*10 + 1 + sizeof(int)), (char *) (pBuffer + (TAMANHO * (i+1)) + sizeof(int) + sizeof(char)*10 + 1 + sizeof(int)));
        }
    } 
    
    //Realocando novo espaço
    pBuffer = (void*)realloc(pBuffer, (*numPessoas-1) * TAMANHO + sizeof(int));
    *numPessoas = *numPessoas-1;

    if (encontrou==1){
        printf("\nPalavra excluida com sucesso!\n");
    } 
}

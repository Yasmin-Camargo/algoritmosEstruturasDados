//NOME: Yasmin Souza Camargo
/*Faça um programa que armazena nomes. O programa deve armazenar
todos os nomes na mesma string. O tamanho da string deve crescer e diminuir
conforme nomes forem colocados ou removidos. Não pode ter desperdício de memória.*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Escopo das funções
void adicionarNome();
void mostrarNome();
void excluirNome();

//Váriaveis globais
char *nomes;
int elementos = 0;

int main(){
    int op = 1;

    //alocando memória
    nomes = (char*) malloc(sizeof(char )); 
    //testa se conseguiu alocar espaço
    if (nomes == NULL){
        printf("Erro na alocacao de memoria");
        exit (1);
    }

    //Verificando se conseguiu alocar memória
    if (nomes == NULL){
        printf("\n\n ERRO de alocacao de memoria!!");
        exit(1);
    }

    //menu
    while (op != 0){
        printf("\n\n --- 1) Adicionar nome");
        printf("\n --- 2) Remover nome");
        printf("\n --- 3) Listar");
        printf("\n --- 4) Sair");
        printf("\n   Escolha uma opcao: ");
        scanf("%d", &op);

        switch (op){
            case 1:
                adicionarNome();
            break;

            case 2:
                excluirNome();
            break;

            case 3:
                mostrarNome();
            break;

            case 4:
            printf("\n\n Saindo...");
            op=0;
            break;

            default:
            printf("\n\n OPCAO INVALIDA!!!");
        }
    }
    //liberando memória
    free(nomes);
}


//FUNÇÕES:
void adicionarNome(){
    char caracteres[20];

    fflush(stdin);
    printf("\n\n Digite o nome a ser adicionado: ");
    scanf("%s", caracteres);
    strcat(caracteres, ";");
    
    //Realocando espaço para mais uma palavra
    nomes = (char*) realloc(nomes, sizeof(caracteres) * sizeof(char) + 2);
    //Testa se conseguiu alocar espaço
    if (nomes == NULL){
        printf("Erro na alocacao de memoria");
        exit (1);
    }

    //Adiciona no ponteiro caracter por caracter da nova palavra
    int i=0;
    for (elementos; elementos <= (strlen(nomes)); elementos++) {
        nomes[elementos] = caracteres[i];
        i++;
    } 
    elementos--;
}
    
void mostrarNome(){
    printf("\n\n\n      Nomes:\n        %s", nomes);
}

void excluirNome(){
    char caracteresExcluidos[20];
    int posicao;

    printf("Digite o nome a ser excluido: ");
    scanf("%s", caracteresExcluidos);

    char *excluir = strstr(nomes, caracteresExcluidos); //ponteiro onde começa a string encontrada
    
    if (!excluir) { //Verifica se foi encontrado o nome
        printf("\n\n ERRO! O nome nao existe\n");
    } else{
        posicao = strlen(nomes) - strlen(excluir); //posição onde esta a palavra
        if (posicao != 0 && nomes[posicao - 1] == ',') {
            posicao--;
            excluir--;
        }

        //Move as letras até que toda a palavra esteja removida 
        for (int i = 0; i <= strlen(caracteresExcluidos); i++) {
            for (int j = 0; j < strlen(excluir); j++) {
                nomes[posicao + j] = nomes[posicao + j + 1];
            }
            elementos--;
        }

        //Realoca o novo espaço
        nomes = (char *)realloc(nomes, ((strlen(nomes)) + 2) * sizeof(char));
    }
}




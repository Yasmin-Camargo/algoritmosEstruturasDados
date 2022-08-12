#include <stdlib.h>
#include <stdio.h>

//Escopo das funções
void adicionarNome();

//Váriaveis globais
char **nomes=NULL;
int linhas=0;

int main(){
    int op=1;

    //alocando linhas e colunas
    nomes = (char**)malloc(linhas * sizeof(char *)); 
    nomes[linhas] = (char*)malloc(sizeof(char)); 

    //Verificando se conseguiu alocar memória
    if (nomes == NULL){
        printf("\n\n ERRO de alocacao de memoria!!");
        exit(1);
    }

    //menu
    while (op != 0){
        printf("\n\n1) Adicionar nome");
        printf("\n2) Remover nome");
        printf("\n3) Listar");
        printf("\n4) Sair");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &op);

        switch (op){
            case 1:
                adicionarNome();
            break;

            case 2:
            printf("Adicionando");
            break;

            case 3:
            printf("Adicionando");
            break;

            case 4:
            printf("\n\n Saindo...");
            op=0;
            break;

            default:
            printf("\n\n OPCAO INVALIDA!!! \n\n");
        }
    }
    
    //liberando memória
    for (int i = 0; i < linhas; i++){
        free(nomes[i]);
    }
    free(nomes);
    
}


//FUNÇÕES:
void adicionarNome(){
    char caracter;

    linhas++;
    nomes = (char**)realloc(*nomes, linhas * sizeof(char *));

    fflush(stdin);
    printf("\n\n Digite o nome a ser adicionado: ");
    scanf("%c", &caracter);
    
    int colunas=0;
    while (caracter != '\n'){
        nomes[linhas] = (char*)realloc(nomes, sizeof(caracter)+1);
        nomes[linhas][colunas] = caracter;
        
        if (nomes == NULL){
            printf("\n\n ERRO de alocacao de memoria!!");
            exit(1);
        }

        scanf("%c", &caracter);
        colunas++;
    }
    printf("\n\n-- Nome final: %s\n\n", nomes[linhas]);
}
    
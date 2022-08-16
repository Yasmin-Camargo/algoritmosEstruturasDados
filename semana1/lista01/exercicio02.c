#include <stdlib.h>
#include <stdio.h>

//Escopo das funções
void adicionarNome();
void mostrarNome();

//Váriaveis globais
char *nomes;
int elementos=0;

int main(){
    int op=1;

    //alocando memória
    nomes = (char*)malloc(sizeof(char )); 
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
            printf("Adicionando");
            break;

            case 3:
            mostrarNome();
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
    free(nomes);
    
}


//FUNÇÕES:
void adicionarNome(){
    char caracteres[20];

    fflush(stdin);
    printf("\n\n Digite o nome a ser adicionado: ");
    scanf("%s", &caracteres);
    strcat(caracteres,";");
    
    //Realocando espaço para mais uma palavra
    nomes = (char*)realloc(nomes, sizeof(caracteres) * sizeof(char) + 1);
    //Testa se conseguiu alocar espaço
    if (nomes == NULL){
        printf("Erro na alocacao de memoria");
        exit (1);
    }

    int i=0;
    for (elementos; elementos<=(strlen(nomes)); elementos++) {
        nomes[elementos] = caracteres[i];
        i++;
    } 
    elementos--;
    
    printf("\n\n-- Nome final: %s\n\n", nomes);
}
    

void mostrarNome(){
    printf("\n...\n");
    for (int i=0; i<=(strlen(nomes)); i++) {
        if (nomes[i] != ';'){
            printf("%c", nomes[i]);
        }
        if (nomes[i] == ';') {
            printf("\n");
        }
    }
    printf("\n...\n");
}



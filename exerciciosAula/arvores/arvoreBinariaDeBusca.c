//NOME: Yasmin Souza Camargo

// ARVORE BINÁRIA DE BUSCA
/* Implementar uma agenda (nome, idade, telefone) que armazena os dados numa árvore binária de busca (usuário escolhe qual dado é o fator de precedência). A agenda deve permitir incluir, buscar, remover e imprimir toda a árvore usando pré-ordem, central e pós-ordem. */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    char *chave;
    char *nome; 
    char *telefone;
    int idade;
    struct Nodo *esquerda; 
    struct Nodo *direita;  
}Nodo;

typedef struct{
    Nodo *raiz;
    int numNodos;
    char fatorPrecedencia;
}Arvore;


//Escopo de funções
Arvore *RESET();
Nodo *NEWNODO(char nome[], int idade, char telefone[], int fatorPrecedencia);
void PUSH(Nodo **tracer, Nodo *newp);
void PRINTPREORDEM(Nodo *minhaArvore);
void PRINTORDEM(Nodo *minhaArvore);
void PRINTPOSORDEM(Nodo *minhaArvore);
Nodo *SEARCH(Nodo **tracer, char *chave);
void POP(Nodo **tracer, char *chave);
void CLEAR(Nodo *tracer, Arvore *minhaArvore);


int main()
{
    Arvore *minhaArvore = NULL;
    int op = 1, fatorPrecedencia = 0, imprimir = 0, tempIdade = 0;
    char tempNome[30], tempTelefone[20];

    minhaArvore = RESET();
    
    do {
        printf ("\n\n ----------------------------\n");
        printf ("\n  1 - nome ");
        printf ("\n  2 - idade ");
        printf ("\n  3 - telefone \n");
        printf ("\nEscolha o fator de precedencia que voce deseja adicionar dados na arvore: ");
        scanf ("%d", &fatorPrecedencia);
    } while (!(fatorPrecedencia >= 1 && fatorPrecedencia <= 3));

    while (op != 0){
        printf ("\n\n ----------------------------");
        printf ("\n          AGENDA            ");
        printf ("\n ----------------------------  ");
        printf ("\n  1) Incluir ");
        printf ("\n  2) Mostrar ");
        printf ("\n  3) Buscar ");
        printf ("\n  4) Apagar ");
        printf ("\n  5) Alterar fator de precedencia ");
        printf ("\n  0) Sair ");
        printf ("\n\n Escolha uma opcao: ");
        scanf ("%d", &op);
        printf ("\n ----------------------------  ");
        switch (op){
        case 1:
            printf("\n\nAdicione os seguintes dados: ");
            printf("\n Nome: ");
            scanf("%s", tempNome);
            printf(" Idade: ");
            scanf("%d", &tempIdade);
            printf(" Telefone: ");
            scanf("%s", tempTelefone);
            PUSH(&(minhaArvore->raiz), NEWNODO(tempNome, tempIdade, tempTelefone, fatorPrecedencia));
            break;

        case 2:
            do {
                printf ("\n\n  1 - Pre-ordem");
                printf ("\n  2 - Ordem ");
                printf ("\n  3 - Pos-ordem \n");
                printf ("\n Como voce deseja imprimir toda a arvore: ");
                scanf ("%d", &imprimir);
            } while (!(imprimir >= 1 && imprimir <= 3));
            switch(imprimir){
                case 1:
                    printf("\n\n  PRE-ORDEM:\n  ");
                    PRINTPREORDEM(minhaArvore->raiz);
                break;

                case 2:
                    printf("\n\n  ORDEM:\n  ");
                    PRINTORDEM(minhaArvore->raiz);
                break;

                case 3:
                    printf("\n\n  POS-ORDEM:\n  ");
                    PRINTPOSORDEM(minhaArvore->raiz);
                break;
            }
            break;

        case 3:      
            printf("\n Digite a chave que voce deseja buscar: ");
            scanf("%s", tempNome);
            
            Nodo *busca;
            busca = SEARCH (&(minhaArvore->raiz), tempNome);
            if (busca == NULL){
                printf("\n\n DADO NAO FOI ENCONTRADO");
            } else{
                printf("\n\n Objeto foi encontrado: ");
                printf("\n nome: %s", busca->nome);
                printf("\n idade: %d", busca->idade);
                printf("\n telefone: %s", busca->telefone);
            }
            break;

        case 4:
            printf("\n Digite a chave que voce deseja excluir: ");
            scanf("%s", tempNome);
            POP(&(minhaArvore->raiz), tempNome);
            break;

        case 0:
            printf("\n\n Saindo...\n");
            CLEAR(minhaArvore->raiz, minhaArvore);
            break;

        default:
            printf("\n\n\n OPCAO INVALIDA!!! Por favor, tente novamente\n");
            break;
        }
    }
    return (0);
}

Arvore *RESET(){
    Arvore *novaArvore = (Arvore *)(malloc(sizeof(Arvore)));
    novaArvore->numNodos = 0;
    novaArvore->raiz = NULL;
    return novaArvore;
}

Nodo *NEWNODO(char nome[], int idade, char telefone[], int fatorPrecedencia){
    Nodo *novoNodo = (Nodo *) (malloc(sizeof(Nodo)));
    novoNodo->nome = (char *) (malloc(sizeof(char) * strlen(nome) + sizeof(char)));
    novoNodo->telefone = (char *) (malloc(sizeof(char) * strlen(telefone) + sizeof(char)));
    if (novoNodo == NULL || novoNodo->nome == NULL || novoNodo->telefone == NULL){
        printf("Erro de alocacao de memoria");
        exit(1);
    }

    novoNodo->direita = NULL;
    novoNodo->esquerda = NULL;
    novoNodo->idade = idade;
    strcpy(novoNodo->nome, nome);
    strcpy(novoNodo->telefone, telefone);

    //defindo a chave a ser utilizada
    if (fatorPrecedencia == 1){
        novoNodo->chave = (char *) (malloc(sizeof(char) * strlen(nome) + sizeof(char)));
        if (novoNodo->chave == NULL){
            printf("Erro de alocacao de memoria");
            exit (1);
        }
        strcpy(novoNodo->chave, nome);
    } else if (fatorPrecedencia == 2){
        novoNodo->chave = (char *) (malloc(sizeof(char) * 2 + sizeof(char)));
        if (novoNodo->chave == NULL){
            printf("Erro de alocacao de memoria");
            exit (1);
        }
        sprintf(novoNodo->chave, "%d", idade); //Converte idade para string
    } else {
        novoNodo->chave = (char *) (malloc(sizeof(char) * strlen(telefone) + sizeof(char)));
        if (novoNodo->chave == NULL){
            printf("Erro de alocacao de memoria");
            exit (1);
        }
        strcpy(novoNodo->chave, telefone);
    }
    return novoNodo;
}


void PUSH(Nodo **tracer, Nodo *newp){
    Nodo **temp = tracer;
    if (*temp == NULL){ //Primeira pessoa a ser inserida
        *tracer = newp;
    }
    else {
        while((*tracer)){ //Percorre a árvore até encontrar uma folha
            if(strcmp(newp->chave, (*tracer)->chave) > 0){ //Se é maior insere na direita
                if((*tracer)->direita == NULL){ //Encontrou uma folha
                    (*tracer)->direita = newp;
                    break;
                } else{ //Continua percorrendo a árvore
                    tracer = &(*tracer)->direita;
                }
            }
            else {
                if((*tracer)->esquerda == NULL){
                    (*tracer)->esquerda = newp;
                    break;
                } else{
                    tracer = &(*tracer)->esquerda;
                }
            }
        }

    }
}


void PRINTPREORDEM(Nodo *minhaArvore){
    if (minhaArvore){
        printf("%s, ", minhaArvore->chave);
        PRINTPREORDEM(minhaArvore->esquerda);
        PRINTPREORDEM(minhaArvore->direita);
    }
}

void PRINTORDEM(Nodo *minhaArvore){
    if (minhaArvore){
        PRINTORDEM(minhaArvore->esquerda);
        printf("%s, ", minhaArvore->chave);
        PRINTORDEM(minhaArvore->direita);
    }
}

void PRINTPOSORDEM(Nodo *minhaArvore){
    if (minhaArvore){
        PRINTPOSORDEM(minhaArvore->esquerda);
        PRINTPOSORDEM(minhaArvore->direita);
        printf(" %s, ", minhaArvore->chave);
    }
}

Nodo *SEARCH(Nodo **tracer, char *chave){
    int encontrou = 0;
    while((*tracer)){
        if (strcmp(chave, (*tracer)->chave) == 0){
            encontrou = 1;
            break;
        }
        else{
            if (strcmp(chave, (*tracer)->chave) > 0){
                tracer = &(*tracer)->direita;
            } else{
                tracer = &(*tracer)->esquerda;
            }
        }
    }

    if (encontrou == 1){
        return *tracer;
    } else{
        return NULL;
    }
}


void POP(Nodo **tracer, char chave[]){
    int encontrou = 0, direita = 3;
    Nodo **anterior = tracer;
    Nodo **temp = NULL, **ultimo = NULL;

    while((*tracer)){
        if (strcmp(chave, (*tracer)->chave) == 0){
            encontrou = 1;
            break;
        }
        else{
            if (strcmp(chave, (*tracer)->chave) > 0){
                anterior = tracer;
                tracer = &(*tracer)->direita;
                direita = 1;
            } else{
                anterior = tracer;
                tracer = &(*tracer)->esquerda;
                direita = 0;
            }
        }
    }

    if (encontrou == 1){
        // CASO 1: elemento removido é uma folha
        if ((*tracer)->direita == NULL && (*tracer)->esquerda == NULL){
            free((*tracer)->nome);
            free((*tracer)->telefone);
            free((*tracer)->chave);
            free(*tracer);

            if (direita == 1){
                (*anterior)->direita = NULL;
            } else if (direita == 0){
                (*anterior)->esquerda = NULL;
            } else {
                *tracer = NULL;
            }

        // CASO 2: elemento removido possui apenas um filho a esquerda
        } else if ((*tracer)->direita == NULL && (*tracer)->esquerda != NULL){
            temp = tracer;
            free((*temp)->nome);
            free((*temp)->telefone);
            free((*temp)->chave);
            free(*temp);
            if (direita == 1){
                (*anterior)->direita = (*tracer)->esquerda;
            } else if (direita == 0){
                (*anterior)->esquerda = (*tracer)->esquerda;
            } else {
                *tracer = (*tracer)->esquerda;
            }

        // CASO 3: elemento removido possui apenas um filho a direita
        } else if ((*tracer)->direita != NULL && (*tracer)->esquerda == NULL){
            temp = tracer;
            free((*temp)->nome);
            free((*temp)->telefone);
            free((*temp)->chave);
            free(*temp);
            if (direita == 1){
                (*anterior)->direita = (*tracer)->direita;
            } else if (direita == 0){
                (*anterior)->esquerda = (*tracer)->direita;
            } else {
                *tracer = (*tracer)->direita;
            }

        // CASO 4: elemento removido possui dois filhos
        } else {
            ultimo = &(*tracer)->esquerda;

            while((*ultimo)->direita != NULL){
                anterior = tracer;
                ultimo = &(*ultimo)->direita;
            }
            strcpy((*tracer)->nome, (*ultimo)->nome);
            (*tracer)->idade = (*ultimo)->idade;
            strcpy((*tracer)->telefone, (*ultimo)->telefone);
            strcpy((*tracer)->chave, (*ultimo)->chave);

            strcpy((*ultimo)->chave, chave);
            POP(&(*tracer)->esquerda, chave);
        }
    } else{
       printf("\n\n ERRO, Elemento nao foi encontrado");
    }
}

void CLEAR(Nodo *tracer, Arvore *minhaArvore){
    if (tracer == NULL){
        printf("\nArvore esta vazia");
    } else{
        while (tracer){
            POP (&tracer, tracer->chave);
        }   
        minhaArvore->raiz = NULL;
        printf("\nArvore removida com sucesso");
    }
}
//NOME: Yasmin Souza Camargo

// ARVORE AVL

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
int PUSH(Nodo **tracer, Nodo *newp);
void PRINTPREORDEM(Nodo *minhaArvore);
void PRINTORDEM(Nodo *minhaArvore);
void PRINTPOSORDEM(Nodo *minhaArvore);
Nodo *SEARCH(Nodo **tracer, char *chave);

int FB (Nodo *tracer);
int ALTURA(Nodo *tracer);
void RSE(Nodo **tracer);
void RSD(Nodo **tracer);
void RDD(Nodo **tracer);
void RDE(Nodo **tracer);
int BALANCEAMENTO(Nodo **tracer);
int verficaAVL(Nodo *tracer);

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
            printf("\n\n---> Eh uma arvore AVL? %d", verficaAVL(minhaArvore->raiz));
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

        case 0:
            printf("\n\n Saindo...\n");
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


int PUSH(Nodo **tracer, Nodo *newp){
    if(*tracer == NULL){  //Arvore vazia ou folha
        *tracer = newp;
        return 1;
    }
    printf("\n\n%s, %s = %d", newp->chave, (*tracer)->chave, strcmp(newp->chave, (*tracer)->chave));
    if(strcmp(newp->chave, (*tracer)->chave) < 0){ //Se é menor insere na esquerda
        if (PUSH(&(*tracer)->esquerda, newp) == 1){
            if (BALANCEAMENTO(tracer)){
                return 0;
            } else{
                return 1;
            }
        } else{
            return 0;
        }
        
    } else if (strcmp(newp->chave, (*tracer)->chave) > 0){ //Se é maior insere na direita
        if (PUSH(&(*tracer)->direita, newp) == 1){
            if (BALANCEAMENTO(tracer)){
                return 0;
            } else{
                return 1;
            }
        } else{
            return 0;
        }
    }
    return 0;
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

//  ------------------ AVL ------------------
int FB (Nodo *tracer){
    if (tracer == NULL){
        return 0;
    }
    return ALTURA(tracer->esquerda) - ALTURA(tracer->direita);
}

int ALTURA(Nodo *tracer){
    int iEsq,iDir;
    if (tracer == NULL){
        return 0;
    }
    iEsq = ALTURA(tracer->esquerda);
    iDir = ALTURA(tracer->direita);

    if (iEsq > iDir){
        return iEsq + 1;
    } else{
        return iDir + 1;
    }
}

//Rotação Simples para esquerda
void RSE(Nodo **tracer){
    Nodo *aux;
    
    aux = (*tracer)->direita;
    (*tracer)->direita = aux->esquerda;
    aux->esquerda = *tracer;
    *tracer = aux;
}

//Rotação Simples para direita
void RSD(Nodo **tracer){
    Nodo *aux;
    
    aux = (*tracer)->esquerda;
    (*tracer)->esquerda = aux->direita;
    aux->direita = *tracer;
    *tracer = aux;
}

//Rotação Dupla para direita
void RDD(Nodo **tracer){
    RSE(&(*tracer)->esquerda);
    RSD(tracer);
}

//Rotação Dupla para esquerda
void RDE(Nodo **tracer){
    RSD(&(*tracer)->direita);
    RSE(tracer);
}

//Decide qual balanceamento chamar
int BALANCEAMENTO(Nodo **tracer){
    int fb = 0;
    fb = FB(*tracer);
    if(fb >= 2){
        fb = FB((*tracer)->esquerda);
        if(fb >= 1){
            printf("\nRSD\n");
            RSD(tracer);
            return 1;
        } else if(fb <= -1){
            printf("\nRDD\n");
            RDD(tracer);
            return 1;
        }
    } else if (fb <= -2){
        fb = FB((*tracer)->direita);
        if(fb >= 1){
            printf("\nRDE\n");
            RDE(tracer);
            return 1;
        } else if(fb <= -1){
            printf("\nRSE\n");
            RSE(tracer);
            return 1;
        }
    } else{
        printf("\n A arvore ja esta balanceada");
    }
    return 0;
}

//Verifica se a árvore é AVL
int verficaAVL(Nodo *tracer){
    int fb;

    if (tracer == NULL){
        return 1;
    }
    if (!verficaAVL(tracer->esquerda)){
        return 0;
    }
    if (!verficaAVL(tracer->direita)){
        return 0;
    }
    fb = FB(tracer);
    if ((fb > 1) || (fb < -1)){
        return 0;
    } else{
        return 1;
    }
}

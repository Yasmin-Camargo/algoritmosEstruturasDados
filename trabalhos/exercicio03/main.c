// NOME: Yasmin Souza Camargo
// EXERCÍCIO: Criar uma arvore binaria de busca e depois de digitados todos os dados verificar se é AVL

#include <stdio.h>
#include <stdlib.h>

//Arvore
typedef struct Nodo{
    int numero;
    struct Nodo *esquerda;
    struct Nodo *direita;
}Nodo;

Nodo *raiz = NULL;  //Raiz da arvore

//ESCOPO DE FUNÇÕES
void Reset();
Nodo *NewNodo(int novoNumero);
void Push(Nodo *novoNodo);
void Print(Nodo **tracer);
int FB(Nodo *tracer);
int Altura(Nodo *tracer);
int verficaAVL(Nodo *tracer);
void POP(int chave);
void Clear();

int main()
{
    int numero = 1;

    printf("\n\n ATENCAO! Para sair do programa digite 0 ");
    printf("\n\n------------------------------------------- ");

    Reset(); // inicializa raiz como null

    do{
        printf("\nPor favor, digite um numero: ");
        scanf("%d", &numero);

        if (numero != 0){
            Push(NewNodo(numero)); //chama função para adicionar elemento na árvore
        }
    }
    while (numero != 0);

    //Mostra numeros digitados para o usuario em pre ordem
    printf("\n\nNUMEROS DIGITADOS: \n ");
    Print(&raiz);

    //Chama função para verificar se é AVL
    printf("\n\n\n_____________________________________");
    printf("\n\nA arvore eh balanceada? ");
    if(verficaAVL(raiz) == 1){
        printf("sim");
    } else{
        printf("nao");
    }
    printf("\n_____________________________________\n\n");

    Clear();
    return (0);
}


// ----------------- FUNÇÕES ------------------------

// atribui null na raiz
void Reset(){
    raiz = NULL;
}

// cria um novo nodo e atribui dados
Nodo *NewNodo(int novoNumero){
    Nodo *novoNodo = (Nodo *)(malloc(sizeof(Nodo)));
    if (novoNodo == NULL){
        printf("Erro de alocacao");
        exit (0);
    }
    novoNodo->numero = novoNumero;
    novoNodo->esquerda = NULL;
    novoNodo->direita = NULL;

    return novoNodo;
}

// coloca nodo na arvore
void Push(Nodo *novoNodo){
    Nodo **tracer = &raiz;
    if (raiz == NULL){ //Arvore vazia
        raiz = novoNodo;
    } else{
        while (*tracer){
            if (novoNodo->numero < (*tracer)->numero){  //Insere elemento na esquerda
                if ((*tracer)->esquerda == NULL){
                    (*tracer)->esquerda = novoNodo;
                    break;
                } else{
                    tracer = &(*tracer)->esquerda;
                }
            } else if (novoNodo->numero > (*tracer)->numero){
                if ((*tracer)->direita == NULL){    //Insere elemento na direita
                    (*tracer)->direita = novoNodo;
                    break;
                } else{
                    tracer = &(*tracer)->direita;
                }
            } else{ //Elemento repetido: não adiciona elemento na árvore
                free(novoNodo);
                break;
            }
        }
    }
}

//Mostra arvore em pre ordem
void Print(Nodo **tracer){
    if (*tracer != NULL){
        printf("%d | ", (*tracer)->numero);
        Print(&(*tracer)->esquerda);
        Print(&(*tracer)->direita);
    }
}


// Calcula altura do nodo da arvore
int Altura(Nodo *tracer){
    int alturaEsquerda = 0, alturaDireita = 0;
    
    if (tracer == NULL){
        return 0;
    }

    alturaEsquerda = (Altura(tracer->esquerda));
    alturaDireita = (Altura(tracer->direita));

    if (alturaEsquerda > alturaDireita){
        return (alturaEsquerda + 1);
    } else{
        return (alturaDireita + 1);
    }
}

// Calcula fator de balanceamento
int FB(Nodo *tracer){
    if (tracer == NULL){
        return 0;
    }
    return Altura(tracer->esquerda) - Altura(tracer->direita);
}


// Para verificar se uma arvore é AVL é necessário calcular o fator de balanceamento de todos os nodos 
// se todos nós possuirem fator de balanceamento entre -1 e 1, a arvore é AVL
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

// Função para remover um elemento
void POP(int chave){
    Nodo **tracer = &raiz;
    Nodo *anterior = NULL;  //Salva nodo pai (para depois atualizar os ponteiros)

    int encontrou = 0;  // Indica que o nodo foi encontrado
    int direita = 5;    // Indica a direção de onde veio (-5 código para saber que deve-se atualizar a raiz)

    if (raiz != NULL){
        //Percorre arvore procurando o elemento
        while((*tracer)){
            if (chave == (*tracer)->numero){
                encontrou = 1;
                break;
            }
            else{
                if (chave > (*tracer)->numero){ // Realiza busca na direita
                    if ((*tracer)->direita != NULL) {
                        anterior = *tracer;
                        tracer = &(*tracer)->direita;
                        direita = 1;
                    } else {
                        break; //Elemento não foi encontrado
                    }
                } else{                                 // Realiza busca na esquerda
                    if ((*tracer)->esquerda != NULL) {
                        anterior = *tracer;
                        tracer = &(*tracer)->esquerda;
                        direita = 0;
                    } else {
                        break; //Elemento não foi encontrado
                    }
                }
            }
        }
        
        // Efetua a remoção do nodo de acordo com o caso
        if (encontrou == 1){
            // CASO 1: elemento removido é uma folha
            if ((*tracer)->direita == NULL && (*tracer)->esquerda == NULL){
                free(*tracer);
                if (direita == 1){
                    anterior->direita = NULL;   // o elemento removido estava a direita
                } else if (direita == 0){
                    anterior->esquerda = NULL;  // o elemento removido estava a esquerda
                } else {
                    raiz = NULL;                 // ultimo nodo
                }
            
            // CASO 2: elemento removido possui dois filhos
            } else if ((*tracer)->direita != NULL && (*tracer)->esquerda != NULL){
                // procura na esquerda nodo mais a direita
                Nodo *temp = (*tracer)->esquerda; 
                
                while(temp->direita != NULL){
                    temp = temp->direita;
                }

                // troca os elementos
                (*tracer)->numero = temp->numero;
                temp->numero = chave;

                // remove o nodo pelos outros casos
                POP(chave);

            // CASO 3: elemento removido possui apenas um filho 
            } else {
                Nodo *temp = NULL;  

                // Guarda nodos filhos
                if ((*tracer)->direita != NULL) { 
                    temp = (*tracer)->direita;
                } else {
                    temp = (*tracer)->esquerda;
                } 
                
                free(*tracer);

                if (direita == 1){
                    anterior->direita = temp;
                } else if (direita == 0){
                    anterior->esquerda = temp;
                } else {
                    raiz = temp;
                }
            } 
        }
    }
}

void Clear(){
    Nodo **tracer = &raiz;
    if (*tracer != NULL){
        while (*tracer){
            POP ((*tracer)->numero);
        }   
    }
    raiz = NULL;
}
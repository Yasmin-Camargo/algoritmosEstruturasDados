//NOME: Yasmin Souza Camargo
/*
    --- TRABALHO AGENDA ---
    Nenhuma variável pode ser declarada em todo o programa, somente ponteiros. Todos os dados do programa devem ser guardados dentro do pBuffer.
    Nem mesmo como parâmetro de função. Só ponteiros que apontam para dentro do pBuffer.
    Exemplo do que não pode: int c; char a; int v[10]; void Funcao(int parametro)
    Não pode usar struct em todo o programa.
    Usar fila ordenada (heap) para armazenar as pessoas em ordem alfabética sempre que o usuário incluir uma nova pessoa.
    Implementar a base de dados da agenda usando lista duplamente ligada
    Somente essa base de dados pode ficar fora do buffer principal, ou seja, pode usar um malloc para cada nodo.
*/

//OBSERVAÇOES:
//Utilização da técnica tripleref
//Fila de prioridade por Nome

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Escopo das funções
char *NEWELEMENT(char *nome, int *idade, char *telefone);
void RESET(char *start, char *last, int *numPessoas);
void PUSH(char **tracer, char *newp);
void PRINT(char **tracer);
void SEARCH(char **tracer, char *nome, int *achou);
void POP(char **tracer);
void CLEAR(char **tracer);

//TAMANHOS NA STRUCT
#define IDADE (sizeof(char) * 10 + sizeof(char))
#define TELEFONE (sizeof(char) * 10 + sizeof(char) + sizeof(int))
#define NEXT (sizeof(char) * 10 + sizeof(char) + sizeof(int) + sizeof(char) * 11 + sizeof(char))
#define PREVIOUS (sizeof(char) * 10 + sizeof(char) + sizeof(int) + sizeof(char) * 11 + sizeof(char) + sizeof(char**))

int main()
{
    //Ponteiros
    void *pBuffer = NULL; 
    int *numPessoas = NULL, *op = NULL, *idadeTemp = NULL;
	char *nomeTemp = NULL, *telefoneTemp = NULL, *start = NULL, *last = NULL;

    //Alocando memória
    pBuffer = (void *) (malloc(3 * sizeof(int) + (sizeof(char) * 10 + 1) + (sizeof(char) * 11 + 1))); 
    if (pBuffer == NULL){
        printf("\n\n ERRO de alocacao de memoria!!");
        exit(1);
    }

    //Definindo onde irá apontar cada ponteiro
    op = (int *) (pBuffer);
    numPessoas = (int *) (pBuffer + sizeof(int));
    nomeTemp = (char *) (pBuffer + 2 * sizeof(int));
    idadeTemp = (int *) (pBuffer + 2 * sizeof(int) + sizeof(char) * 10 + sizeof(char));
    telefoneTemp = (char *) (pBuffer + 3 * sizeof(int) + sizeof(char) * 10 + sizeof(char));

    //Inicializando váriaveis
    *op = 1;
    strcpy(nomeTemp," ");
    *idadeTemp = 0;
    strcpy(telefoneTemp," ");

    RESET(start, last, numPessoas);

    while (*op != 0){
        printf ("\n\n ----------------------------");
        printf ("\n          AGENDA            ");
        printf ("\n ----------------------------  ");
        printf ("\n  1) Incluir ");
        printf ("\n  2) Mostrar ");
        printf ("\n  3) Buscar ");
        printf ("\n  4) Apagar ");
        printf ("\n  0) Sair ");
        printf ("\n Escolha uma opcao: ");
        scanf ("%d", op);
        printf ("\n ----------------------------  ");
        switch (*op){
        case 1:
            *numPessoas = *numPessoas + 1;
            //Adicinando dados
            fflush(stdin);
            printf("\n\nAdicione os seguintes dados: ");
            printf("\n Nome: ");
            scanf("%s", nomeTemp);
            printf(" Idade: ");
            scanf("%d", idadeTemp);
            printf(" Telefone: ");
            scanf("%s", telefoneTemp);
            //Verifica se o telefone digitado possui 11 digitos
            if (strlen(telefoneTemp) > 11){
                while (strlen(telefoneTemp) > 11){
                    printf("\n\n ATENCAO \n O telefone e um numero de 11 digitos (51999999999)\nPor favor tente novamente\n");
                    printf(" Telefone: ");
                    scanf("%s", telefoneTemp);
                }
            }
            PUSH(&start, NEWELEMENT(nomeTemp,idadeTemp,telefoneTemp));
            break;

        case 2:
            printf ("\n\nTOTAL DE PESSOAS: %d", *numPessoas);
            printf ("\n______________________________________\n");
            PRINT(&start);
            break;

        case 3: 
            printf("\n Digite o nome que deseja buscar: ");
            scanf("%s", nomeTemp);
            *idadeTemp = 0;
            SEARCH(&start, nomeTemp, idadeTemp);
            break;
        case 4:
            POP(&start);
            *numPessoas = *numPessoas - 1;
            break;
        case 0:
            printf("\n\n Saindo...\n");
            CLEAR(&start);
            free (pBuffer);
			return (0);
            break;
        default:
            printf("\n\n\n OPCAO INVALIDA!!! Por favor, tente novamente\n");
            break;
        }
    }
}

//FUNÇÕES
//---------------------------------------------------------------------------------
void RESET(char *start, char *last, int *numPessoas){
    start = NULL;
    last = NULL;
    *numPessoas = 0;
}

char *NEWELEMENT(char *nome, int *idade, char *telefone) //Cria e coloca elementos no Buffer
{
    void *pBuferPessoa = NULL;
    pBuferPessoa = (void *) (malloc(PREVIOUS + sizeof(char**)));
    if (pBuferPessoa == NULL){
        printf("\n\n ERRO de alocacao de memoria!!");
        exit(1);
    }

    //Adicionando dados
    strcpy((char *)(pBuferPessoa), nome);
    *(int *)(pBuferPessoa + IDADE) = *idade;
    strcpy((char *)(pBuferPessoa + TELEFONE), telefone);
    *(char **)(pBuferPessoa + NEXT) = NULL;
    *(char **)(pBuferPessoa +  PREVIOUS) = NULL;

    return (pBuferPessoa);
}

void PUSH(char **tracer, char *newp){ //Conecta buffer na fila seguindo a ordem de prioridade
    char *temp = *tracer;
    while(((*tracer) != NULL) && strcmp(*tracer, newp) < 1){
        temp = *tracer;
		tracer = (char **)(*tracer + NEXT);
	}
    printf("\n%s", (char **)(newp));
  
    *(char **)(newp + NEXT) = *tracer;
    *tracer = newp;
   
    //Atualizando previous
    tracer = &temp;
    while (*tracer != NULL) {
		temp = *tracer; 
		tracer = (char **)(*tracer + NEXT);
		if (*tracer != NULL) { 
			*(char **)(*tracer + PREVIOUS) = (char *)(temp);
		}
	}
}

void PRINT(char **tracer){
	while (*tracer) {
		printf("\nNOME: %s \n", (char **)(*tracer));
        printf("IDADE: %d \n", *(char **)(*tracer + IDADE));
        printf("TELEFONE: %s \n", (char **)(*tracer + TELEFONE));
		tracer = (char **)(*tracer + NEXT);
	}
}

void SEARCH(char **tracer, char *nome, int *achou){
    *achou = 0;
    while(((*tracer) != NULL)){
        if (strcmp(*tracer, nome) == 0){
            *achou = 1;
            break;
        }
		tracer = (char **)(*tracer + NEXT);
	}

    if (*achou == 1){
        printf("\n\n PALAVRA ENCONTRADA");
        printf ("\n______________________________________\n");
        printf("\nNOME: %s \n", (char **)(*tracer));
        printf("IDADE: %d \n", *(int **)(*tracer + IDADE));
        printf("TELEFONE: %s \n", (char **)(*tracer + TELEFONE));
        tracer = (char **)(*tracer + PREVIOUS);
    }
    else{
        printf("\n\n\n PALAVRA NAO FOI ENCONTRADA!!!");
    }
   
    //printf("\nNOME: %s \n", (char **)(*tracer));
    //printf("IDADE: %d \n", *(char **)(*tracer + IDADE));
    //printf("TELEFONE: %s \n", (char **)(*tracer + TELEFONE));
}

void POP(char **tracer){
    if ((*tracer) != NULL){
        char **head = tracer;
        *tracer = *(char **)(*tracer + NEXT);
        //free(head);
    } else {
        printf ("\n\n Nao existe nenhum elemento para ser removido");
    }   

}

void CLEAR(char **tracer){
    char *temp2, *temp;
	
    temp2 = *tracer;
	while ( temp2 != NULL ) {
		temp = *(char **)( temp2 + NEXT );
		free( temp2 );
		temp2 = temp;
	}
}
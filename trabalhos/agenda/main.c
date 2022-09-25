//NOME: Yasmin Souza Camargo

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Escopo das funções
char *NEWELEMENT(char *nome, int *idade, char *telefone);
void RESET(char *start, char *last, int *numPessoas);
void PUSH(char **tracer, char *newp, int *numPessoas);
void PRINT(char **tracer);
void SEARCH(char **tracer, char *nome, int *achou);
char *POP(char **tracer, char *nomeRemovido, int *numPessoas);
void CLEAR(char **tracer);

char *last = NULL, *start = NULL;

//LOCALIZAÇÃO DOS DADOS NO BUFFER 
#define IDADE (sizeof(char) * 10 + sizeof(char))
#define TELEFONE (sizeof(char) * 10 + sizeof(char) + sizeof(int))
#define NEXT (sizeof(char) * 10 + sizeof(char) + sizeof(int) + sizeof(char) * 11 + sizeof(char))
#define PREVIOUS (sizeof(char) * 10 + sizeof(char) + sizeof(int) + sizeof(char) * 11 + sizeof(char) + sizeof(char**))

int main()
{
    //Ponteiros
    void *pBuffer = NULL; 
    int *numPessoas = NULL, *op = NULL, *idadeTemp = NULL;
	char *nomeTemp = NULL, *telefoneTemp = NULL;

    //Alocando memória
    pBuffer = (void *) (malloc(3 * sizeof(int) + (sizeof(char) * 10 + 1) + (sizeof(char) * 20 + 1))); 
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

    RESET(start, last, numPessoas); //Seta valores

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
            if (strlen((char *) (telefoneTemp)) > 11){
                while (strlen((char *) (telefoneTemp)) > 11){
                    printf("\n\n ATENCAO \n O telefone e um numero de 11 digitos (51999999999)\nPor favor tente novamente\n");
                    printf(" Telefone: ");
                    scanf("%s", telefoneTemp);
                }
            }
            PUSH(&start, NEWELEMENT(nomeTemp, idadeTemp, telefoneTemp), numPessoas); 
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
            printf("\n\n Nome removido: %s", POP(&start, nomeTemp, numPessoas));
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

//Cria o buffer e atribui os dados
char *NEWELEMENT(char *nome, int *idade, char *telefone) 
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

//Conecta buffer na fila seguindo a ordem de prioridade e faz as conexões
void PUSH(char **tracer, char *newp, int *numPessoas){ 
    char *temp = *tracer;  
    *numPessoas = *numPessoas + 1;
    while(((*tracer) != NULL) && strcmp(*tracer, newp) < 1){ //Primeiro verifica se tracer aponta para algum lugar e procura até encontrar o local onde o novo elemento deve ser adicionado
		tracer = (char **)(*tracer + NEXT); //Próximo elemento é o que está no next
	}
  
    //Obs: Nesse momento *tracer pode ser o endereço que start esta apontando ou o endereço que está no next do elemento anterior
    *(char **)(newp + NEXT) = *tracer;  //Atualiza o next do elemento adicionado 
    *tracer = newp; // Atualiza quem já estava na fila antes
    
    //Atualizando previous
    tracer = &temp;
    while (*tracer != NULL) {
		temp = *tracer;  //guarda elemento anterior
		tracer = (char **)(*tracer + NEXT);
		if (*tracer != NULL) { 
			*(char **)(*tracer + PREVIOUS) = (char *)(temp); //previus do elemento posterior aponta para o anterior
		}
	}
    last = (char *)(temp); //atualiza último elemento
}

//Mostra todos elementos da fila
void PRINT(char **tracer){
	while (*tracer) {
		printf("\nNOME: %s \n", (char **)(*tracer));
        printf("IDADE: %d \n", *(char **)(*tracer + IDADE));
        printf("TELEFONE: %s \n", (char **)(*tracer + TELEFONE));
		tracer = (char **)(*tracer + NEXT);
	}
}

//Percorre a fila e procura se existe o elemento
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
}

//Remove elemento do inicio
char *POP(char **tracer, char *nomeRemovido, int *numPessoas){
    char *temp, *temp2;

    temp2 = *tracer; 
    if ((*tracer) != NULL){
        strcpy(nomeRemovido, (char *)(*tracer)); //armazena o nome que vai ser removido
        temp = *(char **)(temp2 + NEXT); //guarda o próximo elemento
		free(temp2); 
        *tracer = temp; //Atualiza tracer (start)
        if ((*tracer == NULL)){ 
            last = NULL; //Atualiza last para NULL quando removeu todos elementos
        }
        else{
            *(char **)(*tracer + PREVIOUS) = NULL; //Atualiza previus quando ainda não removeu todos elementos
        }
        *numPessoas = *numPessoas - 1;
    } else {
        strcpy(nomeRemovido, "-");
        printf ("\n\n Nao existe nenhum elemento para ser removido");
    }
    return(nomeRemovido);
}

//Libera espaço alocado
void CLEAR(char **tracer){
    char *temp2, *temp;
	
    temp2 = *tracer;
	while (temp2 != NULL) {
		temp = *(char **)(temp2 + NEXT); //guarda o próximo elemento
		free(temp2); //libera memória
		temp2 = temp; //atualiza o próximo a ser removido
	}
}
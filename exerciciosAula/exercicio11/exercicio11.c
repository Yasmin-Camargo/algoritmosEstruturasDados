#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//NOME: Yasmin
//Exercício 11 - Lista 10 - Alocação dinâmica
/* Crie um programa que declare uma estrutura (registro) para o cadastro de alunos.
(a) Deverao ser armazenados, para cada aluno: matrıcula, sobrenome (apenas um) e
ano de nascimento.
(b) Ao in´ıcio do programa, o usuario devera informar o numero de alunos que serao
armazenados
(c) O programa devera alocar dinamicamente a quantidade necess ´ aria de mem ´ oria ´
para armazenar os registros dos alunos.
(d) O programa devera pedir ao usu ´ ario que entre com as informac¸ ´ oes dos alunos. ˜
(e) Ao final, mostrar os dados armazenados e liberar a memoria alocada. 
*/

//Struct para armazenar dados do aluno
typedef struct registroAluno{
    int matriculaAluno;
    char sobrenomeAluno[30];
    int anoNascimentoAluno;
}Aluno;

int main (){
    int numAlunos;
    Aluno *novoAluno;

    printf ("Por favor, informe a quantidade de alunos que serao armazenados: ");
    scanf ("%d", &numAlunos);

    //Alocando espaço para os novos alunos
    novoAluno = (Aluno *) malloc(numAlunos * sizeof(Aluno));

    //Lendo dados
    for (int i=0; i<numAlunos;i++){
        printf("\n\nDigite os seguintes dados do aluno %d: ", i+1);
        printf("\n  Matricula: ");
        scanf ("%d", &novoAluno[i].matriculaAluno);
        printf("  Sobrenome: ");
        scanf ("%s", &novoAluno[i].sobrenomeAluno);
        printf("  Ano de nascimento: ");
        scanf ("%d", &novoAluno[i].anoNascimentoAluno);
    }
    printf ("\n\n ---------------------------------------------------------------------\n");
    
    //Mostra os dados armazenados
    for (int i=0; i<numAlunos;i++){
        printf("\n\n ALUNO %d", i+1);
        printf(" |  Matricula: %d", novoAluno[i].matriculaAluno);
        printf(" |  Sobrenome: %s", novoAluno[i].sobrenomeAluno);
        printf(" |  Ano de nascimento: %d", novoAluno[i].anoNascimentoAluno);
    }
    printf("\n\n");
    free (novoAluno); //Libera memória
}


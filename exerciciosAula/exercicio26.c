#include <stdio.h>
#include <string.h>
#include <math.h>

//NOME: Yasmin

//Exercício 26 - Lista 09 - Ponteiros
/* Implemente uma funcao que calcule as raızes de uma equacao do segundo grau do tipo Ax2 + Bx + C = 0
A variavel A tem que ser diferente de zero. 
• Se ∆ < 0 nao existe real. 
• Se ∆ = 0 existe uma raiz real.
• Se ∆ ≥ 0 existem duas ra´ızes reais.
Essa func¸ao deve obedecer ao seguinte prototipo: int raizes(float A,float B,float C,float * X1,float * X2);
Essa funcao deve ter como valor de retorno o nuumero de raızes reais e distintas da
equacao. Se existirem raızes reais, seus valores devem ser armazenados nas variaveis 
apontadas por X1 e X2 */

//Escopo das funções
int raizes (float a, float b, float c, float * x1, float * x2);

int main (){
    float valorA=0.0, valorB=0.0, valorC=0.0, *valorX1, *valorX2;
    int valorRaizes=0;

    //Alocando memoria
    valorX1 = (float*)malloc(sizeof(float)); 
    valorX2 = (float*)malloc(sizeof(float)); 

    //Testa se conseguiu alocar memória
    if (valorX1 == NULL){
        printf("Erro na alocacao de memoria");
        exit (1);
    }
    if (valorX2 == NULL){
        printf("Erro na alocacao de memoria");
        exit (1);
    }

    printf ("\n\nVAMOS CALCULAR A FORMULA DE BHASKARA");
    printf ("\nDigite o valor de a: ");
    scanf ("%f", &valorA);
    printf ("Digite o valor de b: ");
    scanf ("%f", &valorB);
    printf ("Digite o valor de c: ");
    scanf ("%f", &valorC);

    //Verifica valor de A
    if (valorA == 0){
        printf ("O valor de A deve ser diferente de zero");
    }
    else{
        valorRaizes = raizes(valorA, valorB, valorC, valorX1, valorX2);
        if (valorRaizes==1){
            printf ("\n\nRESULTADO:");
            printf ("\n x = %.2f", *valorX1);
        }
        else if (valorRaizes==2){
            printf ("\n\nRESULTADO:");
            printf ("\n x' = %.2f", *valorX1);
            printf ("\n x'' = %.2f", *valorX2);
        }
    }

}

//Função que calcula a Bhaskara
int raizes (float a, float b, float c, float * x1, float * x2){
    float delta=0.0;
    int numRaizes=0;

    printf ("\n\n\nSendo a = %.2f, b = %.2f e c = %.2f\n", a,b,c);

    delta =  (b * b) - (4 * a * c); //Calcula valor do delta
    printf ("\ndelta = %.2f\n", delta);

    if (delta < 0){
        printf("Como delta < 0, Nao existem raiz real");
    }
    else if (delta == 0){
        numRaizes=1;
        printf("Como delta = 0, existe uma raiz real");
        *x1 = (float)(-b) / (2 * a);    //Calcula valor de x
        return (numRaizes);
    }
    else {
        printf("Como delta > 0, existe duas raizes reais");
        numRaizes=2;
        delta = sqrt(delta);
        *x1 = (float)(-b + delta) / (2 * a);   //Calcula valor de x1
        *x2 = (float)(-b - delta) / (2 * a);   //Calcula valor de x2
        return (numRaizes);
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char **nomes, letra, temp[2];
    int linhas=1;

    printf("Digite um letra \n");
    scanf("%c", &letra);

    nomes = (char**)malloc(linhas * sizeof(char *));
    nomes[linhas] = (char*)malloc(sizeof(letra));

    *nomes = letra;
    strcpy(temp, "y");
    
    printf ("\n\nponteiro: %s \ncaracter: %s\n", nomes, temp);

    nomes = (char*)realloc(nomes,sizeof(temp));
    
    strcat(nomes, temp);

    puts(nomes);
    free(nomes);
    
}
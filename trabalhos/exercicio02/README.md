## Trabalho Prático 2
Fazer um programa que testa a sequencia de caracteres fornecidas pelo usuario é um palindromo, ou seja, é uma palavra cuja primeira metade é simétrica a segunda metade.
 
 AABCCBAA - sim

 ADDFDDA - sim

 ABFFBB - não

O usuário digita uma letra e tecla enter, até que digite x e enter para terminar a sequencia
Implemente a função POP e PUSH de pilha e resolva o problema com elas.

### REGRAS DE FORMATAÇÃO:
https://web.stanford.edu/class/cs106b/resources/style_guide.html

### GIT:
https://github.com/Yasmin-Camargo/algoritmosEstruturasDados/tree/main/trabalhos/exercicio02

### Link do vídeo:
https://drive.google.com/file/d/1_GdDuvuA4WnHB8eTuyEIRkorpg7eCIgx/view?usp=
sharing

### PROBLEMAS ENCONTRADOS:
- scanf agora lê apenas um caracter em vez de uma string
- Alterações no pop:
 Código depois do if foi movido para dentro do else, 
 Remoção de uma linha que não fazia nada
- Comparação para descobrir quando as palavras são iguais (quando tamanho
da palavra é par): 
 Em vez de pegar a palavra na struct, ir comparando conforme vai
retirando os elementos com pop: se todos elementos retirados forem
iguais a palavra é um palíndromo
- Finalização do caso quando a palavra tem tamanho ímpar
- Nova função “TestaPalindromo” para reaproveitamento de código
- O free foi passado para dentro de uma nova função chamada CLEAR
- Tratando palavras maiúsculas e minúsculas iguais
- Variável sequência que antes era um vetor, agora foi passada para dinâmica


### LISTA DE TESTES
Palavras que são palíndromos: AABCCBAA, ADDFDDA, reviver

Palavras que NÃO são palíndromos: ABFFBB, yasmin, AED

# algoritmosEstruturasDados
Algoritmos desenvolvidos durante as aulas do cuso de Algoritmos e Estruturas de dados I do curso de Ciência da Computação da UFPel

## Identificação
Nome do Aluno: Yasmin Souza Camargo

E-mail para contato: yasmin.sc@inf.ufpel.edu.br

## Estilo de Formatação:
https://web.stanford.edu/class/cs106b/resources/style_guide.html 

## Entregas
### exerciciosAula
#### exercicio13
Exercicio 13 da lista 11 de arquivos: Faca um programa que permita que o usuario entre com diversos nomes e telefone para cadastro, e crie um arquivo com essas informacoes, uma por linha. O usuario finaliza a entrada com ‘0’ para o telefone

#### exercicio03
Exercicio 03 da lista 10 de alocação dinâmica: Faca um programa que leia do usuario o tamanho de um vetor a ser lido e faca a alocacao dinamica de memoria. Em seguida, leia do usuario seus valores e mostre quantos dos numeros sao pares e quantos sao ımpares

#### exercicio04
Exercício 4 da Lista 10 de Alocação dinâmica: Faca um programa que receba do usuario o tamanho de uma string e chame uma função para alocar dinamicamente essa string. Em seguida, o usuario dever a informar o conteudo dessa string. O programa imprime a string sem suas vogais

#### exercicio11
Exercício 11 da Lista 10 de Alocação dinâmica: Crie um programa que declare uma estrutura (registro) para o cadastro de alunos.
(a) Deverao ser armazenados, para cada aluno: matrıcula, sobrenome (apenas um) e
ano de nascimento.
(b) Ao inıcio do programa, o usuario devera informar o numero de alunos que serao
armazenados
(c) O programa devera alocar dinamicamente a quantidade necessaria de memoria
para armazenar os registros dos alunos.
(d) O programa devera pedir ao usuario que entre com as informacoes dos alunos. 
(e) Ao final, mostrar os dados armazenados e liberar a memoria alocada. 

#### exercicio26
Exercício 26 da Lista 09 de Ponteiros: Implemente uma funcao que calcule as raızes de uma equacao do segundo grau do tipo Ax2 + Bx + C = 0.
Essa funcao deve obedecer ao seguinte prototipo: 
int raizes(float A,float B,float C,float * X1,float * X2);
Essa funcao deve ter como valor de retorno o nuumero de raızes reais e distintas da
equacao. Se existirem raızes reais, seus valores devem ser armazenados nas variaveis 
apontadas por X1 e X2

### lista01
#### exercicio01
Criar um projeto "Olá Mundo" em C no Visual Code e usando o debug com um breakpoint no printf

#### exercicio02
Faça um programa que armazena nomes. O programa deve armazenar
todos os nomes na mesma string. O tamanho da string deve crescer e diminuir
conforme nomes forem colocados ou removidos. Não pode ter desperdício de memória.

### lista02
#### exercicio03
Faça uma agenda capaz de incluir, apagar, buscar e listar quantas pessoas o usuário desejar, porém, toda a informação incluída na agenda deve ficar num único lugar chamado: “void *pBuffer”.
- Não pergunte para o usuário quantas pessoas ele vai incluir.
- Não pode alocar espaço para mais pessoas do que o necessário.
- Cada pessoa tem nome[10], idade e telefone.

### lista03
#### exercicio05
Faça um programa que armazene a informação de várias pessoas.
O programa só deve sair quando o usuário disser que não deseja mais entrar com os dados de outra pessoa.
Antes de sair o programa deve apresentar, de forma organizada, os dados de todas as pessoas

#### exercicio07
Inverso do exercício 03 da lista 02
O programa deve armazenar no máximo 10 pessoas
Todas as variáveis que forem usadas no programa deve ser ponteiros. A única exceção é o item 1 que deve ser uma variável global Pessoa pessoas[10].
Os ponteiros devem apontar para um buffer chamado pBuffer onde os dados devem
ser armazenados. Por exemplo, um contador para um for deve ser um ponteiro para
int e o int vai ficar armazenado dentro de pBuffer
Não pode usar struct dentro do pBuffer

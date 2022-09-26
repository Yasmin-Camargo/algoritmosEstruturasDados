## Trabalho Prático 01
Faça um programa que solicita do usuário uma série de números, cada número pode ser um
int, float ou double. Antes de solicitar o número pergunte qual tipo de dado o usuário vai entrar. Todos os números entrados devem ser armazenados num buffer único. Esse buffer deve ter tamanho dinâmico e não deve desperdiçar memória, por exemplo, alocar sempre espaço para um double quando o usuário inserir um int ou float. Você não deve solicitar para o usuário quantos números ele deseja entrar, na escolha do tipo de dados coloque uma opção para parar a entrada da série de números. Após isso você deve imprimir todos os números do buffer, primeiro toda a série em sequência depois novamente, mas primeiro os ints seguido dos floats e doubles

### REGRAS DE FORMATAÇÃO:
https://web.stanford.edu/class/cs106b/resources/style_guide.html

### GIT:
https://github.com/Yasmin-Camargo/algoritmosEstruturasDados/tree/main/trabalhos/exercicio01

### Link do vídeo:
https://drive.google.com/file/d/1frfpzKXoxYxQLEmBLBvA79lt9i2S3rxp/view?usp=sharing

### PROBLEMAS ENCONTRADOS:
1. Inicializando os ponteiros com EOF em vez de NULL

2. %f no scanf para double em vez de %lf

3. A alocação para a string não foi realizada

4. Acrescentei mais testes

5. Remoção das variáveis globais

6. Removi os printf que estava utilizando para testes

7. Ausência do Casting nos ponteiros int, float e double

8. Terminar exercício: imprimir ints seguido dos floats e doubles

9. Aplicação das regras do estilo de formatação

### LISTA DE TESTES
-  Sequência de 10 valores só do tipo Int
-  Sequência de 10 valores só do tipo Float
-  Sequência de 10 valores só do tipo Double
-  Sequência de valores com vários tipos (5 inteiro, 6 float, 4 double)
## Trabalho Prático 4
Dado um vetor nums contendo n número inteiros positivos e únicos encontre o número
faltante na sequência. Assuma que somente um número está faltando para completar a
sequência numérica.

Exemplo 1:
Entrada: nums = [3, 0, 1]; 
Saída: 2; 
Explicação: n = 3 já que existem 3 números, então todos os números estão no intervalo
[0,3]. 2 é o número ausente no intervalo, pois não aparece em nums.

Exemplo 2:
Entrada: nums = [0, 1]; 
Saída: 2; 
Explicação: n = 2 já que existem 2 números, então todos os números estão no intervalo
[0,2]. 2 é o número ausente no intervalo, pois não aparece em nums.

Exemplo 3:
Entrada: nums = [9,6,4,2,3,5,7,0,1]
Saída: 8
Explicação: n = 9 já que existem 9 números, então todos os números estão no intervalo
[0,9]. 8 é o número ausente no intervalo, pois não aparece em nums.


A complexidade da resposta não pode ser superior a O(nlogn)
Dica, existe uma solução O(n)

### REGRAS DE FORMATAÇÃO:
https://web.stanford.edu/class/cs106b/resources/style_guide.html

### GIT:
https://github.com/Yasmin-Camargo/algoritmosEstruturasDados/tree/main/trabalhos/exercicio04

### Link do vídeo:
https://drive.google.com/file/d/1bnPxx0AzyYrbN4pL-egIGoFFny77KuaD/view?usp=sharing  

### PROBLEMAS ENCONTRADOS:
- No momento de passar o tamanho do vetor diminuir - 1
- Na função "NumeroFaltante" retorna como padrão o último número
- Adicionada a função free
- Vetor auxiliar inicializando, agora, na posição zero

### LISTA DE TESTES
- 3, 0, 1 										(saída: 2)
- 0, 1										(saída: 2)
- 9,6,4,2,3,5,7,0,1								(saída: 8)
- 20, 19, 18, 1, 2, 3, 0, 4, 15, 16, 5, 11, 6, 12, 7, 13, 9, 8, 13, 14, 17		(saída: 10)




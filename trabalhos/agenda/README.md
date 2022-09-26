## Trabalho Agenda
Faça uma agenda capaz de incluir, apagar, buscar e listar quantas pessoas o usuário desejar.
- Não pergunte para o usuário quantas pessoas ele vai incluir.
- Não pode alocar espaço para mais pessoas do que o necessário.
- Nenhuma variável pode ser declarada em todo o programa, somente ponteiros. Todos os dados do programa devem ser guardados dentro do pBuffer.
    Nem mesmo como parâmetro de função. Só ponteiros que apontam para dentro do pBuffer.
    Exemplo do que não pode: int c; char a; int v[10]; void Funcao(int parametro)
- Não pode usar struct em todo o programa.
- Usar fila ordenada (heap) para armazenar as pessoas em ordem alfabética sempre que o usuário incluir uma nova pessoa.
- Implementar a base de dados da agenda usando lista duplamente ligada. 
    Somente essa base de dados pode ficar fora do buffer principal, ou seja, pode usar um malloc para cada nodo.

### REGRAS DE FORMATAÇÃO: 
https://web.stanford.edu/class/cs106b/resources/style_guide.html  

### Link do GIT: 
https://github.com/Yasmin-Camargo/algoritmosEstruturasDados/tree/main/trabalhos/agenda 

### Link do vídeo: 
https://drive.google.com/file/d/1sVDNOQReo6TttVQqRUau5RQoeEKOGZeo/view?usp=sharing

### Observações
- Utilização da técnica tripleref
- Fila de prioridade por Nome

### Lista de testes
https://github.com/Yasmin-Camargo/algoritmosEstruturasDados/tree/main/trabalhos/agenda/testes
1) Adiciona 10 pessoas, lista, remove 4 pessoas, lista, busca uma pessoa que existe, busca outra que não existe, encerra;
2) Adiciona 3 pessoas, lista, busca as tres, busca uma que não existe, remove todas, busca uma que existia, encerra
3) Lista, adiciona 5 pessoas, lista, remove todas, remove mais uma, lista, busca, adiciona mais duas, lista, busca, encerra

### Resultados do teste Dr Memory
https://github.com/Yasmin-Camargo/algoritmosEstruturasDados/tree/main/trabalhos/agenda/resultados-DRMemory

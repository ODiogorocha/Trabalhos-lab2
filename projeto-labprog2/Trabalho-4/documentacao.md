
# **Documentação - Sistema de Restaurante (Tarefa 4)**

## **Objetivo**
O objetivo deste trabalho foi criar um sistema de gerenciamento de restaurante utilizando estruturas de dados dinâmicas (filas, pilhas e matrizes). O sistema permite gerenciar mesas, grupos de clientes, uma fila de espera, e uma pilha de pratos, além de diversas operações que um restaurante normalmente teria.

---

## **Estruturas de Dados Utilizadas**

### **Mesa**
A estrutura `Mesa` representa uma mesa do restaurante. Cada mesa possui:
- `numeroMesa`: Identificador único da mesa.
- `ocupada`: Um valor booleano que indica se a mesa está ocupada (`true`) ou livre (`false`).
- `numPessoas`: Número de pessoas ocupando a mesa, caso esteja ocupada.
- `comanda`: O número da comanda associada à mesa.

### **Grupo**
A estrutura `Grupo` representa um grupo de clientes na fila de espera:
- `senha`: Um número único atribuído ao grupo, utilizado para identificá-los na fila de espera.
- `numPessoas`: Número de pessoas no grupo.

### **Fila**
A estrutura `Fila` representa a fila de espera para mesas, contendo:
- `grupos`: Um vetor dinâmico de grupos aguardando mesas.
- `inicio`, `fim`: Índices que indicam as posições de início e fim da fila.
- `tamanho`: Número atual de grupos na fila.
- `capacidade`: Capacidade máxima da fila.

### **Pilha**
A estrutura `Pilha` representa a pilha de pratos, armazenando:
- `pratos`: Um vetor dinâmico que contém os pratos na pilha.
- `topo`: Índice do topo da pilha (onde o próximo prato será retirado).
- `capacidade`: Capacidade máxima da pilha.

---

## **Funções**

### **1. `inicializarMesas(int linhas, int colunas)`**
Esta função cria e inicializa a matriz de mesas no restaurante. A quantidade de mesas é determinada pelos parâmetros `linhas` e `colunas`, representando o número de linhas e colunas na matriz de mesas. A função retorna um ponteiro para a matriz de mesas alocada dinamicamente.

- **Parâmetros**:
  - `linhas`: Número de linhas da matriz de mesas.
  - `colunas`: Número de colunas da matriz de mesas.

- **Retorno**:
  - Retorna um ponteiro para a matriz de mesas alocada dinamicamente.

### **2. `liberarMesa(Mesa *mesa)`**
Esta função libera uma mesa, tornando-a "livre" para outros grupos. A mesa, após ser liberada, tem seu campo `ocupada` definido como `false`, o número de pessoas como `0`, e a comanda como `-1`.

- **Parâmetros**:
  - `mesa`: Ponteiro para a mesa que será liberada.

### **3. `imprimirMesas(Mesa **mesas, int linhas, int colunas)`**
Esta função imprime o estado de todas as mesas do restaurante, mostrando o número da mesa, se ela está ocupada ou livre, o número de pessoas sentadas e o número da comanda.

- **Parâmetros**:
  - `mesas`: Matriz de mesas alocada dinamicamente.
  - `linhas`: Número de linhas da matriz de mesas.
  - `colunas`: Número de colunas da matriz de mesas.

### **4. `inicializarFila(int capacidade)`**
Esta função inicializa uma fila de espera, criando uma estrutura de fila com capacidade para armazenar até `capacidade` grupos de clientes. Ela aloca dinamicamente os dados necessários para a fila.

- **Parâmetros**:
  - `capacidade`: Capacidade máxima da fila de espera.

- **Retorno**:
  - Retorna um ponteiro para a fila de espera alocada dinamicamente.

### **5. `adicionarGrupo(Fila *fila, int numPessoas)`**
Esta função adiciona um grupo à fila de espera. Ela cria um novo grupo com uma senha única e o número de pessoas informado e adiciona esse grupo à fila.

- **Parâmetros**:
  - `fila`: Ponteiro para a fila de espera.
  - `numPessoas`: Número de pessoas no grupo que está sendo adicionado à fila.

### **6. `removerGrupo(Fila *fila)`**
Esta função remove o grupo que está na posição mais antiga da fila (o primeiro grupo a chegar) e retorna o grupo removido.

- **Parâmetros**:
  - `fila`: Ponteiro para a fila de espera.

- **Retorno**:
  - Retorna o grupo removido da fila.

### **7. `imprimirFila(Fila *fila)`**
Esta função imprime o estado atual da fila de espera, mostrando o número de grupos na fila e a quantidade total de pessoas aguardando.

- **Parâmetros**:
  - `fila`: Ponteiro para a fila de espera.

### **8. `inicializarPilha(int capacidade)`**
Esta função inicializa uma pilha de pratos. Ela cria uma pilha com a capacidade especificada, inicialmente vazia, pronta para ser usada.

- **Parâmetros**:
  - `capacidade`: Capacidade máxima da pilha de pratos.

- **Retorno**:
  - Retorna um ponteiro para a pilha de pratos alocada dinamicamente.

### **9. `empilhar(Pilha *pilha, int pratos)`**
Esta função adiciona uma quantidade de pratos à pilha. Os pratos são empilhados no topo da pilha.

- **Parâmetros**:
  - `pilha`: Ponteiro para a pilha de pratos.
  - `pratos`: Número de pratos a ser adicionado à pilha.

### **10. `desempilhar(Pilha *pilha)`**
Esta função remove e retorna o número de pratos do topo da pilha. Caso a pilha esteja vazia, ela retorna `-1`.

- **Parâmetros**:
  - `pilha`: Ponteiro para a pilha de pratos.

- **Retorno**:
  - Retorna o número de pratos desempilhados. Caso a pilha esteja vazia, retorna `-1`.

### **11. `imprimirPilha(Pilha *pilha)`**
Esta função imprime o número de pratos presentes na pilha.

- **Parâmetros**:
  - `pilha`: Ponteiro para a pilha de pratos.

---

## **Funcionamento do Sistema**

O sistema é baseado em um **menu interativo** que permite ao usuário realizar as seguintes operações:

1. **Abrir restaurante**: Inicializa as mesas do restaurante com o número de linhas e colunas fornecido.
2. **Chegar (grupo de clientes)**: Adiciona um novo grupo de clientes à fila de espera ou ocupa mesas se houver disponibilidade.
3. **Finalizar refeição/liberar mesa**: Libera uma mesa quando os clientes terminam a refeição, e chama grupos da fila de espera para ocupar as mesas liberadas.
4. **Desistir de esperar**: Permite que um grupo desista de aguardar por uma mesa, removendo-o da fila de espera.
5. **Repor pratos**: Adiciona pratos à pilha de pratos.
6. **Imprimir pilha de pratos, fila de espera e ocupação das mesas**: Exibe o estado atual da pilha de pratos, da fila de espera e da ocupação das mesas.

---

## **Conclusão**

Este sistema simula as operações básicas de um restaurante, com a utilização de filas e pilhas para gerenciar a ordem de atendimento dos clientes e o controle de pratos. A implementação em C faz uso de alocação dinâmica de memória, funções modulares e manipulação de estruturas de dados fundamentais.

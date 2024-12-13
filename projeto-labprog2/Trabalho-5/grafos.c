#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// __INT_MAX__ é uma constante definida na biblioteca <limits.h> que representa o maior valor que um tipo int pode armazenar.
// É usado nos algoritmos de caminho mínimo para indicar que uma distância é "infinita",
// ou seja, que um nó ainda não foi alcançado ou que a distância entre dois nós não foi calculada.


// Estrutura para representar uma aresta
typedef struct Aresta {
    int indice_destino;
    int peso_aresta;
    struct Aresta* proxima_aresta;
} Aresta;

// Estrutura para representar um nó no grafo
typedef struct No {
    Aresta* lista_arestas;
} No;

// Estrutura para representar o grafo
typedef struct Grafo {
    int quantidade_nos;
    No* lista_nos;
} Grafo;

// Função para criar um grafo
Grafo* criar_grafo(int quantidade_nos) {
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo->quantidade_nos = quantidade_nos;
    grafo->lista_nos = (No*)malloc(quantidade_nos * sizeof(No));
    for (int indice = 0; indice < quantidade_nos; indice++) {
        grafo->lista_nos[indice].lista_arestas = NULL;
    }
    return grafo;
}

// Função para adicionar uma aresta ao grafo
void adicionar_aresta(Grafo* grafo, int indice_origem, int indice_destino, int peso_aresta) {
    Aresta* nova_aresta = (Aresta*)malloc(sizeof(Aresta));
    nova_aresta->indice_destino = indice_destino;
    nova_aresta->peso_aresta = peso_aresta;
    nova_aresta->proxima_aresta = grafo->lista_nos[indice_origem].lista_arestas;
    grafo->lista_nos[indice_origem].lista_arestas = nova_aresta;
}

// Função para executar o algoritmo de Dijkstra
void algoritmo_dijkstra(Grafo* grafo, int indice_no_inicial) {
    int quantidade_nos = grafo->quantidade_nos;
    int* vetor_distancia = (int*)malloc(quantidade_nos * sizeof(int));
    int* vetor_visitados = (int*)calloc(quantidade_nos, sizeof(int));

    for (int indice = 0; indice < quantidade_nos; indice++) {
        vetor_distancia[indice] = __INT_MAX__;
    }
    vetor_distancia[indice_no_inicial] = 0;

    for (int passo = 0; passo < quantidade_nos - 1; passo++) {
        int menor_distancia = __INT_MAX__, indice_atual = -1;

        for (int indice = 0; indice < quantidade_nos; indice++) {
            if (!vetor_visitados[indice] && vetor_distancia[indice] <= menor_distancia) {
                menor_distancia = vetor_distancia[indice];
                indice_atual = indice;
            }
        }

        if (indice_atual == -1) break;
        vetor_visitados[indice_atual] = 1;

        Aresta* aresta_atual = grafo->lista_nos[indice_atual].lista_arestas;
        while (aresta_atual != NULL) {
            int indice_destino = aresta_atual->indice_destino;
            int peso_aresta = aresta_atual->peso_aresta;

            if (!vetor_visitados[indice_destino] && vetor_distancia[indice_atual] != __INT_MAX__ && vetor_distancia[indice_atual] + peso_aresta < vetor_distancia[indice_destino]) {
                vetor_distancia[indice_destino] = vetor_distancia[indice_atual] + peso_aresta;
            }
            aresta_atual = aresta_atual->proxima_aresta;
        }
    }

    for (int indice = 0; indice < quantidade_nos; indice++) {
        printf("Distância do nó %d ao nó %d: %d\n", indice_no_inicial, indice, vetor_distancia[indice]);
    }

    free(vetor_distancia);
    free(vetor_visitados);
}

// Função para executar o algoritmo de Bellman-Ford
void algoritmo_bellman_ford(Grafo* grafo, int indice_no_inicial) {
    int quantidade_nos = grafo->quantidade_nos;
    int* vetor_distancia = (int*)malloc(quantidade_nos * sizeof(int));

    for (int indice = 0; indice < quantidade_nos; indice++) {
        vetor_distancia[indice] = __INT_MAX__;
    }
    vetor_distancia[indice_no_inicial] = 0;

    for (int passo = 0; passo < quantidade_nos - 1; passo++) {
        for (int indice_origem = 0; indice_origem < quantidade_nos; indice_origem++) {
            Aresta* aresta_atual = grafo->lista_nos[indice_origem].lista_arestas;
            while (aresta_atual != NULL) {
                int indice_destino = aresta_atual->indice_destino;
                int peso_aresta = aresta_atual->peso_aresta;
                if (vetor_distancia[indice_origem] != __INT_MAX__ && vetor_distancia[indice_origem] + peso_aresta < vetor_distancia[indice_destino]) {
                    vetor_distancia[indice_destino] = vetor_distancia[indice_origem] + peso_aresta;
                }
                aresta_atual = aresta_atual->proxima_aresta;
            }
        }
    }

    for (int indice_origem = 0; indice_origem < quantidade_nos; indice_origem++) {
        Aresta* aresta_atual = grafo->lista_nos[indice_origem].lista_arestas;
        while (aresta_atual != NULL) {
            int indice_destino = aresta_atual->indice_destino;
            int peso_aresta = aresta_atual->peso_aresta;
            if (vetor_distancia[indice_origem] != __INT_MAX__ && vetor_distancia[indice_origem] + peso_aresta < vetor_distancia[indice_destino]) {
                printf("Ciclo negativo detectado!\n");
                free(vetor_distancia);
                return;
            }
            aresta_atual = aresta_atual->proxima_aresta;
        }
    }

    for (int indice = 0; indice < quantidade_nos; indice++) {
        printf("Distância do nó %d ao nó %d: %d\n", indice_no_inicial, indice, vetor_distancia[indice]);
    }

    free(vetor_distancia);
}

// Função principal
int main() {
    int quantidade_nos = 10;
    Grafo* grafo = criar_grafo(quantidade_nos);

    adicionar_aresta(grafo, 0, 1, 10);
    adicionar_aresta(grafo, 0, 2, 15);
    adicionar_aresta(grafo, 1, 3, 12);
    adicionar_aresta(grafo, 2, 5, 10);
    adicionar_aresta(grafo, 3, 4, 2);
    adicionar_aresta(grafo, 4, 5, 1);
    adicionar_aresta(grafo, 5, 6, 5);
    adicionar_aresta(grafo, 6, 7, 3);
    adicionar_aresta(grafo, 7, 8, 8);
    adicionar_aresta(grafo, 8, 9, 6);
    adicionar_aresta(grafo, 9, 0, 7);
    adicionar_aresta(grafo, 0, 3, 25);
    adicionar_aresta(grafo, 1, 4, 20);
    adicionar_aresta(grafo, 2, 6, 18);
    adicionar_aresta(grafo, 3, 7, 16);
    adicionar_aresta(grafo, 4, 8, 14);
    adicionar_aresta(grafo, 5, 9, 12);
    adicionar_aresta(grafo, 6, 0, 10);
    adicionar_aresta(grafo, 7, 1, 8);
    adicionar_aresta(grafo, 8, 2, 6);
    adicionar_aresta(grafo, 9, 3, 4);


    printf("Resultado do Algoritmo de Dijkstra:\n");
    algoritmo_dijkstra(grafo, 0);

    printf("\nResultado do Algoritmo de Bellman-Ford:\n");
    algoritmo_bellman_ford(grafo, 0);

    // Liberação de memória
    for (int indice = 0; indice < quantidade_nos; indice++) {
        Aresta* aresta_atual = grafo->lista_nos[indice].lista_arestas;
        while (aresta_atual != NULL) {
            Aresta* aresta_temp = aresta_atual;
            aresta_atual = aresta_atual->proxima_aresta;
            free(aresta_temp);
        }
    }
    free(grafo->lista_nos);
    free(grafo);

    return 0;
}

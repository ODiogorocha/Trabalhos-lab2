#ifndef PILHA_H
#define PILHA_H

typedef struct {
    int *pratos;
    int topo;
    int capacidade;
}Pilha;

Pilha* inicia_pilha(int capacidade);
void empilhar(Pilha *pilha, int pratos);
int desempilhar(Pilha *pilha);
void imprimir_pilha(Pilha *pilha);

#endif
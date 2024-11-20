#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha* inicia_pilha(int capacidade){
    Pilha *pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->pratos = (int*)malloc(capacidade * sizeof(int));
    pilha->topo = -1;
    pilha->capacidade= capacidade;
    return pilha;
}

void empilhar(Pilha *pilha, int pratos) {
    if (pilha->topo == pilha->capacidade - 1) {
        printf("Pilha cheai!\n");
        return;
    }
    pilha->pratos[++pilha->topo] = pratos;
}

int desempilhar(Pilha *pilha) {
    if (pilha->topo == -1){
        printf("Pilha vazia!\n");
        return -1;
    }
    return pilha->pratos[pilha->topo--];
}

void imprimir_pilha(Pilha *pilha) {
    printf("Pilha de pratos: %d pratos \n", pilha->topo + 1);
}

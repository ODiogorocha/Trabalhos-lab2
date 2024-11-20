#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila* inicia_fila(int capacidade) {
    Fila *fila = (Fila*)malloc(sizeof(Fila));
    fila->grupos = (Grupo*)malloc(capacidade * sizeof(Grupo));
    fila->inicio = 0;
    fila->fim = 0;
    fila->tamanho = 0;
    fila->capacidade = capacidade;
    return fila;
}

void adicionar_grupo(Fila *fila, int numero_pessoas){
    if (fila->tamanho == fila->capacidade) {
        printf("Fila cheia!\n");
        return;
    }
    Grupo novo_Grupo = { .senha = fila->fim + 1, .numero_pessoas = numero_pessoas};
    fila->grupos[fila->fim] = novo_Grupo;
    fila->fim = (fila->fim + 1) % fila->capacidade;
    fila->tamanho++;
}

Grupo remover_grupo(Fila *fila) {
    if (fila->tamanho == 0) {
        printf("Fila vazia! \n");
        return (Grupo) { .senha = -1, .numero_pessoas = 0};
    }
    Grupo grupo = fila->grupos[fila->inicio];
    fila->inicio = (fila->inicio + 1) % fila->capacidade;
    fila->tamanho--;
    return grupo;
}

void imprimir_fila(Fila *fila) {
    printf("Fila de espera:\n");
    for (int i = 0; i < fila->tamanho; i++) {
        int index = (fila->inicio + 1) % fila->capacidade;
        printf("Grupo %d: %d pessoas\n", fila->grupos[index].senha, fila->grupos[index].numero_pessoas);
    }
}
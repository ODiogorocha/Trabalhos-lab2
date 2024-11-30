#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pilha.h"

// Função para inicializar a pilha
Pilha* inicializar_pilha() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    if (pilha == NULL) {
        printf("Erro ao alocar memória para a pilha de pratos.\n");
        exit(1);
    }
    pilha->topo = NULL;
    pilha->tamanho = 0;
    return pilha;
}

// Função para empilhar um prato
void empilhar_prato(Pilha* pilha, int prato_id) {
    NoPilha* novo = (NoPilha*)malloc(sizeof(NoPilha));
    if (novo == NULL) {
        printf("Erro ao alocar memória para o nó da pilha.\n");
        exit(1);
    }
    novo->prato_id = prato_id;
    novo->proximo = pilha->topo;
    pilha->topo = novo;
    pilha->tamanho++;
}

// Função para desempilhar um prato
int desempilhar_prato(Pilha* pilha) {
    if (pilha->topo == NULL) {
        printf("Pilha de pratos vazia.\n");
        return -1; // Código de erro
    }

    NoPilha* temp = pilha->topo;
    int prato_id = temp->prato_id;
    pilha->topo = temp->proximo;
    free(temp);
    pilha->tamanho--;
    return prato_id;
}

// Função para verificar se a pilha está vazia
bool pilha_vazia(Pilha* pilha) {
    return pilha->topo == NULL;
}

// Função para imprimir o estado da pilha
void imprimir_pilha(Pilha* pilha) {
    NoPilha* atual = pilha->topo;
    printf("Pilha de pratos (topo para base):\n");
    while (atual != NULL) {
        printf("Prato ID: %d\n", atual->prato_id);
        atual = atual->proximo;
    }
    printf("Total de pratos na pilha: %d\n", pilha->tamanho);
}

// Função para liberar a memória da pilha
void destruir_pilha(Pilha* pilha) {
    while (!pilha_vazia(pilha)) {
        desempilhar_prato(pilha);
    }
    free(pilha);
}

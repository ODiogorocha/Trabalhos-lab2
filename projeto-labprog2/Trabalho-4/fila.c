#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fila.h"

// Função para inicializar a fila
Fila* inicializar_fila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    if (fila == NULL) {
        printf("Erro ao alocar memória para a fila de grupos.\n");
        exit(1);
    }
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
    return fila;
}

// Função para enfileirar um grupo
void enfileirar_grupo(Fila* fila, int senha, int quantidade_pessoas) {
    Grupo* novo = (Grupo*)malloc(sizeof(Grupo));
    if (novo == NULL) {
        printf("Erro ao alocar memória para o grupo na fila.\n");
        exit(1);
    }
    novo->senha = senha;
    novo->quantidade_pessoas = quantidade_pessoas;
    novo->proximo = NULL;

    if (fila->fim != NULL) {
        fila->fim->proximo = novo;
    }
    fila->fim = novo;

    if (fila->inicio == NULL) {
        fila->inicio = novo;
    }
    fila->tamanho++;
}

// Função para desenfileirar um grupo
Grupo* desenfileirar_grupo(Fila* fila) {
    if (fila_vazia(fila)) {
        printf("Fila de espera vazia.\n");
        return NULL;
    }

    Grupo* removido = fila->inicio;
    fila->inicio = removido->proximo;
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }
    fila->tamanho--;
    return removido;
}

// Função para verificar se a fila está vazia
bool fila_vazia(Fila* fila) {
    return fila->inicio == NULL;
}

// Função para imprimir o estado da fila
void imprimir_fila(Fila* fila) {
    Grupo* atual = fila->inicio;
    printf("Fila de espera (senha e quantidade de pessoas):\n");
    while (atual != NULL) {
        printf("Senha: %d, Pessoas: %d\n", atual->senha, atual->quantidade_pessoas);
        atual = atual->proximo;
    }
    printf("Total de grupos na fila: %d\n", fila->tamanho);
}

// Função para liberar a memória da fila
void destruir_fila(Fila* fila) {
    while (!fila_vazia(fila)) {
        Grupo* temp = desenfileirar_grupo(fila);
        free(temp);
    }
    free(fila);
}

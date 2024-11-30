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

// Função para verificar e separar 4 pessoas do grupo, alocando em uma mesa
void alocar_grupo_em_mesa(Fila* fila) {
    if (fila_vazia(fila)) {
        printf("Fila de espera vazia. Nenhum grupo para alocar.\n");
        return;
    }

    Grupo* atual = fila->inicio;
    while (atual != NULL) {
        if (atual->quantidade_pessoas > 4) {
            // Se o grupo tiver mais de 4 pessoas, aloca 4 pessoas em uma mesa
            printf("Grupo com senha %d tem mais de 4 pessoas. Alocando 4 pessoas em uma mesa.\n", atual->senha);
            atual->quantidade_pessoas -= 4;
            // O grupo com mais de 4 pessoas permanece na fila com a quantidade reduzida
            return;
        }
        atual = atual->proximo;
    }
    printf("Nenhum grupo com mais de 4 pessoas encontrado.\n");
}

// Função para remover um grupo da fila com base na senha
void sair_da_fila(Fila* fila, int senha) {
    if (fila_vazia(fila)) {
        printf("Fila de espera vazia. Nenhum grupo para remover.\n");
        return;
    }

    Grupo* atual = fila->inicio;
    Grupo* anterior = NULL;

    while (atual != NULL) {
        if (atual->senha == senha) {
            // Encontrou o grupo com a senha correspondente
            if (anterior == NULL) {
                // O grupo a ser removido é o primeiro da fila
                fila->inicio = atual->proximo;
                if (fila->inicio == NULL) {
                    fila->fim = NULL;
                }
            } else {
                // O grupo a ser removido está no meio ou no final da fila
                anterior->proximo = atual->proximo;
                if (atual == fila->fim) {
                    fila->fim = anterior;
                }
            }
            fila->tamanho--;
            free(atual);
            printf("Grupo com senha %d removido da fila.\n", senha);
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    printf("Grupo com senha %d não encontrado na fila.\n", senha);
}

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

// Função para iniciar uma fila vazia
Fila* inicia_fila() {
    return NULL; 
}

// Função para adicionar um grupo na fila
void adicionar_grupo(Fila **inicio, int numero_pessoas) {

    // Cria um novo nó da fila
    Fila *novo = (Fila *)malloc(sizeof(Fila));
    if (!novo) {
        printf("Erro ao alocar memória para o novo grupo.\n");
        exit(1);
    }

    novo->grupo.numero_pessoas = numero_pessoas;
    novo->proximo = NULL;

    // Insere o novo nó no final da fila
    if (*inicio == NULL) {
        *inicio = novo; 
    } else {
        Fila *temp = *inicio;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novo;
    }
}

// Função para remover o primeiro grupo da fila
Grupo remover_grupo(Fila **inicio) {
    if (*inicio == NULL) {
        printf("Fila vazia!\n");
        return (Grupo){.numero_pessoas = 0};
    }

    Fila *temp = *inicio;
    Grupo grupo_removido = temp->grupo;
    *inicio = temp->proximo; 
    free(temp); 
    return grupo_removido;
}

// Função para imprimir os grupos na fila
void imprimir_fila(Fila *inicio) {
    if (inicio == NULL) {
        printf("Fila está vazia.\n");
        return;
    }

    printf("Fila de espera:\n");
    Fila *temp = inicio;
    while (temp != NULL) {
        printf("Grupo %d: %d pessoas\n",temp->grupo.numero_pessoas);
        temp = temp->proximo;
    }
}

// Função para destruir a fila e liberar memória
void destruir_fila(Fila **inicio) {
    while (*inicio != NULL) {
        Fila *temp = *inicio;
        *inicio = (*inicio)->proximo;
        free(temp);
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fila.h"

// Função para iniciar uma fila vazia
Fila* inicia_fila() {
    return NULL; 
}

// Função para adicionar um grupo na fila
void enfileirar_grupo(Fila **inicio, int senha, int numero_pessoas) {

    // Cria um novo nó da fila
    Fila *novo = (Fila *)malloc(sizeof(Fila));
    if (!novo) {
        printf("Erro ao alocar memória para o novo grupo.\n");
        exit(1);
    }

    novo->grupo.numero_pessoas = numero_pessoas;
    novo->grupo.senha = senha;
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
Grupo* remover_grupo(Fila **inicio) {
    if (*inicio == NULL) {
        printf("Fila vazia!\n");
        return NULL;
    }

    Fila *temp = *inicio;
    Grupo* grupo_removido = (Grupo*)malloc(sizeof(Grupo));
    if (temp->grupo.numero_pessoas > 4) {
        grupo_removido->numero_pessoas = 4;
        grupo_removido->senha = temp->grupo.senha;
        temp->grupo.numero_pessoas -= 4;
    } else {
        *inicio = temp->proximo;
        *grupo_removido = temp->grupo;
        free(temp);
    }
    return grupo_removido;
}

bool fila_vazia(Fila* filaEspera) {
    if (filaEspera == NULL) {
        return true;
    }
    return false;
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
        printf("Grupo %d: %d pessoas\n",temp->grupo.senha, temp->grupo.numero_pessoas);
        temp = temp->proximo;
    }
}

void desistir(Fila** filaEspera, int senha) {
    
    Fila* temp = *filaEspera;
    Fila* anterior = NULL;

    while (temp != NULL) {
        if (temp->grupo.senha == senha) {
            if (anterior == NULL) {  // O nó a remover é o primeiro
                *filaEspera = temp->proximo;
            } else {
                anterior->proximo = temp->proximo;
            }
            free(temp);
            printf("Grupo com senha %d saiu da fila.\n", senha);
            return;
        }
        anterior = temp;
        temp = temp->proximo;
    }

    printf("Grupo com senha %d não encontrado na fila.\n", senha);
}

// Função para destruir a fila e liberar memória
void destruir_fila(Fila **inicio) {
    while (*inicio != NULL) {
        Fila *temp = *inicio;
        *inicio = (*inicio)->proximo;
        free(temp);
    }
}

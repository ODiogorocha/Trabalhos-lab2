#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha* inicia_pilha(){
    return NULL;
}

void empilhar(Pilha **pilha, int quantidade) {
    
    for(int i = 0; i < quantidade; i++) {
        Pilha *novo = (Pilha*)malloc(sizeof(Pilha));
        if (novo == NULL) {
            printf("Erro ao alocar memória para a pilha.\n");
            return;
        }
        novo->prato.prato_limpo = true;
        novo->prox = *pilha;
        *pilha = novo;
    }

}

void desempilhar(Pilha **pilha, int quantidade) {
    if (pilha == NULL) {
        printf ("Pilha de pratos: 0 pratos \n");
        return;
    }

    for(int i = 0; i < quantidade && pilha != NULL; i++) {
        Pilha *temp = *pilha;
        *pilha = temp->prox;

        free(temp);
    }

}

void imprimir_pilha(Pilha *pilha) {
    if (pilha == NULL) {
        printf ("Pilha de pratos: 0 pratos \n");
        return;
    }
    int num_pratos = 0;
    Pilha *temp = pilha;
    while (temp != NULL) {
        num_pratos++;
        temp = temp->prox; // Acesso seguro
    }
    printf("Pilha de pratos: %d pratos \n", num_pratos);
}


void destruir_pilha(Pilha **inicio) {
    while (*inicio != NULL) {
        Pilha *temp = *inicio;
        *inicio = (*inicio)->prox;
        free(temp);
    }
}

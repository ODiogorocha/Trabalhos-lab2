#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h>

// Estrutura para representar um prato na pilha
typedef struct NoPilha {
    int prato_id;
    struct NoPilha* proximo;
} NoPilha;

typedef struct {
    NoPilha* topo;
    int tamanho;
} Pilha;

// Funções para gerenciamento da pilha
Pilha* inicializar_pilha();
void empilhar_prato(Pilha* pilha, int prato_id);
int desempilhar_prato(Pilha* pilha);
bool pilha_vazia(Pilha* pilha);
void imprimir_pilha(Pilha* pilha);
void destruir_pilha(Pilha* pilha);

#endif 
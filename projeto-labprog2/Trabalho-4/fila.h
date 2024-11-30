#ifndef FILA_H
#define FILA_H

#include <stdbool.h>

// Estrutura para representar um grupo na fila
typedef struct Grupo {
    int senha;
    int quantidade_pessoas;
    struct Grupo* proximo;
} Grupo;

typedef struct {
    Grupo* inicio;
    Grupo* fim;
    int tamanho;
} Fila;

// Funções para gerenciamento da fila
Fila* inicializar_fila();
void enfileirar_grupo(Fila* fila, int senha, int quantidade_pessoas);
Grupo* desenfileirar_grupo(Fila* fila);
bool fila_vazia(Fila* fila);
void imprimir_fila(Fila* fila);
void destruir_fila(Fila* fila);

#endif 

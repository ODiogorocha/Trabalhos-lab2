#ifndef FILA_H
#define FILA_H

typedef struct {
    int senha;
    int numero_pessoas;
} Grupo;

typedef struct Fila {
    Grupo grupo;
    struct Fila *inicio;
    struct Fila *proximo;
} Fila;

Fila* inicia_fila();
void adicionar_grupo(Fila **inicio, int numero_pessoas);
Grupo remover_grupo(Fila **inicio);
void imprimir_fila(Fila *inicio);
void destruir_fila(Fila **inicio);

#endif

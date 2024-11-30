#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#include <stdbool.h>

// Estrutura para representar uma mesa
typedef struct {
    int numero_mesa;
    bool ocupada;
    int numero_pessoas;
    int numero_pratos;
    int comanda;
} Mesa;

// Funções para gerenciamento de mesas
Mesa** inicializar_mesa(int linhas, int colunas);
void liberar_mesa(Mesa* mesa);
void imprimir_mesas(Mesa** mesas, int linhas, int colunas);
void destruir_mesas(Mesa** mesas, int linhas);

#endif 
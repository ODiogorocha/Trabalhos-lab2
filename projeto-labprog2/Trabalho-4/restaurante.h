#ifndef RESTAURANTE_H
#define RESTAURANTE_H
#include <stdbool.h>
#include "fila.h"
#include "pilha.h"

typedef struct{
    int numero_mesa;
    bool ocupada;
    int numero_pessoas;
    int numero_pratos;
    int comanda;
}Mesa;

Mesa** inicializar_mesa(int linhas, int colunas);
void liberar_mesa(Mesa **mesa, int numeroMesa, int numLinhas, int numColunas, Pilha** pratos);
void imprimir_mesas(Mesa **mesas, int linhas, int colunas);
void preencheMesa(Mesa **mesas, Fila **filaEspera, int linhas, int colunas, Pilha **pilhaPratos);

#endif

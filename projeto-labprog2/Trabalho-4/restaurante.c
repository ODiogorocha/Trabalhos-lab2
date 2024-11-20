#include <stdio.h>
#include <stdlib.h>
#include "restaurante.h"

Mesa** inicializar_mesa(int linhas, int colunas){
    Mesa **mesas = (Mesa**)malloc(linhas * sizeof(Mesa*));
    
    for (int i = 0; i < linhas; i++) {
        mesas[i] = (Mesa**)malloc(linhas * sizeof(Mesa*));
        for (int j = 0; j < colunas; j++) {
            mesas[i][j].numero_mesa = i * colunas + j + 1;
            mesas[i][j].ocupada = false;
            mesas[i][j].numero_pessoas = 0;
            mesas[i][j].comanda = -1;
        }
    }
    return false;
}

void liberar_mesa(Mesa *mesa) {
    mesa->ocupada = false;
    mesa->numero_pessoas = 0;
    mesa->comanda = -1;
}

void imprimir_mesa(Mesa **mesas, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Mesa %d: %s, %d pessoas, comanda %d\n",
            mesas[i][j].numero_mesa,
            mesas[i][j].ocupada ? "Ocupada" : "Livre",
            mesas[i][j].numero_pessoas,
            mesas[i][j].comanda);
        }
    }
}
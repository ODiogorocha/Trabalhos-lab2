#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "restaurante.h"

// Função para inicializar a matriz de mesas
Mesa** inicializar_mesa(int linhas, int colunas) {
    Mesa** mesas = (Mesa**)malloc(linhas * sizeof(Mesa*));
    if (mesas == NULL) {
        printf("Erro ao alocar memória para as mesas.\n");
        exit(1);
    }

    for (int i = 0; i < linhas; i++) {
        mesas[i] = (Mesa*)malloc(colunas * sizeof(Mesa));
        if (mesas[i] == NULL) {
            printf("Erro ao alocar memória para a linha %d das mesas.\n", i);
            exit(1);
        }
        for (int j = 0; j < colunas; j++) {
            mesas[i][j].numero_mesa = i * colunas + j + 1;
            mesas[i][j].ocupada = false;
            mesas[i][j].numero_pessoas = 0;
            mesas[i][j].numero_pratos = 4;
            mesas[i][j].comanda = 0;
        }
    }
    return mesas;
}

// Função para liberar uma única mesa
void liberar_mesa(Mesa* mesa) {
    mesa->ocupada = false;
    mesa->numero_pessoas = 0;
    mesa->numero_pratos = 4;
    mesa->comanda = 0;
}

// Função para imprimir o status de todas as mesas
void imprimir_mesas(Mesa** mesas, int linhas, int colunas) {
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

// Função para liberar a memória alocada para as mesas
void destruir_mesas(Mesa** mesas, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(mesas[i]);
    }
    free(mesas);
}

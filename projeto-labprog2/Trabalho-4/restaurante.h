#ifndef RESTAURANTE_H
#define RESTAURANTE_H
#include <stdbool.h>

typedef struct{
    int numero_mesa;
    bool ocupada;
    int numero_pessoas;
    int comanda;
}Mesa;

Mesa** inicializar_mesa(int linhas, int colunas);
void liberar_mesa(Mesa *mesa);
void imrimir_mesas(Mesa **mesas, int linhas, int colunas);

#endif
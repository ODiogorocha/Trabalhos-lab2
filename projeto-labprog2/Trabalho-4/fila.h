#ifndef FILA_H
#define FILA_H

typedef struct {
    int senha;
    int numero_pessoas;
}Grupo;

typedef struct {
    Grupo *grupos;
    //sei que poderia ir tudo em uma unica linha mas acho que fica visualmente melhor separado
    int inicio;
    int fim;
    int tamanho;
    int capacidade;
}Fila;

Fila inicia_fila(int capacidade);
void adiconar_grupo(Fila *fila, int numero_pessoas);
Grupo remover_grupo(Fila *fila);
void imprimir_fila(Fila *fila);

#endif
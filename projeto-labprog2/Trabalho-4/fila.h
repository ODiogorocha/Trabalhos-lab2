#ifndef FILA_H
#define FILA_H

typedef struct grupo Grupo;
typedef struct fila Fila;

struct grupo {
    int senha;
    int numero_pessoas;
};

struct fila {
    Grupo grupo;
    Fila *inicio;
    Fila *proximo;
};

Fila* inicia_fila();
void enfileirar_grupo(Fila **inicio, int senha, int numero_pessoas);
Grupo* remover_grupo(Fila **inicio);
void imprimir_fila(Fila *inicio);
void destruir_fila(Fila **inicio);
bool fila_vazia(Fila* filaEspera);
void desistir(Fila** filaEspera, int senha);


#endif

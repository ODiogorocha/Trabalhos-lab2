#ifndef PILHA_H
#define PILHA_H
#include <stdbool.h>

typedef struct pratos Pratos;
typedef struct pilha Pilha;

struct pratos {
    bool prato_limpo;
};


struct pilha {
    Pratos prato;
    Pilha *prox;
};

Pilha* inicia_pilha();
void empilhar(Pilha **pilha, int quantidade);
void desempilhar(Pilha **pilha, int quantidade);
void imprimir_pilha(Pilha *pilha);
void destruir_pilha(Pilha **inicio);

#endif

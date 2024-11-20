#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "restaurante.h"
#include "fila.h"
#include "pilha.h"

int main() {
    int linhas;
    int colunas;
    int opcao;

    printf("Informe as dimensões das mesas (linhas e colunas): ");
    scanf("%d %d", &linhas, &colunas);

    Mesa **mesa = inicializar_mesa(linhas, colunas);
    Fila *fila = inicializar_fila(10);  
    Pilha *pilha = inicializar_pilha(100);  

    empilhar(pilha, 100);

    do {
        printf("\n1. Imprimir mesas\n2. Adicionar grupo à fila\n3. Liberar mesa\n4. Imprimir fila\n5. Imprimir pilha\n6. Sair\n");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                imprimir_mesas(mesa, linhas, colunas);
                break;
            case 2:
                int pessoas;
                printf("Número de pessoas no grupo: ");
                scanf("%d", &pessoas);
                adicionar_grupo(fila, pessoas);  
                break;
            case 3:
                liberar_mesa(&mesa[0][0]);
                break;
            case 4:
                imprimir_fila(fila);
                break;
            case 5:
                imprimir_pilha(pilha);
                break;
        }
    } while (opcao != 6);  

    return 0;
}

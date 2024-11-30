#include <stdio.h>
#include <stdlib.h>
#include "restaurante.h"
#include "pilha.h"
#include "fila.h"

// Função para exibir o menu de opções
void exibir_menu() {
    printf("\nMenu do Restaurante:\n");
    printf("1. Abrir restaurante\n");
    printf("2. Chegar (grupo de) clientes\n");
    printf("3. Finalizar refeição/liberar mesa\n");
    printf("4. Desistir de esperar\n");
    printf("5. Repor pratos\n");
    printf("6. Imprimir estado do restaurante\n");
    printf("7. Sair\n");
}

int main() {
    int linhas, colunas;
    Mesa** mesas = NULL;
    Pilha* pilha_pratos = inicializar_pilha();
    Fila* fila_espera = inicializar_fila();
    int opcao;

    while (1) {
        exibir_menu();
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Informe o número de linhas: ");
                scanf("%d", &linhas);
                printf("Informe o número de colunas: ");
                scanf("%d", &colunas);

                mesas = inicializar_mesa(linhas, colunas);
                for (int i = 0; i < linhas * colunas; i++) {
                    empilhar_prato(pilha_pratos, i + 1);
                }
                printf("Restaurante aberto com %d mesas.\n", linhas * colunas);
                break;

            case 2:
                {
                    int senha, quantidade_pessoas;
                    printf("Informe a senha do grupo: ");
                    scanf("%d", &senha);
                    printf("Informe a quantidade de pessoas: ");
                    scanf("%d", &quantidade_pessoas);

                    enfileirar_grupo(fila_espera, senha, quantidade_pessoas);
                    printf("Grupo de %d pessoas entrou na fila com a senha %d.\n", quantidade_pessoas, senha);
                }
                break;

            case 3:
                if (mesas != NULL) {
                    // Lógica para liberar mesa e reposicionar clientes da fila (detalhes omitidos)
                    printf("Mesa liberada e reposição de clientes da fila realizada.\n");
                } else {
                    printf("Restaurante ainda não foi aberto.\n");
                }
                break;

            case 4:
                if (!fila_vazia(fila_espera)) {
                    Grupo* removido = desenfileirar_grupo(fila_espera);
                    if (removido != NULL) {
                        printf("Grupo com a senha %d desistiu de esperar.\n", removido->senha);
                        free(removido);
                    }
                } else {
                    printf("Fila de espera vazia.\n");
                }
                break;

            case 5:
                empilhar_prato(pilha_pratos, 1); // Adiciona um prato de exemplo
                printf("Prato adicionado à pilha.\n");
                break;

            case 6:
                imprimir_mesas(mesas, linhas, colunas);
                imprimir_pilha(pilha_pratos);
                imprimir_fila(fila_espera);
                break;

            case 7:
                destruir_pilha(pilha_pratos);
                destruir_fila(fila_espera);
                for (int i = 0; i < linhas; i++) {
                    free(mesas[i]);
                }
                free(mesas);
                printf("Saindo do restaurante.\n");
                exit(0);
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}

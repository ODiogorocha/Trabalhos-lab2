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

void menu(Mesa*** mesas, Pilha** pilha_pratos, Fila** fila_espera, int opcao, int* linhas, int* colunas){
    int senha;
    switch (opcao) {
        case 1:
            if (*mesas == NULL){
                printf("Informe o número de linhas: ");
                scanf("%d", linhas);
                printf("Informe o número de colunas: ");
                scanf("%d", colunas);
                *mesas = inicializar_mesa(*linhas, *colunas);
                printf("Restaurante aberto com %d mesas, distribuidas em uma matrix %dx%d.\n", *linhas * *colunas, *linhas, *colunas);
                imprimir_mesas(*mesas, *linhas, *colunas);
            } else {printf("O restaurante já foi aberto");}            
            break;

        case 2:
            
            int quantidade_pessoas;
            printf("Informe a senha do grupo: ");
            scanf("%d", &senha);
            printf("Informe a quantidade de pessoas: ");
            scanf("%d", &quantidade_pessoas);
            enfileirar_grupo(fila_espera, senha, quantidade_pessoas);
            printf("Grupo de %d pessoas entrou na fila com a senha %d.\n", quantidade_pessoas, senha);
            
            break;

        case 3:
            imprimir_mesas(*mesas, *linhas, *colunas);
            if (mesas != NULL) {
                int numeroMesa;
                printf("Informe o número da mesa a ser liberada: ");
                scanf("%d", &numeroMesa);
                liberar_mesa(*mesas, numeroMesa, *linhas, *colunas, pilha_pratos);
            } else {
                printf("Restaurante ainda não foi aberto.\n");
            }
            break;

        case 4:
            imprimir_fila(*fila_espera);
            printf("qual a senha do grupo que quer desistir.\n");
            scanf("%d", &senha);

            if (fila_vazia(*fila_espera)) {
                printf("Fila de espera vazia.\n");
            } else {
                desistir(fila_espera, senha);
            }
            break;

        case 5:
            empilhar(pilha_pratos, 1); // Adiciona um prato de exemplo
            printf("Prato adicionado à pilha.\n");
            break;

        case 6:
            imprimir_mesas(*mesas, *linhas, *colunas);
            imprimir_pilha(*pilha_pratos);
            imprimir_fila(*fila_espera);
            break;

        case 7:
            destruir_pilha(pilha_pratos);
            destruir_fila(fila_espera);
            for (int i = 0; i < *linhas; i++) {
                free((*mesas)[i]);
            }
            free(*mesas);
            printf("Saindo do restaurante.\n");
            exit(0);
            break;


        default:
            printf("Opção inválida. Tente novamente.\n");
    }

}

int main() {
    int linhas, colunas;
    Mesa** mesas = NULL;
    Pilha* pilha_pratos = inicia_pilha();
    Fila* fila_espera = inicia_fila();
    int opcao;

    while (1) {
        exibir_menu();
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        menu(&mesas, &pilha_pratos, &fila_espera, opcao, &linhas, &colunas);
        preencheMesa(mesas, &fila_espera, linhas, colunas, &pilha_pratos);
    }

    return 0;
}

#include <stdio.h>
#include "main.h"

int main() {
    Aluno *listaAlunos = NULL;
    Projeto *listaProjetos = NULL;
    Professor *listaProfessores = NULL;
    Vinculo *listaVinculos = NULL;
    
    int opcao;

    do {
        exibirMenu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        processarOpcao(opcao, &listaAlunos, &listaProjetos, &listaProfessores, &listaVinculos);
    } while (opcao != 9);

    return 0;
}

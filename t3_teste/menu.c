#include <stdio.h>  // Necessário para printf e scanf
#include "menu.h"
#include "lista.h"

void menu(int opcao, Alunos** lista_alunos, Professores** lista_professores, Projetos** lista_projetos) {
    switch (opcao) {
        case 1:
            *lista_alunos = insere_aluno(*lista_alunos);
            break;
        case 2:
            *lista_professores = insere_professor(*lista_professores);
            break;
        case 3:
            *lista_projetos = insere_projeto(*lista_projetos, *lista_professores);
            break;
        case 4:
            excluir_aluno(lista_alunos);
            break;
        case 5:
            excluir_professor(lista_professores);
            break;
        case 6:
            excluir_projeto(lista_projetos);
            break;
        case 7:
            criar_vinculo(*lista_alunos, *lista_projetos);
            break;
        case 8:
            excluir_vinculo(*lista_projetos);
            break;
        case 9:
            //relatorio_final(*lista_alunos, *lista_professores, *lista_projetos);  // Esta função deve ser declarada ou definida
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida!\n");
    }
}

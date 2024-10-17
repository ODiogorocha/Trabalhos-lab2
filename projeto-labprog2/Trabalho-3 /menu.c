#include "menu.h"
#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void texto_menu() {
    printf("Digite:\n");
    printf("1 caso queira cadastrar um aluno e listar os alunos cadastrados;\n");
    printf("2 caso queira cadastrar um professor e listar os professores cadastrados;\n");
    printf("3 caso queira cadastrar um projeto e listar os projetos cadastrados;\n");
    printf("4 caso queira excluir um aluno cadastrado e listar os alunos cadastrados;\n");
    printf("5 caso queira excluir um professor cadastrado e listar os professores cadastrados;\n");
    printf("6 caso queira excluir um projeto cadastrado e listar os projetos cadastrados cadastrados;\n");
    printf("7 caso queira mostrar todos os professores, alunos e projetos que estão cadastrados;\n");
    printf("8 caso queira vincular um aluno a um projeto;\n");
    printf("9 caso queira excluir um vinculo;\n");
    printf("0 caso queira sair do programa de registro e vinculos.\n");
}

void menu(int opcao) {
    
    texto_menu();

    switch (opcao)
    {
    case 1:
        /* code */
        break;
    case 2:

        break;
    case 3:

        break;
    case 4:

        break;
    case 5:

        break;
    
    case 6:
        
        break;
    case 7:

        break;
    case 8:

        break;
    case 9:

        break;
    case 0:
        printf("Um arquivo txt sera criado para salvar todos os registros.\n");
        break;
    default:
        printf("Opição não existente, tente novamente.\n");
        break;
    }

}

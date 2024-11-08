#include "lista.h"
#include "menu.h"
#include <stdio.h>

int main() {
    Alunos* lista_alunos = cria_lista_alunos();
    Professores* lista_professores = cria_lista_professores();
    Projetos* lista_projetos = cria_lista_projetos();

    int opcao;
    do {
        printf("Escolha uma opção:\n");
        printf("1. Inserir aluno\n2. Inserir professor\n3. Inserir projeto\n");
        printf("4. Excluir aluno\n5. Excluir professor\n6. Excluir projeto\n");
        printf("7. Criar vínculo\n8. Excluir vínculo\n9. Relatório\n0. Sair\n");
        scanf("%d", &opcao);

        menu(opcao, &lista_alunos, &lista_professores, &lista_projetos);

    } while(opcao != 0);

    return 0;
}

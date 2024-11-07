#include <stdio.h>
#include "menu.h"
#include "lista.h"

void exibirMenu() {
    printf("1. Cadastrar Aluno\n");
    printf("2. Listar Alunos\n");
    printf("3. Cadastrar Projeto\n");
    printf("4. Listar Projetos\n");
    printf("5. Cadastrar Professor\n");
    printf("6. Listar Professores\n");
    printf("7. Vincular Aluno a Projeto\n");
    printf("8. Listar Vinculos\n");
    printf("9. Sair\n");
}

void processarOpcao(int opcao, Aluno **listaAlunos, Projeto **listaProjetos, Professor **listaProfessores, Vinculo **listaVinculos) {
    int matricula, codigo, projetoCodigo;
    float bolsa;
    char nome[100], telefone[15], descricao[200], tipo[20], departamento[100];

    switch (opcao) {
        case 1:
            printf("Matricula: ");
            scanf("%d", &matricula);
            printf("Nome: ");
            scanf(" %[^\n]", nome);
            printf("Telefone: ");
            scanf("%s", telefone);
            cadastrarAluno(listaAlunos, matricula, nome, telefone);
            break;
        case 2:
            listarAlunos(*listaAlunos);
            break;
        case 3:
            printf("Codigo: ");
            scanf("%d", &codigo);
            printf("Descricao: ");
            scanf(" %[^\n]", descricao);
            printf("Tipo (ensino/pesquisa/extensao): ");
            scanf("%s", tipo);
            printf("Orcamento aprovado: ");
            scanf("%f", &bolsa);
            cadastrarProjeto(listaProjetos, codigo, descricao, tipo, bolsa);
            break;
        case 4:
            listarProjetos(*listaProjetos);
            break;
        case 5:
            printf("Codigo: ");
            scanf("%d", &codigo);
            printf("Nome: ");
            scanf(" %[^\n]", nome);
            printf("Departamento: ");
            scanf(" %[^\n]", departamento);
            cadastrarProfessor(listaProfessores, codigo, nome, departamento);
            break;
        case 6:
            listarProfessores(*listaProfessores);
            break;
        case 7:
            printf("Matricula do aluno: ");
            scanf("%d", &matricula);
            printf("Codigo do projeto: ");
            scanf("%d", &projetoCodigo);
            printf("Bolsa mensal: ");
            scanf("%f", &bolsa);
            break;
        case 8:
            listarVinculos(*listaVinculos);
            break;
        case 9:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida!\n");
            break;
    }
}

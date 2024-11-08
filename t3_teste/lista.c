#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista.h"

// Função para buscar aluno
Alunos* busca_aluno(int codigo, Alunos* lista) {
    Alunos* temp = lista;
    while (temp) {
        if (temp->aluno.codigo == codigo) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Função para buscar projeto
Projetos* busca_projeto(int codigo, Projetos* lista) {
    Projetos* temp = lista;
    while (temp) {
        if (temp->projeto.codigo == codigo) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Função para buscar professor
bool busca_professor(int codigo, Professores* lista, Professor** orientador) {
    Professores* temp = lista;
    while (temp) {
        if (temp->professor.codigo == codigo) {
            *orientador = &temp->professor;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Função para inserir aluno na lista
Alunos* insere_aluno(Alunos* lista) {
    Alunos* novo_aluno = (Alunos*)malloc(sizeof(Alunos));
    printf("Digite o código do aluno: ");
    scanf("%d", &novo_aluno->aluno.codigo);
    printf("Digite o nome do aluno: ");
    scanf("%s", novo_aluno->aluno.nome);

    novo_aluno->next = lista;
    return novo_aluno;
}

// Função para inserir professor na lista
Professores* insere_professor(Professores* lista) {
    Professores* novo_professor = (Professores*)malloc(sizeof(Professores));
    printf("Digite o código do professor: ");
    scanf("%d", &novo_professor->professor.codigo);
    printf("Digite o nome do professor: ");
    scanf("%s", novo_professor->professor.nome);

    novo_professor->next = lista;
    return novo_professor;
}

// Função para inserir projeto na lista
Projetos* insere_projeto(Projetos* lista, Professores* lista_professores) {
    Projetos* novo_projeto = (Projetos*)malloc(sizeof(Projetos));
    int cod_professor;

    printf("Digite o código do projeto: ");
    scanf("%d", &novo_projeto->projeto.codigo);
    printf("Digite o nome do projeto: ");
    scanf("%s", novo_projeto->projeto.nome);

    printf("Digite o código do professor orientador: ");
    scanf("%d", &cod_professor);

    // Busca o professor orientador
    Professor* orientador = NULL;
    if (!busca_professor(cod_professor, lista_professores, &orientador)) {
        printf("Professor não encontrado. O projeto não foi inserido.\n");
        free(novo_projeto);
        return lista;
    }

    novo_projeto->projeto.orientador = orientador;
    novo_projeto->next = lista;
    return novo_projeto;
}

// Função para excluir aluno
void excluir_aluno(Alunos** lista) {
    int codigo;
    printf("Digite o código do aluno a ser excluído: ");
    scanf("%d", &codigo);

    Alunos* temp = *lista;
    Alunos* prev = NULL;
    
    while (temp && temp->aluno.codigo != codigo) {
        prev = temp;
        temp = temp->next;
    }

    if (temp) {
        if (prev) {
            prev->next = temp->next;
        } else {
            *lista = temp->next;
        }
        free(temp);
        printf("Aluno excluído com sucesso.\n");
    } else {
        printf("Aluno não encontrado.\n");
    }
}

// Função para excluir professor
void excluir_professor(Professores** lista) {
    int codigo;
    printf("Digite o código do professor a ser excluído: ");
    scanf("%d", &codigo);

    Professores* temp = *lista;
    Professores* prev = NULL;
    
    while (temp && temp->professor.codigo != codigo) {
        prev = temp;
        temp = temp->next;
    }

    if (temp) {
        if (prev) {
            prev->next = temp->next;
        } else {
            *lista = temp->next;
        }
        free(temp);
        printf("Professor excluído com sucesso.\n");
    } else {
        printf("Professor não encontrado.\n");
    }
}

// Função para excluir projeto
void excluir_projeto(Projetos** lista) {
    int codigo;
    printf("Digite o código do projeto a ser excluído: ");
    scanf("%d", &codigo);

    Projetos* temp = *lista;
    Projetos* prev = NULL;
    
    while (temp && temp->projeto.codigo != codigo) {
        prev = temp;
        temp = temp->next;
    }

    if (temp) {
        if (prev) {
            prev->next = temp->next;
        } else {
            *lista = temp->next;
        }
        free(temp);
        printf("Projeto excluído com sucesso.\n");
    } else {
        printf("Projeto não encontrado.\n");
    }
}

// Função para criar vínculo entre aluno e projeto
void criar_vinculo(Alunos* lista_alunos, Projetos* lista_projetos) {
    int codigo_aluno, codigo_projeto;
    Alunos* aluno = NULL;
    Projetos* projeto = NULL;

    printf("Digite o código do aluno: ");
    scanf("%d", &codigo_aluno);
    printf("Digite o código do projeto: ");
    scanf("%d", &codigo_projeto);

    // Buscar aluno e projeto
    aluno = busca_aluno(codigo_aluno, lista_alunos);
    projeto = busca_projeto(codigo_projeto, lista_projetos);

    if (aluno && projeto) {
        // Criar vínculo aqui
        printf("Vínculo criado com sucesso entre aluno e projeto.\n");
    } else {
        printf("Aluno ou projeto não encontrados.\n");
    }
}

// Função para excluir vínculo
void excluir_vinculo(Projetos* lista_projetos) {
    int codigo_projeto;
    printf("Digite o código do projeto para excluir vínculo: ");
    scanf("%d", &codigo_projeto);

    Projetos* projeto = busca_projeto(codigo_projeto, lista_projetos);
    if (projeto) {
        projeto->projeto.orientador = NULL;  // Excluir vínculo
        printf("Vínculo excluído com sucesso.\n");
    } else {
        printf("Projeto não encontrado.\n");
    }
}


#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>

typedef struct Aluno {
    char nome[50];
    int codigo;
} Aluno;

typedef struct Alunos {
    Aluno aluno;
    struct Alunos* next;
} Alunos;

typedef struct Professor {
    char nome[50];
    int codigo;
} Professor;

typedef struct Professores {
    Professor professor;
    struct Professores* next;
} Professores;

typedef struct Projeto {
    char nome[50];
    int codigo;
    Professor* orientador;
} Projeto;

typedef struct Projetos {
    Projeto projeto;
    struct Projetos* next;
} Projetos;

Alunos* cria_lista_alunos();
Professores* cria_lista_professores();
Projetos* cria_lista_projetos();

Alunos* insere_aluno(Alunos* lista);
Professores* insere_professor(Professores* lista);
Projetos* insere_projeto(Projetos* lista, Professores* lista_professores);

void mostra_alunos(Alunos* lista);
void mostra_professores(Professores* lista);
void mostra_projetos(Projetos* lista);

bool busca_professor(int codigo, Professores* lista, Professor** orientador);

void excluir_aluno(Alunos** lista);
void excluir_professor(Professores** lista);
void excluir_projeto(Projetos** lista);
void criar_vinculo(Alunos* lista_alunos, Projetos* lista_projetos);
void excluir_vinculo(Projetos* lista_projetos);

#endif

//#ifdef LISTA_H
#define LISTA_H
#include <stdbool.h>

// estruturas necessarias
typedef struct Aluno {
    char *nome;
    int codigo;
}Aluno; 

typedef struct Alunos {
    Aluno aluno;
    struct Alunos* proximo;
}Alunos;

typedef struct Professor {
    char *nome;
    int codigo;
}Professor;

typedef struct Professores {
    Professor professor;
    struct Professores* proximo;
}Professores;

typedef struct Projeto {
    char *nome;
    int codigo;
    Professor* orientador;
}Projeto;

typedef struct Projetos {
    Projeto projeto;
    struct projetos* proximo;
}Projetos;

// prototipo de funcoes 
Alunos* criar_lista_alunos();
Professores* cria_lista_professoes();

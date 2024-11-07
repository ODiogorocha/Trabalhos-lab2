#ifndef LISTAS_H
#define LISTAS_H

// Definições das structs
typedef struct aluno {
    int matricula;
    char nome[100];
    char telefone[15];
    struct aluno *prox;
} Aluno;

typedef struct projeto {
    int codigo;
    char descricao[200];
    char tipo[20]; 
    float orcamento_aprovado;
    float orcamento_atual;
    struct projeto *prox;
} Projeto;

typedef struct professor {
    int codigo;
    char nome[100];
    char departamento[100];
    struct professor *prox;
} Professor;

typedef struct vinculo {
    Aluno *aluno;
    Projeto *projeto;
    float bolsa_mensal;
    struct vinculo *prox;
} Vinculo;

// Funções de manipulação de listas
Aluno* criarAluno(int matricula, const char *nome, const char *telefone);
Projeto* criarProjeto(int codigo, const char *descricao, const char *tipo, float orcamento_aprovado);
Professor* criarProfessor(int codigo, const char *nome, const char *departamento);
Vinculo* criarVinculo(Aluno *aluno, Projeto *projeto, float bolsa_mensal);

void cadastrarAluno(Aluno **listaAlunos, int matricula, const char *nome, const char *telefone);
void listarAlunos(Aluno *listaAlunos);

void cadastrarProjeto(Projeto **listaProjetos, int codigo, const char *descricao, const char *tipo, float orcamento_aprovado);
void listarProjetos(Projeto *listaProjetos);

void cadastrarProfessor(Professor **listaProfessores, int codigo, const char *nome, const char *departamento);
void listarProfessores(Professor *listaProfessores);

void vincularAlunoProjeto(Aluno *aluno, Projeto *projeto, float bolsa_mensal, Vinculo **listaVinculos);
void listarVinculos(Vinculo *listaVinculos);

#endif 

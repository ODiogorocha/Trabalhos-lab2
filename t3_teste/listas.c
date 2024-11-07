#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

// Funções para criar estruturas
Aluno* criarAluno(int matricula, const char *nome, const char *telefone) {
    Aluno *novo = (Aluno*)malloc(sizeof(Aluno));
    novo->matricula = matricula;
    strcpy(novo->nome, nome);
    strcpy(novo->telefone, telefone);
    novo->prox = NULL;
    return novo;
}

Projeto* criarProjeto(int codigo, const char *descricao, const char *tipo, float orcamento_aprovado) {
    Projeto *novo = (Projeto*)malloc(sizeof(Projeto));
    novo->codigo = codigo;
    strcpy(novo->descricao, descricao);
    strcpy(novo->tipo, tipo);
    novo->orcamento_aprovado = orcamento_aprovado;
    novo->orcamento_atual = orcamento_aprovado; 
    novo->prox = NULL;
    return novo;
}

Professor* criarProfessor(int codigo, const char *nome, const char *departamento) {
    Professor *novo = (Professor*)malloc(sizeof(Professor));
    novo->codigo = codigo;
    strcpy(novo->nome, nome);
    strcpy(novo->departamento, departamento);
    novo->prox = NULL;
    return novo;
}

Vinculo* criarVinculo(Aluno *aluno, Projeto *projeto, float bolsa_mensal) {
    Vinculo *novo = (Vinculo*)malloc(sizeof(Vinculo));
    novo->aluno = aluno;
    novo->projeto = projeto;
    novo->bolsa_mensal = bolsa_mensal;
    novo->prox = NULL;
    return novo;
}

// Funções de cadastro e listagem
void cadastrarAluno(Aluno **listaAlunos, int matricula, const char *nome, const char *telefone) {
    Aluno *novo = criarAluno(matricula, nome, telefone);
    novo->prox = *listaAlunos;
    *listaAlunos = novo;
}

void listarAlunos(Aluno *listaAlunos) {
    Aluno *atual = listaAlunos;
    while (atual != NULL) {
        printf("Matricula: %d\nNome: %s\nTelefone: %s\n\n", atual->matricula, atual->nome, atual->telefone);
        atual = atual->prox;
    }
}

void cadastrarProjeto(Projeto **listaProjetos, int codigo, const char *descricao, const char *tipo, float orcamento_aprovado) {
    Projeto *novo = criarProjeto(codigo, descricao, tipo, orcamento_aprovado);
    novo->prox = *listaProjetos;
    *listaProjetos = novo;
}

void listarProjetos(Projeto *listaProjetos) {
    Projeto *atual = listaProjetos;
    while (atual != NULL) {
        printf("Codigo: %d\nDescricao: %s\nTipo: %s\nOrcamento Aprovado: %.2f\nOrcamento Atual: %.2f\n\n",
               atual->codigo, atual->descricao, atual->tipo, atual->orcamento_aprovado, atual->orcamento_atual);
        atual = atual->prox;
    }
}

void cadastrarProfessor(Professor **listaProfessores, int codigo, const char *nome, const char *departamento) {
    Professor *novo = criarProfessor(codigo, nome, departamento);
    novo->prox = *listaProfessores;
    *listaProfessores = novo;
}

void listarProfessores(Professor *listaProfessores) {
    Professor *atual = listaProfessores;
    while (atual != NULL) {
        printf("Codigo: %d\nNome: %s\nDepartamento: %s\n\n", atual->codigo, atual->nome, atual->departamento);
        atual = atual->prox;
    }
}

void vincularAlunoProjeto(Aluno *aluno, Projeto *projeto, float bolsa_mensal, Vinculo **listaVinculos) {
    // Verifica se o projeto tem orçamento suficiente
    if (projeto->orcamento_atual >= bolsa_mensal * 12) {
        Vinculo *novo = criarVinculo(aluno, projeto, bolsa_mensal);
        novo->prox = *listaVinculos;
        *listaVinculos = novo;
        projeto->orcamento_atual -= bolsa_mensal * 12;
    } else {
        printf("Orcamento insuficiente para vincular o aluno ao projeto.\n");
    }
}

void listarVinculos(Vinculo *listaVinculos) {
    Vinculo *atual = listaVinculos;
    while (atual != NULL) {
        printf("Aluno: %s\nProjeto: %s\nBolsa: %.2f\n\n", atual->aluno->nome, atual->projeto->descricao, atual->bolsa_mensal);
        atual = atual->prox;
    }
}

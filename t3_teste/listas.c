#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "listas.h"

// funcao busca aluno 
Alunos* busca_alunos(int codigo, Alunos* lista){
    Alunos* temporario = lista;
    while (temporario) {
        if (temporario->aluno.codigo == codigo){
            return temporario;
        }
        temporario = temporario->proximo;
    }
    return NULL;
}

// funcao buscar projeto
Projeto* busca_projeto(int codigo, Projeto* lista){
    Projetos* temporario = lista;
    while (temporario) {
        if (temporario->projeto.codigo == codigo){
            return temporario;
        }
        temporario = temporario->proximo;
    }
    return NULL;
}

// funcao busca professor 
bool busca_professor(int codigo, Professores* lista, Professor** orientador) {
    Professores* temporario = lista;
    while (temporario) {
        if (temporario->professor.codigo == codigo) {
            *orientador = &temporario->professor;
            return true;
        }
        temporario = temporario->proximo;
    }
    return false;
}

// funcao para inserir aluno na lista 
Alunos* insere_alunos(Alunos* lista){
    Alunos* novo_aluno = (Alunos*)malloc(sizeof(Alunos));
    printf("Digite o codigo do aluno:\n");
    scanf("%d", &novo_aluno->aluno.codigo);
    printf("Digite o nome do aluno:\n");
    scanf("%s", novo_aluno->aluno.nome);

    novo_aluno->proximo = lista;
    return novo_aluno;
}

// funcao para inserir o professor na lista 
Professores* insere_professores(Professores* lista) {
    Professores* novo_professor = (Professor*)malloc(sizeof(Professores));
    printf("Digite o codigo do professor: \n");
    scanf("%d", &novo_professor->professor.codigo);
    printf("Digite o nome do professor:\n");

    novo_professor->proximo = lista;
    return novo_professor;
}

// funcao para excluir aluno
void excluir_aluno(Alunos** lista){
    int codigo;
    printf("Digite o codigo do aluno a ser excluido: \n");
    scanf("%d", &codigo);

    Alunos* temporario = *lista;
    Alunos* anterior = NULL;

    while (temporario && temporario->aluno.codigo != codigo) {
        anterior = temporario;
        temporario = temporario->proximo;
    }

    if (temporario) {
        if (anterior) {
            anterior->proximo = temporario->proximo;
        }else{
            *lista = temporario->proximo;
        }
        free(temporario);
        printf("Alunos excluido com sucesso !\n");
    }else{
        printf("Alunos nao encontrados..\n");
    }
} 

// funcao excluir projeto 
void excluir_projeto(Projetos** lista) {
    int codigo;
    printf("Digite o código do projeto a ser excluído: ");
    scanf("%d", &codigo);

    Projetos* temporario = *lista;
    Projetos* anterior = NULL;

    while (temporario && temporario->projeto.codigo != codigo) {
        anterior = temporario;
        temporario = temporario->proximo;
    }

    if (temporario) {
        if (anterior) {
            anterior->proximo = temporario->proximo;
        } else {
            *lista = temporario->proximo;
        }
        free(temporario);
        printf("Projeto excluído com sucesso.\n");
    } else {
        printf("Projeto não encontrado.\n");
    }
}

// funcao criar vinculo dos alunos e projetos 
void criar_vnculo(Alunos* lista_alunos, Projetos* lista_projetos) {
    
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


enum tipos_projetos Tipos_projetos;
typedef struct alunos Alunos;
typedef struct aluno Aluno;
typedef struct projetos Projetos;
typedef struct projeto Projeto;
typedef struct professor Professor;
typedef struct professores Professores;

enum tipos_projetos { ensino = 0, pesquisa, extensão };

struct aluno {
    char nome[45];
    int matricula;
    int telefone;
};

struct professor {
    char nome[45];
    int codigo;
    char departamento[10];
};

struct projeto
{
    int cod_projeto;
    char descricao[100];
    int Tipo;
    float orcamento;
    float orcamento_dispo;
    Professor* orientador;
};


struct alunos {
    Aluno pessoa;
    Alunos* prox;
};

struct professores {
    Professor pessoa;
    Professores* prox;
};

struct projetos
{
    Projeto proj;
    Projetos* prox;
};

Alunos* cria_lista_alunos() {
    return NULL;
}

Professores* cria_lista_alunos() {
    return NULL;
}

Projetos* cria_lista_alunos() {
    return NULL;
}

bool busca_professor(int codigo, Professores* lista, Professor* orientador){
    Professores* temporario = lista;

    do {
        if(temporario->pessoa.codigo == codigo) {
            orientador = &lista->pessoa;
            return true;
        }

        temporario = temporario->prox;
    } while (temporario != NULL);

    return false;
}

void orienta_tipo_projeto() {
    printf("Digite o numero 0 se for projeto de ensino\n");
    printf("Digite o numero 1 se for projeto de pesquisa\n");
    printf("Digite o numero 2 se for projeto de extensão\n");
    printf("Qual o tipo do seu projeto: ");
}

int tipo_do_projeto(){
    int qual_projeto;
    
    orienta_tipo_projeto();

    do {
        scanf("%d", &qual_projeto);
        getchar();

        switch (qual_projeto)
        {
        case ensino:
            return ensino;
            
        case pesquisa:
            return pesquisa;
            
        case extensão:
            return extensão;
        
        default:
            printf("O tipo de projeto que voce informou não foi encontrado.\n");
        }

    } while (qual_projeto < 0 || qual_projeto > 2);
}

void registra_aluno(Alunos* aluno) {
    printf("Qual o nome do aluno: ");
    scanf("%s", aluno->pessoa.nome);

    size_t len = strlen(aluno->pessoa.nome);
    if (len > 0 && aluno->pessoa.nome[len - 1] == '\n') {
        aluno->pessoa.nome[len - 1] = '\0';
    }

    printf("Qual a matricula do aluno: ");
    scanf("%d", aluno->pessoa.matricula);

    printf("Qual o telefone do aluno: ");
    scanf("%d", aluno->pessoa.telefone);

    getchar();
}

void registra_professor(Professores* professor) {
    printf("Qual o nome do professor: ");
    scanf("%s", professor->pessoa.nome);

    size_t len = strlen(professor->pessoa.nome);
    if (len > 0 && professor->pessoa.nome[len - 1] == '\n') {
        professor->pessoa.nome[len - 1] = '\0';
    }

    printf("Qual a matricula do professor: ");
    scanf("%d", professor->pessoa.codigo);

    printf("Qual o departamento em siglas do professor: ");
    scanf("%s", professor->pessoa.departamento);

    getchar();
}

int registra_projeto(Projetos* projeto, Professores* lista) {
    int codigo;

    printf("Qual o código do projeto: ");
    scanf("%d", projeto->proj.cod_projeto);

    printf("Qual a descrição do projeto: ");
    scanf("%s", projeto->proj.descricao);

    size_t len = strlen(projeto->proj.descricao);
    if (len > 0 && projeto->proj.descricao[len - 1] == '\n') {
        projeto->proj.descricao[len - 1] = '\0';
    }

    projeto->proj.Tipo = tipo_do_projeto();

    printf("Qual é o orçamento aprovado para o projeto: ");
    scanf("%d", projeto->proj.orcamento);

    projeto->proj.orcamento_dispo = projeto->proj.orcamento;

    printf("Qual o código do professor orientador deste projeto");
    scanf("%d", &codigo);
    if (!busca_professor(codigo, lista, projeto->proj.orientador)) {
        int resposta = 3;
        pergunta_novo_professor(&resposta);
        if(resposta == 1){
            lista = insere_professor(lista);
            return resposta;
        } else {
            return 0;
        }
    }
    return 1;
    getchar();
}

void pergunta_novo_professor(int* resp) {
    printf("O professor informado, não existe nos registros.\n");
    printf("gostaria de registralo(digite 0 para não e 1 para sim): ");
    while (resp < 0 || resp > 1) {
        scanf("%d", resp);
        getchar();
    }
    
}

Alunos* insere_aluno(Alunos* lista){
    Alunos* novo = (Alunos*)malloc(sizeof(Alunos));

    registra_aluno(novo);
    novo->prox = lista;

    return novo;
}

Professores* insere_professor(Professores* lista){
    Professores* novo = (Professores*)malloc(sizeof(Professores));

    registra_professor(novo);
    novo->prox = lista;

    return novo;
}

Projetos* insere_projeto(Projetos* lista, Professores* lista_de_professores){
    int verifica;
    Projetos* novo = (Projetos*)malloc(sizeof(Projetos));

    verifica = registra_projeto(novo, lista_de_professores);
    if(verifica == 0) {
        printf("Como nenhum professor foi encontrado e não foi solicitado registrado, ");
        printf("o registro deste projeto sera apagado.");
        
        free(novo);
        return lista;
    }
    novo->prox = lista;

    return novo;
}

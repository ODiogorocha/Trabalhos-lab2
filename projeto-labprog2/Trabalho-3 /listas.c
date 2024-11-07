#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

enum tipos_projetos { ensino = 0, pesquisa, extensão };

struct vinculo {
    Aluno* aluno;
    int valor_bolsa;
};

struct vinculos {
    Vinculo* vinculo;
    Vinculos* prox;
};

struct aluno {
    char nome[45];
    int matricula;
    int telefone;
};

struct alunos {
    Aluno pessoa;
    Alunos* prox;
};

struct professor {
    char nome[45];
    int codigo;
    char departamento[10];
};

struct professores {
    Professor pessoa;
    Professores* prox;
};

struct projeto
{
    int cod_projeto;
    char descricao[100];
    int Tipo;
    float orcamento;
    float orcamento_dispo;
    Professor* orientador;
    Vinculos* vinculados;
};

struct projetos
{
    Projeto proj;
    Projetos* prox;
};

//########################################//

Alunos* cria_lista_alunos() {
    return NULL;
}

Professores* cria_lista_professores() {
    return NULL;
}

Projetos* cria_lista_projetos() {
    return NULL;
}

Vinculos* cria_lista_vinculos() {
    return NULL;
}

bool busca_professor(int codigo, Professores* lista, Professor* orientador){
    
    if (lista == NULL) {
        return false;
    }
    
    Professores* temporario = lista;

    while (temporario != NULL) {
        if(temporario->pessoa.codigo == codigo) {
            orientador = &lista->pessoa;
            free(temporario);
            return true;
        }

        temporario = temporario->prox;
    }
    free(temporario);
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

bool registra_aluno(Alunos* aluno) {

    printf("Qual a matrícula do aluno: ");
    scanf("%d", &aluno->pessoa.matricula);

    if (verifica_existe_aluno(aluno->prox, aluno->pessoa.matricula)) {
        prinf("O aluno que você deseja registrar ja existe.");
        return true;
    }

    if (verifica_existe_aluno(aluno, aluno))
    printf("Qual o nome do aluno: ");
    scanf("%s", &aluno->pessoa.nome);

    size_t len = strlen(aluno->pessoa.nome);
    if (len > 0 && aluno->pessoa.nome[len - 1] == '\n') {
        aluno->pessoa.nome[len - 1] = '\0';
    }

    printf("Qual o telefone do aluno: ");
    scanf("%d", &aluno->pessoa.telefone);

    getchar();
    
    return false;
}

bool registra_professor(Professores* professor) {
    
    printf("Qual a o código de matrícula do professor: ");
    scanf("%d", &professor->pessoa.codigo);
    
    if (verifica_existe_professor(professor->prox, professor->pessoa.codigo)) {
        prinf("O professor que você deseja registrar ja existe.");
        return true;
    }

    printf("Qual o nome do professor: ");
    scanf("%s", &professor->pessoa.nome);

    size_t len = strlen(professor->pessoa.nome);
    if (len > 0 && professor->pessoa.nome[len - 1] == '\n') {
        professor->pessoa.nome[len - 1] = '\0';
    }

    

    printf("Qual o departamento em siglas do professor: ");
    scanf("%s", &professor->pessoa.departamento);

    getchar();
    
    return false;
}

int registra_projeto(Projetos* projeto, Professores* lista) {
    int codigo;
    int verifica = 0;
    printf("Qual o código do projeto: ");
    scanf("%d", &projeto->proj.cod_projeto);

    if (verifica_existe_professor(projeto->prox, projeto->proj.cod_projeto)) {
        prinf("O projeto que você deseja registrar ja existe.");
        
        verifica = 1;
        return verifica;
    }


    printf("Qual a descrição do projeto: ");
    scanf("%s", &projeto->proj.descricao);

    size_t len = strlen(projeto->proj.descricao);
    if (len > 0 && projeto->proj.descricao[len - 1] == '\n') {
        projeto->proj.descricao[len - 1] = '\0';
    }

    projeto->proj.Tipo = tipo_do_projeto();

    printf("Qual é o orçamento aprovado para o projeto: ");
    scanf("%d", &projeto->proj.orcamento);

    projeto->proj.orcamento_dispo = projeto->proj.orcamento;

    printf("Qual o código do professor orientador deste projeto");
    scanf("%d", &codigo);
    if (!busca_professor(codigo, lista, projeto->proj.orientador)) {
        int resposta = 3;
        pergunta_novo_professor(&resposta);
        if(resposta == 1){
            lista = insere_professor(lista);
            
            return verifica;
        } else {
            verifica = 2;
            return verifica;
        }
    }
    projeto->proj.vinculados = cria_lista_vinculos();
    return verifica;
    getchar();
}

void pergunta_novo_professor(int* resp) {
    printf("O professor informado, não existe nos registros.\n");
    printf("gostaria de registralo(digite 0 para não e 1 para sim): ");
    while (resp < 0 || resp > 1) {
        scanf("%d", &resp);
        getchar();
    }
    
}

Alunos* insere_aluno(Alunos* lista){
    Alunos* novo = (Alunos*)malloc(sizeof(Alunos));

    if(registra_aluno(novo)) {

        free(novo);
        return lista;
    }


    novo->prox = lista;
    return novo;
}

Professores* insere_professor(Professores* lista){
    Professores* novo = (Professores*)malloc(sizeof(Professores));

    if(registra_professor(novo)) {

        free(novo);
        return lista;
    }
    novo->prox = lista;

    return novo;
}

Projetos* insere_projeto(Projetos* lista, Professores* lista_de_professores){

    Projetos* novo = (Projetos*)malloc(sizeof(Projetos));
    int verifica = registra_projeto(novo, lista_de_professores);
    
    if (verifica == 1) {

        free(novo);
        return lista;

    } else if(verifica == 2) {
        printf("Como nenhum professor foi encontrado e não foi solicitado registrado, ");
        printf("o registro deste projeto sera apagado.");
        
        free(novo);
        return lista;
    }
    novo->prox = lista;

    return novo;
}

bool verifica_existe_projeto (Projetos* lista, int codigo) {
    if (lista == NULL) {
        return false;
    }

    Projetos* temporario =  cria_lista_projetos();
    temporario = lista;

    while (temporario != NULL) {
        if (temporario->proj.cod_projeto == codigo) {
            free(temporario);
            return true;
        }
        temporario = temporario->prox;
    }

    free(temporario);
    return false;
}

bool verifica_existe_professor (Professores* lista, int codigo) {
    if (lista == NULL) {
        return false;
    }
    
    Professores* temporario =  cria_lista_professores();
    temporario = lista;

    while (temporario != NULL) {
        if (temporario->pessoa.codigo == codigo) {
            free(temporario);
            return true;
        }
        temporario = temporario->prox;
    }
    free(temporario);
    return false;
}

bool verifica_existe_aluno (Alunos* lista, int matricula) {
    if (lista == NULL) {
        return false;
    }
    
    Alunos* temporario =  cria_lista_alunos();
    temporario = lista;

    while (temporario != NULL) {
        if (temporario->pessoa.matricula == matricula) {
            free(temporario);
            return true;
        }
        temporario = temporario->prox;
    }
    free(temporario);
    return false;
}

//Preciso agregar as funções de mostra as de registro

void mostra_alunos(Alunos* lista) {
    
    if (lista == NULL) {
        printf ("A lista está vazia.");
        return;
    }
    
    Alunos* temporario = (Alunos*)malloc(sizeof(Alunos));
    temporario = lista;
    printf("Lista de alunos por nome e matricula:\n");
    while (temporario != NULL) {
        printf(" | %s\n", lista->pessoa.nome);
    }
}

void mostra_professores(Professores* lista) {
    
    if (lista == NULL) {
        printf ("A lista está vazia.");
        return;
    }
    
    Professores* temporario = (Professores*)malloc(sizeof(Professores));
    temporario = lista;
    printf("Lista de professores por nome e códigos:\n");
    while (temporario != NULL) {
        printf(" | %s, codigo: %d\n", lista->pessoa.nome, lista->pessoa.codigo);
    }
    
}

void mostra_projetos(Projetos* lista) {
    
    if (lista == NULL) {
        printf ("A lista está vazia.");
        return;
    }
    
    Projetos* temporario = (Projetos*)malloc(sizeof(Projetos));
    temporario = lista;
    printf("Lista de projetos por códigos dos projetos:\n");
    while (temporario != NULL) {
        printf(" | %d\n", lista->proj.cod_projeto);
    }
    
}

//Criar vinculos

void criar_vinculo (Alunos* lista_de_alunos, Projetos* lista_de_projetos) {
    
    int matricula, codigo;
    int verifica = 0;
    Projetos* temporario =  cria_lista_projetos();
    do {
        if (verifica == 1) {
            printf ("Projeto não encontrado, tente novamente.\n");
        }
        verifica = 1;
        printf ("Digite o código do projeto que você gostaria de registrar o bolsista:");
        scanf("%d", &codigo);
        
        
        temporario = lista_de_projetos;

        while (temporario != NULL) {
            if (temporario->proj.cod_projeto == codigo) {
                verifica = 0;
                break;
                
            }
            temporario = temporario->prox;
        }

        
    } while (verifica == 0);

    



}

bool vincular_aluno (Alunos* lista, Projeto* projeto) {
    Alunos* temporario = (Alunos*)malloc(sizeof(Alunos));
    
    int matricula, verifica = 0;


    do {
        if (verifica == 1) {
            printf ("aluno não encontrado\n");
            printf ("Digite 1 para tentar novamente e 0 casso queira desistir do processo:");
            scanf("%d", &verifica);
        }
        if (verifica == 0) {
            printf("Aluno não encontrado e, não foi escolhido tentar novamente.\n");
            return false;
        }
        verifica = 1;

        printf ("Digite a matricula do aluno que sera vinculado:");
        scanf("%d", &matricula);
        temporario = lista;

        while (temporario != NULL) {
            if (temporario->pessoa.matricula == matricula) {
                projeto->vinculados->vinculo->aluno = &temporario->pessoa;
                verifica = 2;
                free(temporario);
                break;
            }
            temporario = temporario->prox;
        }



    } while (verifica == 2);
    free(temporario);



}

bool verifica_verba(Projeto* projeto) {
    float bolsa = -1.0;

    while (bolsa < 0 || bolsa > projeto->orcamento_dispo) {
        printf("Digite o valor mensal da bolsa: ");
        scanf("%f", &bolsa);
    }
}
//criada para testes
int main() {

}

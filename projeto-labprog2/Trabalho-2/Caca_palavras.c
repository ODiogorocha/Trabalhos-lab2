//##################################################//
//              O CAÇA PALAVRAS                     //
//    trabalho 2 de laboratorio de programação 2    //
//      Feito por Weslley Menezes e Diogo Rocha     //
//##################################################//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//##################################################//
// Funções de entrada

void coletar_frase(char **matriz, int lin, int colu);
void pede_tam(int* colu, int* lin);

//##################################################//
// Função de saída

void imprimir_matriz(char **matriz, int lin, int colu);

//##################################################//
// Funções alocação dinamica

char **alocar_matriz(int colu, int lin);
void liberar_matriz(char **matriz, int lin);

//##################################################//
// Funções de processamento

void buscar_palavra_direcao(char **matriz, int lin, int colu, const char *palavra);
void completa_com_0(int colu, int lin, char** matriz);
void preencher_matriz(char **matriz, int lin, int colu, char *vetor);
bool quer_jogar(char palavra[50]);

//##################################################//
// funções de busca
bool buscar_horizontal_esquerda_direita(char **matriz, int lin, int colu, const char *palavra, int *linha_ini, int *coluna_ini, int *linha_fim, int *coluna_fim);
bool buscar_horizontal_direita_esquerda(char **matriz, int lin, int colu, const char *palavra, int *linha_ini, int *coluna_ini, int *linha_fim, int *coluna_fim);
bool buscar_vertical_cima_baixo(char **matriz, int lin, int colu, const char *palavra, int *linha_ini, int *coluna_ini, int *linha_fim, int *coluna_fim);
bool buscar_vertical_baixo_cima(char **matriz, int lin, int colu, const char *palavra, int *linha_ini, int *coluna_ini, int *linha_fim, int *coluna_fim);
bool buscar_diagonal_principal_cima_baixo(char **matriz, int lin, int colu, const char *palavra, int *linha_ini, int *coluna_ini, int *linha_fim, int *coluna_fim);
bool buscar_diagonal_principal_baixo_cima(char **matriz, int lin, int colu, const char *palavra, int *linha_ini, int *coluna_ini, int *linha_fim, int *coluna_fim);
bool buscar_diagonal_secundaria_cima_baixo(char **matriz, int lin, int colu, const char *palavra, int *linha_ini, int *coluna_ini, int *linha_fim, int *coluna_fim);
bool buscar_diagonal_secundaria_baixo_cima(char **matriz, int lin, int colu, const char *palavra, int *linha_ini, int *coluna_ini, int *linha_fim, int *coluna_fim);

//#################################################//
// Funções

int main() {
    int linhas, colunas; // Definindo tamanho da matriz
    char palavra[50];

    pede_tam(&colunas, &linhas);
    char **matriz = alocar_matriz(colunas, linhas);
    coletar_frase(matriz, linhas, colunas);
    printf("||Digite *** para parar de jogar.||\n");
    imprimir_matriz(matriz, linhas, colunas);
    
    do{
        printf("Digite a palavra que deseja buscar: ");
        fgets(palavra, sizeof(palavra), stdin);
        size_t len = strlen(palavra);
        if (len > 0 && palavra[len - 1] == '\n') {
            palavra[len - 1] = '\0';
        }
    
        buscar_palavra_direcao(matriz, linhas, colunas, palavra);
    } while (quer_jogar(palavra));
    

    liberar_matriz(matriz, linhas);
    return 0;
}

char **alocar_matriz(int colu, int lin) {
    char **caca_pala;
    caca_pala = (char**)malloc(sizeof(char*) * lin);
    if (caca_pala == NULL) {
        printf("Alocação deu errado.");
        return NULL;
    }

    for (int i = 0; i < lin - 1; i++) {
        caca_pala[i] = (char*)malloc(sizeof(char) * colu);
        if(caca_pala[i] == NULL){
            printf("Algo deu errado na alocação das lin.\n");
            return NULL;
        }
    }

    caca_pala[lin - 1] = (char*)malloc(sizeof(char) * (colu + 1));
    if (caca_pala == NULL) {
        printf("Alocação deu errado.");
        return NULL;
    }

    completa_com_0(colu, lin, caca_pala);
    return caca_pala;
}

void liberar_matriz(char **matriz, int lin) {
    for (int i = 0; i < lin; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

void coletar_frase(char **matriz, int lin, int colu) {
    char *vetor = (char*)malloc(sizeof(char) * (colu * lin) * 2);
    
    printf("Insira a sua frase para virar o caça palavras: ");
    fgets(vetor, (colu * lin) * 2, stdin);
    size_t len = strlen(vetor);
    if (len > 0 && vetor[len - 1] == '\n') {
        vetor[len - 1] = '\0';
    }

    preencher_matriz(matriz, lin, colu, vetor);
    free(vetor);
}

void preencher_matriz(char **matriz, int lin, int colu, char *vetor) {
    int conta_vetor = 0;
    
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < colu; j++) {
            

            while (vetor[conta_vetor] == ' ' && conta_vetor < ((lin * colu) * 2)) {
                conta_vetor++;
            }
            if (vetor[conta_vetor] == '\0') {
                break;
            }
            matriz[i][j] = vetor[conta_vetor];
            conta_vetor++;
        }
    }
    
   matriz[lin - 1][colu] = '\0';
}

void completa_com_0(int colu, int lin, char** matriz) {
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < colu; j++) {

            matriz[i][j] = '0';

        }
    }
    matriz[lin - 1][colu] = '\0';

}

void imprimir_matriz(char **matriz, int lin, int colu) {
    int temporario;
    printf("Matriz:\n");
    for (int i = 0; i < colu; i++){    
        temporario = i + 1;
        if(i != 0) {
            printf(" %d", temporario);
        } else {
            printf("  %d", temporario);  
        }
        
    }
    printf("\n");
    for (int i = 0; i < lin; i++) {
        temporario = i + 1;
        printf("%d ", temporario);
        for (int j = 0; j < colu; j++) {

            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
}

bool quer_jogar(char palavra[50]) {
    char verifica [4] = "***";

    if (strcmp(palavra, verifica) != 0) {
        return true;
    }
    printf("!!OBRIGADO POR JOGAR!!");
    return false;
}

void pede_tam(int* colu, int* lin) {
    printf("Qual o número de linhas da sua matriz: ");
    scanf("%d", lin);
    printf("Qual o número de colunas da sua matriz: ");
    scanf("%d", colu);
    getchar();
}

void buscar_palavra_direcao(char **matriz, int lin, int colu, const char *palavra) {
    int linha_inicio, coluna_inicio, linha_fim, coluna_fim;
    if (buscar_horizontal_esquerda_direita(matriz, lin, colu, palavra, &linha_inicio, &coluna_inicio, &linha_fim, &coluna_fim)) {
        printf("A palavra '%s' ocorre na horizontal esquerda para direita, iniciando na posição [%d, %d] e tenmina na posição [%d, %d].\n", palavra, linha_inicio, coluna_inicio, linha_fim, coluna_fim);
        return;
    }
    if (buscar_horizontal_direita_esquerda(matriz, lin, colu, palavra, &linha_inicio, &coluna_inicio, &linha_fim, &coluna_fim)) {
        printf("A palavra '%s' ocorre na horizontal direita para esquerda, iniciando na posição [%d, %d] e tenmina na posição [%d, %d].\n", palavra, linha_inicio, coluna_inicio, linha_fim, coluna_fim);
        return;
    }
    if (buscar_vertical_cima_baixo(matriz, lin, colu, palavra, &linha_inicio, &coluna_inicio, &linha_fim, &coluna_fim)) {
        printf("A palavra '%s' ocorre na vertical cima para baixo, iniciando na posição [%d, %d] e tenmina na posição [%d, %d].\n", palavra, linha_inicio, coluna_inicio, linha_fim, coluna_fim);
        return;
    }
    if (buscar_vertical_baixo_cima(matriz, lin, colu, palavra, &linha_inicio, &coluna_inicio, &linha_fim, &coluna_fim)) {
        printf("A palavra '%s' ocorre na vertical baixo para cima, iniciando na posição [%d, %d] e tenmina na posição [%d, %d].\n", palavra, linha_inicio, coluna_inicio, linha_fim, coluna_fim);
        return;
    }
    if (buscar_diagonal_principal_cima_baixo(matriz, lin, colu, palavra, &linha_inicio, &coluna_inicio, &linha_fim, &coluna_fim)) {
        printf("A palavra '%s' ocorre na diagonal principal (cima para baixo), iniciando na posição [%d, %d] e tenmina na posição [%d, %d].\n", palavra, linha_inicio, coluna_inicio, linha_fim, coluna_fim);
        return;
    }
    if (buscar_diagonal_principal_baixo_cima(matriz, lin, colu, palavra, &linha_inicio, &coluna_inicio, &linha_fim, &coluna_fim)) {
        printf("A palavra '%s' ocorre na diagonal principal (baixo para cima), iniciando na posição [%d, %d] e tenmina na posição [%d, %d].\n", palavra, linha_inicio, coluna_inicio, linha_fim, coluna_fim);
        return;
    }
    if (buscar_diagonal_secundaria_cima_baixo(matriz, lin, colu, palavra, &linha_inicio, &coluna_inicio, &linha_fim, &coluna_fim)) {
        printf("A palavra '%s' ocorre na diagonal secundária (cima para baixo), iniciando na posição [%d, %d] e tenmina na posição [%d, %d].\n", palavra, linha_inicio, coluna_inicio, linha_fim, coluna_fim);
        return;
    }
    if (buscar_diagonal_secundaria_baixo_cima(matriz, lin, colu, palavra, &linha_inicio, &coluna_inicio, &linha_fim, &coluna_fim)) {
        printf("A palavra '%s' ocorre na diagonal secundária (baixo para cima), iniciando na posição [%d, %d] e tenmina na posição [%d, %d].\n", palavra, linha_inicio, coluna_inicio, linha_fim, coluna_fim);
        return;
    }
    printf("A palavra '%s' não foi encontrada na matriz.\n", palavra);
}

bool buscar_horizontal_esquerda_direita(char **matriz, int lin, int colu, const char *palavra, int *linha_ini, int *coluna_ini, int *linha_fim, int *coluna_fim) {
    int tamanhoPalavra = strlen(palavra);
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j <= colu - tamanhoPalavra; j++) {
            if (strncmp(&matriz[i][j], palavra, tamanhoPalavra) == 0) {
                *linha_ini = i + 1;
                *coluna_ini = j + 1;
                *linha_fim = i + 1;
                *coluna_fim = j + tamanhoPalavra;
                return true; // Palavra encontrada
            }
        }
    }
    return false; // Palavra não encontrada
}

bool buscar_horizontal_direita_esquerda(char **matriz, int lin, int colu, const char *palavra, int *linha_ini, int *coluna_ini, int *linha_fim, int *coluna_fim) {
    int tamanhoPalavra = strlen(palavra);

    for (int i = 0; i < lin; i++) {
        for (int j = colu - 1; j >= tamanhoPalavra - 1; j--) {  // Começa da direita e vai para a esquerda
            int k;
            bool valida = true;
            
            // Verifica se a palavra está presente da direita para a esquerda
            for (k = 0; k < tamanhoPalavra; k++) {
                if (matriz[i][j - k] != palavra[k]) {
                    valida = false;
                    break;
                }
            }
            
            if (valida) {
                *linha_ini = i + 1;
                *coluna_ini = j + 1;
                *linha_fim = i + 1;
                *coluna_fim = j - tamanhoPalavra + 2;
                return true; // Palavra encontrada
            }
        }
    }

    return false; // Palavra não encontrada
}

bool buscar_vertical_cima_baixo(char **matriz, int lin, int colu, const char *palavra, int *linha_ini, int *coluna_ini, int *linha_fim, int *coluna_fim) {
    int tamanhoPalavra = strlen(palavra);
    for (int j = 0; j < colu; j++) {
        for (int i = 0; i <= lin - tamanhoPalavra; i++) {
            int k;
            for (k = 0; k <= tamanhoPalavra; k++) {
                if (matriz[i + k][j] != palavra[k]) {
                    break;
                }
            }
            if (k == tamanhoPalavra) {
                *linha_ini = i + 1;
                *coluna_ini = j + 1;
                *linha_fim = i + tamanhoPalavra;
                *coluna_fim = j + 1;
                return true; // Palavra encontrada
            }
        }
    }
    return false; // Palavra não encontrada
}

bool buscar_vertical_baixo_cima(char **matriz, int lin, int colu, const char *palavra, int *linha_ini, int *coluna_ini, int *linha_fim, int *coluna_fim) {
    int tamanhoPalavra = strlen(palavra);
    for (int j = 0; j < colu; j++) {
        for (int i = lin - 1; i >= tamanhoPalavra - 1; i--) {
            int k;
            for (k = 0; k < tamanhoPalavra; k++) {
                if (matriz[i - k][j] != palavra[k]) {
                    break;
                }
            }
            if (k == tamanhoPalavra) {
                *linha_ini = i + 1;
                *coluna_ini = j + 1;
                *linha_fim = i - tamanhoPalavra + 2;
                *coluna_fim = j + 1;
                return true; // Palavra encontrada
            }
        }
    }
    return false; // Palavra não encontrada
}

bool buscar_diagonal_principal_cima_baixo(char **matriz, int lin, int colu, const char *palavra, int *linha_ini, int *coluna_ini, int *linha_fim, int *coluna_fim) {
    int tamanhoPalavra = strlen(palavra);
    for (int i = 0; i <= lin - tamanhoPalavra; i++) {
        for (int j = 0; j <= colu - tamanhoPalavra; j++) {
            int k;
            for (k = 0; k < tamanhoPalavra; k++) {
                if (matriz[i + k][j + k] != palavra[k]) {
                    break;
                }
            }
            if (k == tamanhoPalavra) {
                *linha_ini = i + 1;
                *coluna_ini = j + 1;
                *linha_fim = i + tamanhoPalavra;
                *coluna_fim = j + tamanhoPalavra;
                return true; // Palavra encontrada
            }
        }
    }
    return false; // Palavra não encontrada
}

bool buscar_diagonal_principal_baixo_cima(char **matriz, int lin, int colu, const char *palavra, int *linha_ini, int *coluna_ini, int *linha_fim, int *coluna_fim) {
    int tamanhoPalavra = strlen(palavra);
    for (int i = lin - 1; i >= tamanhoPalavra - 1; i--) {
        for (int j = colu - 1; j >= tamanhoPalavra - 1; j--) {
            int k;
            for (k = 0; k < tamanhoPalavra; k++) {
                if (matriz[i - k][j - k] != palavra[k]) {
                    break;
                }
            }
            if (k == tamanhoPalavra) {
                *linha_ini = i + 1;
                *coluna_ini = j + 1;
                *linha_fim = i - tamanhoPalavra + 2;
                *coluna_fim = j - tamanhoPalavra + 2;
                return true; // Palavra encontrada
            }
        }
    }
    return false; // Palavra não encontrada
}

bool buscar_diagonal_secundaria_cima_baixo(char **matriz, int lin, int colu, const char *palavra, int *linha_ini, int *coluna_ini, int *linha_fim, int *coluna_fim) {
    int tamanhoPalavra = strlen(palavra);
    for (int i = 0; i <= lin - tamanhoPalavra; i++) {
        for (int j = tamanhoPalavra - 1; j < colu; j++) {
            int k;
            for (k = 0; k < tamanhoPalavra; k++) {
                if (matriz[i + k][j - k] != palavra[k]) {
                    break;
                }
            }
            if (k == tamanhoPalavra) {
                *linha_ini = i + 1;
                *coluna_ini = j + 1;
                *linha_fim = i + tamanhoPalavra;
                *coluna_fim = j - tamanhoPalavra + 2;
                return true; // Palavra encontrada
            }
        }
    }
    return false; // Palavra não encontrada
}

bool buscar_diagonal_secundaria_baixo_cima(char **matriz, int lin, int colu, const char *palavra, int *linha_ini, int *coluna_ini, int *linha_fim, int *coluna_fim) {
    int tamanhoPalavra = strlen(palavra);
    for (int i = lin - 1; i >= tamanhoPalavra - 1; i--) {
        for (int j = 0; j <= colu - tamanhoPalavra; j++) {
            int k;
            for (k = 0; k < tamanhoPalavra; k++) {
                if (matriz[i - k][j + k] != palavra[k]) {
                    break;
                }
            }
            if (k == tamanhoPalavra) {
                *linha_ini = i + 1;
                *coluna_ini = j + 1;
                *linha_fim = i - tamanhoPalavra + 2;
                *coluna_fim = j + tamanhoPalavra;
                return true; // Palavra encontrada
            }
        }
    }
    return false; // Palavra não encontrada
}

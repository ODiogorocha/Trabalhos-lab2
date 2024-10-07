#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Protótipos das funções
char **alocar_matriz(int colu, int lin);
void liberar_matriz(char **matriz, int lin);
void coletar_frase(char **matriz, int lin, int colu);
void preencher_matriz(char **matriz, int lin, int colu, char *vetor);
void imprimir_matriz(char **matriz, int lin, int colu);
void buscar_palavra_direcao(char **matriz, int lin, int colu, const char *palavra);
int buscar_horizontal_esquerda_direita(char **matriz, int lin, int colu, const char *palavra, int *linha, int *coluna);
int buscar_horizontal_direita_esquerda(char **matriz, int lin, int colu, const char *palavra, int *linha, int *coluna);
int buscar_vertical_cima_baixo(char **matriz, int lin, int colu, const char *palavra, int *linha, int *coluna);
int buscar_vertical_baixo_cima(char **matriz, int lin, int colu, const char *palavra, int *linha, int *coluna);
int buscar_diagonal_principal_cima_baixo(char **matriz, int lin, int colu, const char *palavra, int *linha, int *coluna);
int buscar_diagonal_principal_baixo_cima(char **matriz, int lin, int colu, const char *palavra, int *linha, int *coluna);
int buscar_diagonal_secundaria_cima_baixo(char **matriz, int lin, int colu, const char *palavra, int *linha, int *coluna);
int buscar_diagonal_secundaria_baixo_cima(char **matriz, int lin, int colu, const char *palavra, int *linha, int *coluna);

// Funções
char **alocar_matriz(int colu, int lin) {
    char **caca_pala = (char**)malloc(sizeof(char*) * lin);
    if (caca_pala == NULL) {
        printf("Alocação deu errado.");
        return NULL;
    }

    for (int i = 0; i < lin; i++) {
        caca_pala[i] = (char*)malloc(sizeof(char) * colu);
        if (caca_pala[i] == NULL) {
            printf("Algo deu errado na alocação das linhas.\n");
            return NULL;
        }
    }
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
            if (vetor[conta_vetor] == ' ') {
                conta_vetor++;
            }
            matriz[i][j] = vetor[conta_vetor++];
        }
    }
}

void imprimir_matriz(char **matriz, int lin, int colu) {
    printf("Matriz:\n");
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < colu; j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
}

void buscar_palavra_direcao(char **matriz, int lin, int colu, const char *palavra) {
    int linha, coluna;
    if (buscar_horizontal_esquerda_direita(matriz, lin, colu, palavra, &linha, &coluna)) {
        printf("A palavra '%s' ocorre na horizontal esquerda para direita, iniciando na posição [%d, %d]\n", palavra, linha + 1, coluna + 1);
        return;
    }
    if (buscar_horizontal_direita_esquerda(matriz, lin, colu, palavra, &linha, &coluna)) {
        printf("A palavra '%s' ocorre na horizontal direita para esquerda, iniciando na posição [%d, %d]\n", palavra, linha + 1, coluna + 1);
        return;
    }
    if (buscar_vertical_cima_baixo(matriz, lin, colu, palavra, &linha, &coluna)) {
        printf("A palavra '%s' ocorre na vertical cima para baixo, iniciando na posição [%d, %d]\n", palavra, linha + 1, coluna + 1);
        return;
    }
    if (buscar_vertical_baixo_cima(matriz, lin, colu, palavra, &linha, &coluna)) {
        printf("A palavra '%s' ocorre na vertical baixo para cima, iniciando na posição [%d, %d]\n", palavra, linha + 1, coluna + 1);
        return;
    }
    if (buscar_diagonal_principal_cima_baixo(matriz, lin, colu, palavra, &linha, &coluna)) {
        printf("A palavra '%s' ocorre na diagonal principal (cima para baixo), iniciando na posição [%d, %d]\n", palavra, linha + 1, coluna + 1);
        return;
    }
    if (buscar_diagonal_principal_baixo_cima(matriz, lin, colu, palavra, &linha, &coluna)) {
        printf("A palavra '%s' ocorre na diagonal principal (baixo para cima), iniciando na posição [%d, %d]\n", palavra, linha + 1, coluna + 1);
        return;
    }
    if (buscar_diagonal_secundaria_cima_baixo(matriz, lin, colu, palavra, &linha, &coluna)) {
        printf("A palavra '%s' ocorre na diagonal secundária (cima para baixo), iniciando na posição [%d, %d]\n", palavra, linha + 1, coluna + 1);
        return;
    }
    if (buscar_diagonal_secundaria_baixo_cima(matriz, lin, colu, palavra, &linha, &coluna)) {
        printf("A palavra '%s' ocorre na diagonal secundária (baixo para cima), iniciando na posição [%d, %d]\n", palavra, linha + 1, coluna + 1);
        return;
    }
    printf("A palavra '%s' não foi encontrada na matriz.\n", palavra);
}

int buscar_horizontal_esquerda_direita(char **matriz, int lin, int colu, const char *palavra, int *linha, int *coluna) {
    int tamanhoPalavra = strlen(palavra);
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j <= colu - tamanhoPalavra; j++) {
            if (strncmp(&matriz[i][j], palavra, tamanhoPalavra) == 0) {
                *linha = i;
                *coluna = j;
                return 1; // Palavra encontrada
            }
        }
    }
    return 0; // Palavra não encontrada
}

int buscar_horizontal_direita_esquerda(char **matriz, int lin, int colu, const char *palavra, int *linha, int *coluna) {
    int tamanhoPalavra = strlen(palavra);
    for (int i = 0; i < lin; i++) {
        for (int j = colu - 1; j >= tamanhoPalavra - 1; j--) {
            if (strncmp(&matriz[i][j - tamanhoPalavra + 1], palavra, tamanhoPalavra) == 0) {
                *linha = i;
                *coluna = j - tamanhoPalavra + 1;
                return 1; // Palavra encontrada
            }
        }
    }
    return 0; // Palavra não encontrada
}

int buscar_vertical_cima_baixo(char **matriz, int lin, int colu, const char *palavra, int *linha, int *coluna) {
    int tamanhoPalavra = strlen(palavra);
    for (int j = 0; j < colu; j++) {
        for (int i = 0; i <= lin - tamanhoPalavra; i++) {
            int k;
            for (k = 0; k < tamanhoPalavra; k++) {
                if (matriz[i + k][j] != palavra[k]) {
                    break;
                }
            }
            if (k == tamanhoPalavra) {
                *linha = i;
                *coluna = j;
                return 1; // Palavra encontrada
            }
        }
    }
    return 0; // Palavra não encontrada
}

int buscar_vertical_baixo_cima(char **matriz, int lin, int colu, const char *palavra, int *linha, int *coluna) {
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
                *linha = i;
                *coluna = j;
                return 1; // Palavra encontrada
            }
        }
    }
    return 0; // Palavra não encontrada
}

int buscar_diagonal_principal_cima_baixo(char **matriz, int lin, int colu, const char *palavra, int *linha, int *coluna) {
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
                *linha = i;
                *coluna = j;
                return 1; // Palavra encontrada
            }
        }
    }
    return 0; // Palavra não encontrada
}

int buscar_diagonal_principal_baixo_cima(char **matriz, int lin, int colu, const char *palavra, int *linha, int *coluna) {
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
                *linha = i;
                *coluna = j;
                return 1; // Palavra encontrada
            }
        }
    }
    return 0; // Palavra não encontrada
}

int buscar_diagonal_secundaria_cima_baixo(char **matriz, int lin, int colu, const char *palavra, int *linha, int *coluna) {
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
                *linha = i;
                *coluna = j;
                return 1; // Palavra encontrada
            }
        }
    }
    return 0; // Palavra não encontrada
}

int buscar_diagonal_secundaria_baixo_cima(char **matriz, int lin, int colu, const char *palavra, int *linha, int *coluna) {
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
                *linha = i;
                *coluna = j;
                return 1; // Palavra encontrada
            }
        }
    }
    return 0; // Palavra não encontrada
}

int main() {
    int lin = 5, colu = 5; // Definindo tamanho da matriz
    char **matriz = alocar_matriz(colu, lin);
    
    coletar_frase(matriz, lin, colu);
    imprimir_matriz(matriz, lin, colu);

    char palavra[50];
    printf("Digite a palavra que deseja buscar: ");
    fgets(palavra, sizeof(palavra), stdin);
    size_t len = strlen(palavra);
    if (len > 0 && palavra[len - 1] == '\n') {
        palavra[len - 1] = '\0';
    }

    buscar_palavra_direcao(matriz, lin, colu, palavra);

    liberar_matriz(matriz, lin);
    return 0;
}

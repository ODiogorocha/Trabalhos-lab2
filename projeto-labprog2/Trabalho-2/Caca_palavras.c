#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

    caca_pala[lin - 1] = (char**)malloc(sizeof(char*) * (colu + 1));
    if (caca_pala == NULL) {
        printf("Alocação deu errado.");
        return NULL;
    }

    return caca_pala;
}

void libera_matriz(char** caca_pala, int colu) {
    for (int i = 0; i < colu; i++) {
        free(caca_pala[i]);
    }
    free(caca_pala);
}

void coleta_a_frase(char** caca_pala, int colu, int lin) {
    int tamanho_da_frase = 0;
    char * vetor = (char*)malloc(sizeof(char) * (colu * lin) * 2);
    
    
    printf("Insira a sua frase para virar o caça palavras: ");
    
    fgets(vetor, ((colu * lin) * 2), stdin);
    size_t len = strlen(vetor);
    if (len > 0 && vetor[len - 1] == '\n') {
        vetor[len - 1] = '\0';
    }


}
void salva_na_matriz(char** caca_pala, int lin, int colu, int tamanho_da_frase, char* vetor) {
    int conta_vetor = 0;
    
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < colu; j++) {
            

            if (vetor[conta_vetor] == ' ') {
                conta_vetor++;
            }
            caca_pala[i][j] = vetor[conta_vetor];
            tamanho_da_frase++;
            conta_vetor++;
        }

        
    }
    
   caca_pala[lin - 1][colu + 1] = '\0';
}
//fazer função para completar a matriz.


int main() {
    int colunas = 3; 
    int linhas = 4; 
    
    char** mat;

    mat = alocar_matriz(colunas, linhas); 

    coleta_a_frase(mat, colunas, linhas);

}

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

//#################################################//
//funções de entrada:
int pede_valor();

void monta_matriz(int m, int mat[m][6]);

int o_que_fazer(int opcao, int vet[6]);

int pede_numero_municipios();

//#################################################//
//funções de processamento:
int calcula_em_100mil(float populacao, float casos);

void separa_o_maior(int m, int mat[m][6], int vet[2]);

void executa_atividade();

void chama_funcoes_na_ordem_certa(int m, int mat[m][6], int vet[2]);

//#################################################//
//funções de saída:

void mostrar_linha(int vet[6]);

void mostrar_tabela(int m, int mat[m][6]);

void mostra_maior_municipio_casos(int casos);

void mostra_maior_municipio_mortes(int casos);

void junta_os_mostrar(int m, int mat[m][6], int vet[2]);

//#################################################//

int main() { executa_atividade(); }

int pede_valor() {
  int valor;
  scanf("%d", &valor);
  return valor;
}

int calcula_em_100mil(float populacao, float casos) {
  int resultado;

  resultado = casos * 100000 / populacao;

  return resultado;
}

int o_que_fazer(int opcao, int vet[6]) {
  if (opcao == 0) {
    printf("Informe o código do município: ");
    return pede_valor();
  } else if (opcao == 1) {
    printf("Informe o número de habitantes do município: ");
    return pede_valor();
  } else if (opcao == 2) {
    printf("Informe o número total de casos confirmados: ");
    return pede_valor();
  } else if (opcao == 3) {
    printf("Informe o número total de óbitos: ");
    return pede_valor();
  } else if (opcao == 4) {
    return calcula_em_100mil(vet[1], vet[2]);
  } else if (opcao == 5) {
    return calcula_em_100mil(vet[1], vet[3]);
  } else {
    printf("O loço for deu problema");
    return 0;
  }
}

void monta_matriz(int m, int mat[m][6]) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 6; j++) {
      mat[i][j] = o_que_fazer(j, mat[i]);
    }
    printf("\n##################################################################\n\n");
  }
}

void separa_o_maior(int m, int mat[m][6], int vet[2]) {
  int maior_casos = mat[0][4];
  int maior_mortes = mat[0][5];

  printf("\n%d||%d\n", maior_casos, maior_mortes);

  for (int i = 0; i < m; i++) {
    if (maior_casos <= mat[i][4]) {
      vet[0] = mat[i][0];
      maior_casos = mat[i][4];
    } else if (maior_mortes <= mat[i][5]) {
      vet[1] = mat[i][0];
      int maior_mortes = mat[i][5];
    }
  }
}

void mostrar_linha(int vet[6]) {
  for (int i = 0; i < 6; i++) {
    printf(" %d |", vet[i]);
  }
}

void mostrar_tabela(int m, int mat[m][6]) {
  printf("\n");
  for (int i = 0; i < m; i++) {
    printf("|");
    mostrar_linha(mat[i]);
    printf("\n");
  }
}

void mostra_maior_municipio_casos(int casos) {
  printf("O código do município que tem a maior incidência de casos é: ");
  printf("%d\n", casos);
}

void mostra_maior_municipio_mortes(int casos) {
  printf("O código do município que tem a maior mortalidade: ");
  printf("%d\n", casos);
}

void junta_os_mostrar(int m, int mat[m][6], int vet[2]) {
  mostrar_tabela(m, mat);
  mostra_maior_municipio_casos(vet[0]);
  mostra_maior_municipio_mortes(vet[1]);
}

void chama_funcoes_na_ordem_certa(int m, int mat[m][6], int vet[2]) {
  monta_matriz(m, mat);
  separa_o_maior(m, mat, vet);
  junta_os_mostrar(m, mat, vet);
}

int pede_numero_municipios() {
  printf("Informe o numero de municípios: ");
  int municipios = pede_valor();
  return municipios;
}

void executa_atividade() {

  int numero_municipios = pede_numero_municipios();
  int matriz_da_doenca[numero_municipios][6];
  int vetor_dos_maiores[2];

  chama_funcoes_na_ordem_certa(numero_municipios, matriz_da_doenca, vetor_dos_maiores);
}

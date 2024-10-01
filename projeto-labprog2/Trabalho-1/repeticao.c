#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool verifica_se_crescente(float vet[3]) {

  if (vet[0] < vet[1] && vet[1] < vet[2]) {
    return true;
  }
  return false;
}

void pede_e_guarda_valores(float vetor_valores[3]) {
  float variavel_temp;

  for (int i = 0; i < 3; i++) {
    printf("Digite um número: ");
    if (scanf("%f", &variavel_temp) != 1) {
      return;
    }
    vetor_valores[i] = variavel_temp;
  }
}

int soma(float vetor[3]) {
  float soma = 0;

  for (int i = 0; i < 3; i++) {
    soma = soma + vetor[i];
  }
  return soma;
}

int produto(float vetor[3]) {
  float produto = 1;

  for (int i = 0; i < 3; i++) {
    produto = produto * vetor[i];
  }

  return produto;
}

int media(float vetor[3]) {
  float media = 0;

  for (int i = 0; i < 3; i++) {
    media = media + vetor[i];
  }
  media = media / 3;

  return media;
}

void apresenta_resultados(float vet[3]) {
  float som = soma(vet);
  float prod = produto(vet);
  float med = media(vet);

  printf("O resultado da soma dos três números é: %0.2f\n", som);

  printf("O resultado do produto dos três números é: %0.2f\n", prod);

  printf("O resultado da média dos três números é: %0.2f \n", med);
}

void laco_de_repet() {
  float vetor[3];

  pede_e_guarda_valores(vetor);

  while (verifica_se_crescente(vetor)) {
    apresenta_resultados(vetor);
    pede_e_guarda_valores(vetor);
  }
  printf("Adeus.");
}

int main() { laco_de_repet(); }

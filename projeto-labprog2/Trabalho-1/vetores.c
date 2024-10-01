#include <stdio.h>
#include <stdlib.h>

void le_vetor_de_inteiros(int vet[5]){
    printf("Escreva os valores a serem armazenados no vetor:\n");
    for(int i = 0; i < 5; i++){
        scanf("%d", &vet[i]);
    }
}

void inverte_vetor(int vet[5]){
    int vetor_invertido[5];

    for(int i = 0; i < 5; i++){
        vetor_invertido[i] = vet[4 - i]; 
    }

    printf("Vetor original:\n");
    for(int i = 0; i < 5; i++){
        printf("%d ", vet[i]);
    }
    printf("\nVetor invertido:\n");
    for(int i = 0; i < 5; i++){
        printf("%d ", vetor_invertido[i]);
    }
    printf("\n");
}

void ordenar_vetor(int vet[5]){
    int aux;
    for(int i = 0; i < 5 - 1; i++){
        for(int j = i + 1; j < 5; j++){
            if(vet[i] > vet[j]){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }

    printf("Vetor ordenado:\n");
    for(int i = 0; i < 5; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}

int maior_valor_do_vetor(int vet[5]){
    int maior = vet[0]; 
    for(int i = 1; i < 5; i++){
        if(maior < vet[i]){
            maior = vet[i];
        }
    }
    return maior;
}

int menor_valor_do_vetor(int vet[5]){
    int menor = vet[0]; 
    for(int i = 1; i < 5; i++){
        if(menor > vet[i]){
            menor = vet[i];
        }
    }
    return menor;
}

int media_de_valores_de_vetor(int vet[5]){
    int soma = 0;
    for(int i = 0; i < 5; i++){
        soma += vet[i];
    }
    return soma / 5; 
}

int valores_maiores_que_a_media(int vet[5], int media){
    int quantidade = 0; 
    for(int i = 0; i < 5; i++){
        if(vet[i] > media){
            quantidade++;
        }
    }
    return quantidade;
}

void tela_geral(){
    int valor_de_selecao = 0;
    int vetor[5]; 
    int media;
    int vetor_preenchido = 0;

    while (1) {  
        printf("\nVoce gostaria de acessar:\n");
        printf("1 - Ler vetor\n");
        printf("2 - Inverter vetor\n");
        printf("3 - Ordenar o vetor\n");
        printf("4 - Maior valor do vetor\n");
        printf("5 - Menor valor do vetor\n");
        printf("6 - Media dos valores\n");
        printf("7 - Valores maiores que a media\n");
        printf("0 - Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &valor_de_selecao); 

        switch (valor_de_selecao){
        case 1:
            le_vetor_de_inteiros(vetor);
            vetor_preenchido = 1;  
            break;
        case 2:
            if (vetor_preenchido) {
                inverte_vetor(vetor);
            } else {
                printf("O vetor ainda nao foi preenchido.\n");
            }
            break;
        case 3:
            if (vetor_preenchido) {
                ordenar_vetor(vetor);
            } else {
                printf("O vetor ainda nao foi preenchido.\n");
            }
            break;
        case 4:
            if (vetor_preenchido) {
                printf("Maior valor: %d\n", maior_valor_do_vetor(vetor));
            } else {
                printf("O vetor ainda nao foi preenchido.\n");
            }
            break;
        case 5:
            if (vetor_preenchido) {
                printf("Menor valor: %d\n", menor_valor_do_vetor(vetor));
            } else {
                printf("O vetor ainda nao foi preenchido.\n");
            }
            break;
        case 6:
            if (vetor_preenchido) {
                media = media_de_valores_de_vetor(vetor);
                printf("Media: %d\n", media);
            } else {
                printf("O vetor ainda nao foi preenchido.\n");
            }
            break;
        case 7:
            if (vetor_preenchido) {
                media = media_de_valores_de_vetor(vetor); 
                printf("Valores maiores que a media: %d\n", valores_maiores_que_a_media(vetor, media));
            } else {
                printf("O vetor ainda nao foi preenchido.\n");
            }
            break;
        case 0:
            printf("Encerrando o programa...\n");
            return; 
        default:
            printf("Opcao invalida!\n");
            break;
        }
    }
}

int main(){
    tela_geral();
    return 0;
}

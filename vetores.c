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

    printf("Voce gostaria de acessar:\n");
    printf("ler vetor (1)\n");
    printf("inverter vetor (2)\n");
    printf("ordenar o vetor (3)\n");
    printf("maior valor do vetor (4)\n");
    printf("menor valor do vetor (5)\n");
    printf("media dos valores (6)\n");
    printf("valores maiores que a media (7)\n");

    scanf("%d", &valor_de_selecao); 

    switch (valor_de_selecao){
    case 1:
        le_vetor_de_inteiros(vetor);
        break;
    case 2:
        inverte_vetor(vetor);
        break;
    case 3:
        ordenar_vetor(vetor);
        break;
    case 4:
        printf("Maior valor: %d\n", maior_valor_do_vetor(vetor));
        break;
    case 5:
        printf("Menor valor: %d\n", menor_valor_do_vetor(vetor));
        break;
    case 6:
        media = media_de_valores_de_vetor(vetor);
        printf("Media: %d\n", media);
        break;
    case 7:
        media = media_de_valores_de_vetor(vetor); 
        printf("Valores maiores que a media: %d\n", valores_maiores_que_a_media(vetor, media));
        break;
    default:
        printf("Opcao invalida!\n");
        break;
    }
}

int main(){
    tela_geral();
    return 0;
}

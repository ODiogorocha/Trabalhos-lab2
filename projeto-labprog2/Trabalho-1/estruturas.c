#include<stdio.h>
#include<stdlib.h>

struct usuarios{
    int idade;
    int qtdade;
};
typedef struct usuarios Usuario;

void leVetor (int tamanho, Usuario* vet){
    for(int i = 0; i < tamanho; i++){
        printf("Digite a idade do leitor: \n");
        scanf("%d", &vet[i].idade);
        printf("Digite a quantidade de livros lido por esse usuario:\n");
        scanf("%d", &vet[i].qtdade);
    }
}

int calculaQtidadeLivros (int tamanho, Usuario* vet){
    int total_de_livros = 0;
    for(int i = 0; i < tamanho; i++){
        if(vet[i].idade < 18 ){
            total_de_livros += vet[i].idade;
        }
    }
    return total_de_livros;
}

float calculaMedia (int tamanho, Usuario* vet){
    float total_de_livros = 0;
    for(int i = 0; i < tamanho; i++){
        total_de_livros += vet[i].qtdade;
    }
    return total_de_livros / tamanho;
}


int main(){
    int tamanho = 5;
    Usuario usuarios[tamanho];

    leVetor(tamanho, usuarios);

    int total_de_livros_lidos_menores_18 = calculaQtidadeLivros(tamanho, usuarios);
    float media_de_livros = calculaMedia(tamanho, usuarios);
    
    printf("Aquantidade de livros lidos por entrevistados menores de 18 anos foi: %d \n", total_de_livros_lidos_menores_18);
    printf("A media de livros lidos pelos entrevistados: %d \n", media_de_livros);
    return 0;
}

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
        scanf("%d", &vet.idade);
        printf("Digite a quantidade de livros lido por esse usuario:\n");
        scanf("%d", &vet.qtdade);
    }
}

int calculaQtidadeLivros (int tamanho, Usuario* vet){

}

float calculaMedia (int tamanho, Usuario* vet){

}


int main(){
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

void selecao(){
    float p1;
    float p2;
    float nota3;
    float media_recuperada;
    float media;

    printf("Escreva a nota da primeira prova:\n");
    scanf("%f", &p1);
    printf("Escreva a nota da segunda prova:\n");
    scanf("%f",&p2);

     media = (p1 + p2) / 2;

    if(media < 5 || p1 <= 3 || p2 <= 3){
        printf("Escreva a nota da terceira prova:\n");
        scanf("%f",&nota3);

         media_recuperada = (media + nota3) / 2;
        
        if(media_recuperada >= 7){
            printf("A media geral e %.2f e o aluno esta:APROVADO\n", media_recuperada);
        }else{
            printf("A media geral e %.2f e o aluno esta:REPROVADO\n", media_recuperada);
        }
    }else{
        printf("A media geral e %.2f e o aluno esta:APROVADO\n", media);
    }
}

int main(){
selecao();
}
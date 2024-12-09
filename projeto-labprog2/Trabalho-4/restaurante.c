#include <stdio.h>
#include <stdlib.h>
#include "restaurante.h"
#include "fila.h"
#include "pilha.h"

Mesa** inicializar_mesa(int linhas, int colunas){
    Mesa **mesas = (Mesa**)malloc(linhas * sizeof(Mesa*));
    int numeroMesa = 1;
    for (int i = 0; i < linhas; i++) {
        mesas[i] = (Mesa*)malloc(colunas * sizeof(Mesa));
        for (int j = 0; j < colunas; j++) {
            mesas[i][j].numero_mesa = numeroMesa;
            mesas[i][j].ocupada = false;
            mesas[i][j].numero_pessoas = 0;
            mesas[i][j].numero_pratos = 4;
            mesas[i][j].comanda = mesas[i][j].numero_mesa;
            numeroMesa++;
        }
    }
    return mesas;
}

void liberar_mesa(Mesa **mesa, int numeroMesa, int numLinhas, int numColunas, Pilha** pratos) {
    for (int i = 0; i < numLinhas; i++) {
        for (int j = 0; j < numColunas; j++) {
            if (mesa[i][j].numero_mesa == numeroMesa && mesa[i][j].ocupada) {
                mesa[i][j].ocupada = false;
                empilhar(pratos, mesa[i][j].numero_pratos);
                mesa[i][j].numero_pratos = 0;
                mesa[i][j].numero_pessoas = 0;
                
                printf("Mesa %d liberada.\n", numeroMesa);

                return;
            }
        }
    }

    printf("Mesa %d já está livre ou não existe.\n", numeroMesa);
}

void imprimir_mesas(Mesa **mesas, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {

            printf("Mesa %d: %s, %d pessoas, comanda %d\n",
            mesas[i][j].numero_mesa,
            mesas[i][j].ocupada ? "Ocupada" : "Livre", // ? simplificacao de um if else condição ? valor_se_verdadeiro : valor_se_falso;
            mesas[i][j].numero_pessoas,
            mesas[i][j].comanda);
        }
    }
}

void preencheMesa(Mesa** mesas, Fila** filaEspera, int linhas, int colunas, Pilha** pilhaPratos) {
    if (filaEspera == NULL) {
        return;
    }
    bool teste = false;
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++) {
            if (!mesas[i][j].ocupada) {
                Grupo* grupoPessoas = remover_grupo(filaEspera);
                if (grupoPessoas == NULL) {
                    teste = true;
                    break;
                }
                mesas[i][j].numero_pessoas = grupoPessoas->numero_pessoas;
                if(mesas[i][j].numero_pratos > mesas[i][j].numero_pessoas) {
                    empilhar(pilhaPratos, (mesas[i][j].numero_pratos - mesas[i][j].numero_pessoas));
                    mesas[i][j].numero_pratos = mesas[i][j].numero_pessoas;
                } else if (mesas[i][j].numero_pratos < mesas[i][j].numero_pessoas) {
                    desempilhar(pilhaPratos, (mesas[i][j].numero_pessoas - mesas[i][j].numero_pratos));
                    mesas[i][j].numero_pratos = mesas[i][j].numero_pessoas;
                }
                mesas[i][j].ocupada = true;
            }
            if (teste){break;}
        }
        if (teste){break;}
    }
}

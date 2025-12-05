#include<stdio.h>
#include<stdlib.h>
#include"matriz.h"
typedef struct matriz {
    int linhas; /// defini quantos vetores tem
    int colunas; // defini o tam vet
    int** vetores;/// acessa os vetores
} Matriz;

Matriz* criaMatriz(int linhas, int colunas){

    Matriz* m = malloc(sizeof(Matriz));
    if (m == NULL) {
        return NULL;
    }
    m->linhas = linhas;
    m->colunas = colunas;

    m->vetores = malloc(linhas * sizeof(int*));
    if (m->vetores == NULL) {
        free(m);
        return NULL;
    }

    for (int i = 0; i < linhas; i++) {
        m->vetores[i] = malloc(colunas * sizeof(int));
        if (m->vetores[i] == NULL) {
            // libera o que já foi alocado
            for (int j = 0; j < i; j++) {
                free(m->vetores[j]);
            }
            free(m->vetores);
            free(m);
            return NULL;
        }
    }

    return m;
}
void liberaMatriz(Matriz* m){
    int linha, coluna;
    linha= m->linhas;
    coluna= m->colunas;

    for(int i=0;i<linha;i++){
        free(m->vetores[i]);
    }
    free(m->vetores);
    free(m);
}
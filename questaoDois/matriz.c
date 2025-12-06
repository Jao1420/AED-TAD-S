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
Matriz* somaMatrizes(Matriz* m, Matriz*n){
    int linhas, colunas;
    linhas= m->linhas;
    colunas=m->colunas;
    //para a resultado
    Matriz * resultado=criaMatriz(linhas,colunas);
    resultado->linhas=linhas;
    resultado->colunas=colunas;
    //supondo que o user sabe os pré requisitos 
    int soma=0;
    //anda os vetores 
    for(int i=0; i<linhas; i++){
        // anda os inidices dos vetoress
        for (int j=0;j<colunas;j++){
            soma =  m->vetores[i][j] + n->vetores[i][j];
            resultado->vetores[i][j]=soma;
            soma=0;
        }
    }
    return resultado;
}
Matriz* subtraiMatrizes(Matriz* m, Matriz*n){
    int linhas, colunas;
    linhas= m->linhas;
    colunas=m->colunas;
    //para a resultado
    Matriz * resultado=criaMatriz(linhas,colunas);
    resultado->linhas=linhas;
    resultado->colunas=colunas;
    //supondo que o user sabe os pré requisitos 
    int subtrai=0;
    //anda os vetores 
    for(int i=0; i<linhas; i++){
        // anda os inidices dos vetoress
        for (int j=0;j<colunas;j++){
            subtrai =  m->vetores[i][j] - n->vetores[i][j];
            resultado->vetores[i][j]=subtrai;
            subtrai=0;
        }
    }
    return resultado;
}
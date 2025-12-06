#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include"matriz.h"
typedef struct matriz {
    int linhas; /// defini quantos vetores tem
    int colunas; // defini o tam vet
    int** vetores;/// acessa os vetores
} Matriz;

static int gerador_inicializado = 0;

Matriz* criaMatrizRandom(int linhas, int colunas) {
    
    // Inicializa o gerador de números aleatórios APENAS UMA VEZ
    if (!gerador_inicializado) {
        srand(time(NULL)); 
        gerador_inicializado = 1;
    }
    
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

    // Alocação das colunas (linhas)
    for (int i = 0; i < linhas; i++) {
        m->vetores[i] = malloc(colunas * sizeof(int));
        if (m->vetores[i] == NULL) {
            // Liberação em caso de falha
            for (int j = 0; j < i; j++) {
                free(m->vetores[j]);
            }
            free(m->vetores);
            free(m);
            return NULL;
        }
    }
    
    // SUBSTITUIÇÃO: Preenchendo com números aleatórios (entre 1 e 100)
    int MIN = 1;
    int MAX = 100;
    int amplitude = MAX - MIN + 1;

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            // Fórmula: (rand() % Amplitude) + Mínimo
            m->vetores[i][j] = (rand() % amplitude) + MIN;
        }
    }
    
    return m;
}

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
    // criando com 0 
    for (int i=0;i<linhas;i++){
        for (int j=0; j<colunas; j++){
            m->vetores[i][j]=0;
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

Matriz* multiplicaMatrizes(Matriz*m, Matriz* n){
    int colunaA,LinhaA;
    int colunaB,linhaB;
    colunaA= m->colunas;
    LinhaA= m->linhas;
    colunaB= n->colunas;
    linhaB= n->linhas;

    if(colunaA!=linhaB){
        return NULL;
    }
    Matriz * resultado=criaMatriz(LinhaA,colunaB);
    for (int i = 0; i < LinhaA; i++) {
        // Colunas da Matriz Resultado (0 até colunaB - 1)
        for (int j = 0; j < colunaB; j++) {
            int soma = 0;
            //  Somatório dos produtos (0 até K - 1)
            for (int k = 0; k < colunaA; k++) {
                // Cálculo: soma += M[i][k] * N[k][j]
                soma += m->vetores[i][k] * n->vetores[k][j];
            }
            resultado->vetores[i][j] = soma;
        }
    }
    return resultado;
}

void imprimeMatDiagonal(Matriz *m){
    int linhas, colunas;
    linhas= m->linhas;
    colunas=m->colunas;

    for(int i=0; i<linhas ;i++){
        for(int j=0; j<colunas;j++){
            if(i==j){
                printf("%d ", m->vetores[i][j]);
            }
        }
    }
    printf("\n");
}

void imprimeMat(Matriz *m){
     int linhas, colunas;
    linhas= m->linhas;
    colunas=m->colunas;

    for(int i=0; i<linhas ;i++){
        for(int j=0; j<colunas;j++){
         printf("%2d ", m->vetores[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
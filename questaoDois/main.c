#include <stdio.h>
#include "matriz.h"
#include <time.h>

int main(void) {

    // Cria matriz 3x3 zerada
    Matriz* primeira = criaMatriz(3, 3);

    // Cria matrizes com números aleatórios
    Matriz* aMultiplica = criaMatrizRandom(2, 4);
    Matriz* bMultiplica = criaMatrizRandom(4, 2);
    Matriz* cSoma       = criaMatrizRandom(5, 5);
    Matriz* dSoma       = criaMatrizRandom(5, 5);

    printf("===== Multiplica =====\n");
    imprimeMat(aMultiplica);
    imprimeMat(bMultiplica);

    // Multiplicação → cria nova matriz
    Matriz* resultMulti = multiplicaMatrizes(aMultiplica, bMultiplica);
    printf("resultado da multiplicacao:\n");
    imprimeMat(resultMulti);

    printf("===== Soma =====\n");
    imprimeMat(cSoma);
    imprimeMat(dSoma);
    // Soma → cria nova matriz
    Matriz* resultSoma = somaMatrizes(cSoma, dSoma);
    printf("resultado da soma:\n");
    imprimeMat(resultSoma);

    
    printf("===== Diagonais =====\n");
    // Apenas imprime as diagonais
    printf("Diagonal da matriz A Multiplica:\n");
    imprimeMatDiagonal(aMultiplica);

    printf("Diagonal da matriz B Multiplica:\n");
    imprimeMatDiagonal(bMultiplica);
    
    printf("Diagonal da matriz C Soma:\n");
    imprimeMatDiagonal(cSoma);

    printf("Diagonal da matriz D Soma:\n");
    imprimeMatDiagonal(dSoma);

    // Libera todas as matrizes criadas
    liberaMatriz(resultMulti);
    liberaMatriz(resultSoma);
    liberaMatriz(aMultiplica);
    liberaMatriz(bMultiplica);
    liberaMatriz(cSoma);
    liberaMatriz(dSoma);
    liberaMatriz(primeira);

    return 0;
}

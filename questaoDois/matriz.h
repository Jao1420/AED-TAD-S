#pragma once
typedef struct matriz Matriz;

Matriz* criaMatriz(int linhas, int colunas);
Matriz* criaMatrizRandom(int linhas, int colunas);
void liberaMatriz(Matriz* m);
Matriz* preencheMatriz(Matriz* m);
Matriz* somaMatrizes(Matriz* m, Matriz*n);
Matriz* subtraiMatrizes(Matriz* m, Matriz*n);
Matriz* multiplicaMatrizes(Matriz* m, Matriz*n);
void imprimeMat(Matriz *m);
void imprimeMatDiagonal(Matriz *m);

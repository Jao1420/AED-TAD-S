#include "frac.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct frac{
    int numerador;
    int denominador;
}Frac;

void imprime(Frac* f){
    if (f == NULL){
        printf("Fração inválida!\n");
        return;
    }
    printf("%d/%d\n", f->numerador, f->denominador);
}

Frac* criaFracao(int a, int b){
    Frac* retorno;
    retorno = malloc(sizeof (Frac));
    if( retorno==NULL){
        return NULL;
    }
    retorno->numerador=a;
    retorno->denominador=b;
    return retorno;
}

void liberaFracao(Frac* liberar){
    free(liberar);
    liberar=NULL;
}

int mdcfracao(int a, int b){
    int auxA = (int)fabs((double)a);
    int auxB = (int)fabs((double)b);
    
    while (auxB != 0) {
        int temp = auxB;
        auxB = auxA % auxB;
        auxA = temp;
    }
    return auxA;
}

void simplificaFracao(Frac* a){
    if (a->numerador == 0) {
        a->denominador = 1;
        return;
    }
    int mdc= mdcfracao(a->numerador,a->denominador);
    a->numerador/= mdc;
    a->denominador/= mdc;
    if (a->denominador < 0) {
        a->numerador *= -1;
        a->denominador *= -1;
    }

}


Frac* somaFracao(Frac* a, Frac* b){
    Frac* aux=criaFracao(0,0);
    Frac* result=criaFracao(0,0);

    if(a->denominador == b->denominador){
        result->numerador=a->numerador +b->numerador;
        result->denominador= a->denominador;
        simplificaFracao(result);
        liberaFracao(aux);
        return result;
    }else{
        // acha denominador comum
        result->denominador=a->denominador*b->denominador;
        // achando o numerador
        aux->numerador= b->denominador *a->numerador;
        aux->numerador+= a->denominador *b->numerador;
        // atribuindo para o retorno
        result->numerador = aux->numerador;
        simplificaFracao(result);
        liberaFracao(aux);
        return result;
    }
}
Frac* subtraiFracao(Frac* a, Frac* b){
    Frac* result=criaFracao(0,0);
    if(a->denominador == b->denominador){
        result->numerador=a->numerador -b->numerador;
        result->denominador= a->denominador;
        simplificaFracao(result);
        return result;
    }else{
        Frac* aux=criaFracao(0,0);

        result->denominador= a->denominador * b->denominador;
        // achando o numerador
        aux->numerador= b->denominador *a->numerador;
        aux->numerador-= a->denominador *b->numerador;

        result->numerador = aux->numerador;
        simplificaFracao(result);
        liberaFracao(aux);
        return result;
    }
}

Frac* multiplicaFracao(Frac* a, Frac* b){
    int novoNum = a->numerador * b->numerador;
    int novoDen = a->denominador * b->denominador;

    Frac* result = criaFracao(novoNum, novoDen);
    return result;
}

Frac* divideFracao(Frac* a, Frac* b){
    if (b->numerador == 0) return NULL;

    int novoNum = a->numerador * b->denominador;
    int novoDen = a->denominador * b->numerador;

    Frac* result = criaFracao(novoNum, novoDen);
    return result;
}

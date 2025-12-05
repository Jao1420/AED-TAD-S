#include <stdio.h>
#include "frac.h"

int main(){
    Frac* fracaoUm = criaFracao(1, 2);   // 1/2
    Frac* fracaoDois = criaFracao(3, 4);   // 3/4

    printf("fracao Um = ");
    imprime(fracaoUm);

    printf("fracao Dois = ");
    imprime(fracaoDois);

    printf("\n=== SOMA ===\n");
    Frac* s = somaFracao(fracaoUm, fracaoDois);
    imprime(s);

    printf("\n=== SUBTRACAO ===\n");
    Frac* sub = subtraiFracao(fracaoUm, fracaoDois);
    imprime(sub);

    printf("\n=== MULTIPLICACAO ===\n");
    Frac* m = multiplicaFracao(fracaoUm, fracaoDois);
    imprime(m);

    printf("\n=== DIVISÃO ===\n");
    Frac* d = divideFracao(fracaoUm, fracaoDois);
    imprime(d);

    // Libera tudo
    liberaFracao(fracaoUm);
    liberaFracao(fracaoDois);
    liberaFracao(s);
    liberaFracao(sub);
    liberaFracao(m);
    liberaFracao(d);

    return 0;
}

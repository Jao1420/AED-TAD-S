typedef struct frac Frac;

Frac* criaFracao(int a, int b);
void liberaFracao(Frac* a);
void imprime(Frac* f);
Frac* somaFracao(Frac* a, Frac* b);
Frac* subtraiFracao(Frac* a, Frac* b);
Frac* multiplicaFracao(Frac* a, Frac* b);
Frac* divideFracao(Frac* a, Frac* b);
int mdcfracao(int a, int b);
void simplificaFracao(Frac* a);

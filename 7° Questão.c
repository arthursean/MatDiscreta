#include <stdio.h>
int extendedEuclid(int a, int b, int *s, int *t) {
    if (b == 0) {
        *s = 1;
        *t = 0;
        return a;
    }
    int s1, t1;
    int mdc = extendedEuclid(b, a % b, &s1, &t1);
    *s = t1;
    *t = s1 - (a / b) * t1;
    return mdc;
}

// Função que retorna o inverso de a módulo b, ou -1 se o inverso não existir
int inverseMod(int a, int m) {
    int s, t;
    int mdc = extendedEuclid(a, m, &s, &t);
    if (mdc != 1) {
        return -1; // inverso não existe
    }
    return (s % m + m) % m; // retorna o inverso
}

int main() {
    int a, m;
    printf("Digite o valor de a: ");
    scanf("%d", &a);
    printf("Digite o valor de m: ");
    scanf("%d", &m);
    int inv = inverseMod(a, m);
    if (inv == -1) {
        printf("O inverso de %d módulo %d não existe.\n", a, m);
    } else {
        printf("O inverso de %d módulo %d é %d.\n", a, m, inv);
    }
    return 0;
}

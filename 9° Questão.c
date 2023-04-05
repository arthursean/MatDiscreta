#include <stdio.h>
int mdc(int a, int b) {
    if (b == 0) {
        return a;
    }
    return mdc(b, a % b);
}

int euclides_extendido(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    int x1, y1;
    int mdc = euclides_extendido(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;
    return mdc;
}

int inverso_modulo(int a, int m) {
    int x, y;
    int mdc = euclides_extendido(a, m, &x, &y);
    if (mdc != 1) {
        return -1; // a e m nao sao coprimos
    }
    return (x % m + m) % m;
}

int teorema_chines(int b1, int m1, int b2, int m2, int b3, int m3) {
    int M = m1 * m2 * m3;
    int x = b1 * inverso_modulo(M / m1, m1) * M / m1+
            b2 * inverso_modulo(M / m2, m2) * M/m2 +
            b3 * inverso_modulo(M / m3, m3) * M/m3;
    return x % M;
}

int main() {
    int a1,b1, b2, b3, m1, m2, m3;
    printf("Digite as tres congruencias no formato 'ax = b (mod m)':\n");
    scanf("%d x = %d (mod %d)", &a1, &b1, &m1);
    scanf("%d x = %d (mod %d)", &a1, &b2, &m2);
    scanf("%d x = %d (mod %d)", &a1, &b3, &m3);

    if (mdc(m1, m2) != 1 || mdc(m1, m3) != 1 || mdc(m2, m3) != 1) {
        printf("Os modulos nao sao coprimos. Nao ha solucao unica.\n");
        return 0;
    }

    int x = teorema_chines(b1, m1, b2, m2, b3, m3);
    printf("A solucao unica da congruencia eh: %d\n", x);

    return 0;
}

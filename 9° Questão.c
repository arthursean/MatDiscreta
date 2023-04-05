#include <stdio.h>
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int extended_euclidean(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extended_euclidean(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;
    return gcd;
}

int mod_inverse(int a, int m) {
    int x, y;
    int gcd = extended_euclidean(a, m, &x, &y);
    if (gcd != 1) {
        return -1; // a e m nao sao coprimos
    }
    return (x % m + m) % m;
}

int chinese_remainder(int b1, int m1, int b2, int m2, int b3, int m3) {
    int M = m1 * m2 * m3;
    int x = b1 * mod_inverse(M / m1, m1) * M / m1+
            b2 * mod_inverse(M / m2, m2) * M/m2 +
            b3 * mod_inverse(M / m3, m3) * M/m3;
    return x % M;
}

int main() {
    int a1,b1, b2, b3, m1, m2, m3;
    printf("Digite as tres congruencias no formato 'ax = b (mod m)':\n");
    scanf("%d x = %d (mod %d)", &a1, &b1, &m1);
    scanf("%d x = %d (mod %d)", &a1, &b2, &m2);
    scanf("%d x = %d (mod %d)", &a1, &b3, &m3);

    if (gcd(m1, gcd(m2, m3)) != 1) {
        printf("Os modulos nao sao coprimos. Nao ha solucao unica.\n");
        return 0;
    }

    int x = chinese_remainder(b1, m1, b2, m2, b3, m3);
    printf("A solucao unica da congruencia eh: %d\n", x);

    return 0;
}

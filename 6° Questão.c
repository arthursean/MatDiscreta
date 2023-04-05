#include <stdio.h>
int gcd(int a, int b, int *s, int *t) {
    if (a == 0) {
        *s = 0;
        *t = 1;
        return b;
    }

    int s1, t1;
    int d = gcd(b % a, a, &s1, &t1);

    *s = t1 - (b / a) * s1;
    *t = s1;

    return d;
}

int main() {
    int a, b;
    printf("Digite dois números inteiros: ");
    scanf("%d %d", &a, &b);

    int s, t;
    int d = gcd(a, b, &s, &t);

    printf("mdc(%d, %d) = %d = %d * %d + %d * %d\n", a, b, d, s, a, t, b);
    printf("\ns = %d\nt = %d", s, t);

    return 0;
}

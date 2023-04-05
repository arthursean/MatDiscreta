int mdc(int a, int b, int *s, int *t) {
    if (b == 0) {
        *s = 1;
        *t = 0;
        return a;
    }
    int s1, t1;
    int d = mdc(b, a % b, &s1, &t1);
    *s = t1;
    *t = s1 - (a / b) * t1;
    return d;
}

int inverso(int a, int m) {
    int s, t;
    int d = mdc(a, m, &s, &t);
    if (d != 1) {
        printf("A congruência não tem solução inteira.\n");
        return -1;
    } else {
        return (s % m + m) % m;
    }
}

int main() {
    int a, b, m;
    printf("Entre com os valores de a, b e m na congruência ax ≡ b mod m: ");
    scanf("%d %d %d", &a, &b, &m);
    int inv = inverso(a, m);
    if (inv != -1) {
        printf("A solução da congruência é x = %d.\n", (b * inv) % m);
    }
    return 0;
}

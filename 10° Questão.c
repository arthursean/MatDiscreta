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

int teorema_chines(int b[], int m[], int n) {
    int M = 1, i;
    for(int i=0; i<n; i++)
    {
        M *= m[i];
    }

    int x;
    for(int i=0; i<n; i++)
    {
        x += b[i] * inverso_modulo(M / m[i], m[i]) * M / m[i];
    }
    return x % M;
}

int main() {
    
    int n, i;
    printf("Digite o numero de congruencias:\n");
    scanf("%d", &n);

    int a1,b[n], m[n];
    
    printf("Digite as tres congruencias no formato 'ax = b (mod m)':\n");
    for(i=0; i<n; i++)
    {
        scanf("%d x = %d (mod %d)", &a1, &b[i], &m[i]);
    }

    int j;

    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if (mdc(m[i], m[j]) != 1) {
                printf("Os modulos nao sao coprimos. Nao ha solucao unica.\n");
                return 0;
            }
        }
    }

    int x = teorema_chines(b[n], m[n] , n);
    printf("A solucao unica da congruencia eh: %d\n", x);

    return 0;
}
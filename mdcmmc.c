#include <stdio.h>
int mdc(int a, int b, int x, int resultado)
{
    if (x > b || x > a)
    {
        printf("MDC:%d\n", resultado);
        return 0;
    }
    if (a % x == 0 && b % x == 0)
    {
        resultado = resultado * x;
        return mdc(a / x, b / x, x, resultado);
    }
    else
    {
        return mdc(a, b, x + 1, resultado);
    }
}
int mmc(int a, int b, int i, int valor)
{
    if (a == 1 && b == 1)
    {
        printf("MMC:%d\n", valor);
        return 0;
    }
    else
    {
        if (a % i == 0 && b % i == 0)
        {
            valor = valor * i;
            return mmc(a / i, b / i, i, valor);
        }
        else if (a % i == 0)
        {
            valor = valor * i;
            return mmc(a / i, b, i, valor);
        }
        else if (b % i == 0)
        {
            valor = valor * i;
            return mmc(a, b / i, i, valor);
        }
        else
        {
            return mmc(a, b, i + 1, valor);
        }
    }
}
int main()
{
    int a, b;
    printf("Digite o primeiro número:");
    scanf("%d", &a);
    printf("Digite o segundo número:");
    scanf("%d", &b);
    mdc(a, b, 2, 1);
    mmc(a, b, 2, 1);
    return 0;
}
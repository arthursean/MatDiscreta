#include <stdio.h>

int coprimo(int a, int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        if (a % n == 0)
        {
            return coprimo(a, n - 1);
        }
        else
        {
            printf("%d\n", n);
            return coprimo(a, n - 1);
        }
    }
}

int main()
{
    int a;
    printf("Digite um numero:");
    scanf("%d", &a);
    printf("Esses são os coprimos de:%d\n", a);
    coprimo(a, a);
    return 0;
}
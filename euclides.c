#include <stdio.h>

int euclides(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return euclides(b, a % b);
    }
}
int main()
{
    int a, b;
    printf("Digite o primeiro número:");
    scanf("%d", &a);
    printf("Digite o segundo número:");
    scanf("%d", &b);
    printf("%d\n", euclides(a, b));
    return 0;
}
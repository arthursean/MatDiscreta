#include <stdio.h>

int decompor(long int a, long int b)
{
    if (a >= 1)
    {
        if (a / b == 1 && a % b == 0)
        {
            printf("%ld", a);
            return 0;
        }
        else if (a % b == 0)
        {
            printf("%ld*", b);
            return decompor(a / b, b);
        }
        else
        {
            return decompor(a, b + 1);
        }
    }
}
int main()
{
    long int a;
    printf("Digite um número:");
    scanf("%ld", &a);
    decompor(a, 2);
    return 0;
}

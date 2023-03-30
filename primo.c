#include <stdio.h>
int primo(int a, int div, int i)
{
    if (i > a)
    {
        if (div == 2)
        {
            printf("É primo\n");
            return 0;
        }
        else
        {
            printf("Não é primo\n");
            return 0;
        }
    }
    else
    {
        if (a % i == 0)
        {
            return primo(a, div + 1, i + 1);
        }
        else
        {
            return primo(a, div, i + 1);
        }
    }
}
int main()
{
    int a;
    scanf("%d", &a);
    primo(a, 0, 1);
    return 0;
}
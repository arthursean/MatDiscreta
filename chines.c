#include <stdio.h>

// Função para calcular o inverso modular de a mod m
int modular_inverse(int a, int m)
{
    int m0 = m, s = 0, t = 1, num, q;
 
    if (m == 1)
        return 0;
 
    while (m)
    {
        q = a / m;
        num = m;
        m = a % m, a = num;
        num = s;
        s = t - q * s;
        t = num;
    }
 
    if (s < 0)
        s += m0;
    
    while(s<=0)
    {
        s+=m0;
    }
    return s;
}

// Função para verificar se um número é primo
int coprimo(int a, int b){
    if(b==0)
    {
        return a;
    }
    else
    {
        return coprimo(b, a%b);
    }
}

// Função para calcular a solução usando o Teorema Chinês do Resto
int chinese_remainder(int a[], int m[], int n)
{
    int indice, nzao = 1, sum = 0, p;

    // Calcular a multiplicação de todos os valores de m
    for (indice = 0; indice < n; indice++) {
        nzao = nzao * m[indice];
    }

    // Calcula a solução
    for (indice = 0; indice < n; indice++) {
        p = nzao / m[indice];
        sum += a[indice] * modular_inverse(p, m[indice]) * p;
    }

    return sum % nzao;
}

int main()
{
    int a[3], m[3], indice;

    printf("Digite as tres congruencias (no formato x = a[i] (mod m[i])), com 'i' sendo indice:\n");

    for (indice = 0; indice < 3; indice++) {
        printf("a[valor da %d congruencia(s)] = \n", indice+1);
        scanf("%d", &a[indice]);
        printf("m[valor da %d congruencia(s)] = \n", indice+1);
        scanf("%d", &m[indice]);
    }


    // Verifica se todos os valores de m são primos
    if (!coprimo(coprimo(m[indice], m[indice+1]), m[indice+2])) {
        printf("Os modulos devem ser primos entre si!\n");
        return 0;
    }

    printf("A solucao unica das tres congruencias eh: %d\n", chinese_remainder(a, m, 3));

    return 0;
}
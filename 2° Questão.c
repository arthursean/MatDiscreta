#include <stdio.h>
#include <time.h>
int main()
{
    time_t init_time = time(NULL);
    long long int num = 3;
    int div;

    while (time(NULL) < init_time + 60)
    {
        div = 0;
        for (int i = 1; i <= num / 3; i = i + 2)
        {
            if (num % i == 0)
            {
                div++;
            }
        }
        if (div == 1)
        {
            printf("%lld\n", num);
            num = num + 2;
        }
        else
        {
            num = num + 2;
        }
    }
    return 0;
}

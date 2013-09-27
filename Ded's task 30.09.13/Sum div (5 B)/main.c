#include <stdio.h>
#include <stdlib.h>

unsigned int sum_div(unsigned int n)
{
    unsigned int res = 0;

    for(unsigned int i = 1; i*i <= n; i++)
    {
        if (n % i == 0)
        {
            res += (i + n / i);
        }
    }

    return res;
}

int main()
{
    unsigned int n = 0;
    scanf("%u", &n);

    unsigned int res = sum_div(n);

    printf("%u", res);

    return 0;
}

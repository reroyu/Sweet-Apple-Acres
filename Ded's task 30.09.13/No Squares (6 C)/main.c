#include <stdio.h>
#include <stdlib.h>

int has_square(unsigned int x);

int main()
{
    int n = 0;
    scanf("%d", &n);

    unsigned int x = 0;

    for(int i = 0; i < n; i++)
    {
        scanf("%u", &x);
        if (!has_square(x))
            printf("%u\t", x);
    }

    return 0;
}

int has_square(unsigned int x)
{
    for(int i = 2; i*i <= x; i++)
    {
        if (x % (i*i) == 0)
            return 1;
    }

    return 0;
}

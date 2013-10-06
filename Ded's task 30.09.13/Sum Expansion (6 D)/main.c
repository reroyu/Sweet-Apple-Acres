#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <assert.h>

#define arrelem(arrname)(n)(m)      arrname[(n) * (n) + (m)]

unsigned int p(int n, int k, unsigned int parray[])
{
    assert(parray);
    assert(k);

    unsigned int * cell = &( arrelem(parray)(n)(k) );

    if (*cell)
        return *cell;

    if (n < k)
        return (*cell = p(n, n, parray));

    return (*cell = p((n - k), k, parray) + p(n, (k - 1), parray));
}

int main()
{
    int n = 0;
    scanf("%d", &n);

    static unsigned int * parray = (unsigned int *)calloc((n + 1) * (n + 1) , sizeof(int));
    for(int i = 0; i < n + 1; i++)
        for(int j = 0; j < n + 1; j++)
        {
            if (((i == 0) && (j != 0)) || (j == 1))
                arrelem(parray)(i)(j) = 1;
            else
                arrelem(parray)(i)(j) = 0;
        }

    printf("%u", p(n, n, parray));

    return 0;
}

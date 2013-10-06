#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <assert.h>

#define NDEBUG 1

#define DEBUG if (0)

unsigned int p(int n, int k, unsigned int * parray, int size)
{
    assert(parray);
    DEBUG {printf("Taking p(%d, %d)\n", n, k);}
    assert(k);

    unsigned int res = 0;

    unsigned int * cell = parray + n * size + k;

    if (*cell)
        return *cell;

    else if (n < k)
        return (*cell = p(n, n, parray, size));

    else
        return (*cell = p((n - k), k, parray, size) + p(n, (k - 1), parray, size));
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    int size = n + 1;

    unsigned int * parray = (unsigned int *)calloc(size * size , sizeof(unsigned int));
    assert(parray);
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
        {
            if (((i == 0) && (j != 0)) || (j == 1))
            {
                *(parray + i * (size) + j) = 1;
            }
            else
            {
                *(parray + i * (size) + j) = 0;
            }
        }

    /*DEBUG
    {
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                printf("[%d][%d]%u\t", i, j, *(parray + i * (size) + j));
            }
            printf("\n");
        }
    }*/

    printf("%u", p(n, n, parray, size));

    free(parray);

    return 0;
}

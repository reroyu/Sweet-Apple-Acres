#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <assert.h>

#define NDEBUG 1

#define DEBUG if (0)

int p(int n, int k, int * parray, int size)
{
    assert(parray);
    DEBUG {printf("Taking p(%d, %d)\n", n, k);}
    assert(k >= 0);

    int * cell = parray + n * size + k;

    if (*cell >= 0)
        return *cell;

    else if (n < k)
        return (*cell = p(n, n, parray, size));

    else
        return (*cell = p((n - k), (k - 1), parray, size) + p(n, (k - 1), parray, size));
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    int size = n + 1;

    int * parray = (int *)calloc(size * size , sizeof(int));
    assert(parray);
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
        {
            if (((i == 0) || (i == 1))  && (j != 0))
            {
                *(parray + i * size + j) = 1;
            }
            else if (j == 0)
            {
                *(parray + i * size + j) = 0;
            }
            else
            {
                *(parray + i * size + j) = -1;
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

    printf("%d", p(n, n, parray, size));

    free(parray);

    return 0;
}

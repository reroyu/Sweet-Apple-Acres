#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned int find_square(unsigned int x);
int expand(unsigned int x, unsigned int* a);

int main()
{
    unsigned int x = 0;
    scanf("%u", &x);
    unsigned int a[4] = {0, 0, 0, 0};

    expand(x, a);

    for(int i = 0; i < 4; i++)
        printf("%u \t", a[i]);

    return 0;
}

int expand(unsigned int x, unsigned int* a)
{
    unsigned int square = 0;
    for(int j = 0; j < 4; j++)
    {
        square = find_square(x);
        *(a + 3 - j) = square;
        x -= square;
    }

    return 0;
}

unsigned int find_square(unsigned int x)
{
    unsigned int i = 0;
    for(i = 0; i*i <= x; i++);
    return (i - 1)*(i - 1);
}

#include <stdio.h>
#include <stdlib.h>

unsigned int min_com_mult(unsigned int x, unsigned int y);
unsigned int max_com_div(unsigned int x, unsigned int y);
int swap(unsigned int* a, unsigned int* b);

int main()
{
    unsigned int a, b, c = 0;
    scanf("%u %u %u", &a, &b, &c);

    //ÍÎÊ(a,b,c) = ÍÎÊ(ÍÎÊ(a,b),c)
    unsigned int res = min_com_mult(min_com_mult(a, b), c);

    printf("%u", res);

    return 0;
}

unsigned int max_com_div(unsigned int x, unsigned int y)
{
    unsigned int a = x; unsigned int b = y;
    if (a < b) swap(&a, &b);
    do
    {
        a -= b;
        if (a < b) swap(&a, &b);
    }
    while(b);

    return a;
}

unsigned int min_com_mult(unsigned int x, unsigned int y)
{
    return x * y / max_com_div(x, y);
}

int swap(unsigned int* a, unsigned int* b)
{
    unsigned int temp = *b;
    *b = *a;
    *a = temp;

    return 0;
}

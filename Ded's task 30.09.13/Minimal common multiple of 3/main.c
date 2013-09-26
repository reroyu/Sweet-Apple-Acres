#include <stdio.h>
#include <stdlib.h>

int min_com_mult(int x, int y);
int max_com_div(int x, int y);
int swap(int* a, int* b);

int main()
{
    int a, b, c = 0;
    scanf("%d %d %d", &a, &b, &c);

    //ÍÎÊ(a,b,c) = ÍÎÊ(ÍÎÊ(a,b),c)
    int res = min_com_mult(min_com_mult(a, b), c);

    printf("%d", res);

    return 0;
}

int max_com_div(int x, int y)
{
    int a = x; int b = y;
    if (a < b) swap(&a, &b);
    do
    {
        a -= b;
        if (a < b) swap(&a, &b);
    }
    while(b);

    return a;
}

int min_com_mult(int x, int y)
{
    return x * y / max_com_div(x, y);
}

int swap(int* a, int* b)
{
    int temp = *b;
    *b = *a;
    *a = temp;

    return 0;
}

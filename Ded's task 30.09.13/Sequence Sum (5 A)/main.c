#include <stdio.h>
#include <stdlib.h>

#define DEBUG if(0)

float seq_sum(int n, float x)
{
    float member = 1;
    float sum = 1;

    for(int k = 1; k <= n; k++)
    {
        DEBUG {printf("k = %d, member = %f, sum = %f \n", k, member, sum);}
        member *= x / k;
        sum += member;
    }

    DEBUG {printf("sum = %f \n", sum);}
    return sum;
}

int main()
{
    int n = 0;
    float x = 0;

    scanf("%d %f", &n, &x);

    DEBUG {printf("n = %d, x = %f \n", n, x);}
    float res = seq_sum(n, x);

    printf("%.6f", res);

    return 0;
}

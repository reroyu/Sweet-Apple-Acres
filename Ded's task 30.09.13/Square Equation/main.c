#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

const int EVIL = 1488;

double solve_square(double a, double b, double c, double* x1, double* x2);

int main()
{

    double a, b, c = EVIL;
    printf("Equation: ax^2 + bx + c = 0.\nPlease, enter a, b, c\n");
    scanf("%lf %lf %lf", &a, &b, &c);

    double x1, x2 = (double)EVIL;

    int num = EVIL;
    num = solve_square(a, b, c, &x1, &x2);

    switch (num)
    {
        case 3: {
                    printf("All real numbers are roots\n");
                    break;
                }
        case 2: {
                    printf("Two roots: %lf, %lf\n", x1, x2);
                    break;
                }
        case 1: {
                    printf("One root: %lf\n", x1);
                    break;
                }
        case 0: {
                    printf("No roots, grustka... :(\n");
                    break;
                }
        default:{
                    printf("Unexpected error, fail! Azazaz )))0)nulik\n num = %d\n", num);
                    break;
                }
    }

    return 0;
}

// Solves square equation ax^2 + bx + c = 0
// Takes a, b, c and two pointers to variables for roots
// Returns number of roots or 3 if all numbers are roots
double solve_square(double a, double b, double c, double* x1, double* x2)
{
    assert(x1); assert(x2);
    assert(x1 != x2);

    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
                return 3;
            else
                return 0;
        }
        else
        {
            *x1 = -c / b;
            return 1;
        }
    }
    else
    {
        double D = b * b - 4 * a * c;
        if (D < 0)
        {
            return 0;
        }
        else
        {
            double DRoot = sqrt(D);
            if (D == 0)
            {
                *x1 = (-b + DRoot) / (2 * a);
                return 1;
            }
            else
            {
                *x1 = (-b + DRoot) / (2 * a);
                *x2 = (-b - DRoot) / (2 * a);
                return 2;
            }
        }
    }
}

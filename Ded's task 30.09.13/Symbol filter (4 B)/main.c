#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int print(int c);

int main()
{
    int c = 0;
    do
    {
        c = getchar();
        print(c);
    }
    while(c != EOF);

    return 0;
}

int print(int c)
{
    if (c != EOF)
    {
        if (ispunct(c))
            ;

        else if (isupper(c))
            putchar(tolower(c));

        else if (isdigit(c))
            putchar('#');

        else if ((c == ' ') || (c == '\t'))
            {
                do
                {
                    c = getchar();
                }
                while((c == ' ') || (c == '\t'));
                putchar(' ');
                print(c);
            }

        else putchar(c);
    }
    else return 1;

    return 0;
}

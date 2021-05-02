#include "fagundez.h"
#include <ctype.h>

int maximum(int a, int b, int c)
{
    int result;
    if (a > b && a > c)
    {
        result = a;
    }
    else
    {
        if (b > c)
        {
            result = b;
        }
        else
        {
            result = c;
        }
    }

    return result;
}

char miToLower(char letra)
{
    if( letra >= 'A' && letra <= 'Z')
    {
        letra+=32;
    }

    return letra;
}

int esPar(int num)
{
    return !(num % 2);
}


void duplicate(int *num)
{
    *num = *num * 2;
}
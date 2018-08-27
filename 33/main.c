//
//  main.c
//  33
//
//  Created by Tyler Niiyama on 12/31/17.
//  Copyright © 2017 Tyler Niiyama. All rights reserved.
//

// https://projecteuler.net/problem=33

#include <stdio.h>
#include <math.h>
#include <float.h>

int is_prime(int x);

int main(void)
{
    for (int i = 10; i < 100; i++)
    {
        // use only prime denominators
        if (is_prime(i) == 0)
        {
            // need numerator of two digits
            for (int j = 10; j < i; j++)
            {
                // check tens place of denominator and ones place of numerator
                if (((int)(i / 10) != 0) && (i % 10 != 0))
                {
                    float fraction = (double) j / i;
                    if (j % 10 == (int)(i / 10))
                    {
                        float reduced = (double)((int)(j / 10)) / (i % 10);
                        // use epsilon to avoid float comparison
                        if (fabs(fraction - reduced) <= FLT_EPSILON)
                        {
                            printf("%i/%i\n", j, i);
                        }
                    }
                    if ((int)(j / 10) == i % 10)
                    {
                        float reduced = (double)(j % 10) / ((int)(i / 10));
                        if (fabs(fraction - reduced) <= FLT_EPSILON)
                        {
                            printf("%i/%i\n", j, i);
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int is_prime(int x)
{
    if (x < 1)
    {
        return 0;
    }
    int k = 1, a = 0, b = 0;
    long n;
    switch(x)
    {
        case 1: return 0;
        case 2: return 1;
        case 3: return 1;
        case 4: return 0;
        case 5: return 1;
        case 6: return 0;
        case 7: return 1;
    }
    if (x % 2 == 0 || x % 3 == 0)
    {
        return 0;
    }
    n = (int) sqrt(x);
    while (b < n)
    {
        a = (6 * k) - 1;
        b = (6 * k) + 1;
        if (x % a == 0 || x % b == 0)
        {
            return 0;
        }
        k++;
    }
    return 1;
}

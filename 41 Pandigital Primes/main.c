//
//  main.c
//  41
//
//  Created by Tyler Niiyama on 1/18/18.
//  Copyright © 2018 Tyler Niiyama. All rights reserved.
//

// Find the largest n-digit pandigital prime

#include <stdio.h>
#include <math.h>

int is_prime(int x);

int main(void)
{
    // b r u t e  f o r c e
    int max = 0;
    for (int a = 1; a < 8; a++)
    {
        for (int b = 1; b < 8; b++)
        {
            if (b != a)
            {
            for (int c = 1; c < 8; c++)
            {
                if (c != a && c != b)
                {
                for (int d = 1; d < 8; d++)
                {
                    if (d != a && d != b && d != c)
                    {
                    for (int e = 1; e < 8; e++)
                    {
                        if (e != a && e != b && e != c && e != d)
                        {
                        for (int f = 1; f < 8; f++)
                        {
                            if (f < 8 && f != a && f != b && f != c && f != d && f != e)
                            {
                            for (int g = 1; g < 8; g++)
                            {
                                if (g != a && g != b && g != c && g != d && g != e && g != f)
                                {
                                int number = g + pow(10, 1) * f + pow(10, 2) * e + pow(10, 3) * d + pow(10, 4) * c + pow(10, 5) * b + pow(10, 6) * a;
                                if (number > max && is_prime(number) == 1)
                                {
                                    max = number;
                                }
                                }
                            }
                            }
                        }
                        }
                    }
                    }
                }
                }
            }
            }
        }
        }
    printf("%i\n", max);
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


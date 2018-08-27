//
//  main.c
//  35
//
//  Created by Tyler Niiyama on 1/15/18.
//  Copyright © 2018 Tyler Niiyama. All rights reserved.
//

// Find the number of circular primes there are below one million

#include <stdio.h>
#include <math.h>

int is_prime(int x);

int main(void)
{
    // problem gives number under 100
    int count = 13;
    int digits = 3;
    for (int i = 100; i < 1000001; i++)
    {
        // keeps track of digits
        if (i >= pow(10, digits))
        {
            digits++;
        }
        if (is_prime(i))
        {
            // rotates digits around
            int number = (i / 10) + ((i % 10) * pow(10, digits - 1));
            while (number != i)
            {
                if (is_prime(number) == 0)
                {
                    break;
                }
                number = (number / 10) + ((number % 10) * pow(10, digits - 1));
            }
            // increases count if passes prime check back to the original num
            if (number == i)
            {
                count++;
                printf("%i\n", number);
            }
        }
    }
    printf("%i\n", count);
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

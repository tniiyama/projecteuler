//
//  main.c
//  37
//
//  Created by Tyler Niiyama on 1/16/18.
//  Copyright © 2018 Tyler Niiyama. All rights reserved.
//

// Find the sum of the only eleven primes that are both truncatable from left to right and right to left

#include <stdio.h>
#include <math.h>

int is_prime(int x);

int main(void)
{
    int sum = 0;
    int digits = 2;
    // assuming max is 1,000,000
    for (int i = 10; i < 1000001; i++)
    {
        // keeps track of digits
        if (i >= pow(10, digits))
        {
            digits++;
        }
        if (is_prime(i) == 1)
        {
            // truncates from the right
            int buffer = i / 10;
            for (int j = 0; j < digits - 1; j++)
            {
                if (is_prime(buffer) == 0)
                {
                    break;
                }
                buffer = buffer / 10;
            }
            // truncates from the left if the other direction passes
            if (buffer == 0)
            {
                buffer = i % (int) pow(10, digits);
                for (int j = digits; j > 0; j--)
                {
                    if (is_prime(buffer) == 0)
                    {
                        break;
                    }
                    buffer = buffer % (int) pow(10, j - 1);
                }
                if (buffer == 0)
                {
                    sum = sum + i;
                    printf("%i\n", i);
                }
            }
        }
    }
    printf("%i\n", sum);
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

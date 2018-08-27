//
//  main.c
//  58
//
//  Created by Tyler Niiyama on 2/16/18.
//  Copyright © 2018 Tyler Niiyama. All rights reserved.
//

// https://projecteuler.net/problem=58

#include <stdio.h>
#include <math.h>

int is_prime(int x);

int main(void)
{
    int primes = 0;
    int total = 1;
    int number = 1;
    int counter = 0;
    int increment = 2;
    while (1)
    {
        number = number + increment;
        if (is_prime(number) == 1)
        {
            primes++;
        }
        total++;
        counter++;
        if (counter % 4 == 0)
        {
            if ((float)primes / (float)total < 0.1)
            {
                break;
            }
            // side length increases by two every four diagonals
            counter = 0;
            increment = increment + 2;
        }
    }
    printf("%i\n", increment + 1);
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

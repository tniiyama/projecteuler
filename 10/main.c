//
//  main.c
//  10
//
//  Created by Tyler Niiyama on 9/23/17.
//  Copyright © 2017 Tyler Niiyama. All rights reserved.
//

// Find the sum of all primes under 2,000,000

#include <stdio.h>
#include <math.h>

int is_prime(int x);

int main(void)
{
    long sum = 0;
    for (int i = 2; i < 2000000; i++)
    {
        if (is_prime(i) == 1)
        {
            sum += i;
        }
    }
    printf("%li\n", sum);
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
        // all primes are in the form 6k+1 or 6k-1, where k is an integer
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

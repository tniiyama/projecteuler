//
//  main.c
//  27
//
//  Created by Tyler Niiyama on 12/31/17.
//  Copyright © 2017 Tyler Niiyama. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int is_prime(int x);

int main(void)
{
    int longest = 0, a = 0, b = 0;
    int primes[1000];
    int index = 0;
    int i = 1;
    while (index < 1000)
    {
        if (is_prime(i))
        {
            primes[index] = i;
            index++;
        }
        i++;
    }
    for (int i = -999; i < 1000; i += 2)
    {
        for (int j = 1; primes[j] <= 1000; j++)
        {
            int n = 0;
            int counter = 0;
            while (is_prime(pow(n, 2) + (n * i) + primes[j]))
            {
                counter++;
                n++;
            }
            if (counter > longest)
            {
                longest = counter, a = i, b = primes[j];
            }
        }
    }
    printf("%i\n", a * b);
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

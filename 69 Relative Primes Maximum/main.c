//
//  main.c
//  69
//
//  Created by Tyler Niiyama on 2/9/18.
//  Copyright © 2018 Tyler Niiyama. All rights reserved.
//

// https://projecteuler.net/problem=69

#include <stdio.h>
#include <math.h>

int is_prime(int x);

int main(void)
{
    int answer = 1;
    // to minimize the totient function, n should be the largest number with as many factors as possible
    // multiply all the prime numbers
    for (int i = 1; i < 100; i++)
    {
        if (is_prime(i) == 1)
        {
            answer = answer * i;
            if (answer >= 1000000)
            {
                answer = answer / i;
                break;
            }
        }
    }
    printf("%i\n", answer);
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

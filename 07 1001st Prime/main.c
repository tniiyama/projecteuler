//
//  main.c
//  7
//
//  Created by Tyler Niiyama on 9/17/17.
//  Copyright © 2017 Tyler Niiyama. All rights reserved.
//

// What is the 10,001st prime number

#include <stdio.h>
#include <math.h>

int
main(void)
{
    int number = 5;
    int length = 2;
    int max = 2;
    int primes[10001];
    for (int i = 0; i < 10001; i++)
    {
        primes[i] = 0;
    }
    primes[0] = 2;
    primes[1] = 3;
    while (primes[10000] == 0)
    {
        // runs through array of previous primes to check for divisibility
        for (int i = 1; i < length; i++)
        {
            // moves on if divisible
            if (number % primes[i] == 0)
            {
                break;
            }
            // adds number to list if the check is greater than sqrt
            if (primes[i] > max)
            {
                primes[length] = number;
                length++;
                break;
            }
        }
        // all primes are odd
        number += 2;
        max = sqrt(number);
    }
    printf("%i\n", primes[10000]);
    return 0;
}

//
//  main.c
//  46
//
//  Created by Tyler Niiyama on 10/9/17.
//  Copyright © 2017 Tyler Niiyama. All rights reserved.
//

// Find the smallest odd composite that cannot be written as the sum of a prime and twice a square

#include <stdio.h>
#include <math.h>

int is_prime(int x);

int main(void)
{
    int number = 9;
    while (1 == 1)
    {
        // keeps it odd, checks if composite
        number += 2;
        if (is_prime(number) == 1)
        {
            continue;
        }
        int counter = 0;
        // generates squares to subtract from the composite number
        for (int i = 1; 2 * pow(i, 2) <= number; i++)
        {
            int prime = number - (2 * pow(i, 2));
            // checks if the difference is prime
            if (is_prime(prime) == 1)
            {
                counter++;
                break;
            }
        }
        // ends if no sum of a prime and twice a square can be found
        if (counter == 0)
        {
            printf("%i\n", number);
            break;
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

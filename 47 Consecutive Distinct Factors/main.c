//
//  main.c
//  47
//
//  Created by Tyler Niiyama on 1/24/18.
//  Copyright © 2018 Tyler Niiyama. All rights reserved.
//

// Find the first number of four consecutive integers to have four distinct prime factors each

#include <stdio.h>
#include <math.h>

int is_prime(int x);

int main(void)
{
    for (int i = 10; i < 1000000; i++)
    {
        // row is numbers in a row, count is number of prime factors for each number
        int row = 0;
        int count = 0;
        // the numbers in the sequence have to be composite
        if (is_prime(i) == 1)
        {
            row = 0;
            continue;
        }
        int x = i;
        for (int j = 2; x != 1; j++)
        {
            if (j > x)
            {
                break;
            }
            // reduces the number to its prime factorization, counts distinct factors
            if (is_prime(j) == 1)
            {
                if (x % j == 0)
                {
                    count++;
                    while (x % j == 0)
                    {
                        x = x / j;
                    }
                }
            }
            if (count > 4)
            {
                break;
            }
        }
        // keeps track of the successes in a row
        if (count == 4)
        {
            row++;
        }
        else
        {
            row = 0;
        }
        // prints first number if 4 in a row is found
        if (row == 4)
        {
            printf("%i\n", i - 3);
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

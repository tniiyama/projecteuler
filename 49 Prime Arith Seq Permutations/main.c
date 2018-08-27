//
//  main.c
//  49
//
//  Created by Tyler Niiyama on 1/30/18.
//  Copyright © 2018 Tyler Niiyama. All rights reserved.
//

// https://projecteuler.net/problem=49

#include <stdio.h>
#include <math.h>

int is_prime(int x);
int search(int *x, int y);

int main(void)
{
    for (int i = 1009; i < 10000; i = i + 2)
    {
        if (is_prime(i) == 0)
        {
            continue;
        }
        // generates a common difference
        for (int j = 2; j < (10000 - i) / 2; j = j + 2)
        {
            if (is_prime(i + j) == 0 || is_prime(i + 2 * j) == 0)
            {
                continue;
            }
            // creates an array to store the digits of the number
            int x = i;
            int array[4];
            for (int k = 0; k < 4; k++)
            {
                array[k] = x % 10;
                x = x / 10;
            }
            // checks permutations for i + j
            x = i + j;
            int count = 0;
            for (int k = 0; k < 4; k++)
            {
                if (search(array, x % 10) == 1)
                {
                    count++;
                }
                x = x / 10;
            }
            // checks permutations for i + 2j
            x = i + 2 * j;
            for (int k = 0; k < 4; k++)
            {
                if (search(array, x % 10) == 1)
                {
                    count++;
                }
                x = x / 10;
            }
            // prints first number and common difference if all digits match
            if (count == 8)
            {
                printf("%i, %i\n", i, j);
                break;
            }
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

// only four elements, so linear search
int search(int *x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        if (x[i] == y)
        {
            return 1;
        }
    }
    return 0;
}

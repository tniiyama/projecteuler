//
//  main.c
//  73
//
//  Created by Tyler Niiyama on 8/16/18.
//  Copyright © 2018 Tyler Niiyama. All rights reserved.
//

// Find the number of fractions between 1/3 and 1/2 in the sorted set of
// reduced proper fractions for d ≤ 12,000

#include <stdio.h>

int gcf(int x, int y);

int main(void)
{
    double upper = 0.5;
    double lower = 0.333333333333333333;
    int count = 0;
    int numeratorstart = 2;
    for (int i = 5; i < 12001; i++)
    {
        int numerator = numeratorstart;
        // increases starting numerator when possible
        if ((((double)(numerator + 1) / (double)(i)) < lower) || (numerator * 3 == i))
        {
            numeratorstart++;
            numerator++;
        }
        // counts fractions until greater than 0.5
        while (((double)(numerator) / (double)(i) < upper) && (numerator * 2 != i))
        {
            if (gcf(numerator, i) == 0)
            {
                numerator++;
                continue;
            }
            count++;
            numerator++;
        }
    }
    printf("%i\n", count);
    return 0;
}

// determines if a gcf exists using Euclid's algorithm
int gcf(int x, int y)
{
    if ((x == 0) || (x == 1))
    {
        return x;
    }
    return gcf(y % x, x);
}


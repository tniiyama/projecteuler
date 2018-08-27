//
//  main.c
//  71
//
//  Created by Tyler Niiyama on 6/25/18.
//  Copyright © 2018 Tyler Niiyama. All rights reserved.
//

// By listing the set of reduced proper fractions for denominator ≤ 1,000,000 in ascending
// order of size, find the numerator of the fraction immediately to the left of 3/7

#include <stdio.h>

int main(void)
{
    double target = 0.428571428571428571;
    double lower = 0.4;
    // start with 4/10
    int numeratorstart = 4;
    int numeratorl = 4;
    int denominatorl = 10;
    for (int i = 10; i < 1000000; i++)
    {
        int numerator = numeratorstart;
        // increase starting numerator if possible
        if (((double)(numerator + 1) / (double)(i)) < lower)
        {
            numeratorstart++;
            numerator++;
        }
        while ((double)(numerator) / (double)(i) < target)
        {
            // checks if the fraction is equivalent to 3/7
            if ((numerator % 3 == 0) && (i % 7 == 0) && (numerator / 3 == i / 7))
            {
                break;
            }
            // incrases closest value if possible
            if (((double)(numerator) / (double)(i) > lower) && ((double)(numerator) / (double)(i) < target))
            {
                lower = (double)numerator / (double)i;
                numeratorl = numerator;
                denominatorl = i;
            }
            numerator++;
        }
    }
    printf("%i/%i\n", numeratorl, denominatorl);
    return 0;
}

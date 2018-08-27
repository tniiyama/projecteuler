//
//  main.c
//  30
//
//  Created by Tyler Niiyama on 12/31/17.
//  Copyright © 2017 Tyler Niiyama. All rights reserved.
//

// Find the sum of all the numbers that can be written as the sum of fifth powers of their digits

#include <stdio.h>
#include <math.h>

int main(void)
{
    // brute force, trial and error concluded the number to have six digits
    int sum = 0;
    for (int a = 0; a < 10; a++)
    {
        for (int b = 0; b < 10; b++)
        {
            for (int c = 0; c < 10; c++)
            {
                for (int d = 0; d < 10; d++)
                {
                    for (int e = 0; e < 10; e++)
                    {
                        for (int f = 0; f < 10; f++)
                        {
                            int number = (a * 100000) + (b * 10000) + (c * 1000) + (d * 100) + (e * 10) + f;
                            if (number == pow(a, 5) + pow(b, 5) + pow(c, 5) + pow(d, 5) + pow(e, 5) + pow(f, 5))
                            {
                                printf("%i\n", number);
                                sum = sum + number;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%i\n", sum);
    return 0;
}

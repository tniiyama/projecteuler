//
//  main.c
//  9
//
//  Created by Tyler Niiyama on 12/14/17.
//  Copyright © 2017 Tyler Niiyama. All rights reserved.
//

// Find the product abc of the one Pythagorean triplet for which a + b + c = 1000.

#include <stdio.h>
#include <math.h>

int main(void)
{
    // goes through all triples looking for the desired triple
    for (int a = 0; a < 333; a++)
    {
        for (int b = a + 1; b < 1000; b++)
        {
            for (int c = b + 1; c < 1000; c++)
            {
                if (pow(a, 2) + pow(b, 2) == pow(c, 2))
                {
                    if (a + b + c == 1000)
                    {
                        printf("%i\n", a * b * c);
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}

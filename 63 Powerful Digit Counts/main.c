//
//  main.c
//  63
//
//  Created by Tyler Niiyama on 4/10/18.
//  Copyright © 2018 Tyler Niiyama. All rights reserved.
//

// Find the number of n-digit positive integers that are also an nth power

#include <stdio.h>
#include <math.h>

int main(void)
{
    int count = 0;
    // base can't be greater than 9 for there to be the same number of digits
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 100; j++)
        {
            // calculates power and checks if it has n digits
            long power = pow(i, j);
            long checklow = pow(10, j - 1);
            long checkhigh = pow(10, j);
            if ((power >= checklow) && (power < checkhigh))
            {
                count++;
            }
        }
    }
    printf("%i\n", count);
    return 0;
}

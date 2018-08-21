//
//  main.c
//  12
//
//  Created by Tyler Niiyama on 9/23/17.
//  Copyright © 2017 Tyler Niiyama. All rights reserved.
//

// Find the first triangle number with over five hundred divisors

#include <stdio.h>
#include <math.h>

int
main(void)
{
    long number = 1;
    int i = 2;
    while (1)
    {
        int divisors = 0;
        // goes through numbers up to sqrt
        for (int j = 1; j < sqrt(number) + 1; j++)
        {
            if (number % j == 0)
            {
                // counts divisors twice because of divisors above and below sqrt
                divisors = divisors + 2;
            }
        }
        if (divisors >= 500)
        {
            break;
        }
        number = number + i;
        i++;
    }
    printf("%li\n", number);
    return 0;
}

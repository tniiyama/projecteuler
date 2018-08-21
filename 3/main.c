//
//  main.c
//  3
//
//  Created by Tyler Niiyama on 9/17/17.
//  Copyright © 2017 Tyler Niiyama. All rights reserved.
//

// Find the largest prime factor of 600851475143

#include <stdio.h>

int
main(void)
{
    int factor = 2;
    long number = 600851475143;
    while (factor < number)
    {
        // divides the number by small factors until the largest one remains
        while (number % factor == 0)
        {
            number /= factor;
        }
        factor++;
    }
    printf("%i\n", factor);
    return 0;
}

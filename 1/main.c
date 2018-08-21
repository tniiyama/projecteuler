//
//  1.c
//  projecteuler
//
//  Created by Tyler Niiyama on 9/17/17.
//  Copyright © 2017 Tyler Niiyama. All rights reserved.
//

// Find the sum of all the multiples of 3 or 5 below 1000

#include <stdio.h>

int
main(void)
{
    int sum = 0;
    for (int i = 0; i < 1000; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            sum = sum + i;
        }
    }
    printf("%i\n", sum);
    return 0;
}

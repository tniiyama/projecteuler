//
//  main.c
//  6
//
//  Created by Tyler Niiyama on 9/17/17.
//  Copyright © 2017 Tyler Niiyama. All rights reserved.
//

// Find the difference between the sum of the squares of the first one hundred natural numbers
// and the square of the sum

#include <stdio.h>
#include <math.h>

int
main(void)
{
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 1; i < 101; i++)
    {
        sum1 = sum1 + pow(i, 2);
        sum2 = sum2 + i;
    }
    sum2 = pow(sum2, 2);
    printf("%i\n", sum2 - sum1);
    return 0;
}

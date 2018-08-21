//
//  main.c
//  21
//
//  Created by Tyler Niiyama on 10/4/17.
//  Copyright © 2017 Tyler Niiyama. All rights reserved.
//

// Find the sum of all the amicable numbers under 10000

#include <stdio.h>

int main(void)
{
    int total = 0;
    for (int i = 2; i < 10000; i++)
    {
        // finds divisor sum of a number and checks if its an amicable pair
        int sum1 = 0;
        for (int j = 1; j < i; j++)
        {
            if (i % j == 0)
            {
                sum1 = sum1 + j;
            }
        }
        if (sum1 != i)
        {
            int sum2 = 0;
            for (int j = 1; j < sum1; j++)
            {
                if (sum1 % j == 0)
                {
                    sum2 = sum2 + j;
                }
            }
            if (sum2 == i)
            {
                total = total + i;
            }
        }
    }
    printf("%i\n", total);
    return 0;
}

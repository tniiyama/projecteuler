//
//  main.c
//  97
//
//  Created by Tyler Niiyama on 8/14/18.
//  Copyright © 2018 Tyler Niiyama. All rights reserved.
//

// Find the last ten digits of 28433 × 2^7830457 + 1

#include <stdio.h>
#include <math.h>

int main(void)
{
    // array has 11 digits to prevent seg fault
    int array[11];
    for (int i = 0; i < 11; i++)
    {
        array[i] = 0;
    }
    array[0] = 1;
    // uses array to handle multiplication
    for (int i = 0; i < 7830457; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            array[j] *= 2;
        }
        // carries over
        for (int j = 0; j < 11; j++)
        {
            if (array[j] > 9)
            {
                array[j + 1]++;
                array[j] %= 10;
            }
        }
    }
    // multiplies by 28,433
    for (int j = 0; j < 11; j++)
    {
        array[j] *= 28433;
    }
    // carries over
    for (int j = 0; j < 11; j++)
    {
        if (array[j] > 9)
        {
            array[j + 1] += array[j] / 10;
            array[j] %= 10;
        }
    }
    // adds 1
    array[0]++;
    for (int i = 9; i >= 0; i--)
    {
        printf("%i", array[i]);
    }
    printf("\n");
    return 0;
}

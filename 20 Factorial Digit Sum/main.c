//
//  main.c
//  20
//
//  Created by Tyler Niiyama on 12/17/17.
//  Copyright © 2017 Tyler Niiyama. All rights reserved.
//

// Find the sum of the digits in the number 100!

#include <stdio.h>

int main(void)
{
    // pretty much exactly like problem 16
    int array[310];
    for (int i = 0; i < 310; i++)
    {
        array[i] = 0;
    }
    array[0] = 1;
    for (int i = 1; i < 101; i++)
    {
        for (int j = 0; j < 310; j++)
        {
            array[j] *= i;
        }
        for (int j = 0; j < 310; j++)
        {
            if (array[j] > 9)
            {
                array[j + 1] += array[j] / 10;
                array[j] %= 10;
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < 310; i++)
    {
        sum += array[i];
    }
    printf("%i\n", sum);
    return 0;
}

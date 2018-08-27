//
//  main.c
//  16
//
//  Created by Tyler Niiyama on 12/14/17.
//  Copyright © 2017 Tyler Niiyama. All rights reserved.
//

// Find the sum of the digits of the number 2^1000

#include <stdio.h>
#include <math.h>

int main(void)
{
    int array[310];
    for (int i = 0; i < 310; i++)
    {
        array[i] = 0;
    }
    array[0] = 1;
    for (int i = 0; i < 1000; i++)
    {
        // goes through array twice to do multiplication
        for (int j = 0; j < 310; j++)
        {
            array[j] *= 2;
        }
        for (int j = 0; j < 310; j++)
        {
            if (array[j] > 9)
            {
                array[j] %= 10;
                array[j + 1] += 1;
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

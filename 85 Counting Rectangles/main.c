//
//  main.c
//  85
//
//  Created by Tyler Niiyama on 8/13/18.
//  Copyright © 2018 Tyler Niiyama. All rights reserved.
//

// https://projecteuler.net/problem=85

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int target = 2000000;
    int difference = 2000000;
    int x = 0;
    int y = 0;
    for (int i = 1; i < 1000; i++)
    {
        for (int j = i; j < 1000; j++)
        {
            // formula for number of rectangles can be found analytically using summations
            if (abs(target - (i * j * (i + 1) * (j + 1) / 4)) < difference)
            {
                difference = abs(target - (i * j * (i + 1) * (j + 1) / 4));
                x = i;
                y = j;
            }
        }
    }
    printf("%i, %i\n", x, y);
    return 0;
}

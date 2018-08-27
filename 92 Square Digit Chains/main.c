//
//  main.c
//  92
//
//  Created by Tyler Niiyama on 8/10/18.
//  Copyright © 2018 Tyler Niiyama. All rights reserved.
//

// https://projecteuler.net/problem=92

#include <stdio.h>
#include <math.h>

int main(void)
{
    int count = 0;
    int digits = 1;
    for (int i = 1; i < 10000000; i++)
    {
        if (i >= pow(10, digits))
        {
            digits++;
        }
        int number = i;
        // all chains arrive at 1 or 89
        while (number != 1 && number != 89)
        {
            int temp = 0;
            // adds squares of digits and repeats
            while (number > 0)
            {
                temp = temp + pow((number % 10), 2);
                number = number / 10;
            }
            number = temp;
        }
        if (number == 89)
        {
            count++;
        }
    }
    printf("%i\n", count);
    return 0;
}

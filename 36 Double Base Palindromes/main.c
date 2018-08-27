//
//  main.c
//  36
//
//  Created by Tyler Niiyama on 1/15/18.
//  Copyright © 2018 Tyler Niiyama. All rights reserved.
//

// Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2

#include <stdio.h>
#include <math.h>

int main(void)
{
    int sum = 0;
    int digits = 1;
    for (int i = 1; i < 1000001; i++)
    {
        // keeps track of digits
        if (i >= pow(10, digits))
        {
            digits++;
        }
        int reverse = 0;
        int buffer = i;
        // reverses in base 10, checks if same
        for (int j = 0; j < digits; j++)
        {
            reverse += (buffer % 10) * pow(10, digits - 1 - j);
            buffer = buffer / 10;
        }
        if (reverse == i)
        {
            int binaryreverse = 0;
            buffer = reverse;
            // uses bitwise operators to reverse digits in binary, checks if same
            while (buffer > 0)
            {
                binaryreverse = (binaryreverse << 1) | (buffer & 1);
                buffer = buffer >> 1;
            }
            if (binaryreverse == i)
            {
                sum += i;
                printf("%i\n", reverse);
            }
        }
    }
    printf("%i\n", sum);
    return 0;
}

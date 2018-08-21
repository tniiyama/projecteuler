//
//  main.c
//  14
//
//  Created by Tyler Niiyama on 10/25/17.
//  Copyright © 2017 Tyler Niiyama. All rights reserved.
//

// Find the starting number, under one million, which produces the longest chain

#include <stdio.h>

int main(void)
{
    long highest = 0;
    long other_number = 0;
    for (long i = 1; i < 1000000; i++)
    {
        int counter = 0;
        long number = i;
        // goes through collatz sequence for each number under one million
        while (number != 1)
        {
            if (number % 2 == 0)
            {
                number = number / 2;
            }
            else
            {
                number = (3 * number) + 1;
            }
            counter++;
        }
        if (counter > highest)
        {
            highest = counter;
            other_number = i;
        }
    }
    printf("%li\n", other_number);
    return 0;
}

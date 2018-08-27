//
//  main.c
//  28
//
//  Created by Tyler Niiyama on 10/1/17.
//  Copyright © 2017 Tyler Niiyama. All rights reserved.
//

// Finid the sum of the numbers on the diagonals in a 1001 by 1001 number spiral

#include <stdio.h>

int main(void)
{
    long sum = 0;
    int number = 1;
    int counter = 0;
    int increment = 0;
    // 1001 x 1001 has 1,002,001 numbers
    while (number <= 1002001)
    {
        // side length of the spiral increases by 2 every four diagonals
        if (counter % 4 == 0)
        {
            counter = 0;
            increment = increment + 2;
        }
        sum = sum + number;
        printf("%i %i\n", number, increment);
        counter++;
        number = number + increment;
    }
    printf("%li\n", sum);
    return 0;
}

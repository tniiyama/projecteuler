//
//  main.c
//  48
//
//  Created by Tyler Niiyama on 1/30/18.
//  Copyright © 2018 Tyler Niiyama. All rights reserved.
//

// Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000

#include <stdio.h>

int main(void)
{
    // last ten digits of the sum from 1-10
    long sum = 405071317;
    for (int i = 11; i < 1001; i++)
    {
        long number = 1;
        // slowly multiplies up to avoid overflow, only takes last ten digits
        for (int j = 0; j < i; j++)
        {
            number = (number * i) % 10000000000;
        }
        sum = (sum + number) % 10000000000;
    }
    printf("%li\n", sum);
    return 0;
}

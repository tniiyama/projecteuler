//
//  2.c
//  projecteuler
//
//  Created by Tyler Niiyama on 9/17/17.
//  Copyright © 2017 Tyler Niiyama. All rights reserved.
//

// Find the sum of all even Fibonacci sequence numbers under 4,000,000

#include <stdio.h>

int
main(void)
{
    int fib1 = 1;
    int fib2 = 1;
    int temp = 0;
    int sum = 0;
    while (temp < 4000000)
    {
        temp = fib1 + fib2;
        if (temp % 2 == 0)
        {
            sum = sum + temp;
        }
        fib1 = fib2;
        fib2 = temp;
    }
    printf("%i\n", sum);
    return 0;
}

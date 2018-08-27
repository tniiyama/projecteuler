//
//  main.c
//  34
//
//  Created by Tyler Niiyama on 1/13/18.
//  Copyright © 2018 Tyler Niiyama. All rights reserved.
//

// Find the sum of all numbers which are equal to the sum of the factorial of their digits.

#include <stdio.h>

int fact(int x);

int main(void)
{
    int sum = 0;
    // assuming 1,000,000 is the max
    for (int i = 3; i < 1000000; i++)
    {
        int factsum = 0;
        int number = i;
        // divides the number digit by digit and adds the factorials
        while (number > 0)
        {
            factsum += fact(number % 10);
            number = number / 10;
        }
        if (factsum == i)
        {
            printf("%i\n", i);
            sum += i;
        }
    }
    printf("%i\n", sum);
    return 0;
}

// returns the factorial of input
int fact(int x)
{
    if (x == 0)
    {
        return 1;
    }
    else if (x == 1 || x == 2)
    {
        return x;
    }
    else
    {
        return (x * fact(x - 1));
    }
}

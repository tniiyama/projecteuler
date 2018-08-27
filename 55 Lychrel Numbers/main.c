//
//  main.c
//  55
//
//  Created by Tyler Niiyama on 2/5/18.
//  Copyright © 2018 Tyler Niiyama. All rights reserved.
//

// Find the number of Lychrel numbers below ten-thousand
// https://projecteuler.net/problem=55

#include <stdio.h>
#include <math.h>

long palindrome(long x);

int main(void)
{
    int answer = 0;
    for (int i = 1; i < 10000; i++)
    {
        int count = 0;
        long number = i;
        // problem specifies to stop after 50 iterations
        while (count < 50 && number != palindrome(number))
        {
            number = number + palindrome(number);
            count++;
        }
        if (count >= 50)
        {
            answer++;
        }
    }
    printf("%i\n", answer);
    return 0;
}

// returns palindrome of the input
long palindrome(long x)
{
    long answer = 0;
    long duplicate = x;
    int digits = 0;
    // counts digits first
    while (duplicate > 0)
    {
        duplicate = duplicate / 10;
        digits++;
    }
    // creates palindrome
    for (int i = digits - 1; i >= 0; i--)
    {
        answer = answer + pow(10, i) * (x % 10);
        x = x / 10;
    }
    return answer;
}


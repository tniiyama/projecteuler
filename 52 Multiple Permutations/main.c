//
//  main.c
//  52
//
//  Created by Tyler Niiyama on 2/4/18.
//  Copyright © 2018 Tyler Niiyama. All rights reserved.
//

// Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, all contain the same digits

#include <stdio.h>
#include <math.h>

int is_permutation(int *x, int *y, int digits);

int main(void)
{
    int digits = 3;
    for (int i = 100; i < 1000000; i++)
    {
        int count = 0;
        // keeps track of digits
        if (i >= pow(10, digits))
        {
            digits++;
        }
        // the first digit must be 1 so 6x has the same number of digits
        if (i > 2 * pow(10, digits - 1))
        {
            i = i + 8 * pow(10, digits - 1);
            continue;
        }
        // creates an array of the digits of i
        int array[digits];
        int temp = i;
        for (int j = digits - 1; j >= 0; j--)
        {
            array[j] = temp % 10;
            temp = temp / 10;
        }
        for (int j = 2; j < 7; j++)
        {
            // "adds" the array to itself to get an array for 2x, 3x, etc
            int multiple[digits];
            int carry = 0;
            for (int k = digits - 1; k >= 0; k--)
            {
                multiple[k] = (carry + array[k] * j) % 10;
                carry = (carry + array[k] * j) / 10;
            }
            if (carry > 0)
            {
                break;
            }
            if (is_permutation(array, multiple, digits) == 1)
            {
                count++;
            }
        }
        // prints if succeeds 5 times in a row
        if (count == 5)
        {
            printf("%i\n", i);
            break;
        }
    }
    return 0;
}

// checks if one array is a permutation of the other
int is_permutation(int *x, int *y, int digits)
{
    for (int i = 0; i < digits; i++)
    {
        int test = x[i];
        int found = 0;
        for (int j = 0; j < digits; j++)
        {
            if (y[j] == test)
            {
                y[j] = -1;
                found++;
                break;
            }
        }
        if (found == 0)
        {
            return 0;
        }
    }
    return 1;
}

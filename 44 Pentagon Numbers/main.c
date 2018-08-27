//
//  main.c
//  44
//
//  Created by Tyler Niiyama on 1/24/18.
//  Copyright © 2018 Tyler Niiyama. All rights reserved.
//

// Given a pair of pentagonal numbers whose sum and difference are both pentagonal,
// find the minimum difference

#include <stdio.h>

int search(int *array, int x);

int main(void)
{
    // make array of 10,000 pentagonal numbers
    int array[10000];
    for (int i = 1; i < 10000; i++)
    {
        array[i] = i * (3 * i - 1) / 2;
    }
    // set an arbitrarily large min value
    int minimum = 10000000;
    for (int i = 1; i < 10000; i++)
    {
        for (int j = i + 1; j < 10000; j++)
        {
            // checks if both sum and difference are pentagonal
            if (search(array, array[j] + array[i]) == 1 && search(array, array[j] - array[i]) == 1)
            {
                printf("%i, %i\n", j, i);
                if (array[j] - array[i] < minimum)
                {
                    minimum = array[j] - array[i];
                }
            }
        }
    }
    printf("%i\n", minimum);
    return 0;
}

// binary search
int search(int *array, int x)
{
    int min = 1;
    int max = 9999;
    int mid = 0;
    while (min <= max)
    {
        mid = (min + max) / 2;
        if (x < array[mid])
        {
            max = mid - 1;
        }
        else if (x > array[mid])
        {
            min = mid + 1;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

//
//  main.c
//  25
//
//  Created by Tyler Niiyama on 12/22/17.
//  Copyright © 2017 Tyler Niiyama. All rights reserved.
//

// Find the index of the first term in the Fibonacci sequence to contain 1000 digits

#include <stdio.h>

int main(void)
{
    int array[1000];
    int previous[1000];
    for (int i = 0; i < 1000; i++)
    {
        array[i] = 0;
        previous[i] = 0;
    }
    array[0] = 1;
    previous[0] = 1;
    int index = 2;
    while (array[999] == 0)
    {
        // adds previous term to current term
        for (int i = 0; i < 1000; i++)
        {
            int buffer = array[i];
            array[i] += previous[i];
            previous[i] = buffer;
        }
        // distributes digits
        for (int i = 0; i < 1000; i++)
        {
            if (array[i] > 9)
            {
                array[i + 1] += array[i] / 10;
                array[i] %= 10;
            }
        }
        index++;
    }
    printf("%i\n", index);
    return 0;
}

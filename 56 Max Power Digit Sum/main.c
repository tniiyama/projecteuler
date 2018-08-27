//
//  main.c
//  56
//
//  Created by Tyler Niiyama on 2/14/18.
//  Copyright © 2018 Tyler Niiyama. All rights reserved.
//

// Find the maximum digital sum of numbers of the form, a^b, where 1 < a, b < 100

#include <stdio.h>

int main(void)
{
    int endsum = 0;
    for (int a = 11; a < 100; a++)
    {
        // initializes array to represent the number
        int number[200];
        for (int i = 0; i < 200; i++)
        {
            number[i] = -1;
        }
        // loop goes from 11-99, so only two digits are intiialized
        number[0] = a % 10;
        number[1] = a / 10;
        for (int b = 2; b < 100; b++)
        {
            // multiplies the array by a
            int i = 0;
            int sum = 0;
            while (number[i] != -1)
            {
                number[i] *= a;
                i++;
            }
            i = 0;
            while (number[i] != -1)
            {
                // changes a -1 to 0 if the number of digits increases
                if ((number[i + 1] == -1) && ((number[i] / 10) > 0))
                {
                    number[i + 1] += 1;
                }
                // carries over and keeps track of digit sum
                number[i + 1] += number[i] / 10;
                number[i] = number[i] % 10;
                sum += number[i];
                i++;
            }
            if (sum > endsum)
            {
                endsum = sum;
            }
        }
    }
    printf("%i\n", endsum);
    return 0;
}

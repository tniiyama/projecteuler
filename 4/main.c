//
//  main.c
//  4
//
//  Created by Tyler Niiyama on 9/17/17.
//  Copyright © 2017 Tyler Niiyama. All rights reserved.
//

// Find the largest palindrome made from the product of two 3-digit numbers

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int highest = 0;
    int number = 0;
    for (int i = 999; i > 0; i--)
    {
        for (int j = 999; j > 0; j--)
        {
            number = i * j;
            // assuming the largest product has 6 digits
            char str[7];
            // converts product to a string to check for palindrome 
            sprintf(str, "%i", number);
            if (str[strlen(str) - 1] == str[0])
            {
                if (str[strlen(str) - 2] == str[1])
                {
                    if(str[strlen(str) - 3] == str[2])
                    {
                        if (number > highest)
                        {
                            highest = number;
                        }
                    }
                }
            }
        }
    }
    printf("%i\n", highest);
    return 0;
}

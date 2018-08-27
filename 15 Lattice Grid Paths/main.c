//
//  main.c
//  15
//
//  Created by Tyler Niiyama on 12/14/17.
//  Copyright © 2017 Tyler Niiyama. All rights reserved.
//

#include <stdio.h>

int main(void)
{
    long number = 1;
    for (int i = 21; i < 41; i++)
    {
        number = number * i;
    }
    for (int i = 1; i < 21; i++)
    {
        number = number / i;
    }
    printf("%li\n", number);
    printf("%li\n", (long) 23 * 29 * 31 * 33 * 35 * 37 * 39 * 4);
    return 0;
}

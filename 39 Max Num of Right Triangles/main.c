//
//  main.c
//  39
//
//  Created by Tyler Niiyama on 1/17/18.
//  Copyright © 2018 Tyler Niiyama. All rights reserved.
//

// If p is the perimeter of a right angle triangle with integral length sides,
// find the value p <= 1,000 with the maximum number of unique triangles

#include <stdio.h>
#include <math.h>

int main(void)
{
    int index = 0;
    int max = 0;
    // runs through possible values of a, b, and c for a given p
    for (int p = 10; p < 1001; p++)
    {
        int count = 0;
        for (int a = 1; a < p; a++)
        {
            for (int b = a; a + b < p; b++)
            {
                int c = p - a - b;
                // checks if its a right triangle
                if (pow(a, 2) + pow(b, 2) == pow(c, 2))
                {
                    count++;
                }
            }
        }
        if (count > max)
        {
            max = count;
            index = p;
        }
    }
    printf("%i\n", index);
    return 0;
}

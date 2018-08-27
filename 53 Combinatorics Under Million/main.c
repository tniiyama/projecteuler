//
//  main.c
//  53
//
//  Created by Tyler Niiyama on 2/5/18.
//  Copyright © 2018 Tyler Niiyama. All rights reserved.
//

// Find the number of values of nCr, for 1 ≤ n ≤ 100, that are greater than one-million

#include <stdio.h>

int main(void)
{
    int count = 0;
    for (int i = 20; i < 101; i++)
    {
        for (int j = 1; j < i; j++)
        {
            double sum = 1;
            int n = i;
            int r = j;
            // multiply and divide at the same time to avoid overflow
            while (n > i - j && r > 0)
            {
                sum = sum * n / r;
                n--;
                r--;
            }
            // if r finishes first
            if (n > i - j)
            {
                while (n > i - j)
                {
                    sum = sum * n;
                    n--;
                    if (sum > 1000000)
                    {
                        break;
                    }
                }
            }
            // if n finishes first
            else if (r > 0)
            {
                while (r > 0)
                {
                    sum = sum / r;
                    r--;
                }
            }
            if (sum > 1000000)
            {
                count++;
            }
        }
    }
    printf("%i\n", count);
    return 0;
}

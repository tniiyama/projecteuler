//
//  main.c
//  45
//
//  Created by Tyler Niiyama on 10/9/17.
//  Copyright © 2017 Tyler Niiyama. All rights reserved.
//

// Find the next triangle, pentagonal, and hexagonal number after 40755

#include <stdio.h>

int main(void)
{
    int triangle = 40755, pentagon = 40755, hexagon = 40755;
    int tindex = 285;
    int pindex = 165;
    int hindex = 143;
    // calculates tri, pent, and hex numbers until they're all equal
    do
    {
        hexagon = hexagon + (4 * hindex) + 1;
        hindex++;
        while (pentagon < hexagon)
        {
            pentagon = pentagon + (3 * pindex) + 1;
            pindex++;
        }
        while (triangle < hexagon)
        {
            triangle = triangle + tindex + 1;
            tindex++;
        }
    } while (triangle != pentagon || pentagon != hexagon || hexagon != triangle);
    printf("%i, %i, %i\n", triangle, pentagon, hexagon);
    return 0;
}

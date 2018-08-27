//
//  main.c
//  42
//
//  Created by Tyler Niiyama on 1/18/18.
//  Copyright © 2018 Tyler Niiyama. All rights reserved.
//

// https://projecteuler.net/problem=42

#include <stdio.h>
#include <math.h>

FILE *file;

int main(void)
{
    if ((file = fopen("/Users/tniiyama/Desktop/p042_words.txt", "r")) == NULL)
    {
        printf("Can't open file\n");
        return 1;
    }
    int count = 0;
    char buffer = 'a';
    while (fscanf(file, "%c", &buffer) != EOF)
    {
        int sum = 0;
        // adds up alphabet scores of each word until the end " character is found
        do
        {
            fscanf(file, "%c", &buffer);
            sum = sum + buffer - 64;
        } while (buffer != '"');
        sum = sum + 64 - '"';
        // reversal of triangle number formula
        if (((int)sqrt(2 * sum)) * ((int)sqrt(2 * sum) + 1) == 2 * sum)
        {
            count++;
        }
        fseek(file, 1, SEEK_CUR);
    }
    printf("%i\n", count);
    fclose(file);
    return 0;
}

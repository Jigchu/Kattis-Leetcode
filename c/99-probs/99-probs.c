#include <stdio.h>

int main(void)
{
    // Gets input
    int price;
    if (scanf("%i", &price) == EOF)
    {
        return 1;
    }

    // Finds the first 99 higher than price and first 99 lower than price
    int lower = price; 
    int higher = price;

    while (lower % 100 != 99 && lower > -1)
    {
        lower--;
    }

    while (higher % 100 != 99)
    {
        higher++;
    }

    // Finds diff between lower and price && higher and price
    int diff_l = price - lower;
    int diff_h = higher - price;

    // Handling for if lower is a negative number
    if (lower <= 0)
    {
        diff_l = 100000000;
    }

    if (diff_h <= diff_l)
    {
        price = higher;
    }
    else if (diff_l < diff_h)
    {
        price = lower;
    }

    // Prints result
    printf("%i\n", price);

    // Succesful execution
    return 0;
}